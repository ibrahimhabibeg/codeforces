#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a;
  cin >> TC;
  while (TC--)
  {
    int mx = -1, neg = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
      scanf("%d", &a);
      mx = max(mx,a); 
      if(a<0) neg = a;
    }
    if(neg<0) printf("%d\n", neg);
    else   printf("%d\n", mx);
  }   
}