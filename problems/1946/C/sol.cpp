#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int dp[N], s[N];
vector<int> adj[N];

int calcS(int u, int p){
  s[u] = 1;
  for(int v:adj[u]) if(v!=p) s[u]+=calcS(v, u);
  return s[u];
}

int f(int u, int x, int p){
  int ans = 0;
  dp[u] = 0;
  for(int v:adj[u]) if(v!=p) ans+=f(v, x, u), dp[u]+=dp[v];
  if(s[u]-dp[u]>=x) dp[u] = s[u], ans++;
  return ans;
}

int main(){
  int TC, n, k, a, b;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) scanf("%d%d", &a, &b), adj[a].push_back(b), adj[b].push_back(a);
    calcS(1, 0);
    int l = 1, r = n;
    while (l<r){
      int m = (l+r+1)/2;
      if(f(1, m, 0)-1>=k)
      l = m;
      else
      r = m-1;
    }
    printf("%d\n", l);
  }   
}