#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18;

int main(){
  int n, m, a, b, c;
  scanf("%d %d", &n, &m);
  vector<int> adj[n+1], dis(n+1);
  vector<string> res;
  vector<ll> resTime;
  vector<vector<ll>> w(n+1, vector<ll>(n+1));
  for (int i = 0; i < m; i++){
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back(b);
    adj[b].push_back(a);
    w[a][b] = c;
    w[b][a] = c;
  }
  set<pair<ll,int>> s;
  vector<pair<ll, int>> dist(n+1);
  for (int i = 0; i <= n; i++) dist[i] = make_pair(INF, i);
  s.insert(make_pair(0, 1));
  dist[1].first = 0;
  while (!s.empty()) {
    int u = (*s.begin()).second;
    s.erase(s.begin());
    dis[u] = true;
    for (int v: adj[u]) if(!dis[v]) 
      if (dist[v].first > dist[u].first + w[u][v]) {
        s.erase(make_pair(dist[v].first, v));
        dist[v].first = dist[u].first + w[u][v];
        s.insert(make_pair(dist[v].first, v));
      }
  }
  if(dist[n].first==INF) {printf("inf"); return 0;}  
  ll time = 0,endTime = dist[n].first;
  sort(dist.begin(), dist.end());
  int i = 0;
  string st;
  for (int i = 0; i < n; i++) st+='0';
  while (dist[i].first<endTime){
    st[dist[i].second-1] = '1';
    int j = i+1;
    while (dist[j].first==dist[i].first) st[dist[j++].second-1] = '1';
    res.push_back(st);
    resTime.push_back(dist[j].first-dist[i].first);
    time = dist[j].first;
    i = j;
  }
  printf("%lld %lld\n", time, res.size()*1LL);
  for (int i = 0; i < res.size(); i++){
    cout << res[i];
    printf(" %lld\n", resTime[i]);
  }
}