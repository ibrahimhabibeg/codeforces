#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], l[n], r[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    l[0] = 1, r[n-1] = 0;
    for (int i = n-2; i >= 0; i--) r[i] = a[i]<a[i+1]?r[i+1]:r[i+1]+1;
    for (int i = 1; i < n; i++) l[i] = a[i]<a[i-1]?l[i-1]:l[i-1]+1;
    int res = min(l[n-1], r[0]);
    for (int i = 0; i < n-1; i++) res = min(res, l[i] + r[i+1]);
    printf("%d\n", res);
  }   
}