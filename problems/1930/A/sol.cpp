#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[2*n];
    for (int i = 0; i < 2*n; i++) scanf("%d", &a[i]);
    sort(a, a+2*n);
    int res = 0;
    for (int i = 0; i < 2*n; i+=2) res+=a[i];
    printf("%d\n", res);
  }   
}