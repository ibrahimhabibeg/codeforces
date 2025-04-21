#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    int res = 0;
    for (int i = 2; i < n; i++) if(s[i-2]=='p' && s[i-1]=='i' && s[i]=='e') res++;
    for (int i = 2; i < n; i++) if(s[i-2]=='m' && s[i-1]=='a' && s[i]=='p') res++;
    for (int i = 4; i < n; i++) if(s[i-4]=='m' && s[i-3]=='a' && s[i-2]=='p' && s[i-1]=='i' && s[i]=='e') res--;
    printf("%d\n", res);
  }   
}