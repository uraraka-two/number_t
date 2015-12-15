#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <tuple>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

#define INIT 13

using namespace std;

// 304250263527210: 2 3 5 7 11 13 17 19 23 29 31 37 41
typedef tuple <int,int,int,int,int,int,int,int,int,int,int,int,int> fctr;
typedef long long ll;
map<fctr,int> mfctr;
ostream& operator<<(ostream& ost, const vector<int>& v)
{
  for (int i = 0; i < v.size(); ++i) {
     ost << v[i] << ' ';
  }
  return ost;
}

int main()
{
  vector<int> fs_tmp(INIT,1);
  vector<vector<int> > fs;
  map<ll,vector<int> > m;
  REP(i, INIT) fs_tmp[i] = i;
  for(int p = 2; p < INIT; p++){
    if (fs_tmp[p] != p) continue;
    int pp = 2*p;
    while ( pp <= INIT ){
      int t = fs_tmp[pp];
      if (m.count(pp) == 0) {
        vector<int> v;
        m[pp] = v;
      }
      auto l = m[pp];
      //l.push_back(t);
      l.push_back(p);
      m[pp] = l;
      fs_tmp[pp] = p;
      pp = pp + p;
    }
  } 
  //REP(i,INIT) cout << fs_tmp[i] << endl;
  for (map<ll,vector<int> >::const_iterator iter = m.begin();
        iter != m.end(); iter++) {
     auto x = iter->second; 
     auto t = make_tuple(2,3,5,1,1,1,1,1,1,1,1,1,1);
     mfctr[t]=iter->first;
     cout << iter->first << ":";
     cout << x << endl;
  }
  return 0;
}
