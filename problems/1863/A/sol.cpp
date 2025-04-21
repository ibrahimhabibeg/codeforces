#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a, q;
  string s;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &a, &q);
    cin >> s;
    int ca = a, mxca = a, p = 0;
    for (char c: s){
      p+=c=='+';
      if(c=='+') ca++;
      else ca--;
      mxca = max(mxca, ca);
    }
    if(mxca>= n) printf("YES\n");
    else if(p+a<n) printf("NO\n");
    else printf("MAYBE\n");
  }   
}