#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main(){
  int TC, n, m, q;
  ll k;
  cin >> TC;
  while (TC--){
    scanf("%d%d%lld%d", &n, &m, &k, &q);
    int a[q], b[q];
    for (int i = 0; i < q; i++) scanf("%d%d", &a[i], &b[i]);
    vector<bool> r(n+1), c(m+1);
    int rc = n, cc =m;
    ll t = 0;
    for (int i = q-1; i >=0; i--)
    {
      if(rc!=0&&cc!=0&&(!r[a[i]]||!c[b[i]])) t++;
      if(!r[a[i]]) rc--;
      if(!c[b[i]]) cc--;
      r[a[i]]=c[b[i]]=true;
    }
    ll res = 1;
    for (int i = 0; i < t; i++) res = (res*k)%MOD;
    printf("%lld\n", res);
  }   
}