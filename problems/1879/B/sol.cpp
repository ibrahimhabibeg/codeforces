#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll x, n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    ll ma = 1e9+5, mb = 1e9+5, sa = 0, sb = 0;
    for (int i = 0; i < n; i++) scanf("%lld", &x), ma=min(ma,x), sa+=x; 
    for (int i = 0; i < n; i++) scanf("%lld", &x), mb=min(mb,x), sb+=x;
    printf("%lld\n", min(n*ma+sb,n*mb+sa));
  }   
}