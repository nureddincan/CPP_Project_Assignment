#include "Oturan.h"

AileReisi::AileReisi(string ad, string daireNo) {
    isim = ad;
    daire = daireNo;
}

void AileReisi::yaz() {
    cout << "Aile Reisi: " << isim << " Daire: " << daire << endl;
}

string AileReisi::toString() {
    return "Aile Reisi: " + isim + " Daire: " + daire;
}

Misafir::Misafir(string ad, string daireNo) {
    isim = ad;
    daire = daireNo;
}

void Misafir::yaz() {
    cout << "Misafir: " << isim << " Daire: " << daire << endl;
}

string Misafir::toString() {
    return "Misafir: " + isim + " Daire: " + daire;
}
