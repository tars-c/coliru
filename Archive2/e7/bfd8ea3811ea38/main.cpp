#include <string>
#include <cstdio>
#include <iostream>

std::string foo(const double f) { 
    char buf[6]; 
    sprintf(buf, "%.3f", f); 
    return buf; 
}

int main() {
    std::cout << foo(2.13456e+100);
}
