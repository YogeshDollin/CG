#include<iostream>
#include<graphics.h>

using namespace std;

class Draw_circle{
	int xmid,ymid;
public:
	
	 void set(int midx,int midy,int xc,int yc){
		xmid=midx+xc;
		ymid=midy-yc;
	}

	void draw_pixel(int x,int y,int color){
		putpixel(xmid+x,ymid-y,color);
		putpixel(xmid-x,ymid-y,color);
		putpixel(xmid+x,ymid+y,color);
		putpixel(xmid-x,ymid+y,color);
		putpixel(xmid+y,ymid-x,color);
		putpixel(xmid-y,ymid-x,color);
		putpixel(xmid+y,ymid+x,color);
		putpixel(xmid-y,ymid+x,color);
	}

	void circle_bres_algo(int r){
		//cout<<xmid<<" "<<ymid<<endl;
	int	x=0;
	 int y=r;

		int d=3-2*r;
		do{
			//cout<<x<<"  "<<y<<endl;
			draw_pixel(x,y,10);
			if(d<=0)
				d=d+4*x+6;
			else{
				d=d+4*(x-y)+10;
				y--;
			}
			x++;
			delay(50);
		}while(x<=y);
	}
};

int main(){
	int gd=DETECT,gm=VGAMAX,x,y,radius,xmid,ymid,xmax,ymax;
	Draw_circle c;

	cout<<"\n enter x and ycoordinate and radius : ";
	cin>>x>>y>>radius;

	initgraph(&gm,&gd,NULL);
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;

	//cout<<xmax<<" "<<ymax<<endl;

	 line(0,ymid,xmax,ymid);
	 line(xmid,0,xmid,ymax);

	 c.set(xmid,ymid,x,y);

	 c.circle_bres_algo(radius);
	
	 getch();
	 closegraph();
	return 0;
}