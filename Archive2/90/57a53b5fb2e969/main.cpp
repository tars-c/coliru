#include <iostream>
#include <dlfcn.h>

void* handle;

void say(int a) {
    typedef void(*func_sig)(int);
    dlerror();
    static func_sig func = (func_sig) dlsym(handle, __FUNCDNAME__);
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "dlsym error: " << dlsym_error << '\n';
        dlclose(handle);
        exit(1);
    }
    return func(a);
}

void say(float a) {
    typedef void(*func_sig)(float);
    dlerror();
    static func_sig func = (func_sig) dlsym(handle, __FUNCDNAME__);
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "dlsym error: " << dlsym_error << '\n';
        dlclose(handle);
        exit(1);
    }
    return func(a);
}

int main() {
    // open library
    //void* handle = dlopen("./say_externC.so", RTLD_LAZY);
    handle = dlopen("./say.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "dlopen error: " << dlerror() << '\n';
        return 1;
    }

    // use function
    int myint = 3;
    say(myint);
    float myfloat = 5.0f;
    say(myfloat);

    // close library
    dlclose(handle);
}