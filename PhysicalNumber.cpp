#pragma
#include "PhysicalNumber.h"
using namespace std;
//Positive


ariel::PhysicalNumber &ariel::operator+=(ariel::PhysicalNumber &b, const ariel::PhysicalNumber &a) {
    return b;
}

//negative
ariel::PhysicalNumber ariel::operator-(PhysicalNumber &a, PhysicalNumber &b) {
    return PhysicalNumber(0, Unit::HOUR);
}

ariel::PhysicalNumber ariel::operator-=(PhysicalNumber &number, PhysicalNumber &other) {
    return PhysicalNumber(0, Unit::HOUR);
}

ariel::PhysicalNumber ariel::operator-(PhysicalNumber &a) {
    return PhysicalNumber(0, Unit::HOUR);
}

//comparison
bool ariel::operator==(const PhysicalNumber &a, const PhysicalNumber &b) {
    return true;
}

bool ariel::operator>=(const PhysicalNumber &a, const PhysicalNumber &b) {
    return true;
}

bool ariel::operator <= (const PhysicalNumber &a, const PhysicalNumber &b) {
    return true;
}

bool ariel::operator>(const PhysicalNumber &a, const PhysicalNumber &b) {
    return true;
}

bool ariel::operator<(const PhysicalNumber &a, const PhysicalNumber &b) {
    return true;
}

bool ariel::operator!=(const PhysicalNumber &a, const PhysicalNumber &b) {
    return true;
}

istream& ariel::operator>>(istream &in, ariel::PhysicalNumber &a) {
    //in>>a.data >> a.unit;
    return in;
}

ostream& ariel::operator<<(ostream &out,const ariel::PhysicalNumber &a) {
    int temp = a.unit;
    string t ="";
    switch (temp){
        case 0: t= "cm";break;
        case 1: t= "m";break;
        case 2: t= "km";break;
        case 3: t= "sec";break;
        case 4: t= "min";break;
        case 5: t= "hour";break;
        case 6: t= "g";break;
        case 7: t= "kg";break;
        case 8: t= "ton";break;
        case 9: t= "bad";break;
    }
    out<< a.data << "[" <<t<<"]";
    return out;
}




//
