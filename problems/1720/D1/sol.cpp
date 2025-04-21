#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], res = 1;
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) for (int j = max(0, i-512); j < i; j++) if((a[j]^i)<(a[i]^j)) dp[i] = max(dp[i], dp[j]+1);
    for (int i = 0; i < n; i++) res = max(res, dp[i]);
    printf("%d\n", res);
  }   
}