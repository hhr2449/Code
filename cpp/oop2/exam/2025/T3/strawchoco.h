#pragma once
class Strawberry : public EventInterface{

public:
    int mood;
    Strawberry() : mood(0) {}
    ~Strawberry(){}

    int get_mood() {
        return mood;
    }
    void increase_mood(int value) {
        mood += value;
    }

    void zoo(EventInterface* e) {
        e->increase_mood(1);
    }
    void shop(EventInterface* e){
        e->increase_mood(5);
    }
    void birthday(){

    }
};
class Chocolate : public EventInterface{
    
public:
int mood;
    Chocolate() : mood(0) {}
    ~Chocolate() {}

    int get_mood() {
        return mood;
    }
    void increase_mood(int value) {
        mood += value;
    }

    void zoo(EventInterface* e) {
        e->increase_mood(5);
    }
    void shop(EventInterface* e) {
        e->increase_mood(1);
    }
    void birthday() {

    }
};