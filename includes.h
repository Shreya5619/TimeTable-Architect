#pragma once
#include<string>
#include<vector>
#include<ctime>
#include"configs.cpp"
class subject {
public:
    std::string name;
    std::string title;
    std::string elective;
    std::string courseCode;
    bool lab;
    int credits, hoursPerCredit;
    unsigned short int bFactor;
    std::vector<std::string> rooms;
    bool readData(std::string inp);
    std::string convertToString();
    subject() {
        credits = 0;
        hoursPerCredit = 0;
        bFactor = 0;
    };
};

class teacher {
public:
    std::string name;//name of teacher
    std::string branch;//branch of teacher
    std::string email;
    std::vector<std::vector<bool>> timeTable;//when teacher is free. 1 for free 0 for occupiued.
    std::vector<std::vector<std::string>> timeTableName;//what teacher is teaching when occupied. changes done by program, not taken from user.

    bool readData(std::string inp);//function which converts std::string input from teacherdata to the objects data
    std::string convertToString();//reverse of above
    void showTimeTable();
    teacher() {
        std::vector<bool> a(periods);
        std::vector<std::string> b(periods,"");
        for (int i = 0; i < days; i++) {
            timeTable.push_back(a);
            timeTableName.push_back(b);
        }
    }
};

class room {
public:
    std::string name;
    int capacity = 0;
    bool labOrNot = 0;
    std::string building;
    std::vector<std::vector<bool>> timeTable;//when room is free. 0 for free 1 for occupiued.
    std::vector<std::vector<std::string>> timeTableName;//what class the rooms is holding. changes done by program, not taken from user.
    bool readData(std::string inp);
    void showTimeTable();
    std::string convertToString();
    room() {
        std::vector<bool> a(periods);
        std::vector<std::string> b(periods,"");
        for (int i = 0; i < days; i++) {
            timeTable.push_back(a);
            timeTableName.push_back(b);
        }
    }//initialise all classes to zero.
};

class settings {
    public:
        std::string path;
        int freeFactor=0;
        float reductionIndex = 0;
        std::vector<std::vector<bool>> defaultReserve;
        std::string convertToString();
        bool readData(std::string inp);
};

class logger {
public:
    std::string path;
    void init() {
        // Get the current system time
        std::time_t currentTime = std::time(nullptr);

        // Convert the system time to a string representation
        std::string timeString = std::ctime(&currentTime);

        // Print the current time
        std::cout << timeString << std::endl;
        //split timestring wiht spoaces
        std::vector<std::string> timeVector;
        std::string temp = "";
        for (int i = 0; i < timeString.size(); i++) {
            if (timeString[i] != ' ') {
                temp.push_back(timeString[i]);
            }
            else {
                timeVector.push_back(temp);
                temp = "";
            }
        }
        // Iterate through timeVector and print its elements
        for (const auto& time : timeVector) {
            path += time;
        }
    }
    void log(std::string message) {
        std::fstream file;
        file.open("logs/" + path, std::ios::app);
        if (file.is_open()) {
            file << message << "\n";
            file.close();
        }
        else {
            // Failed to open the file
            std::cout << "Failed to open the file." << std::endl;
        }
    }
};
class section {
public:
    std::string name;
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
    std::string formattedOutput;

    void block(int i, int j, std::string Teacher, std::string Subject);
    void makeTIMETABLE();
    void showTimeTable();
    void showTeacherTable();
    void showRoomTable();
    section() {
        log += "Section object constructor";
        std::vector<std::string> deff = { "f","f","f","f","f","f" };
        std::vector<std::string> defNA = { "NA","NA","NA","NA","NA","NA" };
        log += "\ninside constructor going to initialise timeTable,roomTable,teacherTable and bfactor";
        for (int i = 0; i < days; i++) {
            timeTable.push_back(deff);
            teacherTable.push_back(deff);
            roomTable.push_back(defNA);
            bfactor.push_back(0);
        }
        log += "\ninitialisation of tables done, going to exit constructor.";
        std::vector<bool>temp(days, 0);
        labAllotment = temp;
        formattedOutput = "TIME DAY,9:00-10:00,10:00-11:00,,11:30-12:30,12:30-1:30,,2:30-3:30,3:30-4:30\n";
    }
    std::string convertToString();
    bool readData(std::string inp);
    bool deAllocate();//used to deallocate a class
    bool error_;
    std::string errorMessage;
    int _intersections;// a variable reserved for the findIntersection function. the fucntion will alter this number 
    std::string log;// log of where the program has reached.
    //and change it to how many intersections it has found
    //returns a vector of vector of bools. 0 represents all the timetables are free at that period,day. 
    //1 represents not all are free 
    //the following factors are used by findWeightageLab for scoring which periods to use for allotment. change the following to adjust allotment
    int busyFactorL = 10;//busy factor is addded if teacher is either busy before or after the period.
    int freeFactorL = 25;//freefactor is addded if teacher is either free before or after the period
    int baseFactorL = 5;//it helps in choosing teachers that are already free over the others.

    //the following factors are used by findWeightageCore for scoring which periods to use for allotment. change the following to adjust allotment
    int busyFactorC = 10;//busy factor is addded if teacher is either busy before or after the period.
    int freeFactorC = 25;//freefactor is addded if teacher is either free before or after the period
    int baseFactorC = 5;//this factor is added to all the subjects, it helps in choosing teachers that are already free over the others.
    float reductionIndexC = 1.2;//this factor is used to discourage alloting same class same time again.Score of all the possible intersections in the same time are divided by this factor.
    logger logs;//a logging object
private:
    std::vector<int> bfactor;
    std::vector<std::vector<std::string>> returnCombinations(std::vector<std::string> comb, int required);
    std::vector<std::vector<bool>> findIntersection(std::vector<std::vector<std::vector<bool>>> inputs, std::vector<std::vector<std::string>> def = {});
    room& returnRoom(std::string name);
    teacher& returnTeacher(std::string inp);
    subject& returnSubject(std::string inp);
    std::vector<std::vector<int>> findWeightageLab(std::vector < std::vector<bool>> inp, std::vector<teacher> teachers);//fucntion returns a matrix of weightAge for each intersection. 
    std::vector<std::vector<int>> findWeightageCore(std::vector < std::vector<bool>> inp, teacher teachers);//fucntion returns a matrix of weightAge for each intersection.
    std::vector<std::string> section::splitString(const std::string& str, char delimiter);
    std::vector<bool> labAllotment;
};
