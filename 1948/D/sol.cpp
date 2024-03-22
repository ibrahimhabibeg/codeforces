#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    string s;
    cin >> s;
    int n = s.size(), res = 0;
    for (int d = 1; d <= n/2; d++){
      int t = 0;
      for (int i = 0; i < d; i++) if(s[i]==s[i+d]||s[i]=='?'||s[i+d]=='?') t++;
      if(t==d) res = d;
      for (int i = d; i+d < n; i++){
        if(s[i]==s[i-d]||s[i]=='?'||s[i-d]=='?') t--;
        if(s[i]==s[i+d]||s[i]=='?'||s[i+d]=='?') t++;
        if(t==d) res = d;
      }
    }
    printf("%d\n", res*2);
  }   
}