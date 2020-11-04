//此程序的目的是在输入的一系列字符串中找到和目标字符串相同的字符串并且返回最开始的下标

#include <stdio.h>
#define MAX 1000

int getline(char s[], int n);  //定义一个函数，用来通过输入构造一个字符串
int search(char s[],char t[]);   //定义一个函数，用来查找字符串中是否存在目标字符串，如果存在，返回第一个字符串的下标
char pattern [] = "ould";

int main ()
{
    char line[MAX];
    int found = 0;

    while ( getline ( line, MAX)  > 0)          //一定注意while的语法，是当括号里面的条件不满足时才会终止，当条件满足时，则会一直循环执行。
        {
            if (search (line, pattern) > 0)      //所以也就导致了输完一个字符串之后，先判断是否是符合条件的，然后继续循环，执行下一个输入的字符串
            {                                    //直到while里面的等于0为止，因为可以判断出字符串的个数不可能小于0，等于0的时候即输入零个字符，直接按ctrl+z，生成EOF字符
                printf ("%s \n", line);
                found ++;
            }           
        }
    
    return found;
}

//定义gettline函数

int getline (char s[], int lim )
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c =getchar ()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')            //以下三行意味着出现换行符此字符串将终结，然后进行查找的函数
        s[i++] = '\n';
    s[i] = '\0';

    return i;
}

//定义search函数

int search (char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; s[j] == t [k]; ++j, ++k)  //进行遍历，如果符合字符串的规定的话，就继续进行，只是不做任何处理罢了。
            ;
        if (k > 0 && t[k] == '\0')                   //注意：如果字符串仅仅为"ould"，则不能进行查找，原因是此时for循环语句中的第二个条件时，
                                                     // 原来字符中的\0和现在字符中的\0也是相等的，将会导致下面的if中的t[k]不会等于'\0'

            return i;
    }
       
    return -1;
}
