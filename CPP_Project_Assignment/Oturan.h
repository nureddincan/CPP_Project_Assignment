#ifndef OTURAN_H
#define OTURAN_H

#include <iostream>
#include <string>
using namespace std;

class Oturan {
protected:
    string isim;
    string daire;
public:
    string getAd() const { return isim; } // Oturanýn adýný döndürür.
    void setAd(const string& ad) { isim = ad; } // Oturanýn adýný ayarlar.

    string getDaireNo() const { return daire; }  // Oturanýn daire numarasýný döndürür.
    void setDaireNo(const string& daireNo) { daire = daireNo; } // Oturanýn daire numarasýný ayarlar.

    virtual void yaz() = 0; // Oturan bilgilerini ekrana yazdýrýr.
    virtual string toString() = 0; // Oturan bilgilerini bir metin olarak döndürür.
};

class AileReisi : public Oturan {
public:
    AileReisi(string ad, string daireNo);
    void yaz() override;
    string toString() override;
};

class Misafir : public Oturan {
public:
    Misafir(string ad, string daireNo);
    void yaz() override;
    string toString() override;
};

#endif
