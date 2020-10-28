//#include <bits/stdc++.h>
#include "bigint.h"
#include <list>

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

int lastDigit(BigInt a) {
    std::string s = BigIntToStr(a);
    return s.back() - '0';
}

int lastDigit(BigInt v1, BigInt v2)
{
   /* std::cout << v1;
    std::cout << endl;
    std::cout << v2;
    std::cout << endl;*/
    if ((v1 == toBigInt(0)) && (v2 == toBigInt(0))) return 1;
    if (v2 == toBigInt(0)) return lastDigit(v1);
    v2 = v2 % toBigInt(4);
    int lDigit = lastDigit(v1);
    if (v2 == 0) return (int)pow(lDigit, 4) % 10;
    else {
        v1 = pow(toBigInt(lDigit), v2);
        return lastDigit(v1);
    }
}

int last_digit(std::list<int> array) {

    std::vector<BigInt> v;
    for (auto const& i : array) v.push_back(toBigInt(i));

    switch (v.size())
    {
    case 0: return 1;
    case 1: return lastDigit(v[0]);
    case 2: return lastDigit(v[0], v[1]);
    default: {
        int last = v.size() - 1;
        while (true)
        {
            //for (auto& i : v) std::cout << " " << i;
            //std::cout << endl << last << std::endl;
            if (last == 0)
            {
                if (v[0] > toBigInt(9)) return lastDigit(v[0], v[1]);
                else return    lastDigit(v[0]);
            }
            
            if (v[last] == toBigInt(0))
            {
                v[last - 1] = toBigInt(1);
                last--;
            }
            else {
                //if (last != 1)
                //{
                    v[last] = v[last] % toBigInt(4);
                    //std::cout << "v[last] = " << BigIntToStr(v[last]) << "\n";
                    if (v[last] == toBigInt(0)) v[last-1] = pow(v[last - 1], toBigInt(4));
                    else v[last - 1] = pow(v[last - 1], v[last]);
                //}
                last--;
            }
            
        }
    }
    }
    return -1;
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
    cout << res[0] << " " << res[1] << "\n";
    res = divide_strings("12578367047084780373", "4158924807"); // {"6000", "1"}));
    cout << res[0] << " " << res[1] << "\n";*/
    std::cout << "ans = " << last_digit({}) << "\n";; //(1));
    std::cout << "ans = " << last_digit({ 0,0 }) << "\n";; //(1));
    std::cout << "ans = " << last_digit({ 0,0,0 }) << "\n";; //(0));
    std::cout << "ans = " << last_digit({ 1,2 }) << "\n";; //(1));
    std::cout << "ans = " << last_digit({ 3,4,5 }) << "\n"; //(1))<< "\n";
    std::cout << "ans = " << last_digit({ 4,3,6 }) << "\n"; //(4));
    std::cout << "ans = " << last_digit({ 7,6,21 }) << "\n"; //(1));
    std::cout << "ans = " << last_digit({ 12,30,21 }) << "\n"; //(6));
    std::cout << "ans = " << last_digit({ 2,2,2,0 }) << "\n"; //(4));
    std::cout << std::endl;
    std::cout << "ans = " << last_digit({ 937640,767456,981242 }) << "\n"; //(0));
    std::cout << "ans = " << last_digit({ 123232,694022,140249 }) << "\n"; //(6));
    std::cout << "ans = " << last_digit({ 499942,898102,846073 }) << "\n"; //(6));

    
    /*std::cout << "ans = " << last_digit({ 4,1}) << "\n";
    std::cout << "ans = " << last_digit({ 4,2}) << "\n";
    std::cout << "ans = " << last_digit({9,7}) << "\n";
    std::cout << last_digit({ 10,100000000 }) << "\n";
    */
    //std::cout << pow(toBigInt(694022), toBigInt(140249));

    return 0;
}