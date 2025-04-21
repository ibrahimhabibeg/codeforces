#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int a[n], mn = n;
    for (int i = n-1; i >= 0; i--) scanf("%d", &a[i]);
    stack<pair<int,int>> s, t;
    ll sm = n;
    for (int i = 0; i < n; i++){
      mn = min(mn, a[i]);
      sm+=mn;
      t.push(make_pair(mn,1));
    }
    for (int i = 0; i < n; i++){
      s.push(t.top());
      t.pop();
    }
    ll res = sm;
    for (int i = n-1; i>0; i--){
      int cnt = 1;
      while (s.top().first>a[i]){
        sm-=s.top().first*1ll*s.top().second;
        cnt+=s.top().second;
        s.pop();
      }
      sm+=a[i]*1ll*cnt;
      res = max(res, sm);
      s.push(make_pair(a[i], cnt));
    }
    printf("%lld\n", res);
  }   
}