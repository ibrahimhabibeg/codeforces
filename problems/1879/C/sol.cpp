#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 998244353;

int main(){
  int TC;
  string s;
  cin >> TC;
  while (TC--){
    cin >> s;
    int n = s.size(), r = 0, d = 1, f[n+1], g = 1;
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = (i*1LL*f[i-1])%MOD;
    for (int i = 1; i < n; i++){
      if(s[i]!=s[i-1]){
        r+=g-1;
        if(g>1) d = (d*1LL*g)%MOD;
        g=1;
      }else g++;
    }
    r+=g-1;
    if(g>1) d = (d*1LL*g)%MOD;
    d = (d*1LL*f[r])%MOD;
    printf("%d %d\n", r, d);
  }   
}