#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
vector<int> p, edges, sze;
vector<vector<int>> adj;
unordered_map<int, int> mp[N];

int dfs(int u){
  sze[u] = 1;
  for(int v: adj[u]) if(v!=p[u]){
    p[v] = u;
    sze[u] += dfs(v);
  }
  return sze[u];
}

bool dp(int u, int r){
  vector<int> cnt(3);
  for(int v: adj[u]) if(v!=p[u]){
    cnt[sze[v]%3]++;
    if(!dp(v, sze[v]%3)) return false;
    if(sze[v]%3==0) edges.push_back(mp[u][v]);
  }
  if(r==0 && ((cnt[2]==1 && cnt[1]==0)||(cnt[2]==0&&cnt[1]==2))) return true;
  if(r==1 && cnt[1]==0 && cnt[2]==0) return true;
  if(r==2 && cnt[1]==1 && cnt[2]==0) return true;
  return false;
}

void solve(){
  int n, a, b;
  scanf("%d", &n);
  adj.clear(), p.clear(), sze.clear();
  edges.resize(0), adj.resize(n+1), p.resize(n+1), sze.resize(n+1);
  for (int i = 0; i < n-1; i++){
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    mp[a][b] = mp[b][a] = i+1;
  }
  if((n%3)!=0){printf("-1\n"); return;}
  dfs(1);
  if(dp(1, 0)){
    printf("%d\n", n/3 -1);
    for (int i: edges) printf("%d ", i);
    printf("\n");  
  } else printf("-1\n");
}

int main(){
  int TC, n, a, b;
  cin >> TC;
  while (TC--) solve();
}