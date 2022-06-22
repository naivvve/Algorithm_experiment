#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdio.h>
#include <mm_malloc.h>
#include <string.h>
using namespace std; //随机数函数头文件
int count1=0,count2=0,count3=0;
double l1, m1,l2, m2,l3, m3,end1=0,end2=0,end3=0;
void BubbleSort(int num[], int n)//冒泡排序
{
    for (int i=0; i<n-1; i++)//两个for循环实现排序
        for (int j=0; j<n-i-1; j++){
            count1++;
            l1=(double)clock();
            if (num[j]>num[j+1])//当前元素较大时
            {
                m1=(double)clock();
                end1+=(m1-l1);
                int temp=num[j];//exchange
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
}

void merge(int num[],int left[],int right[],int l,int r)//两个有序序列的合并
{
    int i=0,j=0,p=0;
    l2=(double)clock();
    while(i<l&&j<r)//较小的放入num
    {
        m2=(double)clock();
        end2+=(m2-l2);
        count2++;
        if(left[i]<=right[j])
            num[p++]=left[i++];
        else
            num[p++]=right[j++];
    }
    while(i<l)//将剩余元素放入num
        num[p++]=left[i++];
    while(j<r)
        num[p++]=right[j++];
}

void mergeSort(int num[],int n)//合并排序
{
    if(n>1)
    {
        int mid=n/2;
        int *left=(int*)malloc(sizeof(int)*mid),*right=(int*)malloc(sizeof(int)*(n-mid));
        for(int i=0; i<mid; i++)
        {
            left[i]=num[i];
        }
        for(int j=mid; j<n; j++)
        {
            right[j-mid]=num[j];
        }
        mergeSort(left,mid);    //左半部分
        mergeSort(right,n-mid); //右半部分
        merge(num,left,right,mid,n-mid); //对两个有序序列进行合并
        free(right);
        free(left);
    }
}

void quickSort(int a[], int low,int high)//快速排序
{
    if(low<high)//递归终止条件
    {
        int i=low,j=high;
        int target=a[low];//待排序数组的第一个数为目标数target
        while(i<j)
        {
            l3=(double)clock();
            while(i<j&&a[j]>=target){
                m3=(double)clock();
                end3+=(m3-l3);
                j--;//右侧
                count3++;
            }
            if(i<j)
                a[i++]=a[j];
            l3=(double)clock();
            while(i<j&&a[i]<=target){
                m3=(double)clock();
                end3+=(m3-l3);
                i++;//左侧
                count3++;
            }
            if(i<j)
                a[j--]=a[i];
        }
        a[i]=target;//把目标数赋值到下标i的位置
        quickSort(a,low,i-1);//递归对目标数左、右数字进行排序
        quickSort(a,i+1,high);
    }
}

void print(int arr[], int n)//输出函数
{
    for(int j=0; j<n; j++)
    {
        cout<<arr[j]<<'\t';
    }
    cout<<endl;
}

int main()
{
    int n,a[100000],b[10000],c[10000];

    cout<<"请输入要生成随机数个数的参数n：";
    cin>>n;
    srand(time(0));
    for(int i=0; i<n; i++)
        a[i]=1+rand()%n;
    cout<<"*********************************************************************************************************************** \n";
    cout<<"随机数组为：\n";
    print(a,n);
    cout<<"*********************************************************************************************************************** \n";
    memcpy(b,a,sizeof(b));
    memcpy(c,a,sizeof(b));
    BubbleSort(a,n);//冒泡排序函数
    cout<<"冒泡排序后数组如下：\n";
    print(a,n);
    cout<<"冒泡排序基本操作的次数为：\n";
    printf("%d\n", count1);
    cout<<"冒泡排序比较操作耗费的时间为：\n";
    printf("%.4fms\n", end1);
    mergeSort(b,n);//合并排序函数
    cout<<"*********************************************************************************************************************** \n";
    cout<<"合并排序后生成的数组为：\n";
    print(b,n);
    cout<<"合并排序基本操作的次数为：\n";
    printf("%d\n", count2);
    cout<<"合并排序比较操作耗费的时间为：\n";
    printf("%.4fms\n", end2);
    quickSort(c,0,n-1);//快速排序函数
    cout<<"*********************************************************************************************************************** \n";
    cout<<"快速排序后生成的数组为：\n";
    print(c,n);
    cout<<"快速排序基本操作的次数为：\n";
    printf("%d\n", count3);
    cout<<"快速排序比较操作耗费的时间为：\n";
    printf("%.4fms\n", end3);
    return 0;
}
