// Moving_kites
#include<stdio.h>
#include<graphics.h>

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
		//delay(5);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");

	DDA(150,100,100,150);
	DDA(150,100,200,150);
	DDA(100,150,200,150);

	DDA(150,100,150,150);
	
	DDA(100,150,160,250);
	DDA(200,150,140,250);
	DDA(140,250,160,250);

	DDA(150,150,300,300);

	delay(100);
	cleardevice();

	for(int i=0;i<=100;i++)
	{
		int a=rand()%50;
		int b=rand()%50;

	DDA(150+a,100+b,100+a,150+b);
	DDA(150+a,100+b,200+a,150+b);
	DDA(100+a,150+b,200+a,150+b);

	DDA(150+a,100+b,150+a,150+b);
	
	DDA(100+a,150+b,160+a,250+b);
	DDA(200+a,150+b,140+a,250+b);
	DDA(140+a,250+b,160+a,250+b);

	DDA(150+a,150+b,300+a,300+b);
	delay(100);
	cleardevice();
	}

	getch();
	return 0;
}