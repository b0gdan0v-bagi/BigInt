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

BigInt simpleMulti(BigInt a, BigInt b)
{
    return a * b; // make lambda in future!
}

BigInt vectorParralelMultipicator(std::vector<BigInt> v)
{
    BigInt ans;
    std::cout << "Multiplicatin vector with size " << v.size() << "\n";
    switch (v.size())
    {
    case 0: return BIGINT_ONE;
    case 1: return v[0];
    case 2: return v[0] * v[1];
    default:
        int size = v.size();
        std::vector<std::future<BigInt>> results;
        if (size % 2 == 0)
        {
            ans = BIGINT_ONE;
            for (int i = 0; i < size; i += 2) results.push_back(std::async(std::launch::async, simpleMulti, v[i], v[i + 1]));
        }
        else
        {
            ans = v.back();
            for (int i = 0; i < size - 1; i += 2) results.push_back(std::async(std::launch::async, simpleMulti, v[i], v[i + 1]));
        }
        std::vector<BigInt> calc(results.size());
        for (int i = 0; i < calc.size(); i++) calc[i] = results[i].get();
        ans = ans * vectorParralelMultipicator(calc);

        break;
    }
//    ans = BIGINT_ONE;
    return ans;
}

BigInt factorialPartial(int s, int a)
{
    std::cout << "Worker " << s << " " << a << " started\n";
    auto tp1 = std::chrono::high_resolution_clock::now();
    if (a < s) return BIGINT_ONE;
    if (a == s) return BigInt(a);
    BigInt ans = BIGINT_ONE;
    if (a > s)
    {
        for (int i = s; i <= a; i++) ans = ans * BigInt(i);
    }
    auto tp2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = tp2 - tp1;
    std::cout <<"Worker " << s << " " << a << " ended in " + std::to_string(elapsedTime.count()) + "s\n";
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
    //std::cout << "start pos " << startPos << " " << ans << "\n";
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
    std::vector<BigInt> calc(par.size());
    for (int i = 0; i < calc.size(); i++) calc[i] = par[i].get();
    ans = vectorParralelMultipicator(calc);
    //for (auto i = par.begin(); i != par.end(); i++) ans = ans * (*i).get();

    return ans;
}

BigInt factorialP2(int a, int nThreads = 10)
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
    //std::cout << "start pos " << startPos << " " << ans << "\n";
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

BigInt factorialPartial_Parrallel(int s, int a, int nThreads = 10)
{
    BigInt ans;
    int startPos, lBound, uBound;
    a -= s;
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
    //std::cout << "start pos " << startPos << " " << ans << "\n";
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
        par.push_back(std::async(std::launch::async, factorialPartial, lBound+s, uBound+s));
    }
    for (auto i = par.begin(); i != par.end(); i++) ans = ans * (*i).get();

    return ans;
}

int main()
{
    /*int number = 150000;
    auto tpT = std::chrono::high_resolution_clock::now();
    auto aa = factorialP(number);
    auto tp2T = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTimeT = tp2T - tpT;
    std::cout << "\nDone in " + std::to_string(elapsedTimeT.count()) + "s\n";

    tpT = std::chrono::high_resolution_clock::now();
    auto bb = factorialP2(number);
    tp2T = std::chrono::high_resolution_clock::now();
    elapsedTimeT = tp2T - tpT;
    std::cout << "\nDone in " + std::to_string(elapsedTimeT.count()) + "s\n";
    std::cout << aa - bb;
    system("pause");*/
    std::string line;
    std::ifstream input("input.txt");
    if (input.is_open())
    {
        while (std::getline(input, line))
        {
            std::cout << line << '\n';
        }
        input.close();
    }
    int number = 110000;
    number = std::stoi(line);
    std::cout << "calculating factorial for " << number << "\n";
    auto tp1 = std::chrono::high_resolution_clock::now();
    auto veryBigFactorial = factorialP(number);
    auto tp2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = tp2 - tp1;
    std::cout << "\nDone in " + std::to_string(elapsedTime.count()) + "s\n";
    std::cout << "Factorial have " << veryBigFactorial.BigIntToStr().size() << " digigits!\n";
    std::cout << "We will try to write it in file!\n";


    std::ofstream log("log_factorial_" + std::to_string(number) + ".txt");
    if (log.is_open())
    {
        log << "\nDone in " + std::to_string(elapsedTime.count()) + "s\n";
        log << "Factorial have " << veryBigFactorial.BigIntToStr().size() << " digigits!\n";
    }
    else std::cout << "Unable to create log file\n";
    log.close();

    tp1 = std::chrono::high_resolution_clock::now();
    std::ofstream output("output_factorial_" + std::to_string(number) + ".txt");
    if (output.is_open())
    {
        output << veryBigFactorial.BigIntToStr();
    }
    else std::cout << "Unable to create output file\n";
    output.close();
    tp2 = std::chrono::high_resolution_clock::now();
    elapsedTime = tp2 - tp1;
    std::cout << "\nDone in " + std::to_string(elapsedTime.count()) + "s\nPress any key to exit!\n";
    system("pause");
    /*
    auto tp1 = std::chrono::high_resolution_clock::now();
    auto test = factorial(number);
    auto tp2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = tp2 - tp1;
    std::cout << "\nDone in " + std::to_string(elapsedTime.count()) + "s\n";
    int const nThreads_MAX = 30;
    //auto testP = factorialP(number, 7);
    //std::cout << test - testP << "\n";
    //system("pause");
    std::vector<std::string> resStr;


    for (int i = 3; i <= nThreads_MAX; i++)
    {
        tp1 = std::chrono::high_resolution_clock::now();
        auto testP = factorialP(number, i);
        tp2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTimeP = tp2 - tp1;
        std::cout << "\nFor nTreads = " << i << " done in " + std::to_string(elapsedTimeP.count()) + "s\n";
        std::cout << "Ratio is " + std::to_string(elapsedTime.count() / elapsedTimeP.count()) + "s\n";
        std::cout << "Correct? " << test - testP << "\n";

        resStr.push_back(std::to_string(i) + " " + std::to_string(elapsedTime.count() / elapsedTimeP.count()) + " " +
            std::to_string(elapsedTimeP.count()) + " " + std::to_string(i * elapsedTime.count()));
    }
    
    std::ofstream output("output.txt");
    if (output.is_open())
    {
        for (auto const& i : resStr) output << i << "\n";
        output.close();
    }
    else std::cout << "Unable to create config.cfg file\n";*/
}