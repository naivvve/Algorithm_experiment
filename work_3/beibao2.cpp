#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Sort(int n,float *w,float *v)//排序函数
{
    int i,j;
    float temp1,temp2;
    for(i=1;i<=n;i++)
    for(j=1;j<=n-i;j++)//冒泡排序
    {
        temp1=v[j]/w[j];
        temp2=v[j+1]/w[j+1];
        if(temp1<temp2)
        {
            swap(w[j],w[j+1]);
            swap(v[j],v[j+1]);
        }
    }
}

int main()
{
    double l1, m1;
    float w[101],v[101],x[101];//物品重量、物品价值、放入背包的物品比例
    int n,i;//n为物品数
    float M;//背包容量
    cin>>n>>M;

    srand(time(0));
    for(i=1; i<=n; i++){
        w[i]=1+rand()%(int)M;
        cout<<w[i]<<endl;}

     srand(time(0));
    for(i=1; i<=n; i++){
        v[i]=+rand()%(int)(M-10);
        cout<<v[i]<<endl;
    }

    l1=(double)clock();
    Sort(n,w,v);
    for(i=1;i<=n;i++)
        x[i]=0;
    float c=M;//更新背包容量
    for(i=1;i<=n;i++)
    {
        if(c<w[i])
            break;
        x[i]=1;
        c=c-w[i];
    }
    if(i<=n)
        x[i]=c/w[i];
    for(int i=1;i<=n;i++)
        cout<<"重量为"<<w[i]<<"价值量为"<<v[i]<<"的物品"<<"放入的比例为"<<x[i]<<endl;
    printf("\n耗费时间为：\n");
    m1=(double)clock();
    printf("%.4fms\n", (m1-l1));
    return 0;
}

