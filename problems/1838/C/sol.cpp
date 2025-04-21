#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &m);
    int s = m;
    int a[n][m];
    for (int i = 0; i < n; i++){
      s--;
      if(s==0) s = m;
      for (int j = 0; j < m; j++) a[i][(m%2==0?j:(s+j)%m)] = m*i + j + 1;
    }
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++) printf("%d ", a[i][j]);
      printf("\n");
    }
    printf("\n");
  }   
}