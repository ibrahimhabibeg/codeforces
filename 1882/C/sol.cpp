#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll res = 0;
    for (int i = 1; i <= n; i++) if(a[i]>0) res+=a[i];
    if(n>1&&a[1]<0 && a[2]>0) res+=max(0, a[1]+a[2])-a[2];
    printf("%lld\n", res);
  }   
}