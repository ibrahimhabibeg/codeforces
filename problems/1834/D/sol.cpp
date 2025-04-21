#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &m);
    int l[n], r[n], shrt = m, erl = m, lat = 0;
    for (int i = 0; i < n; i++) scanf("%d %d", &l[i], &r[i]);
    for (int i = 0; i < n; i++){
      shrt = min(shrt, r[i]-l[i]+1);
      erl = min(erl, r[i]);
      lat = max(lat, l[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++){
      res = max(res, r[i]-l[i]+1-shrt);
      res = max(res, r[i]- max(l[i]-1, erl));
      res = max(res, min(r[i]+1, lat)-l[i]);
    }
    printf("%d\n", 2*res);
  }   
}