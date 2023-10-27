#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int a[N], xr[N];
vector<int> adj[N];
bool isOddYes;

int dfs(int u, int p){
  xr[u] = a[u];
  for (int v: adj[u]) if(v!=p) xr[u]^=dfs(v,u);
  return xr[u];
}

bool dfs2(int u, int p){
  bool res = xr[u]==xr[1];
  int cnt = 0;
  for (int v: adj[u]) if(v!=p) {
    bool d = dfs2(v,u);
    cnt+=d, res|=d;
  }
  if(cnt>1||(cnt==1&&xr[u]==0)) isOddYes = true;
  return res;
}

int main(){
  int TC, n, k, c, b;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), adj[i].clear();
    for (int i = 0; i < n-1; i++) scanf("%d%d", &c, &b), adj[c].push_back(b), adj[b].push_back(c);
    dfs(1,0);
    if(xr[1]==0){
      printf("YES\n");
      continue;
    }
    isOddYes = false;
    dfs2(1,0);
    if(isOddYes&&k>2) printf("YES\n");
    else printf("NO\n");
  }   
}