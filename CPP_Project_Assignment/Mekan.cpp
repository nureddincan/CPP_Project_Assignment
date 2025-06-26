#include "Mekan.h"

Daire::Daire(string ad) {
    mekanAdi = ad;
    mekanTuru = "Daire";
}

void Daire::yaz() {
    cout << "Daire Adý: " << mekanAdi << endl;
}
// Dairenin adýný, "Daire: [ad]" formatýnda bir metin olarak döndürür.
string Daire::toString() {
    return "Daire: " + mekanAdi; 
}

Fitness::Fitness(string ad) {
    mekanAdi = ad;
    mekanTuru = "Fitness";
}

void Fitness::yaz() {
    cout << "Fitness Alaný: " << mekanAdi << endl;
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
