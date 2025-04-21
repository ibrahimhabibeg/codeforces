#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  ll m;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n+2];
    a[0] = n+1, a[n+1] = n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%lld", &m);
    vector<ll> sz(n+1);
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n+1; i++) {
      while (!s.empty()&&a[i]>=a[s.top()]){
        int j = s.top();
        s.pop();
        sz[i-s.top()-1]+=min(a[i],a[s.top()])-a[j];
      }
      s.push(i);
    }
    ll r = 0;
    for (int i = n; i >=2; i--){
      ll c = min(sz[i], m/i);
      r+= (i-1)*1LL*c, m-=i*1LL*c;
      if(c<sz[i]&&m>0) r+=m-1, m = 0;
    }
    printf("%lld\n", r);
  }   
}