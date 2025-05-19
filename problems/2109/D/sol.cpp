#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int INF = 2e9 + 10;
int n, dis[N][2];
set<vector<int>> q;
vector<int> adj[N];

void eraseFromQ(int u, int p) {
  auto it = q.find({dis[u][p], u, p});
  if(it != q.end()) q.erase(it);
}

void addToQ(int u, int p) {
  q.insert({dis[u][p], u, p});
}

void expand(int u, int p) {
  int ip = (p+1)%2, d = dis[u][p] + 1;
  for (int v: adj[u]) if(d<dis[v][ip]) {
      eraseFromQ(v, ip);
      dis[v][ip] = d;
      addToQ(v, ip);
  }
} 

void solve(){
  int m, l, x, y;
  cin >> n >> m >> l;
  for (int i = 1; i <= n; i++) dis[i][0] = INF, dis[i][1] = INF, adj[i].clear();
  int min_odd = 1e5, sm = 0, lar_odd, lar_even;
  bool foundOdd = false;
  for (int i = 0; i < l; i++) {
    cin >> x;
    sm += x;
    if(x%2) min_odd = min(x, min_odd), foundOdd = true;
  }
  if(sm%2) {
    lar_odd = sm;
    if(foundOdd) lar_even = sm - min_odd;
    else lar_even = -1;
  } else {
    lar_even = sm;
    if(foundOdd) lar_odd = sm - min_odd;
    else lar_odd = -1;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dis[1][0] = 0;
  addToQ(1, 0);
  while (!q.empty()) {
    auto it = q.begin();
    int u = (*it)[1], p = (*it)[2];
    q.erase(it);
    expand(u, p);
  }
  for(int u = 1; u<=n; u++) {
    if(dis[u][0]<=lar_even || dis[u][1] <= lar_odd) cout << 1;
    else cout << 0;
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TC = 1;
  cin >> TC;
  while(TC--){
    solve();
  }
}