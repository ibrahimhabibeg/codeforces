#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9+7;

int main(){
  int n;
  scanf("%d", &n);
  int pow[n+1], x[n];
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  pow[0] = 1;
  for (int i = 1; i <= n; i++) pow[i] = (pow[i-1]*2)%MOD;
  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      int l = lower_bound(x, x+n, 2*x[i]-x[j]) - x, r = lower_bound(x, x+n, 2*x[j]-x[i]) - x;
      ans = (ans + pow[l+n-r])%MOD;
    }
  }
  printf("%d", ans);  
}