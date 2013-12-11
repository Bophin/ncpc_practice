#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <limits>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

const double EPS=1e-6;
const double INF=numeric_limits<double>::infinity();

bool LT(double x, double y) { return y-x>EPS; }
bool LE(double x, double y) { return y-x>-EPS; }
bool EQ(double x, double y) { return abs(x-y)<EPS; }

struct pt {
  double x,y;
  pt() {}
  pt(double x_, double y_) : x(x_), y(y_) {}
  pt operator + (const pt& p) const { return pt(x+p.x,y+p.y); }
  pt operator - (const pt& p) const { return pt(x-p.x,y-p.y); }
  double operator * (const pt& v) const { return x*v.x + y*v.y; }
  double operator ^ (const pt& v) const { return x*v.y - y*v.x; }
};

bool operator < (const pt& p, const pt& q) {
  if (!EQ(p.y,q.y)) return p.y>q.y;
  return LT(p.x,q.x);
}

bool operator != (const pt& p, const pt& q) {
  return !(EQ(p.x,q.x) && EQ(p.y,q.y));
}

struct segment {
  pt a,b,v;
  double intersectx(double x) const {
    return a.y+(x-a.x)/v.x*v.y;
  }
  double intersecty(double y) const {
    return a.x+(y-a.y)/v.y*v.x;
  }
};

bool intersect(const segment& r, const segment& s) {
  double q=r.v^s.v;
  if (q<0) return intersect(s,r);
  pt d=s.a-r.a;
  double qlambda=d^s.v;
  double qmu=d^r.v;
  if (q==0) {
    return true;
    if (qlambda!=0 || qmu!=0) return false;
    qlambda=d*r.v;
    return qlambda>=0 && qlambda<=q;
  }
  return qlambda>=0 && qlambda<=q && qmu>=0 && qmu<=q;
}

istream& operator >> (istream& i, pt& p) { return i >> p.x >> p.y; }
istream& operator >> (istream& i, segment& s) {
  i >> s.a >> s.b;
  if (s.b<s.a) swap(s.a,s.b);
  s.v=s.b-s.a;
  return i;
}
ostream& operator << (ostream& o, const pt& p) { return o << p.x << ' ' << p.y; }
ostream& operator << (ostream& o, const segment& s) { return o << s.a << ' ' << s.b; }

typedef vector<segment> VS;

/* Assumptions:
 * No crossing
 * No vertical segments
 */
int main() {
  const int n=100000;
  cerr << RAND_MAX << endl;
  srand(4);
  VS segments,out;
  for (int i=0;i<n;++i) {
  nextchoice:
    segment s;
    //s.a = pt(rand()%20000-10000,i*10+rand()%1000);
    s.a = pt(rand()%20000-10000,i*10+rand()%1000-500000);
    s.v = pt(rand()%1000+1,rand()%1000+1);
    if (rand()&1) s.v.x*=-1;
    s.b=s.a+s.v;
    for (int j=i-1;j>=max(0,i-1500);--j) {
      //for (int j=i-1;j>=0;--j) {
      if (intersect(segments[j],s)) goto nextchoice;
    }
    //    if (abs(s.a.x)<1000 && abs(s.b.x)<1000)
      out.push_back(s);
    segments.push_back(s);
  }
  cout << out.size() << endl;
  for (int i=0;i<out.size();++i)
    cout << out[i] << endl;
  cout << 0 << endl;
}
