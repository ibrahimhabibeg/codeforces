#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    int l = 1, r = n+1;
    while (l<r){
      int m = (l+r)/2;
      ll g1 = m/3, g2=m/3, g3=m/3; 
      if(m%3==1) g1++;
      else if(m%3==2) g1++, g2++;
      ll v = 2*1ll*(g1*g2+g1*g3+g2*g3);
      if(v>=n) r = m;
      else l = m+1;
    }
    printf("%d\n", l);
  } 
}