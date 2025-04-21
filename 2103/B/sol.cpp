#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = '0' + s;
  int c = 0;
  for(int i = 1; i <= n; i++){
    if(s[i] != s[i-1]){
      c++;
    }
  }
  int a = -1, b = -1;
  for(int i = 1; i <= n; i++){
    if(s[i] == '0' && s[i-1] == '1'){
      a = i;
      break;
    }
  }
  if(a != -1){
    for(int i = a+1; i <= n; i++){
      if(s[i] == '1'){
        b = i;
        break;
      }
    }
  }
  if(a==-1) cout << n + c << endl;
  else if(b == -1) cout << n + c - 1 << endl;
  else cout << n + c - 2 << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TC = 1;
  cin >> TC;
  while(TC--){
    solve();
  }
}