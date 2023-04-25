前面 4个 demo 是从 widget 开始的，在控件内。

从这个开始，用 `GtkApplication` 写。讲控件的布局从业务逻辑代码中 separate 出来。
一般 ui 文件放在 /usr/share/ 目录

advantages: 调整界面不用重新编译程序，UI可以用图形界面编辑。

---

日志 暂时用 g_print() 函数，点击控件后将信息显示在后台终端

## 常见问题处理

1 确认版本

```bash
pkg-config --version
pkg-config --modversion gtk+-3.0
pkg-config --list-all | grep gtk
```

2 warning: ‘activate’ defined but not used

解决：函数前面加上 `G_GNUC_UNUSED` , 该类型属性的本质

```c
#define G_GNUC_UNUSED __attribute__((__unused__))
```

> 关键字 `__attribute__` 也可以对结构体 (struct) 或共用体（union）进行属性设置。大致有六个参数值可以被设定，即：aligned, packed, transparent_union, unused, deprecated和 may_alias。