#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &k);
    int x[k], c[k];
    for (int i = 0; i < k; i++) scanf("%d", &x[i]);
    for (int i = 0; i < k; i++) scanf("%d", &c[i]);
    string res = "";
    int b = 0;
    if(c[0]>x[0]) {printf("NO\n"); continue;}
    for (int i = 0; i < c[0]-3; i++) res += 'a';
    for (int i = 0; i < x[0]-c[0]+3; i++) res += 'a' + b++%3;
    bool isYes = true;
    for (int i = 1; i < k; i++)
    {
      if(x[i]-x[i-1]<c[i]-c[i-1]) {isYes = false; break;}
      for (int j = 0; j < c[i]-c[i-1]; j++) res += 'a' + i + 2;
      for (int j = 0; j < x[i]-x[i-1]-c[i]+c[i-1]; j++) res += 'a' + b++%3;
    }
    if(isYes) cout << "YES\n" << res << "\n";
    else printf("NO\n");
  }   
}