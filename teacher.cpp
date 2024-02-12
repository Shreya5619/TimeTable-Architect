#include<string>
#include<iostream>
#include"configs.cpp"
#include<vector>
//includes
//namespace declaration
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
bool teacher::readData(std::string inp) {
    enum format {
        namen,
        branchn,
        //workHoursn,
        timeTablen
    };//Used for switch statements. each field corresponds to its location in the std::string
    int commacount = 0;//numebr of commas encountered
    try {
        for (int i = 0; i < inp.size(); i++) {
            if (inp[i] == ',') {
                commacount++;
                continue;
            }//equivalent to next column
            switch (commacount) {
            case namen:
                name.push_back(inp[i]);
                break;//read name
            case branchn:
                branch.push_back(inp[i]);
                break;//read branch
                /*case workHoursn:
                    workHours=workHours*10+inp[i]-'0';
                    break;//read workhours
                    */
            case timeTablen:
                commacount = 0;
                int strptr = i;
                while (inp[strptr]) {
                    if (inp[strptr] == ',') {
                        commacount++;
                    }
                    else if (!(commacount % 2)) {
                        timeTable[commacount / 12][(commacount % 12) / 2] = inp[strptr] - '0';
                    }
                    else {
                        timeTableName[commacount / 12][(commacount % 12) / 2] = timeTableName[commacount / 12][(commacount % 12) / 2] * 10 + inp[strptr] - '0';
                    }
                    strptr++;
                }
                goto a;
                break;
            }
        }
    }
    catch (...) {
        return 0;
    }
a:
    return 1;
}
std::string teacher::convertToString() {
    std::string output;
    output = name;
    output.push_back(',');
    output += branch;
    //output.push_back(',');
    //output+=std::to_string(workHours);
    for (int i = 0; i < days; i++) {
        for (int j = 0; j < days; j++) {
            output += "," + std::to_string(timeTable[i][j]) + "," + std::to_string(timeTableName[i][j]);
        }
    }
    return output;
}
void teacher::showTimeTable() {
    for (int i = 0; i < days; i++) {
        for (int j = 0; j < periods; j++) {
            std::cout << timeTable[i][j] << "      ";
        }
        std::cout << std::endl;
    }
}