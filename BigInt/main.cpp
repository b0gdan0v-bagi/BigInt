//#include <bits/stdc++.h>
//#include "bigint.h"
#include "bigInt2.h"
#include <iostream> 
#include <list>
#include <chrono>
#include <future>
#include <thread>
#include <algorithm>
#include <fstream>


bool is_prime(int x) {
    //std::cout << "Calculating. Please, wait...\n";
    for (int i = 2; i < x; ++i) if (x % i == 0) return false;
    return true;
}

BigInt powP(BigInt a, BigInt b, int nThreads)
{
    if (b == BIGINT_ZERO) return BIGINT_ONE;
    BigInt tmp = pow(a, b / BIGINT_TWO);
    if (b % 2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}

int main()
{

    //std::cout << a+b;
    //std::cout << b << "\n";
    

    //BigInt c = BigInt("123456789987654321") * BigInt("123456789987654320");
    //std::cout << c - BigInt("15241578994055784077274805802316720") << "\n";
    //std::cout << BigInt("123456789987654321")*BigInt("123456789987654320");
    //std::cout << BigInt("1234567899876543218383838383838477777777777777777777")*BigInt("12e333333333333342342342354644234343433456789987654320")
    //    *BigInt("38381231247347237923379");
    //std::cout << BigInt("1234567899876543218383838383838477777777777777777777") / BigInt("12e3333333333333424343433456789987654320")
    //        *BigInt("38381231247347237923379");
    //std::cout << BigInt(123456) % BigInt(10);
    //BigInt c = factorial(10000);
    //std::cout << c;
    //unsigned const int nThreads = std::thread::hardware_concurrency();
    //unsigned const int nThreads = 100;

    //std::cout << nThreads << "\n";
    //std::future<int> result = std::async(calculate,3);
    //std::cout << result.get() << std::endl;
    std::vector<std::string> resStr;
    auto tp1 = std::chrono::high_resolution_clock::now();


    //std::cout << pow(BigInt(123), BigInt(5));
    std::cout << pow(123, 5);

    auto tp2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = tp2 - tp1;
    std::cout << "\nDone in " + std::to_string(elapsedTime.count()) + "s";
   /*
    for (int nThreads = 1; nThreads <= 25; nThreads++)
    {
        clock_t begin_time = clock();
        std::vector<std::future<bool>> VF;
        for (int i = 0; i < nThreads; i++)
        {
            VF.push_back(std::async(is_prime, 313222313));
        }
        std::vector<bool> V(VF.size());
        for (int i = 0; i < nThreads; i++)
        {
            V[i] = VF[i].get();
        }
        for (int i = 0; i < nThreads; i++)
        {
            //std::cout << "Checking whether " << 313222313 + i << "  is prime.\n";
            if (V[i]) std::cout << "+";
            else std::cout << "-";
        }
        float parallel = float(clock() - begin_time) / CLOCKS_PER_SEC;
        //std::cout << "\nDone in " << float(clock() - begin_time) / CLOCKS_PER_SEC << " sec\n";
        begin_time = clock();
        std::cout << "\n";
        for (int i = 0; i < nThreads; i++)
        {
            //std::cout << "Checking whether " << 313222313 + i << "  is prime.\n";
            if (is_prime(313222313)) std::cout << "+";
            else std::cout << "-";
        }
        std::cout << "\n";
        //std::cout << "\nDone in " << float(clock() - begin_time) / CLOCKS_PER_SEC << " sec\n";
        float once = float(clock() - begin_time) / CLOCKS_PER_SEC;
        std::cout << "By " << nThreads << " done by ratio " << once / parallel << " parallel = " << parallel
            << " once = " << once << "\n";
        resStr.push_back(std::to_string(nThreads) + " " + std::to_string(once / parallel) + " " +
            std::to_string(parallel) + " " + std::to_string(once));
    }

    std::ofstream output("output.txt");
    if (output.is_open())
    {
        for (auto const& i : resStr) output << i << "\n";
        output.close();
    }
    else std::cout << "Unable to create config.cfg file\n";
    //system("pause");
    */
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