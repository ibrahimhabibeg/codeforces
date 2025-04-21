#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int TC, n, c;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &c);
    ll a[n+1];
    for (int i = 1; i <=n; i++) scanf("%lld", &a[i]);
    set<pair<ll, int>> s;
    for (int i = 2; i <=n; i++) s.insert(make_pair(c*1LL*i-a[i],i));
    while(!s.empty()){
      auto p = *(s.begin());
      if(p.first<=a[1]){
        a[1]+=a[p.second];
        s.erase(s.begin());
      }else{
        break;
      }
    }
    if(s.empty()) printf("Yes\n");
    else printf("No\n");
  }   
}