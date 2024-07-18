//Create a small C program and compile it using gcc compiler. Verify the output of the C program after execution.

#include<stdio.h>
int main()
{  int i,n=5,sum=0;
    for(i=1;i<=n;i++)
      sum+=i;
    printf("The sum of numbers from 1 to %d is %d\n.",n,sum);
}
