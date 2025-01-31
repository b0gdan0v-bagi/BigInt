#pragma once

#include <vector>
#include <string>
#include <iostream> 
#include <stdlib.h>  
#include <sstream>   
#include <cstdlib>

//using namespace std;

typedef int64_t ll;
typedef long long ll;
typedef std::pair<ll, ll> lll;
typedef std::pair<ll, int> lli;
typedef std::pair<int, int> ii;

#define EL printf("\n")
#define OK printf("OK")
//#define pb push_back
//#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef std::vector<int> BigInt;

void Set(BigInt& a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}

std::string BigIntToStr(BigInt a) {
    std::string res, buff;
    Set(a);
    (a.size() == 0) ? res += '0' : res += std::to_string(a.back());
    FORD(i, a.size() - 2, 0)
    {
        buff = std::to_string(a[i]);
        while (buff.size() != 9) buff = '0' + buff;
        res += buff;
    }
    return res;
}

BigInt toBigInt(std::string s) {
    BigInt ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) { ans.push_back(0); return ans; }
    while (s.size() % 9 != 0) s = '0' + s;
    for (int i = 0; i < s.size(); i += 9) {
        int v = 0;
        for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
        ans.insert(ans.begin(), v);
    }
    Set(ans);
    return ans;
}

BigInt toBigInt(char c[]) {
    std::string s = "";
    for (int i = 0;i<=strlen(c)-1 ;i++) s += c[i];
    return toBigInt(s);
}

BigInt toBigInt(ll x) {
    std::string s = "";
    while (x > 0) s = char(x % 10 + '0') + s, x /= 10;
    return toBigInt(s);
}

BigInt toBigInt(int x) {
    return toBigInt((ll)x);
}

void operator >> (std::istream& in, BigInt& a) {
    std::string s;
    std::getline(std::cin, s);
    a = toBigInt(s);
}

void operator << (std::ostream& out, BigInt a) {
    std::cout << BigIntToStr(a);
}

bool operator < (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (a.size() != b.size()) return (a.size() < b.size());
    FORD(i, a.size() - 1, 0)
        if (a[i] != b[i]) return (a[i] < b[i]);
    return false;
}

bool operator > (BigInt a, BigInt b) {
    return (b < a);
}

bool operator == (BigInt a, BigInt b) {
    return (!(a < b) && !(b < a));
}

bool operator <= (BigInt a, BigInt b) {
    return (a < b || a == b);
}

bool operator >= (BigInt a, BigInt b) {
    return (b < a || b == a);
}

bool operator < (BigInt a, int b) {
    return (a < toBigInt(b));
}

bool operator > (BigInt a, int b) {
    return (a > toBigInt(b));
}

bool operator == (BigInt a, int b) {
    return (a == toBigInt(b));
}

bool operator >= (BigInt a, int b) {
    return (a >= toBigInt(b));
}

bool operator <= (BigInt a, int b) {
    return (a <= toBigInt(b));
}

BigInt max(BigInt a, BigInt b) {
    if (a > b) return a;
    return b;
}

BigInt min(BigInt a, BigInt b) {
    if (a < b) return a;
    return b;
}

BigInt operator + (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
   // FOR(i, 0, max(a.size(), b.size()) - 1) 
    for(int i = 0; i<= std::max(a.size(), b.size()) - 1;i++)
    {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        ans.push_back(carry % base);
        carry /= base;
    }
    if (carry) ans.push_back(carry);
    Set(ans);
    return ans;
}

BigInt operator + (BigInt a, int b) {
    return a + toBigInt(b);
}

BigInt operator ++ (BigInt& a) { // ++a
    a = a + 1;
    return a;
}

void operator += (BigInt& a, BigInt b) {
    a = a + b;
}

void operator += (BigInt& a, int b) {
    a = a + b;
}




BigInt operator - (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i, 0, a.size() - 1) {
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if (carry < 0) ans.push_back(carry + base), carry = -1;
        else ans.push_back(carry), carry = 0;
    }
    Set(ans);
    return ans;
}

BigInt operator - (BigInt a, int b) {
    return a - toBigInt(b);
}

void operator -- (BigInt& a) { // --a
    a = a - 1;
}

void operator -= (BigInt& a, BigInt b) {
    a = a + b;
}

void operator -= (BigInt& a, int b) {
    a = a - b;
}


BigInt operator * (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    ans.assign(a.size() + b.size(), 0);
    FOR(i, 0, a.size() - 1) {
        ll carry = 0ll;
        for (int j = 0; j < b.size() || carry > 0; j++) {
            ll s = ans[i + j] + carry + (ll)a[i] * (j < b.size() ? (ll)b[j] : 0ll);
            ans[i + j] = s % base;
            carry = s / base;
        }
    }
    Set(ans);
    return ans;
}

BigInt operator * (BigInt a, int b) {
    return a * toBigInt(b);
}

void operator *= (BigInt& a, BigInt b) {
    a = a * b;
}

void operator *= (BigInt& a, int b) {
    a = a * b;
}

BigInt operator / (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == toBigInt(0)) return toBigInt("-1");
    BigInt ans, cur;
    FORD(i, a.size() - 1, 0) {
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (b * toBigInt(mid) > cur) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        cur = cur - toBigInt(x - 1) * b;
        ans.insert(ans.begin(), x - 1);
    }
    Set(ans);
    return ans;
}

std::pair<BigInt, BigInt> QR(BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == toBigInt(0)) return { toBigInt("-1"),toBigInt("-1") };
    BigInt ans, cur;
    FORD(i, a.size() - 1, 0) {
        cur.insert(cur.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (b * toBigInt(mid) > cur) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        cur = cur - toBigInt(x - 1) * b;
        ans.insert(ans.begin(), x - 1);
    }
    Set(ans);
    Set(cur);
    return { ans,cur };
}

BigInt operator / (BigInt a, int b) {
    Set(a);
    BigInt ans;
    ll cur = 0ll;
    FORD(i, a.size() - 1, 0) {
        cur = (cur * (ll)base + (ll)a[i]);
        ans.insert(ans.begin(), cur / b);
        cur %= b;
    }
    Set(ans);
    return ans;
}

void operator /= (BigInt& a, BigInt b) {
    a = a / b;
}

void operator /= (BigInt& a, int b) {
    a = a / b;
}

BigInt operator % (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (b == toBigInt(0)) return toBigInt("-1");
    BigInt ans;
    FORD(i, a.size() - 1, 0) {
        ans.insert(ans.begin(), a[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (b * toBigInt(mid) > ans) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        ans = ans - toBigInt(x - 1) * b;
    }
    Set(ans);
    return ans;
}

int operator % (BigInt a, int b) {
    Set(a);
    if (b == 0) return -1;
    int ans = 0;
    FORD(i, a.size() - 1, 0)
        ans = (ans * (base % b) + a[i] % b) % b;
    return ans;
}

void operator %= (BigInt& a, BigInt b) {
    a = a % b;
}
void operator %= (BigInt& a, int b) {
    a = a % toBigInt(b);
}
BigInt gcd(BigInt a, BigInt b) {
    Set(a);
    Set(b);
    while (b > toBigInt(0)) {
        BigInt r = a % b;
        a = b;
        b = r;
    }
    Set(a);
    return a;
}
BigInt lcm(BigInt a, BigInt b) {
    return (a * b / gcd(a, b));
}
BigInt sqrt(BigInt a) {
    BigInt x0 = a, x1 = (a + 1) / 2;
    while (x1 < x0) {
        x0 = x1;
        x1 = (x1 + a / x1) / 2;
    }
    return x0;
}
BigInt pow(BigInt a, BigInt b) {
    
    if (b == toBigInt(0)) return toBigInt(1);
    BigInt tmp = pow(a, b / 2);
    if (b % 2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}
BigInt pow(BigInt a, int b) {
    return pow(a, (toBigInt(b)));
}
int log(int n, BigInt a) { // log_n(a)
    Set(a);
    int ans = 0;
    while (a > toBigInt(1)) {
        ans++;
        a /= n;
    }
    return ans;
}



