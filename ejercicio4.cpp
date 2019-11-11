#include <iostream>

int getMax(int i, int j)
{
    std::cout << "El número mayor entre "<<i<<" y "<<j<< " es ";
    if(i<j){
        std::cout<<j<<std::endl;
        return j;
    }
    else{
        std::cout<<i<<std::endl;
        return i;
    }
}
double getMax(double i, double j)
{
    std::cout << "El número mayor entre "<<i<<" y "<<j<< " es ";
    if(i<j){
        std::cout<<j<<std::endl;
        return j;
    }
    else{
        std::cout<<i<<std::endl;
        return i;
    }
}



int main(void)
{
    double i=45676545.01;
    double j= 56788765.405;
    int a=1;
    int b=-1;
    getMax(a,b);
    getMax(i,j);
    
    return 0;
}