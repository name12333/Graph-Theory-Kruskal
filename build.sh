#!/bin/bash

# 图论项目构建脚本

echo "正在构建图论项目..."

# 创建构建目录
if [ ! -d "build" ]; then
    mkdir build
fi

# 进入构建目录
cd build

# 运行CMake
cmake ..

# 编译项目
make

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "编译成功！"
    echo "运行程序..."
    ./GraphTheory
else
    echo "编译失败！请检查代码。"
    exit 1
fi

# 返回上级目录
cd ..

echo "构建完成！"
echo "请在浏览器中打开 web/visualize_new.html 查看可视化效果"
