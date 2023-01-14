#ifndef LISTFILM_H_INCLUDED
#define LISTFILM_H_INCLUDED

#include <iostream>
#include <conio.h>
using namespace std;

#define firstFilm(P) ((P).firstFilm)
#define nextFilm(P) (P)->nextFilm
#define infoFilm(P) (P)->infoFilm

struct filmNetflix{
    int id;
    string judul, durasi, desc, studio;
    int tahunRilis;
};

typedef struct elmFilm *adrFilm;

struct elmFilm{
    filmNetflix infoFilm;
    adrFilm nextFilm;
};

struct listFilm{
    adrFilm firstFilm;
};

void createListFilm(listFilm &listF);
adrFilm createElmFilm(filmNetflix info);
void insertLastFilm(listFilm &listF, adrFilm dataFilm);
void showAllFilm(listFilm listF);
adrFilm cariDataFilm(listFilm listF, string judul);
int autoIncrementIDFilm(listFilm listF);

#endif // LISTFILM_H_INCLUDED
