#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=5; 
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
        return D;
    }
}

int main()
{
	int flag;
	cout<<"开始输入1，结束输入0：";
	
	while(cin>>flag)
	{
		if(!flag)break;
		double a[N][N]={0};
		cout<<"输入四个空间点坐标(最后输入交点)：\n";
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				a[i][j]-=a[3][j];
			}
		} 
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			cout<<a[i][j]<<" ";
			cout<<endl;
		}
		double  answer=det(a,3);
		if(answer<0)answer*=-1;
		double ans=answer/6;
		printf("若为六面体，体积为：%.6lf\n若为四面体体积为%.6lf\n继续输入1，退出输入0：",answer,ans);
	}
	return 0;
}





















