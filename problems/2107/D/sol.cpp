#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5;
queue<int> unopened;
vector<vector<int>> res;
int n, p[N], dis[N];
bool taken[N];
vector<int> adj[N];

int getFarthestLargestValue(int s) {
  queue<int> q;
  q.push(s);
  vector<bool> found(n+1);
  found[s] = true;
  dis[s] = 1;
  int res;
  while (!q.empty()){
    int sz = q.size(), mxNodeInLevel = 0;
    while (sz--) {
      int u = q.front();
      mxNodeInLevel = max(mxNodeInLevel, u);
      q.pop();
      for(int v: adj[u]) if(!found[v] && !taken[v]) {
        q.push(v);
        found[v] = true;
        p[v] = u;
        dis[v] = dis[u] + 1;
      }
    }
    res = mxNodeInLevel;
  }
  return res;
}

void open(int s) {
  int u = getFarthestLargestValue(s);
  int v = getFarthestLargestValue(u);
  res.push_back({dis[v], max(u, v), min(u, v)});
  int w = v;
  p[u] = 0;
  while(w) {
    taken[w] = true;
    for(int x: adj[w]) if(x!=p[w] && !taken[x]) unopened.push(x);
    w = p[w];
  }
}

void solve(){
  res.clear();
  int u, v;
  cin >> n;

  // Cleanup
  res.clear();
  for (int i = 1; i <= n; i++) adj[i].clear(), taken[i] = false;

  for (int i = 0; i < n-1; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
  unopened.push(1);
  while (!unopened.empty()) {
    int s = unopened.front();
    unopened.pop();
    open(s);
  }
  sort(res.begin(), res.end());
  for (int i = res.size()-1; i >= 0; i--) for(int j = 0; j < 3; j++) cout << res[i][j] << " ";
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