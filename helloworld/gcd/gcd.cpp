#include <iostream>

template<int a, int b>
struct gcd {
	inline static constexpr int value = gcd<b, a%b>::value;
};

//partial specialization
template<int a>
struct gcd<a, 0> {
	inline static constexpr int value = a;
};

int main()
{
  	static_assert(gcd<5, 15>::value == 5);
    return 0;
}