#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>

#define MAX 16

void prepare(void);
void welcome(void);
void printmenu(void);
long sum(long*);
void warning(void);
void dowork(long*);

int main()
{
    long data[MAX];

    prepare();
    welcome();
    dowork(data);
    return 0;
}

void welcome()
{
    puts("Hello, pwners!");
    printf("I hear that your math score is bad so give me %d number, i'll sum it up for you :)\n", MAX);
}

void printmenu()
{
    puts("1. write");
    puts("2. read");
    puts("3. get sum and exit");
}

long sum(long *data)
{
    long a = 0;
    for (int i=0; i<MAX; a += data[i++]);
    return a;
}

void dowork(long *data)
{
    long tmp1 = 0, tmp2 = 0;
    int tmp3;
    
    while (1)
    {
        printmenu();
        printf("Your choice: ");
        scanf("%d", &tmp3);
        
        switch (tmp3)
        {
            case 1:
                printf("Number: ");
                scanf("%ld", &tmp1);
        
                while (1)
                {
                    printf("Index: ");
                    scanf("%ld", &tmp2);
                    if (tmp2 < MAX) break;
                    else 
                    {
                        puts("Don't mess with me!");
                        exit(-1);
                    }
                }
                data[tmp2] = tmp1;
                break;
            case 2:
                while (1)
                {
                    warning();
                    scanf("%ld", &tmp1);
                    if (tmp1 < MAX) break;
                    else
                    {
                        puts("Don't mess with me!");
                        exit(-1);
                    }
                }
                printf("%ld\n", data[tmp1]);
                break;
            case 3:
                printf("Here is your sum: %ld\n", sum(data));
                goto endgame;
            default:
                puts("Don't mess with me!");
                exit(-1);
        }
    }
    
endgame:
    puts("Goodbye!");
}

void prepare()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
}

void warning()
{
    // Do you think typing printf is boring? Just try to save some time
    int (*p)(char*, ...) = (int (*)(char*, ...))&printf;
    
    p("Don't mess with me or i'll kick your ass!\n");
    p("Index: ");
}
