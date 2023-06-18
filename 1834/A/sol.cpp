#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, a;
  cin >> TC;
  while (TC--){
    int n, p = 0, np;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
      scanf("%d", &a);
      p+=a==1;
    }
    int res = 0;
    if(p<(n+1)/2) np = (n+1)/2;
    else np = p;
    if((n-np)%2==1)np++;
    printf("%d\n", np-p);
  }   
}