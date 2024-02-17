
#include<vector>
#include<string>
#include "includes.h"
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