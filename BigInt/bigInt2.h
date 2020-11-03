#pragma once

#include <vector>
#include <string>
#include <iostream> 

typedef long long ll;
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;

typedef std::vector<int> bigInt;

class BigInt 
{
    std::vector<int> m_values;
public:
    BigInt() {}
    BigInt(std::string s) :m_values(toBigInt(s)) {}
    BigInt(ll x) : m_values(toBigInt(x)) {}
    BigInt(int x) : m_values(toBigInt((ll)x)) {}

    void PrintStr() { std::cout << BigIntToStr() << "\n"; }
    void PrintInt() {
        for (auto i = m_values.rbegin(); i != m_values.rend(); i++) std::cout << *i;
        std::cout << std::endl;
    }

    std::string BigIntToStr() {
        std::string res, buff;
        Set();
        (m_values.size() == 0) ? res += '0' : res += std::to_string(m_values.back());
        for (int i = m_values.size() - 2; i >= 0; i--)
        {
            buff = std::to_string(m_values[i]);
            while (buff.size() != 9) buff = '0' + buff;
            res += buff;
        }
        return res;
    }

    int getSizeOfBlocks() { return m_values.size(); }
    friend std::ostream& operator<< (std::ostream& out, const BigInt& bigint);
    friend bool operator== (const BigInt& b1, const BigInt& b2);
    friend bool operator< (const BigInt& b1, const BigInt& b2);
    friend bool operator> (const BigInt& b1, const BigInt& b2);
    friend bool operator<= (const BigInt& b1, const BigInt& b2);
    friend bool operator>= (const BigInt& b1, const BigInt& b2);
    friend BigInt operator+(const BigInt& b1, const BigInt& b2);
    friend BigInt operator-(const BigInt& b1, const BigInt& b2);
    friend BigInt operator*(const BigInt& b1, const BigInt& b2);
    


private:

    std::vector<int> toBigInt(std::string s) {
        bigInt ans;
        std::vector<int> reverseAns;
        if (s[0] == '-') return ans;
        if (s.size() == 0) { ans.push_back(0); return ans; }
        while (s.size() % 9 != 0) s = '0' + s;
        for (int i = 0; i < s.size(); i += 9) {
            int v = 0;
            for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
            reverseAns.push_back(v);
            //ans.insert(ans.begin(), v);
        }
        ans.reserve(reverseAns.size());
        for (auto i = reverseAns.rbegin(); i != reverseAns.rend(); i++) ans.push_back(*i);
        Set();
       // std::cout << ans.size();
        return ans;
    }

    std::vector<int> toBigInt2(std::string s) {
        std::vector<int> ans;
        if (s[0] == '-') return ans;
        if (s.size() == 0) { ans.push_back(0); return ans; }
        while (s.size() % 9 != 0) s = '0' + s;
        for (int i = 0; i < s.size(); i += 9) {
            int v = 0;
            for (int j = i; j < i + 9; j++) v = v * 10 + (s[j] - '0');
            ans.insert(ans.begin(), v);
        }
        Set();
        return ans;
    }

    std::vector<int> toBigInt(ll x) {
        std::string s = "";
        while (x > 0) s = char(x % 10 + '0') + s, x /= 10;
        return toBigInt(s);
    }


    void Set() { while (m_values.size() > 1 && m_values.back() == 0) m_values.pop_back(); }

    
};