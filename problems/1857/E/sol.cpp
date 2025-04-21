#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    pair<int, int> a[n];
    ll res[n], s = n;
    for (int i = 0; i < n; i++) scanf("%d", &x), a[i]= make_pair(x, i), s+=x;
    sort(a, a+n);
    for (int i = 0; i < n; i++) res[a[i].second] = s + i*1LL*a[i].first - (n-i)*1LL*a[i].first, s-=2*a[i].first;
    for (int i = 0; i < n; i++) printf("%lld ", res[i]);
    printf("\n");
  }   
}