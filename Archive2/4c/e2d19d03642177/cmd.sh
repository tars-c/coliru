clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -pedantic-errors -O3 -Wno-unused main.cpp -lsupc++ -o test && ./test && echo ok