//#include <bits/stdc++.h>
//#include "bigint.h"
#include "bigInt2.h"
#include <iostream> 
#include <list>
#include <chrono>
#include <thread>



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
    const clock_t begin_time = clock();

    //BigInt c = BigInt("123456789987654321") * BigInt("123456789987654320");
    //std::cout << c - BigInt("15241578994055784077274805802316720") << "\n";
    //std::cout << BigInt("123456789987654321")*BigInt("123456789987654320");
    //std::cout << BigInt("1234567899876543218383838383838477777777777777777777")*BigInt("12e333333333333342342342354644234343433456789987654320")
    //    *BigInt("38381231247347237923379");
    //std::cout << BigInt("1234567899876543218383838383838477777777777777777777") / BigInt("12e3333333333333424343433456789987654320")
    //        *BigInt("38381231247347237923379");
    //std::cout << BigInt(123456) % BigInt(10);

    //std::cout << sqrt(BigInt(100500)*BigInt(200501));
    //std::cout << pow(BigInt(100500), BigInt(0));
    //std::cout << factorial(100) - BigInt("93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
    
    std::cout << "\nDone in " << float(clock() - begin_time) / CLOCKS_PER_SEC << " sec\n";
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