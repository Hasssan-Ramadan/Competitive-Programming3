#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.in", "r", stdin);
    int t;
    cin >> t;
    int cnt = 1;
    while (t--)
    {
        string cards[52];
        for (int i = 0; i < 52; i++)
        {
            cin >> cards[i];
        }
        cout << "Case " << cnt++ << ": " << cards[32] << endl;
    }
}
