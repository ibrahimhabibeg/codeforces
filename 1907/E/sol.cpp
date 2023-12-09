#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    ll n, res = 1;
    scanf("%lld", &n);
    while(n){
      int a = n%10;
      res*=1+a+((a*(a+1))/2);
      n/=10;
    }
    printf("%lld\n", res);
  }   
}