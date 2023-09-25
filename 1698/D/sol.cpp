#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int l = 1, r = n;
    while (l<r){
      int m = (l+r)/2, c=0;
      printf("? %d %d\n", l, m);
      fflush(stdout);
      for (int i = 0; i < m-l+1; i++) scanf("%d", &x), c+=x>=l &&x<=m;
      if(c%2==0) l = m+1;
      else r = m;
    }
    printf("! %d\n", l);
    fflush(stdout);
  }   
}