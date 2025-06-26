#include "DosyaIslemleri.h"
#include <fstream>
#include <iostream>

using namespace std;

void mekanKaydet(Mekan* mekanlar[], int mekanSayisi) {
    ofstream mekanDosyasi("mekan.txt", ios::out);
    if (mekanDosyasi.is_open()) {
        for (int i = 0; i < mekanSayisi; i++) {
            mekanDosyasi << mekanlar[i]->toString() << endl;
        }
        mekanDosyasi.close();
        cout << "Mekanlar dosyaya kaydedildi!" << endl;
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void mekanGuncelle(Mekan* mekanlar[], int mekanSayisi) {
    int guncellemeIndex;
    cout << "G�ncellemek istedi�iniz mekan�n numaras�n� girin (3-" << mekanSayisi << "): ";
    cin >> guncellemeIndex;
    if (guncellemeIndex > 2) {
    	if (guncellemeIndex < 1 || guncellemeIndex > mekanSayisi) {
        	cout << "Ge�ersiz mekan numaras�!" << endl;
        	return;
    	}

    	string yeniAdi;
    	cout << "Yeni daire numaras�n� girin: ";
    	cin >> yeniAdi;

    	mekanlar[guncellemeIndex - 1]->mekanAdi = yeniAdi;

    	mekanKaydet(mekanlar, mekanSayisi);
    	cout << "Mekan ba�ar�yla g�ncellendi!" << endl;
    }
    else {
    	cout << "Ge�ersiz mekan numaras�!" << endl;
    }
}

void mekanSil(Mekan* mekanlar[], int& mekanSayisi, const string& mekanAdi) {
    bool bulundu = false;
    for (int i = 0; i < mekanSayisi; i++) {
        if (mekanlar[i]->getMekanAdi() == mekanAdi) {
            delete mekanlar[i]; 
            for (int j = i; j < mekanSayisi - 1; j++) {
                mekanlar[j] = mekanlar[j + 1];
            }
            mekanSayisi--;
            bulundu = true;
            cout << mekanAdi << " adl� mekan silindi!" << endl;
            break;
        }
    }
    
    if (bulundu) {
        ofstream mekanDosyasi("mekan.txt", ios::out); 
        if (mekanDosyasi.is_open()) {
            for (int i = 0; i < mekanSayisi; i++) {
                mekanDosyasi << mekanlar[i]->toString() << endl;
            }
            mekanDosyasi.close();
            cout << "Dosya g�ncellendi." << endl;
        }
        else {
            cout << "Dosya a��lamad�!" << endl;
        }
    }
    else {
        cout << mekanAdi << " adl� mekan bulunamad�!" << endl;
    }
}

void mekanOku() {
    ifstream mekanDosyasi("mekan.txt");
    string line;
    if (mekanDosyasi.is_open()) {
    	cout << endl;
        while (getline(mekanDosyasi, line)) {
            cout << line << endl;
        }
        mekanDosyasi.close();
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void oturanKaydet(Oturan* oturanlar[], int oturanSayisi) {
    ofstream oturanDosyasi("data.txt", ios::out);
    if (oturanDosyasi.is_open()) {
        for (int i = 0; i < oturanSayisi; i++) {
            oturanDosyasi << oturanlar[i]->toString() << endl;
        }
        oturanDosyasi.close();
        cout << "Oturanlar dosyaya kaydedildi!" << endl;
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void oturanOku() {
    ifstream oturanDosyasi("data.txt");
    string line;
    if (oturanDosyasi.is_open()) {
    	cout << endl;
        while (getline(oturanDosyasi, line)) {
            cout << line << endl;
        }
        oturanDosyasi.close();
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}
void oturanGuncelle(Oturan* oturanlar[], int oturanSayisi, const string& eskiAd, const string& yeniAd, const string& yeniDaire) {
    bool bulundu = false;

    for (int i = 0; i < oturanSayisi; i++) {
        if (oturanlar[i]->getAd() == eskiAd) { 
            oturanlar[i]->setAd(yeniAd);         
            oturanlar[i]->setDaireNo(yeniDaire);
            bulundu = true;
            cout << eskiAd << " adl� oturan g�ncellendi!" << endl;
            break;
        }
    }

    if (!bulundu) {
        cout << eskiAd << " adl� oturan bulunamad�!" << endl;
    }
    else {
        oturanKaydet(oturanlar, oturanSayisi); 
    }
}

void oturanSil(Oturan* oturanlar[], int& oturanSayisi, const string& oturanAdi) {
    bool bulundu = false;

    for (int i = 0; i < oturanSayisi; i++) {
        if (oturanlar[i]->getAd() == oturanAdi) { 
            delete oturanlar[i]; 
            for (int j = i; j < oturanSayisi - 1; j++) {
                oturanlar[j] = oturanlar[j + 1]; 
            }
            oturanSayisi--;
            bulundu = true;
            cout << oturanAdi << " adl� oturan silindi!" << endl;
            break;
        }
    }

    if (!bulundu) {
        cout << oturanAdi << " adl� oturan bulunamad�!" << endl;
    }
    else {
        oturanKaydet(oturanlar, oturanSayisi); 
    }
}

void odemeKaydet(string odemeBilgisi) {
    ofstream odemeDosyasi("odeme.txt", ios::app);
    if (odemeDosyasi.is_open()) {
        odemeDosyasi << odemeBilgisi << endl;
        odemeDosyasi.close();
        cout << "�deme kaydedildi!" << endl;
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void odemeGuncelle(const string& daireNo, const string& yeniDurum) {
    ifstream dosyaOku("odeme.txt");
    ofstream geciciDosya("temp.txt");

    bool bulundu = false;
    string satir;

    if (dosyaOku.is_open() && geciciDosya.is_open()) {
        while (getline(dosyaOku, satir)) {
            size_t pos = satir.find(':');
            if (pos != string::npos && satir.substr(0, pos) == daireNo) {
                geciciDosya << daireNo << ": " << yeniDurum << endl;
                bulundu = true;
            }
            else {
                geciciDosya << satir << endl;
            }
        }
        dosyaOku.close();
        geciciDosya.close();

        remove("odeme.txt");
        rename("temp.txt", "odeme.txt");

        if (bulundu)
            cout << daireNo << " numaral� �deme durumu g�ncellendi!" << endl;
        else
            cout << daireNo << " numaral� daire bulunamad�!" << endl;
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void odemeSil(const string& daireNo) {
    ifstream dosyaOku("odeme.txt");
    ofstream geciciDosya("temp.txt");

    bool bulundu = false;
    string satir;

    if (dosyaOku.is_open() && geciciDosya.is_open()) {
        while (getline(dosyaOku, satir)) {
            size_t pos = satir.find(':');
            if (pos != string::npos && satir.substr(0, pos) == daireNo) {
                bulundu = true;
                continue;
            }
            geciciDosya << satir << endl;
        }

        dosyaOku.close();
        geciciDosya.close();

        remove("odeme.txt");
        rename("temp.txt", "odeme.txt");

        if (bulundu)
            cout << daireNo << " numaral� �deme kayd� silindi!" << endl;
        else
            cout << daireNo << " numaral� daire bulunamad�!" << endl;
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void odemeOku() {
    ifstream odemeDosyasi("odeme.txt");
    string line;
    if (odemeDosyasi.is_open()) {
    	cout << endl;
        while (getline(odemeDosyasi, line)) {
            cout << line << endl;
        }
        odemeDosyasi.close();
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void havuzKullanimKontrol(const string& daireNo) {
    ifstream odemeDosyasi("odeme.txt"); 
    ofstream havuzDosyasi("HavuzKul.txt", ios::app); 

    bool odemeBulundu = false;
    string satir;

    if (odemeDosyasi.is_open() && havuzDosyasi.is_open()) {
        if (odemeDosyasi.is_open()) {
            string satir;
            while (getline(odemeDosyasi, satir)) {
                size_t pos = satir.find(":");
                if (pos != string::npos) {
                    string mekanTuru = satir.substr(0, pos);
                    string mekanAdi = satir.substr(pos + 1);
                    if (mekanTuru ==daireNo) {
                    	if (mekanAdi == " Odedi" || mekanAdi == " Odendi" || mekanAdi == " Odenildi") {
                        	havuzDosyasi << daireNo << " - Kullandirildi" << endl;
                        	cout << daireNo << " numaral� daire havuz kullan�m� kaydedildi: Kullandirildi" << endl;
                    	}
                    	else{
                        	havuzDosyasi << daireNo << " - Kullandirilmadi" << endl;
                        	cout << daireNo << " numaral� daire havuz kullan�m� kaydedildi: Kullandirilmadi" << endl;
                    	}
                	}
                }
            }
        }
        odemeDosyasi.close();
        havuzDosyasi.close();
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}

void fitnessKullanimKontrol(const string& daireNo) {
    ifstream odemeDosyasi("odeme.txt"); 
    ofstream havuzDosyasi("Fitness.txt", ios::app);

    bool odemeBulundu = false;
    string satir;

    if (odemeDosyasi.is_open() && havuzDosyasi.is_open()) {
        if (odemeDosyasi.is_open()) {
            string satir;
            while (getline(odemeDosyasi, satir)) {
                size_t pos = satir.find(":");
               	if (pos != string::npos) {
                    string mekanTuru = satir.substr(0, pos);
                    string mekanAdi = satir.substr(pos + 1);
                    if (mekanTuru ==daireNo) {
                    	if (mekanAdi == " Odedi" || mekanAdi == " Odendi" || mekanAdi == " Odenildi") {
                        	havuzDosyasi << daireNo << " - Kullandirildi" << endl;
                        	cout << daireNo << " numaral� daire fitness kullan�m� kaydedildi: Kullandirildi" << endl;
                    	}
                    	else {
                        	havuzDosyasi << daireNo << " - Kullandirilmadi" << endl;
                        	cout << daireNo << " numaral� daire fitness kullan�m� kaydedildi: Kullandirilmadi" << endl;
                    	}
               		}
                }
            }
        }
        odemeDosyasi.close();
        havuzDosyasi.close();
    }
    else {
        cout << "Dosya a��lamad�!" << endl;
    }
}
