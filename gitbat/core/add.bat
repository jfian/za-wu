@echo off
title = GitBat
chcp 65001
cls
set /p name=仓库名：
cd ..
if  exist %name% goto YES
if not exist %name% goto NO

:YES
cd %name%
echo.|git add .
git commit -m"HELLO~"
cd ..
call Run.bat
exit

:NO
echo 仓库不存在
pause
call Run.bat
exit