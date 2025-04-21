#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], ev = 0, od = 0;
    ll s = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++){
      s+=a[i], ev+=(a[i]%2)==0, od+=a[i]%2;
      ll m = od;
      ll res = s - (m/3);
      if(m%3 == 1) res -=1;
      if(i==0) res = s;
      printf("%lld ", res);
    }
    printf("\n");
  }   
}