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

	// Mekan sýnýfýndan türetilmiþ nesneleri iþaret eden bir dizi.
    Mekan* mekanlar[maxMekanSayisi]; 
    Oturan* oturanlar[maxOturanSayisi];

    int mekanSayisi = 0;
    int oturanSayisi = 0;

    mekanlar[mekanSayisi++] = new Fitness("Fitness Salonu"); // Bir Fitness nesnesi oluþturur.

    mekanlar[mekanSayisi++] = new Havuz("Yuzme Havuzu"); 	 // Bir Havuz nesnesi oluþturur.
    mekanKaydet(mekanlar, mekanSayisi);

    int secim;

    do {
        cout << "\n1. Mekan Ýþlemleri\n";
        cout << "2. Oturan Ýþlemleri\n";
        cout << "3. Ödeme Ýþlemleri\n";
        cout << "4. Havuz Giriþ\n";
        cout << "5. Fitness Giriþ\n";
        cout << "6. Çýkýþ\n";
        cout << "Seçiminizi yapýn: ";
        cin >> secim;

        switch (secim) {
        case 1: {
            int mekanSecim;
            do {
                cout << "\n1. Mekan Ekle\n";
                cout << "2. Mekanlarý Görüntüle\n";
                cout << "3. Mekan Güncelle\n";
                cout << "4. Mekan Sil\n";
                cout << "5. Geri\n";
                cout << "Seçiminizi yapýn: ";
                cin >> mekanSecim;

                switch (mekanSecim) {
                case 1:
                    if (mekanSayisi < maxMekanSayisi) {
                        string mekanAdi;
                        cout << "Mekan adý girin (Daire): ";
                        cin >> mekanAdi; 
                        if (mekanAdi == "Daire") {
                            string daireNo;
                            cout << "Daire numarasýný girin: ";
                            cin >> daireNo;
                            mekanlar[mekanSayisi++] = new Daire(daireNo);
                            cout << daireNo << " numaralý daire eklendi!" << endl;
                            mekanKaydet(mekanlar, mekanSayisi);
                            break;
                        }
                    }
                    else {
                        cout << "Mekan sayýsý limitini aþtýnýz!" << endl;
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
                    cout << "Daire numarasýný girin: ";
                    cin >> mekanAdi;

                    mekanSil(mekanlar, mekanSayisi, mekanAdi);
                    break;
                }
                
                case 5:
                    break;
                    
                default:
                    cout << "Geçersiz seçenek!" << endl;
                    break;
                }
                
            } while (mekanSecim != 5);
            
            break;
        }

        case 2: {
            int oturanSecim;
            do {
                cout << "\n1. Oturan Ekle\n";
                cout << "2. Oturanlarý Görüntüle\n";
                cout << "3. Oturan Sil\n";
                cout << "4. Oturan Güncelle\n";
                cout << "5. Geri\n";
                cout << "Seçiminizi yapýn: ";
                cin >> oturanSecim;

                switch (oturanSecim) {
                case 1: {
                    string oturanAdi, daireNo,misafirmi;
                    cout << "Misafir mi? (E/H): ";
                    cin >> misafirmi;
                    cout << "Oturan adý girin: ";
                    cin >> oturanAdi;
                    cout << "Daire numarasýný girin: ";
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
                    cout << "Silmek istediðiniz oturanýn adýný girin: ";
                    cin >> silinecekAd;
                    oturanSil(oturanlar, oturanSayisi, silinecekAd);
                    break;
                }
                
                case 4: {
                    string eskiAd, yeniAd, yeniDaire;
                    cout << "Güncellenecek oturanýn adýný girin: ";
                    cin >> eskiAd;
                    cout << "Yeni adý girin: ";
                    cin >> yeniAd;
                    cout << "Yeni daire numarasýný girin: ";
                    cin >> yeniDaire;
                    oturanGuncelle(oturanlar, oturanSayisi, eskiAd, yeniAd, yeniDaire);
                    break;
                }
                
                case 5:
                    break;
                    
                default:
                    cout << "Geçersiz seçenek!" << endl;
                    break;
                }
                
            } while (oturanSecim != 5);
            
			break;
        }

        case 3: {
            int odemeSecim;
            do {
                cout << "\n1. Ödeme Ekle\n";
                cout << "2. Ödeme Görüntüle\n";
                cout << "3. Ödeme Sil\n";
                cout << "4. Ödemeleri Güncelle\n";
                cout << "5. Çýkýþ\n";
                cout << "Seçiminizi yapýn: ";
                cin >> secim;

                cin.ignore();

                switch (secim) {
                case 1: {
                    string odemeno,odemebilgi;
                    cout << "Daire numarasýný girin: ";
                    getline(cin, odemeno);
                    cout << "Ödeme durumunu girin (Odedi/Odenmedi): ";
                    getline(cin, odemebilgi);
                    odemeno = odemeno + ": " + odemebilgi;
                    odemeKaydet(odemeno);
                    break;
                }
                
                case 4: {
                    string daireNo, yeniDurum;
                    cout << "Güncellenecek daire numarasýný girin: ";
                    cin >> daireNo;
                    cout << "Yeni ödeme durumunu girin (Odedi/Odenmedi): ";
                    cin.ignore();
                    getline(cin, yeniDurum);

                    odemeGuncelle(daireNo, yeniDurum);
                    break;
                }
                
                case 3: {
                    string daireNo;
                    cout << "Ödemesi silinecek daire numarasýný girin: ";
                    cin >> daireNo;

                    odemeSil(daireNo);
                    break;
                }
                
                case 2: {
                    odemeOku();
                    break;
                }
                
                case 5:
                    cout << "Çýkýlýyor..." << endl;
                    break;
                    
                default:
                    cout << "Geçersiz seçenek!" << endl;
                    break;
                }
                cout << endl;
                
            } while (secim != 5);
            
            break;
        }
        
        case 4: {
              string daireNo;
              cout << "Daire numarasýný girin: ";
              cin >> daireNo;

              havuzKullanimKontrol(daireNo);
              break;
        }
        
        case 5: {
            string daireNo;
            cout << "Daire numarasýný girin: ";
            cin >> daireNo;

            fitnessKullanimKontrol(daireNo);
            break;
        }
        
        case 6: {
            cout << "Çýkýlýyor..." << endl;
            break;
        }

        default: {
               cout << "Geçersiz seçenek!" << endl;
               break;
        }
        
        }

    } while (secim != 6);
	// Program sona erdiðinde bellekte oluþturulan nesneler silinir.
    for (int i = 0; i < mekanSayisi; i++) {
        delete mekanlar[i];
    }
    for (int i = 0; i < oturanSayisi; i++) {
        delete oturanlar[i];
    }

    return 0;
}
