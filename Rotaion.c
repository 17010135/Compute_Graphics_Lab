// Rotaion
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
		delay(5);
	}
}


int main()  
{  

	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");

    int x1,y1,x2,y2,x3,y3;  
    double s,c, angle;  
    
    DDA(150,100,100,150);
	DDA(100,150,200,150);
	DDA(200,150,150,100);

    angle=30;
    c = cos(angle *M_PI/180);  
    s = sin(angle *M_PI/180);  
    x1 = floor(150 * c + 100 * s);  
    y1 = floor(-150 * s + 100 * c);  
    x2 = floor(100 * c + 150 * s);  
    y2 = floor(-100 * s + 150 * c);  
    x3 = floor(200 * c + 150 * s);  
    y3 = floor(-200 * s + 150* c);  
    delay(10);
    cleardevice();  
    DDA(x1, y1 ,x2, y2);  
    DDA(x2,y2, x3,y3);  
    DDA(x3, y3, x1, y1);  
    getch();  
    
    return 0;  
}  
