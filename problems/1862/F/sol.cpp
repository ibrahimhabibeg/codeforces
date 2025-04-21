#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, w, f;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &w, &f, &n);
    int sum = 0, a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum+=a[i];
    vector<bool> dp(sum+1);
    dp[0] = true;
    for (int i = 0; i < n; i++)  for (int s = sum; s - a[i] >= 0; s--) dp[s] = dp[s] || dp[s-a[i]];
    int res = 2e9;
    for (int i = 0; i <= sum; i++) if(dp[i]) 
      res = min(res, max((i+w-1)/w, (sum-i+f-1)/f));
    printf("%d\n", res);
  }   
}