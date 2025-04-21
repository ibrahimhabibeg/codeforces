#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int a[N], b[N], d, res[N];
vector<int> adj[N];
ll A[N], B[N];

void dfs(int u){
  d++;
  for (int v: adj[u]){
    A[v] = A[u]+a[v];
    B[d-1] = B[d-2] + b[v];
    res[v] = upper_bound(B, B+d, A[v]) - B - 1;
    dfs(v);
  }
  d--;
}

int main(){
  int TC, n, p;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    d=1;
    for(int i=1; i<=n; i++) adj[i].clear();
    for (int i = 2; i <= n; i++) scanf("%d%d%d", &p, &a[i], &b[i]), adj[p].push_back(i);
    B[0] = 0, A[0] = 0;
    dfs(1);
    for (int i = 2; i <= n; i++) printf("%d ", res[i]);
    printf("\n");
  }
}