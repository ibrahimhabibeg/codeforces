#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], res = 0, mn = 1e9+1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n-1; i >= 0; i--){
      if(a[i]>mn) res = max(res, a[i]);
      mn = min(mn, a[i]);
    }
    printf("%d\n", res);
  }   
}