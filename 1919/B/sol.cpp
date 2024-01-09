#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    int c = 0, res = n;
    for (int i = 0; i < n; i++){
      if(s[i]=='+') c++;
      else c--;
      res = min(res, n - (i+1) + abs(c));
    }
    printf("%d\n", res);
  }   
}