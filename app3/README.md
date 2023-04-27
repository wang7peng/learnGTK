## GtkBuilder template

特性

1 增加 标题栏

目录结构

```
.
├── assets        # 资产
│   └── xxx.ui    # 示例ui
├── cmd           # C文件
│   ├── main.c
│   └── ...
├── include       # 头文件
│   └── example.h
├── ... 
└── xmake.lua     # xmake 构建
```
注：真正的 UI 文件在其他目录, 可以把这个 ui 先复制过去。

学习方法：
先原样复制，运行起来后，将 exampleapp 名字换成 recordapp ，看哪些地方受影响。


## 心得

步骤学会了，主要是对文件的位置做处理，如绝对路径的配置，如果将 ui的路径做成可配的，那这个工作重点又变成了字符串的拼接和文件的读写上面来了。

权限问题。mv、cp、vim 都要 root 权限。