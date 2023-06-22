#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  string s;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<int> edges[3][3], ex[3][3];
    vector<tuple<int, int, int, int>> res;
    for (int i = 0; i < n; i++){
      cin >> s;
      pair<int, int> cnt[3] = {make_pair(0,0), make_pair(0,1), make_pair(0,2)};
      for (char c: s) cnt[0].first+=c=='w', cnt[1].first+=c=='i', cnt[2].first+=c=='n';
      sort(cnt, cnt+3);
      if(cnt[2].first==3) edges[cnt[2].second][cnt[0].second].push_back(i+1), edges[cnt[2].second][cnt[1].second].push_back(i+1);
      else if(cnt[2].first==2) edges[cnt[2].second][cnt[0].second].push_back(i+1);
    }
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        for (int k = edges[i][j].size()-1; k>=0; k--){
          int sz = edges[j][i].size(); 
          if(sz==0) ex[i][j].push_back(edges[i][j][k]);
          else {
            res.push_back(make_tuple(edges[i][j][k], i, edges[j][i][sz-1], j));
            edges[j][i].pop_back();
          }
          edges[i][j].pop_back();
        }
      }
    }
    for (int i = 0; i < ex[0][1].size(); i++){
      res.push_back(make_tuple(ex[0][1][i], 0, ex[1][2][i], 1));
      res.push_back(make_tuple(ex[1][2][i], 0, ex[2][0][i], 2));
    }
    for (int i = 0; i < ex[0][2].size(); i++){
      res.push_back(make_tuple(ex[0][2][i], 0, ex[2][1][i], 2));
      res.push_back(make_tuple(ex[2][1][i], 0, ex[1][0][i], 1));
    }
    printf("%d\n", (int)res.size());
    for (int i = 0; i < res.size(); i++){
      int c1 = get<1>(res[i]), c2 = get<3>(res[i]);
      printf("%d %c %d %c\n", get<0>(res[i]), c1==0?'w':c1==1?'i':'n', get<2>(res[i]), c2==0?'w':c2==1?'i':'n');
    }
  }   
}