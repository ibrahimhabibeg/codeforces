#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  char a[2][n];
  for (int i = 0; i < n; i++) scanf(" %c", &a[0][i]);
  for (int i = 0; i < n; i++) scanf(" %c", &a[1][i]);
  bool isMul = false;
  for (int i = 0; i < n; i++){
    int c = (a[0][i]=='.') + (a[1][i]=='.');
    if(c==2 && i < n-1 && a[0][i+1]=='.' && a[1][i+1]=='.') isMul = true;
    if(c==1) {
      if(i==n-1) {
        printf("None\n");
        return;
      }
      if(a[0][i]=='.') {
        if(a[0][i+1]=='#') {
          printf("None\n");
          return;
        }
        a[0][i+1]='#';
      } else {
        if(a[1][i+1]=='#') {
          printf("None\n");
          return;
        }
        a[1][i+1]='#';
      }
    }
  }
  if(isMul) printf("Multiple\n");
  else printf("Unique\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}