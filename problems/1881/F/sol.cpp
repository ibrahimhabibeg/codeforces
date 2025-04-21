#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+5;
int d[N];
vector<int> adj[N];

int dfs(int u, int p){
  d[u] = 1+d[p];
  for (int v: adj[u]) if(v!=p) dfs(v, u);
  return d[u];
}

int main(){
  int TC, n, k, x, y;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    vector<int> mk;
    d[0] = -1;
    for (int i = 0; i <= n; i++) adj[i].clear();
    for (int i = 0; i < k; i++) scanf("%d", &x), mk.push_back(x);
    for (int i = 0; i < n-1; i++) scanf("%d%d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
    if(k==1){
      printf("0\n");
      continue;
    }
    dfs(mk[0], 0);
    int a = 0, dis = 0;
    for (int i = 0; i < k; i++) if(d[mk[i]]>d[a]) a = mk[i];
    dfs(a, 0);
    for (int i = 0; i < k; i++) dis = max(dis, d[mk[i]]);
    printf("%d\n", (dis+1)/2);
  }   
}