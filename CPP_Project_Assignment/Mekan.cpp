#include "Mekan.h"

Daire::Daire(string ad) {
    mekanAdi = ad;
    mekanTuru = "Daire";
}

void Daire::yaz() {
    cout << "Daire Ad�: " << mekanAdi << endl;
}
// Dairenin ad�n�, "Daire: [ad]" format�nda bir metin olarak d�nd�r�r.
string Daire::toString() {
    return "Daire: " + mekanAdi; 
}

Fitness::Fitness(string ad) {
    mekanAdi = ad;
    mekanTuru = "Fitness";
}

void Fitness::yaz() {
    cout << "Fitness Alan�: " << mekanAdi << endl;
}

string Fitness::toString() {
    return "Fitness: " + mekanAdi;
}

Havuz::Havuz(string ad) {
    mekanAdi = ad;
    mekanTuru = "Havuz";
}

void Havuz::yaz() {
    cout << "Havuz: " << mekanAdi << endl;
}

string Havuz::toString() {
    return "Havuz: " + mekanAdi;
}
