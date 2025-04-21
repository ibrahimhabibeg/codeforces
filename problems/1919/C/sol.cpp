#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int z, res = 0, x = n+1, y = n+1;
    for (int i = 0; i < n; i++){
      scanf("%d", &z);
      if(z>y) res++, x = y, y = z;
      else if(z>x) y = z;
      else x = z;
    }
    printf("%d\n", res);
  }   
}