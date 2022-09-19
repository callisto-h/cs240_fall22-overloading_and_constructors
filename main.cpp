#include "Sample.h"
#include <iostream>

int main(){
    /**
     * QUESTION:
     * 0. Which constructors/functions are being called on
     * the below lines?
     *
     */
    Sample a;
    Sample b(1);
    Sample c(a);
    Sample d = b;
    Sample e;
    e = b;

    /**
     * NOTE:
     * Even though some of the above objects are
     * copies of each other, note that the memory addresses
     * that their val_ptr pointers point to are all different
     */

    std::cout << "====== SAMPLES ======" << std::endl;

    std::cout << "Sample a:" << std::endl;
    std::cout << a << std::endl;
    std::cout << "Sample b:" << std::endl;
    std::cout << b << std::endl;
    std::cout << "Sample c:" << std::endl;
    std::cout << c << std::endl;
    std::cout << "Sample d:" << std::endl;
    std::cout << d << std::endl;
    std::cout << "Sample e:" << std::endl;
    std::cout << e << std::endl;

    std::cout << "====== INPUT DATA ======" << std::endl;

    std::cout << "Write to Sample a :";
    std::cin >> a;
    std::cout << "Write to Sample b :";
    std::cin >> b;
    std::cout << "Write to Sample c :";
    std::cin >> c;
    std::cout << "Write to Sample d :";
    std::cin >> d;
    std::cout << "Write to Sample e :";
    std::cin >> e;

    std::cout << "====== SAMPLES ======" << std::endl;

    std::cout << "Sample a:" << std::endl;
    std::cout << a << std::endl;
    std::cout << "Sample b:" << std::endl;
    std::cout << b << std::endl;
    std::cout << "Sample c:" << std::endl;
    std::cout << c << std::endl;
    std::cout << "Sample d:" << std::endl;
    std::cout << d << std::endl;
    std::cout << "Sample e:" << std::endl;
    std::cout << e << std::endl;

    return 0;
}
