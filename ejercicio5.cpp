#include <iostream>
#include <cmath>
int main(int argc, char **argv)
{
    int N=atoi(argv[1]); //casting to int
    double *array = new double[N];
    for(int i =0;i<N;i++)
    {
        array[i]=i;
    }
    delete[] array;
    std::cout<<"Terminado"<<std::endl;
    return 0;
}