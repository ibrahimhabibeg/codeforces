#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9 +7;

int inv(ll x)
{
  int y = MOD - 2;
  ll z = 1;
  while(y){
    if(y%2==1) z = (z*x)%MOD;
    y/=2;
    x = (x*x)%MOD;
  }
  return z%MOD;
}

int main(){
  int TC, n, m, x;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &m);
    vector<int> a;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &x);
      mp[x]++;
      if(mp[x]==1) a.push_back(x);
    }
    sort(a.begin(), a.end());
    int len = 0;
    ll res = 0, p = 1;
    for (int i = 0; i < a.size(); i++) {
      if(i!=0 && a[i]!=a[i-1]+1) len = 1;
      else len++;
      if(i>=m) p = (p*inv(mp[a[i-m]]))%MOD;
      p = (p*mp[a[i]])%MOD;
      if(len>=m) res  = (res + p)%MOD;
    }
    printf("%lld\n", res);
  }   
}