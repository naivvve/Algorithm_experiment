#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdio.h>

#include <string.h>
using namespace std; //���������ͷ�ļ�

void BubbleSort(int num[], int n)//ð������
{
    for (int i=0; i<n-1; i++)//����forѭ��ʵ������
        for (int j=0; j<n-i-1; j++)
            if (num[j]>num[j+1])  //��ǰԪ�ؽϴ�ʱ
            {
                int temp=num[j];//exchange
                num[j]=num[j+1];
                num[j+1]=temp;
            }
}

void merge(int num[],int left[],int right[],int l,int r)//�����������еĺϲ�
{
    int i=0,j=0,p=0;
    while(i<l&&j<r)//��С�ķ���num
    {
        if(left[i]<=right[j])
            num[p++]=left[i++];
        else
            num[p++]=right[j++];
    }
    while(i<l)//��ʣ��Ԫ�ط���num
        num[p++]=left[i++];
    while(j<r)
        num[p++]=right[j++];
}

void mergeSort(int num[],int n)//�ϲ�����
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
        mergeSort(left,mid);    //��벿��
        mergeSort(right,n-mid); //�Ұ벿��
        merge(num,left,right,mid,n-mid); //�������������н��кϲ�
        free(right);
        free(left);
    }
}

void quickSort(int a[], int low,int high)//��������
{
    if(low<high)//�ݹ���ֹ����
    {
        int i=low,j=high;
        int target=a[low];//����������ĵ�һ����ΪĿ����target
        while(i<j)
        {
            while(i<j&&a[j]>=target)
                j--;//�Ҳ�
            if(i<j)
                a[i++]=a[j];
            while(i<j&&a[i]<=target)
                i++;//���
            if(i<j)
                a[j--]=a[i];
        }
        a[i]=target;//��Ŀ������ֵ���±�i��λ��
        quickSort(a,low,i-1);//�ݹ��Ŀ�����������ֽ�������
        quickSort(a,i+1,high);
    }
}

void print(int arr[], int n)//�������
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
    double l1, m1,l2, m2,l3, m3;
    cout<<"������Ҫ��������������Ĳ���n��";
    cin>>n;
    srand(time(0));
    for(int i=0; i<n; i++)
        a[i]=1+rand()%n;
    cout<<"*********************************************************************************************************************** \n";
    cout<<"�������Ϊ��\n";
    print(a,n);
    cout<<"*********************************************************************************************************************** \n";
    memcpy(b,a,sizeof(b));
    memcpy(c,a,sizeof(b));
    l1=(double)clock();
    BubbleSort(a,n);//ð��������
    cout<<"ð��������������£�\n";
    print(a,n);
    cout<<"����ķѵ�ʱ��Ϊ��\n";
    m1=(double)clock();
    printf("%.4fms\n", (m1-l1));
    l2=(double)clock();
    mergeSort(b,n);//�ϲ�������
    cout<<"*********************************************************************************************************************** \n";
    cout<<"�ϲ���������ɵ�����Ϊ��\n";
    print(b,n);
    cout<<"����ķѵ�ʱ��Ϊ��\n";
    m2=(double)clock();
    printf("%.4fms\n", (m2-l2));
    l3=(double)clock();
    quickSort(c,0,n-1);//����������
    cout<<"*********************************************************************************************************************** \n";
    cout<<"������������ɵ�����Ϊ��\n";
    print(c,n);
    cout<<"����ķѵ�ʱ��Ϊ��\n";
    m3=(double)clock();
    printf("%.4fms\n", (m3-l3));
    return 0;
}
