#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll x;
  cin >> TC;
  while (TC--){
    scanf("%lld", &x);
    vector<int> a;
    int i = 0;
    while (x){
      if(x%2) a.push_back(i);
      i++, x/=2;
    }
    int n = a.size();
    printf("%d\n", a[n-1]+n-1);
    for (int i = 0; i < a[n-1]; i++) printf("%d ", i);
    for (int i = n-2; i >=0; i--) printf("%d ", a[i]);
    printf("\n");
  }   
}