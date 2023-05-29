#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> s;
    int curr = 0, len = 0;
    for (int i = 2; i <= n; i++){
      if(s[i-2]==curr) len++;
      else len = 1, curr = s[i-2];
      printf("%d ", i-len);
    }
    printf("\n");
  }   
}