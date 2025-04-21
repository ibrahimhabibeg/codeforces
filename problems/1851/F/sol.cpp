#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, x;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) scanf("%d", &x), a[i] = make_pair(x, i+1);
    sort(a, a+n);
    int res = 0;
    for (int i = 1; i < n-1; i++) if((a[i].first^a[i+1].first)<(a[res].first^a[res+1].first)) res = i;
    int v = a[res].first, x = 0;
    for (int i = 0; i < k; i++) x+=(((v%2)+1)%2)<<i, v/=2;
    printf("%d %d %d\n", a[res].second, a[res+1].second, x);
  }   
}