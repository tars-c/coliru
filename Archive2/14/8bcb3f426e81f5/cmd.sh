set -x ; clang++ -std=c++1y -O3 -Wall -Wextra -pedantic-errors -pthread main.cpp && echo 1 5 6 0 > in.txt && ./a.out < in.txt