#include <type_traits>

enum class enabler {};

template <typename T>
using EnableIf = typename std::enable_if<T::value, enabler>::type;

template <typename T>
using DisableIf = typename std::enable_if<!T::value, enabler>::type;

template <typename T,
          EnableIf<std::is_integral<T>>...>
void f(T) {}

template <typename T,
          DisableIf<std::is_integral<T>>...>
void f(T);

int main() {
    f(0);
}
