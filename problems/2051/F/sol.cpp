#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m, q, x;
  scanf("%d%d%d", &n, &m, &q);
  vector<pair<int,int>> v;
  v.push_back(make_pair(m, m));
  while(q--) {
    scanf("%d", &x);
    multiset<pair<int, int>> s;
    for(auto p: v) {
      int a = p.first, b = p.second;
      if(x<a) {
        s.insert(make_pair(max(0, a-1), b));
      } else if(x>b) {
        s.insert(make_pair(a, min(b+1, n)));
      } else {
        s.insert(make_pair(1,1));
        s.insert(make_pair(n,n));
        if(a<b) s.insert(make_pair(a,b));
      }
    }
    vector<pair<int, int>> nv;
    nv.push_back(*s.begin());
    s.erase(s.begin());
    while (!s.empty()){
      auto p = *s.begin();
      s.erase(s.begin());
      if(p.first<=nv[nv.size()-1].second) nv[nv.size()-1].second = max(nv[nv.size()-1].second, p.second);
      else nv.push_back(p);
    }
    v = nv;
    int res = 0;
    for (auto p: v) res += p.second - p.first + 1;
    printf("%d ", res);
  }
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}