// Bresenham
#include<stdio.h>
#include<graphics.h>

void Bresenham(int xa,int ya,int xb,int yb)
{
	int dx=abs(xb-xa);
	int dy=abs(yb-ya);
	int p=2*dy-dx;
	int twoDy=2*dy;
	int twoDyDx=2*(dy-dx);
	int x,y,xend;

	if(xa>xb)
	{
		xend=xa;
		x=xb;
		y=yb;
	}
	else
	{
		xend=xb;
		x=xa;
		y=ya;
	}
	putpixel(x,y,RED);
	while(x<xend)
	{
		x++;
		if(p<0)
		{
			p=p+twoDy;
		}
		else
		{
			p=p+twoDyDx;
			y++;
		}
		putpixel(x,y,RED);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");

	Bresenham(50,80,40,150);
	getch();
	return 0;
}