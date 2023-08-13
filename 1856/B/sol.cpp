#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    ll cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a), cnt+=a==1, sum+=a;
    sum-=n;
    if(n>1 && sum>=cnt) printf("YES\n");
    else printf("NO\n");
  }   
}