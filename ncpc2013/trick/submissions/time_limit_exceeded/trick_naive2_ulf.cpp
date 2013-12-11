#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

const double eps = 1e-5;

int main() {
    double X;
    scanf("%lf",&X);
    ll P = 1;
    bool empty = true;
    for (ll A = 1; A < 100000000; ++A) {
        if (A >= P*10)
            P *= 10;
        ll d0 = A/P;
        if (abs((A-d0*P)*10+d0 - A*X) < eps) {
            printf("%d\n",A);
            empty = false;
        }
    }
    if (empty)
        puts("No solution");
}