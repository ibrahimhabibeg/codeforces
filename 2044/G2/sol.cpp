#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n, a[N], s[N]; // 0 -> Not Visited, 1 -> Visited, 2 -> completed
vector<int> p[N];
bool c[N];

void cycle(int u) {
  if(s[u] == 2) return;
  if(s[u]) c[u] = true;
  s[u]++;
  cycle(a[u]);
  s[u] = 2;
}

int sz(int u) {
  int res = 1;
  for(int v: p[u]) res+=sz(v);
  return res;
}

void solve(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) s[i] = 0, p[i].clear(), c[i] = false;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]].push_back(i);
  for (int i = 1; i <= n; i++) cycle(i);
  int res = 2;
  for (int i = 1; i <= n; i++) if(!c[i] && c[a[i]]) res = max(res, 2 + sz(i));
  printf("%d\n", res);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}