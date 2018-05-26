/* exampe41.c */
#include <stdio.h>
enum week						/* 定义一个枚举类型 */
{
  SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};
int main()
{
  enum week x, y; 					/* 定义两个枚举变量 */
  x = TUESDAY;					/* 枚举常量TUESDAY的值为2 */
  y = THURSDAY; 					/* 枚举常量THURSDAY的值为4 */
  int z=6;
  printf ("x = %d\ny = %d\nz = %d\n",x,y,z);		/* 输出枚举变量和整型变量的值 */
  return 0;
}
