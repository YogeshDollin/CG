/*Write C++/Java program to draw 2-D object and perform following basic transformations,
a) Scaling
b) Translation
c) Rotation
Use operator overloading.*/

#include <iostream>
#include <graphics.h>

using namespace std;

class Transformation{
	int tx,ty,sx,sy,n;

public:
		void getdata(int arr[][3],int);
		void draw_image(int a[][3],int,int);
		void scaling();
		void transformations();
		void rotation();

};

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

void Transformation::draw_image(int arr[][3],int xmid,int ymid){
	
	for(int i=0;i<n-1;i++)
		line(xmid+arr[i][0],ymid-arr[i][1],xmid+arr[i+1][0],ymid-arr[i+1][1]);
		
	line(xmid+arr[n-1][0],ymid-arr[n-1][1],xmid+arr[0][0],ymid-arr[0][1]);
}

int main(){
	Transformation t;
	int n;
	cout<<"\n enter number of verices to add : ";
	cin>>n;
	int arr[n][3];
	t.getdata(arr,n);

	int gd=DETECT,gm=VGAMAX,xmid,ymid;
	initgraph(&gd,&gm,NULL);

		xmid=getmaxx()/2;
		ymid=getmaxy()/2;

		t.draw_image(arr,xmid,ymid);
		getch();

		closegraph();

	return 0;
}