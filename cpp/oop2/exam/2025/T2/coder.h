#pragma once 
#include "agent.h"
using namespace std;
class Coder : public Agent{
    public:
    int agent_id;
    std::string& codes;
    int sum = 0;
    Coder(int id, std::string& codes): Agent(id, codes), agent_id(id), codes(codes) {}
    void action() {
        std::string str;
        cin >> str;
        codes += str;
        sum += str.size();
    }
    void report() {
        cout << "Coder " << agent_id <<": " << sum << " characters coded" << '\n';
    }
    ~Coder(){}
};