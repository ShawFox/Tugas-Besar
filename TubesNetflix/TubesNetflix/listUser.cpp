#include "listUser.h"
#include "fungsi.h"

void createListUser(listUser &listU){
    firstUser(listU) = NULL;
}

adrUser createElmUser(userSubcriber info){
    adrUser dataUser = new elmUser;

    infoUser(dataUser) = info;
    childUser(dataUser) = NULL;
    nextUser(dataUser) = NULL;

    return dataUser;
}


adrChild createElmChild(adrFilm dataFilm){
    adrChild dataChild = new elmChild;

    nextChild(dataChild) = NULL;
    infoChild(dataChild) = dataFilm;

    return dataChild;
}

void insertFirstUser(listUser &listU, adrUser dataUser){
    if(firstUser(listU) == NULL){
        firstUser(listU) = dataUser;
    }else{
        nextUser(dataUser) = firstUser(listU);
        firstUser(listU) = dataUser;
    }
}

void insertLastChild(adrUser dataUser, adrChild dataChild){
    if(childUser(dataUser) == NULL){
        childUser(dataUser) = dataChild;
    }else{
        adrChild tempChild = childUser(dataUser);

        while(nextChild(tempChild) != NULL){
            tempChild = nextChild(tempChild);
        }

        nextChild(tempChild) = dataChild;
    }
}

void deleteFirstChild(adrUser &dataUserLogin, adrChild &dataDelFilm){
    adrChild dataChild = firstChild(dataUserLogin);

    if(nextChild(dataChild) != NULL){
        dataDelFilm = dataChild;
        firstChild(dataUserLogin) = nextChild(dataDelFilm);
        nextChild(dataDelFilm) = NULL;
    }else{
        dataDelFilm = dataChild;
        firstChild(dataUserLogin) = NULL;
        nextChild(dataDelFilm) = NULL;
    }
}

void deleteAfterChild(adrUser &dataUserLogin, adrChild delChild, adrChild &dataDelFilm){
    adrChild dataChild = firstChild(dataUserLogin);

    while(nextChild(dataChild) != delChild){
        dataChild = nextChild(dataChild);
    }

    if(nextChild(nextChild(dataChild)) == NULL){
        dataDelFilm = nextChild(dataChild);
        nextChild(dataChild) = NULL;
    }else{
        dataDelFilm = nextChild(dataChild);
        nextChild(dataChild) = nextChild(dataDelFilm);
        nextChild(dataDelFilm) = NULL;
    }
}

adrUser cariDataUser(listUser listU, string gmail){
    adrUser dataUser = firstUser(listU);

    while(dataUser != NULL){
        if(infoUser(dataUser).gmail == gmail){
            return dataUser;
        }
        dataUser = nextUser(dataUser);
    }

    return NULL;
}

void createRelasi(listUser &listU, listFilm listF, adrUser dataUserLogin){
    adrUser dataUser = firstUser(listU);

    if(dataUser == NULL){
        cout<<"Data Subcriber kosong"<<endl;
    }else{
        while(dataUser != NULL){

            dataUser = nextUser(dataUser);
        }
    }
}



adrChild cekRelasiChild(adrUser dataUserLogin, string judul){
    adrChild dataChild = childUser(dataUserLogin);

    if(dataChild != NULL){
        while(dataChild != NULL){
            if(infoFilm(infoChild(dataChild)).judul == judul){
                return dataChild;
            }
            dataChild = nextChild(dataChild);
        }
    }

    return NULL;
}

void showAllChild(adrUser dataUserLogin){
    adrChild dataChild = firstChild(dataUserLogin);
    int i = 1;

    garis(50);
    cout<<"\t\tFilm Subcriber"<<endl;

    if(dataChild == NULL){
        cout<<"Tidak ada yang di subcribe"<<endl;
    }else{
        while(dataChild != NULL){
            garis(50);
            cout<<"No Film: "<<i<<endl;
            cout<<"Judul: "<<infoFilm(infoChild(dataChild)).judul<<endl;
            garis(50);
            cout<<"Desc: "<<infoFilm(infoChild(dataChild)).desc<<endl;
            cout<<"studio: "<<infoFilm(infoChild(dataChild)).studio<<endl;
            garis(50);
            cout<<"Durasi: "<<infoFilm(infoChild(dataChild)).durasi<<endl;
            garis(50);
            cout<<endl;
            i++;

            dataChild = nextChild(dataChild);
        }
    }
}

int countChild(adrChild dataChild){
    int jumlah = 0;

    while(dataChild != NULL){
        jumlah++;
        dataChild = nextChild(dataChild);
    }

    return jumlah;
}
