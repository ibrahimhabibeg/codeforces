#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int a[n], b[n],  gmn = 0, smx  = 1e9+5;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    ll res = 0;
    for (int i = 0; i < n; i++)
    res+=abs(a[i]-b[i]), gmn = max(gmn, min(a[i],b[i])), smx = min(smx, max(a[i],b[i]));
    if(gmn>smx) res+=2*1ll*(gmn-smx);
    printf("%lld\n", res);
  }   
}