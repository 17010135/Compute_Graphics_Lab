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
		delay(5);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");

	DDA(100,100,100,250);
	DDA(500,100,500,250);
	DDA(100,100,500,100);
	DDA(100,250,500,250);

	DDA(60,100,100,100);
	DDA(100,50,60,100);

	DDA(500,100,540,100);
	DDA(570,50,540,100);
	DDA(100,50,570,50);

	DDA(150,150,150,250);
	DDA(200,150,200,250);

	DDA(150,150,200,150);
	DDA(175,150,175,250);

	DDA(150,170,200,170);
	DDA(150,190,200,190);
	DDA(150,210,200,210);
	DDA(150,230,200,230);

	DDA(400,150,450,150);
	DDA(400,190,450,190);
	DDA(400,170,450,170);
	DDA(425,150,425,190);
	DDA(400,150,400,190);
	DDA(450,150,450,190);








	getch();
	return 0;

}