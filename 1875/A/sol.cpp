#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll a, b, n, x;
  cin >> TC;
  while (TC--){
    scanf("%lld%lld%lld", &a, &b, &n);
    ll res = b;
    for (int i = 0; i < n; i++) scanf("%lld", &x),  res+=min(x, a-1);
    printf("%lld\n", res);
  }   
}