#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <limits>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

const double INF=numeric_limits<double>::infinity();
const double EPS=1e-6;

bool LT(double x, double y) { return y-x>EPS; }
bool LE(double x, double y) { return x-y<EPS; }
bool EQ(double x, double y) { return abs(x-y)<EPS; }

struct pt {
  double x,y;
  pt() {}
  pt(double x_, double y_) : x(x_), y(y_) {}
  pt operator - (const pt& p) const { return pt(x-p.x,y-p.y); }
};

bool operator < (const pt& p, const pt& q) {
  if (!EQ(p.y,q.y)) return p.y>q.y;
  return LT(p.x,q.x);
}

bool operator <= (const pt& p, const pt& q) {
  if (!EQ(p.y,q.y)) return p.y>q.y;
  return LE(p.x,q.x);
}

struct segment {
  pt a,b,v;
  double intersectx(double x) const {
    return a.y+(x-a.x)/v.x*v.y;
  }
};

istream& operator >> (istream& i, pt& p) { return i >> p.x >> p.y; }
istream& operator >> (istream& i, segment& s) {
  i >> s.a >> s.b;
  if (s.b<s.a) swap(s.a,s.b);
  s.v=s.b-s.a;
  return i;
}
ostream& operator << (ostream& o, const pt& p) { return o << p.x << ' ' << p.y; }

typedef vector<pt> VP;
typedef vector<segment> VS;

VS ramps;
#ifdef VISUAL_DEBUG
VP ballmoves;
#endif

/* Assumptions:
 * No crossing
 * No vertical segments
 */
int main() {
  int n;
  cin >> n;
  ramps=VS(n);
  FOR(i,0,n) cin >> ramps[i];
  pt ball;
  cin >> ball.x;
  ball.y=INF;
#ifdef VISUAL_DEBUG
  ballmoves.push_back(pt(ball.x,2));
#endif
  while(true) {
    int imax=-1;
    pt ymax(ball.x,-INF);
    FOR (i,0,n) {
      pt x(ball.x,ramps[i].intersectx(ball.x));
      if (ball < x && x < ymax && ramps[i].a <= x && x <= ramps[i].b) {
	ymax=x;
	imax=i;
      }
    }
    if (imax>=0) {
      ball=ramps[imax].b;
#ifdef VISUAL_DEBUG
      ballmoves.push_back(ymax);
      ballmoves.push_back(ball);
#endif
    }
    else break;
  }
#ifdef VISUAL_DEBUG
  ballmoves.push_back(pt(ball.x,-4));
  for (int i=0;i<n;++i) {
    const segment& s=ramps[i];
    printf("draw((%f,%f)*20--(%f,%f)*20,black*1.5);\n",s.a.x,s.a.y,s.b.x,s.b.y);
  }
  for (int i=1;i<ballmoves.size();++i) {
    const pt& a=ballmoves[i-1];
    const pt& b=ballmoves[i];
    printf("draw((%f,%f)*20--(%f,%f)*20,red+opacity(.5)+2);\n",a.x,a.y,b.x,b.y);
  }
#else
  printf("%.0f\n",ball.x);
#endif
}
