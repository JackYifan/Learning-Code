#include<iostream>
#define JH(a,b,t) t = a; a = b; b = t
int main()
{
    double  x=1.2423;
    int y=234;
    float z=2.34;
    JH(x,y,z);
    std::cout<<x<<" "<<y<<" "<<z;
}