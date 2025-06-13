#pragma once 
#include "agent.h"
class Tester : public Agent{
    public:
    int agent_id;
    std::string& codes;
    char marker;
    int flag;
    int pass = 0;
    Tester(int id, std::string& codes, char marker_, int flag_): Agent(id, codes), agent_id(id), codes(codes), marker(marker_), flag(flag_) {}
    void action() {
        int cnt = 0;
        for(int i = 0; i < codes.size(); i++) {
            if(codes[i] == marker) {
                cnt++;
            }
        }
        if(cnt%2 == flag) {
            pass++;
        }
    }
    void report() {
        cout << "Tester " << agent_id <<": " << pass << " tests passed" << '\n';
    }
    ~Tester(){}
};