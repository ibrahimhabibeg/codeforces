#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 +5;
vector<pair<int,ll>> adj[N], radj[N];
ll f[N];
ll INF = 1e15;

int main(){
  int n, m, a, b;
  ll w;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) adj[i].clear(), radj[i].clear(), f[i] = INF; 
  for (int i = 0; i < m; i++) 
    scanf("%d%d%lld", &a, &b, &w), adj[a].push_back(make_pair(b, w)), radj[b].push_back(make_pair(a, w));
  f[1] = 0;
  set<pair<ll, int>> s;
  for (int i = 1; i <= n; i++) s.insert(make_pair(f[i], i));
  while(!s.empty()){
    auto it = s.begin();
    int u = (*it).second;
    s.erase(it);
    for (auto &[v, w]: adj[u]) if(w+f[u]<f[v]) s.erase(make_pair(f[v], v)), f[v] = w+f[u], s.insert(make_pair(f[v], v));
  }
  for (int i = 1; i <= n; i++) s.insert(make_pair(f[i], i));
  while(!s.empty()){
    auto it = s.begin();
    int u = (*it).second;
    s.erase(it);
    for (auto &[v, w]: radj[u]) if(w+f[u]<f[v]) s.erase(make_pair(f[v], v)), f[v] = w+f[u], s.insert(make_pair(f[v], v));
  }
  for (int i = 2; i <= n; i++){
    if(f[i]==INF) printf("-1 ");
    else printf("%lld ", f[i]);
  }
  printf("\n");
    
}