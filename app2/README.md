## A trivial app

GTK 多文件开发。采用 xmake 配置，不使用 cmake 和 Makefile，太难了。

目录结构

```
.
├── cmd           # C文件
│   ├── main.c
│   └── ...
├── include       # 头文件
│   └── example.h
├── ... 
└── xmake.lua     # xmake 构建
```

构建方法看 xmake，运行时直接 `sh build.sh` 

## Tips

头文件里定义的时候加 G_BEGIN_DECLS、G_END_DECLS