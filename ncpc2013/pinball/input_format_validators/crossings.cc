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
  pt d=s.a-r.a;
  double q=r.v^s.v;
  double qlambda=d^s.v;
  double qmu=d^r.v;
  if (q==0) {
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

typedef vector<segment> VS;

enum event_type {
  DELETE,ADD
};

struct event {
  pt p;
  event_type type;
  int s;
  event() {}
  event(const pt& p_, event_type type_, int s_) : p(p_), type(type_), s(s_) {}
};

bool operator < (const event& e, const event& f) {
  return f.p<e.p;
}
typedef priority_queue<event> PQ;

VS ramps;

struct cmpramp {
  bool operator () (int r_, int s_) const {
    const segment& r=ramps[r_];
    const segment& s=ramps[s_];
    if (s.a<r.a) return ! operator () (s_, r_);
    double rx=r.intersecty(s.a.y);
    return LT(rx,s.a.x);
  }
};
typedef set<int,cmpramp> SI;

/* Assumptions:
 * No crossing
 * No vertical segments
 */
int main() {
  int n;
  cin >> n;
  ramps=VS(n);
  FOR(i,0,n) cin >> ramps[i];
  PQ events;
  FOR(i,0,n) {
    events.push(event(ramps[i].a,ADD,i));
    events.push(event(ramps[i].b,DELETE,i));
  }
  double x0;
  cin >> x0;
  SI active;
  while(!events.empty()) {
    event e=events.top();events.pop();
    switch(e.type) {
    case ADD: {
      //cerr << "ADD " << e.p << endl;
      auto it = active.insert(e.s).first;
      if (it!=active.begin()) {
	it--;
	if (intersect(ramps[*it],ramps[e.s])) abort();
	it++;
      }
      it++;
      if (it!=active.end()) {
	if (intersect(ramps[*it],ramps[e.s])) abort();
      }
      break;
    }
    case DELETE: {
      active.erase(e.s);
      break;
    }
    }
  }
  exit(42);
}
