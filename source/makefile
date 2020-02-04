all: loginpage login test_cookie registerpage error

loginpage: loginpage.c API/html_layout.c
	gcc loginpage.c API/html_layout.c -o cgi/loginpage.cgi -std=c99 -Wall

login: 	login.c API/html_layout.c API/argparse.c API/cookies.c
	gcc login.c API/html_layout.c API/argparse.c API/cookies.c -o cgi/login.cgi -std=c99 -Wall

test_cookie: test_cookie.c API/cookies.c API/html_layout.c
	gcc test_cookie.c API/cookies.c API/html_layout.c -o cgi/test_cookie.cgi -std=c99 -Wall

registerpage: registerpage.c API/html_layout.c
	gcc registerpage.c API/html_layout.c -o cgi/registerpage.cgi -std=c99 -Wall

error: error.c  API/html_layout.c
	gcc error.c API/html_layout.c -o cgi/error.cgi -std=c99 -Wall
