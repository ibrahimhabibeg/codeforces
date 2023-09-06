#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int a[n+1], res = 0;
    for (int i = 1; i <=n; i++) {
      scanf("%d", &x);
      a[x] = i;
    }
    for (int i = 2; i <=n; i++) res+=a[i]<a[i-1];
    printf("%d\n", res);
  }   
}