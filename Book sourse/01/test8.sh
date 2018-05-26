#!/bin/bash
SUM=0
for X in `seq 1 10`					#循环列表为1 2 3 4 5 6 7 8 9 10
do
  if [ `expr $X % 2` = "0" ]				#测试是否为偶数
  then
    continue						#跳出本次循环
  fi
  echo $X
  SUM=`expr $SUM + $X`			#累加
done
echo "Sum:$SUM"
