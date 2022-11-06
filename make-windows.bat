@echo off

set CC=gcc

%CC% versions\windows\dt.c -o "dist\dt.exe"
%CC% versions\windows\dt.c -o "obj\dt.o"

mkdir dist

mkdir "C:\Program Files\deuterium\"
mkdir "C:\Program Files\deuterium\templates"
echo nul>"C:\Program Files\deuterium\config.TOML"
copy "dist\dt.exe" "C:\Program Files\deuterium\dt.exe"
