#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    ll b, n;
    scanf("%lld%lld", &b, &n);
    ll p = b%n;
    int k = 1;
    vector<bool> dp(n);
    bool isYes = false;
    while (!dp[p]){
      if(p==0){
        isYes = true;
        printf("1 %d\n", k);
        break;
      }
      if(p==1){
        isYes = true;
        printf("2 %d\n", k);
        break;
      }
      if(p==n-1){
        isYes = true;
        printf("3 %d\n", k);
        break;
      }
      k++;
      dp[p] = true;
      p = (p*b)%n;
    }
    if(!isYes) printf("0\n");
  }   
}