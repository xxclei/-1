@echo off
rem 运行 Bison 生成解析器
bison --yacc -dv zzh.y

rem 运行 Flex 生成词法分析器
flex zzh.l

rem 编译生成的 C 文件
gcc -o zzh y.tab.c lex.yy.c

rem 提示用户输入 demo.txt 文件路径
set /p inputFile=please input the program file e.g. demo.txt: 

rem 运行生成的可执行文件
zzh.exe %inputFile%

rem 运行 Python 脚本
python ToTree.py

pause