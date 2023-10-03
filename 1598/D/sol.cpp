#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    vector<ll> t(n+1), d(n+1);
    int a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]), t[a[i]]++, d[b[i]]++;
    ll res = n*(n-1)*(n-2)/6;
    for (int i = 0; i < n; i++) 
    res-=(t[a[i]]-1)*(d[b[i]]-1);
    printf("%lld\n", res);
  }   
}