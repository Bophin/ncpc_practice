#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct point {
	int x,y;
};

const int rad = 90;

int main()
{
	int n;

	cin >> n;
	vector<point> all(n);
	for(int i=0; i<n; i++) cin >> all[i].x >> all[i].y;

	cin >> n;
	vector<point> hull(n);
	for(int i=0; i<n; i++) cin >> hull[i].x >> hull[i].y;

	printf("\
#FIG 3.2  Produced by xfig version 3.2.5b\n\
Landscape\n\
Center\n\
Metric\n\
A4      \n\
100.00\n\
Single\n\
-2\n\
1200 2\n\
");

	printf("2 3 0 1 0 7 50 -1 -1 0.000 0 0 -1 0 0 %d\n\t",hull.size()+1);
	for(int i=0; i<hull.size(); i++) printf(" %d %d",hull[i].x,hull[i].y);
	printf(" %d %d\n",hull[0].x,hull[0].y);

	for(int i=0; i<all.size(); i++) {
		printf("1 3 0 1 0 0 50 -1 20 0.000 1 0.0000 %d %d %d %d %d %d %d %d\n",
		       all[i].x,all[i].y,rad,rad,all[i].x,all[i].y,all[i].x+rad,all[i].y);
	}

	return 0;
}
