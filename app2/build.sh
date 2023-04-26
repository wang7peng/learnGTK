#!/bin/bash
date +"%Y-%m-%d"
echo "-----------------------"

echo "-0-  清理环境"
xmake f -c

echo "-1-  配置输出目录" # 不写的话自动增加 build 目录
xmake f -o ./bin/ 

echo "-2-  开始生成可执行程序"
xmake

echo "收尾: 自动运行一次"
xmake run