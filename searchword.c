#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 100
#define SIZE 11

//定义结构体
struct key
{
    char * word;
    int count;
};

struct key keytab[] = 
{
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* …… */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int getword (char * word, int lim);            //声明函数
int binsearch(char * word, struct key tab[], int size);
void print (struct key tab[], int size);

int main ()
{
    char * word[MAXSIZE];
    int w, n;

    if (w = getword (word,MAXSIZE) != EOF)
        if (isalpha(word[0]))
            if ( (n = binsearch(word, keytab, SIZE) >= 0) )                   //此处SIZE是指结构体内字符的个数。
                keytab[n].count ++;

    print(keytab, SIZE);



}

//定义print函数

void print(struct key tab[],int size)
{
    int i;
    for (i = 0;i < size;i++)
        if (keytab[i].count > 0)
            printf("%4d %s\n",keytab[i].count,keytab[i].word);
}

//定义binsearch函数。

int strcmp1 (char * s , char * t);
int binsearch(char * word ,struct key tab[], int size)
{
    int cond;
    int low, mid, high;

    low = 0;
    high = size - 1;
    
    while (low <= high)
    {
        mid =(low + high)/2;
        if ((cond = strcmp1(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;      
    }
    return -1;
}

//定义strcmp函数

int strcmp1 (char * s , char * t)
{
 for ( ;*s == *t;s++, t++ )
 {
    if (*s == '\0')
        return 0;
    else
        return *s - *t;
    
 }
}
//定义getword函数。

int getword (char * word, int lim)
{
    int c, getch(void);
    char * w = word;
    void ungetch(int ch);

    while (isspace(c = getch()))
        ;
    if (c != EOF)
       *w++ = c;
    if (! isalpha (c))
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (! isalnum(*w = getch()))
        {   
            ungetch(*w);
            break;
        }
    *w = '\0';

    return word[0];
}


//定义函数getch 和函数 ungetch。
#define BUFSIZE 100

int bufp;
char buf[BUFSIZE];

int getch (void)
{
    return (bufp > 0) ? buf [--bufp] : getchar();
}

void ungetch(int ch)
{
    if (bufp >= BUFSIZE)
        printf ("ungetch : too many characters\n");
    else
        buf [bufp ++] = ch;
    
}
