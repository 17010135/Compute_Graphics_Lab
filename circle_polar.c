// circle_polar
#include<stdio.h>
#include<graphics.h>
#include<math.h>


void circle_polar(int xc,int yc,int r)
{
	int x,y;
	double theta;

	for(int i=0;i<=360;i++)
	{
		theta=(3.14*i)/180;
		x=xc+(r*cos(theta));
		y=yc+(r*sin(theta));
		putpixel(x,y,RED);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	circle_polar(100,100,50);
	getch();
	return 0;
}