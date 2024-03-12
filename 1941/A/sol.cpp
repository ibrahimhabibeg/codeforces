#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &m, &k);
    int a[n], b[m], res = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if(a[i]+b[j]<=k) res++;
    printf("%d\n", res);
  }   
}