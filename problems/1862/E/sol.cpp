#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, d;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &m, &d);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    ll res = 0, sum = 0;
    multiset<int> s;
    for (int i = 0; i < m; i++) s.insert(0);
    for (int i = 0; i < n; i++){
      sum-=d;
      int mn = *(s.begin());
      if(mn<a[i])sum+=a[i]-mn, s.erase(s.begin()), s.insert(a[i]);
      res = max(res, sum);
    }
    printf("%lld\n", res);
  }   
}