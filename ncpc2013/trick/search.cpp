#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const double eps = 1e-5;

int solutions(double X) {
    ll P = 1;
    int n = 0;
    bool empty = true;
    for (int k = 0; k < 8; ++k) {
        for (int d0 = 1; d0 < 10; ++d0) {
            ll A = d0*(P*10-1)/(10-X)+.5;
            if (A/P == d0 && abs((A-d0*P)*10+d0 - X*A) < eps) {
                ++n;
            }
        }
        P = P*10;
    }
    return n;
}

int main() {
    for (double X = 1; X < 10; X+=0.0001) {
        int res = solutions(X);
        if (res > 0)   
            cout << X << " " << res << endl;
    }

}
