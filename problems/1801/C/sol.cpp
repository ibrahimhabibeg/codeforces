#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> shorten(vector<int> old){
  vector<int> res;
  int mx = 0;
  for (int x: old) if(x>mx){
    res.push_back(x);
    mx = max(mx, x);
  }
  return res; 
}

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &k);
      a[i].resize(k);
      for (int j = 0; j < k; j++) scanf("%d", &a[i][j]); 
    }
    for(int i = 0; i<n; i++) a[i] = shorten(a[i]);
    map<int, vector<int>> mp;
    for(int i = 0; i<n; i++) for(int x: a[i]) mp[x].push_back(i);
    vector<int> dp(n);
    int done = 0;
    for(auto &it : mp){
      int c = it.first, new_done = 0;
      for (int i: it.second)
      {
        dp[i] = max(dp[i]+1, done+1);
        if(c==a[i].back()) new_done = max(new_done, dp[i]);
      }
      done = max(done, new_done);
    }
    int res = 0;
    for (int x: dp) res = max(res, x);
    printf("%d\n", res);
  }   
}