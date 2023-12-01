#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    ll a[n], b[n+1];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    b[n] = 0;
    for (int i = n-1; i >=0; i--) b[i] = a[i] + b[i+1];
    ll k = 1, res = 0;
    for (int i = 0; i < n; i++){
      res+=k*a[i];
      if(b[i+1]>0) k++;
    }
    printf("%lld\n", res);
  }   
}