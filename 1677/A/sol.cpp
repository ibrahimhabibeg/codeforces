#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int j = 0;  j< n; j++) for (int i = 1;  i<=j; i++) 
      dp[i][j] = dp[i-1][j] + (a[i-1]<a[j]);
    ll res = 0;
    for (int i = 0; i < n; i++){
      ll r = 0;
      for (int j = i+2; j<n; j++){ 
        r+=dp[i][j-1];
        if(a[i]>a[j]) res+=r;
      }
    } 
    printf("%lld\n", res);
  }   
}