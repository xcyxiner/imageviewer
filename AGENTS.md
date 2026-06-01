# agents.md — 项目规则与环境说明

目的
- 作为团队与自动化代理（AI agents）使用的全局规则文件，说明本仓库的系统环境、编译约定与推荐工具。

环境 (当前)
- 操作系统：Ubuntu 24
- C++ 标准：C++17
- Qt：使用系统安装的 Qt 6.4（无需在仓库内编译 Qt）

编译与构建（建议）
- 推荐使用 CMake 构建系统。
- 基本构建步骤：
  ```bash
  mkdir -p build && cd build
  cmake -DCMAKE_BUILD_TYPE=Release ..
  cmake --build . -- -j$(nproc)
  ```

CMake 最小示例（添加到项目根 CMakeLists.txt 或供参考）：
```cmake
cmake_minimum_required(VERSION 3.16)
project(ImageViewer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
add_executable(imageviewer src/main.cpp ...)
target_link_libraries(imageviewer PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
```

若需将 Qt 指向非标准位置，可额外提供 toolchain.cmake 或在 CI 中传入 -DQt6_DIR=...。

代码约定（建议）
- 使用 C++17 特性，避免依赖更高标准特性。
- 使用一致的代码风格（建议添加 .clang-format），并在 PR 合并前运行格式化。
- 建议使用 clang-tidy（或等效工具）做静态检查，CI 中开启常用检查项。

CI / 自动化 说明
- CI 环境应在 Ubuntu 24 上构建并使用系统 Qt6.4（或通过 apt 安装 qt6 相关包）。
- CI 步骤示例：安装依赖 -> cmake 配置 -> 构建 -> 运行单元测试 -> 静态分析 -> 打包。

AI 代理（agents）交互规范
- 构建/运行相关任务应遵循本文件中列出的系统与版本约束（Ubuntu 24, C++17, Qt6.4）。
- 若需要新增依赖或更改基础环境，先在 issue/PR 中讨论并更新本文件。
- 自动化代理在修改构建或环境配置时，应同时提交可重复的构建步骤（如 CMake 变量或 toolchain 文件）。

附录：快速检查命令
- 检查 Qt 版本：
  ```bash
  qmake -v || qtpaths --plugin-info
  # 或查找 pkg-config: pkg-config --modversion Qt6Gui
  ```
- 检查编译器与标准：
  ```bash
  g++ --version
  # 在 CMake 输出中确认 CMAKE_CXX_STANDARD
  ```

---
说明：如需机器可读的配置（toolchain.cmake、ai-config.json、.clang-format、.clang-tidy），请选择要生成的具体文件，或允许同时生成文档 + 简短 JSON。