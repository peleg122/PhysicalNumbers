//
// Created by Peleg on 05/04/2019.
//
#pragma once
#include "Unit.h"
#include <iostream>
using namespace std;

namespace ariel {
    class PhysicalNumber{
        private:
            double data;
            Unit unit;
        public:
        PhysicalNumber();
            //constructor with initializing list
            PhysicalNumber(double num, Unit type):data(num), unit(type){
                if(type>=0 && type<=2){
                    //should be switch cases better code
                }else if(type>=3 && type<=5){

                }else if(type>=6 && type<=8){

                }else{
                    throw std::invalid_argument( "received wrong value" );
                }
            }
            double GetData(){
                return this->data;
            }
            std::string GetUnit(){
                int temp = this->unit;
                switch (temp){
                    case 0: return "cm";
                    case 1: return "m";
                    case 2: return "km";
                    case 3: return "sec";
                    case 4: return "min";
                    case 5: return "hour";
                    case 6: return "g";
                    case 7: return "kg";
                    case 8: return "ton";
                    case 9: return "bad";
                }
                return "";
            }
            void SetUnit(Unit un){
                this->unit = un;
            }
            void setData(double num){
                this->data=num;
            }

            //Positive

            friend ariel::PhysicalNumber operator+( PhysicalNumber & a,  PhysicalNumber& b);
            friend ariel::PhysicalNumber& operator+=(PhysicalNumber& b,const ariel::PhysicalNumber& a);

            //negative
            friend PhysicalNumber operator-(PhysicalNumber& a, PhysicalNumber& b);
            friend ariel::PhysicalNumber& operator-=(PhysicalNumber& b,const ariel::PhysicalNumber& a);
            friend PhysicalNumber operator-(PhysicalNumber& a);//not const cuz we do need to change number

            //comparison
            friend bool operator== (const PhysicalNumber& a,const PhysicalNumber& b);
            friend bool operator>= (const PhysicalNumber& a,const PhysicalNumber& b);
            friend bool operator<= (const PhysicalNumber& a,const PhysicalNumber& b);
            friend bool operator> (const PhysicalNumber& a,const PhysicalNumber& b);
            friend bool operator< (const PhysicalNumber& a,const PhysicalNumber& b);
            friend bool operator!= (const PhysicalNumber& a,const PhysicalNumber& b);

            //++,--
            friend PhysicalNumber& operator++(PhysicalNumber& a, int); //num++
            friend PhysicalNumber& operator++(PhysicalNumber& a);//++num

            friend PhysicalNumber& operator--(PhysicalNumber& a, int); //num++
            friend PhysicalNumber& operator--(PhysicalNumber& a);//++num
            //input output
            friend istream& operator>> (istream& in, ariel::PhysicalNumber& a);
            friend ostream& operator<<(ostream& out,const ariel::PhysicalNumber& a);

            //calculation function
            void Calculation(ariel::PhysicalNumber &a, ariel::PhysicalNumber& b);
    };
}
