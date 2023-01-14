#include "listFilm.h"
#include "fungsi.h"

void createListFilm(listFilm &listF){
    firstFilm(listF) = NULL;
}

adrFilm createElmFilm(filmNetflix info){
    adrFilm dataFilm = new elmFilm;

    infoFilm(dataFilm) = info;
    nextFilm(dataFilm) = NULL;

    return dataFilm;
}

void insertLastFilm(listFilm &listF, adrFilm dataFilm){
    if(firstFilm(listF) == NULL){
        firstFilm(listF) = dataFilm;
        nextFilm(firstFilm(listF)) = dataFilm;
    }else{
        adrFilm temp = firstFilm(listF);

        while(nextFilm(temp) != firstFilm(listF)){
            temp = nextFilm(temp);
        }

        nextFilm(temp) = dataFilm;
        nextFilm(dataFilm) = firstFilm(listF);
    }
}

adrFilm cariFilm(listFilm listF, int idFilm){
    adrFilm dataFilm = firstFilm(listF);

    if(dataFilm != NULL){
        do{
            if(infoFilm(dataFilm).id == idFilm){
                return dataFilm;
            }
            dataFilm = nextFilm(dataFilm);
        }while(dataFilm != firstFilm(listF));
    }

    return NULL;
}

void showAllFilm(listFilm listF){
    adrFilm dataFilm = firstFilm(listF);
    int i = 1;

    garis(50);
    if(dataFilm != NULL){
        cout<<"Seluruh Film Netflix"<<endl;
        garis(50);
        do{
            cout<<"No Film: "<<i<<endl;
            cout<<"Judul: "<<infoFilm(dataFilm).judul<<endl;
            garis(50);
            cout<<"Desc: "<<infoFilm(dataFilm).desc<<endl;
            cout<<"studio: "<<infoFilm(dataFilm).studio<<endl;
            garis(50);
            cout<<"Durasi: "<<infoFilm(dataFilm).durasi<<endl;
            garis(50);
            cout<<endl;
            garis(50);
            i++;
            dataFilm = nextFilm(dataFilm);
        }while(dataFilm != firstFilm(listF));
    }else{
        cout<<"\t\tData Film Kosong"<<endl;
        garis(50);
    }

}

adrFilm cariDataFilm(listFilm listF, string judul){
    adrFilm dataFilm = firstFilm(listF);

    if(dataFilm != NULL){
        do{
            if(infoFilm(dataFilm).judul == judul){
                return dataFilm;
            }
            dataFilm = nextFilm(dataFilm);
        }while(dataFilm != firstFilm(listF));
    }
    return NULL;
}

int autoIncrementIDFilm(listFilm listF){
    adrFilm dataFilm = firstFilm(listF);

    if(dataFilm != NULL){
        while(nextFilm(dataFilm) != firstFilm(listF)){
            dataFilm = nextFilm(dataFilm);
        }

        return infoFilm(dataFilm).id + 1;
    }

    return 1;
}
