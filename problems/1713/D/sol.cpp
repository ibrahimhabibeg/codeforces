#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<int> a[n+1];
    for (int i = 1; i <=1<<n; i++) a[n].push_back(i);
    for (int L = n; L>1; L-=2){
      for (int i = 0; i < 1<<L; i+=4){
        printf("? %d %d\n", a[L][i+0], a[L][i+2]);
        fflush(stdout);
        int r, x, y;
        scanf("%d", &r);
        if(r==0) x = 1, y=3;
        else if(r==1) x = 0, y=3;
        else x = 1, y=2;
        printf("? %d %d\n", a[L][i+x], a[L][i+y]);
        fflush(stdout);
        scanf("%d", &r);
        if(r==1) a[L-2].push_back(a[L][i+x]);
        else a[L-2].push_back(a[L][i+y]);
      }
    }
    if(n%2==1){
      printf("? %d %d\n", a[1][0], a[1][1]);
      fflush(stdout);
      int r;
      scanf("%d", &r);
      if(r==1) a[0].push_back(a[1][0]);
      else a[0].push_back(a[1][1]);
    }
    printf("! %d\n", a[0][0]);
    fflush(stdout);
  }   
}