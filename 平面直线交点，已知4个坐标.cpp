#include<iostream>
using namespace std;
int jiaodian(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x0,double &y0,int &a)
{
	int flag=0;
	double b=(y1-y2)*(x3-x4)-(y3-y4)*(x1-x2);
	double k=(y3-y1)*(x3-x4)*(x1-x2)+x1*(y1-y2)*(x3-x4)+x3*(y4-y3)*(x1-x2);
	if(x1!=x2&&x3!=x4)
	{
		cout<<"����ֱ��б�ʾ����ڡ�\n";
		if(k==0)//б�����
		{
		   if(b==0)
		   {
		   	cout<<" ��ֱ���غ�\n";
		   	flag=1;
			} 
		} 
		else//б�ʲ���� 
		{
			cout<<"б�ʲ����\n";
			x0=k/b;
			y0=(x0-x1)*(y1-y2)/(x1-x2)+y1;
			a=1;
		}
	}
	if(x1==x2&&x3==x4)//б�ʾ�������
	{
		cout<<"��ֱ��б�ʾ�������\n";
		if(x1!=x3)cout<<"ƽ��\n";
		if(x1==x3)
		{
			cout<<"�غ�\n";
			flag=1;
		} 
	} 
	if(x1==x2&&x3!=x4)
	{
		cout<<"L1б�ʲ�����,L2����\n";
		x0=x1;y0=(x1-x3)*(y3-y4)/(x3-x4)+y3;
		a=1;
	}
	if(x3==x4&&x1!=x2)
	{
		cout<<"L2б�ʲ����ڣ�L1����\n";
		x0=x3;
		y0=(x3-x1)*(y1-y2)/(x1-x2)+y1;
		a=1;
	}
	return flag;
}
int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4,x0,y0;
	cout<<"�����ĸ��㣺\n";
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		int flag1=0;
		int flag=jiaodian(x1,y1,x2,y2,x3,y3,x4,y4,x0,y0,flag1);
		if(flag1)
		cout<<"����Ϊ��("<<x0<<","<<y0<<")\n";
		cout<<"����������ĸ��㣺\n"; 
	}
	return 0;
}





















