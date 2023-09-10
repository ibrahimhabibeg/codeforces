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
    if(n%2==0) printf("2\n");
    else printf("4\n");
    if(n%2==0) printf("1 %d\n", n);
    else printf("1 %d\n", n-1);
    if(n%2==0) printf("1 %d\n", n);
    else printf("1 %d\n", n-1);
    if(n%2==1){
      printf("%d %d\n", n-1, n);
      printf("%d %d\n", n-1, n);
    }
  }   
}