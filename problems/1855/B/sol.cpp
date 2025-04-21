#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    ll r = 1;
    while (n%(r+1)==0) r++;
    printf("%lld\n", r);
  }   
}