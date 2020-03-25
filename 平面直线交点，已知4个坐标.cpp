#include<iostream>
using namespace std;
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
		   	cout<<" 两直线重合\n";
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
			cout<<"重合\n";
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
int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4,x0,y0;
	cout<<"输入四个点：\n";
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		int flag1=0;
		int flag=jiaodian(x1,y1,x2,y2,x3,y3,x4,y4,x0,y0,flag1);
		if(flag1)
		cout<<"交点为：("<<x0<<","<<y0<<")\n";
		cout<<"请继续输入四个点：\n"; 
	}
	return 0;
}





















