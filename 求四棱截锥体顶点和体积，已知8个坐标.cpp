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
	double s1,s2,s,s3,s4,arr1[N][N]={0},arr2[N][N]={0},arr3[N][N]={0},arr4[N][N]={0};
	double x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,x5,y5,z5,x6,y6,z6,x7,y7,z7,x8,y8,z8,x0,y0,z0;
	cout<<"\n���ǳ����/**�������Ŀ�����������׶��ABCD-A1B1C1D1�����\nA,A1,����ֱ��ΪL1��B,B1����ֱ��ΪL2��L1��L2���㼴Ϊ����O(����һλС��)��\n�������󼴿��ô�����׶�����ȥС����׶������������**/\n-------------------------\n";
	cout<<"������ռ��A,A1��B,B1��C,C1��D,D1�����꣺\n";
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4,&x5,&y5,&z5,&x6,&y6,&z6,&x7,&y7,&z7,&x8,&y8,&z8)!=EOF)
	{
		int flag1,flag2,flag3,flag4;
		flag1=jiaodian(x1,y1,x2,y2,x3,y3,x4,y4,x0,y0,flag3);
		flag2=jiaodian(z1,y1,z2,y2,z3,y3,z4,y4,z0,y0,flag4);
		x0=x0*10+0.5;y0=y0*10+0.5;z0=z0*10+0.5;
		int t1=x0,t2=y0,t3=z0;
		x0=(double)t1/10;y0=(double)t2/10;z0=(double)t3/10;
		if(x0<1e-8&&x0>-1e-8)x0=0;
		if(y0<1e-8&&y0>-1e-8)y0=0;
		if(z0<1e-8&&z0>-1e-8)z0=0;		
		if(flag1*flag2)cout<<"L1��L2�غ�\n";
		if(flag3*flag4)
		{
			printf("����Ϊ��(%lf,%lf,%lf)\n",x0,y0,z0); 
			arr1[0][0]=x1-x0;arr1[0][1]=y1-y0;arr1[0][2]=z1-z0;
			arr1[1][0]=x3-x0;arr1[1][1]=y3-y0;arr1[1][2]=z3-z0;
			arr1[2][0]=x5-x0;arr1[2][1]=y5-y0;arr1[2][2]=z5-z0;
			arr2[0][0]=x2-x0;arr2[0][1]=y2-y0;arr2[0][2]=z2-z0;
			arr2[1][0]=x4-x0;arr2[1][1]=y4-y0;arr2[1][2]=z4-z0;
			arr2[2][0]=x6-x0;arr2[2][1]=y6-y0;arr2[2][2]=z6-z0;
			arr3[0][0]=x1-x0;arr3[0][1]=y1-y0;arr3[0][2]=z1-z0;
			arr3[1][0]=x7-x0;arr3[1][1]=y7-y0;arr3[1][2]=z7-z0;
			arr3[2][0]=x5-x0;arr3[2][1]=y5-y0;arr3[2][2]=z5-z0;
			arr4[0][0]=x2-x0;arr4[0][1]=y2-y0;arr4[0][2]=z2-z0;
			arr4[1][0]=x8-x0;arr4[1][1]=y8-y0;arr4[1][2]=z8-z0;
			arr4[2][0]=x6-x0;arr4[2][1]=y6-y0;arr4[2][2]=z6-z0;
			cout<<"A,B,Cԭ�������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(j==0) 
					cout<<setw(12)<<arr1[i][j]+x0<<" ";
					if(j==1)
					cout<<setw(12)<<arr1[i][j]+y0<<" ";
					if(j==2)
					cout<<setw(12)<<arr1[i][j]+z0<<" ";
				}
				cout<<endl;
			} 
			cout<<"A1,B1,C1ԭ�������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(j==0) 
					cout<<setw(12)<<arr2[i][j]+x0<<" ";
					if(j==1)
					cout<<setw(12)<<arr2[i][j]+y0<<" ";
					if(j==2)
					cout<<setw(12)<<arr2[i][j]+z0<<" ";
				}
				cout<<endl;
			} 
			cout<<"A,D,Cԭ�������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(j==0) 
					cout<<setw(12)<<arr3[i][j]+x0<<" ";
					if(j==1)
					cout<<setw(12)<<arr3[i][j]+y0<<" ";
					if(j==2)
					cout<<setw(12)<<arr3[i][j]+z0<<" ";
				}
				cout<<endl;
			} 
			cout<<"A1,D1,C1ԭ�������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(j==0) 
					cout<<setw(12)<<arr4[i][j]+x0<<" ";
					if(j==1)
					cout<<setw(12)<<arr4[i][j]+y0<<" ";
					if(j==2)
					cout<<setw(12)<<arr4[i][j]+z0<<" ";
				}
				cout<<endl;
			} 
			cout<<"A,B,C��ȥ���������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<setw(12)<<arr1[i][j]<<" ";
				}
				cout<<endl;
			} 
			cout<<"A1,B1,C1��ȥ���������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<setw(12)<<arr2[i][j]<<" ";
				}
				cout<<endl;
			} 
			cout<<"A,D,C��ȥ���������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<setw(12)<<arr3[i][j]<<" ";
				}
				cout<<endl;
			} 
			cout<<"A1,D1,C1��ȥ���������꣺\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<setw(12)<<arr4[i][j]<<" ";
				}
				cout<<endl;
			} 
			s1=det(arr1,3)/6;
			s2=det(arr2,3)/6;
			s3=det(arr3,3)/6;
			s4=det(arr4,3)/6;
			if(s1>s2)
			{
				double temp=s1;
				s1=s2;
				s2=temp;
			}
			if(s3>s4)
			{
				double temp=s3;
				s3=s4;
				s4=temp;
			}
			s=s2-s1+s4-s3;
			printf("������׶O-ABC���Ϊ%.6lf\nС����׶0-A1B1C1���Ϊ��%.6lf\n������׶O-BCD���Ϊ%.6lf\nС����׶0-B1C1D1���Ϊ��%.6lf\n",s2,s1,s4,s3);
			printf("�������׶�����Ϊ: %.6lf-%.6lf+%.6lf-%.6lf=%.6lf\n",s2,s1,s4,s3,s); 
			cout<<"\n------------------------------------------------------\n���������ռ��A,A1��B,B1��C,C1,D,D1�����꣺\n";			
		
		}
		else cout<<"�޽���!�������ݴ���������������롣\n��������ռ��A,A1��B,B1��C,C1,D,D1�����꣺\n";
			
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
