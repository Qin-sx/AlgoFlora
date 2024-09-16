#include <iostream>
#include <iomanip>
#include <bitset>

#define BITNUM 16

int method_0(int n)
{
    std::cout << "method_0(n)" << std::endl;
    int count = 0;
    int i = 0;
    while (n)
    {   
        std::cout << "setp" << std::setfill('0') << std::setw(2) << ++i << " "<< std::bitset<BITNUM>(n) << std::endl;
        int a = n;
        std::cout <<"       " << std::bitset<BITNUM>(a >>= 1) << std::endl;

        count += n & 1;
        n >>= 1;
    }
    return count;
}

int method_1(int n)
{
    std::cout << "method_1(n)" << std::endl;
    int i = 0;
    int count = 0;
    while (n)
    {
        std::cout << "setp" << std::setfill('0') << std::setw(2) << ++i << " "<< std::bitset<BITNUM>(n) << std::endl;
        std::cout <<"       " << std::bitset<BITNUM>(n - 1) << std::endl;
        std::cout <<"       " << std::bitset<BITNUM>(n & n - 1) << std::endl;
        
        n &= n - 1;
        count++;
    }
    return count;
}

int method_2(int n)
{
    std::cout << "method_2(n)" << std::endl;
    int i = 0;

    int a = n, b = n;
    std::cout << "setp" << std::setfill('0') << std::setw(2)<< ++i << " "<< std::bitset<BITNUM>(0x55555555) << " "<< std::bitset<BITNUM>(0x55555555) << std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>(n)  << " "<< std::bitset<BITNUM>(a >> 1)<< std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>((n & (0x55555555)) + ((b >> 1) & (0x55555555))) << std::endl;
    n = (n & (0x55555555)) + ((n >> 1) & (0x55555555));

    a = n, b = n;
    std::cout << "setp" << std::setfill('0') << std::setw(2)<< ++i << " "<< std::bitset<BITNUM>(0x33333333) << " "<< std::bitset<BITNUM>(0x33333333) << std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>(n)  << " "<< std::bitset<BITNUM>(a >> 2)<< std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>((n & (0x33333333)) + ((b >> 2) & (0x33333333))) << std::endl;
    n = (n & (0x33333333)) + ((n >> 2) & (0x33333333));

    a = n, b = n;
    std::cout << "setp" << std::setfill('0') << std::setw(2)<< ++i << " "<< std::bitset<BITNUM>(0x0f0f0f0f) << " "<< std::bitset<BITNUM>(0x0f0f0f0f) << std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>(n)  << " "<< std::bitset<BITNUM>(a >> 4)<< std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>((n & (0x0f0f0f0f)) + ((b >> 4) & (0x0f0f0f0f))) << std::endl;
    n = (n & (0x0f0f0f0f)) + ((n >> 4) & (0x0f0f0f0f));

    a = n, b = n;
    std::cout << "setp" << std::setfill('0') << std::setw(2)<< ++i << " "<< std::bitset<BITNUM>(0x00ff00ff) << " "<< std::bitset<BITNUM>(0x00ff00ff) << std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>(n)  << " "<< std::bitset<BITNUM>(a >> 8)<< std::endl;
    std::cout <<"       "<< std::bitset<BITNUM>((n & (0x00ff00ff)) + ((b >> 8) & (0x00ff00ff))) << std::endl;
    n = (n & (0x00ff00ff)) + ((n >> 8) & (0x00ff00ff));

    n = (n & (0x0000ffff)) + ((n >> 16) & (0x0000ffff));

    return n;
}

int main()
{
    int n = 0b0100101100101010;
    // int n = 0b0000000000101010;

    std::cout << method_0(n) << std::endl;
    std::cout << method_1(n) << std::endl;
    std::cout << method_2(n) << std::endl;
    return 0;
}