#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, k, a;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &m, &k);
    ll res = 0;
    int mna = 1e9+5, mnb = 1e9+5, mxa=0, mxb = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a), res+=a, mna = min(mna,a), mxa = max(mxa,a);
    for (int i = 0; i < m; i++) scanf("%d", &a), mnb = min(mnb,a), mxb = max(mxb,a);
    res-=mna+mxa;
    if(k%2==1){
      res += mxa+max(mxb, mna);
    }else{
      if(mna>mxb) res+=mnb+mna;
      else res+=min(mxa, mxb)+min(mna, mnb);
    }
    printf("%lld\n", res);
  }   
}