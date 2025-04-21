#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binPow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if(b&1) res*=a;
    a*=a;
    b>>=1;
  }
  return res;
}

void solve(){
  ll n;
  scanf("%lld", &n);
  printf("%lld\n", (9*n-3)*1ll*binPow(4, n-3));
}

int main(){
  int TC = 1;
  // scanf("%d", &TC);
  while(TC--){
    solve();
  }
}