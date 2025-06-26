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
    string getAd() const { return isim; } // Oturan�n ad�n� d�nd�r�r.
    void setAd(const string& ad) { isim = ad; } // Oturan�n ad�n� ayarlar.

    string getDaireNo() const { return daire; }  // Oturan�n daire numaras�n� d�nd�r�r.
    void setDaireNo(const string& daireNo) { daire = daireNo; } // Oturan�n daire numaras�n� ayarlar.

    virtual void yaz() = 0; // Oturan bilgilerini ekrana yazd�r�r.
    virtual string toString() = 0; // Oturan bilgilerini bir metin olarak d�nd�r�r.
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
