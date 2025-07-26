# GameHalfBot - 奇迹手游自动化辅助工具

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows-blue.svg)](https://www.microsoft.com/windows)
[![Language](https://img.shields.io/badge/language-C++-orange.svg)](https://isocpp.org/)
[![Framework](https://img.shields.io/badge/framework-MFC-red.svg)](https://docs.microsoft.com/en-us/cpp/mfc/)

## 🎮 项目简介

GameHalfBot 是一个专为奇迹类手游设计的自动化辅助工具，采用C++/MFC开发，支持多种模拟器平台。该工具提供自动挂机、技能管理、副本自动化等功能，帮助玩家提升游戏体验。

## ✨ 主要功能

### 🎯 核心功能
- **自动挂机系统** - 自动打怪、拾取、复活
- **技能自动化** - 智能技能释放和目标选择
- **副本自动化** - 血色城堡、恶魔广场等副本
- **多开支持** - 支持多模拟器和多角色管理
- **游戏增强** - 经验翻倍、伤害翻倍等功能

### 🛠️ 技术特性
- **DLL注入技术** - 深度集成游戏进程
- **Hook技术** - 拦截和修改游戏数据
- **内存操作** - 直接读写游戏内存
- **自定义协议** - TCP通信和消息队列
- **配置管理** - INI文件存储和加密

## 🎯 支持的游戏

- **天使神谕** (Angel Oracle)
- **天使之战** (Angel's War)  
- **永恒联盟** (Eternal Alliance)
- 其他奇迹类手游

## 🖥️ 支持的模拟器

- **雷电模拟器** (Leidian)
- **夜神模拟器** (Nox)
- **网易模拟器** (NetEase)
- **Mumu12模拟器** (Mumu12)
- **联想模拟器** (Lenovo)

## 📋 系统要求

### 最低配置
- **操作系统**: Windows 7/8/10/11
- **内存**: 4GB RAM
- **存储**: 500MB 可用空间
- **网络**: 稳定的网络连接

### 推荐配置
- **操作系统**: Windows 10/11
- **内存**: 8GB RAM
- **处理器**: Intel i5 或 AMD Ryzen 5
- **存储**: 1GB 可用空间

## 🚀 快速开始

### 1. 下载和安装
```bash
# 克隆仓库
git clone https://github.com/yourusername/GameHalfBot.git
cd GameHalfBot

# 或者直接下载发布版本
# 从 Releases 页面下载最新版本
```

### 2. 运行程序
```bash
# 进入bin目录
cd bin

# 运行主程序
GameBot_release.exe
```

### 3. 基本配置
1. 选择游戏版本
2. 选择模拟器类型
3. 配置游戏账号
4. 设置挂机参数

## 📁 项目结构

```
GameHalfBot/
├── GameBot/                 # 主程序源码
│   ├── Config/             # 配置管理模块
│   ├── Dlgs/               # 对话框界面
│   ├── Global/             # 全局定义和枚举
│   ├── Protocol/           # 网络协议处理
│   ├── Struct/             # 数据结构定义
│   ├── Util/               # 工具类
│   └── FunctionHelper/     # 功能助手
├── Proxy/                  # DLL注入模块
├── bin/                    # 编译输出目录
│   ├── GameConfig/         # 游戏配置文件
│   └── GameBot_release.exe # 主程序可执行文件
└── Obj/                    # 编译中间文件
```

## 🔧 开发环境

### 必需工具
- **Visual Studio 2008** 或更高版本
- **Windows SDK**
- **MFC库**

### 编译步骤
1. 打开 `GameHalfBot_ModifySpeed.sln`
2. 选择 Release 配置
3. 编译解决方案
4. 运行程序

## 📖 使用说明

### 基本操作
1. **启动程序** - 运行 `GameBot_release.exe`
2. **选择游戏** - 在版本选择框中选择对应游戏
3. **连接模拟器** - 选择并连接目标模拟器
4. **登录账号** - 输入游戏账号信息
5. **开始挂机** - 点击开始按钮启动自动化

### 高级功能
- **技能配置** - 在技能设置中配置技能释放顺序
- **挂机点设置** - 设置自动挂机的位置坐标
- **副本设置** - 配置副本自动化的时间和参数
- **全局快捷键** - 使用快捷键快速控制程序

## ⚙️ 配置说明

### 主要配置文件
- `bin/GameConfig/mainGameCfg.dat` - 主配置文件
- `bin/GameConfig/Global.ini` - 全局设置
- `bin/GameConfig/platform.cfg` - 平台配置

### 配置参数说明
```ini
[Player1]
SkillList=1,2,3,4          # 技能列表
SkillSendInterval=1000     # 技能释放间隔(毫秒)
IsAutoHungUp=1             # 是否自动挂机
AutoHungUpPointX=100       # 挂机点X坐标
AutoHungUpPointY=200       # 挂机点Y坐标
```

## 🔒 安全说明

### 使用注意事项
- 本工具仅供学习和研究使用
- 请遵守游戏服务条款
- 使用风险由用户自行承担
- 建议在测试环境中使用

### 免责声明
本项目仅用于技术研究和学习目的，使用者需要自行承担使用风险，开发者不承担任何法律责任。

## 🤝 贡献指南

### 如何贡献
1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

### 开发规范
- 遵循现有的代码风格
- 添加适当的注释
- 确保代码可以正常编译
- 进行充分的测试

## 📝 更新日志

### v0.30 (最新版本)
- ✨ 新增血色城堡自动化
- ✨ 新增恶魔广场自动化
- ✨ 支持多模拟器同时运行
- 🐛 修复技能释放间隔问题
- 🐛 优化内存使用效率

### v0.29
- ✨ 新增全局快捷键支持
- ✨ 新增实时坐标显示
- 🐛 修复自动反击功能

### v0.28
- ✨ 新增自动复活功能
- ✨ 新增自动拾取功能
- 🐛 修复连接稳定性问题

## 📞 联系方式

- **项目主页**: [GitHub Repository](https://github.com/yourusername/GameHalfBot)
- **问题反馈**: [Issues](https://github.com/yourusername/GameHalfBot/issues)
- **讨论交流**: [Discussions](https://github.com/yourusername/GameHalfBot/discussions)

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 🙏 致谢

感谢所有为这个项目做出贡献的开发者，以及提供技术支持的社区成员。

---

**⭐ 如果这个项目对您有帮助，请给我们一个星标！** 