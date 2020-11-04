/*这个程序的目的是构造一个链表，包括两个函数，一个是构造链表函数，其返回的是一个头指针。另一个是输出链表的函数，其需要的形参是头指针。*/


#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct Student)

//创建结构体：Node，包含了两部分，第一部分包括学号和成绩，第二部分是指向下一个Node的指针

struct Student
{
    int num;
    float score;
    struct Student *next;
};

//构造一个创建链表的函数，返回的是头指针，因为头指针可以代表整个链表。

int n ;//定义一个类似于全局变量，用于对链表节点进行计数

struct Student * creat(void)
{
    struct Student *head,*p1,*p2;
   
    n = 0;
    p1=p2=(struct Student *)malloc(LEN);
    scanf("%d,%f",&p1->num,&p1->score);
    head = NULL;
    while (p1->num!=0)
    {
        n=n+1;
        if (n==1)head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct Student *) malloc(LEN);
        scanf("%d,%f",&p1->num,&p1->score);
    }
    p2->next = NULL;
    return head;
}

//构造输出函数，输出链表,需要传入形参为头指针

void print(struct Student *head)
{
    struct Student *p;

    printf("\nNow,These %d records are:\n",n);
    p = head;
    if (head != NULL)
    {
        do
        {
            printf("num = %d,score = %f\n",p->num,p->score);
            p = p->next;
        }while (p != NULL);
    }

}

//主函数

int main()
{
    struct Student *head;
    head = creat();
    print (head);
}
