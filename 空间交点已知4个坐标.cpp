#include<iostream>
#include<cstdio>
using namespace std;
int jiaodian(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x0,double &y0,int &a);
int main()
{
	double x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x0,y0,z0;
	cout<<"\n���ǳ����/**�������Ŀ������ռ�ֱ�ߵĽ��㣬�����ĸ���A,B,C,D;A,B����ֱ��ΪL1,C,D����ֱ��ΪL2**/\n-----------------------------------------------------------------------------\n";
	cout<<"�������ĸ��ռ�ĵ�����(8����)��\n";
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4)!=EOF)
	{
		int flag1,flag2,flag3,flag4;
		flag1=jiaodian(x1,y1,x2,y2,x3,y3,x4,y4,x0,y0,flag3);
		flag2=jiaodian(z1,y1,z2,y2,z3,y3,z4,y4,z0,y0,flag4);
		if(x0<1e-8&&x0>-1e-8)x0=0;
		if(y0<1e-8&&y0>-1e-8)y0=0;
		if(z0<1e-8&&z0>-1e-8)z0=0;		
		if(flag1*flag2)cout<<"L1��L2�غ�\n";
		if(flag3*flag4)cout<<"����Ϊ��("<<x0<<","<<y0<<","<<z0<<")\n";
		else cout<<"�޽���\n";
		cout<<"\n------------------------------------------------------\n����������ĸ��㣺\n";	
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
		cout<<"����ֱ��б�ʾ����ڡ�\n";
		if(k==0)//б�����
		{
		   if(b==0)
		   {
		   	cout<<" ��ֱ�߿����غ�\n";
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
			cout<<"��ֱ�߿����غ�\n";
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
