#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calcScore(vector<int> a, vector<int> b){
  int i = 0;
  while(i<a.size() && a[i]==b[i]) i++;
  return i;
}

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m)), b(n,vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) b[i][a[i][j]-1] = j + 1;
    sort(b.begin(),b.end());
    for (int i = 0; i < n; i++)
    {
      int j = lower_bound(b.begin(), b.end() , a[i]) - b.begin();
      int ans = 0;
      if(j>0) ans = calcScore(a[i], b[j-1]);
      if(j<n) ans = max(ans, calcScore(a[i], b[j]));
      cout << ans << " ";
    }
    cout << "\n";
  }   
}