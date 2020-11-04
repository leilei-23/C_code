//定义了一个将数字转换成字符串的函数

void itoa (int n , char s[])
{
    int i , sign;
    if  ((sign == n) < 0)
        n = -n;
    i = 0;
    do 
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse (s);     //对字符串反向取
}