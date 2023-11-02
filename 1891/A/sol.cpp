#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n+1];
    bool isYes = true;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int m = 1; m <=5; m++) for (int i = 2 + (1<<(m-1)); i <= min(n, 1<<m); i++) if(a[i]<a[i-1]) isYes =  false;
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}