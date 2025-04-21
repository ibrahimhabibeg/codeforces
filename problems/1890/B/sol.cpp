#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &m);
    char s[n+1], t[m+1];
    scanf("%s%s", s, t);
    bool isT = m%2==1;
    for (int i = 1; i < m; i++) if(t[i]==t[i-1]) isT = false;
    bool isS = true;
    for (int i = 1; i < n; i++)
      if(s[i]==s[i-1]&&!(isT&&s[i]!=t[0]))
       isS = false;
    if(isS) printf("Yes\n");
    else printf("No\n");
  }   
}