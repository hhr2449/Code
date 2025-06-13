#pragma once
#include "card.h"
#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Cards {
    list<Card> l;
public:
    Cards() = default;

    Cards(std::string n, std::vector<int> v) {
        for(int num : v) {
            l.emplace_back(n, num);
        }
    }

    void put(Card c) {
        l.push_front(c);
    }

    void print() {
        if(l.empty()) {
            cout << "empty" << endl;
            return;
        }
        for(const auto& card : l) {
            cout << card << ' ';
        }
        cout << endl;
    }

    int count() {
        return l.size();
    }

    void merge(Cards &other) {
        if(other.l.empty()) return;
        
        if(l.empty()) {
            l.splice(l.end(), other.l);
            return;
        }
        
        // 异或操作
        l.back().number ^= other.l.front().number;
        
        // 合并牌堆
        l.splice(l.end(), other.l);
    }
};