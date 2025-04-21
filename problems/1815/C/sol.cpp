#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF = 2000;

int main(){
  int TC, n, m, a, b;
  cin >> TC;
  while (TC--){
    scanf("%d %d", &n, &m);
    vector<int> d(n+1, INF), res;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++){
      scanf("%d %d", &a, &b);
      adj[b].push_back(a);      
    }
    d[1] = 0;
    int f = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
      int s = q.size();
      for (int i = 0; i < s; i++){
        int u = q.front();
        q.pop();
        for (int v: adj[u]) if(d[v]==INF){
          d[v] = f;
          q.push(v);
        }
      }
      f++;
    }
    vector<vector<int>>l (f);
    bool isFinite = true;
    for (int i = 1; i <= n; i++){
      if(d[i]==INF) isFinite = false;
      else l[d[i]].push_back(i);
    }
    if(!isFinite){
      printf("INFINITE\n");
      continue;
    }
    for (int i = f-1; i >= 0; i--) for (int j = i; j < f; j++) for (int k: l[j]) res.push_back(k);
    printf("FINITE\n%d\n", (int) res.size());
    for (int i: res) printf("%d ", i);
    printf("\n");
  }   
}