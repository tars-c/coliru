g++-4.8 -std=c++11 -O2 -Wall -Wno-parentheses -pedantic -pthread main.cpp && ls -la --time-style=long-iso | ./a.out -s 1 -l 1 -f  "mod|links|group|user|size|date:2|name"