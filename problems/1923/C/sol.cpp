#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, q, a, l, r;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &q);
    ll s[n+1], c[n+1];
    s[0] = 0, c[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a), s[i] = s[i-1] + a-1, c[i] = c[i-1] + (a==1);
    while (q--){
      scanf("%d%d", &l, &r);
      if(l==r) printf("NO\n");
      else if(s[r]-s[l-1]>=c[r]-c[l-1]) printf("YES\n");
      else printf("NO\n");
    }
  }   
}