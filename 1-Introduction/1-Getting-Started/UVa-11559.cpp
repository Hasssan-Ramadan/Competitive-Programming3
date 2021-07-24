#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b, h, w;
    while (cin >> n >> b >> h >> w)
    {
        int minmum = INFINITY;
        int c, mw;
        for (int i = 0; i < h; i++)
        {
            cin >> c;
            cin >> mw;
            for (int j = 1; j < w; j++)
            {
                int m;
                cin >> m;
                mw = max(mw, m);
            }
            if (mw >= n)
            {
                minmum = min(minmum, n * c);
            }
        }
        if (minmum <= b)
        {
            cout << minmum << endl;
        }
        else
        {
            cout << "stay home" << endl;
        }
    }
}