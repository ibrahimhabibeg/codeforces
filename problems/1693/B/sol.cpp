#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
ll s[N], L[N], H[N];
vector<int> adj[N];

ll dfs(int u){
  ll ss = 0, t = 0;
  for(int v: adj[u]) t+=dfs(v), ss+=s[v];
  if(ss>=L[u]){
    s[u] = min(ss, H[u]);
    return t;
  }else{
    s[u] = H[u];
    return t + 1;
  }
}

int main(){
  int TC, n, p;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 2; i <= n; i++) scanf("%d", &p), adj[p].push_back(i);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &L[i], &H[i]);
    printf("%lld\n", dfs(1));
  }   
}