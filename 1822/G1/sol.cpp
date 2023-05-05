#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main()
{
  int TC, n, v;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    vi d;
    unordered_map<int, ll> mp;
    int max_val = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> v;
      if (mp.find(v) == mp.end())
      {
        d.push_back(v);
        mp[v] = 1;
        max_val = max(max_val, v);
      }
      else
        mp[v]++;
    }
    ll res = 0;
    for (int x : d)
    {
      res += mp[x] * (mp[x] - 1) * (mp[x] - 2);
      for (int b = 2; x * b * b <= max_val; b++)
        if(mp.find(x*b)!=mp.end() && mp.find(x*b*b)!=mp.end()) res += mp[x] * mp[x*b] * mp[x*b*b];
    }
    cout << res << "\n";
  }
}