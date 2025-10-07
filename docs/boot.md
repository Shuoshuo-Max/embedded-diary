\# STM32F103xB 启动流程分析



\## 1. 启动文件结构

\- 文件位置：`startup\_stm32f103xb.s`

\- 文件类型：ARM汇编文件

\- 主要功能：定义中断向量表、初始化基础硬件环境



\## 2. Reset\_Handler 流程

1\. \*\*初始化栈指针(SP)\*\*：从向量表第一个条目加载初始栈指针值## 3. 关键函数说明

\- `SystemInit()`：位于system\_stm32f1xx.c

\- 设置时钟树

\- 配置Flash延迟

\- 初始化基本外设时钟



\- `\_\_libc\_init\_array()`：

\- 调用C++全局构造函数（如果使用C++）

\- 初始化C运行时环境



\## 4. 内存布局（参考链接脚本）

\- Flash起始地址：0x08000000

\- RAM起始地址：0x20000000

\- 栈顶位置：`\_estack`（通常位于RAM末尾）



\## 5. Keil工程注意事项

1\. 需确保启动文件与芯片型号匹配

2\. 在Options for Target → Debug中：

\- 勾选"Load Application at Startup"

\- 设置初始PC为Reset\_Handler

3\. 分散加载文件需与链接脚本对应

