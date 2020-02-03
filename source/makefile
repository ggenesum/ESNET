all: loginpage login test_cookie

loginpage: loginpage.c API/html_layout.c
	gcc loginpage.c API/html_layout.c -o cgi/loginpage.cgi -std=c99 -Wall

login: 	login.c API/html_layout.c API/argparse.c API/cookies.c
	gcc login.c API/html_layout.c API/argparse.c API/cookies.c -o cgi/login.cgi -std=c99 -Wall

test_cookie: test_cookie.c API/cookies.c API/html_layout.c
	gcc test_cookie.c API/cookies.c API/html_layout.c -o cgi/test_cookie.cgi -std=c99 -Wall
