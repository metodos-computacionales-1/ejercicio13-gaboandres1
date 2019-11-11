#include <iostream>
int subtraction(int a, int b)
{
    int r;
    std::cout << "La variable local r está en la dirección de memoria: "<< &r << std::endl;
    r=a-b;
    return r;
}

int main(void)
{
    int x=5,y=3,z;
    z=subtraction(7,2);
    std::cout<< "The first result is " <<z<<"\n";
    std::cout<< "x está en la dirección de memoria: " <<&x<<"\n";
    std::cout<< "y está en la dirección de memoria: " <<&y<<"\n";
    std::cout<< "z está en la dirección de memoria: " <<&z<<"\n";
    
    subtraction(7,2);
    subtraction(x,y);
    z=4+subtraction(x,y);
    std::cout<< "The fourth result is " <<z<<"\n";
    std::cout<< "z is in memory adress: " <<&z<<"\n";

    return 0;
}