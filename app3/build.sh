#!/bin/bash
date +"%Y-%m-%d"
echo "-----------------------"

echo "-0-  清理环境"
xmake f -c
sudo rm cmd/resource.c

echo "-1-  配置输出目录" # 不写的话自动增加 build 目录
xmake f -o ./bin/ 

echo "-2-  创建 resource.c"
# 确认 xmllint 命令已经装上, sudo apt install libxml2* -y
sudo su - <<EOF
cd /home/learnGTK/app3/cmd/
glib-compile-resources app3.gresource.xml --target=resource.c --generate-source
EOF

echo "-3-  开始生成可执行程序"
xmake

echo "收尾: 自动运行一次"
xmake run