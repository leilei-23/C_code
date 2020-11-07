#include <stdio.h>
int main ()
{
    int c, i, nwhite, nother, ndigit[10];   //三个值分别用来对空格、其他、数字进行计数

    //个数初始化
    nwhite = 0;
    nother = 0;
    for (i = 0;i < 10;++i)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF)    //EOF指的是文件结束符，在windows中指的是ctrl+z,在linux系统中指的是crtl+d
    {
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': 
                ndigit[c-'0']++;   //'0'指的是0在ASC II中是指48，而c代表的也是ASC II码，所以相减就是把对应的字符'c'转换成int类型，即 0-9
                break;
            case ' ': 
            case '\n':           //记住这样的case表示方式
            case '\t': 
                nwhite++;
                break;
            default: 
                nother++;
                break;
        }
    }
    printf("digits = ");
    for (i = 0;i < 10; ++i)
        printf(" %d",ndigit[i]);
    printf("\nwhite space = %d\nother = %d\n",nwhite,nother);
    return 0;

}
