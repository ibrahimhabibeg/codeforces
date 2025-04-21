#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<int> s;
vector<int> adj[200007];
 
int dfs(int u, int p){
  int res = 1;
  for(int v: adj[u]) if(v^p) res += dfs(v, u);
  return s[u] = res;  
}
 
int MOD = 1e9 + 7;
 
int main(){
  int n, k, a, b;
  scanf("%d %d", &n, &k);
  if(k%2==1){cout << 1; return 0;}
  s.resize(n+1);
  for (int i = 0; i < n-1; i++)
  {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  ll p = (n*1LL*(n-1)/2)%MOD, q = p;
  for (int u = 1; u <= n; u++) p = (p + s[u]*1LL*(n-s[u]))%MOD;
  ll x = q, z = MOD-2, y = 1;
  while (z)
  {
    if(z%2) y = (y*x) % MOD;
    x = (x*x)%MOD;
    z/=2;
  }
  ll res = (p * y) % MOD;
  cout << res << "\n";
}