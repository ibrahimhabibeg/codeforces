#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  string s;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<int> cnt(26);
    for (int i = 0; i < 2*n+1; i++){
      cin >> s;
      for (char c: s) cnt[c-'a']++;
    }
    char f;
    for (int i = 0; i < 26; i++) if(cnt[i]%2==1) {
      f = 'a' + i;
      break;
    }
    printf("%c\n", f);
  }   
}