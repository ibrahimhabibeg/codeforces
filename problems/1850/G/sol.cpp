#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x, y;
  cin >> TC;
  while (TC--)
  {
    map<int, int> h, v, d1, d2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
      scanf("%d %d", &x, &y);
      h[x]++, v[y]++, d1[y-x]++, d2[x+y]++;
    }
    ll res = 0;
    for (auto const& [key, val] : h) res += val*1LL*(val-1);
    for (auto const& [key, val] : v) res += val*1LL*(val-1);
    for (auto const& [key, val] : d1) res += val*1LL*(val-1);
    for (auto const& [key, val] : d2) res += val*1LL*(val-1);
    printf("%lld\n", res);
  }   
}