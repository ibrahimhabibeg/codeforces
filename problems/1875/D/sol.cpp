#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<int> c(n), dp(n+1, 1e9);
    for (int i = 0; i < n; i++){
      scanf("%d", &a);
      if(a<n)c[a]++;
    }
    dp[0] = 0;
    for (int v = 1; v <=n; v++){
      for (int i = 0; i<v; i++)
       dp[v] = min(dp[v], v*max(0,c[i]-1)+i+dp[i]);
    }
    int res = dp[n];
    for (int v = 0; v <n; v++) if(c[v]==0) res = min(res, dp[v]);
    printf("%d\n", res);
  }   
}