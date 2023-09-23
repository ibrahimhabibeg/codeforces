#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+5;
bool c[N], dis[2][N];
int l[2][N], p[N];
vector<int> adj[N];

bool dfs(int u){
  for(int v: adj[u]){
    if(p[v]==0){
      p[v] = u;
      if(dfs(v)) return true;
    }  
    else if(v!=p[u]){
      c[v] = true;
      int w = u;
      while (w!=v) c[w]=true, w=p[w];
      return true;
    }
  }
  return false;
}

void bfs(int r, int f){
  int d = 0;
  queue<int> q;
  q.push(r);
  dis[f][r] = true;
  while (!q.empty()){
    int s = q.size();
    while (s--){
      int u = q.front();
      q.pop();
      l[f][u] = d;
      for(int v: adj[u]) if(!dis[f][v])  dis[f][v] = true, q.push(v);
    }
    d++;
  }
}

int main(){
  int TC, n, a, b, y, z;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i <= n; i++) c[i] = dis[0][i] = dis[1][i] = false, p[i] = 0, l[0][i] = l[1][i] = n+2, adj[i].clear();
    for (int i = 0; i < n; i++) scanf("%d%d", &y, &z), adj[y].push_back(z), adj[z].push_back(y);
    p[1] = -1;
    dfs(1), bfs(a, 0), bfs(b,1);
    int x = -1;
    for (int i = 1; i <= n; i++) if(c[i]) {
      if(x==-1) x = i;
      else if(l[1][i]<l[1][x]) x = i;
    }
    if(l[0][x]<=l[1][x]) printf("NO\n");
    else printf("YES\n");
  }   
}