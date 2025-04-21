#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int l[N], r[N], c[N], m, n, q;

bool isPoss(int s){
  vector<int> a(n+1, 0);
  for (int i = 0; i < s; i++) a[c[i]] = 1;
  for (int i = 1; i <=n; i++) a[i]+=a[i-1];
  for (int i = 0; i < m; i++) if(a[r[i]]-a[l[i]-1]>(r[i]-l[i]+1)/2) return true;
  return false;
}

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d", &l[i], &r[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) scanf("%d", &c[i]);
    int l = 1, r = q;
    while (l<r){
      int m = (l+r)/2;
      if(isPoss(m)) r=m;
      else l = m+1;
    }
    if(isPoss(l)) printf("%d\n", l);
    else printf("-1\n");
  }   
}