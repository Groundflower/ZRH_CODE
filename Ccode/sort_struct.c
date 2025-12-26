#include<stdio.h>
#define N 3
#define NAMESIZE 20
struct student
{
    char name[NAMESIZE];
    int age;
    char sex;
};
//struct student stu[3];
int main()
{
    int i,j;
    struct student stu[10];
    struct student change;
    printf("Please input student data\n");
    i=0;
    while(i<N)
    {
        printf("name:age:sex:");
        scanf("%s",&stu[i].name);
        scanf("%d",&stu[i].age);
        scanf("%c",&stu[i].sex);
        i++;
    }
    for(i=0;i<N-1;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(stu[i].age>stu[j].age)
            {
                change=stu[i];
                stu[i]=stu[j];
                stu[j]=change;
            }
        }
    }
    printf("The result after sorting\n");
    for(i=0;i<N;i++)
        printf("Name:%s\tAge:%d\tSex:%c\n",stu[i].name,stu[i].age,stu[i].sex);

return 0;

}