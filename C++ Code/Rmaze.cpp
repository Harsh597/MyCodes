#include <iostream>
using namespace std;
int countPathMaze(int n, int i, int j)
{
    if (i >= n || j >= n)
        return 0;
    if (i == n - 1 || j == n - 1)//getting same ans for OR operator and AND operator
        return 1;

    return countPathMaze(n, i + 1, j) + countPathMaze(n, i, j + 1);
}
int main()
{
    cout << countPathMaze(10, 0, 0);
    return 0;
}
