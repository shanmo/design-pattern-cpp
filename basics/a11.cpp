/* ************************************************************************
> File Name:     a11.cpp
> Author:        Sean
> Project:    LeetCode
> Created Time:  Sat Oct 16 15:37:06 2021
> Description:   
 ************************************************************************/
#include <memory> 
#include <iostream> 

using namespace std; 

class Animal {
protected:
    string _name; 
public:
    Animal(const string& name) : _name(name) {

    }
};

class IChange {
public: 
    virtual void ChangeThing(const string& thing) = 0;  
};

class Cat : public Animal, public IChange {
public:
    Cat(const string& name) : Animal(name) {

    }
    void ChangeThing(const string& thing) override {
        cout << "My name is " << _name << " 我会用万能口袋变出 " << thing << endl; 
    }
};

class Monkey : public Animal, public IChange {
public: 
    Monkey(const string& name) : Animal(name) {

    }
    void ChangeThing(const string& thing) override {
        cout << "My name is " << _name << " 我会用毫毛变出 " << thing << endl; 
    }
};

int main() {
    auto cat = make_unique<Cat>("机器猫");
    cat->ChangeThing("Switch游戏机");
    auto mon = make_unique<Monkey>("孙悟空");
    mon->ChangeThing("小猴子");
}
