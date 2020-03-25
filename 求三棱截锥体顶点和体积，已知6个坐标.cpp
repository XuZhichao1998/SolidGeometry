#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
const int N=3;
double det(double aaa[N][N],int n);
int jiaodian(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x0,double &y0,int &a);
int main()
{
	double s1,s2,s,arr1[N][N]={0},arr2[N][N]={0};
	double x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5,x6,y6,z6,x0,y0,z0;
	cout<<"\n许智超设计/**这个程序目的是求三棱截锥体ABC-A1B1C1体积。\nA,A1,所在直线为L1；B,B1所在直线为L2。L1与L2交点即为顶点。\n求出顶点后即可用大三棱锥体积减去小三棱锥的体积的求出答案**/\n-------------------------\n";
	cout<<"请输入空间点A,A1，B,B1，C,C1的坐标：\n";
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4,&x5,&y5,&z5,&x6,&y6,&z6)!=EOF)
	{
		int flag1,flag2,flag3,flag4;
		flag1=jiaodian(x1,y1,x2,y2,x3,y3,x4,y4,x0,y0,flag3);
		flag2=jiaodian(z1,y1,z2,y2,z3,y3,z4,y4,z0,y0,flag4);
		if(x0<1e-8&&x0>-1e-8)x0=0;
		if(y0<1e-8&&y0>-1e-8)y0=0;
		if(z0<1e-8&&z0>-1e-8)z0=0;
		if(flag1*flag2)cout<<"L1和L2重合\n";
		if(flag3*flag4)
		{
			printf("交点为：(%.6lf,%.6lf,%.6lf)\n",x0,y0,z0);
			arr1[0][0]=x1-x0;arr1[0][1]=y1-y0;arr1[0][2]=z1-z0;
			arr1[1][0]=x3-x0;arr1[1][1]=y3-y0;arr1[1][2]=z3-z0;
			arr1[2][0]=x5-x0;arr1[2][1]=y5-y0;arr1[2][2]=z5-z0;
			arr2[0][0]=x2-x0;arr2[0][1]=y2-y0;arr2[0][2]=z2-z0;
			arr2[1][0]=x4-x0;arr2[1][1]=y4-y0;arr2[1][2]=z4-z0;
			arr2[2][0]=x6-x0;arr2[2][1]=y6-y0;arr2[2][2]=z6-z0;
			s1=det(arr1,3)/6;
			s2=det(arr2,3)/6;
			if(s1>s2)
			{
				double temp=s1;
				s1=s2;
				s2=temp;
			}
			s=s2-s1;
			printf("大三棱锥体积为%.6lf\n小三棱锥体积为：%.6lf\n",s2,s1);
			printf("该三棱截锥体体积为: %.6lf-%.6lf=%.6lf\n",s2,s1,s);
			cout<<"\n------------------------------------------------------\n请继续输入空间点A,A1，B,B1，C,C1的坐标：\n";

		}
		else cout<<"无交点!输入数据错误，请检查后重新输入。\n重新输入空间点A,A1，B,B1，C,C1的坐标：\n";

	}
	return 0;
}



int jiaodian(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double &x0,double &y0,int &a)
{
	int flag=0;
	double k=(y1-y2)*(x3-x4)-(y3-y4)*(x1-x2);
	double b=(y3-y1)*(x3-x4)*(x1-x2)+x1*(y1-y2)*(x3-x4)+x3*(y4-y3)*(x1-x2);
	if(abs(b)<1e-8)b=0; 
	cout<<"k="<<k<<"\tb="<<b<<endl;
	if(x1!=x2&&x3!=x4)
	{
		cout<<"两条直线斜率均存在。\n";
		if(k==0)//斜率相等
		{
			cout<<"两直线斜率相等\n";
		   if(b==0)
		   {
		   	cout<<" 两直线可能重合\n";
		   	flag=1;
			}
		}
		else//斜率不相等
		{
			cout<<"斜率不相等\n";
			x0=b/k;
			y0=(x0-x1)*(y1-y2)/(x1-x2)+y1;
			a=1;
			cout<<"x0="<<x0<<" "<<"y0="<<y0<<endl;
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
double det(double aaa[N][N],int n)
{
	double a[N][N];
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	     a[i][j]=aaa[i][j];
    double D;
    if(n==1){D=a[0][0];return D;}
    if(n==2){D=a[0][0]*a[1][1]-a[0][1]*a[1][0];return D;}
    if(n>=3)
    {
        D=0.0;
        double line1[N];
        double temp[N][N];
        for(int i=0;i<n;i++)
            {line1[i]=a[i][0]*pow(-1,i+2);}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                temp[i][j]=a[i][j+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int r=i;r<n-1;r++)
            {
                for(int c=0;c<n;c++)
                {
                    a[r][c]=temp[r+1][c];
                }
            }
            D+=line1[i]*det(a,n-1);
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n;j++)
                    a[i][j]=temp[i][j];
            }
        }
        if(D<0) D*=-1;
        return D;
    }
}
