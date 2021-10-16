/* ************************************************************************
> File Name:     a5.cpp
> Author:        Sean
> Project:   我们一起学猫叫 
> Created Time:  Sat Oct 16 11:07:05 2021
> Description:   
 ************************************************************************/
#include <string> 

using namespace std; 

class Cat {
private: 
    string _name;
    int _shoutNum; 
public: 
    Cat() : _name("cat"), _shoutNum(3) {

    }
    Cat(const auto& string s, int num) : _name(s), _shoutNum(num) {

    }
    int GetNum() {
        return _shoutNum;
    }
    void SetNum(int value) {
       if (value <= 10) {
           _shoutNum = value; 
       } 
       else 
           _shoutNum = 10; 
    }
    string Shout() {
        string result = "";
        for (int i = 0; i < _shoutNum; ++i) {
            result += "瞄";
        }
        return "我的名字叫做 " + _name + " " + result; 
    }
};

int main() {
    Cat cat("mm", 5);
}
