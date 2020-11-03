//#include <bits/stdc++.h>
//#include "bigint.h"
#include "bigInt2.h"
#include <iostream> 
#include <list>
#include <chrono>



int main()
{
    BigInt a("123456789987654321");
    std::cout << a.BigIntToStr() << "\n";
    a.PrintStr();
    a.PrintInt();
    std::cout << a.getSizeOfBlocks() << "\n";
    
    BigInt b(1234);
    std::cout << b << "\n" << b.getSizeOfBlocks() << "\n";

    std::cout << (a > b);
    std::cout << "\n**\n";
    //std::cout << a+b;
    //std::cout << b << "\n";
    BigInt c = BigInt("123456789987654321") * BigInt("123456789987654320");
    std::cout << c - BigInt("15241578994055784077274805802316720") << "\n";
    std::cout << BigInt("123456789987654321")*BigInt("123456789987654320");
    //std::cin >> b;
    /*
    BigInt a = toBigInt("123456789987654321");
    std::cout << BigIntToStr(a);
    system("pause");
    const clock_t begin_time = clock();
    BigInt answer = pow(toBigInt(123232), 694);
    
    std::cout << BigIntToStr(answer);

    std::cout << "Done in " << float(clock() - begin_time) / CLOCKS_PER_SEC << " sec\n";
    std::cout << "123232^69402 have " << answer.size() * 9 << " digits, here its list\n";
    system("pause");
    return 0;*/
}