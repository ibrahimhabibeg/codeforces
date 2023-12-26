#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
vector<int> adj[N];
int dp[N];

int dfs1(int u){
  int mx = 0;
  for(int v: adj[u]) mx=max(mx,dfs1(v));
  return dp[u] = 1 + mx;
}

int dfs(int u){
  int res = 0;
  for(int v: adj[u]) res += max(dfs(v), dp[v]);
  return res;
}

int main(){
  int n, p;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 2; i <= n; i++) scanf("%d", &p), adj[p].push_back(i);
  dfs1(1);
  printf("%d", max(dp[1], dfs(1)));
}