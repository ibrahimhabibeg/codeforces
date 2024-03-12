#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    bool isYes = true;
    for (int i = 0; i < n-2; i++){
      if(a[i]<0){
        isYes = false;
        break;
      }
      a[i+1]-=2*a[i], a[i+2]-=a[i], a[i]=0;
    }
    if(isYes && a[n-1]==0 && a[n-2]==0) printf("YES\n");
    else printf("NO\n");
  }   
}