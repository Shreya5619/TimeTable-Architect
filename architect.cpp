#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"includes.h"
#include"initializer_list"
// using namespace std;
class section {
public:
    int name;
    std::vector<teacher> allTeachers;
    std::vector<std::string> coreTeachers;
    std::vector<subject> coreSubjects;
    void addCore(std::string Teacher, subject Subject);


    std::vector<std::vector<std::string>> labTeachers;
    std::vector<subject> labSubjects;
    std::vector<int> noOfLabs;
    std::vector<int> noTeachersPerLab;
    void addLab(std::vector<std::string> teacherList, subject Subject, int noLabs, int noTeachersLab);
    //make a vector type list of the names of teachers who can take the subject. then pass a subject object to the function
    //third parameter is how many lab rooms do you need per session Last is how many teachers you need per lab

    std::vector<room> allRooms;
    std::vector<std::string> defaultRooms;
    std::vector<std::vector<std::string>> timeTable;
    std::vector<std::vector<std::string>> teacherTable;
    std::vector<std::vector<std::string>> roomTable;

    void block(int i, int j, std::string Teacher, std::string Subject);
    void makeTIMETABLE();
    void showTimeTable();
    void showTeacherTable();
    void showRoomTable();
    section() {
        std::vector<std::string> deff = { "f","f","f","f","f","f" };
        std::vector<std::string> defNA = { "NA","NA","NA","NA","NA","NA" };
        for (int i = 0; i < days; i++) {
            timeTable.push_back(deff);
            teacherTable.push_back(deff);
            roomTable.push_back(defNA);
            bfactor.push_back(0);
        }
    }

    bool error_;
    std::string errorMessage;
    int _intersections;// a variable reserved for th enext function. the fucntion will alter this number 
    //and change it to how many intersections it has found
    //returns a vector of vector of bools. 0 represents all the timetables are free at that period,day. 
    //1 represents not all are free
private:
    std::vector<int> bfactor;
    std::vector<std::vector<std::string>> returnCombinations(std::vector<std::string> comb, int required);
    std::vector<std::vector<bool>> findIntersection(std::vector<std::vector<std::vector<bool>>> inputs, std::vector<std::vector<std::string>> def = {});
    room& returnRoom(std::string name);
    teacher& returnTeacher(std::string inp);
    subject& returnSubject(std::string inp);
    std::vector<std::vector<int>> findWeightageLab(std::vector < std::vector<bool>> inp, std::vector<teacher> teachers);//fucntion returns a matrix of weightAge for each intersection. 
    std::vector<std::vector<int>> findWeightageCore(std::vector < std::vector<bool>> inp, teacher teachers);//fucntion returns a matrix of weightAge for each intersection.
};
void section::addCore(std::string Teacher, subject Subject) {
    coreTeachers.push_back(Teacher);
    coreSubjects.push_back(Subject);
}
void section::block(int i, int j, std::string Teacher, std::string Subject) {
    timeTable[i][j] = Teacher;
    teacherTable[i][j] = Subject;
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

//a function that returns all possible 'required' number of combinations from the vector of teacghers. designed for finding all possible lab allotments.
std::vector<std::vector<std::string>> section::returnCombinations(std::vector<std::string> comb, int required) {
    std::vector<std::vector<std::string>> sols;
    std::vector<int>ptrs;
    //making the inital state of the ptrs array. 
    for (int i = 0; i < required; i++) {
        ptrs.push_back(i);
    }
    bool trigger = 1;
    while (trigger) {
        //this part is adding the combination to the total liost of combination
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
void section::makeTIMETABLE() {
    //alloting labs
    for (int i = 0; i < labTeachers.size(); i++) {
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
            for (auto day : intersection) {
                for (int k = 0; k < day.size(); k += 2) {
                    if (!day[k] && !day[k + 1]) {
                        intersectionCount++;
                        break;
                    }
                }
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
                            if (intersectionScore[f][g] > tops[l]) {
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
                std::vector<int> temp(6, 1);
                std::vector<std::vector<int>> ans(6, std::vector<int>(6, 1));
                //make a days*periods empty matrix
                interSectionList.push_back(ans);
                score.push_back(-1);
            }
        }
        //finding the best possible combination. adding all the factors index referes to the combination
        int index = 0;
        int indexScore = -1;
        for (int f = 0; f < score.size(); f++) {
            if (score[f] > indexScore) {
                indexScore = score[f];
                index = f;
            }
        }
        std::cout << "index: " << index << " indexscore " << indexScore << "\n";
        //if credits satisfied
        if (indexScore != -1) {
            //here allotment starts
            int credCount = labSubjects[i].credits;
            //coming back here if credits not satisfied
        repeatLt:
            //find best credits number of intersections
            std::vector<int> tops(credCount, 0);
            for (int f = 0; f < days; f++) {
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
            //iterate through each period
            for (int k = 0; k < days; k++) {
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
                if (highest >= tops[0] && credCount) {
                    //assgign timetable name
                    timeTable[k][highestindex] = labSubjects[i].name;
                    timeTable[k][highestindex + 1] = labSubjects[i].name;
                    std::string teacherString;
                    std::string roomString;
                    //making teacher and room string a,b,c,d format
                    for (auto teachers : allCombs[index][0]) {
                        teacherString += teachers + " , ";
                    }
                    for (auto rooms : allCombs[index][1]) {
                        roomString += rooms + " , ";
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
                    for (auto rooms : allCombs[index][0]) {
                        room& r = returnRoom(rooms);
                        r.timeTable[k][highestindex] = 1;
                        r.timeTable[k][highestindex + 1] = 1;
                        r.timeTableName[k][highestindex] = name;
                        r.timeTableName[k][highestindex + 1] = name;
                    }
                    //decrease the factors to reduce prefereence of allotment on same time again
                    for (int j = 0; j < days; j++) {
                        interSectionList[index][j][highestindex] /= 2;
                        interSectionList[index][j][highestindex + 1] /= 2;
                    }
                    //convert thew period to -1 to prevent further allotment on the same day.
                    interSectionList[index][k][0] = -1;
                    //reduce commacount
                    credCount--;
                }
            }
            if (credCount) {
                goto repeatLt;//repeat from ranking process.
            }
        }
        else {
            errorMessage += "oops! collision occured when alloting " + labSubjects[i].name + "  \n";
        }
    }
    //find preferred clasroom
    std::vector<int> scoreRoom;
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
        scoreRoom.push_back(score);
    }
    int highestR = 0, highestindexR = -1;
    for (int i = 0; i < scoreRoom.size(); i++) {
        if (scoreRoom[i] > highestR) {
            highestR = scoreRoom[i];
            highestindexR = i;
        }
    }
    room& defaultRoomP = returnRoom(defaultRooms[highestindexR]);
    room& defaultRoom = returnRoom(defaultRooms[highestindexR]);
    //coreteachers allocation
    for (int subjects = 0; subjects < coreSubjects.size(); subjects++) {
        teacher& currTeacher = returnTeacher(coreTeachers[subjects]);
        subject currSubject = coreSubjects[subjects];
        std::cout << "\ncurrent: " << currSubject.name << "\n";
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
                                    scoredTable[j][highestindex] /= 1.5;
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
                        //
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
}
