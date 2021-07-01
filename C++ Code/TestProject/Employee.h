#include<string>
using namespace std;
class Employee
{
    private:
    string name;
    int age;
    public:
    Employee();
    Employee(string n, int a);
    void getData();
    void showData();
};
