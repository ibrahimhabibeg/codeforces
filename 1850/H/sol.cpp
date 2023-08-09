#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;

ll L[N];
bool dis[N];
vector<pair<int,int>> adj[N];

bool dfs(int u){
  dis[u] = true;
  for (auto &[v, d]: adj[u]){
    if(dis[v] && L[v]!=L[u]+d) return false;
    else if(!dis[v]){
      L[v]=L[u]+d;
      if(!dfs(v)) return false;
    }
  }
  return true;
}

int main(){
  int TC, n, m, a, b, d;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) L[i] = 0, dis[i] = false, adj[i].clear();
    for (int i = 0; i < m; i++) scanf("%d%d%d", &a, &b, &d), adj[a].push_back(make_pair(b, d)), adj[b].push_back(make_pair(a, -d));
    bool isYes = true;
    for (int i = 1; i <= n; i++) if(!dis[i]) if(!dfs(i)) {
      isYes = false;
      break;
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}