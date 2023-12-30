#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  ll b;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    ll p = 1;
    for(int i =0; i< n;i++) scanf("%lld", &b), p*=b;
    if(2023%p){
      printf("NO\n");
    }else{
      printf("YES\n%lld", 2023/p);
      for (int i = 0; i < k-1; i++) printf(" 1");
      printf("\n");
    }
  }   
}