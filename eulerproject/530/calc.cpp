#include <iostream>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstdlib>

#define MAX 10000000

typedef unsigned long long int ll;
using namespace std;

bool v[MAX];
int sp[MAX];

void sieve(){
  for (ll i = 2; i < MAX; i += 2){
    sp[i] = 2;//even numbers have smallest prime factor 2
  }
  for (ll i = 3; i < MAX; i += 2){
    if (!v[i]){
      sp[i] = i;
      for (ll j = i; (j*i) < MAX; j += 2){
        if (!v[j*i]) v[j*i] = true, sp[j*i] = i;
      }
    }
  }
}

void sieve2() {
  for (ll i = 0; i < MAX; i += 1) sp[i] = i;
  
  for (ll i = 2; i < MAX; i += 2) {
    if (sp[i] == i) {
      ll pp = 2 * i;
      while (pp < MAX) {
        sp[pp] = i;
        pp = pp + i;
      }
    }
  }
}

inline ll gcd(ll x, ll y) {
  ll t;
  while (y != 0) {
    t = x % y;
    x = y;
    y = t;
  }
  return  x;
}
inline map<ll, int> fact(ll n){
  map<ll, int> hms;
  int a;
  if ( n == 1 ){
    return hms;
  } else if ( n % 2 == 0){
    a = 2;
  } else {
    a = sp[n];
  }
  while (n >= a * a) {
    if (n % a == 0) {
      hms[a]++;
      n /= a;
    } else {
      a++;
    }
  }
  if ( n > 1 )
    hms[n]++;
  return hms;
}

//
// a(p^e) = p^(e-1)*((p-1)e+p)
//
inline ll closed_form(ll p, ll e) {
  ll ans = pow(p, (e-1)) * ((p-1)*e+p);
  return ans;
}

int main() {
  ll k,d;

  cin >> k;
  ll sqrtK = sqrt(k);
  sieve();

  ll big_sum=0;
  map<ll, int> cnt;
  ll remainder, multiple, ans = 0;
  for (d = 1; d <= sqrtK; d++){
    ans = 0;
    cnt = fact(d);
    ll ans = 1;
    lldiv_t div;
    for (map<ll,int>::const_iterator p = cnt.begin();
          p != cnt.end(); p++) {

        int e = p->second;
        ans *= closed_form(p->first, e);
    }
    div = lldiv((k / d - d), d);
    multiple = div.quot;
    remainder = div.rem;
    ans = multiple * ans;
    for (ll i = 0; i < remainder; i++) {
      if ( d == i + 1 ) ans += d;
      else ans += gcd(d, i + 1);
    }
    big_sum += ans * 2 + d;
  }
  cout << big_sum << endl;
  return 0;
}
