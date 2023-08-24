#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  string vika = "vika";
  while (TC--){
    scanf("%d%d", &n, &m);
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int c = 0;
    bool b[4] = {false, false, false, false};
    for (int j = 0; j < 4; j++){
      while (c<m && !b[j]){
        for (int i = 0; i < n; i++) if(a[i][c]==vika[j]) b[j] = true;
        c++;
      }
    }
    if(b[0]&&b[1]&&b[2]&&b[3]) printf("YES\n");
    else printf("NO\n");
  }   
}