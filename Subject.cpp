#include<string>
#include"configs.cpp"
#include<iostream>
#include<vector>
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
bool subject::readData(std::string inp) {
    enum format {
        namen,
        titlen,
        courseCoden,
        electiven,
        labn,
        creditsn,
        hoursPerCreditn,
        bFactorn,
        roomsn,
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
                name.push_back(inp[i]);
                break;
            case titlen:
                title.push_back(inp[i]);
                break;
            case courseCoden:
                courseCode.push_back(inp[i]);
                break;
            case electiven:
                elective.push_back(inp[i]);
                break;
            case labn:
                lab = inp[i] - '0';
                break;
            case creditsn:
                credits = credits * 10 + inp[i] - '0';
                break;
            case hoursPerCreditn:
                hoursPerCredit = hoursPerCredit * 10 + inp[i] - '0';
                break;
            case bFactorn:
                bFactor = bFactor * 10 + inp[i] - '0';
                break;
            case roomsn:
                int commaCount = 0;
                i++;
                std::vector<std::string> temp;
                rooms.push_back("");
                while (true) {
                    if (inp[i] == ']') {
                        break;
                    }
                    else if (inp[i] == ',') {
                        rooms.push_back("");
                        commaCount++;
                    }
                    else {
                        rooms[commaCount].push_back(inp[i]);
                    }
                    i++;
                }

            }
        }
        return 1;
    }
    catch (...) {
        return 0;
    }
}
std::string subject::convertToString() {
    std::string out;
    out = name + ",";
    out += title + ",";
    out += courseCode + ",";
    out += elective + ",";
    out += std::to_string(lab) + ",";
    out += std::to_string(credits) + ",";
    out += std::to_string(hoursPerCredit) + ",";
    out += std::to_string(bFactor) + ",[";
    for (int i = 0; i < rooms.size() - 1; i++) {
        out += rooms[i] + ",";
    }
    out += rooms[rooms.size() - 1] + "]";
    return out;
}