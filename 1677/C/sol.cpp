#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
bool dis[N];
int adj[N];

int dfs(int u){
  dis[u] = true;
  int res = 1;
  if(!dis[adj[u]]) res += dfs(adj[u]);
  return res;
}

int main(){
  int TC;
  ll n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), dis[i+1] = false;
    for (int i = 0; i < n; i++) scanf("%d", &adj[a[i]]);
    ll c = 0;
    for (int i = 1; i <= n; i++) if(!dis[i]) c+=dfs(i)/2;
    ll res = n*(n+1) - (n-c)*(n-c+1) - c*(c+1);
    printf("%lld\n", res);
  }   
}