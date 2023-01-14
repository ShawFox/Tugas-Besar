#ifndef LISTUSER_H_INCLUDED
#define LISTUSER_H_INCLUDED

#include <iostream>
#include <conio.h>
using namespace std;

#include "listFilm.h"

#define firstUser(P) ((P).firstUser)
#define firstChild(P) (P)->child
#define infoUser(P) (P)->infoUser
#define nextUser(P) (P)->nextUser
#define childUser(P) (P)->child

#define nextChild(P) (P)->nextChild
#define infoChild(P) (P)->infoChild

struct userSubcriber{
    int id;
    string nama, alamat, gmail;
    int umur;
};

typedef struct elmUser *adrUser;
typedef struct elmChild *adrChild;

struct elmUser{
    userSubcriber infoUser;
    adrUser nextUser;
    adrChild child;
};

struct elmChild{
    adrFilm infoChild;
    adrChild nextChild;
};

struct listUser{
    adrUser firstUser;
};

void createListUser(listUser &listU);
adrUser createElmUser(userSubcriber info);
adrChild createElmChild(adrFilm dataFilm);
void insertLastChild(adrUser dataUser, adrChild dataChild);
void insertFirstUser(listUser &listU, adrUser dataUser);
void deleteFirstChild(adrUser &dataUserLogin, adrChild &dataDelFilm);
void deleteAfterChild(adrUser &dataUserLogin, adrChild delChild, adrChild &dataDelFilm);
adrUser cariDataUser(listUser listU, string gmail);
void showAllChild(adrUser dataUserLogin);
adrChild cekRelasiChild(adrUser dataUserLogin, string judul);
int countChild(adrChild dataChild);

#endif // LISTUSER_H_INCLUDED
