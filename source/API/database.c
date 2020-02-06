#include "../sqlite3/sqlite3.h"
#include <stdio.h>
#include <time.h>
#include "error.h"

#define DEBUG 1

struct login_cookie
{
    char *auth_token;
};

sqlite3* init_sqldb(){
    sqlite3 *db;
    //sqlite3_stmt *res;

    int rc = sqlite3_open("../DB/ESNetDB.db", &db);

    if (rc != SQLITE_OK) {
        errpage("Cannot open database",DEBUG);
        sqlite3_close(db);
        return NULL;
    }
    return db;
}

void close_sqldb(sqlite3* db){
    sqlite3_close(db);
}

 int __GetUserId(char* username, sqlite3* db){
    sqlite3_stmt *res;
    char *sql = "SELECT Id FROM User WHERE Username = ?1;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
        sqlite3_bind_text(res, 1, username, -1, sqlite3_free);
    else
        return -1;

    int step = sqlite3_step(res);

    if(step == SQLITE_ROW)
        return sqlite3_column_int(res, 0);
    else
        return -1;
}

 int __Username_exists(char* Username,sqlite3* db){
    sqlite3_stmt *res;
    char *sql = "SELECT Id FROM User WHERE Username = ?1;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
        sqlite3_bind_text(res, 1, Username, -1, sqlite3_free);
    else
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));

    int step = sqlite3_step(res);

    if(step == SQLITE_ROW)
        return 1;
    return 0;
}

char* HashPassword(char* pass){return pass;};

int Register(char* username, char* email, char* pass, sqlite3 *db){
    sqlite3_stmt *res;

    char* HPass = HashPassword(pass);
    if(!__Username_exists(username,db)){
        char *sql = "INSERT INTO User(Username,HPass,Email) VALUES (?1,?2,?3);";

        int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

        if (rc == SQLITE_OK){
            sqlite3_bind_text(res, 1, username, -1, sqlite3_free);
            sqlite3_bind_text(res, 2, HPass, -1, sqlite3_free);
            sqlite3_bind_text(res, 3, email, -1, sqlite3_free);
        }
        else
            fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));

        int step = sqlite3_step(res);

        if(step == SQLITE_DONE)
            return sqlite3_last_insert_rowid(db);
    }
    return -1;
}

int Auhtenticate(char* username, char* pass, struct login_cookie login_cookie, sqlite3 *db){
    sqlite3_stmt *res;
    if(login_cookie.auth_token != NULL){
        char *sql = "SELECT UserId FROM Token WHERE C1 = ?1 OR C2 = ?1";

        int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

        if (rc == SQLITE_OK){
            sqlite3_bind_text(res, 1, login_cookie.auth_token, -1, NULL);
        }
        else
            errpage((char *)sqlite3_errmsg(db),DEBUG);

        int step = sqlite3_step(res);

        if (step == SQLITE_ROW) {
            sqlite3_finalize(res);
            return sqlite3_column_int(res, 0);
        }
    }
    else {
        char *sql = "SELECT Id FROM User WHERE Username = ?1 AND HPass = ?2;";

        char* HPass = HashPassword(pass);

        int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

        if (rc == SQLITE_OK){
            sqlite3_bind_text(res, 1, username, -1, NULL);
            sqlite3_bind_text(res, 2, HPass, -1, NULL);
        }
        else
          errpage((char *)sqlite3_errmsg(db),DEBUG);

        int step = sqlite3_step(res);

        if (step == SQLITE_ROW){
            sqlite3_finalize(res);
            return sqlite3_column_int(res, 0);
        }
    }

    return -1;
}

/*int main(void) {
    sqlite3* db = init_sqldb();
    int a =Register("NomDeOuf","NomDeOuf@gmail.com","Mdp2ouf" ,db);
    printf("%d\n", a);
    printf("%d\n", __GetUserId("NomDeOuf",db));

    close_sqldb(db);
    return 0;
}*/
