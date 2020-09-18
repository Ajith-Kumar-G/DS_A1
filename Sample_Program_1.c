#include<stdio.h>

struct student_data
{
int student_id;
int age;
int marks;
}S1;
void getdata(struct student_data *);
void validation(struct student_data,int * );
void qualification(struct student_data,int,int *);

int main()
{
    int flag1=0,flag2=0; //Flag1 : Validity Flag, Flag2 : Qualification Flag
    getdata(&S1);
    validation(S1,&flag1);
    qualification(S1,flag1,&flag2);
    if (flag1==1)
       {
        if(flag2==1)
           printf("\nThe Given Data Is Valid And You are Qualified!!");
        else
            printf("\nThe Given Data Is Valid, But You are Not Qualified for the Admission!!");
       }
    else
        printf("\nThe Given Data Is not valid, Check The validation criteria And try applying again.");

       return 0;
}

void getdata(struct student_data *S)
{
    printf("\nEnter the Student_Id, Age, Marks <In the same order> :\n");
    scanf("%d%d%d",&S->student_id,&S->age,&S->marks);
}
void validation(struct student_data S, int *f1)
{
    if(S.age>20 && 0<=S.marks<=100)
        *f1=1;
}
void qualification(struct student_data S,int f1, int *f2)
{
    if(S.marks>=65 && f1==1)
        *f2=1;
}
