//#include <bits/stdc++.h>
#include "bigint.h"

vector<string> divide_strings(string a, string b)
{
    BigInt aa = toBigInt(a);
    BigInt bb = toBigInt(b);
    pair<BigInt, BigInt> qu_re;
    Set(aa);
    Set(bb);
    BigInt ans, cur;
    FORD(i, aa.size() - 1, 0) {
        cur.insert(cur.begin(), aa[i]);
        int x = 0, L = 0, R = base;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (bb * toBigInt(mid) > cur) {
                x = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        cur = cur - toBigInt(x - 1) * bb;
        ans.insert(ans.begin(), x - 1);
    }
    Set(ans);
    Set(cur);

    vector<string> res;
    res.push_back(BigIntToStr(ans));
    res.push_back(BigIntToStr(cur));
    return res;
}

int main()
{
    vector<string> res;
    /*res = divide_strings("0", "5"); // {"0", "0"})); 
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("4", "5"); // {"0", "4"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("10", "2"); // {"5", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("20", "3"); // {"6", "2"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("60", "5"); // {"12", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("219", "11"); // {"19", "10"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("729", "9"); // {"81", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("1000", "10"); // {"100", "0"}));
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("600001", "100"); // {"6000", "1"}));
    cout << res[0] << " " << res[1] << "\n";*/
    res = divide_strings("12578367047084780373", "4158924807"); // {"6000", "1"}));
    cout << res[0] << " " << res[1] << "\n";

    BigInt aa = toBigInt("12578367047084780373");
    BigInt bb = toBigInt("4158924807");

    pair<BigInt, BigInt> test;
    test = QR(aa, bb);

    return 0;
}