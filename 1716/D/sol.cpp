#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 998244353;

int main(){
  int k, n;
  scanf("%d%d", &n, &k);
  int M = 0, c = n;
  while (c>=0) c-=k+M, M++; 
  M++;
  vector<int> A(n+1), r(n+1);
  A[0] = 1;
  for (int m = 0; m<M-1; m++){
    vector<int> B(n+1);
    for (int i = 0; i+k+m <= n; i++) A[i+k+m] = (A[i+k+m]+A[i])%MOD, B[i+k+m] = (B[i+k+m]+A[i])%MOD;
    for (int i = 0; i <= n; i++) A[i]=B[i];
    for (int i = 1; i <= n; i++) r[i]=(r[i]+A[i])%MOD;
  }
  for (int i = 1; i <= n; i++) printf("%d ", r[i]);
}