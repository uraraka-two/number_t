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

ll gcd_bi(ll u, ll v)
{
    // simple cases (termination)
    if (u == v) return u;

    if (u == 0) return v;

    if (v == 0) return u;

    // look for factors of 2
    if (~u & 1) { // u is even 
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
    return gcd((v - u) >> 1, u);
}

ll gcd_iter(ll u, ll v) {
  int shift;
  /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
  if (u == 0) return v;
  if (v == 0) return u;
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
  while ((u & 1) == 0)
    u >>= 1;
  do {
       while ((v & 1) == 0)  /* Loop X */
           v >>= 1;
       if (u > v) {
         unsigned int t = v; v = u; u = t;}  // Swap u and v.
       v = v - u;                       // Here v >= u.
     } while (v != 0);
  /* restore common factors of 2 */
  return u << shift;
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
      ans += gcd_iter(d, i + 1);
    }
    big_sum += ans * 2 + d;
  }
  cout << big_sum << endl;
  return 0;
}
