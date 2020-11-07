#include <stdio.h>
#include <stdlib.h>   //为了调用atofa函数。


//函数声明
int getop (char s []);
void push (double p);
double pop(void);

#define NUMBER '0'
#define MAXOP 100
char s [MAXOP];


int main ()
{
    int type;
    double temp;

    while ((type = getop (s)) != EOF) 
    {
        switch (type)
        {
            //分成很多case,来进行讨论，如果是数字，就将其压入栈，如果是加减乘除运算符，就将栈中最顶层的两个元素取出，对其进行操作，然后将运算结果压入栈。
            //如果是换行符，表示这次运算结束了，此时栈中也只有一个元素，将其取出就是最后的结果，进行输出即可。
            case NUMBER:
                push( atof (s) );  //atof函数是将字符串转化成double型数字。
                break;
            case '+':
                push( pop () + pop () );
                break;
            case '*':
                push( pop () * pop () );
                break;
            case '-':
                temp = pop ();
                push( pop () - temp);
                break;
            case '/':
                temp = pop ();
                if (temp == 0.0)
                    printf("error : zero divisor \n");
                else
                    push(pop () / temp);
                break;
            case '\n':
                printf("\t%.8g\n", pop ());  //%f是指结果输出形式为小数，%e是指结果输出形式为指数形式，%g是指结果输出形式为%f或者%e进行自动选择，并除去多余的零
                break;
            default:
                printf("error : unknow command %s\n",s);
                break;

        }
    }
    return 0;
}


//定义函数push。
#define MAXBP  100

int bp = 0;
double val[MAXBP] ;        //构建一个栈，用来存放double类型的数据，栈的最大容量为100

void push (double p)
{
    if (bp >= MAXBP)
        printf("error : stack is full, can't push. %g\n",p);
    else
        val[bp++] = p;     //bp++代表的意思是先取bp本来的值，然后操作完成之后对bp加一，这样的话就是从0开始了，然后也实现了bp的自增。
                          //但是也导致了每次压栈之后，指针指向的不是新压栈的数据，而是压栈之后，这个数据之上的数据，也就是下一次压栈要进入数据的位置。
}

//定义函数pop。

double pop (void)  //因为栈里存储的是double型数据，所以函数要返回double型。
{
    if (bp > 0)
        return val [--bp];  //因为上面压栈之后指针指向的不是最上面的数据，而是压栈之后的上面的位置，所以这里要先对bp进行自减，然后在对其进行操作。
    else{                   //通过自减，使得指针不断向栈底进行移动，新加入数据时也将覆盖之前的数据，所以就变相的认为数据出栈了。
        printf("error : stack empty\n");
        return 0.0; 
    }        
}

//定义函数getop,该函数用于输出一个数字。
#include <ctype.h>
int getch (void);
void ungetch (int);

int getop (char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')     //除去空格以及制表符
        ;
    s[1] = '\0';
    if (! isdigit(c) && c !='.')             //不是数字以及小数点，即运算符，则直接输出。
        return c;
    i = 0;
    if ( isdigit (c))                         //如果是数字的话，就接着对下面的进行，因为数字有可能不止一位。
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))  //当遇到小数点的时候，这个时候跳过这个小数点，再进行数字输入。
            ;
    s[i] = '\0';           //在最后加上，表示字符串结束。
    if (c != EOF)         //因为最后时因为从不是阿拉伯数字0-9循环才跳出，所以这个时候c仍然是有赋值的，所以要将这个赋值进行回收。
        ungetch(c);

    return NUMBER;
}

//定义getch函数
#define MAXBAR 100
int bar = 0;
char barf[MAXBAR];

int getch (void)
{
    return (bar > 0) ? barf[--bar] : getchar(); //因为下面的ungetch最后实现了bar自增，所以要先自减，之后才取值。
}

//定义ungetch函数
void ungetch (int c) 
{
    if (bar >= MAXBAR)
        printf("ungetch : too many character\n");
    else
        barf[bar++] = c;   //先对bar进行操作，然后实现自增
}
