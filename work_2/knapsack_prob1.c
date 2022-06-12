#include<stdio.h>
int N,C,bestp,p[10000],w[10000],x[10000],bestx[10000];//物品的个数，背包的容量，最大价值物品的价值，物品的重量，x[i]暂存物品的选中情况,物品的选中情况

void Backtrack(int i,int cp,int cw)
{
    int j;
    if(i>N)
    {
        if(cp>bestp)
        {
            bestp=cp;
            for(i=0; i<=N; i++) bestx[i]=x[i];
        }
    }
    else
        for(j=0; j<=1; j++)
        {
            x[i]=j;
            if(cw+x[i]*w[i]<=C)
            {
                cw+=w[i]*x[i];
                cp+=p[i]*x[i];
                Backtrack(i+1,cp,cw);
                cw-=w[i]*x[i];
                cp-=p[i]*x[i];
            }
        }
}

int main()
{
    int i;
    double l1, m1;
    bestp=0;
    printf("请输入背包最大容量:\n");
    scanf("%d",&C);
    printf("请输入物品个数:\n");
    scanf("%d",&N);

    srand(time(0));
    for(i=0; i<N; i++)
        w[i]=1+rand()%N;
    printf("n个物品的重量为:\n");
    for(i=0; i<N; i++)
        printf("%d ",w[i]);

    srand(time(0));
    for(i=0; i<N; i++)
        p[i]=3+rand()%N;
    printf("\nn个物品的价值为:\n");
    for(i=0; i<N; i++)
        printf("%d ",p[i]);

    l1=(double)clock();
    Backtrack(1,0,0);
    printf("\n耗费时间为：\n");
    m1=(double)clock();
    printf("%.4fms\n", (m1-l1));
    printf("最大价值为:\n");
    printf("%d\n",bestp);
    printf("被选中的物品依次为(0表示未选中，1表示选中)\n");
    for(i=1; i<=N; i++)
        printf("%d ",bestx[i]);
    printf("\n");
    return 0;
}
