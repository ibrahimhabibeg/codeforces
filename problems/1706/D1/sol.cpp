#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &k);
    int a[n], mna = 30001, res = 4000;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), mna = min(mna, a[i]);
    for (int mn = 1; mn <= mna; mn++){
      int mx = mn;
      for (int i = 0; i < n; i++){
        int p = min(k, a[i]/mn);
        mx = max(mx, a[i]/p);
      }
      res = min(res, mx-mn);
    }
    printf("%d\n", res);
  }   
}