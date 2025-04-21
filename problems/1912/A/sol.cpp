#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll x, k, l, a;
  scanf("%lld%lld", &x, &k);
  multiset<pair<pair<ll,ll>,pair<ll,ll>>> s;
  vector<vector<pair<ll,ll>>> b(k);
  for (int i = 0; i < k; i++){
    scanf("%lld", &l);
    ll sm = 0, mn = 0;
    for (int j= 0; j< l; j++){
      scanf("%lld", &a);
      sm+=a, mn = min(mn, sm);
      if(sm>0){
        b[i].push_back(make_pair(-mn,sm));
        sm = mn = 0;
      } 
    }
    if(b[i].size()>0) s.insert(make_pair(b[i][0], make_pair(i,0)));
  }
  while (!s.empty()){
    auto p = *(s.begin());
    if(x>=p.first.first){
      x+=p.first.second, s.erase(s.begin());
      if(b[p.second.first].size()>p.second.second+1) s.insert(make_pair(b[p.second.first][p.second.second+1], make_pair(p.second.first,p.second.second+1)));
    } 
    else break;
  }
  printf("%lld", x);
}