#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, sx, sy, j;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d%d", &n, &sx, &sy);
    int x[n+1], y[n+1];
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    set<int> a, b;
    for (int i = 1; i <= n; i++){
      if((sx+sy)%2==(x[i]+y[i])%2) a.insert(i);
      else b.insert(i);
    }
    bool isFirst = a.size()>=b.size();
    if(isFirst){
      printf("First\n");
      fflush(stdout);
      if(b.begin()!=b.end()){
        printf("%d\n", *(b.begin()));
        fflush(stdout);
        b.erase(b.begin());
      }else{
        printf("%d\n", *(a.begin()));
        fflush(stdout);
        a.erase(a.begin());
      }
    }else{
      printf("Second\n");
      fflush(stdout);
    }
    while (a.size()>0 || b.size()>0){
      scanf("%d", &j);
      if((sx+sy)%2==(x[j]+y[j])%2) a.erase(j);
      else b.erase(j);
      if(a.size()==0 && b.size()==0) break;
      if(isFirst){
        if(b.begin()!=b.end()){
          printf("%d\n", *(b.begin()));
          fflush(stdout);
          b.erase(b.begin());
        }else{
          printf("%d\n", *(a.begin()));
          fflush(stdout);
          a.erase(a.begin());
        }
      }else{
        if(a.begin()!=a.end()){
          printf("%d\n", *(a.begin()));
          fflush(stdout);
          a.erase(a.begin());
        }else{
          printf("%d\n", *(b.begin()));
          fflush(stdout);
          b.erase(b.begin());
        }
      }
    }
    
  }   
}