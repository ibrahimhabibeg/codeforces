#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    pair<int, int> a[n];
    int b[n];
    for (int i = 0; i < n; i++) scanf("%d", &x), a[i] = make_pair(x, i);
    sort(a, a+n);
    for (int i = 0; i < n; i++) b[a[i].second] = n-i;
    for (int i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");
  }   
}