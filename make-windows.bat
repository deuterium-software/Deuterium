@echo off

set CC=gcc

%CC% windows\dt.c -o "dist\dt.exe"
%CC% windows\dt.c -o "obj\dt.o"

mkdir "C:\Program Files\deuterium\"
mkdir "C:\Program Files\deuterium\templates"
echo nul>"C:\Program Files\deuterium\config"
copy "dist\dt.exe" "C:\Program Files\deuterium\dt.exe"
