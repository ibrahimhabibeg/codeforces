#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 25;
const int Q = 2e5 + 5;
int g[N];
int e[N][N];
pair<int, bool> a[Q];
int n, q;
const int MAX_E = 1e6;
int dp[N][1 << 21];

void initGraph() {
  for (int u = 1; u <= n; u++) for (int v = 1; v <= n; v++) if(u!=v) {
    int w = 0, u_r = 1, v_l = 2;
    for (int i = 0; i < q; i++){
      if(a[i].first==u && a[i].second) {
        u_r++;
        if(u_r==v_l){
          w++;
          v_l++;
        }
      } else if(a[i].first==v && !a[i].second) v_l++; 
    }
    e[u][v] = w;
  }
  for (int i = 1; i <= n; i++) e[i][0] = MAX_E, e[0][i] = 0;
}

int dfs(int u, int visit_mask) {
  if(dp[u][visit_mask] != -1) return dp[u][visit_mask];
  bool didVisitAll = true;
  int res = 1e9;
  for (int i = 1; i <= n; i++) if((visit_mask & (1 << i)) == 0) {
    didVisitAll = false;
    res = min(res, e[u][i] + dfs(i, visit_mask | (1 << i)));
  }
  if(didVisitAll) return dp[u][visit_mask] = g[u];
  return dp[u][visit_mask] = res;
}

void solve(){
  int x;
  char c;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %c", &x, &c);
    a[i] = make_pair(x, c == '+');
    g[x] += c == '+';
  }
  for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << (n+1)); j++) dp[i][j] = -1;
  initGraph();
  printf("%d\n", dfs(0, 1 << 0) + n);
}

int main(){
  solve();
}