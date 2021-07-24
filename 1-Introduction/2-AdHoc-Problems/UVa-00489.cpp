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

int main()
{
 setIO();
 int round;
 while (cin >> round, round != -1)
 {
  string solution, guess;
  cin >> solution >> guess;

  int stroke = 0;
  for (int i = 0; i < guess.size() && stroke <= 6 && solution != ""; ++i)
  {
   if (solution.find(guess[i]) != string::npos)
   {
    solution.erase(remove(solution.begin(), solution.end(), guess[i]), solution.end());
   }
   else
    ++stroke;
  }
  cout << "Round " << round << endl;
  if (stroke == 7)
   cout << "You lose." << endl;
  else if (solution == "")
   cout << "You win." << endl;
  else
   cout << "You chickened out." << endl;
 }
 return 0;
}
