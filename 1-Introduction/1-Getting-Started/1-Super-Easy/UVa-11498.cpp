#include <bits/stdc++.h>
using namespace std;

class point
{
private:
    int x;
    int y;

public:
    point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void compare(point temp)
    {
        if (x > temp.x && y > temp.y)
        {
            cout << "SO" << endl;
        }
        else if (x < temp.x && y < temp.y)
        {
            cout << "NE" << endl;
        }
        else if (x > temp.x && y < temp.y)
        {
            cout << "NO" << endl;
        }
        else if (x < temp.x && y > temp.y)
        {
            cout << "SE" << endl;
        }
        else
        {
            cout << "divisa" << endl;
        }
    }
};

int main()
{
    int k = 0;
    while (cin >> k)
    {
        if (k == 0)
            return 0;
        int x, y;
        cin >> x >> y;
        point div(x, y);
        while (k--)
        {
            cin >> x >> y;
            point temp(x, y);
            div.compare(temp);
        }
    }
}