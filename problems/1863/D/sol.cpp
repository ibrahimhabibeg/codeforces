#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    char a[n][m+1];
    vector<int> nu(n), nl(m);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    bool isYes = true;
    for (int i = 0; i < n; i++){
      int c = 0;
      for (int j = 0; j < m; j++) c+=a[i][j]!='.', nu[i]+=a[i][j]=='U';
      if(c%2==1){
        isYes = false; 
        break;
      }
    }
    for (int j = 0; j < m; j++){
      int c = 0;
      for (int i = 0; i < n; i++) c+=a[i][j]!='.', nl[j]+=a[i][j]=='L';
      if(c%2==1){
        isYes = false; 
        break;
      }
    }
    if(!isYes){
      printf("-1\n");
      continue;
    }
    for (int i = 0; i < n; i++){
      int c = 0;
      for (int j = 0; j < m; j++) 
      if(a[i][j]=='U') a[i][j]=c<nu[i]/2?'W':'B', a[i+1][j]=c<nu[i]/2?'B':'W', c++;
    }
    for (int j = 0; j < m; j++){
      int c = 0;
      for (int i = 0; i < n; i++) 
      if(a[i][j]=='L') a[i][j]=c<nl[j]/2?'W':'B', a[i][j+1]=c<nl[j]/2?'B':'W', c++;
    }
    for (int i = 0; i < n; i++)printf("%s\n", a[i]);
    
  }   
}