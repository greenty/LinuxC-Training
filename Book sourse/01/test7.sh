#!/bin/bash
while :
do
  echo -n "请输入一个数字："
  read IN							#读入数字
  case $IN in
  1|2|3)						#对1~3执行相同操作
    echo "数字在1到3之间。"
    ;;
  *)
    echo "数字大于三，程序退出。"
    break						#跳出整个循环
    ;;
  esac
done
