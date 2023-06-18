#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  string s, t;
  cin >> TC;
  while (TC--){
    int n, d1 = 0, d2 = 0;
    scanf("%d", &n);
    cin >> s >> t;
    for (int i = 0; i < n; i++) d1 += s[i]!=t[i], d2 += s[i]!=t[n-1-i];
    printf("%d\n", min(d1==0?0:(2*d1 - (d1%2)), d2==0?2:(2*d2 - ((d2+1)%2))));
  }   
}