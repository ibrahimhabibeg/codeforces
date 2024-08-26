#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int score = 0;
  for (int i = n-2; i >= 0; i-=2){
    score += a[i+1] - a[i];
  }
  score = max(0, score - k);
  if(n%2) score +=a[0];
  printf("%d\n", score);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}