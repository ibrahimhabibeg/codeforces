#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int a[2*n];
    for (int i = 0; i < 2*n; i++) scanf("%d", &a[i]);
    sort(a, a+2*n);
    printf("%d\n", a[n-1]-a[0]+a[2*n-1]-a[n]);
    for (int i = 0; i < n; i++) printf("%d %d\n", a[i], a[i+n]);
  }   
}