@echo off

set CC=gcc

%CC% dt.c -o "dt.exe"

mkdir "C:\Program Files\deuterium\"
copy "dt.exe" "C:\Program Files\dt.exe"
