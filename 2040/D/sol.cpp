#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, x, y;
  scanf("%d", &n);
  int a[n], odd = 2*n, even = 2, level = 1;
  vector<int> adj[n+1];
  for (int i = 0; i < n-1; i++) scanf("%d%d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
  queue<int> q;
  q.push(1);
  bool b[n+1];
  for (int i = 1; i <= n; i++) b[i] = false;
  while (!q.empty()){
    int sz = q.size();
    while (sz--){
      int u = q.front();
      b[u] = true;
      q.pop();
      if(level%2) a[u] = odd, odd-=2;
      else a[u] = even, even +=2;
      for (int v: adj[u]) if(!b[v]) q.push(v);
    }
    level++;
  }
  q.push(1);
  for (int i = 1; i <= n; i++) b[i] = false;
  while (!q.empty()){
    int sz = q.size();
    while (sz--){
      int u = q.front();
      b[u] = true;
      q.pop();
      for (int v: adj[u]) if(!b[v]) {
        if(abs(a[u]-a[v])==2) a[v] = a[u] - 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}