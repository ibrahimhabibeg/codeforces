#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, x;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &k, &x);
    if(x==k) x--;
    if(k>n||x<k-1) printf("-1\n");
    else printf("%d\n", k*(k-1)/2 + (n-k)*x);
  }   
}