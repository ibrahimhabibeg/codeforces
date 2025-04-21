#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    if(m==1) printf("0\n");
    else printf("%d\n", min(m, n+1));
    for (int i = 0; i < n; i++){
      int k = m==1?i:i%(m-1);
      for (int j = 0; j < m; j++) printf("%d ", (k+j)%m);
      printf("\n");
    }
  }   
}