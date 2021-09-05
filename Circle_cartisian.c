// Circle_cartisian
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void Circle_cartisian(int xc,int yc,int r)
{
	int x,y;
	int f;

	for(y=(yc-r);y<=(yc+r);y++)
	{
		f=sqrt((r*r)-pow((y-yc),2));

		x=xc+f;
		putpixel(x,y,RED);
		x=xc-f;
		putpixel(x,y,RED);
	}

	for(x=(xc-r);x<=(xc+r);x++)
	{
		f=sqrt((r*r)-pow((x-xc),2));

		y=yc+f;
		putpixel(x,y,RED);
		y=yc-f;
		putpixel(x,y,RED);
	}
	
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	Circle_cartisian(100,100,50);
	getch();
	return 0;
}