#include "listUser.h"
#include "listFilm.h"
#include "fungsi.h"

int main()
{
    int pilih;
    char kembali;
    listUser listU;
    listFilm listF;
    userSubcriber infoU;
    adrUser dataUserLogin = NULL;
    filmNetflix infoF;

    createListUser(listU);
    createListFilm(listF);

    tambahUserDefault(listU);
    tambahFilmDefault(listF);

    login:
    menuLogin(listU, dataUserLogin);

    if(dataUserLogin == NULL){
        goto login;
    }

    user:
    menuUser(dataUserLogin, pilih);

    switch(pilih){
    case 1:
        tambahFilmSubcriber(listF, dataUserLogin);
        break;
    case 2:
        deleteFilmSubcriber(listU, listF, dataUserLogin);
        break;
    case 3:
        showAllChild(dataUserLogin);
        break;
    case 4:
        cariSubcribeFilmUser(dataUserLogin);
        break;
    case 5:
        filmSubcribeTerbanyak(listU);
        break;
    case 6:
        tampilUserSubcriber(listU, listF);
        break;
    case 7:
        deleteUser(listU, dataUserLogin);
        goto login;
        break;
    case 0:
        system("cls");
        dataUserLogin = NULL;
        goto login;
        break;
    default:
        system("cls");
        garis(50);
        cout<<"Pilihan tidak ada"<<endl;
        garis(50);
        cout<<"tekan enter...";
        getch();
        system("cls");
        goto user;
        break;
    }

    garis(50);
    cout<<"Kembali ke menu?(Y/N): ";
    cin>>kembali;

    system("cls");
    if(kembali == 'Y' || kembali == 'y'){
        goto user;
    }

    return 0;
}
