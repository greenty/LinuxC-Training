#!/bin/bash
COUNTER=0
while [ $COUNTER -lt 3 ]
do
  COUNTER=`expr $COUNTER + 1`	#累加
  echo $COUNTER					#输出结果
done
