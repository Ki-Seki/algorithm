#include <iostream>

typedef long long LL;

// calculate a ^ b % c
LL fastPowerRecursion(LL a, LL b, LL c)
{
    if (a == 0 || c == 1) return 0;  // special judge
    if (b == 0) return 1;  // recursive boundary
    a %= c;  // optimization
    if (b & 1)  // if b is even
        return a * fastPowerRecursion(a, b - 1, c) % c;
    else
    {
        LL tmp = fastPowerRecursion(a, b / 2, c);
        return tmp * tmp % c;
    }
}

// calculate a ^ b % c
// example: 99^6 == 99^2 * 99^4
LL fastPowerIteration(LL a, LL b, LL c)
{
    if (a == 0 || c == 1) return 0;  // special judge
    a %= c;
    LL ans = 1;
    while (b > 0)
    {
        if (b & 1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}

int main()
{
    printf("%lld, %lld", fastPowerRecursion(55, 100, 450), fastPowerIteration(55, 100, 450));
    return 0;
}