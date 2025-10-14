#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXINTV 15

double dl(double);
double df(double);
void calc(double f, double wd, double wr, double r, double t, double nw);

main()
{
	double f;
	double wd;
	double wr;
	double r;
	double t;
	double nw;

	printf("frequency [MHz]:\n");
	scanf("%lf", &f);
	printf("wire diameter [mm]:\n");
	scanf("%lf", &wd);
	printf("wire radius [mm]:\n");
	scanf("%lf", &wr);
	printf("ratio:\n");
	scanf("%lf", &r);
	printf("turns:\n");
	scanf("%lf", &t);
	printf("number of wavelengths:\n");
	scanf("%lf", &nw);

	calc(f, wd, wr, r, t, nw);
	return 0;
}

double dl(double diam)
{
	double tab[] = {
		1.045, 1.053, 1.060, 1.064, 1.068, 1.070, 1.070, 1.071,
		1.071, 1.070, 1.070, 1.070, 1.070, 1.069, 1.069, 1.068, 1.067
	};

	int i = (int)diam;
	if (i < 0)
		i = 0;
	if (i >= MAXINTV+1)
		i = MAXINTV;
	return tab[i] + (tab[i + 1] - tab[i]) * (diam - i);
}

/* temporary solution */
double df(double diam)
{
	double tab[] = {
		1.013, 1.014, 1.015, 1.016, 1.017, 1.018, 1.020, 1.022,
		1.025, 1.027, 1.030, 1.033, 1.036, 1.041, 1.044, 1.049, 1.054
	};

	int i = (int)diam;
	if (i < 0)
		i = 0;
	if (i >= MAXINTV+1)
		i = MAXINTV;
	return tab[i] + (tab[i + 1] - tab[i]) * (diam - i);
}

void calc(double f, double wd, double wr, double r, double t, double nw)
{
	double wl = 300000.0 / f;
	double wdeff = (wd > MAXINTV) ? MAXINTV : wd;
	double wlc = wl * dl(wdeff);
	double bc = 2 * wr - M_PI * wr / 2.0;
	double od = 0.0088 * wlc;

