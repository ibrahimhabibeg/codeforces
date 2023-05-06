#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    vector<ll> a(n);
    unordered_set<ll> s;
    s.insert(0);
    for (int i = 0; i < n; i++) scanf("%llu", &a[i]);
    for (int i = 0; i < n-1; i++)
      for (int j = i+1; j < n; j++)
        for (ll d = 1; d <= sqrt(a[j]-a[i]); d++)
          if((a[j]-a[i])%d==0){
            ll q = (a[j]-a[i])/d + d;
            if(q%2==0){
              q/=2;
              if(q*q>a[j]) s.insert(q*q-a[j]);
            }
            ll d2 = (a[j]-a[i])/d;
            q = (a[j]-a[i])/d2 + d2;
            if(q%2==0){
              q/=2;
              if(q*q>a[j]) s.insert(q*q-a[j]);
            }
          }
    int res = 1;
    for(ll x : s){
      int squarness = 0;
      for (int i = 0; i < n; i++)
      {
        ll sr = sqrt(a[i]+x);
        if(sr*sr==a[i]+x) squarness++;
      }
      res = max(res, squarness);
    }
    printf("%d\n", res);
  }   
}