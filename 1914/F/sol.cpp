#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 +5;
vector<int> adj[N];
int s[N], dp[N];

int dfs(int u){
  bool isFirstFound = false;
  int mx = 0;
  for (int v:adj[u]){
    int x = dfs(v);
    if(!isFirstFound || x>dp[mx]) mx=v, isFirstFound = true;
  }
  if(!isFirstFound) return dp[u] = 1;
  int sm = s[u]-1-s[mx]+dp[mx];
  if(sm%2) return dp[u] = 2 + 2*(max(0,dp[mx]-1-(sm/2)));
  else return dp[u] = 1+2*(max(0,dp[mx]-(sm/2)));
}

int sz(int u){
  s[u] = 1;
  for (int v: adj[u]) s[u]+=sz(v);
  return s[u];
}

int main(){
  int TC, n, a;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 2; i <= n; i++) scanf("%d", &a), adj[a].push_back(i);
    sz(1);
    printf("%d\n", (n-dfs(1))/2);
  }   
}