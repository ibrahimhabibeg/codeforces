#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n, dis[2][N], a[2][N];

void dfs(int r, int c){
  if(dis[r][c]) return;
  dis[r][c] = true;
  if(c+1<n ) dfs(r, c+1+a[r][c+1]);
  if(c-1>=0) dfs(r, c-1+a[r][c-1]);
  if(r+1<2 ) dfs(r+1, c+a[r+1][c]);
  if(r-1>=0) dfs(r-1, c+a[r-1][c]);
}


int main(){
  int TC;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    for (int i = 0; i < n; i++){
      if(s[i]=='>') a[0][i] = 1;
      else a[0][i] = -1;
      dis[0][i] = false;
    }
    scanf("%s", s);
    for (int i = 0; i < n; i++){
      if(s[i]=='>') a[1][i] = 1;
      else a[1][i] = -1;
      dis[1][i] = false;
    }
    dfs(0,0);
    if(dis[1][n-1]) printf("YES\n");
    else printf("NO\n");
  }   
}