#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, s, a;
  cin >> TC;
  while (TC--){
    ll res= 0;
    scanf("%d", &n);
    int sm1 = 1e9+5, sm2 = 1e9+5;
    for (int i = 0; i < n; i++){
      int m1, m2;
      scanf("%d%d%d", &s, &m1, &m2);
      if(m2<m1) swap(m1, m2);
      for (int j = 0; j < s-2; j++){
        scanf("%d", &a);
        if(a<m1) m2 = m1, m1 = a;
        else if(a<m2) m2 = a;
      }
      res+=m2, sm1 = min(sm1, m1), sm2 = min(sm2, m2);
    }
    res+=sm1-sm2;
    printf("%lld\n", res);
  }   
}