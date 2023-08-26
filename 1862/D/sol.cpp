#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    ll r = (1+sqrt(1+8*n))/2, l = n - ((r*(r-1))/2);
    printf("%lld\n", r+l);
  }   
}