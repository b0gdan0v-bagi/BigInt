#include "bigInt2.h"

std::ostream& operator<<(std::ostream& out, const BigInt& bigint)
{
	
	for (auto i = bigint.m_values.rbegin(); i != bigint.m_values.rend();i++) out << *i;
	return out;
}

bool operator==(const BigInt& b1, const BigInt& b2)
{
	if (b1.m_values.size() != b2.m_values.size()) return false;
	for (int i = 0; i < b1.m_values.size(); i++) if (b1.m_values[i] != b2.m_values[i]) return false;
	return true;
}

bool operator<(const BigInt& b1, const BigInt& b2)
{
	if (b1.m_values.size() != b2.m_values.size()) return (b1.m_values.size() < b2.m_values.size());
	//FORD(i, b1.m_values.size() - 1, 0)
	for (int i=b1.m_values.size()-1;i>=0;i--)
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
	for (int i = 0; i <= std::max(b1.m_values.size(), b2.m_values.size()) - 1; i++)
	{
		if (i < b1.m_values.size()) carry += b1.m_values[i];
		if (i < b2.m_values.size()) carry += b2.m_values[i];
		ans.m_values.push_back(carry % base);
		carry /= base;
	}
	if (carry) ans.m_values.push_back(carry);
	ans.Set();
	//for (auto i = ans.m_values.rbegin(); i != ans.m_values.rend(); i++) std::cout << *i << "\n";
	
	return ans;
}

BigInt operator-(const BigInt& b1, const BigInt& b2)
{
	BigInt ans;
	int carry = 0;
	for (int i = 0; i < b1.m_values.size(); i++)
	{
		carry += b1.m_values[i] - (i < b2.m_values.size() ? b2.m_values[i] : 0);
		if (carry < 0) ans.m_values.push_back(carry + base), carry = -1;
		else ans.m_values.push_back(carry), carry = 0;
	}
	ans.Set();
	return ans;
}

BigInt operator*(const BigInt& b1, const BigInt& b2)
{
	BigInt ans;
	ans.m_values.assign(b1.m_values.size() + b2.m_values.size(), 0);
	for(int i = 0;i< b1.m_values.size();i++)
	{
		ll carry = 0ll;
		for (int j = 0; j < b2.m_values.size() || carry > 0; j++) {
			ll s = ans.m_values[i + j] + carry + (ll)b1.m_values[i] * (j < b2.m_values.size() ? (ll)b2.m_values[j] : 0ll);
			ans.m_values[i + j] = s % base;
			carry = s / base;
		}
	}
	ans.Set();
	return ans;
}

BigInt operator/(const BigInt& b1, const BigInt& b2)
{
	if (b2 == BigInt(0)) {
		std::cout << "Warning divider = ZERO, answer is -1 \n";
		return BigInt("-1");
	}
	BigInt ans, cur;
	
	for (int i = b1.m_values.size()-1; i>=0;i--)
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
	ans.Set();
	return ans;
}

BigInt operator%(const BigInt& b1, const BigInt& b2)
{
	if (b2 == BigInt(0)) {
		std::cout << "Warning divider = ZERO, answer is -1 \n";
		return BigInt("-1");
	}
	BigInt cur;
	for (int i = b1.m_values.size() - 1; i >= 0; i--)
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
	cur.Set();
	return cur;
}


