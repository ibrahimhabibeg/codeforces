#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    int c = 0;
    for (int i = 0; i < n/2; i++) c+=s[i]!=s[n-1-i];
    for (int i = 0; i <= n; i++){
      if(i<c||i>n-c) printf("0");
      else if(n%2==1 || (c+i)%2==0) printf("1");
      else printf("0");
    }
    printf("\n");
  }   
}