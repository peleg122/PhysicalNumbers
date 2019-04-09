#pragma once
#include "PhysicalNumber.h"
using namespace std;


//
// Created by Peleg on 05/04/2019.
//
ariel::PhysicalNumber::PhysicalNumber() {//default constructor
    this->data=0;
    this->unit=BAD;
}

//Positive
ariel::PhysicalNumber ariel::PhysicalNumber::operator+(const ariel::PhysicalNumber &second) {
    PhysicalNumber temp;
    temp.SetUnit(this->unit);
    if (this->unit == 0 && second.unit == 0) { //case 1 : unit first is CM
        temp.setData(this->data + second.data);//"cm"+"cm"
    } else if (this->unit == 0 && second.unit == 1) {
        temp.setData(this->data + second.data * 100);//"cm"+"m"*100
    } else if (this->unit == 0 && second.unit == 2) {
        temp.setData(this->data + second.data * 100000);//"cm"+"km"*100,000
    } else if (this->unit == 1 && second.unit == 0) {//case 2 : unit first is Meters
        temp.setData(this->data + second.data / 100);//"m"+"cm"/100
    } else if (this->unit == 1 && second.unit == 1) {
        temp.setData(this->data + second.data);//"m"+"m"
    } else if (this->unit == 1 && second.unit == 2) {
        temp.setData(this->data + second.data * 1000);//"m"+"km"*1000
    } else if (this->unit == 2 && second.unit == 0) {//case 3: unit first is KM
        temp.setData(this->data + second.data / 100000);//"km"+"sm"/100,000
    } else if (this->unit == 2 && second.unit == 1) {
        temp.setData(this->data + second.data / 1000);//"km"+"m"/1000
    } else if (this->unit == 2 && second.unit == 2) {
        temp.setData(this->data + second.data);//"km"+"km"
    } else if (this->unit == 3 && second.unit == 3) {//case 1 : unit first is sec
        temp.setData(this->data + second.data);//"sec"+"sec"
    } else if (this->unit == 3 && second.unit == 4) {
        temp.setData(this->data + second.data * 60);//"sec"+"min"*60
    } else if (this->unit == 3 && second.unit == 5) {
        temp.setData(this->data + second.data * 3600);//"sec"+"hour"*3600
    } else if (this->unit == 4 && second.unit == 3) {//case 2 : unit first is min
        temp.setData(this->data + second.data / 60);//"min"+"sec"/60
    } else if (this->unit == 4 && second.unit == 4) {
        temp.setData(this->data + second.data);//"min"+"min"
    } else if (this->unit == 4 && second.unit == 5) {
        temp.setData(this->data + second.data * 60);//"min"+"hour"*60
    } else if (this->unit == 5 && second.unit == 3) {//case 3: unit first is hour
        temp.setData(this->data + second.data / 3600);//"hour"+"sec"/3600
    } else if (this->unit == 5 && second.unit == 4) {
        temp.setData(this->data + second.data / 60);//"hour"+"min"/60
    } else if (this->unit == 5 && second.unit == 5) {
        temp.setData(this->data + second.data);//"hour"+"hour"
    } else if (this->unit == 6 && second.unit == 6) { //case 1 : unit first is gram
        temp.setData(this->data + second.data);//"gram"+"gram"
    } else if (this->unit == 6 && second.unit == 7) {
        temp.setData(this->data + second.data * 1000);//"gram"+"kg"*1000
    } else if (this->unit == 6 && second.unit == 8) {
        temp.setData(this->data + second.data / 1000000);//"gram"+"ton"*1,000,000
    } else if (this->unit == 7 && second.unit == 6) {//case 2 : unit first is kg
        temp.setData(this->data + second.data / 1000);//"kg"+"gram"/1000
    } else if (this->unit == 7 && second.unit == 7) {
        temp.setData(this->data + second.data);//"kg"+"kg"
    } else if (this->unit == 7 && second.unit == 8) {
        temp.setData(this->data + second.data * 1000);//"kg"+"ton"*1,000
    } else if (this->unit == 8 && second.unit == 6) {//case 3: unit first is ton
        temp.setData(this->data + second.data / 1000000);//"ton"+"gram"/1,000,000
    } else if (this->unit == 8 && second.unit == 7) {
        temp.setData(this->data + second.data / 1000);//"ton"+"kg"/1000
    } else if (this->unit == 8 && second.unit == 8) {
        temp.setData(this->data + second.data);//"ton"+"ton"
    } else {
        cout<<"wrong units"<<endl; //
        throw std::invalid_argument("received wrong Units");
    }
    return temp;
}

ariel::PhysicalNumber &ariel::operator+=(ariel::PhysicalNumber &first, const ariel::PhysicalNumber &secnd) {
    if (first.unit == 0 && secnd.unit == 0) { //case 1 : unit first is CM
        first.setData(first.data + secnd.data);//"cm"+"cm"
    } else if (first.unit == 0 && secnd.unit == 1) {
        first.setData(first.data + secnd.data * 100);//"cm"+"m"*100
    } else if (first.unit == 0 && secnd.unit == 2) {
        first.setData(first.data + secnd.data * 100000);//"cm"+"km"*100,000
    } else if (first.unit == 1 && secnd.unit == 0) {//case 2 : unit first is Meters
        first.setData(first.data + secnd.data / 100);//"m"+"cm"/100
    } else if (first.unit == 1 && secnd.unit == 1) {
        first.setData(first.data + secnd.data);//"m"+"m"
    } else if (first.unit == 1 && secnd.unit == 2) {
        first.setData(first.data + secnd.data * 1000);//"m"+"km"*1000
    } else if (first.unit == 2 && secnd.unit == 0) {//case 3: unit first is KM
        first.setData(first.data + secnd.data / 100000);//"km"+"sm"/100,000
    } else if (first.unit == 2 && secnd.unit == 1) {
        first.setData(first.data + secnd.data / 1000);//"km"+"m"/1000
    } else if (first.unit == 2 && secnd.unit == 2) {
        first.setData(first.data + secnd.data);//"km"+"km"
    } else if (first.unit == 3 && secnd.unit == 3) {//case 1 : unit first is sec
        first.setData(first.data + secnd.data);//"sec"+"sec"
    } else if (first.unit == 3 && secnd.unit == 4) {
        first.setData(first.data + secnd.data * 60);//"sec"+"min"*60
    } else if (first.unit == 3 && secnd.unit == 5) {
        first.setData(first.data + secnd.data * 3600);//"sec"+"hour"*3600
    } else if (first.unit == 4 && secnd.unit == 3) {//case 2 : unit first is min
        first.setData(first.data + secnd.data / 60);//"min"+"sec"/60
    } else if (first.unit == 4 && secnd.unit == 4) {
        first.setData(first.data + secnd.data);//"min"+"min"
    } else if (first.unit == 4 && secnd.unit == 5) {
        first.setData(first.data + secnd.data * 60);//"min"+"hour"*60
    } else if (first.unit == 5 && secnd.unit == 3) {//case 3: unit first is hour
        first.setData(first.data + secnd.data / 3600);//"hour"+"sec"/3600
    } else if (first.unit == 5 && secnd.unit == 4) {
        first.setData(first.data + secnd.data / 60);//"hour"+"min"/60
    } else if (first.unit == 5 && secnd.unit == 5) {
        first.setData(first.data + secnd.data);//"hour"+"hour"
    } else if (first.unit == 6 && secnd.unit == 6) { //case 1 : unit first is gram
        first.setData(first.data + secnd.data);//"gram"+"gram"
    } else if (first.unit == 6 && secnd.unit == 7) {
        first.setData(first.data + secnd.data * 1000);//"gram"+"kg"*1000
    } else if (first.unit == 6 && secnd.unit == 8) {
        first.setData(first.data + secnd.data / 1000000);//"gram"+"ton"*1,000,000
    } else if (first.unit == 7 && secnd.unit == 6) {//case 2 : unit first is kg
        first.setData(first.data + secnd.data / 1000);//"kg"+"gram"/1000
    } else if (first.unit == 7 && secnd.unit == 7) {
        first.setData(first.data + secnd.data);//"kg"+"kg"
    } else if (first.unit == 7 && secnd.unit == 8) {
        first.setData(first.data + secnd.data * 1000);//"kg"+"ton"*1,000
    } else if (first.unit == 8 && secnd.unit == 6) {//case 3: unit first is ton
        first.setData(first.data + secnd.data / 1000000);//"ton"+"gram"/1,000,000
    } else if (first.unit == 8 && secnd.unit == 7) {
        first.setData(first.data + secnd.data / 1000);//"ton"+"kg"/1000
    } else if (first.unit == 8 && secnd.unit == 8) {
        first.setData(first.data + secnd.data);//"ton"+"ton"
    } else {
        cout<<"wrong units"<<endl;
        throw std::invalid_argument("received wrong Units");
    }
    return first;
}

//negative
ariel::PhysicalNumber ariel::PhysicalNumber::operator-(const ariel::PhysicalNumber &second) {
    PhysicalNumber temp;
    temp.SetUnit(this->unit);
    if (this->unit == 0 && second.unit == 0) { //case 1 : unit first is CM
        temp.setData(this->data - second.data);//"cm"+"cm"
    } else if (this->unit == 0 && second.unit == 1) {
        temp.setData(this->data - second.data * 100);//"cm"+"m"*100
    } else if (this->unit == 0 && second.unit == 2) {
        temp.setData(this->data - second.data * 100000);//"cm"+"km"*100,000
    } else if (this->unit == 1 && second.unit == 0) {//case 2 : unit first is Meters
        temp.setData(this->data - second.data / 100);//"m"+"cm"/100
    } else if (this->unit == 1 && second.unit == 1) {
        temp.setData(this->data - second.data);//"m"+"m"
    } else if (this->unit == 1 && second.unit == 2) {
        temp.setData(this->data - second.data * 1000);//"m"+"km"*1000
    } else if (this->unit == 2 && second.unit == 0) {//case 3: unit first is KM
        temp.setData(this->data - second.data / 100000);//"km"+"sm"/100,000
    } else if (this->unit == 2 && second.unit == 1) {
        temp.setData(this->data - second.data / 1000);//"km"+"m"/1000
    } else if (this->unit == 2 && second.unit == 2) {
        temp.setData(this->data - second.data);//"km"+"km"
    } else if (this->unit == 3 && second.unit == 3) {//case 1 : unit first is sec
        temp.setData(this->data - second.data);//"sec"+"sec"
    } else if (this->unit == 3 && second.unit == 4) {
        temp.setData(this->data - second.data * 60);//"sec"+"min"*60
    } else if (this->unit == 3 && second.unit == 5) {
        temp.setData(this->data - second.data * 3600);//"sec"+"hour"*3600
    } else if (this->unit == 4 && second.unit == 3) {//case 2 : unit first is min
        temp.setData(this->data - second.data / 60);//"min"+"sec"/60
    } else if (this->unit == 4 && second.unit == 4) {
        temp.setData(this->data - second.data);//"min"+"min"
    } else if (this->unit == 4 && second.unit == 5) {
        temp.setData(this->data - second.data * 60);//"min"+"hour"*60
    } else if (this->unit == 5 && second.unit == 3) {//case 3: unit first is hour
        temp.setData(this->data - second.data / 3600);//"hour"+"sec"/3600
    } else if (this->unit == 5 && second.unit == 4) {
        temp.setData(this->data - second.data / 60);//"hour"+"min"/60
    } else if (this->unit == 5 && second.unit == 5) {
        temp.setData(this->data - second.data);//"hour"+"hour"
    } else if (this->unit == 6 && second.unit == 6) { //case 1 : unit first is gram
        temp.setData(this->data - second.data);//"gram"+"gram"
    } else if (this->unit == 6 && second.unit == 7) {
        temp.setData(this->data - second.data * 1000);//"gram"+"kg"*1000
    } else if (this->unit == 6 && second.unit == 8) {
        temp.setData(this->data - second.data / 1000000);//"gram"+"ton"*1,000,000
    } else if (this->unit == 7 && second.unit == 6) {//case 2 : unit first is kg
        temp.setData(this->data - second.data / 1000);//"kg"+"gram"/1000
    } else if (this->unit == 7 && second.unit == 7) {
        temp.setData(this->data - second.data);//"kg"+"kg"
    } else if (this->unit == 7 && second.unit == 8) {
        temp.setData(this->data - second.data * 1000);//"kg"+"ton"*1,000
    } else if (this->unit == 8 && second.unit == 6) {//case 3: unit first is ton
        temp.setData(this->data - second.data / 1000000);//"ton"+"gram"/1,000,000
    } else if (this->unit == 8 && second.unit == 7) {
        temp.setData(this->data - second.data / 1000);//"ton"+"kg"/1000
    } else if (this->unit == 8 && second.unit == 8) {
        temp.setData(this->data - second.data);//"ton"+"ton"
    } else {
        cout<<"wrong units"<<endl; //
        throw std::invalid_argument("received wrong Units");
    }
    return temp;
}

ariel::PhysicalNumber &ariel::operator-=(ariel::PhysicalNumber &first, const ariel::PhysicalNumber &second) {
    if (first.unit == 0 && second.unit == 0) { //case 1 : unit first is CM
        first.setData(first.data - second.data);//"cm"+"cm"
    } else if (first.unit == 0 && second.unit == 1) {
        first.setData(first.data - second.data * 100);//"cm"+"m"*100
    } else if (first.unit == 0 && second.unit == 2) {
        first.setData(first.data - second.data * 100000);//"cm"+"km"*100,000
    } else if (first.unit == 1 && second.unit == 0) {//case 2 : unit first is Meters
        first.setData(first.data - second.data / 100);//"m"+"cm"/100
    } else if (first.unit == 1 && second.unit == 1) {
        first.setData(first.data - second.data);//"m"+"m"
    } else if (first.unit == 1 && second.unit == 2) {
        first.setData(first.data - second.data * 1000);//"m"+"km"*1000
    } else if (first.unit == 2 && second.unit == 0) {//case 3: unit first is KM
        first.setData(first.data - second.data / 100000);//"km"+"sm"/100,000
    } else if (first.unit == 2 && second.unit == 1) {
        first.setData(first.data - second.data / 1000);//"km"+"m"/1000
    } else if (first.unit == 2 && second.unit == 2) {
        first.setData(first.data - second.data);//"km"+"km"
    } else if (first.unit == 3 && second.unit == 3) {//case 1 : unit first is sec
        first.setData(first.data - second.data);//"sec"+"sec"
    } else if (first.unit == 3 && second.unit == 4) {
        first.setData(first.data - second.data * 60);//"sec"+"min"*60
    } else if (first.unit == 3 && second.unit == 5) {
        first.setData(first.data - second.data * 3600);//"sec"+"hour"*3600
    } else if (first.unit == 4 && second.unit == 3) {//case 2 : unit first is min
        first.setData(first.data - second.data / 60);//"min"+"sec"/60
    } else if (first.unit == 4 && second.unit == 4) {
        first.setData(first.data - second.data);//"min"+"min"
    } else if (first.unit == 4 && second.unit == 5) {
        first.setData(first.data - second.data * 60);//"min"+"hour"*60
    } else if (first.unit == 5 && second.unit == 3) {//case 3: unit first is hour
        first.setData(first.data - second.data / 3600);//"hour"+"sec"/3600
    } else if (first.unit == 5 && second.unit == 4) {
        first.setData(first.data - second.data / 60);//"hour"+"min"/60
    } else if (first.unit == 5 && second.unit == 5) {
        first.setData(first.data - second.data);//"hour"+"hour"
    } else if (first.unit == 6 && second.unit == 6) { //case 1 : unit first is gram
        first.setData(first.data - second.data);//"gram"+"gram"
    } else if (first.unit == 6 && second.unit == 7) {
        first.setData(first.data - second.data * 1000);//"gram"+"kg"*1000
    } else if (first.unit == 6 && second.unit == 8) {
        first.setData(first.data - second.data / 1000000);//"gram"+"ton"*1,000,000
    } else if (first.unit == 7 && second.unit == 6) {//case 2 : unit first is kg
        first.setData(first.data - second.data / 1000);//"kg"+"gram"/1000
    } else if (first.unit == 7 && second.unit == 7) {
        first.setData(first.data - second.data);//"kg"+"kg"
    } else if (first.unit == 7 && second.unit == 8) {
        first.setData(first.data - second.data * 1000);//"kg"+"ton"*1,000
    } else if (first.unit == 8 && second.unit == 6) {//case 3: unit first is ton
        first.setData(first.data - second.data / 1000000);//"ton"+"gram"/1,000,000
    } else if (first.unit == 8 && second.unit == 7) {
        first.setData(first.data - second.data / 1000);//"ton"+"kg"/1000
    } else if (first.unit == 8 && second.unit == 8) {
        first.setData(first.data - second.data);//"ton"+"ton"
    } else {
        cout<<"wrong units"<<endl;
        throw std::invalid_argument("received wrong Units");
    }
    return first;
}

ariel::PhysicalNumber ariel::operator-( ariel::PhysicalNumber &a) {
    return PhysicalNumber(-(a.data),a.unit);
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

ariel::PhysicalNumber &ariel::operator++(ariel::PhysicalNumber &a, int) {
    a.setData(a.data+1);
    return a;
}

ariel::PhysicalNumber &ariel::operator++(ariel::PhysicalNumber &a) {
    a.setData(a.data+1);
    return a;
}

ariel::PhysicalNumber &ariel::operator--(ariel::PhysicalNumber &a, int) {
    a.setData(a.data-1);
    return a;
}
ariel::PhysicalNumber &ariel::operator--(ariel::PhysicalNumber &a) {
    a.setData(a.data-1);
    return a;
}

ariel::PhysicalNumber ariel::operator+(ariel::PhysicalNumber &a) {//unary plus
    return a;
}

istream& ariel::operator>>(istream &in, ariel::PhysicalNumber &a) {
    in>>a.data ;
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
