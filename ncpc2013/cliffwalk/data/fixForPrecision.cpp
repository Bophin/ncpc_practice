// Solution by Fredrik Svensson
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

#define MAX_H 400
#define MAX_W 400
const int maxClimb = 1000; // 1 meter.
const double dryingPeriod = 1; // One hour.
const double pi = 3.1415926535897932384626433832795;

struct pos
{
	int x, y;
	double t;

	pos()
	{
	}
	pos(int x, int y, double time) :
		x(x), y(y), t(time)
	{
	}

	bool operator>(const pos &rhs) const
	{
		return (this->t > rhs.t);
	}
};

double a, m;
int w, h;
int mapZ[MAX_H][MAX_W];
double dryTime[MAX_H][MAX_W]; // The time when the rock is dry.
double enterTime[MAX_H][MAX_W]; // The earliest time when Charlotte reaches the rock.

double wetTime[MAX_H][MAX_W]; // The time when the tide makes the rock wet. Encoded 12-t.
double leaveTime[MAX_H][MAX_W]; // The latest time Charlotte can leave the rock. Encoded 12-t.

const int dxs[] = {1,-1,0,0};
const int dys[] = {0,0,1,-1};

void shortestPath(const pos &start, double (&charlotteTimeMap)[MAX_H][MAX_W], const double (&minTimeMap)[MAX_H][MAX_W])
{
	priority_queue<pos, std::vector<pos>, std::greater<pos> > pq;
	pq.push(start);
	while (!pq.empty())
	{
		pos p = pq.top();
		pq.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = p.x + dxs[i];
			int y = p.y + dys[i];
			if (x < 0 || x >= w || y < 0 || y >= h)
				continue;
			int zDiff = mapZ[p.y][p.x] - mapZ[y][x];
			if (abs(zDiff) > maxClimb)
				continue;
			double nextTime = max(p.t, minTimeMap[y][x]) + m;
			if (nextTime < charlotteTimeMap[y][x])
			{
				charlotteTimeMap[y][x] = nextTime;
				pq.push(pos(x,y,nextTime));
			}
		}
	}
}

double calcDist(int dx, int dy)
{
	return sqrt((double)(dx*dx + dy*dy));
}

int main()
{
	cin >> a >> m;
	cout << a << ' ' << m << endl;
	a *= 1000.0;
	m /= 3600.0;
	pos start(0, 0, 0.0);
	cin >> w >> h >> start.x >> start.y;
	cout << w << ' ' << h << ' ' << start.x << ' ' << start.y << endl;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			int z;
			cin >> z;
			mapZ[y][x] = z;
			if (z <= a)
				wetTime[y][x] = acos((2.0*z)/a-1)*6/pi;
			else
				wetTime[y][x] = -2;
			dryTime[y][x] = wetTime[y][x] + dryingPeriod;

		}
	}
	double rets[2];
	m += 1.1/3600.0;
	for (int i = 0; i < 2; ++i)
	{
		for (int y = 0; y < h; ++y)
		{
			for (int x = 0; x < w; ++x)
			{
				enterTime[y][x] = 12;
				leaveTime[y][x] = 12-0;
			}
		}
		enterTime[start.y][start.x] = 0;
		leaveTime[start.y][start.x] = 0;

		shortestPath(start, enterTime, dryTime);
		shortestPath(start, leaveTime, wetTime);

		double ret = 0;
		pos end;
		for (int y = 0; y < h; ++y)
		{
			for (int x = 0; x < w; ++x)
			{
				if (enterTime[y][x] <= 12-leaveTime[y][x])
				{
					const double dist = calcDist(x - start.x, y - start.y);
					if (dist > ret)
					{
						if (i == 1 && dist > rets[0])
							mapZ[y][x] /= 10;
						else
							ret = dist;
						end.x = x;
						end.y = y;
					}
				}
				if (i == 1)
				{
					if (x != 0)
						cout << ' ';
					cout << mapZ[y][x];
				}
			}
			if (i == 1)
				cout << endl;
		}
		// cout << 10*ret << " (" << end.x << ',' << end.y << ')' << endl;
		rets[i] = ret;
		m -= 2.2/3600.0;
		if (m < 0)
			m = 0;
	}
	// assert(rets[0] == rets[1]);
	return 42;
}
