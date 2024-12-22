//402519 Hatice YILDIZ 422610 Zehra OZCIRIS 402504 Elif Sedanur AKSOY

#include <iostream>
#include<string>
#include<regex>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<ctime>
using namespace std;


class kisi
{
public:
    void setad_soyad();
    string getad_soyad();
    void settelno(string telno);
    void displayad_soyad();
    void displaytelno();
    string gettelno();
private:
    string ad_soyad;
    string telno;
    bool isValid(string);
};

void kisi::setad_soyad()
{
    string adsoyad;
    string ad;
    string soyad;
    cout << "Adinizi giriniz:";
    cin >> ad;
    cout << "soyadinizi giriniz:";
    cin >> soyad;
    adsoyad = ad + ' ' + soyad;
    ad_soyad = adsoyad;

}
string kisi::getad_soyad()
{
    return ad_soyad;
}
void kisi::displayad_soyad()
{
    cout << "AD SOYAD: " << ad_soyad << endl;
}
void kisi::settelno(string telefon)
{
    if (isValid(telefon))
        telno = telefon;

    else
    {
        cout << "\nGirilen telefon numarasi gecersiz! lütfen tekrar giriniz.\n";
        string teltekrar;
        cin >> teltekrar;
        settelno(teltekrar);
    }
}
bool kisi::isValid(string numara)
{
    const regex pattern("(0|90|5)?[5][0-9]{9}"); //pattern e istediðimiz koþulu atadýk kosul 0-90-5 bunlardan biriyle baþlayacak  5 le baþlayacak içerisinde 0-9 araliýgiðnda sayýlar 9 tane olacak

    if (regex_match(numara, pattern)) //pattern ile geleni karþýlaþtýracak bu zatan kütüphane fonku
    {
        return true;
    }
    else
    {
        return false;
    }
}
void kisi::displaytelno()
{
    cout << "TELEFON NUMARASI: " << telno << endl;
}
string kisi::gettelno()
{
    return telno;

}

class yonetici :public kisi
{
public:
    bool ygiris();
};

bool yonetici::ygiris()
{
    int count = 0;
    string username, pass, u, p;
    system("cls");
    cout << "SIFRENIZI GIRINIZ:" << endl;
    cout << "SIFRE:";
    cin >> pass;

    ifstream yonetici_bilgi("yonetici.txt"); //yonetici.txt dosyadan okuma yaparýz
    while (yonetici_bilgi >> p)
    {
        if (p == pass)
        {
            count = 1;
            system("cls");
        }
    }
    yonetici_bilgi.close();
    if (count == 1)
    {
        cout << "\nMERHABA YONETICI\nGIRIS BASARILI\n\n";
        return true;
    }
    else
    {
        cout << "\nHATALI GIRIS\nLUTFEN SIFRENIZI KONTROL EDINIZ\n";
        return false;
    }
}

class kullanici :public kisi
{
public:
    void setkullanici_adi(string);
    string getkullaniciadi()const;
    void seteposta();
    string geteposta()const;
    int setadres_ilce();
    string getadres_ilce() const;
    void setsifre(string);
    string getsifre()const;
    void setindirim_kodu();
    string getindirim_kodu()const;
    void setdtarihi(string);
    void getdtarihi()const;
    void inputdtarihi();
    bool ozelkaraktermi(char c);
    void kayit();
    bool giris();
    void sifreolustur();
    void gorus();
private:
    string kullanici_adi;
    string eposta;
    string adres_ilce;
    string sifre;
    string indirim_kodu;
    string dtarihi;
    bool isvalideposta(string);
    int gunkontrol(int);//gun kontrolü utility fonksiyon olarak tanimlandi
    int gun, ay, yil;
};

void kullanici::setindirim_kodu()
{
     srand(time(0));
        static const char kodkarakterleri[] = "0123456789"
                                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                "abcdefghijklmnopqrstuvwxyz";

        int uzunluk = sizeof(kodkarakterleri) - 1;
        for(int m = 0; m < 7; m++)
            {
            indirim_kodu  = indirim_kodu + kodkarakterleri[rand() % uzunluk];
            }
}
string kullanici::getindirim_kodu()const
{ return indirim_kodu; }
void kullanici::setkullanici_adi(string kullanici)
{
    kullanici_adi = kullanici;
}
string kullanici::getkullaniciadi()const
{ return kullanici_adi; }
void kullanici::gorus()
{
    string gorus;
    cout << "Lutfen gorusunuzu:";
    cin.ignore();
    getline(cin >> ws, gorus);

    ofstream oneriyazz;
    oneriyazz.open("oneri.txt");
    oneriyazz << gorus;
    oneriyazz << endl;
    oneriyazz.close();
}
void kullanici::seteposta()
{
    string posta;
mtekrar:cout << "E-posta adresinizi (or:444444@ktu.edu.tr,ogrenci@gmail.com) :";
    cin >> posta;
    if (isvalideposta(posta))
        eposta = posta;
    else
    {
        cout << "\nGecerli mail adressi girilmemistir!!n";
        goto mtekrar;
    }
}
bool kullanici::isvalideposta(string kontrolposta)
{
    const regex pattern("[a-zA-Z 0-9.-_]+@+gmail+\.com+$");
    const regex pattern2("[0-9]+@ktu+\.edu+\.tr+$");
    if (regex_match(kontrolposta, pattern))
        return true;
    else if (regex_match(kontrolposta, pattern2))
        return true;
    else
        return false;
}
string kullanici::geteposta()const
{
    return eposta;
}
int kullanici::setadres_ilce()
{
    cout << "1.Ortahisar\n";
    cout << "2.Akcabat\n";
    cout << "3.Vakfikebir\n";
    cout << "4.Besikduzu\n";
    cout << "5.Yomra\n";
    cout << "6.Arsin\n";
    cout << "7.Arakli\n";
    int sec;
asec:cout << "\n\nAdresinizi seciniz(1-7):";
    cin >> sec;
    switch (sec)
    {
    case 1:
        adres_ilce = "Ortahisar";
        return 1;
        break;

    case 2:
        adres_ilce = "Akcabat";
        return 2;
        break;
    case 3:
        adres_ilce = "Vakfikebir";
        return 3;
        break;
    case 4:
        adres_ilce = "Besikduzu";
        return 4;
        break;
    case 5:
        adres_ilce = "Yomra";
        return 5;
        break;
    case 6:
        adres_ilce = "Arsin";
        return 6;
        break;
    case 7:
        adres_ilce = "Arakli";
        return 7;
        break;
    default:
        cout << "lutfen seceneklarden birini seciniz:\n";
        goto asec;
    }
}
string kullanici::getadres_ilce()const
{ return adres_ilce; }
bool kullanici::ozelkaraktermi(char c)
{
    if (int(c) >= 32 && int(c) <= 47)
    {
        return true;
    }
    if (int(c) >= 58 && int(c) <= 64)
    {
        return true;
    }
    if (int(c) >= 91 && int(c) <= 96)
    {
        return true;
    }
    if (int(c) >= 123 && int(c) <= 126)
    {
        return true;
    }
}
void kullanici::setsifre(string pin)
{
    int bharf = 0, sayilar = 0, ozelkarakter = 0, ksayi = 0;
    for (int i = 0; i < pin.length(); i++)
    {
        if (isupper(pin[i]))
        {
            bharf++;
        }
        if (pin[i] >= '0' && pin[i] <= '9')
        {
            sayilar++;
        }
        if (ozelkaraktermi(pin[i]))
        {
            ozelkarakter++;
        }
    }
    ksayi = bharf + sayilar + ozelkarakter;
    if (bharf > 0 && sayilar > 0 && ozelkarakter > 0 && ksayi >= 6)
    {
        sifre = pin;
        cout << "SIFRENIZ OLUSTURULDU\n(GUCLU SIFRE)" << endl;
    }
    else
    {
        cout << "SIFRENIZ OLUSTURULDU ANCAK GUCSUZ SIFRE!!\nYENIDEN SIFRE OLUSTURUN LUTFEN:";
        string yenipin;
        cout << "TEKRAR SIFRE GIRIN:";
        cin >> yenipin;
        setsifre(yenipin);
    }
}
void kullanici::sifreolustur()
{
    string yenisifre;
    cout << "YENI SIFRENIZI GIRINIZ:";
    cin >> yenisifre;
    setsifre(yenisifre);
}
string kullanici::getsifre()const
{ return sifre; }
void kullanici::inputdtarihi()
{
    int gg, aa, yy;
dtarihitek:cout << "Dogum tarihinizi gun ay yil seklinde her giriste enter a basarak girin:";
    cout << "Gun:"; cin >> gg;
    cout << "Ay:"; cin >> aa;
    cout << "Yil:"; cin >> yy;

    if (aa > 0 && aa <= 12)
        ay = aa;
    else
    {
        cout << "Gecersiz ay girilmistir!!! Tekrar giriniz.\n";
        goto dtarihitek;
    }
    if (yy > 2004)
    {
        cout << "Uzgunuz sisteme 18 yasindan kucukler kayit yapamaz!!\n";
        system("cls");
    }
    else if (yy < 1930 && yy > 2022)
    {
        cout << "Gecersiz yil girilmistir!!! Tekrar giriniz\n";
        goto dtarihitek;
    }
    else
        yil = yy;
    if (gunkontrol(gg) != 0)
        gun = gg;
    else
    {
        cout << "Gecersiz gun girilmistir!!! Tekrar giriniz.";
        goto dtarihitek;
    }
}
int kullanici::gunkontrol(int gg)
{
    static int gunler[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (gg > 0 && gg <= gunler[ay])
        return gg;
    if (ay == 2 && gg == 29 && (yil % 400 == 0 || (yil % 4 == 0 && yil % 100 != 0)))
        return gg;
    else
        return 0;
}
void kullanici::getdtarihi()const
{
    cout << gun << "/" << ay << "/" << yil;
}
void kullanici::kayit()
{
    string username, pass;
    string posta, telno, adres, dogumtarihi, indirimkodu;
    system("cls");
    cout << "Kullanici adinizi girin :";
    cin >> username;
    setkullanici_adi(username);
    cout << "Sifrenizi giriniz.(Guclu sifre icin en az bir tane buyuk harf,sayi ve ozel karakter giriniz.Sifreniz en az 6 karakterli olmalı.)";
    cin >> pass;
    setsifre(pass);
    seteposta();
    cout << "Telefon numaranizi giriniz:";
    cin >> telno;
    settelno(telno);
    setadres_ilce();
    inputdtarihi();
    setindirim_kodu();
    string sifree;
    for (int i = 0; i < sifre.length(); i++)
        sifree += '*';

    ofstream reg("kayit.txt"); //ios::app
    reg << kullanici_adi << ' ' << sifree << ' ' << eposta << ' ' << gettelno() << ' ' << adres_ilce << ' '; reg <<  gun<<"/"<<ay<<"/"<<yil ; reg << " indirim kodu:" << indirim_kodu << endl;
    system("cls");
    cout << "\nKAYIT BASARILI\n";
}
bool kullanici::giris()
{
    int count = 0;
    string username, pass, u, p;
    system("cls");
    cout << "Kullanici adi ve sifrenizi giriniz:" << endl;
    cout << "Kullanici adi:";
    cin >> username;
    cout << "Sifre:";
    cin >> pass;

    ifstream input("musteri.txt");
    while (input >> u >> p)
    {
        if (u == username && p == pass)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\nMerhaba " << username << "\nGiris basarili\n\n";
        return true;
    }
    else
    {
        cout << "\nHATALI GIRIS\nLUTFEN KULLANICI ADI VE SIFRENIZI KONTROL EDİNİZ\n";
        return false;
    }
}

class zaman
{
    friend ostream& operator<<(ostream&, zaman);
public:
    zaman(int = 0);
    void setZaman();
    void setZaman2(int = 0);
    zaman operator+(const zaman&);
    zaman operator-(const zaman&);
    zaman& operator=(const zaman&);
    int getSaat();
    int getDakika();
    void printZaman();
private:
    int saat;
    int dakika;
};

zaman::zaman(int s)
{
    setZaman2(s);
}
void zaman::setZaman()
{
    time_t simdi = time(0);
    tm* simdikizaman = localtime(&simdi);
    dakika = simdikizaman->tm_min;
    saat = simdikizaman->tm_hour;
}
int zaman::getSaat()
 { return saat; }
int zaman::getDakika()
{ return dakika; }
void zaman::printZaman()
{
    cout << setfill('0')<<setw(2)<<saat<< ":" <<setw(2)<< getDakika() << endl;
}
ostream& operator<<(ostream& output, zaman z)
{
    output<< z.saat << "." << z.dakika << endl;
    return output;
}
void zaman::setZaman2(int z)
{
    if (z >= 60)
    {
        saat = z / 60;
        dakika = z % 60;
    }
    else
    {
        dakika = z;
        saat = 0;
    }
}
zaman& zaman::operator=(const zaman& z1)
{
    this->dakika = z1.dakika;
    this->saat = z1.saat;
    return *this;
}
zaman zaman::operator+(const zaman& z1)
{
    zaman zaman1;
    zaman1.dakika = dakika + z1.dakika;
    if (zaman1.dakika >= 60)
    {
        zaman1.dakika = (dakika + z1.dakika) % 60;
        zaman1.saat = zaman1.saat + (dakika + z1.dakika) / 60;
    }
    zaman1.saat = saat + z1.saat;
    if (zaman1.saat >= 24)
    {
        zaman1.saat -= 24;
    }

    return zaman1;
}
zaman zaman::operator-(const zaman& z1)
{
    zaman zaman1;
    if (dakika < z1.dakika)
    {
        zaman1.dakika = (dakika + 60) - z1.dakika;
        saat -= 1;
    }
    else
    {
        zaman1.dakika = dakika - z1.dakika;
    }
    if (saat < z1.saat)
    {
        zaman1.saat = (saat + 24) - z1.saat;
    }
    else
    {
        zaman1.saat = saat - z1.saat;
    }
    return zaman1;
}

class kurye :public zaman, public kisi
{
    static int kuryeSayisi;
public:
    kurye();
    ~kurye();
    enum varisNoktasi { Ortahisar = 1, Akcabat, Vakfikebir, Besikduzu, Yomra, Arsin, Arakli }; //string degerine karsilik sayi veriyor tip
    void kuryeEkle();
    static int getKuryeSayisi();
    void getDagitimBitis();
    void setKuryeler();
    zaman* dagitim_bitisler;

private:
    //int* siparisNumaralari;
    kisi kuryeler[20];
};

int kurye::kuryeSayisi = 5;
kurye::kurye()
{
    dagitim_bitisler = new zaman[8];
    dagitim_bitisler[0].setZaman2(0);
    dagitim_bitisler[Ortahisar].setZaman2(35);
    dagitim_bitisler[Akcabat].setZaman2(50);
    dagitim_bitisler[Vakfikebir].setZaman2(90);
    dagitim_bitisler[Besikduzu].setZaman2(110);
    dagitim_bitisler[Yomra].setZaman2(55);
    dagitim_bitisler[Arsin].setZaman2(70);
    dagitim_bitisler[Arakli].setZaman2(100);

   setKuryeler();
}
kurye::~kurye()
{
    delete[] dagitim_bitisler;
}

void kurye::getDagitimBitis()
{
    for (int i = 0; i < kuryeSayisi; i++)
    {
        dagitim_bitisler[i].printZaman();
    }
}
int kurye::getKuryeSayisi()
{
    return kuryeSayisi;
}

void kurye::kuryeEkle()
{
    string tel;
    setad_soyad();
    cout << "Yeni kuryenin telefon numarasini giriniz:";
    getline(cin, tel);
    kuryeler[kuryeSayisi].settelno(tel);
    kuryeSayisi += 1;
}
void kurye::setKuryeler()
{
    for (int i = 0; i < kuryeSayisi; i++)
    {
        kuryeler[i].settelno("05432123456");

    }
}



//kıyafet classı
class kiyafet
{
public:
    kiyafet();
    void menu();
    void urun_ekle();
    void setkiyafetadi();
    string getkiyafetadi();
    void setfiyat();
    double getfiyat();
    void  printboyut();
    void printcolor();
    string etek[5]={"Mini_Etek","Pileli_Etek","Deri_Etek","Uzun_Etek"}, ayakkabi[6]={"Bot","Babet","Sandalet","Cizme","Spor_ayakkabi"}, pantolon[5]={"Kumas_pantolon","kot_pantolon","Ispanyol_paca",}, elbise[5]={"Cicekli_elbise","Abiye_elbise","Puantiyeli_elbise"},
    tshirt[5]={"Baskili","Cizgili","Batik_desen"}, gomlek[5]={"Oduncu_gomlek","Saten_gomlek","Sifon_gomlek"};
    double etekfiyat[5]={10,20,30,40}, ayakkabifiyat[5]={10,20,30,50,60}, pantolonfiyat[5]={10,20,30}, elbisefiyat[5]={10,20,30}, tshirtfiyat[5]={10,20,30}, gomlekfiyat[5]={40,50,30};
    int e = 0, p = 0, a = 0, eb = 0, t = 0, g = 0;
private:
    const string kategori[6] = { "etek","pantolon","ayakkabi","elbise","tshirt","gomlek" };;
    string kiyafet_adi;
    double fiyat;
    int boyut[4];
    string renk[4];
};
kiyafet::kiyafet()
{
    boyut[0] = 36;
    boyut[1] = 38;
    boyut[2] = 40;
    boyut[3] = 42;
    renk[0] = "SIYAH";
    renk[1] = "BEYAZ";
    renk[2] = "KIRMIZI";
    renk[3] = "MAVI";
}
void kiyafet::setkiyafetadi()
{
    cout << "Kiyafet adi giriniz: ";
    string kiyafetadi;
    //cin>> kiyafetadi;
    // cin.get(dizi_adi, dizi_boyut, sonlandirma_karakter);
    //getline(cin,kiyafetadi);
    kiyafet_adi = kiyafetadi;
}
string kiyafet::getkiyafetadi()
{
    return kiyafet_adi;
}
void kiyafet::setfiyat()
{
    cout << "Kiyafetin ücretini giriniz";
    cin >> fiyat;
}
double kiyafet::getfiyat()
{
    return fiyat;
}
void kiyafet::urun_ekle()
{
    cout << "\nKATEGORILER:\n1.ETEK\n2.PANTOLON\n3.AYAKKABI\n4.ELBISE\n5.T-SHIRT\n6.GOMLEK" << endl;
    cout << "\n\n\n";
    int kategorisecimi;
    cout << "KIYAFET EKLEMEK ISTEDIGINIZ KATEGORIYI SECINIZ : ";
    cin >> kategorisecimi;

    if (kategorisecimi == 1)
    {
        cout << "Kiyafet adi giriniz: ";
        string kiyafetadi;
        cin >> kiyafetadi;
        kiyafet_adi = kiyafetadi;
        etek[e] = kiyafet_adi;
        cout << "Kiyafetin ücretini giriniz";
        cin >> fiyat;
        etekfiyat[e] = fiyat;
        e++;
    }
    else if (kategorisecimi == 2)
    {
        cout << "Kiyafet adi giriniz: ";
        string kiyafetadi;
        cin >> kiyafetadi;
        kiyafet_adi = kiyafetadi;
        pantolon[p] = kiyafet_adi;
        cout << "Kiyafetin ücretini giriniz";
        cin >> fiyat;
        pantolonfiyat[p] = fiyat;
        p++;
    }
    else if (kategorisecimi == 3)
    {
        cout << "Kiyafet adi giriniz: ";
        string kiyafetadi;
        cin >> kiyafetadi;
        kiyafet_adi = kiyafetadi;
        cout << "Kiyafetin ücretini giriniz";
        cin >> fiyat;
        ayakkabi[a] = kiyafet_adi;
        ayakkabifiyat[a] = fiyat;
        a++;
    }
    else if (kategorisecimi == 4)
    {
        cout << "Kiyafet adi giriniz: ";
        string kiyafetadi;
        cin >> kiyafetadi;
        kiyafet_adi = kiyafetadi;
        cout << "Kiyafetin ücretini giriniz";
        cin >> fiyat;
        elbise[eb] = kiyafet_adi;
        elbisefiyat[eb] = fiyat;
        eb++;
    }
    else if (kategorisecimi == 5)
    {
        cout << "Kiyafet adi giriniz: ";
        string kiyafetadi;
        cin >> kiyafetadi;
        kiyafet_adi = kiyafetadi;
        cout << "Kiyafetin ücretini giriniz";
        cin >> fiyat;
        tshirt[t] = kiyafet_adi;
        tshirtfiyat[t] = fiyat;
        t++;
    }
    else if (kategorisecimi == 6)
    {
        cout << "Kiyafet adi giriniz: ";
        string kiyafetadi;
        cin >> kiyafetadi;
        kiyafet_adi = kiyafetadi;
        cout << "Kiyafetin ücretini giriniz";
        cin >> fiyat;
        gomlek[g] = kiyafet_adi;
        gomlekfiyat[g] = fiyat;
        g++;
    }
    else
    {
        cout << "Boyle bir kategori bulunmamaktadır!!\n\n";
    }
}
void kiyafet::printboyut()
{
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << "." << boyut[i] << "\n";
    }
}
void kiyafet::printcolor()
{
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << "." << renk[i] << "\n";
    }
}





class siparis : public zaman, public kiyafet, public kurye, public kisi, public kullanici
{
public:
    void setsiparisfiyat();
    double getsiparisfiyat();
    void kiyafetozellestir();
    void faturaolustur();
    void siparistakip();
    void setsiparisbaslangic();
    zaman getsiparisbaslangic();
    void printsiparisbaslangic();
    int siparisler[10];
    void printsiparisler();
    vector <string> sepet;
    vector <double> sepetfiyat;
    void setsiparisno();
    int getsiparisno();
    void setSiparisUlasim();
    zaman getSiparisUlasim();
    void printsiparisulasim();
    void siparisver();
private:
    int siparis_no = 1;
    double siparis_fiyat=0;
    zaman siparis_baslangic;
    zaman siparis_ulasim;
    int beden=0;
    string color;
};
void siparis::setsiparisbaslangic()
{
    siparis_baslangic.setZaman();
}
void siparis::kiyafetozellestir()
{
    cout << "BEDENLER:" << endl;
    kiyafet k;
    k.printboyut();
    int temp;
    cout << "KIYAFET BEDENINIZI SECINIZ:(1..4)" << endl;
    cin >> temp;
    if (temp == 1)
    {
        beden = 36;
    }
    else if (temp == 2)
    {
        beden = 38;
    }
    else if (temp == 3)
    {
        beden = 40;
    }
    else if (temp == 4)
    {
        beden = 42;
    }

    cout << "RENKLER:" << endl;
    k.printcolor();
    int temp2;
    cout << "KIYAFET RENGI SECINIZ: (1..4)" << endl;
    cin >> temp2;
    if (temp == 1)
    {
        color = "SIYAH";
    }
    else if (temp == 2)
    {
        color = "BEYAZ";
    }
    else if (temp == 3)
    {
        color = "KIRMIZI";
    }
    else if (temp == 4)
    {
        color = "MAVI";
    }
}
void siparis::setsiparisfiyat()
{
    int vectorboyut = sepetfiyat.size();
    for (int i = 0; i <= vectorboyut; i++)
    {
        siparis_fiyat += sepetfiyat[i];
    }
}
double siparis::getsiparisfiyat()
{
    return siparis_fiyat;
}
void siparis::printsiparisler()
{

        cout << "SIPARIS NO: " << siparisler[getsiparisno()] << endl;

}
void siparis::faturaolustur()
{
    kullanici kullanici1;
    zaman zaman1;
    string isimsoyisim;
    double siparisucret;

    setsiparisfiyat();
    isimsoyisim = kullanici1.getkullaniciadi();
    siparisucret = getsiparisfiyat();

    cout << isimsoyisim << endl;
    cout << "URUNLER: ";
    for (int i = 0; i < sepet.size(); i++)
    {
        cout << sepet[i];
    }
    cout << endl;
    cout << "SIPARISINIZIN TOPLAM TUTARI: " << siparisucret << endl;
    cout << "SIPARISINIZIN TESLIM DURUMU: ";
    siparistakip();
    cout << endl;
}
void siparis::siparistakip()
{
    zaman temp2;
    zaman temp;
    zaman zaman1;
    temp.setZaman();
    temp2.setZaman2(siparis_ulasim.getSaat()-temp.getSaat()*60+(siparis_ulasim.getDakika()-temp.getDakika()));
    temp2.printZaman();

    if(temp2.getSaat()<=0&&temp2.getDakika()<=0)
        cout<<"SIPARISINIZ TESLIM EDILMISTIR IYI GUNLER!!";
    else
        cout<<"Siparisinizin teslimine "<<temp2.getSaat()<<"saat"<<temp2.getDakika()<<" dakika kaldi.";
}
void siparis::setsiparisno()
{
    siparis_no += 1;
}
int siparis::getsiparisno()
{
    return siparis_no;
}
void siparis::setSiparisUlasim()
{
    zaman z;
    kurye k;
    cout<<"Adres bilginiz icin secim yapin(1..7)"<<endl;
    cout<<"1. Ortahisar\n2. Akcaabat\n3. Vakfikebir\n 4.Besikduzu\n 5.Yomra\n6. Arsin\n7. Arakli"<<endl;
    int a;
    cin>>a;
    siparis_ulasim=siparis_baslangic+k.dagitim_bitisler[a];
}
void siparis::printsiparisbaslangic()
{
    siparis_baslangic.printZaman();
}
void siparis::printsiparisulasim()
{
    siparis_ulasim.printZaman();
}
void siparis::siparisver()
{
    setsiparisbaslangic();
    setsiparisno();
    siparisler[getsiparisno()]=siparis_no;
    cout<<getsiparisno()<<" numarali siparisiniz alinmistir"<<endl;
}

int main()
{
    kullanici musteri, musteri2;
    kiyafet kiyafet1;
    yonetici yonetici1;
    zaman z1,z2,z3;
    int secim;
    siparis siparis1;

    cout << "***********************************************************************\n\n";
    cout << "                       MENUYE HOSGELDINIZ                              \n\n";
    cout << "************************************************************************\n\n";
    cout << "1.GIRIS" << endl;
    cout << "2.KAYIT" << endl;
    cout << "3.CIKIS" << endl;
    tsec:cout << "\nSeciminizi girin :";
    cin >> secim;
    system("cls");

    if (secim == 1)
    {
        cout << "1.yonetici girisi" << endl;
        cout << "2.musteri girisi" << endl;
        cout<<"3.geri don"<<endl;
        int a;
        sec:cout << "\nseciminizi girin:";
        cin >> a;

        if(a==1) {
            if(yonetici1.ygiris())
            {
                cout << "1. Kiyafet kategorilerinin yer aldigi dosyalara urun girisinin yaptirilmasi" << endl;
                cout << "2. Sisteme kurye eklenmesi" << endl;
                cout << "3. sikayet ve oneri okunmasi" << endl;
                cout << "4. Kullaniciya indirim kodu tanimlamasi" << endl;
                cout << "5. Yapilan siparislerin faturalarinin goruntulemesi" << endl;
                cout << "6.Geri don"<<endl;

                int sec;
                cout<<"seciminizi girin:";
                cin>>sec;
                system("cls");

                if(sec==1)
                {
                    kiyafet1.urun_ekle();
                }
                else if(sec==3)
                {
                    ifstream onerioku;
                    string satir;
                    onerioku.open("oneri.txt");
                    while(getline(onerioku,satir))
                    {
                        cout<<satir<<endl<<endl;
                    }
                    onerioku.close();
                }
                else if(sec==4)
                {
                    musteri.setindirim_kodu();
                    cout<<"indirim kodunuz: "<<musteri.getindirim_kodu()<<endl;
                }
                else if(sec==5)
                {
                    siparis1.printsiparisler();
                    siparis1.faturaolustur();
                }
            }
            }
          else if(a==2)
          {
            if(musteri.giris())
                {
                cout << "1. Kiyafet kategorilerinin gosterimi ve urun seçimi" << endl;
                cout << "2. Siparis Takip" << endl;
                cout << "3. sikayet/Oneriler(Geri bildirimler)" << endl;
                cout << "4. sifre Degistir" << endl;
                cout << "5. Geri Don." << endl;

                int  sec;
                cout<<"seciminizi girin:";
                cin>>sec;
                system("cls");

                if(sec==1)
                {
                    cout << "Kategoriler : \n1. Etek \n2.Pantolon \n3.Ayakkabi \n4.Elbise \n5.Tshirt \n6.Gomlek" << endl;
                    cout << "\n\n\n";

                    kiyafet kiyafett;
                    siparis* siparisptr;

                    int kategorisecimi;
                    cout << "KATEGORI SECINIZ:";
                    cin >> kategorisecimi;
                    cout << "\n\n\n";

                    system("cls");

                    if (kategorisecimi == 1)
                    {
                        cout << "Etek kategorisindeki urunler:" << endl;
                        for (int i = 0; i <5; i++)
                        {
                            cout << i + 1 << "." << kiyafett.etek[i] << endl;
                        }
                        cout << "SEPETE EKLEMEK ISTEDIGINIZ URUNU SECINIZ(1 2..) :";
                        int a;
                        cin>>a;
                        siparis1.sepet.push_back(kiyafett.etek[a]);
                        siparis1.sepetfiyat.push_back(kiyafett.etekfiyat[a]);
                        siparis1.kiyafetozellestir();
                        system("cls");
                        cout<<"\nSepete eklendi"<<endl;
                        cout<<"\nSiparisi tamamlamak ister misiniz? (e-h)"<<endl;
                        string karar;
                        cin>>karar;
                        if(karar=="e")
                            siparis1.siparisver();
                            system("cls");
                            main();
                    }

                    else if (kategorisecimi == 2)
                    {
                        cout << "Pantolon kategorisideki urunler:" << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            cout << i + 1 << "." << kiyafett.pantolon[i] << endl;
                        }
                        cout << "SEPETE EKLEMEK ISTEDIGINIZ URUNU SECINIZ(1..50) :";
                        int a;
                        cin >> a;
                        siparis1.sepet.push_back(kiyafett.pantolon[a]);
                        siparis1.sepetfiyat.push_back(kiyafett.pantolonfiyat[a]);
                        siparis1.kiyafetozellestir();
                        system("cls");
                        cout<<"\nSepete eklendi"<<endl;
                        cout<<"\nSiparisi tamamlamak ister misiniz? (e-h)"<<endl;
                        string karar;
                        cin>>karar;
                        if(karar=="e")
                            siparis1.siparisver();
                            system("cls");
                            main();
                    }

                    else if (kategorisecimi == 3)
                    {
                        cout << "Ayakabi kategorisindeki urunler:" << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            cout << i + 1 << "." << kiyafett.ayakkabi[i] << endl;
                        }
                        cout << "SEPETE EKLEMEK ISTEDIGINIZ URUNU SECINIZ(1..50) :";
                        int a;
                        cin >> a;
                        siparis1.sepet.push_back(kiyafett.ayakkabi[a]);
                        siparis1.sepetfiyat.push_back(kiyafett.ayakkabifiyat[a]);
                        siparis1.kiyafetozellestir();
                        system("cls");
                        cout<<"\nSepete eklendi"<<endl;
                        cout<<"\nSiparisi tamamlamak ister misiniz? (e-h)"<<endl;
                        string karar;
                        cin>>karar;
                        if(karar=="e")
                            siparis1.siparisver();
                            system("cls");
                            main();
                    }

                    else if (kategorisecimi == 4)
                    {
                        cout << "Elbise kategorisindeki urunler:" << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            cout << i + 1 << "." << kiyafett.elbise[i] << endl;
                        }
                        cout << "SEPETE EKLEMEK ISTEDIGINIZ URUNU SECINIZ(1..50) :";
                        int a;
                        cin >> a;
                        siparis1.sepet.push_back(kiyafett.elbise[a]);
                        siparis1.sepetfiyat.push_back(kiyafett.elbisefiyat[a]);
                        siparis1.kiyafetozellestir();
                        system("cls");
                        cout<<"\nSepete eklendi"<<endl;
                        cout<<"\nSiparisi tamamlamak ister misiniz? (e-h)"<<endl;
                        string karar;
                        cin>>karar;
                        if(karar=="e")
                            siparis1.siparisver();
                            system("cls");
                            main();
                    }

                    else if (kategorisecimi == 5)
                    {
                        cout << "Tshirt kategorisindeki urunler:" << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            cout << i + 1 << "." << kiyafett.tshirt[i] << endl;
                        }
                        cout << "SEPETE EKLEMEK ISTEDIGINIZ URUNU SECINIZ(1..50) :";
                        int a;
                        cin >> a;
                        siparis1.sepet.push_back(kiyafett.tshirt[a]);
                        siparis1.sepetfiyat.push_back(kiyafett.tshirtfiyat[a]);
                        siparis1.kiyafetozellestir();
                        system("cls");
                        cout<<"\nSepete eklendi"<<endl;
                        cout<<"\nSiparisi tamamlamak ister misiniz? (e-h)"<<endl;
                        string karar;
                        cin>>karar;
                        if(karar=="e")
                            siparis1.siparisver();
                            system("cls");
                            main();
                    }

                    else if (kategorisecimi == 6)
                    {
                        cout << "Gomlek kategorisindeki urunler:" << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            cout << i + 1 << "." << kiyafett.gomlek[i] << endl;
                        }
                        cout << "SEPETE EKLEMEK ISTEDIGINIZ URUNU SECINIZ(1..50) :";
                        int a;
                        cin >> a;
                        siparis1.sepet.push_back(kiyafett.gomlek[a]);
                        siparis1.sepetfiyat.push_back(kiyafett.gomlekfiyat[a]);
                        siparis1.kiyafetozellestir();
                        system("cls");
                        cout<<"\nSepete eklendi"<<endl;
                        cout<<"\nSiparisi tamamlamak ister misiniz? (e-h)"<<endl;
                        string karar;
                        cin>>karar;
                        if(karar=="e")
                        siparis1.siparisver();
                        system("cls");
                        main();
                    }
                    else
                        cout << "\nBoyle bir kategori yok!!!" << endl;
                        system("cls");
                        main();
                }
                else if(sec==2)
                {
                    siparis1.siparistakip();
                }
                else if(sec==3)
                {
                musteri.gorus();
                }
                else if(sec==4)
                {
                 musteri.sifreolustur();
                }
          }
    }
    else
        {
            system("cls");
            main();
        }
    }
    else if (secim == 2) {
        musteri.kayit();
    }
    else if (secim == 3) {
        system("cls");
        cout << "BIZI TERCIH ETTIGINIZ ICIN TESEKKUR EDERİZ. IYI GUNLER DILERIZ  :)\n\n";
    }
    else {
        cout << "lutfen yukaridaki seceneklerden seciniz\n" << endl;
        goto tsec;
    }
}

