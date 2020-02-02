all: index.exe login.exe

index.exe: index.c API/html_layout.c
	c:/gcc/bin/gcc.exe index.c API/html_layout.c -o index.exe -std=c99 -Wall

login.exe: 	login.c API/html_layout.c
	c:/gcc/bin/gcc.exe login.c API/html_layout.c -o login.exe -std=c99 -Wall
