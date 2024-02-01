#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    ll a, b, r, x = 0;
    scanf("%lld%lld%lld", &a, &b, &r);
    if(a<b) swap(a, b);
    bool foundFirst = false;
    for (int i = 63; i >=0; i--){
      ll ac = (a>>i)%2, bc = (b>>i)%2;
      if(ac!=bc && foundFirst){
        ll xc = 1^bc;
        if((x + (xc<<i))<= r) x+=(xc<<i);
      }
      foundFirst = foundFirst || ac!=bc;
    }
    printf("%lld\n", abs((a^x)-(b^x)));
  }   
}