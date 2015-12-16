#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <tuple>
#include <iomanip>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

// 304250263527210: 2 3 5 7 11 13 17 19 23 29 31 37 41
typedef tuple <int,int,int,int,int,int,int,int,int,int,int,int,int> fctr;
typedef long long ll;
map<fctr,int> mfctr;
ostream& operator<<(ostream& ost, const vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
     ost << v[i] << ' ';
  }
  return ost;
}
ostream& operator<<(ostream& ost, const fctr& key_fctr) {
  int a[13];
  tie(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11],a[12]) = key_fctr;
  for (int i = 0; i<13; i++) {
     if (a[i] > 1) ost << ' ' << a[i];
  }
  return ost;
}

int main() {
  int INIT;
  cin >> INIT;
  vector<int> fs_tmp(INIT,1);
  vector<vector<int> > fs;
  map<ll,vector<int> > m;
  REP(i, INIT) fs_tmp[i] = i;
  vector<int> v;
  for(int p = 2; p < INIT; p++){
    if (fs_tmp[p] != p) continue;
    int pp = 2*p;
    while ( pp <= INIT ){
      int t = fs_tmp[pp];
      if (m.count(pp) == 0) {
        v.clear();
        m[pp] = v;
      }
      auto l = m[pp];
      l.push_back(p);
      m[pp] = l;
      fs_tmp[pp] = p;
      pp = pp + p;
    }
  } 
  for (map<ll,vector<int> >::const_iterator iter = m.begin();
        iter != m.end(); iter++) {
     auto x = iter->second; 
     int a[14];
     for(int idx = 0; idx<13; idx++){
       if (idx < x.size() ) a[idx] = x[idx];
       else a[idx] = 1;
     }
     auto t = make_tuple(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11],a[12]);
     mfctr[t]=iter->first;
  }
  for (map<fctr,int >::const_iterator iter = mfctr.begin();
        iter != mfctr.end(); iter++) {
    cout << iter->first << ":" << iter->second << endl;
  }

  return 0;
}
