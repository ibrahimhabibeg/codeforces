#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, ms, me, s, e;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &ms, &me);
    bool isYes = true;
    for (int i = 0; i < n-1; i++){
      scanf("%d%d", &s, &e);
      isYes = isYes && (s<ms||e<me);
    }
    if(isYes) printf("%d\n", ms);
    else printf("-1\n");
  }   
}