// Scaling
//scaling
#include<stdio.h>
#include<graphics.h>


void lineDDA(int Xa,int Ya,int Xb,int Yb) 
{ 
int steps;
int dx = Xb-Xa; 
int dy = Yb-Ya; 
if(abs(dx)>abs(dy))
{
steps=abs(dx);
}
else
{
steps=abs(dy);
}

float Xinc=dx/(float)steps; 
float Yinc=dy/(float)steps; 

float X=Xa; 
float Y=Ya; 
for (int i=0;i<=steps;i++) 
{ 
   putpixel (X,Y,RED);  
   X=X+Xinc;		 
   Y=Y+Yinc;		 
   delay(10);		 
						 
} 
} 

void findnewcoordinate(int s[][2],int p[][1])
{
	int c[2][1]={0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<1;j++)
		{
			
			for(int k=0;k<2;k++)
			{
				c[i][j]=c[i][j]+s[i][k]*p[k][j];
			}
		}

	}
	p[0][0]=c[0][0];
	p[1][0]=c[1][0];
}

void scaling(int x[],int y[],int tx,int ty)
{
	lineDDA(x[0],y[0],x[1],y[1]);
	lineDDA(x[1],y[1],x[2],y[2]);
	lineDDA(x[2],y[2],x[0],y[0]);

	int s[2][2]={tx,0,0,ty};
	int p[2][1];

	for(int i=0;i<3;i++)
	{
		p[0][0]=x[i];
		p[1][0]=y[i];

		findnewcoordinate(s,p);
		x[i]=p[0][0];
		y[i]=p[1][0];

	}
	lineDDA(x[0],y[0],x[1],y[1]);
	lineDDA(x[1],y[1],x[2],y[2]);
	lineDDA(x[2],y[2],x[0],y[0]);
}


int main()
{

	int tx,ty;
	int x[]={100,200,300};
	int y[]={200,100,200};


	printf("enter the value of tx\n ");
	scanf("%d",&tx);
	printf("enter the value of ty\n");
	scanf("%d",&ty);
	int gd=DETECT,gm;
	initgraph(&gd, &gm, " ");
    
    delay(10);
	cleardevice();
    scaling(x,y,tx,ty);
    getch();


	return 0;
}