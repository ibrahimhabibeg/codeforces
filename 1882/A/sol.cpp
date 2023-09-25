#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a, b = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      b++;
      if(b==a)b++;
    }
    printf("%d\n", b);
  }   
}