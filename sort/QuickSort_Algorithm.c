#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int l,int r)
{
    int i = l;
    int j = r + 1;
    int p = a[l];
    do
    {
        do
        {
            i++;

        }while(a[i] < p);

        do
        {
            j--;

        }while(a[j] > p);

        swap(&a[i],&a[j]);

    }while(i <= j);

    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}

void quick_sort(int a[],int l,int r)
{
    if(l < r)
    {
        int s = partition(a,l,r);
        quick_sort(a,l,s - 1);
        quick_sort(a,s + 1,r);
    }

}

int main()
{
    int N;
    printf("Enter the number of elements\n");
    scanf("%d",&N);
    int a[N];
    printf("Enter the elements\n");
    for(int i = 0;i < N;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,N - 1);
    for(int i = 0;i < N;i++)
    {
        printf("%d ",a[i]);
    }
}
