#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000 + 5;
ll s[N], dp[N];
vector<pair<int,ll>> adj[N];
int n;

ll f(int st){
  if(dp[st]>-1) return dp[st];
  vector<ll> d(n+1, 1e12);
  d[st] = 0;
  set<pair<ll, int>> q;
  for (int i = 1; i <= n; i++) q.insert(make_pair(d[i], i)); 
  while (!q.empty()){
    auto it = q.begin();
    int u = (*it).second;
    q.erase(it);
    for(auto &[v, w]: adj[u]) if(d[u]+s[st]*w<d[v])
    q.erase(make_pair(d[v], v)), d[v] = d[u]+s[st]*w, q.insert(make_pair(d[v], v));
  }
  dp[st] = d[n];
  for (int i = 1; i <= n; i++) if(s[i]<s[st]) dp[st] = min(dp[st], d[i]+f(i));
  return dp[st];
}

int main(){
  int TC, m, x, y;
  ll z;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) adj[i].clear(), dp[i] = -1;
    for (int i = 0; i < m; i++) scanf("%d%d%lld",&x, &y, &z), adj[x].push_back(make_pair(y, z)), adj[y].push_back(make_pair(x, z));
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
    printf("%lld\n", f(1));
  }   
}