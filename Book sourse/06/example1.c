/* example1.c */
#include <stdio.h>
int main()
{
  int i;
  int tol;
  tol = 0;
  for (i=1; i<=10; i++)
    tol += i;
  printf("1+2+...+10 = %d\n", tol);
  return 0;
}
