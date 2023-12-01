#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int m[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &m[i][j]);
    vector<int> a(n, (1<<30)-1);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
    if(i!=j) a[i]=a[i]&m[i][j];
    bool isYes = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
    if(i!=j && (a[i]|a[j])!=m[i][j]) isYes = false;
    if(isYes){
      printf("YES\n");
      for (int i = 0; i < n; i++) printf("%d ", a[i]);
      printf("\n");
    }
    else printf("NO\n");
  }   
}