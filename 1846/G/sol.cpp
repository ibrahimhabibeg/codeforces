#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF = 1e9; 

int main(){
  int TC, n, m, s;
  string  g, h;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    cin >> g;
    s = stoi(g, nullptr, 2);
    int a[m], r[m], t[m];
    for (int i = 0; i < m; i++) {
      scanf("%d", &t[i]);
      cin >> g >> h;
      r[i] = stoi(g, nullptr, 2), a[i] = stoi(h, nullptr, 2);
    }
    vector<pair<int, int>> adj[1<<(n+1)];
    vector<bool> dis(1<<(n+1));
    vector<int> d(1<<(n+1), INF);
    for (int x = 0; x < 1<<(n+1); x++) for (int i = 0; i < m; i++) adj[x].push_back(make_pair(a[i]|(x&(x^r[i])), t[i]));
    set<pair<int, int>> st;
    st.insert(make_pair(0, s));
    d[s] = 0;
    while (!st.empty()){
      auto it = st.begin();
      pair<int, int> p = *it;
      int u = p.second;
      dis[u] = true;
      for (auto &[v, w] :  adj[u]) if(!dis[v] && d[u]+w<d[v]) st.erase(make_pair(d[v], v)), d[v] = d[u] + w, st.insert(make_pair(d[v], v));
      st.erase(it);
    }
    if(!dis[0]) printf("-1\n");
    else printf("%d\n", d[0]);
  }   
}