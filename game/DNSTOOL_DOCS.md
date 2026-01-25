# DNSTool — 使用说明与技术文档

## 概览
DNSTool 是一个用于对比和测速 DNS 服务器的轻量 C++ 工具。它通过向指定 DNS 服务器发送 UDP 查询测量 RTT（毫秒），并解析返回的 A/AAAA 记录，此外对解析到的 IPv4 地址尝试 TCP 建连以判断可达性。

主要特性：
- 支持多个域名批量测试
- 自动合并本机系统 DNS（Windows / POSIX）并可选择是否包含 IPv6
- 记录每个目标的最小/平均/最大 RTT 与丢包率，并隐藏 100% 丢包的服务器
- 将运行日志追加到 `dnstool.log`（与可执行文件同目录）
- 支持交互式菜单与命令行模式，支持保存默认配置 `dnstool.conf`

## 快速使用
位置：项目源文件位于 `game/dnstool.cpp`，可直接编译生成 `dnstool.exe`。

命令行示例：
```powershell
g++ -std=c++17 game/dnstool.cpp -o game/dnstool.exe -lws2_32 -liphlpapi
.
game\dnstool.exe                          # 交互模式
game\dnstool.exe -D github.com,baidu.com -s 8.8.8.8,1.1.1.1 -n 5 -t 2000
``` 

选项：
- `-d domain`：只测试单个域名
- `-D domain1,domain2`：多个域名逗号分隔
- `-s ip,ip,...`：指定 DNS 服务器列表（默认内置常见公共 DNS）或传入若干裸 IP 参数
- `-n N`：每个域名对每个服务器发送 N 次探测（默认 3）
- `-t ms`：单次超时毫秒（默认 1500）
- `-6`：包含 IPv6 系统 DNS（默认跳过 IPv6）

交互模式：直接运行 `dnstool.exe` 进入菜单，可以修改域名、DNS 列表、探测次数、超时时间、预设并保存默认配置（写入 `dnstool.conf`）。

日志与配置：
- 日志：`dnstool.log` 位于可执行文件同目录，用于追加每次运行摘要与每个解析条目的详细信息。
- 配置：`dnstool.conf`（同目录）格式为简单的键=值，工具支持 `domains`、`servers`、`probes`、`timeout_ms`、`include_ipv6`。

## 在 VS Code 中（使用 MinGW/MSYS 或 WSL）
- 推荐使用已存在的 g++ 任务（workspace 中的 `C/C++: g++.exe 生成活动文件`）。
- 在 Windows 上编译需链接 `Ws2_32` 与 `Iphlpapi`（用于获取本机 DNS 列表）：
  ```powershell
  g++ -std=c++17 game/dnstool.cpp -o game/dnstool.exe -lws2_32 -liphlpapi
  ```

## 在 Visual Studio 中
- 工程文件已在 `vs_dnstool_project` 下生成，直接打开 `vs_dnstool_project/dnstool.sln` 即可构建。
- 工程以 `game/dnstool.cpp` 为源码（项目中通过 wrapper 引入/包含）。

## 技术要点（快速）
- DNS 查询：直接构造 UDP DNS 报文（简易实现，仅发送 A 类型查询），在返回中解析 A/AAAA 记录。
- 验证：基于返回数据的事务 ID（ID）做简单匹配；超时/ID 不匹配视为失败。
- 可达性检测：对返回的 IPv4 地址尝试非阻塞 TCP 连接（端口 80，超时 800ms）判断是否可达。
- 系统 DNS：Windows 使用 `GetAdaptersAddresses`，POSIX 读取 `/etc/resolv.conf`。

## 已知限制与改进建议
- 目前仅对 A (IPv4) 地址做 TCP 可达性检测；IPv6 地址仅列出但不检测连通性。
- DNS 报文解析为简化实现：不处理 EDNS、截断后的 TCP 重试或 DNSSEC 特性。
- 若要更精确地分析 DNS 结果，可使用现有 DNS 库（例如 c-ares 或 ldns）替代手写解析。
- 可加入并发探测（线程池 / async）以提升对大规模服务器列表的速度。

## 联系与贡献
- 源码：`game/dnstool.cpp`
- 若需我生成 curses/TUI 界面或做并发优化，我可以继续实现。
