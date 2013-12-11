#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const double eps = 1e-5;

int main() {
    double X;
    cin >> X;
    ll P = 1;
    bool empty = true;
    for (ll A = 1; A < 100000000; ++A) {
        ll d0 = A, P = 1;
        while (d0>9) d0/=10, P*=10;
        ll B = (A-d0*P)*10+d0;
        if (abs(B - A*X) < eps) {
            cout << A << endl;
            empty = false;
        }
    }
    if (empty)
        cout << "No solution" << endl;
}