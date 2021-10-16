/* ************************************************************************
> File Name:     a7.cpp
> Author:        Sean
> Project:      inheritance   
> Created Time:  Sat Oct 16 13:27:03 2021
> Description:   
 ************************************************************************/
#include <string>
#include <iostream> 

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
    int GetShoutNum() {
        return _shoutNum;
    }
    void SetShoutNum(int num) {
        _shoutNum = num; 
    }
};

class Cat : public Animal {
public:
    Cat(const string& name) : Animal(name) {

    }
    void Shout() {
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
    void Shout() {
        string result = "";
        for (int i = 0; i < _shoutNum; ++i) {
            result += "汪";
        }
        cout << "My name is " << _name << " " << result << endl;
   }
};

int main() {
    Cat cat("mm");
    cat.Shout();
    Dog dog("ww");
    dog.Shout();
}
