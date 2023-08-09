#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
  while (b!=0){
    int c = b;
    b = a%b, a = c;
  }
  return a;
}

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], b[n];
    bool isYes = true;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int j = 0;
    while (j<n && a[j]==0 && b[j]==0) j++;
    if(j==n) {printf("YES\n"); continue;}
    int d = gcd(a[j], b[j]), v = 2*((a[j]/d)%2) + ((b[j]/d)%2), x;
    for (int i = j+1; i < n; i++){
      if(a[i]==0 && b[i]==0) continue;
      d = gcd(a[i], b[i]), x = 2*((a[i]/d)%2) + ((b[i]/d)%2);
      if(x!=v){
        isYes = false;
        break;
      }
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}