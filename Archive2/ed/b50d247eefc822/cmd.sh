echo 'void f(char const* c);' > f.c && mv main.cpp main.c && gcc f.c main.c && ./a.out