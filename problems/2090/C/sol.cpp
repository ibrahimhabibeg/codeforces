#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getX(int s, int t_x, int p){
  if(p==2) s--;
  if(p==0||p==1) return 3*t_x+1;
  else return 3*t_x+2;
}

int getY(int s, int t_x, int p){
  if(p==2) s--;
  int t_y = s-t_x;
  if(p==0||p==3) return 3*t_y+1;
  else return 3*t_y+2;
}

void solve(){
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  set<vector<int>> taken;
  vector<int> t = {0, 0};
  int s = 0, v = 0, t_x = 0, p = 0;
  for (int i = 0; i < n; i++) {
    if(a[i]==0) {
      while(taken.find({3*t[1]+1, 3*(t[0]-t[1])+1})!=taken.end()){
        if(t[1]<t[0]) t[1]++;
        else t[0]++, t[1] = 0;
      }
      printf("%d %d\n", 3*t[1]+1, 3*(t[0]-t[1])+1);
      taken.insert({3*t[1]+1, 3*(t[0]-t[1])+1});
    } else {
      int x = getX(s, t_x, p), y =  getY(s, t_x, p);
      while (taken.find({x, y})!=taken.end() || x<1 || y<1){
        if(p==3 && t_x==s) s+=1, v = 0, t_x = 0, p = 0;
        else if(t_x==s && v==0) v+=1, t_x = 0, p = 1;
        else if(v==0 || p==3) t_x+=1, p = v?1:0;
        else p+=1;
        x = getX(s, t_x, p), y =  getY(s, t_x, p);
      }
      printf("%d %d\n", x, y);
      taken.insert({x, y});
    }
  }
  
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}