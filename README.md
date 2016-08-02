# 照片换底工具 
基于opencv, C++
#依赖: 
opencv2
#使用:
  首先编译huandi.cpp,
  ```
  g++ huandi.cpp -o huandi `pkg-config opencv --cflags --libs`
  ```
  生成可执行文件
  将需要换底的照片放置在与可执行文件同一个目录，运行可执行文件生成`export.jpg` 即为换底完成的照片

#设置：
  默认是将白底换为红底，如果要改变可以稍微修改下`fixed`函数和`changeColor`函数。So easy
