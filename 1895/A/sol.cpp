#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, x, y, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d%d",&x, &y, &k);
    if(x>=y) printf("%d\n", x);
    else if(k+x>=y) printf("%d\n", y);
    else printf("%d\n", y+y-(x+k));
  }   
}