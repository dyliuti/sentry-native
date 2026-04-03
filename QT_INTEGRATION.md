# Sentry SDK for Qt - 编译指南

## 当前状态

### ✅ Windows 编译完成
- 位置：`output/windows/`
- 文件：
  - `include/sentry.h` - 头文件
  - `lib/sentry.lib` - 静态库
  - `bin/sentry.dll` - 动态库
  - `exe/crashpad_handler.exe` - 崩溃处理程序

### ⏳ macOS 编译（需在 Mac 上执行）

## macOS 编译步骤

在 Mac 上执行：

```bash
cd /path/to/sentry-native
bash build_macos.sh
```

编译完成后会生成：
- `output/macos/include/sentry.h`
- `output/macos/lib/libsentry.a`
- `output/macos/bin/libsentry.dylib`

## Qt 集成方式

### Windows 项目配置
```cmake
# CMakeLists.txt
target_include_directories(your_app PRIVATE output/windows/include)
target_link_libraries(your_app PRIVATE output/windows/lib/sentry.lib)
# 运行时需要 sentry.dll
```

### macOS 项目配置
```cmake
# CMakeLists.txt
target_include_directories(your_app PRIVATE output/macos/include)
target_link_libraries(your_app PRIVATE output/macos/lib/libsentry.a)
```

## 版本信息
- Sentry SDK: 0.13.4
- Windows: MSVC 19.42, Visual Studio 2022
- macOS: Universal Binary (arm64 + x86_64)
