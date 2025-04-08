#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  if(n==2) {
    printf("2 1\n");
    return;
  }
  vector<int> sieve(n+1);
  sieve[1] = 1;
  for (int i = 2; i <= n; i++) for (int j = i+i; j<=n; j+=i) sieve[j]++;
  int p = n/3, i = 1;
  while(sieve[p]) p++;
  printf("%d ", p);
  while (p-i>0) printf("%d %d ", p-i, p+i), i++;
  while (p+i<=n) printf("%d ", p+i), i++;
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}