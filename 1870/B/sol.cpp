#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int TC, n, m, x;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    int a[n], b = 0, r = 0, org = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), org^=a[i];
    for (int i = 0; i < m; i++) scanf("%d", &x), b|=x;
    for (int i = 0; i < n; i++) r^=a[i]|b;
    printf("%d %d\n", min(r, org), max(r, org));
  }   
}