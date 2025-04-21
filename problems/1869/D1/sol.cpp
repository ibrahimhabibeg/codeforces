#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
ll a[N], n;

bool solve(){
  ll sum = 0;
  for (int i = 0; i < n; i++) sum+=a[i];
  if(sum%n!=0) return false;
  ll e = sum/n;
  int t[n], g[n];
  for (int i = 0; i < n; i++){
    ll d = abs(a[i]-e);
    if(d==0){ 
      t[i]=g[i]=-1;
      continue;
    }
    int x = 0;
    while (d%2==0) d/=2, x++;
    g[i] = x;
    while (d%2==1) d/=2, x++;
    t[i] = x;
    if(d!=0) return false;
    if(a[i]>e) swap(t[i], g[i]);
  }
  sort(t, t+n);
  sort(g, g+n);
  for (int i = 0; i < n; i++) if(t[i]!=g[i]) return false;
  return true;
}

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    if(solve()) printf("Yes\n");
    else printf("No\n");
  }   
}