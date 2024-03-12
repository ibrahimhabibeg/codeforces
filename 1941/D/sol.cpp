#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, k, d;
  char c;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &m, &k);
    vector<bool> dp(n);
    dp[k-1] = true;
    for (int j = 0; j < m; j++){
      vector<bool> ndp(n);
      scanf("%d", &d);
      cin >> c;
      for (int i = 0; i < n; i++){
        if(c!='1') ndp[(i+d)%n] = ndp[(i+d)%n] || dp[i];
        if(c!='0') ndp[(i-d+n)%n] = ndp[(i-d+n)%n] || dp[i];
      }
      dp = ndp;
    }
    int res = 0;
    for (int i = 0; i < n; i++) if(dp[i]) res++;
    printf("%d\n", res);
    for (int i = 0; i < n; i++) if(dp[i]) printf("%d ", i+1);
    printf("\n");
  }   
}