#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int INF = 1e9, n, a[N];

ll f(int i, int j){
  if(a[i]>=j) return 0;
  if(i==n-1) return INF;
  return (j - a[i])*1LL + f(i+1, j-1);
}

int main(){
  int TC, mx;
  ll k;
  cin >> TC;
  while (TC--){
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
    int l = 0, r = mx+k;
    while (l<r){
      int m = (l+r+1)/2;
      bool isYes = false;
      for (int i = 0; i < n; i++) if(f(i, m)<=k) {
        isYes = true;
        break;
      }
      if(isYes) l = m;
      else r = m-1;
    }
    printf("%d\n", l);
  }   
}