#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int k, n;
  scanf("%d%d", &n, &k);
  int a[n], l = 0, r =n-1;
  ll res = 1;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), res+=a[i];
  sort(a, a+n);
  while(l<r){
    if(a[l]+a[r]<=k)l++, r--;
    else r--, res++;
  }
  printf("%lld", res);
}