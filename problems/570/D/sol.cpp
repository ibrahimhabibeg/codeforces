#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
int mp[N], mpC, s[N];
vector<int> adj[N];
vector<pair<int, int>> d[N];
char st[N];

int cs(int u){
  s[u] = 1;
  for(int v: adj[u]) s[u]+=cs(v);
  return s[u];
}

void dfs(int u, int dp){
  mp[u] = mpC;
  int sz = d[dp].size();
  int c = st[u-1] - 'a';
  d[dp].push_back(make_pair(mpC, d[dp][sz-1].second^(1<<c)));
  mpC++;
  for (int v: adj[u]) dfs(v, dp+1);
}

int main(){
  int n, m, p, x, h;
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) adj[i].clear(), d[i].clear(), d[i].push_back(make_pair(0,0));    
  for (int i = 2; i <= n; i++) scanf("%d", &p), adj[p].push_back(i);
  scanf("%s", st);
  mpC = 1;
  cs(1);
  dfs(1, 1);
  while (m--){
    scanf("%d%d", &x, &h);
    auto itL = lower_bound(d[h].begin(), d[h].end(), make_pair(mp[x], 0));
    auto itR = lower_bound(d[h].begin(), d[h].end(), make_pair(mp[x] + s[x], 0));
    itL--;
    itR--;
    auto p1 = *itL, p2 = *itR;
    int y = p1.second ^ p2.second, c1 = 0;
    while (y) c1+=y%2, y/=2;
    if(c1<=1) printf("Yes\n");
    else printf("No\n");
  }
}