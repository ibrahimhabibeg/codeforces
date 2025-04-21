#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef vector<int> vi;

int main()
{
  int TC, n, s1, s2, x;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> s1 >> s2;
    vector<pr> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i].first;
      v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vi a, b;
    for (int i = 0; i < n; i++)
    {
      if ((a.size() + 1) * s1 <= (b.size() + 1) * s2)
        a.push_back(v[i].second);
      else
        b.push_back(v[i].second);
    }
    cout << a.size();
    for (int c : a)
      cout << " " << c;
    cout << "\n"
         << b.size();
    for (int c : b)
      cout << " " << c;
    cout << "\n";
  }
}