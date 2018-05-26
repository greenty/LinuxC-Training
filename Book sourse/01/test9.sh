#!/bin/bash
sum()							#定义函数
{
SUM=`expr $1 + $2` 				#求和
echo $SUM						#输出计算结果
}
echo -n "请输入两个数字："
read X Y							#读入操作数
echo -n "$X + $Y = "
sum $X $Y						#调用函数
