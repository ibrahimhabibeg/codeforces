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
    bool isYes = a[0]==n;
    if(a[0]==n){
      int i = n-1;
      for (int j = 0; j < n; j++){
        while (i>=0 && a[i]<=j) i--;
        if(i+1!=a[j]) {
          isYes = false;
          break;
        }
      }
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}