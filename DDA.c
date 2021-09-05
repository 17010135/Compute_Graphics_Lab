// DDA
#include<stdio.h>
#include<graphics.h>
#include<math.h>

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
		delay(50);
	}
}

int main()
{

	int gd = DETECT,gm;
	initgraph(&gd,&gm," ");

	DDA(50,80,40,150);

	getch();
	return 0;
}