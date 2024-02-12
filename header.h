#include<iostream>
#include<vector>
#include<string>
#include "teacher.cpp"
#include "subject.cpp"
#include "room.cpp"
using namespace std;
class section {
public:
    int name;
    std::vector<teacher> allTeachers;
    std::vector<string> coreTeachers;
    std::vector<subject> coreSubjects;
    void addCore(string Teacher, subject Subject);


    std::vector<std::vector<string>> labTeachers;
    std::vector<subject> labSubjects;
    std::vector<int> noOfLabs;
    std::vector<int> noTeachersPerLab;
    void addLab(vector<string> teacherList, subject Subject, int noLabs, int noTeachersLab);
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
        vector<string> deff = { "f","f","f","f","f","f" };
        vector<string> defNA = { "NA","NA","NA","NA","NA","NA" };
        for (int i = 0; i < days; i++) {
            timeTable.push_back(deff);
            teacherTable.push_back(deff);
            roomTable.push_back(defNA);
            bfactor.push_back(0);
        }
    }

    bool error_;
    string errorMessage;
    int _intersections;// a variable reserved for th enext function. the fucntion will alter this number 
    //and change it to how many intersections it has found
    //returns a vector of vector of bools. 0 represents all the timetables are free at that period,day. 
    //1 represents not all are free
private:
    vector<int> bfactor;
    vector<vector<string>> returnCombinations(vector<string> comb, int required);
    vector<vector<bool>> findIntersection(std::vector<vector<vector<bool>>> inputs, std::vector<std::vector<std::string>> def = {});
    room& returnRoom(std::string name);
    teacher& returnTeacher(std::string inp);
    subject& returnSubject(std::string inp);
    vector<vector<int>> findWeightageLab(vector < vector<bool>> inp, vector<teacher> teachers);//fucntion returns a matrix of weightAge for each intersection. 
    vector<vector<int>> findWeightageCore(vector < vector<bool>> inp, teacher teachers);//fucntion returns a matrix of weightAge for each intersection.
};