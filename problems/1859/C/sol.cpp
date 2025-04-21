#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int res = 0;
    for (int j = 1; j <= n; j++) for (int k = j+1; k <= n; k++) {
      vector<bool> t(n+1);
      t[j] = true;
      int r = 0;
      for (int v = n; v >= 1; v--) if(v!=k) {
        int i = min(n, j*k/v);
        while(i>0 && t[i]) i--; 
        if(i==0) {
          r = 0;
          break;
        }
        r+=v*i;
        t[i] = true;
      }
      res = max(res, r);
    }
    printf("%d\n", res);
  }   
}