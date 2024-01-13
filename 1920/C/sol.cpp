#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 +5;
int a[N], n;

int gcd(int a, int b){
  while (b){
    int c = a;
    a = b, b = c%b;
  }
  return a;
}

bool isPoss(int k){
  int d = 0;
  for (int i = k; i < n; i++) d= gcd(d, abs(a[i]-a[i%k]));
  return d!=1;
}

int main(){
  int TC;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = 0;
    for (int k = 1; k*k<= n; k++) if(n%k ==0){
      res+=isPoss(k);
      if(k!=n/k) res+=isPoss(n/k);
    }
    printf("%d\n", res);
  }   
}