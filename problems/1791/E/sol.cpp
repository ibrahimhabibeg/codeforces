#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    ll sum = 0;
    int noNeg = 0, minAbs = 1e9+1, a;
    for (int i = 0; i < n; i++){
      scanf("%d", &a);
      noNeg += a<0, minAbs = min(minAbs, abs(a));
      sum +=abs(a);
    } 
    if(noNeg%2==0) printf("%llu\n", sum);
    else printf("%llu\n", sum - 2*1LL*minAbs);
  }   
}