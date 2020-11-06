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

BigInt factorialPartial(int s, int a)
{
    if (a < s) return BIGINT_ONE;
    if (a == s) return BigInt(a);
    BigInt ans = BIGINT_ONE;
    if (a > s)
    {
        for (int i = s; i <= a; i++) ans = ans * BigInt(i);
    }
    return ans;
}

BigInt factorialP(int a, int nThreads = 10)
{
    BigInt ans;
    int startPos, lBound, uBound;
    if (a % nThreads == 0)
    {
        startPos = 0;
        ans = BIGINT_ONE;
    }
    else
    {
        startPos = a % nThreads;
        ans = factorial(startPos);
    }
    std::cout << "start pos " << startPos << " " << ans << "\n";
    std::vector<std::future<BigInt>> par;
    for (int i = 0; i < nThreads; i++)
    {
        lBound = startPos + 1 + a * i / nThreads;
        if (i != nThreads - 1) uBound = startPos + a * (i + 1) / nThreads;
        else uBound = a;
        if (lBound > a) lBound = a;
        if (uBound > a) uBound = a;
        if (lBound == a && uBound == a) { lBound = 1; uBound = 1; }
        //std::cout << "Workers pos " << lBound << " " << uBound << "\n";
        par.push_back(std::async(std::launch::async, factorialPartial, lBound, uBound));
    }
    for (auto i = par.begin(); i != par.end(); i++) ans = ans * (*i).get();

    return ans;
}

int main()
{
    int number = 50000;
    auto tp1 = std::chrono::high_resolution_clock::now();
    auto test = factorial(number);
    auto tp2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = tp2 - tp1;
    std::cout << "\nDone in " + std::to_string(elapsedTime.count()) + "s\n";
    int const nThreads_MAX = 30;
    //auto testP = factorialP(number, 7);
    //std::cout << test - testP << "\n";
    //system("pause");
    for (int i = 3; i <= nThreads_MAX; i++)
    {
        tp1 = std::chrono::high_resolution_clock::now();
        auto testP = factorialP(number, i);
        tp2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTimeP = tp2 - tp1;
        std::cout << "\nFor nTreads = " << i << " done in " + std::to_string(elapsedTimeP.count()) + "s\n";
        std::cout << "Ratio is " + std::to_string(elapsedTime.count() / elapsedTimeP.count()) + "s\n";
        std::cout << "Correct? " << test - testP << "\n";
    }
    
}