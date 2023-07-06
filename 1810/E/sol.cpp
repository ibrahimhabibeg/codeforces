#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200006;

vector<int> adj[N];
int dis[N], a[N], n;

bool isPoss(int u){
  int sz = 0;
  set<pair<int,int>> s;
  s.insert(make_pair(a[u], u));
  while (!s.empty()){
    pair<int, int> p = *(s.begin());
    if(p.first>sz) break;
    dis[p.second] = u;
    s.erase(s.begin());
    sz++;
    for (int v: adj[p.second]) if(dis[v]<u) s.insert(make_pair(a[v], v));
  }
  return sz==n;
}

int main(){
  int TC, m, x, y;
  cin >> TC;
  while (TC--){
    scanf("%d %d", &n, &m);
    for(int i= 1; i<=n; i++) dis[i] = 0, adj[i].clear(), scanf("%d", &a[i]);
    for(int i= 1; i<=m; i++) scanf("%d %d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
    bool isYes = false;
    for(int i= 1; i<=n; i++) if(a[i]==0 && dis[i]==0) if(isPoss(i)){
      isYes = true;
      break;
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}