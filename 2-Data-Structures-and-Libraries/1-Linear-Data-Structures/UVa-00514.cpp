#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int N, c;
void marshal()
{
    while (true)
    {
        stack<int> cars;
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &c);
            if (c == 0)
                return;
            while (j < N && j != c)
            {
                if (cars.size() > 0 && cars.top() == c)
                    break;
                j++;
                cars.push(j);
            }
            if (cars.top() == c)
                cars.pop();
        }
        if (cars.size() == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main()
{
    setIO();
    while (true)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        marshal();
        printf("\n");
    }
}