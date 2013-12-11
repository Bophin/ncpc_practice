#include <cstdio>
#include <cstdlib>
#include <cmath>

int n = 100000;

const double rad1 = 997;
const double rad2 = 999;

int main(int argc, char **argv)
{
	if ( argc>=2 ) n = atoi(argv[1]);

	printf("%d\n",n);

	double theta = 2*M_PI/n;
	for(int i=0; i<n; i++) {
		double r = (i%2 ? rad1 : rad2);
		int x = (int)floor(r*cos(i*theta));
		int y = (int)floor(r*sin(i*theta));
		printf("%d %d\n",x,y);
	}

	return 0;
}
