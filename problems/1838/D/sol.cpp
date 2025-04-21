#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, q, p;
  string s;
  scanf("%d %d", &n, &q);
  cin >> s;
  s = ' ' + s;
  set<int> a;
  for (int i = 1; i <= n; i++) if((i%2==0 && s[i] == '(')|| (i%2==1 && s[i] == ')')) a.insert(i);
  while (q--){
    scanf("%d", &p);
    if(n%2==1){printf("NO\n"); continue;}
    s[p] = s[p]=='('?')':'(';
    if((p%2==0 && s[p] == '(')|| (p%2==1 && s[p] == ')')) a.insert(p);
    else a.erase(p);
    if(a.empty()||((*a.begin())%2==0 && (*a.rbegin())%2==1)) printf("YES\n");
    else printf("NO\n");
  }   
}