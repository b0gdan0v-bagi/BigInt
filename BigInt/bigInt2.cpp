#include "bigInt2.h"

void BigInt::PrintStr()
{
	std::cout << BigIntToStr() << "\n";
}

void BigInt::PrintInt()
{
	for (auto i = m_values.rbegin(); i != m_values.rend(); i++) std::cout << *i;
	std::cout << std::endl;
}

std::string BigInt::BigIntToStr()
{
	std::string res, buff;
	while (m_values.size() > 1 && m_values.back() == 0)m_values.pop_back();
	(m_values.size() == 0) ? res += '0' : res += std::to_string(m_values.back());
	for (long long i = m_values.size() - 2; i >= 0; i--)
	{
		buff = std::to_string(m_values[i]);
		while (buff.size() != 9) buff = '0' + buff;
		res += buff;
	}
	return res;
}

void BigInt::Set() {
	while (m_values.size() > 1 && m_values.back() == 0) { std::cout << "SET WORKING!\n"; m_values.pop_back(); }
}

std::ostream& operator<<(std::ostream& out, const BigInt& bigint)
{
	
	for (auto i = bigint.m_values.rbegin(); i != bigint.m_values.rend();i++) out << *i;
	return out;
}

bool operator==(const BigInt& b1, const BigInt& b2)
{
	if (b1.m_values.size() != b2.m_values.size()) return false;
	for (long long i = 0; i < b1.m_values.size(); i++) if (b1.m_values[i] != b2.m_values[i]) return false;
	return true;
}

bool operator<(const BigInt& b1, const BigInt& b2)
{
	if (b1.m_values.size() != b2.m_values.size()) return (b1.m_values.size() < b2.m_values.size());
	//FORD(i, b1.m_values.size() - 1, 0)
	for (long long i=b1.m_values.size()-1;i>=0;i--)
		if (b1.m_values[i] != b2.m_values[i]) return (b1.m_values[i] < b2.m_values[i]);

	return false;
}

bool operator>(const BigInt& b1, const BigInt& b2)
{
	return (b2 < b1);
}

bool operator<=(const BigInt& b1, const BigInt& b2)
{
	return (b1 < b2 || b1 == b2);
}

bool operator>=(const BigInt& b1, const BigInt& b2)
{
	return (b2 < b1 || b2 == b1);
}

BigInt operator+(const BigInt &b1, const BigInt &b2)
{
	BigInt ans;
	int carry = 0;
	// FOR(i, 0, max(a.size(), b.size()) - 1) 
	for (long long i = 0; i <= std::max(b1.m_values.size(), b2.m_values.size()) - 1; i++)
	{
		if (i < b1.m_values.size()) carry += b1.m_values[i];
		if (i < b2.m_values.size()) carry += b2.m_values[i];
		ans.m_values.push_back(carry % base);
		carry /= base;
	}
	if (carry) ans.m_values.push_back(carry);
	//ans.Set();
	while (ans.m_values.size() > 1 && ans.m_values.back() == 0) ans.m_values.pop_back(); 
	//for (auto i = ans.m_values.rbegin(); i != ans.m_values.rend(); i++) std::cout << *i << "\n";
	
	return ans;
}

BigInt operator-(const BigInt& b1, const BigInt& b2)
{
	BigInt ans;
	int carry = 0;
	for (long long i = 0; i < b1.m_values.size(); i++)
	{
		carry += b1.m_values[i] - (i < b2.m_values.size() ? b2.m_values[i] : 0);
		if (carry < 0) ans.m_values.push_back(carry + base), carry = -1;
		else ans.m_values.push_back(carry), carry = 0;
	}
	//ans.Set();
	while (ans.m_values.size() > 1 && ans.m_values.back() == 0) ans.m_values.pop_back();
	return ans;
}

BigInt operator*(const BigInt& b1, const BigInt& b2)
{
	BigInt ans;
	ans.m_values.assign(b1.m_values.size() + b2.m_values.size(), 0);
	for(long long i = 0;i< b1.m_values.size();i++)
	{
		ll carry = 0ll;
		for (long long j = 0; j < b2.m_values.size() || carry > 0; j++) {
			ll s = ans.m_values[i + j] + carry + (ll)b1.m_values[i] * (j < b2.m_values.size() ? (ll)b2.m_values[j] : 0ll);
			ans.m_values[i + j] = s % base;
			carry = s / base;
		}
	}
	//ans.Set();
	while (ans.m_values.size() > 1 && ans.m_values.back() == 0) { ans.m_values.pop_back(); }
	return ans;
}

BigInt operator/(const BigInt& b1, const BigInt& b2)
{
	if (b2 == BigInt(0)) {
		std::cout << "Warning divider = ZERO, answer is -1 \n";
		return BigInt("-1");
	}
	BigInt ans, cur;
	
	for (long long i = b1.m_values.size()-1; i>=0;i--)
	{
		cur.m_values.insert(cur.m_values.begin(), b1.m_values[i]);
		int x = 0, L = 0, R = base;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (b2 * BigInt(mid) > cur) {
				x = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		cur = cur - BigInt(x - 1) * b2;
		ans.m_values.insert(ans.m_values.begin(), x - 1);
	}
	//ans.Set();
	while (ans.m_values.size() > 1 && ans.m_values.back() == 0) ans.m_values.pop_back();
	return ans;
}

BigInt operator/(const BigInt& b1, const int& b2)
{
	if (b2 == 0) return -1;
	int ans = 0;
	for(int i = b1.m_values.size() - 1; i>=0;i--)
		ans = (ans * (base % b2) + b1.m_values[i] % b2) % b2;
	return ans;
}

BigInt operator % (const BigInt& b1, const BigInt& b2)
{
	if (b2 == BigInt(0)) {
		std::cout << "Warning divider = ZERO, answer is -1 \n";
		return BigInt("-1");
	}
	BigInt cur;
	for (long long i = b1.m_values.size() - 1; i >= 0; i--)
	{
		cur.m_values.insert(cur.m_values.begin(), b1.m_values[i]);
		int x = 0, L = 0, R = base;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (b2 * BigInt(mid) > cur) {
				x = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		cur = cur - BigInt(x - 1) * b2;
	}
	//cur.Set();
	while (cur.m_values.size() > 1 && cur.m_values.back() == 0) cur.m_values.pop_back();
	return cur;
}

BigInt operator%(const BigInt& b1, const int& b2)
{
	BigInt ans;
	ll cur = 0ll;
	for (long long i = b1.m_values.size() - 1; i >= 0; i--)
	{
		cur = (cur * (ll)base + (ll)b1.m_values[i]);
		ans.m_values.insert(ans.m_values.begin(), cur / b2);
		cur %= b2;
	}
	//ans.Set();
	while (ans.m_values.size() > 1 && ans.m_values.back() == 0) ans.m_values.pop_back();
	return ans;
}

BigInt sqrt(BigInt a)
{
	BigInt x0 = a, x1 = (a + BIGINT_ONE) / BIGINT_TWO;
	while (x1 < x0) {
		x0 = x1;
		x1 = (x1 + a / x1) / BIGINT_TWO;
	}
	return x0;
}

BigInt pow(BigInt a, BigInt b) 
{

	if (b == BIGINT_ZERO) return BIGINT_ONE;
	BigInt tmp = pow(a, b / BIGINT_TWO);
	if (b % 2 == 0) return tmp * tmp;
	return tmp * tmp * a;
}
BigInt pow(BigInt a, int b) {
	return pow(a, (BigInt(b)));
}
int log(int n, BigInt a) { // log_n(a)
	a.Set();
	int ans = 0;
	while (a > BIGINT_ONE) {
		ans++;
		a = a / n;
	}
	return ans;
}

BigInt factorial(int a)
{
	if (a == 0) return BIGINT_ONE;
	BigInt ans = BIGINT_ONE;
	for (int i = 1; i <= a; i++)
	{
		ans = ans * BigInt(i);
	}
	//ans.Set();
	while (ans.m_values.size() > 1 && ans.m_values.back() == 0) ans.m_values.pop_back();
	return ans;
}



