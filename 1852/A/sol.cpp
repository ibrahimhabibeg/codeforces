#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &k);
    int a[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] -= i;
    a[0] = 0;
    ll v = 1;
    int i = 1;
    while (k--){
      while (i<=n && a[i]<v) i++;
      v+=i-1;
    }
    printf("%lld\n", v);
  }   
}