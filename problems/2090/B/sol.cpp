#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  string a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> dis = vector(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (j<m && (a[i][j]=='1')) dis[i][j] = 1, j++;
  }
  for (int j = 0; j < m; j++) {
    int i = 0;
    while (i<n && (a[i][j]=='1')) dis[i][j] = 1, i++;
  }
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if((a[i][j]=='1') && !dis[i][j]) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}