#include <stdio.h>
int searchLinear(float* salaries,int size,float searchSalary);
int main()
{
    float salaries[]={20.0f,10.0f,15.0f,12.0f,13.0f};
    int salariesCount=5;
    float searchSalary=12.0f;
    int index=searchLinear(salaries,salariesCount,searchSalary);
    printf("%.2f found at index %d\n",searchSalary,index);
    return 0;
}
int searchLinear(float* salaries,int size,float searchSalary){
    for(int i=0;i<size;i++){
        if(salaries[i]==searchSalary){
            return i;
        }
    }
    return -1;
}
