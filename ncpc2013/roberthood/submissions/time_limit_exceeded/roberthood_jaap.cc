/*
 * Solution for NCPC 2013 problem "Archery" by Jaap Eldering
 * Complexity: O(n^2) naive algorithm
 */

#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long coord;

class point {
public:
	coord x, y;

	point() { x = y = 0; }
	point(coord x1, coord y1) { x = x1; y = y1; }

	point operator +=(point a) { x += a.x; y += a.y; return *this; }
	point operator -=(point a) { x -= a.x; y -= a.y; return *this; }
};

point operator +(point a, point b) { return a += b; }
point operator -(point a, point b) { return a -= b; }
coord operator *(point a, point b) { return a.x*b.x + a.y*b.y; }

coord lensqr(point a) { return a*a; }

int main()
{
	int nshots;
	cin >> nshots;

	if ( nshots<0 ) return -1;

	if ( nshots<2 ) {
		cout << -1 << endl;
		return 0;
	}

	vector<point> shots(nshots);
	for(int i=0; i<nshots; i++) cin >> shots[i].x >> shots[i].y;

	long long best = 0;

	for(int i=0; i<nshots; i++)
		for(int j=i+1; j<nshots; j++)
			best = max(best,lensqr(shots[j]-shots[i]));

    cout.precision(10);
	cout << sqrt(best) << endl;

	return 0;
}
