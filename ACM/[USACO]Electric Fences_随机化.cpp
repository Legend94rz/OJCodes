/*
ID: rz109291
PROG: fence3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;

int X1[200], Y1[200], X2[200], Y2[200];
int F;
const int IT = 300;
double dx[] = { -0.1, 0, 0.1, 0 };
double dy[] = { 0, -0.1, 0, 0.1 };

double ansX, ansY, optD=999999.0;
int earlyStop;

double dist(double x, double y)
{
	double s = 0;
	for (int i = 1; i <= F; i++)
	{
		double d1 = sqrt(pow(x - X1[i], 2) + pow(y - Y1[i], 2));
		double d2 = sqrt(pow(x - X2[i], 2) + pow(y - Y2[i], 2));
		double dist = min(d1, d2);

		if (X1[i] == X2[i] && y >= Y1[i] && y <= Y2[i])
			dist = min(dist, abs(x - X1[i]));

		if (Y1[i] == Y2[i] && x >= X1[i] && x <= X2[i])
			dist = min(dist, abs(y - Y1[i]));
		s += dist;
	}
	return s;
}

int main()
{
	freopen("fence3.in", "r", stdin); freopen("fence3.out", "w", stdout);
	srand(time(NULL));

	cin >> F;
	for (int i = 1; i <= F; i++)
	{
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
		if (X1[i] == X2[i] && Y1[i] > Y2[i])
		{
			int t = Y1[i]; Y1[i] = Y2[i]; Y2[i] = t;
		}
		if (Y1[i] == Y2[i] && X1[i] > X2[i])
		{
			int t = X1[i]; X1[i] = X2[i]; X2[i] = t;
		}
	}


	for (int i = 0; i < IT && earlyStop<50; i++)
	{
		double x = rand() % 100;
		double y = rand() % 100;
		double D = 0;
		for (;;)
		{
			D = dist(x, y);
			double delta = 0;
			int J = -1;
			for (int j = 0; j < 4; j++)
			{
				double t = dist(x + dx[j], y + dy[j]);
				if (D - t > delta)
				{
					J = j;
					delta = D - t;
				}
			}
			if (J <= 0) break;
			x = x + dx[J]; y = y + dy[J];
		}
		if (D < optD)
		{
			optD = D;
			ansX = x;
			ansY = y;
			earlyStop = 0;
		}
		else
		{
			earlyStop++;
		}
	}
	
	printf("%.1lf %.1lf %.1lf\n", ansX, ansY, optD);

	fclose(stdin); fclose(stdout);
}