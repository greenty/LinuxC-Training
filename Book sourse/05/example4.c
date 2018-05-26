/* example4.c */
#include <stdio.h>
int main()
{
	int i;
	int j;
	int x=0;
	for(i=0;i<100000;i++)
	{
		for(j=i;j>0;j--)
		{
			x+=j;
		}
	}
	return 0;
}
