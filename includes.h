#pragma once
#include<string>
#include<vector>
#include"configs.cpp"
class subject {
public:
    std::string name;
    std::string elective;
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
        lab = false;
    };
};

class teacher {
public:
    std::string name;//name of teacher
    std::string branch;//branch of teacher

    std::vector<std::vector<bool>> timeTable;//when teacher is free. 1 for free 0 for occupiued.
    unsigned int timeTableName[days][periods];//what teacher is teaching when occupied. changes done by program, not taken from user.

    bool readData(std::string inp);//function which converts std::string input from teacherdata to the objects data
    std::string convertToString();//reverse of above
    void showTimeTable();
    teacher() {
        std::vector<bool> a(periods);
        for (int i = 0; i < days; i++) {
            timeTable.push_back(a);
            for (int j = 0; j < periods; j++) {
                timeTableName[i][j] = 0;
            }
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
    int timeTableName[days][periods];//what class the rooms is holding. changes done by program, not taken from user.
    bool readData(std::string inp);
    void showTimeTable();
    std::string convertToString();
    room() {
        std::vector<bool> a(periods);
        for (int i = 0; i < days; i++) {
            timeTable.push_back(a);
            for (int j = 0; j < periods; j++) {
                timeTableName[i][j] = 0;
            }
        }
    }//initialise all classes to zero.
};