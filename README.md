# doudoulove

一个基于 Qt 的桌面小应用，用信号与槽（signal/slot）实现了多对话框交互的练手项目。

## 功能

- 主窗口显示 "Dou Dou Love You ❤"
- 三个对话框依次弹出，通过信号与槽串联交互
- 爱豆 → 必须爱，不爱不行 😄

## 技术点

- Qt6 / Qt5 双版本 CMake 构建
- QMainWindow + QDialog 窗口组合
- 自定义信号（`love` / `disLove`）与槽函数
- `Qt::ApplicationModal` 全局模态
- `Qt::WA_DeleteOnClose` 自动内存管理
- 重写 `closeEvent` 控制关闭行为

## 构建 & 运行

```bash
mkdir build && cd build
cmake ..
cmake --build .
./doudoulove
```

## 文件结构

```
├── CMakeLists.txt      # CMake 构建配置
├── main.cpp            # 程序入口
├── mainwindow.h/cpp/ui # 主窗口
├── dialog1.h/cpp/ui    # 第一关：爱不爱豆？
├── dialog2.h/cpp/ui    # 第二关：认真考虑一下？
├── dialog3.h/cpp/ui    # 第三关：求求你了爱爱豆吧
└── dialog1.qrc         # 资源文件
```

## 环境要求

- Qt 5.15+ 或 Qt 6.x
- CMake 3.16+
- C++17 编译器
