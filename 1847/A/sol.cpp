#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, a;
  cin >> TC;
  while (TC--){
    int p;
    scanf("%d%d%d",&n, &k, &p);
    int diff[n-1], res = 0;
    for (int i = 0; i < n-1; i++){
      scanf("%d", &a), diff[i] = abs(a-p), p = a;
    }
    sort(diff, diff+n-1);
    for (int i = 0; i < n-k; i++) 
      res += diff[i];
    printf("%d\n", res);
  }   
}