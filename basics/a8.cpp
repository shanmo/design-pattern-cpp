/* ************************************************************************
> File Name:     a8.cpp
> Author:        Sean
> Project:   多态 
> Created Time:  Sat Oct 16 14:33:53 2021
> Description:   
 ************************************************************************/
#include <iostream> 
#include <memory> 

using namespace std; 

class Animal {
protected: 
    string _name;
    int _shoutNum; 
public: 
    Animal() : _name("no name"), _shoutNum(3) {

    }
    Animal(const string& name) : _name(name), _shoutNum(3) {
        
    }
    int GetNum() {
        return _shoutNum;
    }
    void SetNum(int num) {
        _shoutNum = num; 
    }
    virtual void Shout() {
        string result = "";
        for (int i = 0; i < _shoutNum; ++i) {
            result += "???";
        }
        cout << "My name is " << _name << " " << result << endl; 
    }
};

class Cat : public Animal {
public: 
    Cat(const string& name) : Animal(name) {

    }
    void Shout() override {
        string result = "";
        for (int i = 0; i < _shoutNum; ++i) {
            result += "瞄";
        }
        cout << "My name is " << _name << " " << result << endl; 
    }
};

class Dog : public Animal {
public: 
    Dog(const string& name) : Animal(name) {

    }
    void Shout() override {
        string result = "";
        for (int i = 0; i < _shoutNum; ++i) {
            result += "汪";
        }
        cout << "My name is " << _name << " " << result << endl; 
    }
};

int main() {
    auto ani = make_unique<Animal>();
    ani->Shout();
    ani = make_unique<Cat>("mm");
    ani->Shout();
    ani = make_unique<Dog>("ww");
    ani->Shout();
}
