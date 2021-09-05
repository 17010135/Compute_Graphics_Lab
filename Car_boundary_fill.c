// Car_boundary_fill

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
		//delay(5);
	}
}

void circle_pol(int xc,int yc,int r)
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

void circle_pol_half(int xc,int yc,int r)
{
	int x,y;
	double theta;

	for(int i=180;i<=360;i++)
	{
		theta=(3.14*i)/180;

		x=xc+(r*cos(theta));
		y=yc+(r*sin(theta));
		putpixel(x,y,RED);
	}
}

void Car_boundary_fill(int x,int y,int fill, int boundary)
{
	int current;
	current=getpixel(x,y);
	if(current!=fill && current!=boundary)
	{
		putpixel(x,y,fill);

		Car_boundary_fill(x+1,y,fill,boundary);
		Car_boundary_fill(x-1,y,fill,boundary);
		Car_boundary_fill(x,y+1,fill,boundary);
		Car_boundary_fill(x,y-1,fill,boundary);
	}
}

void flood_fill(int x,int y,int fill,int old_col)
{
	int current;
	current=getpixel(x,y);
	if(current==old_col)
	{
		putpixel(x,y,fill);
		flood_fill(x+1,y,fill,old_col);
		flood_fill(x-1,y,fill,old_col);
		flood_fill(x,y+1,fill,old_col);
		flood_fill(x,y-1,fill,old_col);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");

	for(int i=0;i<=100;i++)
	{



	DDA(100+i,100,200+i,100);
	DDA(100+i,100,50+i,130);
	DDA(200+i,100,250+i,130);

	DDA(20+i,130,50+i,130);
	DDA(250+i,130,280+i,130);

	DDA(20+i,130,20+i,170);
	DDA(280+i,130,280+i,170);

	DDA(20+i,170,70+i,170);
	DDA(230+i,170,280+i,170);

	DDA(120+i,170,180+i,170);

	circle_pol(95+i,170,20);
	circle_pol(205+i,170,20);
	circle_pol_half(95+i,170,25);
	circle_pol_half(205+i,170,25);

	// Car_boundary_fill(95+i,170,4,15);
	// Car_boundary_fill(205+i,170,4,15);

	flood_fill(100+i,130,10,0);


	//delay(10);
	cleardevice();

}

	getch();
	return 0;


}
