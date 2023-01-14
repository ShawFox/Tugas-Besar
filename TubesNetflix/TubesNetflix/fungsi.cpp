#include "fungsi.h"
#include "listFilm.h"
#include "listUser.h"

userSubcriber infoU[5] = {
    {id: 1, nama: "Adam", alamat: "NY city", gmail: "adam@gmail.com", umur: 21},
    {id: 2, nama: "Shelya", alamat: "Berlin", gmail: "Shelya@gmail.com", umur: 35},
    {id: 3, nama: "youcannotseeme", alamat: "British", gmail: "jhon@gmail.com", umur: 31},
    {id: 4, nama: "nibaa", alamat: "Kalbar", gmail: "nibb@gmail.com", umur: 29},
    {id: 5, nama: "gatausiapa", alamat: "Sumsel", gmail: "a@gmail.com", umur: 25}
};

filmNetflix infoF[5] = {
    {id: 1, judul: "Pirrate of the carrabine", durasi: "1:30 Jam", desc: "gatauapa1", studio: "gatausiapa1", tahunRilis: 2012},
    {id: 2, judul: "Junadi & Yoga", durasi: "1:49 Jam", desc: "gatauapa2", studio: "gatausiapa2", tahunRilis: 2002},
    {id: 3, judul: "Titansic", durasi: "2:29 Jam", desc: "gatauapa3", studio: "gatausiapa3", tahunRilis: 2014},
    {id: 4, judul: "Highschool DxD", durasi: "3:21 Jam", desc: "idkanymore1", studio: "PinkPinaple", tahunRilis: 2016},
    {id: 5, judul: "Overflow Maybe", durasi: "12:34 Jam", desc: "same,fakdissit", studio: "PinkPinaple", tahunRilis: 2022}
};

void garis(int n){
    for(int i = 0; i < n; i++){
        cout<<"=";
    }
    cout<<endl;
}

void tambahFilmDefault(listFilm &listF){
    for(int i = 0; i < 5; i++){
        insertLastFilm(listF, createElmFilm(infoF[i]));
    }
}

void tambahUserDefault(listUser &listU){
    for(int i = 0; i < 5; i++){
        insertFirstUser(listU, createElmUser(infoU[i]));
    }
}

void menuLogin(listUser &listU, adrUser &dataUserLogin){
    string gmail;
    int regis;

    garis(30);
    cout<<"Welcome to Netflix"<<endl;
    garis(30);
    cout<<"1. Login"<<endl;
    cout<<"2. Registrasi"<<endl;
    cout<<"0. Exit"<<endl;
    garis(30);
    cout<<"pilih: ";
    cin>>regis;

    if(regis == 1){
        system("cls");
        garis(30);
        cout<<"Login to Netflix"<<endl;
        garis(30);
        cout<<"gmail: ";
        cin>>gmail;

        if(cariDataUser(listU, gmail) != NULL){
            system("cls");
            dataUserLogin = cariDataUser(listU, gmail);
        }else{
            system("cls");

            garis(30);
            cout<<"Gmail tidak ditemukan"<<endl;
            garis(30);
            cout<<"tekan enter...";
            getch();

            system("cls");
            menuLogin(listU, dataUserLogin);
        }
    }else if(regis == 2){
        system("cls");
        registrasiUser(listU);
    }else if(regis == 0){
        exit(0);
    }else{
        system("cls");
        garis(30);
        cout<<"Pilihan tidak ada"<<endl;
        garis(30);
        cout<<"tekan enter...";
        getch();
        system("cls");
        menuLogin(listU, dataUserLogin);
    }
}

void menuUser(adrUser dataUserLogin, int &pilih){
    garis(50);
    cout<<"KW Netflix APP V.1.0"<<endl;
    garis(50);
    cout<<"ID: "<<infoUser(dataUserLogin).id<<endl;
    cout<<"Welcome: "<<infoUser(dataUserLogin).nama<<endl;
    garis(50);
    cout<<"\t\t\tMenu"<<endl;
    garis(50);

    cout<<"1. Subcriber Film"<<endl;
    cout<<"2. Unsubcriber Film"<<endl;
    cout<<"3. Tampilkan Film Subcriber saya"<<endl;
    cout<<"4. Mencari Film Subcriber saya"<<endl;
    cout<<"5. Subcribe Film Terbanyak"<<endl;
    cout<<"6. Tampilkan User Subcribe Film tertentu"<<endl;
    cout<<"7. Hapus akun"<<endl;
    cout<<"0. Logout"<<endl;
    garis(50);
    cout<<"Pilih menu: ";
    cin>>pilih;
}

void registrasiUser(listUser &listU){
    userSubcriber infoU;

    garis(50);
    cout<<"Registrasi KW Netflix"<<endl;
    garis(50);

    cin.ignore();
    if(firstUser(listU) != NULL){
        infoU.id = infoUser(firstUser(listU)).id + 1;
    }else{
        infoU.id = 1;
    }

    cout<<"Nama Pengguna: ";
    getline(cin, infoU.nama);
    cout<<"Alamat: ";
    getline(cin, infoU.alamat);
    cout<<"Gmail: ";
    getline(cin, infoU.gmail);
    cout<<"Umur: ";
    cin>>infoU.umur;

    system("cls");

    insertFirstUser(listU, createElmUser(infoU));

    garis(50);
    cout<<"Registrasi berhasil"<<endl;
    garis(50);
    cout<<"tekan enter...";
    getch();

    system("cls");
}

void tambahFilmSubcriber(listFilm &listF, adrUser dataUserLogin){
    filmNetflix infoF;
    adrFilm dataFilm;
    string judul;
    char cek;

    showAllFilm(listF);

    cout<<"Pilih Judul untuk di subcribe: ";
    cin.ignore();
    getline(cin, judul);
    garis(50);

    dataFilm = cariDataFilm(listF, judul);
    if(dataFilm != NULL){
        garis(50);
        if(cekRelasiChild(dataUserLogin, judul) == NULL){
            insertLastChild(dataUserLogin, createElmChild(dataFilm));
            cout<<"\t\tSubcribe Film berhasil"<<endl;
            cout<<endl;
        }else{
            cout<<"\t\tFilm Sudah di Subcribe"<<endl;
        }
        garis(50);
    }else{
        cout<<"\t\tFilm tidak ditemukan"<<endl;
        garis(50);
        cout<<"Tambahkan Film?(Y/N): ";
        cin>>cek;

        if(cek == 'Y' || cek == 'y'){
            infoF.id = autoIncrementIDFilm(listF);
            infoF.judul = judul;

            cin.ignore();
            cout<<"Judul Film: "<<judul<<endl;
            cout<<"Durasi: ";
            getline(cin, infoF.durasi);
            cout<<"Desc: ";
            getline(cin, infoF.desc);
            cout<<"Studio: ";
            getline(cin, infoF.studio);
            cout<<"Tahun rilis: ";
            cin>>infoF.tahunRilis;

            dataFilm = createElmFilm(infoF);
            insertLastFilm(listF, dataFilm);
            insertLastChild(dataUserLogin, createElmChild(dataFilm));

            garis(50);
            cout<<"\t\tSubcribe Film berhasil"<<endl;
            garis(50);
            cout<<endl;
        }else{
            garis(50);
            cout<<"\t\tGagal Subcribe Film"<<endl;
            garis(50);
            cout<<endl;
        }
    }
}

void deleteFilmSubcriber(listUser listU, listFilm listF, adrUser &dataUserLogin){
    string judul;
    adrChild delChild, dataDelFilm;

    garis(50);
    if(firstChild(dataUserLogin) != NULL){
        showAllChild(dataUserLogin);

        cout<<"Judul Film untuk di unsubcribe: ";
        cin.ignore();
        getline(cin, judul);

        delChild = cekRelasiChild(dataUserLogin, judul);

        if(delChild != NULL){
            if(firstChild(dataUserLogin) == delChild){
                deleteFirstChild(dataUserLogin, dataDelFilm);
            }else{
                deleteAfterChild(dataUserLogin, delChild, dataDelFilm);
            }
            garis(50);
            cout<<"Film di Unsubcribe"<<endl;
            garis(50);
            cout<<"Judul: "<<infoFilm(infoChild(dataDelFilm)).judul<<endl;
            cout<<"Studio: "<<infoFilm(infoChild(dataDelFilm)).studio<<endl;
        }else{
            garis(50);
            cout<<"\t\tFilm tidak ditemukan"<<endl;
        }
    }else{
        garis(50);
        cout<<"\tTidak memiliki Subcriber film"<<endl;
    }
}

void cariSubcribeFilmUser(adrUser dataUserLogin){
    string judul;
    adrChild dataChild;

    garis(50);
    cout<<"Cari Film Subcriber dari user: "<<infoUser(dataUserLogin).nama<<endl;
    garis(50);
    cout<<"Judul Film: ";
    cin.ignore();
    getline(cin, judul);
    garis(50);

    dataChild = cekRelasiChild(dataUserLogin, judul);
    if(dataChild != NULL){
        cout<<"\t\tFilm Ditemukan"<<endl;
        garis(50);
        cout<<"Judul: "<<infoFilm(infoChild(dataChild)).judul<<endl;
        cout<<"Durasi: "<<infoFilm(infoChild(dataChild)).durasi<<endl;
        garis(50);
        cout<<"Studio: "<<infoFilm(infoChild(dataChild)).studio<<endl;
    }else{
        cout<<"Film tidak di temukan pada list Subcribe"<<endl;
    }
}

void filmSubcribeTerbanyak(listUser listU){
    adrUser dataUser = firstUser(listU), maxUser = firstUser(listU);
    int maxFilm = countChild(firstChild(dataUser));

    while(dataUser != NULL){
        if(countChild(firstChild(dataUser)) > maxFilm){
            maxFilm = countChild(firstChild(dataUser));
            maxUser = dataUser;
        }
        dataUser = nextUser(dataUser);
    }

    garis(50);
    cout<<"Data Subcriber terbanyak dipegang oleh: "<<infoUser(maxUser).nama<<endl;
    garis(50);
    cout<<"Sebanyak: "<<maxFilm<<" Jumlah Subcribe Film"<<endl;
    garis(50);
    cout<<"Dengan Film yang di subcribe: "<<endl;
    garis(50);
    showAllChild(maxUser);
}

void deleteUser(listUser &listU, adrUser &dataUserLogin){
    if(firstUser(listU) == dataUserLogin){
        firstUser(listU) = nextUser(dataUserLogin);
        nextUser(dataUserLogin) = NULL;
    }else{
        adrUser dataUser = firstUser(listU);

        while(nextUser(dataUser) != dataUserLogin){
            dataUser = nextUser(dataUser);
        }

        if(nextUser(dataUserLogin) != NULL){
            nextUser(dataUser) = nextUser(dataUserLogin);
            nextUser(dataUserLogin) = NULL;
        }else{
            nextUser(dataUser) = NULL;
        }

    }

    dataUserLogin = NULL;

    garis(50);
    cout<<"\t\tUser terhapus"<<endl;
    garis(50);
    cout<<"tekan enter...";
    getch();

    system("cls");
}

void tampilUserSubcriber(listUser listU, listFilm listF){
    adrUser dataUser = firstUser(listU);
    string judul;
    int total = 0;

    garis(50);
    cout<<"Judul Film: ";
    cin.ignore();
    getline(cin, judul);
    garis(50);
    cout<<endl;

    adrFilm cariFilm = cariDataFilm(listF, judul);
    garis(50);
    if(cariFilm != NULL){
        cout<<"Subcriber Film pada: "<<judul<<endl;

        while(dataUser != NULL){
            adrChild dataChild = firstChild(dataUser);
            while(dataChild != NULL){
                if(infoChild(dataChild) == cariFilm){
                    cout<<"- "<<infoUser(dataUser).nama<<endl;
                    total++;
                }
                dataChild = nextChild(dataChild);
            }
            dataUser = nextUser(dataUser);
        }

        if(total != 0){
            cout<<"Total User Subcribe film ini: "<<total<<endl;
        }else{
            cout<<"Tidak ada User yang subcribe Film ini"<<endl;
        }

    }else{
        cout<<"Film Tidak ditemukan"<<endl;
    }
    garis(50);
}
