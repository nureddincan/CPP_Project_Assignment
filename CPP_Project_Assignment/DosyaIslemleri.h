#ifndef DOSYAISLEMLERI_H
#define DOSYAISLEMLERI_H

#include "Mekan.h"
#include "Oturan.h"
#include <string>

void mekanKaydet(Mekan* mekanlar[], int mekanSayisi);
void mekanGuncelle(Mekan* mekanlar[], int mekanSayisi);
void mekanSil(Mekan* mekanlar[], int& mekanSayisi, const string& mekanAdi);
void mekanOku();

void oturanKaydet(Oturan* oturanlar[], int oturanSayisi);
void oturanOku();
void oturanGuncelle(Oturan* oturanlar[], int oturanSayisi, const string& eskiAd, const string& yeniAd, const string& yeniDaire);
void oturanSil(Oturan* oturanlar[], int& oturanSayisi, const string& oturanAdi);

void odemeKaydet(std::string odemeBilgisi);
void odemeGuncelle(const string& daireNo, const string& yeniDurum);
void odemeSil(const string& daireNo);
void odemeOku();

void havuzKullanimKontrol(const string& daireNo);
void fitnessKullanimKontrol(const string& daireNo);

#endif
