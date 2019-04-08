//
// Created by Peleg on 05/04/2019.
//
#include "PhysicalNumber.h"
using namespace std;

//Positive
ariel::PhysicalNumber &ariel::operator+=(ariel::PhysicalNumber &a, const ariel::PhysicalNumber &b) {
    if((a.unit<=2 || a.unit>=0)&&(b.unit<=2 || b.unit>=0)){
        //case 1 : unit a is CM
        if(a.unit==0 && b.unit==0) {
            a.setData(a.data + b.data);//"cm"+"cm"
        }else if(a.unit==0 && b.unit==1) {
            a.setData(a.data + b.data * 100);//"cm"+"m"*100
        }else if(a.unit==0 && b.unit==2){
                 a.setData(a.data+b.data*100000);//"cm"+"km"*100,000
        }else if(a.unit==1 && b.unit==0){//case 2 : unit a is Meters
                 a.setData(a.data+b.data/100);//"m"+"cm"/100
        }else if(a.unit==1 && b.unit==1){
                 a.setData(a.data+b.data);//"m"+"m"
        }else if(a.unit==1 && b.unit==2){
                 a.setData(a.data+b.data*1000);//"m"+"km"*1000
        }else if(a.unit==2 && b.unit==0){//case 3: unit a is KM
                 a.setData(a.data+b.data/100000);//"km"+"sm"/100,000
        }else if(a.unit==2 && b.unit==1){
                 a.setData(a.data+b.data/1000);//"km"+"m"/1000
        }else if(a.unit==2 && b.unit==2){
                 a.setData(a.data+b.data);//"km"+"km"
        }
    }else if((a.unit<=5)||(a.unit>=3)&&(b.unit<=5||b.unit>=3)){
        //case 1 : unit a is sec
        if(a.unit==3 && b.unit==3) {
            a.setData(a.data + b.data);//"sec"+"sec"
        }else if(a.unit==3 && b.unit==4) {
            a.setData(a.data + b.data * 60);//"sec"+"min"*60
        }else if(a.unit==3 && b.unit==5){
                 a.setData(a.data+b.data*3600);//"sec"+"hour"*3600
        }else if(a.unit==4 && b.unit==3){//case 2 : unit a is min
                 a.setData(a.data+b.data/60);//"min"+"sec"/60
        }else if(a.unit==4 && b.unit==4){
                 a.setData(a.data+b.data);//"min"+"min"
        }else if(a.unit==4 && b.unit==5){
                 a.setData(a.data+b.data*3600);//"min"+"hour"*3600
        }else if(a.unit==5 && b.unit==3){//case 3: unit a is hour
                 a.setData(a.data+b.data/3600);//"hour"+"sec"/3600
        }else if(a.unit==5 && b.unit==4){
                 a.setData(a.data+b.data/60);//"hour"+"min"/60
        }else if(a.unit==5 && b.unit==5){
                 a.setData(a.data+b.data);//"hour"+"hour"
        }
    }else if((a.unit<=8)||(a.unit>=6)&&(b.unit<=8||b.unit>=6)){
        //case 1 : unit a is gram
        if(a.unit==6 && b.unit==6) {
            a.setData(a.data + b.data);//"gram"+"gram"
        }else if(a.unit==6 && b.unit==7) {
            a.setData(a.data + b.data * 1000);//"gram"+"kg"*1000
        }else if(a.unit==6 && b.unit==8){
                 a.setData(a.data+b.data*1000000);//"gram"+"ton"*1,000,000
        }else if(a.unit==7 && b.unit==6){//case 2 : unit a is kg
                 a.setData(a.data+b.data/1000);//"kg"+"gram"/1000
        }else if(a.unit==7 && b.unit==7){
                 a.setData(a.data+b.data);//"kg"+"kg"
        }else if(a.unit==7 && b.unit==8){
                 a.setData(a.data+b.data*1000000);//"kg"+"ton"*1,000,000
        }else if(a.unit==8 && b.unit==6){//case 3: unit a is ton
                 a.setData(a.data+b.data/1000000);//"ton"+"gram"/1,000,000
        }else if(a.unit==8 && b.unit==7){
                 a.setData(a.data+b.data/1000);//"ton"+"kg"/1000
        }else if(a.unit==8 && b.unit==8){
                 a.setData(a.data+b.data);//"ton"+"ton"
        }
    }else{
        throw invalid_argument("Not a unit in this program");
    }
    return a;
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
