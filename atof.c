//这个函数并不是一个高质量的函数，因为它占用了过多的存储空间，
//该函数用来将字符串转换成double型的数。
#include <stdio.h>
#include <ctype.h>  //头文件，导入之后才能使用函数isspace 和函数isdigit。

double atof(char s[])
{
    int i, sign;
    double val,pot;

    for (i = 0; isspace(s[i]); i++) //isspace 函数是用来判断字符串的开头是否是空格，如果是空格，则指针向后移。
        ;

    sign = (s [i] == '-') ? -1 : 1; //用来判断数字的符号
    if (s[i] == '+' || s[i] == '-') //此时的i是去掉空格之后第一个字符的下标，用来将指针向后移指向第一个数字。
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + ( s[i] - '0');  //因为是十进制的，所以要乘以10.

    if (s[i] == '.')                       //判断是否存在小数点。若存在，指针向后移。
        i++;
    for (pot = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + ( s [i] - '0');
        pot *= 10.0;
    }                                      //pot用来标记小数点后面的位数，有几位就是10的几次方。

    return sign * val / pot;   
}
int main ()
{
    char s[] = "-234.5";
    // double b ;                         //此处的main函数用来简单验证函数是否是正确的。
    // b = atof( s );
    printf("%lf",atof( s ));              //注意双精度的数字输出要使用%lf

}
