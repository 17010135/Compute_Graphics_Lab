// Translation
#include<stdio.h>
#include<graphics.h>

int pts[3][3]={{100,50,150},{50,100,100},{1,1,1}};
int mat[3][3]={{1,0,0},{0,1,0},{0,0,1}};
int c[3][3];


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
   delay(5);		 
						 
} 
} 


void translate(int tx,int ty)
{
	mat[0][2]=tx;
	mat[1][2]=ty;
    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			 c[i][j]=0;
			for(int k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+mat[i][k]*pts[k][j];
			}
		}
	}
	lineDDA(c[0][0],c[1][0],c[0][1],c[1][1]);
	lineDDA(c[0][1],c[1][1],c[0][2],c[1][2]);
	lineDDA(c[0][0],c[1][0],c[0][2],c[1][2]);
}

int main()
{

	int tx,ty;

	printf("enter the value of tx\n ");
	scanf("%d",&tx);
	printf("enter the value of ty\n");
	scanf("%d",&ty);
	int gd=DETECT,gm;
	initgraph(&gd, &gm, " ");
	lineDDA(pts[0][0],pts[1][0],pts[0][1],pts[1][1]);
	lineDDA(pts[0][1],pts[1][1],pts[0][2],pts[1][2]);
	lineDDA(pts[0][0],pts[1][0],pts[0][2],pts[1][2]);


	delay(10);
	cleardevice();
    translate(tx,ty);
    getch();


	return 0;
}