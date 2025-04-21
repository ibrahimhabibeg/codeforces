#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int adj[N];
bool dis[N];
int res;

void dfs(int u) {
  if(dis[u]) return;
  res++;
  dis[u] = true;
  dfs(adj[u]);
}

void solve(){
  int n;
  scanf("%d", &n);
  int a[n+1], pos[n+1], d[n+1];
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[a[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= n; i++) adj[i] = pos[i], dis[i] = false;
  res = 0;
  for (int i = 1; i <= n; i++) dfs(d[i]), printf("%d ", res);
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}