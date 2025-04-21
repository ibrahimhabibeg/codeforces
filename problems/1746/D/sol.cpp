#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5 +5;
int s[N];
vector<int> adj[N];
vector<pair<int,ll>> dp[N];
 
ll dfs(int u, int x){
  for(auto [y,ans]: dp[u]) if(y==x) return ans;
  ll res = s[u]*1ll*x;
  int c = adj[u].size();
  if(c==0) res+=0;
  else if(x%c==0) for(int v: adj[u]) res+=dfs(v, x/c);
  else{
    ll b[c];
    for(int i= 0; i<c; i++) {
      int v = adj[u][i];
      ll y = dfs(v,x/c), z = dfs(v,1+(x/c));
      res+=y;
      b[i] = z - y;
    }
    sort(b, b+c, greater<ll>());
    for(int i= 0; i< x%c; i++) res+=b[i];
  }
  dp[u].push_back({x,res});
  return res;
}
 
int main(){
  int TC, n, p, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) adj[i].clear(), dp[i].clear();
    for (int i = 2; i <= n; i++) scanf("%d", &p), adj[p].push_back(i);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    printf("%lld\n", dfs(1,k));
  }   
}
