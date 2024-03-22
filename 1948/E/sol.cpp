#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    int a[n+1], h = (k+1)/2;
    for (int s = 1; s <= n; s+=k){
      int f = min(n, s+h-1), t = s + f, b = s+h;
      for (int i = s; i <= f; i++) a[i] = t-i;
      f = min(n, s+k-1), t = b + f;
      for (int i = b; i <= f; i++) a[i] = t-i;
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    printf("%d\n", (n+k-1)/k);
    for (int i = 0; i < n; i++) printf("%d ", 1+(i/k));
    printf("\n");
  }   
}