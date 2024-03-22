#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    if(n%2) printf("NO\n");
    else{
      printf("YES\n");
      for(int i = 0; i<n; i++) printf("%c", 'A' + ((i%4)/2));
      printf("\n");
    }
  }   
}