#ifndef FUNGSI_H_INCLUDED
#define FUNGSI_H_INCLUDED

#include "listUser.h"
#include "listFilm.h"

void menuUser(adrUser dataUser, int &pilih);
void menuLogin(listUser &listU, adrUser &dataUserLogin);
void garis(int n);
void tambahUserDefault(listUser &listU);
void tambahFilmDefault(listFilm &listF);
void registrasiUser(listUser &listU);
void tambahFilmSubcriber(listFilm &listF, adrUser dataUserLogin);
void deleteFilmSubcriber(listUser listU, listFilm listF, adrUser &dataUserLogin);
void cariSubcribeFilmUser(adrUser dataUserLogin);
void filmSubcribeTerbanyak(listUser listU);
void deleteUser(listUser &listU, adrUser &dataUserLogin);
void tampilUserSubcriber(listUser listU, listFilm listF);

#endif // FUNGSI_H_INCLUDED
