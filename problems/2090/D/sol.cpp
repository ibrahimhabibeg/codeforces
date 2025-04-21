#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  vector<int> sieve(n+1);
  for (int i = 2; i <= n; i++) for (int j = i+i; j <= n; j+=i) sieve[j]++;
  int p;
  for (int i = n/3; i <= n; i++) if(!sieve[i]) {
    p = i;
    break;
  }
  int d = 1;
  while(p-d>0) {
    printf("%d %d ", p-d, p+d);
    d++;
  }
  while(p+d<=n) printf("%d ", p+d), d++;
  if(p) printf("%d", p);
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}