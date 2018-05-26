/* example2.c */
#include <stdio.h>
int tol;
void printinfo()
{
  printf("1+2+...+10 = ");
}
int main()
{
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  int i;
  tol = 0;
  for (i=0; i<10; i++)
    tol += a[i];
  printinfo();
  printf("%d\n", tol);
  return 0;
}
