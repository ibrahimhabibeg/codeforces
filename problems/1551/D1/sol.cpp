#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d",&n, &m, &k);
    int s = n*m/2, v = s-k;
    bool res;
    if(n==1) res=k==s;
    else if(m==1) res=k==0;
    else if((n%2)==0 && (m%2)==0)res=(k%2)==0;
    else if((n%2)==0) res = ((k%2)==0) && (v>=n/2);
    else res = ((v%2)==0) && (k>=m/2);
    if(res) printf("YES\n");
    else printf("NO\n");
  }   
}