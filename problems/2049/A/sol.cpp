#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  bool zeros = true;
  for (int i = 0; i < n; i++) if(a[i]!=0) zeros = false;
  if(zeros) {
    printf("0\n");
    return;
  }
  int s, e;
  for (int i = 0; i < n; i++) if(a[i]!=0) e=i;
  for (int i = n-1; i >=0; i--) if(a[i]!=0) s=i;
  bool notZeros = true;
  for (int i = s; i <= e; i++)if(a[i]==0) notZeros = false;
  if(notZeros) printf("1\n");
  else printf("2\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}