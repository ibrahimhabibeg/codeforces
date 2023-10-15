#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N  = 2e5 + 5;
vector<pair<int, int>> adj[N];
int p[N], c[N], cnt[N][2];

int findSet(int i) {
  if(p[i]==i) return i;
  else return p[i] = findSet(p[i]);
}

void unionSet(int i, int j) {
  int a = findSet(i), b=findSet(j);
  if(a==b) return;
  p[b] = a;
}

bool dfs(int u, int i){
  if(i==u) c[u] = 0, cnt[i][0]++;
  for (auto p:adj[u]){
    int v = p.first, w = p.second;
    if(c[v]==-1){
      c[v]=(c[u]+w)%2;
      cnt[i][c[v]]++;
      if(!dfs(v, i)) return false;
    }else if(c[v]!=(c[u]+w)%2) return false;
  }
  return true;
}

int main(){
  int TC, n, m, a, b;
  char s[9];
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i, c[i]=-1, cnt[i][0]=cnt[i][1]=0, adj[i].clear();
    for (int i = 0; i < m; i++) scanf("%d%d%s", &a, &b, s), adj[a].push_back(make_pair(b, s[0]=='i')), 
    adj[b].push_back(make_pair(a, s[0]=='i')), unionSet(a, b);
    int res = 0;
    for (int i = 1; i <= n; i++) if(p[i]==i) {
      if(dfs(i, i)) res+=max(cnt[i][0], cnt[i][1]);
      else{
        res=-1;
        break;
      }
    }
    printf("%d\n", res);
  }   
}