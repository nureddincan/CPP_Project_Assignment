#ifndef MEKAN_H
#define MEKAN_H

#include <iostream>
#include <string>
using namespace std;

class Mekan {
protected:
    string mekanTuru;
public:
    string mekanAdi;
    virtual void yaz() = 0;
    virtual string toString() = 0;

    string getMekanAdi() const { return mekanAdi; }
    void setMekanAdi(const string& ad) { mekanAdi = ad; }
};

class Daire : public Mekan {
public:
    Daire(string ad);
    void yaz() override;
    string toString() override;
};

class Fitness : public Mekan {
public:
    Fitness(string ad);
    void yaz() override;
    string toString() override;
};

class Havuz : public Mekan {
public:
    Havuz(string ad);
    void yaz() override;
    string toString() override;
};

#endif
