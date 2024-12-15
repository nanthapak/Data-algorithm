#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long modi=100000007;
    long long a = 3, b = 7, temp;
    for (int i = 2; i < n; i++)
    {
        temp=a;
        a=b;
        b=(b*2+temp)%modi;
    }
    cout << b;
}
