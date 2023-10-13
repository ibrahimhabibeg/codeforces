#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> c(n+1);
    int a[n];
    ll res = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int j = 1; j < n; j++){
      c[a[j-1]]++;
      for (int l = j+2; l < n; l++){
        dp[j][l] = dp[j][l-1]+c[a[l-1]];
        if(a[j]==a[l]) res+=dp[j][l];
      }
    }
    printf("%lld\n", res);
  }   
}