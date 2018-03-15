#include<iostream>
#include<graphics.h>

using namespace std;

class Pixel{

protected: int xco,yco;

public:
	Pixel(){xco=0;yco=0;}
	
	void setcoordinate(int x,int y){
	xco=x;yco=y;
	}
	
	void plotpixel(){
	putpixel(xco,yco,15);
	}
};

class Draw_line:public Pixel{

	int x2,y2; 
	
	public:
		Draw_line():Pixel(){
			x2=0;y2=0;
		}
		
		void setline(int x1,int y1,int xx,int yy){
			Pixel::setcoordinate(x1,y1);
			x2=xx;y2=yy;
		}	
			
		void dda_algorithm(){
			float x,y,dx,dy;
			float length;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			
			length=(dx>dy?dx:dy);
			
			dx=(x2-xco)/length;
			dy=(y2-yco)/length;
			
			x=xco+0.5;
			y=yco+0.5;
			
			int i=0;
			while(i<=length){
				Pixel::setcoordinate(x,y);
				Pixel::plotpixel();
				delay(25);
				y=y+dy;
				x=x+dx;
				i=i+1;
			}
		}
		
		void bresenhem_algo(int xmid,int ymid){
			
			float x,y,dx,dy,e,temp;
			int s1,s2,ex_flag,i=1;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			
			x=xco;y=yco;
			
			putpixel(xmid+x,ymid-y,10);
			
			s1=(x2>xco?1:x2=xco?0:-1);
			s2=(y2>yco?1:y2=yco?0:-1);
			
			if(dy>dx){
				temp=dy;
				dy=dx;
				dx=temp;
				ex_flag=1;
			}
			else
				ex_flag=0;
				
			e=2*dy-dx;
			do{
				while(e>=0){
					if(ex_flag==1)
						x=x+s1;
					else
						y=y+s2;
						
					e=e-2*dx;		
				}
				if(ex_flag==1)
					y=y+s2;
				else
					x=x+s1;
				e=e+2*dy;		
				putpixel(xmid+x,ymid-y,10);
				i++;

				delay(25);
			}while(i<=dx);				
		}
};

int main(){
	int gd=DETECT,gm=VGAMAX,x1,y1,x2,y2,ymax,xmax,xmid,ymid;
	Draw_line d;
	
	cout<<"\n ENTER x1,y1:";
	cin>>x1>>y1;
	cout<<"\n ENTER x2,y2:";
	cin>>x2>>y2;
	
	initgraph(&gd,&gm,NULL);
		xmax=getmaxx();
		ymax=getmaxy();
		xmid=xmax/2;
		ymid=ymax/2;
		
		line(0,ymid,xmax,ymid);
		line(xmid,0,xmid,ymax);
		
		//d.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
		//d.dda_algorithm();
		
		d.setline(x1,y1,x2,y2);
		d.bresenhem_algo(xmid,ymid);
		
		getchar();
		
		closegraph();
	
	return 0;
}
