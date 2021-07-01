#include <iostream>
using namespace std;
class temp_F;
class temp_C
{
    float degree;

public:
    float tofahr(float c)
    {
        return (9 * c) / 5 + 32;
    }
    temp_C(float val)
    {
        degree = val;
    }
    friend void add(temp_C &c, temp_F &f);
};
class temp_F
{
    float degree;

public:
    float tocelsius(float f)
    {
        return ((f - 32) * 5) / 9;
    }
    temp_F(float val)
    {
        degree = val;
    }
    friend void add(temp_C &c, temp_F &f);
};
void add(temp_C &c, temp_F &f)
{
    int n;
    float ans;
    cout << "You want ans in \n1) Fahrenheit\n2) Celsius" << endl;
    cin >> n;
    if (n == 1)
    {
        ans = f.degree + c.tofahr(c.degree);
        cout << "\nFahrenheit : " << ans << endl;
    }
    else if (n == 2)
    {
        ans = c.degree + f.tocelsius(f.degree);
        cout << "\nCelsius : " << ans << endl;
    }
}
int main()
{
    float c;
    float f;
    cout << "\nEnter Celsius" << endl;
    cin >> c;
    cout << "\nEnter Fahrenheit" << endl;
    cin >> f;
    temp_C cel(c);
    temp_F fah(f);

    add(cel, fah);
    return 0;
}