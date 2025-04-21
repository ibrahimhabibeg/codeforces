#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPossible(ll h, ll w, multiset<pair<int,int>> a, multiset<pair<int,int>> b){
  while (!b.empty())
  {
    auto big_h = *a.rbegin(), big_w = *b.rbegin();
    if(big_h.first==h && big_h.second<=w){
      w-=big_h.second;
      b.erase(b.find({big_h.second, big_h.first})), a.erase(a.find({big_h.first, big_h.second}));
    }else if(big_w.first==w && big_w.second<=h){
      h-=big_w.second;
      a.erase(a.find({big_w.second, big_w.first})), b.erase(b.find({big_w.first, big_w.second}));
    }
    else return false;
  }
  return true;
}

int main(){
  int TC, n, a, b;
  cin >> TC;
  while (TC--)
  {
    multiset<pair<int,int>> a_set, b_set;
    int mx_h = 0, mx_w = 0;
    ll area = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d %d", &a, &b);
      mx_h = max(mx_h, a), mx_w = max(mx_w, b);
      a_set.insert({a,b}), b_set.insert({b, a});
      area += a * 1LL * b;
    }
    bool wYes = (area % mx_w) == 0 && isPossible(area / mx_w, mx_w, a_set, b_set);
    bool hYes = (area%mx_h)==0 && mx_w != area/mx_h && isPossible(mx_h, area / mx_h, a_set, b_set);
    printf("%d\n", wYes + hYes);
    if(hYes) printf("%d %llu\n", mx_h, area / mx_h);
    if(wYes) printf("%llu %d\n", area / mx_w, mx_w);
  }   
}