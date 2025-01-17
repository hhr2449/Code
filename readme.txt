本文件夹的设置：
1.tasks.json
  "args": [
                "-fdiagnostics-color=always",
                "-g",
                "*.cpp",//*.cpp代表当前目录下的所有cpp文件(实现多文件编译)
                "-o",
                "${fileDirname}\\a.exe"//输出exe文件名为a.exe
            ],
2.多文件的运行要从右上角的图标处进行，不能使用F5,F6（不知道为什么）
3.编码设置为uft8，
setting.json增加
 // 设置终端的参数，编码格式等//这里再修改终端的编码格式为utf-8
    "terminal.integrated.profiles.windows": {
        "Command Prompt": {
            "path": "C:\\Windows\\System32\\cmd.exe",
            "args": ["-NoExit", "/K", "chcp 65001"]
        },
        "PowerShell": {
            "source": "PowerShell",
            "args": ["-NoExit", "/C", "chcp 65001"]
        }
    },
    "terminal.integrated.defaultProfile.windows": "PowerShell",   //使用PowerShell 或者Command Prompt作为终端
    来改变终端的编码格式为utf8