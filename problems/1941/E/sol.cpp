#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, k, d;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d%d", &n, &m, &k, &d);
    int a[n][m];
    ll res[n];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    for (int r = 0; r < n; r++) {
      ll dp[m];
      dp[0] = 1;
      set<pair<ll, int>> st;
      st.insert(make_pair(1, 0));
      for (int i = 1; i < m; i++){
        dp[i] = (a[r][i] + 1)*1ll + (*(st.begin())).first;
        if(i-(d+1)>=0) st.erase(make_pair(dp[i-(d+1)], i-(d+1)));
        st.insert(make_pair(dp[i], i));
      }
      res[r] = dp[m-1];
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) ans+=res[i];
    ll mnAns = ans;
    for (int i = k; i < n; i++) ans+=res[i]-res[i-k], mnAns = min(mnAns, ans);
    printf("%lld\n", mnAns);
  }   
}