#ifndef DB
#define DB

#include "../sqlite3/sqlite3.h"
void init_sqldb(sqlite3* db);
void close_sqldb(sqlite3* db);


 int __GetUserId(char* username, sqlite3* db);
 int __Username_exists(char* Username,sqlite3* db);
//char* HashPassword(char* pass);
int Register(char* username, char* email, char* pass, sqlite3 *db);
int Auhtenticate(char* username, char* pass, struct login_cookie login_cookie, sqlite3 *db);

#endif
