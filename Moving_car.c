// Moving_car

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

	for(int k=0;k<=100;k=k+2)
	{



	DDA(100+k,100,200+k,100);
	DDA(100+k,100,50+k,130);
	DDA(200+k,100,250+k,130);

	DDA(20+k,130,50+k,130);
	DDA(250+k,130,280+k,130);

	DDA(20+k,130,20+k,170);
	DDA(280+k,130,280+k,170);

	DDA(20+k,170,70+k,170);
	DDA(230+k,170,280+k,170);

	DDA(120+k,170,180+k,170);





	circle_pol(95+k,170,20);
	circle_pol(205+k,170,20);
	circle_pol_half(95+k,170,25);
	circle_pol_half(205+k,170,25);


	for(int i=0;i<=360;i=i+30)
	{
		double theta=(3.14*i)/180;
		int x=95+(20*cos(theta));
		int y=170+(20*sin(theta));

		DDA(95+k,170,x+k,y);

	}
	for(int i=0;i<=360;i=i+30)
	{
		double theta=(3.14*i)/180;
		int x=205+(20*cos(theta));
		int y=170+(20*sin(theta));

		DDA(205+k,170,x+k,y);
		
	}
	flood_fill(100+k,105,15,0);
	delay(5);

	cleardevice();

}


	getch();
	return 0;
}

