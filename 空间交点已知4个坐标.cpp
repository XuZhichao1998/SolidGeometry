#include<iostream>
#include<cstdio>
using namespace std;
int jiaodian(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x0,double &y0,int &a);
int main()
{
	double x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x0,y0,z0;
	cout<<"\n许智超设计/**这个程序目的是求空间直线的交点，输入四个点A,B,C,D;A,B所在直线为L1,C,D所在直线为L2**/\n-----------------------------------------------------------------------------\n";
	cout<<"请输入四个空间的点坐标(8个数)：\n";
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4)!=EOF)
	{
		int flag1,flag2,flag3,flag4;
		flag1=jiaodian(x1,y1,x2,y2,x3,y3,x4,y4,x0,y0,flag3);
		flag2=jiaodian(z1,y1,z2,y2,z3,y3,z4,y4,z0,y0,flag4);
		if(x0<1e-8&&x0>-1e-8)x0=0;
		if(y0<1e-8&&y0>-1e-8)y0=0;
		if(z0<1e-8&&z0>-1e-8)z0=0;		
		if(flag1*flag2)cout<<"L1和L2重合\n";
		if(flag3*flag4)cout<<"交点为：("<<x0<<","<<y0<<","<<z0<<")\n";
		else cout<<"无交点\n";
		cout<<"\n------------------------------------------------------\n请继续输入四个点：\n";	
	}
	return 0;	
} 



int jiaodian(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x0,double &y0,int &a)
{
	int flag=0;
	double b=(y1-y2)*(x3-x4)-(y3-y4)*(x1-x2);
	double k=(y3-y1)*(x3-x4)*(x1-x2)+x1*(y1-y2)*(x3-x4)+x3*(y4-y3)*(x1-x2);
	if(x1!=x2&&x3!=x4)
	{
		cout<<"两条直线斜率均存在。\n";
		if(k==0)//斜率相等
		{
		   if(b==0)
		   {
		   	cout<<" 两直线可能重合\n";
		   	flag=1;
			} 
		} 
		else//斜率不相等 
		{
			cout<<"斜率不相等\n";
			x0=k/b;
			y0=(x0-x1)*(y1-y2)/(x1-x2)+y1;
			a=1;
		}
	}
	if(x1==x2&&x3==x4)//斜率均不存在
	{
		cout<<"两直线斜率均不存在\n";
		if(x1!=x3)cout<<"平行\n";
		if(x1==x3)
		{
			cout<<"两直线可能重合\n";
			flag=1;
		} 
	} 
	if(x1==x2&&x3!=x4)
	{
		cout<<"L1斜率不存在,L2存在\n";
		x0=x1;y0=(x1-x3)*(y3-y4)/(x3-x4)+y3;
		a=1;
	}
	if(x3==x4&&x1!=x2)
	{
		cout<<"L2斜率不存在，L1存在\n";
		x0=x3;
		y0=(x3-x1)*(y1-y2)/(x1-x2)+y1;
		a=1;
	}
	return flag;
}
