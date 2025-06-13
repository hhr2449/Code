#include "agent.h"
#include "coder.h"
#include "tester.h"
Agent* Agent::create_agent(int agent_type, int id, std::string& codes) {
    if(agent_type == 0) {
        Agent* a =  new Coder(id, codes);
        return a;
    }
    else {
        char marker_;
        int flag_;
        cin >> marker_ >> flag_;
        Agent* a = new Tester(id, codes, marker_, flag_);
        return a;
    }
}