#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m,k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d%d", &n, &m, &k);
    int a[n], d[m], f[k];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &d[i]);
    for (int i = 0; i < k; i++) scanf("%d", &f[i]);
    int ix = 0, df = a[1]-a[0], df2 = 0;
    for (int i = 1; i < n-1; i++){
      if(a[i+1]-a[i]>df) ix = i, df2 = df, df = a[i+1]-a[i];
      else if(a[i+1]-a[i]>df2) df2 = a[i+1]-a[i];
    }
    int t = a[ix]+((a[ix+1]-a[ix])/2);
    sort(f, f+k);
    for (int i = 0; i < m; i++){
      int j = upper_bound(f, f+k, t-d[i]) - f;
      if(j<k && d[i]+f[j]>=a[ix] && d[i]+f[j]<=a[ix+1]) df= min(df, max(a[ix+1]-(d[i]+f[j]), (d[i]+f[j])-a[ix])); 
      j--;
      if(j>=0 && d[i]+f[j]>=a[ix] && d[i]+f[j]<=a[ix+1]) df= min(df, max(a[ix+1]-(d[i]+f[j]), (d[i]+f[j])-a[ix]));
    }
    printf("%d\n", max(df2, df));
  }   
}