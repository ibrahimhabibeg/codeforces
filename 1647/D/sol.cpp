#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, x, d;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &x, &d);
    int p = 0;
    while (x%d == 0) p++, x/=d;
    bool isKComposite = false, isDComposite = false, kf = false;
    for (int i = 2; i*i <= x; i++) if(x%i == 0){
      isKComposite = true;
      break;
    }
    for (int i = 2; i*i <= d; i++) if(d%i == 0){
      isDComposite = true;
      if((ll) (x*i)%d|| (ll) (x*d/i)%d){
        kf = true;
        break;
      }
    }
    if(p>=2 && isKComposite) printf("YES\n");
    else if(p>=3 && kf) printf("YES\n");
    else if(p>=4 && isDComposite) printf("YES\n");
    else printf("NO\n");
  }
}