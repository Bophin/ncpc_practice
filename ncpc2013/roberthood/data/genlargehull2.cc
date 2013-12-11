#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

const int maxc = 1000;

int gcd(int a, int b) { return a==0 ? b : gcd(b%a,a); }

struct point {
	int x,y;
};

int operator <(point a, point b) { return a.x*b.y - a.y*b.x < 0; }

int main()
{
	set<point> dirs;

	point p;
	int d = 0;
	for(int l=2; l<=21; l++) {
		for(p.x=1; p.x<l; p.x++) {
			p.y = l-p.x;
			if ( gcd(p.x,p.y)==1 ) {
				dirs.insert(p);
				d += p.x;
			}
		}
//		fprintf(stderr,"l = %d: # = %d, d = %d\n",l,dirs.size(),d);
	}

	printf("%d\n",4*dirs.size());
	p.x = p.y = 0;
	for(set<point>::iterator it=dirs.begin(); it!=dirs.end(); ++it) {
		p.x += it->x;
		p.y += it->y;
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",
		       -maxc+p.x ,  p.y+1 ,
		       -maxc+p.x , -p.y   ,
		       +maxc-p.x ,  p.y+1 ,
		       +maxc-p.x , -p.y   );
	}

	return 0;
}
