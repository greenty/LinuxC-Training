/* example16.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>					/* 包含相关函数所在头文件 */
#include <sys/time.h>
int main()
{
  struct timeval time_val;				/* 定义timeval结构体变量，保存时间信息 */
  struct timezone time_zone; 			/* 定义timezone结构体变量，保存时区信息 */
  gettimeofday(&time_val, &time_zone);			/* 获取当前的时间 */
  printf("tv_sec : %ld\n", time_val.tv_sec);			/* 输出秒数 */
  printf("tv_usec : %ld\n", time_val.tv_usec); 		/* 输出微秒数 */
  printf("tz_minuteswest : %d\n", 			/* 输出和格林尼治（Greenwich）时间相差的分钟数 */
        time_zone.tz_minuteswest);
  printf("tz_dsttime : %d\n", time_zone.tz_dsttime); 	/* 输出日光节约时间的状态 */
  return 0;
}
