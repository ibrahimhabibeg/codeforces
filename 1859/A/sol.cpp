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
    sort(a,  a+n);
    int k = n-1;
    while (k>=0 && a[k]==a[n-1]) k--;
    if(k==-1) printf("-1\n");
    else {
      printf("%d %d\n", k+1, n-k-1);
      for (int i = 0; i <=k; i++) printf("%d ", a[i]);
      printf("\n");
      for (int i = 0; i <n-k-1; i++) printf("%d ", a[n-1]);
      printf("\n");
    }
  }   
}