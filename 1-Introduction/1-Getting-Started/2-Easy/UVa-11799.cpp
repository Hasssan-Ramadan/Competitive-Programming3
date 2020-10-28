#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int k = t;
    while (t--)
    {
        int sp;
        priority_queue<int> s;
        int n;
        cin >> n;
        while (n--)
        {
            cin >> sp;
            s.push(sp);
        }
        cout << "Case " << k - t << ": " << s.top() << endl;
    }
}