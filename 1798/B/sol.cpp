#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, m, p;
  cin >> TC;
  while (TC--)
  {
    cin >> m;
    vector<int> v[m];
    for (int i = 0; i < m; i++)
    {
      cin >> n;
      for (int j = 0; j < n; j++)
      {
        cin >> p;
        v[i].push_back(p);
      }
    }
    bool isYes = true;
    int ans[m];
    unordered_set<int> s;
    for (int i = m - 1; i >= 0; i--)
    {
      int j = 0;
      while (j < v[i].size() && s.find(v[i][j]) != s.end())
        j++;
      if (j == v[i].size())
      {
        isYes = false;
        break;
      }
      ans[i] = v[i][j];
      for (int a : v[i])
        s.insert(a);
    }
    if (!isYes)
      cout << "-1";
    else
      for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << "\n";
  }
}