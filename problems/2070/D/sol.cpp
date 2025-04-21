#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

void solve(){
  int n, x;
  scanf("%d", &n);
  vector<int> adj[n+1];
  for (int i = 2; i <= n; i++) scanf("%d", &x), adj[x].push_back(i);
  int D = 0;
  vector<vector<int>> a;
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    int sz = q.size();
    a.push_back(vector<int>());
    while (sz--){
     int u = q.front();
     a[D].push_back(u);
     q.pop();
     for (int v: adj[u]) q.push(v);
    }
    D++;
  }
  vector<ll> F(D+1), f(n+1);
  for (int d = D-1; d>0; d--) for(int u: a[d]) {
    f[u] = (1 + F[d+1])%MOD;
    for(int v: adj[u]) f[u] = (f[u]-f[v])%MOD;
    F[d]= (F[d]+f[u])%MOD; 
  }
  F[1] = (F[1]+1+MOD)%MOD;
  printf("%lld\n", F[1]);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}