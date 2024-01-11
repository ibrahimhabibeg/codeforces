#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] = abs(a[i]);
    set<int> s;
    bool isYes = false;
    for (int v = 0; v < (1<<n); v++){
      int x = 0;
      for (int i = 0; i < n; i++) if((1<<i)&v) x+=a[i];
      if(s.find(x)!=s.end()){
        isYes = true;
        break;
      }
      s.insert(x);
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}