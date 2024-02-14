#include<string>
#include"configs.cpp"
#include<iostream>
#include<vector>
//includes
//namespace declaration
class room {
public:
    std::string name;
    int capacity = 0;
    bool labOrNot = 0;
    std::string building;
    std::vector<std::vector<bool>> timeTable;//when room is free. 0 for free 1 for occupiued.
    std::vector<std::vector<unsigned>> timeTableName;//what class the rooms is holding. changes done by program, not taken from user.
    bool readData(std::string inp);
    void showTimeTable();
    std::string convertToString();
    room() {
        std::vector<bool> a(periods);
        std::vector<unsigned> b(periods, 0);
        for (int i = 0; i < days; i++) {
            timeTable.push_back(a);
            timeTableName.push_back(b);
        }
    }//initialise all classes to zero.
};
void room::showTimeTable() {
    for (int i = 0; i < days; i++) {
        for (int j = 0; j < periods; j++) {
            std::cout << timeTable[i][j] << " , ";
        }
        std::cout << std::endl;
    }
}
bool room::readData(std::string inp) {
    enum format {
        namen,
        capacityn,
        labOrNotn,
        buildingn,
        timeTablen
    };
    int commacount = 0;
    try {
        for (int i = 0; i < inp.size(); i++) {
            if (inp[i] == ',') {
                commacount++;
                continue;
            }
            switch (commacount) {
            case namen:
                name.push_back(inp[i]);
                break;//read name
            case capacityn:
                capacity = capacity * 10 + inp[i] - '0';
                break;//read branch
            case labOrNotn:
                labOrNot = inp[i] - '0';
                break;//read workhours
            case buildingn:
                building.push_back(inp[i]);
                break;//read name
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
std::string room::convertToString() {
    std::string output;
    output += name + "," + std::to_string(capacity) + "," + std::to_string(labOrNot) + "," + building;
    for (int i = 0; i < days; i++) {
        for (int j = 0; j < days; j++) {
            output += "," + std::to_string(timeTable[i][j]) + "," + std::to_string(timeTableName[i][j]);
        }
    }
    return output;
}