#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a;
map<ll, int> mp;

int f(ll x){
  auto it= mp.upper_bound(x);
  auto prev = it;
  prev--;
  ll ps = (*prev).first, cn = (*it).second, pn = (*prev).second;
  x%=ps+cn-pn;
  if(x<ps) return f(x);
  else return a[x-ps+pn];
}

int main(){
  int TC, n, t, q;
  __int128 x;
  ll k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &q);
    __int128 s= 0;
    int m = 0;
    mp.clear(), a.clear();
    mp[0] = 0;
    bool over = false;
    for (int i = 0; i < n; i++){
      scanf("%d%lld", &t, &k);
      x = k;
      if(over) continue;
      if(t==1) a.push_back(x), m++, s++;
      else {
        s*=(x+1);
        if(s>1e18) over = true, mp[1e18 + 5] = m;
        else  mp[s]=m;
      }
    }
    if(!over) mp[s] = m;
    for (int i = 0; i < q; i++){
      scanf("%lld", &k);
      printf("%d ", f(k-1));
    }
    printf("\n");
  }   
}