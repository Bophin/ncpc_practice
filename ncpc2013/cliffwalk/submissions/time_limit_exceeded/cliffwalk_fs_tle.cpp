// Solution by Fredrik Svensson
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_H 200
#define MAX_W 200
const int maxClimb = 1000; // 1 meter.
const double dryingPeriod = 1; // One hour.
const double pi = 3.1415926535897932384626433832795;

struct pos
{
	int x, y;

	pos()
	{
	}
	pos(int x, int y) :
		x(x), y(y)
	{
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
	static bool visited[MAX_H][MAX_W];
	for (int y = 0; y < h; ++y)
		for (int x = 0; x < w; ++x)
			visited[y][x] = false;
	charlotteTimeMap[start.y][start.x] = 0;
	for (;;)
	{
		// Find point with smallest time.
		pos p(-1, -1);
		double t = 123;
		for (int y = 0; y < h; ++y)
		{
			for (int x = 0; x < w; ++x)
			{
				if (!visited[y][x] && charlotteTimeMap[y][x] < t)
				{
					t = charlotteTimeMap[y][x];
					p.x = x;
					p.y = y;
				}
			}
		}
		if (p.x == -1)
			break;
		visited[p.y][p.x] = true;
		for (int i = 0; i < 4; ++i)
		{
			int x = p.x + dxs[i];
			int y = p.y + dys[i];
			if (x < 0 || x >= w || y < 0 || y >= h)
				continue;
			int zDiff = mapZ[p.y][p.x] - mapZ[y][x];
			if (abs(zDiff) > maxClimb)
				continue;
			double nextTime = max(t, minTimeMap[y][x]) + m;
			if (nextTime < charlotteTimeMap[y][x])
			{
				charlotteTimeMap[y][x] = nextTime;
			}
		}
	}
}

double calcDist(int dx, int dy)
{
	return sqrt((double)dx*dx + dy*dy);
}

int main()
{
	cin >> a >> m;
	a *= 1000.0;
	m /= 3600.0;
	pos start(0, 0);
	cin >> w >> h >> start.x >> start.y;
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

			enterTime[y][x] = 12;
			leaveTime[y][x] = 12-0;
		}
	}
	enterTime[start.y][start.x] = 0;
	leaveTime[start.y][start.x] = 0;

	shortestPath(start, enterTime, dryTime);
	shortestPath(start, leaveTime, wetTime);

	double ret = 0;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (enterTime[y][x] <= 12-leaveTime[y][x])
			{
				const double dist = calcDist(x - start.x, y - start.y);
				if (dist > ret)
					ret = dist;
			}
		}
	}
    cout.precision(10);
	cout << 10*ret << endl;
	return 0;
}
