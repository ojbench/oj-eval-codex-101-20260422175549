#include <bits/stdc++.h>
using namespace std;

// Compute the smallest s >= 0 such that after s seconds,
// hour, minute, and second values are equal in bases a, b, c.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d, e, f;
    if (!(cin >> a >> b >> c >> d >> e >> f)) return 0;

    long long T = a * b * c;            // seconds per day
    long long S0 = f * b * a + e * a + d; // current seconds from day start

    long long limit = min(a, min(b, c));
    long long best = LLONG_MAX;

    // Derived: S ≡ (a*b + a + 1) * x (mod T) for some x in [0, min(a,b,c)-1]
    long long coef = ((a * b) % T + a + 1) % T;

    long long S0m = S0 % T;
    for (long long x = 0; x < limit; ++x) {
        long long target = (coef * (x % T)) % T;
        long long s = (target - S0m + T) % T;
        if (s < best) best = s;
        if (best == 0) break;
    }

    cout << best << '\n';
    return 0;
}
