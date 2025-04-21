#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 998244353;

int main(){
  int n;
  scanf("%d", &n);
  vector<int> f(n+1);
  for (int d = 1; d <= n; d++) for(int i = d; i<=n; i+=d) f[i]++;
  int c = f[0];
  for (int i = 1; i <=n; i++) f[i] = (f[i]+c)%MOD, c=(c+f[i])%MOD;
  printf("%d\n", f[n]);
}