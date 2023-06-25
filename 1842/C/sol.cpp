#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<int> l(n+1, -1), mx(n+1, -(n+5)), dp(n+1);
    int a[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++){
      dp[i] = dp[i-1];
      if(l[a[i]]!=-1) dp[i] = max(dp[i], i+mx[a[i]]+1);
      else l[a[i]] = i;
      mx[a[i]] = max(mx[a[i]], dp[i-1]-i);
    }
    printf("%d\n", dp[n]);
  }   
}