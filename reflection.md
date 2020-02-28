# 测试fork功能遇到的问题
1. pid\_t 无法识别类型,fork 无法识别
2. 缺少库　#include <stlib.h> #include <unistd.h>
