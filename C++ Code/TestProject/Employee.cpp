#include<iostream>
#include "C:\Users\harsh\OneDrive\Documents\C++ Code\TestProject\Employee.h"
using namespace std;
Employee::Employee()
{
    name="";
    age=0;
}
Employee::Employee(string n,int a)
{
    name=n;
    age=a;
}
void Employee::getData()
{
    cout<<endl<<"Enter name and age"<<endl;
    cin>>name>>age;
}
void Employee::showData()
{
    cout<<"name= "<<name<<endl<<"age= "<<age<<endl;
}
