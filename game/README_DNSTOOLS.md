dnstool - DNS 测速工具

简介
- 本工具用于对多个 DNS 服务器进行 UDP 查询延迟测量，解析返回的 A/AAAA 记录，并检测返回 A 记录的 TCP 80 可达性。
- 输出控制台表格并将详细日志写入 `dnstool.log`（可执行文件所在目录）。

快速开始
1) 编译（Windows 下示例）
```powershell
C:\msys64\ucrt64\bin\g++.exe -std=c++17 -O2 d:\CODE\YbtCode\game\dnstool.cpp -o d:\CODE\YbtCode\game\dnstool.exe -lws2_32 -liphlpapi
```
2) 运行：
- 交互模式（默认，直接运行可进入菜单）
```
d:\CODE\YbtCode\game\dnstool.exe
```
- 参数模式（示例）：
```
d:\CODE\YbtCode\game\dnstool.exe -D www.example.com,github.com -s 8.8.8.8,1.1.1.1 -n 3 -t 1500
```

参数说明
- `-d domain` : 指定单个域名（等同于 `-D domain`）
- `-D domain1,domain2` : 以逗号分隔的域名列表（默认： `www.example.com,www.360.cn,github.com`）
- `-s ip,ip...` : 以逗号分隔的 DNS 服务器 IP 列表（默认包含系统 DNS + 常见公共 DNS）
- `-n N` : 每个服务器对每个域名的探测次数（默认 3）
- `-t MS` : 查询超时（毫秒，默认 1500）
- `-6` : 包含系统配置的 IPv6 DNS（默认不包含）

配置保存
- 程序会在可执行文件所在目录查找 `dnstool.conf`，若存在会自动加载为默认设置。
- 在交互界面可通过 `s` 保存当前设置为默认（生成 `dnstool.conf`）。

交互界面说明
- 直接运行程序会进入交互菜单，可在菜单中设置域名、DNS 列表、探测次数、超时并开始测速。
- 菜单中选择 `开始测速` 将执行当前配置的测速并输出结果。

输出说明
- 控制台输出每个可见（非 100% 丢包）DNS 服务器对每个域名的统计：Server | Host | Loss% | Min | Avg | Max | Reachable/TotalIPs | ReturnedIPs
- 程序在同目录生成 `dnstool.log`，包含每次运行的详细记录。

示例：
- 以交互模式运行并使用默认设置进行测速。
- 使用参数模式快速脚本化运行。

如需增加功能（并行探测、HTTPS 页面检测、CSV 导出等），请提出需求。
