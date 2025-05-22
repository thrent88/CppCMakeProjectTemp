# CppCMakeProjectTemp

自用型C++的CMAKE的项目

## 异常退出

获取地址后查找函数报错位置

1. 确保有对应的PDB文件
2. 打开`windbg`加载`exe`
3. 加载对应的pdb符号
4. 输入`ln 偏移地址`获取堆栈信息
