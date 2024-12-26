#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> res;
  int c[n+1];
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(c[i]);
    for (int j = c[i]+1; j <= n; j++) if(s.find(j)==s.end()) res.push_back(make_pair(j, c[i]));
    for (int j = n; j > 0; j--) if(s.find(j)==s.end()) res.push_back(make_pair(c[i], j));
  }
  printf("%d\n", res.size());
  for (auto p: res) printf("%d %d\n", p.first, p.second);
}

int main(){
  solve();
}