#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  vector<vector<int>> g(26);
  int n;
  string s;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    int a = 0, b = 0;
    for (char c: s)
    {
      a |= (1<<(c-'a'));
      b ^= (1<<(c-'a')); 
    }
    int x = 1, y = 0;
    while (y<26)
    {
      if((x&a)==0) g[y].push_back(b);
      y++;
      x = x<<1;
    }
  }
  int c = (1<<26) - 1;
  ll res = 0;
  for (int k = 0; k < 26; k++)
  {
    unordered_map<int, int> mp;
    for (int b: g[k])
    {
      res+=mp[(1<<k)^c^b];
      mp[b]++;
    }
  }
  printf("%llu", res);
}