#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &m);
    int pn = 0, pm = 0, qn = 0, qm = 0;
    while (n%3==0){
      n/=3;
      pn++;
    }
    while (n%2==0){
      n/=2;
      qn++;
    }
    while (m%3==0){
      m/=3;
      pm++;
    }
    while (m%2==0){
      m/=2;
      qm++;
    }
    if(n==m && pn>=pm && qm-qn>=0 && pn-pm>=qm-qn) printf("YES\n");
    else printf("NO\n");
  }   
}