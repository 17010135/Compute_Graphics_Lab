// Rotating_wheel
#include<stdio.h>
#include<graphics.h>
#include<math.h>


void Rotating_wheel(int xc,int yc,int r)
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

void DDA(int xa,int ya,int xb,int yb)
{
	int dx=xb-xa;
	int dy=yb-ya;
	int step,k;
	float xincrement,yincrement,x=xa,y=ya;

	if(abs(dx)>abs(dy))
	{
		step=abs(dx);

	}
	else
	{
		step=abs(dy);
	}

	xincrement=dx/(float)step;
	yincrement=dy/(float)step;
	putpixel(x,y,RED);

	for(k=0;k<step;k++)
	{
		x=x+xincrement;
		y=y+yincrement;
		putpixel(x,y,RED);
		//delay(10);
	}





}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");

	for(int i=0;i<100;i++)
	{



	Rotating_wheel(100+i,100,50);
	Rotating_wheel(100+i,100,60);

	for(int j=0;j<=360;j=j+30)
	{
		double theta=(3.14*j)/180;

		int x=100+(50*cos(theta));
		int y=100+(50*sin(theta));
		DDA(100+i,100,x+i,y);


	}
	delay(10);
	cleardevice();
}

	getch();
	return 0;
}