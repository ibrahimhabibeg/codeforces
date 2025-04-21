#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d%d", &n, &m, &k);
    int d = k - (n+m-2);
    if(d<0||(d%2)==1){
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    vector<vector<char>> h(n, vector<char>(m-1, 'R')), v(n-1, vector<char>(m, 'R'));
    v[0][0] = v[0][1] = 'B';
    if((n+m)%2) v[n-2][m-2] = 'B';
    else h[n-1][m-2] = h[n-2][m-2] = 'B';
    for (int i = 1; i < m-1; i+=2) h[0][i] = 'B';
    for (int i = 0; i < n-1; i++) if((m-1+i)%2) v[i][m-1] = 'B';
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m-1; j++) printf("%c ", h[i][j]);
      printf("\n");
    }
    for (int i = 0; i < n-1; i++){
      for (int j = 0; j < m; j++) printf("%c ", v[i][j]);
      printf("\n");
    }
  }   
}