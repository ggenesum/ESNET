all: loginpage login test_cookie registerpage register

loginpage: loginpage.c API/html_layout.c
	gcc loginpage.c API/html_layout.c -o cgi/loginpage.cgi -std=c99 -Wall

login: 	login.c API/html_layout.c API/argparse.c API/cookies.c API/error.c sqlite3/sqlite3.c
	gcc  sqlite3/sqlite3.c login.c API/html_layout.c API/argparse.c API/cookies.c API/error.c API/database.c -o cgi/login.cgi -std=c99 -Wall -lpthread -ldl

test_cookie: test_cookie.c API/cookies.c API/html_layout.c
	gcc test_cookie.c API/cookies.c API/html_layout.c -o cgi/test_cookie.cgi -std=c99 -Wall

registerpage: registerpage.c API/html_layout.c
	gcc registerpage.c API/html_layout.c -o cgi/registerpage.cgi -std=c99 -Wall

register: register.c API/html_layout.c API/argparse.c API/cookies.c API/database.c
	gcc register.c API/html_layout.c API/argparse.c API/cookies.c API/database.c -o cgi/register.cgi -std=c99 -Wall -lpthread -ldl
