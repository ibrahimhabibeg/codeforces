#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n,m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &m);
    printf("%d\n", max(n, m));
  }   
}