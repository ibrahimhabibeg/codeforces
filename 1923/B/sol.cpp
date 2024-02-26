#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, x;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    vector<ll> a(2*n+1);
    ll h = 0;
    int b[n], x;
    bool isYes = true;
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) scanf("%d", &x), a[x+n] = b[i];
    for (int i = 1; i <=n; i++){
      h+=k;
      if(a[n-i]+a[n+i]>h){
        isYes = false;
        break;
      }
      h-=a[n-i]+a[n+i];
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }
}