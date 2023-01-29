//https://youtu.be/z5YfyOy_Vd4?list=PLDyQeDg5RtW8XJZ5mt7sK0L0eGodtxpE-
// copy this code in 
// https://cppinsights.io/
// to view what compiler generates for the below code
#include<bits/stdc++.h>
using namespace std;

template<typename Derived>
class Employee{
public:
    Derived& getDerived(){
        return static_cast<Derived&>(*this);
    }

    void printSalary(){
        getDerived().printSalary();
    }

};
//------------------------------------------
class Engineer: public Employee<Engineer>
{
public:
    void printSalary(){
        cout<< "Engineer salary"<<endl; 
    }

};

class Manager: public  Employee<Manager>
{
public:
    void printSalary(){
        cout<< "Manager salary"<<endl; 
    }

};
//------------------------------------------
template<typename T>
void printSalary(Employee<T>& emp){
    emp.printSalary();
}

int main(){
    
    Engineer eng;
    printSalary(eng);

    Manager mgr;
    printSalary(mgr);
    return 0;
}

