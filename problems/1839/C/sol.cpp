#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    if(a[n-1]==1){printf("NO\n"); continue;}
    printf("YES\n");
    int len = 0;
    for (int i = n-1; i >= 0; i--){
      len +=a[i]==1;
      if(a[i]==1&&(i==0 || a[i-1]==0)) printf("%d ", len), len = 0;
      else printf("0 ");
    }
    printf("\n");
  }   
}