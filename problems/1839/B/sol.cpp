#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a, b;
  cin >> TC;
  while (TC--)
  {
    ll res = 0;
    scanf("%d", &n);
    pair<int, int> v[n];
    for (int i = 0; i < n; i++){
      scanf("%d %d", &a, &b);
      v[i] = make_pair(a, -1*b);
    }
    sort(v, v+n);
    int s = 0;
    for (int i = 0; i < n; i++){
      if(v[i].first!=v[i-1].first) s = i;
      if(i-s<v[i].first) res+= -1 * 1ll * v[i].second;
    }
    printf("%lld\n", res);
  }   
}