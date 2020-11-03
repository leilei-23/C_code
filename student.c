#include <stdio.h>
#define N 3

//构建学生结构体，其中包括学号、姓名、三门课成绩、平均成绩

struct Student
{
    int num;
    char name[20];
    float score[3];
    float avescore;
};

//构建输入学生信息的函数

void input(struct Student stu[])
{
    int i;

    printf("请输入学生的学号、姓名、三门课成绩：\n");
    for (i=0;i<N;++i)
    {
        scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].avescore = ( stu[i].score[0] + stu[i].score[1] + stu[i].score[2] ) / 3.0;
    }
}

//构建比较平均成绩大小的函数，返回平均成绩大的学生结构体

struct Student max(struct Student stu[])
{
    int i ,m=0;

    for (i = 0;i < N;++i)
    {
        if (stu[m].avescore < stu[i].avescore)
            m = i;
    }
    return stu[m];
}

//构建输出函数，输出平均成绩最大的学生

void print(struct Student stud) 
{
    printf("\n平均成绩最大的学生信息：\n");
    printf("学号：%d\n姓名： %s\n分数： %f %f %f\n平均成绩：%f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.avescore);
}

int main ()         //主函数
{
    struct Student stu[N],*p = stu;
    input(p);
    print(max(p));
}
