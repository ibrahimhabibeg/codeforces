#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int b[n+1];
    b[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &x), b[i] = b[i-1]^x;
    set<int> s;
    for (int i = 0; i <= n; i++) s.insert(b[i]);
    int r = 255;
    bool found = false;
    while(!found && r){
      for (int i = 0; i <= n; i++) if(s.find(b[i]^r)!=s.end()) {
        found = true, r+=1;
        break;
      }
      r--;
    }
    printf("%d\n", r);
  }   
}