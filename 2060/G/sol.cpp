#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
  int n;
  scanf("%d", &n);
  vector<vector<int>> a(n, vector<int>(2));
  for (int i = 0; i < n; i++) scanf("%d", &a[i][0]);
  for (int i = 0; i < n; i++) scanf("%d", &a[i][1]);
  sort(a.begin(), a.end(), [](vector<int> x, vector<int> y) {
    return min(x[0], x[1]) < min(y[0], y[1]);
  });
  vector<vector<int>> dp = {{1, 0}, {0, 1}}, ndp = {{0, 0}, {0, 0}};
  for (int i = 1; i < n; i++){
    ndp = {{0, 0}, {0, 0}};
    for (int j1 = 0; j1 < 2; j1++) for (int f1 = 0; f1 < 2; f1++) for (int f = 0; f < 2; f++)
      if(a[i][f] > a[i-1][f1] && a[i][(f+1)%2] > a[i-1][(f1+1)%2])
        ndp[(j1+f)%2][f] |= dp[j1][f1]; 
    dp = ndp;
  }
  if(dp[0][0] || dp[0][1]) printf("YES\n");
  else printf("NO\n");
}
 
int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}