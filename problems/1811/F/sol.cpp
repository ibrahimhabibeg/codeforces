#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(){
  int n, a, b;
  ll m;
  scanf("%d %lld", &n, &m);
  vector<int> adj[n+1];
  for (int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if(n<9) return false;
  int k = sqrt(n), cnt2 = 0, cnt4 = 0;
  if(k*k!=n || (n+k)*1LL!=m) return false;
  vector<bool> dis(n+1), sp(n+1);
  for (int i = 1; i <= n; i++) cnt2+=adj[i].size()==2, cnt4+=adj[i].size()==4, sp[i]=adj[i].size()==4;
  if(cnt2!=n-k||cnt4!=k) return false;
  int u = 0;
  while (!sp[u]) u++;
  dis[u] = true;
  int w = u;
  for (int i = 0; i < k-1; i++){
    bool found = false;
    for(int v: adj[w]) if(!dis[v] && sp[v]){
      found = true, w = v;
      break;
    } 
    if(!found) return false;
    dis[w] = true;
  }
  bool ret = false;
  for(int v: adj[w]) if(v==u) ret = true;
  if(!ret) return false;
  for (u = 0; u <=n; u++) if(sp[u]){
    w = u;
    for (int i = 0; i < k-1; i++){
      bool found = false;
      for(int v: adj[w]) if(!dis[v] && !sp[v]){
        found = true, w = v;
        break;
      } 
      if(!found) return false;
      dis[w] = true;
    }
    bool returned = false;
    for(int v: adj[w]) if(v==u) returned = true;
    if(!returned) return false;
  }
  return true;
}

int main(){
  int TC;
  cin >> TC;
  while (TC--) if(solve()) printf("YES\n"); else printf("NO\n");
}