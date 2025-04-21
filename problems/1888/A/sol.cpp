#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    char s[n+1];
    scanf("%s", s);
    vector<int> cnt(26);
    for(char c: s) cnt[c-'a']++;
    int od = 0;
    for (int i = 0; i < 26; i++) od+=cnt[i]%2;
    if(k>=od-1) printf("YES\n");
    else printf("NO\n");
  }   
}