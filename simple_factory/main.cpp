/* ************************************************************************
> File Name:     main.cpp
> Author:        Sean
> Project:    LeetCode
> Created Time:  Sun Oct 17 15:47:14 2021
> Description:   
 ************************************************************************/
#include <iostream> 
#include <memory> 

using namespace std; 

template <typename T> 
class Operation {
protected:
    T _numA; 
    T _numB;
public: 
    Operation() : _numA(0), _numB(0) {

    }

    T GetNumA() {
        return _numA;
    }
    T GetNumB() {
        return _numB;
    }

    void SetNumA(T num) {
        _numA = num; 
    }
    void SetNumB(T num) {
        _numB = num; 
    }

    virtual T GetResult() = 0; 
};

// note how to inherit from template base class 
template <typename T> 
class OperationAdd : public Operation<T> {
public: 
    T GetResult() override {
        // need to use this due to template type 
        return this->_numA + this->_numB; 
    }
};

template <typename T>
class OperationSub : public Operation<T> {
public:
    T GetResult() override {
        return this->_numA - this->_numB;
    }
};

template <typename T>
class OperationMul : public Operation<T> {
public:
    T GetResult() override {
        return this->_numA * this->_numB;
    }
};

template <typename T> 
class OperationDiv : public Operation<T> {
public: 
    T GetResult() override {
        if (this->_numB == 0) {
            return 0;
        } 
        else {
            return this->_numA / this->_numB;
        }
    }
};

template <typename T> 
class OperationFactory {
public: 
    static shared_ptr<Operation<T>> CreateOperation(char type) {
        shared_ptr<Operation<T>> op = nullptr; 
        switch(type) {
            case '+':
                op = make_shared<OperationAdd<T>>();
                break;
            case '-':
                op = make_shared<OperationSub<T>>();
                break;
            case '*':
                op = make_shared<OperationMul<T>>();
                break;
            case '/':
                op = make_shared<OperationDiv<T>>();
                break;
        }
        return op;
    }
};

int main() {
    cout << "enter 1st num: " << endl;
    double numA; 
    cin >> numA;
    cout << "enter operator +,-,*,/: " << endl;
    char opt;
    cin >> opt; 
    cout << "enter 2nd num: " << endl; 
    double numB;
    cin >> numB;

    auto op = OperationFactory<double>::CreateOperation(opt); 
    op->SetNumA(numA);
    op->SetNumB(numB);
    cout << numA << opt << numB << " is " << op->GetResult() << endl;
}
