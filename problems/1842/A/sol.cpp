#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, x;
  cin >> TC;
  while (TC--){
    scanf("%d %d", &n, &m);
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++){ scanf("%d", &x); a+=x;}
    for (int i = 0; i < m; i++){ scanf("%d", &x); b+=x;}
    if(a>b) printf("Tsondu\n");
    else if(a<b) printf("Tenzing\n");
    else printf("Draw\n");
  }   
}