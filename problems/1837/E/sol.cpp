#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;
const int N = 2097155;

vector<int> pmemo(N, -1);
vector<int> fmemo(N, -1);
 
int pow(int n){
  if(pmemo[n]!=-1) return pmemo[n];
  return pmemo[n] = (2*pow(n-1))%MOD;
}

int fact(int n){
  if(fmemo[n]!=-1) return fmemo[n];
  return fmemo[n] = (n*1LL*fact(n-1))%MOD;
}

int main(){
  pmemo[0] = fmemo[0] = 1;
  int k;
  scanf("%d", &k);
  if(k==0) {
    printf("1\n");
    return 0;
  }
  vector<vector<int>> m(k);
  vector<int> s0(k), s(k), dp(k+1);
  bool possible = true;
  for (int i = 0; i < k; i++) for (int j = 0; j < pow(i+1); j++) m[i].push_back(-1);
  for (int i = 0; i < pow(k); i++) scanf("%d", &m[k-1][i]);
  for (int i = k-1; i > 0; i--) for (int j = 0; j < m[i].size(); j++) if(m[i][j]!=-1) {
    if(m[i][j]<=pow(i)){
      if(m[i-1][j/2]!=-1) possible = false;
      else m[i-1][j/2] = m[i][j];
    }
  }
  for (int i = 0; i < k; i++) for (int j = 0; j < m[i].size(); j+=2) {
    if(i>0 && m[i][j]!=-1 && m[i][j+1]!=-1 && m[i-1][j/2]==-1) possible = false;
    if(m[i][j]!=-1 && m[i][j]>pow(i)) continue;
    if(m[i][j+1]!=-1 && m[i][j+1]>pow(i)) continue;
    s[i]++;
    if(m[i][j] == -1 && m[i][j+1] ==-1) s0[i]++;
  }
  if(!possible) {
    printf("0\n");
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= k; i++) dp[i] = (dp[i-1] * 1LL * ((pow(s0[i-1]) * 1LL * fact(s[i-1]))%MOD))%MOD;
  printf("%d\n", dp[k]);
}