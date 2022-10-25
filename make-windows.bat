@echo off

set CC=gcc

%CC% windows\dt.c -o "dist\dt.exe"

mkdir "C:\Program Files\deuterium\"
copy "dist\dt.exe" "C:\Program Files\dt.exe"