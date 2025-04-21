#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &k);
    printf("%d\n", 1 + ((n+k-2)/k));
  }   
}