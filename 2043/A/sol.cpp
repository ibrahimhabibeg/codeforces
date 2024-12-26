#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  ll n;
  scanf("%lld", &n);
  ll r = -1;
  while(n) n = n >> 2, r++;
  printf("%d\n", 1<<r);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}