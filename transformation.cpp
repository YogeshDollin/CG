/*Write C++/Java program to draw 2-D object and perform following basic transformations,
a) Scaling
b) Translation
c) Rotation
Use operator overloading.*/

#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

class Transformation{
	int n,xmid,ymid;	

public:
		void setparameter(int midx,int midy){
			xmid=midx;
			ymid=midy;
		}
		void getdata(int arr[][3],int);
		void draw_image(int a[][3],bool);
		void scaling(int a[][3],int,int);
		void translation(int a[][3],int,int);
		void rotation(int a[][3],float);

};

void Transformation::rotation(int a[][3],float ang){
	float angle=3.14*ang/180;
	float rotate[2][2]={cos(angle),sin(angle),-sin(angle),cos(angle)};

	int result[n][3];

	for(int i=0;i<n;i++)
		result[i][0]=result[i][1]=result[i][2]=0;

	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				result[i][j]=result[i][j]+rotate[k][j]*a[i][k];

	draw_image(result,0);

}

void Transformation::translation(int a[][3],int tx,int ty){
	for(int i=0;i<n;i++){
		a[i][0]=a[i][0]+tx;
		a[i][1]=a[i][1]+ty;
	}

	draw_image(a,0);
}

void Transformation::scaling(int a[][3],int sx,int sy){
	int scaled[2][2]={sx,0,0,sy};
	int result[n][3];

	for(int i=0;i<n;i++)
		result[i][0]=result[i][1]=result[i][2]=0;

	

	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				result[i][j]=result[i][j]+scaled[k][j]*a[i][k];

	draw_image(result,0);		

}

void Transformation::getdata(int arr[][3],int nn){
	n=nn;	

	cout<<"\n enter vertices : ";
	for(int i=0;i<n;i++){
		cout<<"\n\n\tx"<<i+1<<" : ";
		cin>>arr[i][0];
		cout<<"\t\ty"<<i+1<<" : ";
		cin>>arr[i][1];
		arr[i][2]=1;
	}
}

void Transformation::draw_image(int arr[][3],bool choice){
	
	if(choice==0){
	for(int i=0;i<n-1;i++)
		line(xmid+arr[i][0],ymid-arr[i][1],xmid+arr[i+1][0],ymid-arr[i+1][1]);
		
	line(xmid+arr[n-1][0],ymid-arr[n-1][1],xmid+arr[0][0],ymid-arr[0][1]);
	}
	else{
		for(int i=0;i<n-1;i++)
		line(arr[i][0],ymid-arr[i][1],arr[i+1][0],ymid-arr[i+1][1]);
		
	line(arr[n-1][0],ymid-arr[n-1][1],arr[0][0],ymid-arr[0][1]);	
	}
}

int main(){
	Transformation t;
	int n;
	cout<<"\n enter number of verices to add : ";
	cin>>n;
	int arr[n][3];
	t.getdata(arr,n);


	int choice;
	cout<<"\n\n1.scaling \n2.translation\n3.rotation\n4.exit\n\nenter choice : ";
	cin>>choice;


	int gd=DETECT,gm=VGAMAX,xmid,ymid,sx,sy,tx,ty; float angle;

		switch(choice){
			case 1:{
				cout<<"\n\n enter scaling factor : ";
				cout<<"\n\tsx : ";
				cin>>sx;
				cout<<"\t\tsy : ";
				cin>>sy;

				initgraph(&gd,&gm,NULL);
				xmid=getmaxx()/2;
				ymid=getmaxy()/2;

				t.setparameter(xmid,ymid);
				t.draw_image(arr,1);
				t.scaling(arr,sx,sy);
	
				getch();
				closegraph();
				break;
			}

		case 2:{
			cout<<"\n\n enter translating factor : ";
				cout<<"\n\ttx : ";
				cin>>tx;
				cout<<"\t\tty : ";
				cin>>ty;

			initgraph(&gd,&gm,NULL);

		xmid=getmaxx()/2;
		ymid=getmaxy()/2;

		t.setparameter(xmid,ymid);

		t.draw_image(arr,0);
				
				t.translation(arr,tx,ty);
				getch();
				closegraph();
				break;
			}

			case 3:
					{
						cout<<"\n\nenter angle of rotation : ";
						cin>>angle;

						initgraph(&gd,&gm,NULL);

						xmid=getmaxx()/2;
						ymid=getmaxy()/2;

						t.setparameter(xmid,ymid);

						t.draw_image(arr,1);
						t.rotation(arr,angle);
						getch();
						closegraph();
						break;
					}

			case 4:
					exit(0);

			default :
				cout<<"\n\ninvalid choice";
				break;
			}	
		

	return 0;
}
