#include<string>
#include<iostream>
#include"configs.cpp"
#include<vector>

class settings {
public:
    std::string path;
    int freeFactor = 0;
    float reductionIndex = 0;
    std::vector<std::vector<bool>> defaultReserve;
    std::string convertToString();
    bool readData(std::string inp);
};

std::string settings::convertToString() {
    std::string out;
    out += path + ',';
    out += std::to_string(freeFactor) + ','+std::to_string((int)reductionIndex*100);
    for (auto a : defaultReserve) {
        for (auto b:a) {
            out += ',' + b;
        }
    }
    return out;
}
bool settings::readData(std::string inp) {
    defaultReserve=std::vector<std::vector<bool>>(6,std::vector<bool>(6,0));
    enum format {
        pathn,
        freeFactorn,
        reductionIndexn,
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
            case pathn:
                path.push_back(inp[i]);
                break;
            case freeFactorn:
                freeFactor+=freeFactor*10+inp[i]-'0';
                break;
            case reductionIndexn:
                reductionIndex += reductionIndex * 10 + inp[i] - '0';
                break;
            case timeTablen:
                commacount = 0;
                int strptr = i;
                while (inp[strptr]) {
                    if (inp[strptr] == ',') {
                        commacount++;
                    }
                    else{
                        defaultReserve[commacount / 12][(commacount % 12) / 2] = inp[strptr] - '0';
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