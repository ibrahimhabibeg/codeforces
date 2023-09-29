#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int TC, n, k, q, x;
  string s;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    cin >> s;
    s = " "+s;
    int l[k+1], r[k+1];
    l[0] = r[0] = 0;
    for (int i = 1; i <= k; i++) scanf("%d", &l[i]);
    for (int i = 1; i <= k; i++) scanf("%d", &r[i]);
    vector<int> a(n+2);
    scanf("%d", &q);
    while(q--){
      scanf("%d", &x);
      int y = upper_bound(l, l+k+1, x)-l-1;
      int mn = min(x, l[y]+r[y]-x), mx = max(x, l[y]+r[y]-x);
      a[mn]++, a[mx+1]--;
    }
    char res[n+1];
    for (int i = 1; i <=n; i++){
      a[i]+=a[i-1];
      if(a[i]%2==0) res[i-1]=s[i];
      else{
        int y = upper_bound(l, l+k+1, i)-l-1;
        res[i-1]=s[r[y]+l[y]-i];
      }
    }
    res[n] = '\0';
    printf("%s\n", res);
  }   
}