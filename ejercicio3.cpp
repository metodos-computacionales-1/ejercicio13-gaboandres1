#include <iostream>
long fibonacciR(long n)
{
    if (n == 1)
        return 1;
    else if( n == 2)
        return 1;
    else
        return fibonacciR(n-1) + fibonacciR(n-2);
}
long fibonacciF(long n)
{
    long anterior1 = 1;
    long anterior2 = 1;
    long actual=0;
    for(int i=0; i<n-2; i++){
        actual = anterior1 + anterior2;
        anterior2 = anterior1;
        anterior1 = actual;
    }
    return actual;
}

int main(void)
{
    int number=50;
    std::cout<<"Recursivo para n="<<number<<": " <<fibonacciR(number)<<"\n";
    std::cout<<"No recursivo para n="<<number<<": " <<fibonacciF(number)<<"\n";
    return 0;
}