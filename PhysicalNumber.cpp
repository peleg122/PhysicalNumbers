#include "PhysicalNumber.h"
#include"Unit.h"
#include<string>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>

using namespace std;
/////////////////////help1////////////////////////////////////////
bool checkElement(ariel::Unit a, ariel::Unit b) {
    if((a>=0 && a<=2)&&(b>=0 && b<=2)){
        return true;
    }else if((a>=3 && a<=5)&&(b>=3 && b<=5)){
        return true;
    }else if((a>=6 && a<=8)&&(b>=6 && b<=8)){
        return true;
    }else{
        return false;
    }
}
//////////////////////help2////////////////////////////////////////////////
double castData(ariel::PhysicalNumber a, ariel::PhysicalNumber b){
    double ans;
    if(a.GetUnit() == b.GetUnit()){
        ans = 1;
    }else if(a.GetUnit()=="CM"){
        if(b.GetUnit()=="M"){ ans = 100;}
        else if(b.GetUnit()=="KM"){ ans = 100000;}
    }else if(a.GetUnit()=="M"){
        if(b.GetUnit()=="CM"){ ans = (double)1/100;}
        else if(b.GetUnit()=="KM"){ ans = 1000;}
    }else if(a.GetUnit()=="KM"){
        if(b.GetUnit()=="CM"){ ans = (double)1/100000;}
        else if(b.GetUnit()=="M"){ ans = (double)1/1000;}
    }else if(a.GetUnit()=="SEC"){
        if(b.GetUnit()=="MIN"){ ans = 60;}
        else if(b.GetUnit()=="HOUR"){ ans = 3600;}
    }else if(a.GetUnit()=="MIN"){
        if(b.GetUnit()=="SEC"){ ans = (double)1/60;}
        else if(b.GetUnit()=="HOUR"){ ans = 60;}
    }else if(a.GetUnit()=="HOUR"){
        if(b.GetUnit()=="SEC"){ ans = (double)1/3600;}
        else if(b.GetUnit()=="MIN"){ ans = (double)1/60;}
    }else if(a.GetUnit()=="G"){
        if(b.GetUnit()=="KG"){ans = 1000;}
        else if(b.GetUnit()=="TON"){ ans = 1000000;}
    }else if(a.GetUnit()=="KG"){
        if(b.GetUnit()=="G"){ ans =(double)1/1000;}
        else if(b.GetUnit()=="TON"){ ans = 1000;}
    }else if(a.GetUnit()=="TON"){
        if(b.GetUnit()=="G"){ ans =(double)1/1000000;}
        else if(b.GetUnit()=="KG"){ ans = (double)1/1000;}
    }else
    {
        throw invalid_argument("no");
    }
    return ans;
}

//Positive
///////////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber ariel::PhysicalNumber::operator+(const ariel::PhysicalNumber &b) {
    PhysicalNumber h(0, Unit::M);
    double mult;
    if(!checkElement(this->unit,b.unit)){
        throw std::invalid_argument("Cannot use addition on different unit types!");    }else{
        mult = castData(*this, b);
        h.setUnit(this->unit);
        h.setData(this->data+(b.data*mult));
    }
    return h;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber &ariel::operator+=(ariel::PhysicalNumber &a, const ariel::PhysicalNumber &b) {
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        a.setData(a.data+(b.data*mult));
    }
    return a;
}

//negative///////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber ariel::PhysicalNumber::operator-(const ariel::PhysicalNumber &b) {
    PhysicalNumber h(0, Unit::M);
    double mult;
    if(!checkElement(this->unit,b.unit)){
        throw std::invalid_argument("Cannot use addition on different unit types!");    }else{
        mult = castData(*this, b);
        h.setUnit(this->unit);
        h.setData(this->data-(b.data*mult));
    }
    return h;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber &ariel::operator-=(ariel::PhysicalNumber &a, const ariel::PhysicalNumber &b) {
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        a.setData(a.data-(b.data*mult));
    }
    return a;
}
/////////////////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber ariel::PhysicalNumber::operator-() {//unary -
    PhysicalNumber a(-(this->data),this->unit);
    return a;
}
///////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber ariel::PhysicalNumber::operator+() const{//unary +
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////
//comparison
bool ariel::operator==(const PhysicalNumber &a, const PhysicalNumber &b) {
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        return (a.data==b.data*mult);
    }
}
////////////////////////////////////////////////////////////////////////////////////
bool ariel::operator!=(const PhysicalNumber &a, const PhysicalNumber &b){
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        return (a.data!=b.data*mult);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
bool ariel::operator>=(const PhysicalNumber &a, const PhysicalNumber &b) {
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        return (a.data>=b.data*mult);
    }
}
/////////////////////////////////////////////////////////////////////////////////
bool ariel::operator <= (const PhysicalNumber &a, const PhysicalNumber &b) {
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        return (a.data<=b.data*mult);
    }
}
/////////////////////////////////////////////////////////////////////////////
bool ariel::operator>(const PhysicalNumber &a, const PhysicalNumber &b) {
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        return (a.data>b.data*mult);
    }
}
/////////////////////////////////////////////////////////////////////////////////
bool ariel::operator<(const PhysicalNumber &a, const PhysicalNumber &b) {
    double mult;
    if(!checkElement(a.unit,b.unit)){
        throw invalid_argument("no");
    }else{
        mult = castData(a,b);
        return (a.data<b.data*mult);
    }
}

////////////////////////////////////////////////////////////////////////////////////
//++/--
ariel::PhysicalNumber &ariel::operator++(ariel::PhysicalNumber &a) {///++num
    a.setData(a.data+1);
    return a;
}
/////////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber ariel::PhysicalNumber::operator++(int x) // post
{
    PhysicalNumber tmp = *this;
    ++this->data;
    x;
    return tmp;
}
////////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber &ariel::operator--(ariel::PhysicalNumber &a) {//--num
    a.setData(a.data-1);
    return a;
}
////////////////////////////////////////////////////////////////////////////////////
ariel::PhysicalNumber ariel::PhysicalNumber::operator--(int x) // post
{
    PhysicalNumber tmp = *this;
    --this->data;
    return tmp;
}
////////////////////////////////////////////////////////////////////////////////////
//input output
static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar)
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}

istream& ariel::operator>>(istream& input, ariel::PhysicalNumber &a) {
    double f;string s;
    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();
    if ( (!(input >> a.data))                 ||
         (!getAndCheckNextCharIs(input,'[')) ||
         (!(input >> s))                 ||
         (!(getAndCheckNextCharIs(input,']'))) ) {

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    } else {
        a.data = f;
        string s2=s.substr(1,s.length()-2);
        if(s2=="cm")a.setUnit(CM);
        else if(s2=="m")a.setUnit(M);
        else if(s2=="km")a.setUnit(KM);
        else if(s2=="sec")a.setUnit(SEC);
        else if(s2=="min")a.setUnit(MIN);
        else if(s2=="hour")a.setUnit(HOUR);
        else if(s2=="g")a.setUnit(G);
        else if(s2=="kg")a.setUnit(KG);
        else if(s2=="ton")a.setUnit(TON);
    }
    /*input>>a.data;
    input>>s;
    string s2=s.substr(1,s.length()-2);
    if(s2=="cm")a.setUnit(CM);
    else if(s2=="m")a.setUnit(M);
    else if(s2=="km")a.setUnit(KM);
    else if(s2=="sec")a.setUnit(SEC);
    else if(s2=="min")a.setUnit(MIN);
    else if(s2=="hour")a.setUnit(HOUR);
    else if(s2=="g")a.setUnit(G);
    else if(s2=="kg")a.setUnit(KG);
    else if(s2=="ton")a.setUnit(TON);
    else{
        throw invalid_argument("Not a unit in this program");
    }*/
    return input;
}
////////////////////////////////////////////////////////////////////////////////////
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
        default: throw invalid_argument("noo");
    }
    out<<setprecision(6)<< a.data << "[" <<t<<"]";
    return out;
}

ariel::PhysicalNumber::PhysicalNumber() {
    this->data=0;
    this->unit=BAD;
}



