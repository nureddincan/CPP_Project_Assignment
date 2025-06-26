#include <iostream>
#include <fstream>
#include <string>
#include "Mekan.h"
#include "Oturan.h"
#include "DosyaIslemleri.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");
	
    ofstream dosya("mekan.txt", ios::trunc);
    dosya.close();
    ofstream dosya1("odeme.txt", ios::trunc);
    dosya1.close(); 
    ofstream dosya2("data.txt", ios::trunc);
    dosya2.close();
    ofstream dosya3("HavuzKul.txt", ios::trunc);
    dosya3.close();
    ofstream dosya4("Fitness.txt", ios::trunc);
    dosya4.close();

    const int maxMekanSayisi = 100;
    const int maxOturanSayisi = 100;

	// Mekan s�n�f�ndan t�retilmi� nesneleri i�aret eden bir dizi.
    Mekan* mekanlar[maxMekanSayisi]; 
    Oturan* oturanlar[maxOturanSayisi];

    int mekanSayisi = 0;
    int oturanSayisi = 0;

    mekanlar[mekanSayisi++] = new Fitness("Fitness Salonu"); // Bir Fitness nesnesi olu�turur.

    mekanlar[mekanSayisi++] = new Havuz("Yuzme Havuzu"); 	 // Bir Havuz nesnesi olu�turur.
    mekanKaydet(mekanlar, mekanSayisi);

    int secim;

    do {
        cout << "\n1. Mekan ��lemleri\n";
        cout << "2. Oturan ��lemleri\n";
        cout << "3. �deme ��lemleri\n";
        cout << "4. Havuz Giri�\n";
        cout << "5. Fitness Giri�\n";
        cout << "6. ��k��\n";
        cout << "Se�iminizi yap�n: ";
        cin >> secim;

        switch (secim) {
        case 1: {
            int mekanSecim;
            do {
                cout << "\n1. Mekan Ekle\n";
                cout << "2. Mekanlar� G�r�nt�le\n";
                cout << "3. Mekan G�ncelle\n";
                cout << "4. Mekan Sil\n";
                cout << "5. Geri\n";
                cout << "Se�iminizi yap�n: ";
                cin >> mekanSecim;

                switch (mekanSecim) {
                case 1:
                    if (mekanSayisi < maxMekanSayisi) {
                        string mekanAdi;
                        cout << "Mekan ad� girin (Daire): ";
                        cin >> mekanAdi; 
                        if (mekanAdi == "Daire") {
                            string daireNo;
                            cout << "Daire numaras�n� girin: ";
                            cin >> daireNo;
                            mekanlar[mekanSayisi++] = new Daire(daireNo);
                            cout << daireNo << " numaral� daire eklendi!" << endl;
                            mekanKaydet(mekanlar, mekanSayisi);
                            break;
                        }
                    }
                    else {
                        cout << "Mekan say�s� limitini a�t�n�z!" << endl;
                    }
                    break;

                case 2: {
                    mekanOku();
                    break;
                }

                case 3: {
                    mekanGuncelle(mekanlar, mekanSayisi);
                    break;
                }

                case 4: {
                    string mekanAdi;
                    cout << "Daire numaras�n� girin: ";
                    cin >> mekanAdi;

                    mekanSil(mekanlar, mekanSayisi, mekanAdi);
                    break;
                }
                
                case 5:
                    break;
                    
                default:
                    cout << "Ge�ersiz se�enek!" << endl;
                    break;
                }
                
            } while (mekanSecim != 5);
            
            break;
        }

        case 2: {
            int oturanSecim;
            do {
                cout << "\n1. Oturan Ekle\n";
                cout << "2. Oturanlar� G�r�nt�le\n";
                cout << "3. Oturan Sil\n";
                cout << "4. Oturan G�ncelle\n";
                cout << "5. Geri\n";
                cout << "Se�iminizi yap�n: ";
                cin >> oturanSecim;

                switch (oturanSecim) {
                case 1: {
                    string oturanAdi, daireNo,misafirmi;
                    cout << "Misafir mi? (E/H): ";
                    cin >> misafirmi;
                    cout << "Oturan ad� girin: ";
                    cin >> oturanAdi;
                    cout << "Daire numaras�n� girin: ";
                    cin >> daireNo;
                    if (misafirmi == "E"|| misafirmi == "e")
                    {
                        oturanlar[oturanSayisi++] = new Misafir(oturanAdi, daireNo);
                    }
                    else
                    {
                        oturanlar[oturanSayisi++] = new AileReisi(oturanAdi, daireNo);
                    }
                    oturanKaydet(oturanlar, oturanSayisi);
                    break;
                }
                
                case 2: {
                    oturanOku();
                    break;
                }
                
                case 3: {
                    string silinecekAd;
                    cout << "Silmek istedi�iniz oturan�n ad�n� girin: ";
                    cin >> silinecekAd;
                    oturanSil(oturanlar, oturanSayisi, silinecekAd);
                    break;
                }
                
                case 4: {
                    string eskiAd, yeniAd, yeniDaire;
                    cout << "G�ncellenecek oturan�n ad�n� girin: ";
                    cin >> eskiAd;
                    cout << "Yeni ad� girin: ";
                    cin >> yeniAd;
                    cout << "Yeni daire numaras�n� girin: ";
                    cin >> yeniDaire;
                    oturanGuncelle(oturanlar, oturanSayisi, eskiAd, yeniAd, yeniDaire);
                    break;
                }
                
                case 5:
                    break;
                    
                default:
                    cout << "Ge�ersiz se�enek!" << endl;
                    break;
                }
                
            } while (oturanSecim != 5);
            
			break;
        }

        case 3: {
            int odemeSecim;
            do {
                cout << "\n1. �deme Ekle\n";
                cout << "2. �deme G�r�nt�le\n";
                cout << "3. �deme Sil\n";
                cout << "4. �demeleri G�ncelle\n";
                cout << "5. ��k��\n";
                cout << "Se�iminizi yap�n: ";
                cin >> secim;

                cin.ignore();

                switch (secim) {
                case 1: {
                    string odemeno,odemebilgi;
                    cout << "Daire numaras�n� girin: ";
                    getline(cin, odemeno);
                    cout << "�deme durumunu girin (Odedi/Odenmedi): ";
                    getline(cin, odemebilgi);
                    odemeno = odemeno + ": " + odemebilgi;
                    odemeKaydet(odemeno);
                    break;
                }
                
                case 4: {
                    string daireNo, yeniDurum;
                    cout << "G�ncellenecek daire numaras�n� girin: ";
                    cin >> daireNo;
                    cout << "Yeni �deme durumunu girin (Odedi/Odenmedi): ";
                    cin.ignore();
                    getline(cin, yeniDurum);

                    odemeGuncelle(daireNo, yeniDurum);
                    break;
                }
                
                case 3: {
                    string daireNo;
                    cout << "�demesi silinecek daire numaras�n� girin: ";
                    cin >> daireNo;

                    odemeSil(daireNo);
                    break;
                }
                
                case 2: {
                    odemeOku();
                    break;
                }
                
                case 5:
                    cout << "��k�l�yor..." << endl;
                    break;
                    
                default:
                    cout << "Ge�ersiz se�enek!" << endl;
                    break;
                }
                cout << endl;
                
            } while (secim != 5);
            
            break;
        }
        
        case 4: {
              string daireNo;
              cout << "Daire numaras�n� girin: ";
              cin >> daireNo;

              havuzKullanimKontrol(daireNo);
              break;
        }
        
        case 5: {
            string daireNo;
            cout << "Daire numaras�n� girin: ";
            cin >> daireNo;

            fitnessKullanimKontrol(daireNo);
            break;
        }
        
        case 6: {
            cout << "��k�l�yor..." << endl;
            break;
        }

        default: {
               cout << "Ge�ersiz se�enek!" << endl;
               break;
        }
        
        }

    } while (secim != 6);
	// Program sona erdi�inde bellekte olu�turulan nesneler silinir.
    for (int i = 0; i < mekanSayisi; i++) {
        delete mekanlar[i];
    }
    for (int i = 0; i < oturanSayisi; i++) {
        delete oturanlar[i];
    }

    return 0;
}
