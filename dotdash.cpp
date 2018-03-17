/*Write C++/Java program for line drawing using DDA or Bresenhams algorithm with patterns
such as solid, dotted, dashed, dash dot and thick.*/
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class Types_of_line{
	int thickness;
public:
	void setparameter(int thick){
		thickness=thick;
	}
		void dotted_line_bresenhem(int,int,int,int,int,int,int);
};
void Types_of_line::dotted_line_bresenhem(int xmid,int ymid,int x1,int y1,int x2,int y2,int choice){
	float x,y,dy,dx,e,temp;
	int s1,s2,i=1,indicator=0;
	bool exchange_flag;

	dx=abs(x2-x1);
	dy=abs(y2-y1);

	x=x1; y=y1;

	putpixel(xmid+x,ymid-y,15);

	s1=x2>x1?1:x2==x1?0:-1;
	s2=y2>y1?1:y2==y1?0:-1;

	if(dy>dx){
		temp=dy;
		dy=dx;
		dx=temp;
		exchange_flag=1;
	}
	else
		exchange_flag=0;

	e=2*dy-dx;
	do{
		while(e>=0){
			if(exchange_flag==1)
				x+=s1;
			else
				y+=s2;

			e=e-2*dx;
		}
		if(exchange_flag==1)
			y+=s2;
		else
			x+=s1;

		e=e+2*dy;

		switch(choice){

			case 1:
					if(i%4==0)
						putpixel(xmid+x,ymid-y,15);
						break;

			case 2:
					if(indicator<4)
						indicator++;
					else{
						indicator=(indicator+1)%10;
						putpixel(xmid+x,ymid-y,15);					
					}
						break;

			case 3:
					if(indicator<5){
						if(indicator%2==0)
						putpixel(xmid+x,ymid-y,15);		
						indicator++;
					}
					else{
						indicator=(indicator+1)%10;
						putpixel(xmid+x,ymid-y,15);					
					}
						break;

			case 4:
					{
						/*	
						int wx,wy;

						cout<<"\n\nenter thickness : ";
						cin>>thickness;

						wy=(thickness-1)*(sqrt(pow(x2-x1,2)+pow(y2-y1,2)))/((x2-x1)*2);

						wx=(thickness-1)*(sqrt(pow(x2-x1,2)+pow(y2-y1,2)))/((y2-y1)*2);

						if((y2-y1)/(x2-x1)<1){
							for(int i=0;i<wy;i++){
								putpixel(xmid+x,ymid-y+i,15);
								putpixel(xmid+x,ymid-y-i,15);
							}
						}else{
							for(int i=0;i<wx;i++){
								putpixel(xmid+x+i,ymid-y,15);
								putpixel(xmid+x-i,ymid-y,15);
							}
						}*/putpixel(xmid+x,ymid-y,15);
						break;
					}			
				}
		i++;
		delay(25);
	}while(i<=dx);
}

int main(){
	Types_of_line t;

	int gd=DETECT,gm=VGAMAX,xmid,ymid,x1,y1,x2,y2,thickness;
	cout<<"\n\nenter x1 and y1 : ";
	cin>>x1>>y1;
	cout<<"\n\nenter x1 and y2 : ";
	cin>>x2>>y2;

	cout<<"\n\n1.dotted\n2.dashed\n3.dashdot\n4.thick\n\nenter choice : ";
	int choice;
	cin>>choice;

	if(choice==4){
		cout<<"\n\nenter thickness : ";
						cin>>thickness;
						t.setparameter(thickness);
	}

	initgraph(&gd,&gm,NULL);
	xmid=getmaxx()/2;
	ymid=getmaxy()/2;

	if(choice==4){
			int wx,wy;

				wy=(thickness-1)*(sqrt(pow(x2-x1,2)+pow(y2-y1,2)))/((x2-x1)*2);

				wx=(thickness-1)*(sqrt(pow(x2-x1,2)+pow(y2-y1,2)))/((y2-y1)*2);

					if((y2-y1)/(x2-x1)<1){
						for(int i=0;i<wy;i++){
							t.dotted_line_bresenhem(xmid,ymid,x1,y1-i,x2,y2-i,choice);
							t.dotted_line_bresenhem(xmid,ymid,x1,y1+i,x2,y2+i,choice);
						}
					}else{
						for(int i=0;i<wx;i++){
							t.dotted_line_bresenhem(xmid,ymid,x1-i,y1,x2-i,y2,choice);
							t.dotted_line_bresenhem(xmid,ymid,x1+i,y1,x2+i,y2,choice);
						}
					}
	}
	else
	t.dotted_line_bresenhem(xmid,ymid,x1,y1,x2,y2,choice);
	getch();
	closegraph();

	return 0;
}