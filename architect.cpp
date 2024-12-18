#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"includes.h"
#include"initializer_list"
std::vector<std::vector<float>> section::suggestTimeCore(std::string sub) {
    int i;
    bool found = 0;
    for (i = 0; i < coreSubjects.size(); i++) {
        if (sub == coreSubjects[i].name) {
            found = 1;
            break;
        }
    }
    if (found) {
        std::vector<std::vector<float>> returnVal(6, std::vector<float>(6, 0));
        std::vector<std::vector<std::vector<bool>>> listIntersection;
        teacher t = returnTeacher(coreTeachers[i]);
        if (!error_)
            listIntersection.push_back(t.timeTable);
        if (!(coreSubjects[i].rooms.size() == 1 && coreSubjects[i].rooms[0] == "0")) {
            std::vector<std::vector<bool>> antiIntersection(days, std::vector<bool>(periods, 0));
            for (auto rom : coreSubjects[i].rooms) {
                room r = returnRoom(rom);
                if (!error_)
                    for (int i = 0; i < days; i++) {
                        for (int j = 0; j < periods; j++) {
                            antiIntersection[i][j] = antiIntersection[i][j] || !r.timeTable[i][j];
                        }
                    }
            }
            for (int i = 0; i < days; i++) {
                for (int j = 0; j < periods; j++) {
                    antiIntersection[i][j] = !antiIntersection[i][j];
                }
            }
            listIntersection.push_back(antiIntersection);
        }
        std::vector<std::vector<int>> WeightedinterSection = findWeightageCore(findIntersection(listIntersection), t);
        int highest = 0;
        for (auto day : WeightedinterSection) {
            for (auto period : day) {
                if (period > highest) {
                    highest = period;
                }
            }
        }
        if (highest != 0) {
            for (int i = 0; i < days; i++) {
                for (int j = 0; j < periods; j++) {
                    returnVal[i][j] = (float)WeightedinterSection[i][j] / highest;
                }
            }
        }
        return returnVal;
    }
}
std::vector<std::vector<float>> section::suggestTimeLab(std::vector<std::string> teacherList, std::vector<std::string> roomList, int noLabsPerSession) {
    std::vector<std::vector<float>> returnVal(6, std::vector<float>(6, 0));
    std::vector<teacher> teacherListO;
    for (auto teacherName : teacherList) {
        teacher temp = returnTeacher(teacherName);
        if (!error_)
            teacherListO.push_back(temp);
    }
    std::vector<room> roomListO;
    for (auto roomName : roomList) {
        room temp = returnRoom(roomName);
        if (!error_)
            roomListO.push_back(temp);
    }
    std::vector<std::vector<std::vector<bool>>> heap;
    for (auto teachert : teacherListO) {
        heap.push_back(teachert.timeTable);
    }
    std::vector<std::vector<int>> intersectionRooms(days, std::vector<int>(periods, 0));
    for (auto roomr : roomListO) {
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < periods; j++) {
                intersectionRooms[i][j] += !roomr.timeTable[i][j];
            }
        }
    }
    std::vector<std::vector<bool>> intersection(days, std::vector<bool>(periods, 1));
    for (int i = 0; i < days; i++) {
        for (int j = 0; j < periods; j++) {
            if (intersectionRooms[i][j] >= noLabsPerSession) {
                intersection[i][j] = 0;
            }
        }
    }
    heap.push_back(intersection);
    std::vector<std::vector<bool>> intersections = findIntersection(heap);
    std::vector<std::vector<int>> WeightedinterSection = findWeightageLab(intersections, teacherListO);
    int highest = 0;
    for (auto day : WeightedinterSection) {
        for (auto period : day) {
            if (period > highest) {
                highest = period;
            }
        }
    }
    if (highest != 0) {
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < periods; j++) {
                returnVal[i][j] = (float)WeightedinterSection[i][j] / highest;
            }
        }
    }
    return returnVal;
}
bool section::clear() {
    name = "";
    for (auto& day : timeTable) {
        for (auto& period : day) {
            period = "f";
        }
    }
    for (auto& day : teacherTable) {
        for (auto& period : day) {
            period = "f";
        }
    }
    for (auto& day : roomTable) {
        for (auto& period : day) {
            period = "NA";
        }
    }
    allTeachers = {};
    coreTeachers = {};
    coreSubjects = {};
    labTeachers = {};
    noOfLabs = {};
    noTeachersPerLab = {};
    allRooms = {};
    defaultRooms = {};
    labSubjects = {};
    errorMessage = "";
    log = "cleared";
    bfactor = std::vector<int>(days, 0);
    std::vector<bool>temp(days, 0);
    labAllotment = temp;
    formattedOutput = "TIME DAY,9:00-10:00,10:00-11:00,,11:30-12:30,12:30-1:30,,2:30-3:30,3:30-4:30\n";
    std::vector<float> temp2(periods, 1);
    timeAllotment = temp2;
    defaultRoomName = "";
    return 1;
}
bool section::moveCoreUnalloted(std::string sub, int dayf, int periodf) {
    int i;
    bool found = 0;
    for (i = 0; i < coreSubjects.size(); i++) {
        if (sub == coreSubjects[i].name) {
            found = 1;
            break;
        }
    }
    if (found) {
        teacher& t = returnTeacher(coreTeachers[i]);

        if (!error_) {
            t.timeTable[dayf][periodf] = 1;
            t.timeTableName[dayf][periodf] = name;
            teacherTable[dayf][periodf] = t.name;
        }
        if (coreSubjects[i].rooms.size()) {
            bool found = 1;
            for (auto rooms : coreSubjects[i].rooms) {
                room& r = returnRoom(rooms);
                if (!r.timeTable[dayf][periodf]) {
                    r.timeTable[dayf][periodf] = 1;
                    r.timeTableName[dayf][periodf] = name;
                    roomTable[dayf][periodf] = rooms;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                roomTable[dayf][periodf] = "NAlloted";
                errorMessage += "\n Couldnt allot room for " + coreSubjects[i].name;
            }
        }
        else {
            room& roomDef = returnRoom(defaultRoomName);
            if (!error_) {
                if (!roomDef.timeTable[dayf][periodf]) {
                    roomDef.timeTable[dayf][periodf] = 1;
                    roomDef.timeTableName[dayf][periodf] = name;
                    roomTable[dayf][periodf] = roomDef.name;
                }
                else {
                    bool alloted = 0;
                    for (auto roomName : defaultRooms) {
                        room& currRoom = returnRoom(defaultRoomName);
                        if (!currRoom.timeTable[dayf][periodf]) {
                            currRoom.timeTable[dayf][periodf] = 1;
                            currRoom.timeTableName[dayf][periodf] = name;
                            roomTable[dayf][periodf] = currRoom.name;
                            alloted = 1;
                            break;
                        }
                    }
                    if (!alloted) {
                        roomTable[dayf][periodf] = "Couldnt allot";
                    }
                }
            }
        }
        timeTable[dayf][periodf] = sub;
        return 1;
    }
    return 0;
}
bool section::moveCore(int dayi, int periodi, int dayf, int periodf) {
    std::string subName = timeTable[dayi][periodi];
    std::string teacherName = teacherTable[dayi][periodi];
    std::string roomName = roomTable[dayi][periodi];
    teacher& t = returnTeacher(teacherName);
    if (error_) {
        errorMessage += "Couldnt find" + teacherName + "\n";
        return 0;
    }
    room& r = returnRoom(roomName);
    if (error_) {
        errorMessage += "Couldnt find" + roomName + "\n";
        return 0;
    }
    if (!r.timeTable[dayf][periodf]) {
        r.timeTable[dayf][periodf] = 1;
        r.timeTableName[dayf][periodf] = name;
        roomTable[dayf][periodf] = r.name;
    }
    else {
        subject s = returnSubject(subName);
        if (returnSubject(subName).rooms.size()) {
            room& prevRoom = returnRoom(roomTable[dayi][periodi]);
            if (!error_) {
                prevRoom.timeTable[dayi][periodi] = 0;
                roomTable[dayi][periodi] = "NA";
                for (auto rooms : s.rooms) {
                    room& roomO = returnRoom(rooms);
                    if (!roomO.timeTable[dayf][periodf]) {
                        roomO.timeTable[dayf][periodf] = 1;
                        roomO.timeTableName[dayf][periodf] = name;
                        roomTable[dayf][periodf] = roomO.name;
                        break;
                    }
                }
            }
        }
        else {
            room& roomDef = returnRoom(defaultRoomName);
            if (error_) {
                errorMessage += "Couldnt find" + defaultRoomName + "\n";
                return 0;
            }
            if (!roomDef.timeTable[dayf][periodf]) {
                roomDef.timeTable[dayf][periodf] = 1;
                roomDef.timeTableName[dayf][periodf] = name;
                roomTable[dayf][periodf] = roomDef.name;
            }
            else {
                bool alloted = 0;
                for (auto roomName : defaultRooms) {
                    room& currRoom = returnRoom(defaultRoomName);
                    if (!currRoom.timeTable[dayf][periodf]) {
                        currRoom.timeTable[dayf][periodf] = 1;
                        currRoom.timeTableName[dayf][periodf] = name;
                        roomTable[dayf][periodf] = currRoom.name;
                        alloted = 1;
                        break;
                    }
                }
                if (!alloted) {
                    roomTable[dayf][periodf] = "Couldnt allot";
                    errorMessage += "\nCoudlnt allot rooms for " + subName;
                }
            }
        }
    }
    //changes to be made in timeTable
    timeTable[dayi][periodi] = "f";
    timeTable[dayf][periodf] = subName;
    //changes in teacherTable and teachers timetable
    teacherTable[dayi][periodi] = "f";
    teacherTable[dayf][periodf] = teacherName;
    t.timeTable[dayi][periodi] = 0;
    t.timeTableName[dayi][periodi] = "0";
    t.timeTable[dayf][periodf] = 1;
    t.timeTableName[dayf][periodf] = name;
    //freeing room
    roomTable[dayi][periodi] = "NA";
    r.timeTable[dayi][periodi] = 0;
    r.timeTableName[dayi][periodi] = "0";
    return 1;
}
bool section::moveLabUnallocated(std::string sub, int dayf, int periodf, int noLabsPerSession) {

    if (periodf % 2) {
        periodf--;
    }
    int i = 0;
    for (; i < labSubjects.size(); i++) {

        if (sub == labSubjects[i].name) {

            break;
        }
    }
    std::string teacherNames;
    for (auto& teachers : labTeachers[i]) {
        teacher& t = returnTeacher(teachers);
        t.timeTable[dayf][periodf] = 1;
        t.timeTableName[dayf][periodf] = name;
        t.timeTable[dayf][periodf + 1] = 1;
        t.timeTableName[dayf][periodf + 1] = name;

        teacherNames += t.name + "|";
    }
    std::string roomNames;
    for (auto rooms : labSubjects[i].rooms) {
        if (!noLabsPerSession)
            break;
        room& r = returnRoom(rooms);
        if (!r.timeTable[dayf][periodf] && !r.timeTable[dayf][periodf + 1]) {
            r.timeTable[dayf][periodf] = 1;
            r.timeTableName[dayf][periodf] = name;
            r.timeTable[dayf][periodf + 1] = 1;
            r.timeTableName[dayf][periodf + 1] = name;
            roomNames += r.name + "|";
            noLabsPerSession--;
        }
    }
    timeTable[dayf][periodf] = sub;
    teacherTable[dayf][periodf] = teacherNames;
    roomTable[dayf][periodf++] = roomNames;
    timeTable[dayf][periodf] = sub;
    teacherTable[dayf][periodf] = teacherNames;
    roomTable[dayf][periodf] = roomNames;
    return 1;
}
bool section::moveLab(int dayi, int periodi, int dayf, int periodf, int noLabsPerSession) {
    if (periodi % 2) {
        periodi--;
    }
    if (periodf % 2) {
        periodf--;
    }
    std::string subjectName = timeTable[dayi][periodi];
    std::string teacherNameList = teacherTable[dayi][periodi];
    std::string roomNameList = roomTable[dayi][periodi];
    std::vector<std::string> teacherNames = splitString(teacherNameList, '|');
    std::vector<std::string> roomNames = splitString(roomNameList, '|');
    std::vector<teacher> teachers;
    std::vector<room> rooms;
    bool allFree = true;

    //iterating through all rooms alloted and making them free in that particular slot
    for (auto names : roomNames) {
        room& roomC = returnRoom(names);
        if (!error_) {
            roomC.timeTable[dayi][periodi] = 0;
            roomC.timeTableName[dayi][periodi] = "0";
            roomC.timeTable[dayi][periodi + 1] = 0;
            roomC.timeTableName[dayi][periodi + 1] = "0";
            if (roomC.timeTable[dayf][periodf] || roomC.timeTable[dayf][periodf + 1]) {

                allFree = false;
            }
            /*
            roomC.timeTable[dayf][periodf] = 1;
            roomC.timeTableName[dayf][periodf] = name;
            roomC.timeTable[dayf][periodf+1] = 1;
            roomC.timeTableName[dayf][periodf+1] = name;*/
        }
    }
    //if rooms previously alloted are free in the new slot, then allot the old rooms in new slot
    if (allFree) {
        for (auto names : roomNames) {
            room& roomC = returnRoom(names);
            if (!error_) {
                roomC.timeTable[dayf][periodf] = 1;
                roomC.timeTableName[dayf][periodf] = name;
                roomC.timeTable[dayf][periodf + 1] = 1;
                roomC.timeTableName[dayf][periodf + 1] = name;
            }
        }
    }
    else {
        int i = 0;
        for (; i < labSubjects.size(); i++) {
            if (subjectName == labSubjects[i].name) {
                break;
            }
        }
        roomNameList = "";
        for (auto rooms : labSubjects[i].rooms) {
            if (!noLabsPerSession)
                break;
            room& r = returnRoom(rooms);
            if (!r.timeTable[dayf][periodf] && !r.timeTable[dayf][periodf + 1]) {
                r.timeTable[dayf][periodf] = 1;
                r.timeTableName[dayf][periodf] = name;
                r.timeTable[dayf][periodf + 1] = 1;
                r.timeTableName[dayf][periodf + 1] = name;
                roomNameList += r.name + "|";
                noLabsPerSession--;
            }
        }
    }
    for (auto names : teacherNames) {
        teacher& teacherC = returnTeacher(names);
        if (!error_) {
            teacherC.timeTable[dayi][periodi] = 0;
            teacherC.timeTableName[dayi][periodi] = "0";
            teacherC.timeTable[dayi][periodi + 1] = 0;
            teacherC.timeTableName[dayi][periodi + 1] = "0";
            teacherC.timeTable[dayf][periodf] = 1;
            teacherC.timeTableName[dayf][periodf] = name;
            teacherC.timeTable[dayf][periodf + 1] = 1;
            teacherC.timeTableName[dayf][periodf + 1] = name;
        }
    }
    //deallocating
    timeTable[dayi][periodi] = "f";
    teacherTable[dayi][periodi] = "f";
    roomTable[dayi][periodi] = "NA";
    timeTable[dayi][++periodi] = "f";
    teacherTable[dayi][periodi] = "f";
    roomTable[dayi][periodi] = "NA";
    //allocating
    timeTable[dayf][periodf] = subjectName;
    teacherTable[dayf][periodf] = teacherNameList;
    roomTable[dayf][periodf] = roomNameList;
    timeTable[dayf][++periodf] = subjectName;
    teacherTable[dayf][periodf] = teacherNameList;
    roomTable[dayf][periodf] = roomNameList;
    return 1;

}
// using namespace std;
bool section::deAllocate() {
    logs.log("deallocation");
    //iterating through all teachers and finding the particular classes name,if found make zero
    for (auto& teacher : allTeachers) {
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < periods; j++) {
                if (teacher.timeTableName[i][j] == name) {
                    teacher.timeTable[i][j] = 0;
                    teacher.timeTableName[i][j] = "0";
                }
            }
        }
    }
    //same for rooms
    for (auto& room : allRooms) {
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < periods; j++) {
                if (room.timeTableName[i][j] == name) {
                    room.timeTable[i][j] = 0;
                    room.timeTableName[i][j] = "0";
                }
            }
        }
    }
    return 1;
}
std::string section::convertToString() {
    std::string out;
    out = name;
    for (int i = 0; i < days; i++) {
        for (int j = 0; j < periods; j++) {
            out += "," + timeTable[i][j] + "," + teacherTable[i][j] + "," + roomTable[i][j];
        }
    }
    return out;
}
bool section::readData(std::string inp) {
    for (auto& row : teacherTable)
    {
        for (auto& cell : row)
        {
            cell = "";
        }
    }
    for (auto& row : roomTable)
    {
        for (auto& cell : row)
        {
            cell = "";
        }
    }
    for (auto& row : timeTable)
    {
        for (auto& cell : row)
        {
            cell = "";
        }
    }
    enum format {
        namen,
        timeTablen
    };
    int commaCount = 0;
    try {
        for (int i = 0; i < inp.size(); i++) {
            if (inp[i] == ',') {
                commaCount++;
                continue;
            }
            switch (commaCount) {
            case namen:
                name += inp[i];
                break;
            case timeTablen:
                int commacount = 0;
                int strptr = i;
                while (inp[strptr]) {
                    if (inp[strptr] == ',') {
                        commacount++;
                    }
                    else if (commacount % 3 == 0) {
                        timeTable[commacount / 18][(commacount % 18) / 3] += inp[strptr];
                    }
                    else if (commacount % 3 == 1) {
                        teacherTable[commacount / 18][(commacount % 18) / 3] += inp[strptr];
                    }
                    else {
                        roomTable[commacount / 18][(commacount % 18) / 3] += inp[strptr];
                    }
                    strptr++;
                }
                goto b;
                break;
            }
        }
    }
    catch (...) {
        return 0;
    }
b:
    return 1;
}
void section::addCore(std::string Teacher, subject Subject) {
    coreTeachers.push_back(Teacher);
    coreSubjects.push_back(Subject);
}
void section::block(int i, int j, std::string Teacher, std::string Subject, std::string Room) {
    timeTable[i][j] = Teacher;
    teacherTable[i][j] = Subject;
    roomTable[i][j] = Room;
}
room& section::returnRoom(std::string name) {
    error_ = false;
    for (int i = 0; i < allRooms.size(); i++) {
        if (allRooms[i].name == name) {
            return allRooms[i];
        }
    }
    error_ = true;
    return allRooms[allRooms.size() - 1];
}
teacher& section::returnTeacher(std::string inp) {
    error_ = false;
    for (int i = 0; i < allTeachers.size(); i++) {
        if (allTeachers[i].name == inp) {
            return allTeachers[i];
        }
    }
    error_ = true;
    return allTeachers[allTeachers.size() - 1];
}
subject& section::returnSubject(std::string inp) {
    error_ = false;
    for (int i = 0; i < coreSubjects.size(); i++) {
        if (coreSubjects[i].name == inp) {
            return coreSubjects[i];
        }
    }
    for (int i = 0; i < labSubjects.size(); i++) {
        if (labSubjects[i].name == inp) {
            return labSubjects[i];
        }
    }
    error_ = true;
    return coreSubjects[coreSubjects.size() - 1];
}

void section::showTimeTable() {
    std::cout << "\ntimetable:\n ";
    for (auto a : timeTable) {
        for (auto period : a) {
            std::cout << period << "   ";
        }
        std::cout << std::endl;
    }
}
void section::showTeacherTable() {
    std::cout << "\ntachertable:\n ";
    for (auto a : teacherTable) {
        for (auto period : a) {
            std::cout << period << "   ";
        }
        std::cout << std::endl;
    }
}
void section::showRoomTable() {
    std::cout << "\RoomTable:\n ";
    for (auto a : roomTable) {
        for (auto period : a) {
            std::cout << period << "   ";
        }
        std::cout << std::endl;
    }
}
void section::addLab(std::vector<std::string> teacherList, subject Subject, int noLabs, int noTeachersLab) {
    labTeachers.push_back(teacherList);
    labSubjects.push_back(Subject);
    noOfLabs.push_back(noLabs);
    noTeachersPerLab.push_back(noTeachersLab);
}

//pass parameters as findInttersection({t1,t2,t3,t4},timeTableofStrings);t1 t2 t3 t4 are boolean datatype timetables. last paramm is optional
std::vector<std::vector<bool>> section::findIntersection(std::vector<std::vector<std::vector<bool>>> inputs, std::vector<std::vector<std::string>> def) {
    logs.log("inside find intersection");
    for (auto blocks : inputs) {
        for (auto day : blocks) {
            std::string temp;
            for (auto period : day) {
                temp += period;
            }
            logs.log(temp);
        }
        logs.log("");
    }
    for (auto day : def) {
        std::string temp;
        for (auto period : day) {
            temp += period;
        }
        logs.log(temp);
    }
    std::vector<std::vector<bool>> output;//return type is a vector of vector of booleans
    std::vector<std::vector<int>> temp;//tempetrory vector that stores number of intersections
    _intersections = 0;
    for (int i = 0; i < days; i++) {//making a days*periods matrix
        std::vector<int>tempp;
        for (int j = 0; j < periods; j++) {
            tempp.push_back(0);
        }
        temp.push_back(tempp);
    }

    for (std::vector<std::vector<bool>> each : inputs) {//incrementing when timetable free
        for (int i = 0; i < each.size(); i++) {
            for (int j = 0; j < each[i].size(); j++) {
                temp[i][j] += !each[i][j];
            }
        }
    }
    for (int i = 0; i < days; i++) {
        std::vector<bool>tempp;
        bool alloted = 0;
        for (int j = 0; j < periods; j++) {
            tempp.push_back(!(temp[i][j] / (inputs.size())));
            if (!alloted && !tempp[tempp.size() - 1]) {
                alloted = 1;
            }
        }
        output.push_back(tempp);
    }
    if (def.size()) {
        for (int i = 0; i < days; i++) {
            bool found = false;
            for (int j = 0; j < periods; j++) {
                if (!output[i][j]) {
                    if (def[i][j] != "f") {
                        output[i][j] = 1;
                    }
                    else {
                        if (!found) {
                            _intersections++;
                            found = 1;
                        }
                    }
                }
            }
        }
    }
    return output;
}

//a function that returns all possible 'required' number of combinations from the vector of teachers. designed for finding all possible lab allotments.
std::vector<std::vector<std::string>> section::returnCombinations(std::vector<std::string> comb, int required) {
    std::vector<std::vector<std::string>> sols;
    std::vector<int>ptrs;
    //making the inital state of the ptrs array. 
    for (int i = 0; i < required; i++) {
        ptrs.push_back(i);
    }
    bool trigger = 1;
    while (trigger) {
        //this part is adding the combination to the total list of combination
        std::vector<std::string> temp;
        temp.push_back(comb[ptrs[0]]);
        for (int i = 1; i < required; i++) {
            temp.push_back(comb[ptrs[i]]);
        }
        sols.push_back(temp);
        ptrs[required - 1]++;
        //the following part is checking if the combination is valid after increment.
        for (int i = required - 1; i >= 0; i--) {
            if (ptrs[i] == comb.size() - (required - i - 1)) {
                if (i == 0) {
                    trigger = false;
                    break;
                }
                ptrs[i - 1]++;
            }
        }
        //fixing the combination if not valid
        for (int i = required - 1; i >= 0; i--) {
            if (ptrs[i] == comb.size() - (required - i - 1)) {
                if (i == 0) {
                    trigger = false;
                    break;
                }
                for (int j = i; j < required; j++) {
                    ptrs[j] = ptrs[j - 1] + 1;
                }
            }
        }
    }
    return sols;
}
//a function that scores each period based on how free a teacher is on that particular time.
std::vector<std::vector<int>> section::findWeightageLab(std::vector<std::vector<bool>> inp, std::vector<teacher> teachers) {
    int busyFactor = 10;
    int freeFactor = 25;//2 factors that determine the score alloted to subject. busy factor is addded if teacher is either busy before or after the period. freefactor if teacher is free
    std::vector<std::vector<int>> ans;
    int baseFactor = 5;//this factor is added to all the subjects, it helps in choosing teachers that are already free over the others.
    //make a days*periods empty matrix
    for (int i = 0; i < days; i++) {
        std::vector<int> temp;
        for (int j = 0; j < periods; j++) {
            temp.push_back(0);
        }
        ans.push_back(temp);
    }
    //filter the timetable, keep only 1s where 2 periods are free simultaneously
    for (auto& a : inp) {
        for (int j = 0; j < a.size(); j += 2) {
            if (!a[j]) {
                if (a[j + 1]) {
                    a[j] = 1;
                }
            }
            else {
                a[j + 1] = 1;
            }
        }
    }
    int base = 0;
    for (auto teach : teachers) {
        for (auto day : teach.timeTable) {
            for (auto period : day) {
                if (!period) {
                    base += baseFactor;
                }
            }
        }
    }
    //scoring section 
    //iterate through each day and period. then iterate thourgh each teacher 
    for (int j = 0; j < inp.size(); j++) {
        for (int i = 0; i < inp[j].size(); i += 2) {
            int score = 0;
            if (!inp[j][i]) {
                for (int k = 0; k < teachers.size(); k++) {
                    //if teacher is free before add freeFactor. else add busy factor.
                    if (i > 1) {
                        if (teachers[k].timeTable[j][i - 1]) {
                            score += busyFactor;
                        }
                        else {
                            score += freeFactor;
                        }
                    }
                    else {
                        score += freeFactor;
                    }
                    //if teacher is free after add freeFactor. else add busy factor
                    if (i < 4) {
                        if (teachers[k].timeTable[j][i + 2]) {
                            score += busyFactor;
                        }
                        else {
                            score += freeFactor;
                        }
                    }
                    else {
                        score += freeFactor;
                    }
                }
                score -= bfactor[j];
                score += base;
                ans[j][i] = score;
                ans[j][i + 1] = score;
            }
        }
    }
    return ans;
}
std::vector<std::vector<int>> section::findWeightageCore(std::vector<std::vector<bool>> inp, teacher teachers) {
    int busyFactor = 10;
    int freeFactor = 25;//2 factors that determine the score alloted to subject. busy factor is addded if teacher is either busy before or after the period. freefactor if teacher is free
    std::vector<std::vector<int>> ans(6, std::vector<int>(6, 0));
    int baseFactor = 5;//this factor is added to all the subjects, it helps in choosing teachers that are already free over the others.

    int base = 0;
    for (auto day : teachers.timeTable) {
        for (auto period : day) {
            if (!period) {
                base += baseFactor;
            }
        }
    }
    //scoring section 
    //iterate through each day and period. then iterate thourgh each teacher 
    for (int j = 0; j < inp.size(); j++) {
        for (int i = 0; i < inp[j].size(); i += 1) {
            int score = 0;
            if (!inp[j][i]) {
                //if teacher is free before add freeFactor. else add busy factor.
                if (i > 0) {
                    if (teachers.timeTable[j][i - 1]) {
                        score += busyFactor;
                    }
                    else {
                        score += freeFactor;
                    }
                }
                else {
                    score += freeFactor;
                }
                //if teacher is free after add freeFactor. else add busy factor
                if (i < 5) {
                    if (teachers.timeTable[j][i + 1]) {
                        score += busyFactor;
                    }
                    else {
                        score += freeFactor;
                    }
                }
                else {
                    score += freeFactor;
                }
                score -= bfactor[j];
                score -= 5 * i;
                score += base;
                ans[j][i] = score;
            }
        }
    }
    return ans;
}
std::vector<std::string> section::splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
void section::makeTIMETABLE() {
    logs.log("inside Maketimetable");
    logs.log("BFL: " + std::to_string(busyFactorL));
    logs.log("FFL: " + std::to_string(freeFactorL));
    logs.log("BFL: " + std::to_string(baseFactorL));
    logs.log("BFC: " + std::to_string(busyFactorC));
    logs.log("FFC: " + std::to_string(freeFactorC));
    logs.log("BFC: " + std::to_string(baseFactorC));
    logs.log("RIC: " + std::to_string(reductionIndexC));
    logs.log("currTimetable: ");
    for (auto day : timeTable) {
        std::string temp;
        for (auto period : day) {
            temp += period + ", ";
        }
        logs.log(temp);
    }
    //alloting labs
    //keep track of how many collisions have occured.
    int labCollisions = 0;
    for (int i = 0; i < labTeachers.size(); i++) {
        logs.log("Lsub:" + labSubjects[i].name);

        for (auto teachers : labTeachers[i]) {
            logs.log("teacher: " + teachers);
        }
        for (auto rooms : labSubjects[i].rooms) {
            logs.log("rooms: " + rooms);
        }
        logs.log("Nt:" + std::to_string(noTeachersPerLab[i]));
        logs.log("Nl:" + std::to_string(noOfLabs[i]));
        std::vector<std::vector<std::string>> allCombsTeachers = returnCombinations(labTeachers[i], noOfLabs[i] * noTeachersPerLab[i]);
        std::vector<std::vector<std::string>> allCombsRooms = returnCombinations(labSubjects[i].rooms, noOfLabs[i]);
        std::vector<std::vector<std::vector<std::string>>> allCombs;
        std::vector<std::vector<std::vector<int>>> interSectionList;
        std::vector<int> score;
        //make all possible combinations of teachers, rooms. allCombs is a vector of vector of vector of strings. it holds in a format like: [[[teacher combination1],[roomcombination1]],[[teacher combination2],[roomcombination2]]...]
        for (auto a : allCombsTeachers) {
            for (auto b : allCombsRooms) {
                std::vector<std::vector<std::string>> temp;
                temp.push_back(a);
                temp.push_back(b);
                allCombs.push_back(temp);
            }
        }
        //pushing all the intersections of timetables in order
        for (auto comb : allCombs) {
            std::vector<teacher> teachers;
            std::vector<room> rooms;
            std::vector<std::vector<std::vector<bool>>> timeTables;
            for (auto teachersString : comb[0]) {
                teachers.push_back(returnTeacher(teachersString));
                timeTables.push_back(teachers[teachers.size() - 1].timeTable);
            }
            for (auto roomsString : comb[1]) {
                rooms.push_back(returnRoom(roomsString));
                timeTables.push_back(rooms[rooms.size() - 1].timeTable);
            }
            std::vector<std::vector<bool>> intersection = findIntersection(timeTables, timeTable);
            int intersectionCount = 0;
            for (auto day : intersection) {
                for (auto period : day) {
                    std::cout << period << "  ";
                }
                std::cout << "\n";
            }
            int counter = 0;
            for (auto day : intersection) {
                for (int k = 0; k < day.size(); k += 2) {
                    if (!day[k] && !day[k + 1] && !labAllotment[counter]) {
                        intersectionCount++;
                        break;
                    }
                }
                counter++;
            }
            std::cout << "\n";
            if (intersectionCount >= labSubjects[i].credits) {
                std::vector<std::vector<int>> intersectionScore = findWeightageLab(intersection, teachers);
                interSectionList.push_back(intersectionScore);

                //search best credits number of scores.
                std::vector<int> tops(labSubjects[i].credits, 0);
                for (int f = 0; f < days; f++) {
                    for (int g = 0; g < periods; g++) {
                        for (int l = tops.size() - 1; l >= 0; l--) {
                            if (intersectionScore[f][g] > tops[l] && !labAllotment[f]) {
                                tops[l] = intersectionScore[f][g];
                                break;
                            }
                        }
                    }
                }
                int sum = 0;
                for (auto a : tops) {
                    sum += a;
                }
                score.push_back(sum);
            }
            //intersections less than credits
            else {
                std::vector<std::vector<int>> ans(6, std::vector<int>(6, 1));
                //make a days*periods empty matrix
                interSectionList.push_back(ans);
                score.push_back(-1);
            }
        }
        //finding the best possible combination. index refers to best combination(max value of score)
        int index = 0;
        int indexScore = -1;
        for (int f = 0; f < score.size(); f++) {
            if (score[f] > indexScore) {
                indexScore = score[f];
                index = f;
            }
        }
        std::cout << "index: " << index << " indexscore " << indexScore << "\n";
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < periods; j++) {
                interSectionList[index][i][j] /= timeAllotment[j];
            }
        }
        //if credits satisfied
        if (indexScore != -1) {
            //here allotment starts
            int credCount = labSubjects[i].credits;
            //coming back here if credits not satisfied
        repeatLt:
            if (!compactLab) {
                //find best credits number of intersections
                std::vector<int> tops(credCount, 0);
                for (int f = 0; f < days; f++) {
                    if (!labAllotment[f]) {
                        for (int g = 0; g < periods; g++) {
                            if (interSectionList[index][f][g] == -1) {
                                break;
                            }
                            for (int l = tops.size() - 1; l >= 0; l--) {
                                if (interSectionList[index][f][g] > tops[l]) {
                                    for (int f = 1; f <= l; f++) {
                                        tops[f - 1] = tops[f];
                                    }
                                    tops[l] = interSectionList[index][f][g];
                                    g++;
                                    break;
                                }
                            }
                        }
                    }
                }
                //iterate through each period
                for (int k = 0; k < days; k++) {
                    if (!labAllotment[k]) {
                        int highest = 0, highestindex = 0;
                        //find the highest value in the day
                        for (int l = 0; l < periods; l++) {
                            if (highest < interSectionList[index][k][l]) {
                                highest = interSectionList[index][k][l];
                                highestindex = l;
                            }
                            if (interSectionList[index][k][l] == -1) {
                                break;
                            }
                        }
                        //if highest is in top 'credits' rank
                        if (highest >= tops[0] && credCount && !labAllotment[k]) {
                            timeAllotment[highestindex] = reductionIndexL;
                            timeAllotment[highestindex + 1] = reductionIndexL;
                            //assgign timetable name
                            timeTable[k][highestindex] = labSubjects[i].name;
                            timeTable[k][highestindex + 1] = labSubjects[i].name;
                            labAllotment[k] = 1;
                            std::string teacherString;
                            std::string roomString;
                            //making teacher and room string a,b,c,d format
                            for (auto teachers : allCombs[index][0]) {
                                std::vector<std::string> temp = splitString(teachers, ' ');
                                for (int i = 0; i < temp.size() - 1; i++) {
                                    teachers += temp[i] + "_";
                                }
                                teacherString += temp[temp.size() - 1] + "|";//new delimiiter
                            }
                            for (auto rooms : allCombs[index][1]) {
                                roomString += rooms + "|";
                            }
                            //assignment
                            teacherTable[k][highestindex] = teacherString;
                            teacherTable[k][highestindex + 1] = teacherString;
                            roomTable[k][highestindex] = roomString;
                            roomTable[k][highestindex + 1] = roomString;
                            //assignements of particul;ar teacher and room
                            for (auto teachers : allCombs[index][0]) {
                                teacher& t = returnTeacher(teachers);
                                t.timeTable[k][highestindex] = 1;
                                t.timeTable[k][highestindex + 1] = 1;
                                t.timeTableName[k][highestindex] = name;
                                t.timeTableName[k][highestindex + 1] = name;
                            }
                            for (auto rooms : allCombs[index][1]) {
                                room& r = returnRoom(rooms);
                                r.timeTable[k][highestindex] = 1;
                                r.timeTable[k][highestindex + 1] = 1;
                                r.timeTableName[k][highestindex] = name;
                                r.timeTableName[k][highestindex + 1] = name;
                            }
                            //decrease the factors to reduce prefereence of allotment on same time again
                            for (int j = 0; j < days; j++) {
                                interSectionList[index][j][highestindex] /= reductionIndexC;
                                interSectionList[index][j][highestindex + 1] /= reductionIndexC;
                            }
                            //convert the period to -1 to prevent further allotment on the same day.
                            interSectionList[index][k][0] = -1;
                            //reduce commacount
                            credCount--;
                        }
                    }
                }
            }
            else {
                for (int day = 0; day < days; day++) {
                    if (!labAllotment[day]) {
                        for (int period = 0; period < periods; period += 2) {
                            if (interSectionList[index][day][period] && interSectionList[index][day][period + 1] && credCount) {//assgign timetable name
                                timeTable[day][period] = labSubjects[i].name;
                                timeTable[day][period + 1] = labSubjects[i].name;
                                labAllotment[day] = 1;
                                credCount--;
                                std::string teacherString;
                                std::string roomString;
                                //madaying teacher and room string a,b,c,d format
                                for (auto teachers : allCombs[index][0]) {
                                    std::vector<std::string> temp = splitString(teachers, ' ');
                                    for (int i = 0; i < temp.size() - 1; i++) {
                                        teachers += temp[i] + "_";
                                    }
                                    teacherString += temp[temp.size() - 1] + "|";//new delimiiter
                                }
                                for (auto rooms : allCombs[index][1]) {
                                    roomString += rooms + "|";
                                }
                                labAllotment[day] = 1;
                                teacherTable[day][period] = teacherString;
                                teacherTable[day][period + 1] = teacherString;
                                roomTable[day][period] = roomString;
                                roomTable[day][period + 1] = roomString;
                                //assignements of particul;ar teacher and room
                                for (auto teachers : allCombs[index][0]) {
                                    teacher& t = returnTeacher(teachers);
                                    t.timeTable[day][period] = 1;
                                    t.timeTable[day][period + 1] = 1;
                                    t.timeTableName[day][period] = name;
                                    t.timeTableName[day][period + 1] = name;
                                }
                                for (auto rooms : allCombs[index][1]) {
                                    room& r = returnRoom(rooms);
                                    r.timeTable[day][period] = 1;
                                    r.timeTable[day][period + 1] = 1;
                                    r.timeTableName[day][period] = name;
                                    r.timeTableName[day][period + 1] = name;
                                }
                            }
                        }
                    }
                }
            }
            if (credCount) {
                goto repeatLt;//repeat from ranking process.
            }
        }
        else {
            errorMessage += "collision occured when alloting " + labSubjects[i].name + "  \n";
            errorLabs.push_back(labSubjects[i].name);
        }
    }
    //find preferred clasroom
    std::vector<int> scoreRoom;
    bool found = false;
    for (auto currClass : defaultRooms) {
        int score = 0;
        room curr = returnRoom(currClass);
        for (auto day : curr.timeTable) {
            for (auto period : day) {
                if (!period) {
                    score++;
                }
            }
        }
        if (curr.name == defaultRoomC) {
            score += 10;
            found = true;
        }
        scoreRoom.push_back(score);
    }
    if (!found && defaultRoomC != "NULL") {
        defaultRooms.push_back(defaultRoomC);
        scoreRoom.push_back(30);
    }
    int highestR = 0, highestindexR = -1;
    for (int i = 0; i < scoreRoom.size(); i++) {
        if (scoreRoom[i] > highestR) {
            highestR = scoreRoom[i];
            highestindexR = i;
        }
    }
    room& defaultRoomP = returnRoom(defaultRooms[highestindexR]);
    defaultRoomName = defaultRoomP.name;
    room& defaultRoom = returnRoom(defaultRooms[highestindexR]);
    //coreteachers allocation
    logs.log("Core teacher allocation");
    for (int subjects = 0; subjects < coreSubjects.size(); subjects++) {
        teacher& currTeacher = returnTeacher(coreTeachers[subjects]);
        subject currSubject = coreSubjects[subjects];
        logs.log("t:" + currTeacher.name);
        logs.log("t:" + currSubject.name);
        std::vector<std::string>currDefaultRooms = defaultRooms;
        if (currSubject.rooms[0] == "0") {//check if subject has defult rooms
            if (highestindexR != -1) {//checking if room is alloted
                defaultRoom = defaultRoomP;
            rep:
                std::vector<std::vector<std::vector<bool>>> temp = { currTeacher.timeTable,defaultRoom.timeTable };
                std::vector<std::vector<bool>> intersectionTable = findIntersection(temp, timeTable);
                for (auto d : intersectionTable) {
                    for (auto p : d) {
                        std::cout << p << "   ";
                    }
                    std::cout << "\n";
                }
                if (_intersections >= currSubject.credits) {
                    std::vector<std::vector<int>> scoredTable = findWeightageCore(intersectionTable, currTeacher);//get scored table to choose optimal period
                    int credCount = currSubject.credits;
                    //coming back here if credits not satisfied
                repeatCt:
                    //find best credits number of intersections
                    std::cout << std::endl;
                    for (auto a : scoredTable) {
                        for (auto v : a) {
                            std::cout << v << "   ";
                        }
                        std::cout << "\n";
                    }
                    std::vector<int> tops(credCount, 0);
                    for (int f = 0; f < days; f++) {
                        for (int g = 0; g < periods; g++) {
                            if (scoredTable[f][g] == -1) {
                                break;
                            }
                            for (int l = tops.size() - 1; l >= 0; l--) {
                                if (scoredTable[f][g] > tops[l]) {
                                    for (int f = 1; f <= l; f++) {
                                        tops[f - 1] = tops[f];
                                    }
                                    tops[l] = scoredTable[f][g];
                                    break;
                                }
                            }
                        }
                    }
                    //iterate through each period
                    for (int k = 0; k < days; k++) {
                        int highest = -1, highestindex = 0;
                        //find the highest value in the day
                        for (int l = 0; l < periods; l++) {
                            if (highest < scoredTable[k][l]) {
                                highest = scoredTable[k][l];
                                highestindex = l;
                            }
                            if (scoredTable[k][l] == -1) {
                                break;
                            }
                        }
                        // if highest is in top 'credits' rank
                        if (highest >= tops[0] && credCount && highest != -1) {
                            timeTable[k][highestindex] = coreSubjects[subjects].name;
                            teacherTable[k][highestindex] = currTeacher.name;
                            roomTable[k][highestindex] = defaultRoom.name;
                            currTeacher.timeTable[k][highestindex] = 1;
                            currTeacher.timeTableName[k][highestindex] = name;
                            defaultRoom.timeTable[k][highestindex] = 1;
                            defaultRoom.timeTableName[k][highestindex] = name;
                            for (int j = 0; j < days; j++) {
                                if (scoredTable[j][highestindex] != -1) {
                                    scoredTable[j][highestindex] /= reductionIndexC;
                                }
                            }
                            //convert thew period to -1 to prevent further allotment on the same day.
                            scoredTable[k][0] = -1;
                            //reduce commacount
                            credCount--;
                        }
                    }
                    if (credCount) {
                        goto repeatCt;//repeat from ranking process.
                    }
                }
                //collision handleing
                else {
                    std::cout << "collision!";
                    std::vector<std::vector<std::vector<bool>>> temp = { returnTeacher(coreTeachers[subjects]).timeTable };
                    findIntersection(temp, timeTable);
                    if (_intersections >= coreSubjects[subjects].credits) {
                        //single room cant hold everything
                        //fist stage. allot as much as possible in defaulroom
                        temp.push_back(defaultRoom.timeTable);
                        int credCount = currSubject.credits;
                        std::vector<std::vector<bool>> primarys = findIntersection(temp, timeTable);
                        for (int day = 0; day < primarys.size(); day++) {
                            for (int period = 0; period < periods; period++) {
                                if (!primarys[day][period]) {
                                    credCount--;
                                    timeTable[day][period] = coreSubjects[subjects].name;
                                    teacherTable[day][period] = currTeacher.name;
                                    roomTable[day][period] = defaultRoom.name;
                                    currTeacher.timeTable[day][period] = 1;
                                    currTeacher.timeTableName[day][period] = name;
                                    defaultRoom.timeTable[day][period] = 1;
                                    defaultRoom.timeTableName[day][period] = name;
                                    break;
                                }
                            }
                        }
                        for (auto rooms : defaultRooms) {
                            std::vector<std::vector<std::vector<bool>>> temp = { returnTeacher(coreTeachers[subjects]).timeTable };
                            temp.push_back(returnRoom(rooms).timeTable);
                            std::vector<std::vector<bool>> primarys = findIntersection(temp, timeTable);
                            for (int day = 0; day < primarys.size(); day++) {
                                bool alloted = false;
                                for (int period = 0; period < periods; period++) {
                                    if (timeTable[day][period] == currSubject.name) {
                                        alloted = true;
                                    }
                                }
                                if (!alloted && credCount) {
                                    for (int period = 0; period < periods; period++) {
                                        if (!primarys[day][period]) {
                                            credCount--;
                                            timeTable[day][period] = coreSubjects[subjects].name;
                                            teacherTable[day][period] = currTeacher.name;
                                            roomTable[day][period] = rooms;
                                            currTeacher.timeTable[day][period] = 1;
                                            currTeacher.timeTableName[day][period] = name;
                                            defaultRoom.timeTable[day][period] = 1;
                                            defaultRoom.timeTableName[day][period] = name;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (credCount) {
                            errorMessage += "Couldnt allot all rooms for subject:" + currSubject.name;
                            std::vector<std::vector<std::vector<bool>>> temp = { returnTeacher(coreTeachers[subjects]).timeTable };
                            std::vector<std::vector<bool>> primarys = findIntersection(temp, timeTable);
                            for (int day = 0; day < primarys.size(); day++) {
                                bool alloted = false;
                                for (int period = 0; period < periods; period++) {
                                    if (timeTable[day][period] == currSubject.name) {
                                        alloted = true;
                                    }
                                }
                                if (!alloted && credCount) {
                                    for (int period = 0; period < periods; period++) {
                                        if (!primarys[day][period]) {
                                            credCount--;
                                            timeTable[day][period] = currSubject.name;
                                            teacherTable[day][period] = currTeacher.name;
                                            roomTable[day][period] = "NALOTTED";
                                            currTeacher.timeTable[day][period] = 1;
                                            currTeacher.timeTableName[day][period] = name;
                                            defaultRoom.timeTable[day][period] = 1;
                                            defaultRoom.timeTableName[day][period] = name;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else {
                        //teachers allocation has collision.
                        int credCount = currSubject.credits;
                        std::vector<std::vector<std::vector<bool>>> temp = { returnTeacher(coreTeachers[subjects]).timeTable };
                        std::vector<std::vector<bool>> primarys = findIntersection(temp, timeTable);
                        std::vector<std::vector<int>> scoredTable = findWeightageCore(primarys, currTeacher);
                        //alloting to the maxiumum extent possible.
                        int d = -1;//lazy to change the code
                        for (auto day : scoredTable) {
                            d++;
                            int highest = -1, highestIndex;
                            //checking for the best time in the day
                            for (int period = 0; period < day.size(); period++) {
                                if (day[period] > highest) {
                                    highestIndex = period;
                                    highest = day[period];
                                }
                            }
                            if (highest > 0) {
                                //best time has been found. first checking is done if default room is free thast time else some other room is alloted.
                                if (!defaultRoom.timeTable[d][highestIndex]) {
                                    //default room is only available
                                    timeTable[d][highestIndex] = currSubject.name;
                                    teacherTable[d][highestIndex] = currTeacher.name;
                                    roomTable[d][highestIndex] = defaultRoom.name;
                                    currTeacher.timeTable[d][highestIndex] = 1;
                                    currTeacher.timeTableName[d][highestIndex] = name;
                                    defaultRoom.timeTable[d][highestIndex] = 1;
                                    defaultRoom.timeTableName[d][highestIndex] = name;
                                    credCount--;
                                }
                                else {
                                    bool alloted = false;
                                    //some other room from defaultRooms
                                    for (auto rooms : currDefaultRooms) {
                                        if (!returnRoom(rooms).timeTable[d][highestIndex]) {
                                            timeTable[d][highestIndex] = currSubject.name;
                                            teacherTable[d][highestIndex] = currTeacher.name;
                                            roomTable[d][highestIndex] = rooms;
                                            currTeacher.timeTable[d][highestIndex] = 1;
                                            currTeacher.timeTableName[d][highestIndex] = name;
                                            returnRoom(rooms).timeTable[d][highestIndex] = 1;
                                            returnRoom(rooms).timeTableName[d][highestIndex] = name;
                                            credCount--;
                                            alloted = true;
                                            break;
                                        }
                                    }
                                    if (!alloted) {
                                        timeTable[d][highestIndex] = currSubject.name;
                                        teacherTable[d][highestIndex] = currTeacher.name;
                                        roomTable[d][highestIndex] = "NAlloted";
                                        currTeacher.timeTable[d][highestIndex] = 1;
                                        currTeacher.timeTableName[d][highestIndex] = name;
                                        credCount--;
                                        errorMessage += "\ndid not allot room for " + currSubject.name;

                                    }
                                }
                            }
                        }
                        //check all the other times the teacher is free and sub hasnt been alloted that day
                        std::vector<std::vector<int>> teacherTt = findWeightageCore(currTeacher.timeTable, currTeacher);
                        for (int i = 0; i < days; i++) {
                            bool found = false;
                            for (int j = 0; j < periods; j++) {
                                if (timeTable[i][j] == currSubject.name) {
                                    found = 1;
                                }
                            }
                            if (!found && credCount) {
                                //if timeTable isnt alloted that day
                                int highest = 0, highestIndex = -1;
                                for (int indexC = 0; indexC < periods; indexC++) {
                                    if (teacherTt[i][indexC] > highest) {
                                        highestIndex = indexC;
                                        highest = teacherTt[i][indexC];
                                    }
                                }
                                //found highest in the day. now check if teacher on that time is free somewhere else.
                                if (highestIndex != -1 && timeTable[i][highestIndex] != "block" && timeTable[i][highestIndex] != "f") {
                                    //subject curSub = returnSubject(timeTable[i][highestIndex]);//subject thats there on that time.
                                    int index = -1;
                                    for (int su = 0; su < coreSubjects.size(); su++) {
                                        if (coreSubjects[su].name == timeTable[i][highestIndex]) {
                                            index = su;
                                        }
                                    }
                                    if (index != -1) {
                                        //found the subject. 
                                        teacher& curTeach = returnTeacher(coreTeachers[index]);
                                        int tHighest = 0, tHighestIndex = -1, dayIndex;//vars that hold the best score for that teacher.
                                        for (int d = 0; d < days; d++) {
                                            bool found = false;
                                            for (int p = 0; p < periods; p++) {
                                                if (timeTable[d][p] == timeTable[i][highestIndex] && d != i) {
                                                    found = true;
                                                }
                                            }
                                            if (!found) {
                                                //means not already alloted on that day.
                                                // preoceed to allot teacher there and change the timetable.
                                                std::vector<std::vector<std::vector<bool>>> temp; temp.push_back(curTeach.timeTable);
                                                std::vector < std::vector<bool >>Instersections = findIntersection(temp, timeTable);
                                                std::vector<int> teacherScored = findWeightageCore(Instersections, curTeach)[d];//LIST OF AVAILABLE SLOTS
                                                int indexs = 0, indexsindex = -1;
                                                //find highest on that particualr day
                                                for (int q = 0; q < periods; q++) {
                                                    if (indexs < teacherScored[q]) {
                                                        indexs = teacherScored[q];
                                                        indexsindex = q;
                                                    }
                                                }
                                                //check if its greater than the greates
                                                if (indexsindex != -1) {
                                                    if (indexs > tHighest) {
                                                        tHighest = indexs;
                                                        tHighestIndex = indexsindex;
                                                        dayIndex = d;
                                                    }
                                                }
                                            }
                                        }
                                        if (tHighestIndex != -1) {
                                            //reallot new teacher.
                                            timeTable[dayIndex][tHighestIndex] = timeTable[i][highestIndex];
                                            teacherTable[dayIndex][tHighestIndex] = curTeach.name;
                                            curTeach.timeTable[dayIndex][tHighestIndex] = 1;
                                            curTeach.timeTable[i][highestIndex] = 1;
                                            curTeach.timeTableName[dayIndex][tHighestIndex] = name;
                                            if (!defaultRoom.timeTable[dayIndex][tHighestIndex]) {
                                                roomTable[dayIndex][tHighestIndex] = defaultRoom.name;
                                                defaultRoom.timeTable[dayIndex][tHighestIndex] = 1;
                                                defaultRoom.timeTableName[dayIndex][tHighestIndex] = name;
                                            }
                                            else {
                                                bool alloted = false;
                                                for (auto rooms : defaultRooms) {
                                                    //go through each room and check if its free. if free allot. else put NA 
                                                    if (!returnRoom(rooms).timeTable[dayIndex][tHighestIndex]) {
                                                        roomTable[dayIndex][tHighestIndex] = rooms;
                                                        returnRoom(rooms).timeTable[dayIndex][tHighestIndex] = 1;
                                                        returnRoom(rooms).timeTableName[dayIndex][tHighestIndex] = name;
                                                        alloted = 1;
                                                    }
                                                }
                                                if (!alloted) {
                                                    roomTable[dayIndex][tHighestIndex] = "NAlloted";
                                                    errorMessage += "\ndid not allot room for " + timeTable[i][highestIndex];
                                                }
                                            }
                                            timeTable[i][highestIndex] = currSubject.name;
                                            teacherTable[i][highestIndex] = currTeacher.name;
                                            curTeach.timeTable[i][highestIndex] = 1;
                                            curTeach.timeTable[i][highestIndex] = 1;
                                            curTeach.timeTableName[i][highestIndex] = name;
                                            credCount--;
                                        }
                                    }
                                }
                            }
                        }
                        //if credCount still more than 0 means do not best allocation.
                        if (credCount) {
                            //if here reached means allotment not yet done fully.
                            for (int day = 0; day < days; day++) {
                                bool found = false;
                                for (int period = 0; period < periods; period++) {
                                    if (timeTable[day][period] == currSubject.name) {
                                        found = true;
                                    }
                                }
                                if (!found && credCount) {
                                    for (int period = 0; period < periods; period++) {
                                        if (!currTeacher.timeTable[day][period]) {
                                            //if exectution reaches here it implies that the teacher is free at this time. 
                                            //now check if this subject can be realloted.
                                            //if alloted break out of loop and decrease credCount
                                            if (period != -1 && timeTable[day][period] != "block" && timeTable[day][period] != "f") {
                                                //subject curSub = returnSubject(timeTable[day][period]);//subject thats there on that time.
                                                int index = -1;
                                                for (int su = 0; su < coreSubjects.size(); su++) {
                                                    if (coreSubjects[su].name == timeTable[day][period]) {
                                                        index = su;
                                                    }
                                                }
                                                if (index != -1) {
                                                    //found the subject. 
                                                    teacher& curTeach = returnTeacher(coreTeachers[index]);
                                                    int tHighest = 0, tHighestIndex = -1, dayIndex;//vars that hold the best score for that teacher.
                                                    for (int d = 0; d < days; d++) {
                                                        bool found = false;
                                                        for (int p = 0; p < periods; p++) {
                                                            if (timeTable[d][p] == timeTable[day][period] && d != day) {
                                                                found = true;
                                                            }
                                                        }
                                                        if (!found) {
                                                            //means not already alloted on that day.
                                                            // preoceed to allot teacher there and change the timetable.
                                                            std::vector<std::vector<std::vector<bool>>> temp; temp.push_back(curTeach.timeTable);
                                                            std::vector < std::vector<bool >>Instersections = findIntersection(temp, timeTable);
                                                            std::vector<int> teacherScored = findWeightageCore(Instersections, curTeach)[d];//LIST OF AVAILABLE SLOTS
                                                            int indexs = 0, indexsindex = -1;
                                                            //find highest on that particualr day
                                                            for (int q = 0; q < periods; q++) {
                                                                if (indexs < teacherScored[q]) {
                                                                    indexs = teacherScored[q];
                                                                    indexsindex = q;
                                                                }
                                                            }
                                                            //check if its greater than the greates
                                                            if (indexsindex != -1) {
                                                                if (indexs > tHighest) {
                                                                    tHighest = indexs;
                                                                    tHighestIndex = indexsindex;
                                                                    dayIndex = d;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (tHighestIndex != -1) {
                                                        //reallot new teacher.
                                                        timeTable[dayIndex][tHighestIndex] = timeTable[day][period];
                                                        teacherTable[dayIndex][tHighestIndex] = curTeach.name;
                                                        curTeach.timeTable[dayIndex][tHighestIndex] = 1;
                                                        curTeach.timeTable[day][period] = 1;
                                                        curTeach.timeTableName[dayIndex][tHighestIndex] = name;
                                                        if (!defaultRoom.timeTable[dayIndex][tHighestIndex]) {
                                                            roomTable[dayIndex][tHighestIndex] = defaultRoom.name;
                                                            defaultRoom.timeTable[dayIndex][tHighestIndex] = 1;
                                                            defaultRoom.timeTableName[dayIndex][tHighestIndex] = name;
                                                        }
                                                        else {
                                                            bool alloted = false;
                                                            for (auto rooms : defaultRooms) {
                                                                //go through each room and check if its free. if free allot. else put NA and fuck offf
                                                                if (!returnRoom(rooms).timeTable[dayIndex][tHighestIndex]) {
                                                                    roomTable[dayIndex][tHighestIndex] = rooms;
                                                                    returnRoom(rooms).timeTable[dayIndex][tHighestIndex] = 1;
                                                                    returnRoom(rooms).timeTableName[dayIndex][tHighestIndex] = name;
                                                                    alloted = 1;
                                                                }
                                                            }
                                                            if (!alloted) {
                                                                roomTable[dayIndex][tHighestIndex] = "NAlloted";
                                                                errorMessage += "\ndid not allot room for " + timeTable[day][period];
                                                            }
                                                        }
                                                        timeTable[day][period] = currSubject.name;
                                                        teacherTable[day][period] = currTeacher.name;
                                                        curTeach.timeTable[day][period] = 1;
                                                        curTeach.timeTable[day][period] = 1;
                                                        curTeach.timeTableName[day][period] = name;
                                                        credCount--;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (credCount) {
                            //if exectution reaches here it means that we cant allot with the current input combination.
                            errorMessage += std::to_string(credCount) + " session for " + currSubject.name + " couldnt be alloted.";
                            errorCore.push_back(currSubject.name);
                        }
                    }
                }
            }
        }
        else {
            currDefaultRooms = currSubject.rooms;
            std::cout << "defaults untu";
            std::vector<int> scoreRoom;
            for (auto currClass : currDefaultRooms) {
                int score = 0;
                room& curr = returnRoom(currClass);
                for (auto day : curr.timeTable) {
                    for (auto period : day) {
                        if (!period) {
                            score++;
                        }
                    }
                }
                scoreRoom.push_back(score);
            }
            int highestR = 0, highestindexR = -1;
            for (int i = 0; i < scoreRoom.size(); i++) {
                if (scoreRoom[i] > highestR) {
                    highestR = scoreRoom[i];
                    highestindexR = i;
                }
            }
            if (highestindexR != -1) {
                defaultRoom = returnRoom(currDefaultRooms[highestindexR]);
                goto rep;
            }
            else {
                errorMessage += "check default rooms.  \n";
                std::cout << "no classroom found in defaults";
            }
        }
    }
    //Formatting output
    std::string dayList[] = { "MON","TUE","WED","THU","FRI","SAT" };
    for (int day = 0; day < days; day++) {
        formattedOutput += dayList[day] + ",";
        for (int period = 0; period < periods; period++) {
            if (!(period % 2) && period != 0) {
                formattedOutput += ",";
            }
            formattedOutput += timeTable[day][period] + ",";
        }
        formattedOutput += "\n";
    }
}
std::string section::getConsolidatedRoom() {
    std::string CSV = "m1,m2,m3,m4,m5,m6,t1,t2,t3,t4,t5,t6,w1,ww2,w3,w4,w5,w5,t1,t2,t3,t4,t5,t6,f1,f2,f3,f4,f5,f6,s1,s2,s3,s4,s5,s6\n";
    std::vector<std::vector<std::string>> consolidatedTable(periods * days);
    for (room Room : allRooms) {
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < periods; j++) {
                if (!Room.timeTable[i][j]) {
                    consolidatedTable[i * periods + j].push_back(Room.name);
                }
            }
        }
    }
    for (int k = 0; k < 1000; k++) {
        bool found = false;
        for (int i = 0; i < days * periods; i++) {
            if (consolidatedTable[i].size() >= k) {
                found = true;
                CSV += consolidatedTable[i][k] + ",";
            }
            else {
                CSV += ",";
            }
        }
        if (!found) {
            break;
        }
        CSV += "\n";
    }
    return CSV;
}