#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
  if(b) return gcd(b, a%b);
  return a;
}

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    int g = gcd(n, m), on = n, om = m;
    n/=g, m/=g;
    ll res = 0;
    int p = 0, v = 1;
    while (v<m) p++, v*=2;
    if(v!=m){
      printf("-1\n");
      continue;
    }
    for (int i = 0; i <= p; i++){
      int a = n/v;
      n%=v, v/=2, on-=a*om, res+=on, on*=2;
    }
    printf("%lld\n", res);
  }   
}