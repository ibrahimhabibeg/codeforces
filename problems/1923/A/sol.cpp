#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], l, r;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) if(a[i]) r = i;
    for (int i = n-1; i>=0; i--) if(a[i]) l = i;
    int res = 0;
    for (int i = l+1; i < r; i++) res+=a[i]==0;
    printf("%d\n", res);
  }   
}