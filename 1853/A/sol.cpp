#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a, p;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &a, &p);
    int res = (p-a+2)/2;
    for (int i = 0; i < n-2; i++) scanf("%d", &a), res = min(res, (a-p+2)/2), p = a;
    printf("%d\n", max(0, res));
  }   
}