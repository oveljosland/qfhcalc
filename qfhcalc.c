#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


	
	
	
