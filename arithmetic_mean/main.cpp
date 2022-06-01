#include <iostream>

template < typename T >

void input( T (&array)[8])
{
    T elem;
    std::cout << "Fill the array (8):"<<std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout<<"input "<<i+1<<" elem: "<<std::endl;
        std::cin>>elem;
        array[i]=elem;
    }
}

template < typename T >
void output(const T array[8])
{
    T sum=0;
    for (int i = 0; i < 8; ++i)
    {
    sum+=array[i];
    }
    std::cout<<"Arithmetic mean is: "<<sum/8;

}

int main() {
    double arr[8];
    input(arr);
    output(arr);

    return 0;
}
