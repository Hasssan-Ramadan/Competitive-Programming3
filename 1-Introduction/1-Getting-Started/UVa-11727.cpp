#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int k = t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if ((x > y && z < y) || (z > y && x < y))
        {
            cout << "Case " << k - t << ": " << y << endl;
        }
        else if ((x > z && y < z) || (y > z && x < z))
        {
            cout << "Case " << k - t << ": " << z << endl;
        }
        else
        {
            cout << "Case " << k - t << ": " << x << endl;
        }
    }
}