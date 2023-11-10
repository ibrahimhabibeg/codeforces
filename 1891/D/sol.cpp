#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

__int128 MOD = 1e9 +7;

int main(){
  int TC;
  cin >> TC;
  __int128 pow[61];
  pow[0] = 1;
  for (int i = 1; i < 61; i++) pow[i] = 2*pow[i-1];
  while (TC--){
    ll fst, snd;
    scanf("%lld%lld", &fst, &snd);
    __int128 l = fst, r = snd;
    r++;
    ll res = 0;
    for (__int128 y = 2; y<60; y++){
      __int128 z = 1, lPow = y, hPow = y*y;
      while (lPow<pow[y+1]){
        if(hPow<0) hPow = r;
        __int128 s = max(lPow, max(l,pow[y])), e = min(hPow, min(r,pow[y+1]));
        if(e>s) res = (res+((e-s)%MOD)*z)%MOD;
        z++, lPow*=y, hPow*=y;
      }
    }
    printf("%lld\n", res);
  }   
}