#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &m);
    int a[n], b[n];
    a[0] = 1;
    for (int i = 1; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(a,a+n);
    sort(b,b+n);
    int res = 0;
    for (int i = 0; i < n; i++){
      int p = upper_bound(b,b+n,a[i])-b;
      res = max(res,p-i);
    }
    printf("%d\n",res);
  }   
}