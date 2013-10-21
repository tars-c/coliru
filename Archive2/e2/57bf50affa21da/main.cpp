#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

void readfile(const char *inputfile) {
    std::ifstream is(inputfile);
    std::istreambuf_iterator<char> f(is), l;
    std::vector<char> buf(f, l);

    std::cout.write(buf.data(), buf.size());
}

int main()
{
    readfile("main.cpp");
}
