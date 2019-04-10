//
// Created by Peleg on 05/04/2019.
//

#include "PhysicalNumber.h"
using namespace std;

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

ariel::PhysicalNumber &ariel::operator+=(ariel::PhysicalNumber &a, const ariel::PhysicalNumber &b) {
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
    else if(a.unit==3 && b.unit==3) {
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
        a.setData(a.data+b.data*60);//"min"+"hour"*60
    }else if(a.unit==5 && b.unit==3){//case 3: unit a is hour
        a.setData(a.data+b.data/3600);//"hour"+"sec"/3600
    }else if(a.unit==5 && b.unit==4){
        a.setData(a.data+b.data/60);//"hour"+"min"/60
    }else if(a.unit==5 && b.unit==5){
        a.setData(a.data+b.data);//"hour"+"hour"
    }
    else if(a.unit==6 && b.unit==6) {
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
        a.setData(a.data+b.data*1000);//"kg"+"ton"*1000
    }else if(a.unit==8 && b.unit==6){//case 3: unit a is ton
        a.setData(a.data+b.data/1000000);//"ton"+"gram"/1,000,000
    }else if(a.unit==8 && b.unit==7){
        a.setData(a.data+b.data/1000);//"ton"+"kg"/1000
    }else if(a.unit==8 && b.unit==8){
        a.setData(a.data+b.data);//"ton"+"ton"
    }
    else{
        throw invalid_argument("Not a unit in this program");
    }
    return a;
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

//comparison
bool ariel::operator==(const PhysicalNumber &a, const PhysicalNumber &b) {
    PhysicalNumber temp;
    temp.SetUnit(a.unit);
    if(a.data>=0 && b.data>=0){
    if((a.unit>=0 || a.unit<=2) && (b.unit>=0 || b.unit<=2)){
        if(a.unit < b.unit){
            switch (a.unit){
                case 0:switch (b.unit){
                        case 1:temp.setData(b.data *100);
                        case 2:temp.setData(b.data * 100000);
                    }
                case 1:switch (b.unit){
                        case 0:temp.setData(b.data /100);
                        case 2:temp.setData(b.data /100000);

                    }
                case 2:switch (b.unit){
                        case 0:temp.setData(b.data *100000);
                        case 1:temp.setData(b.data *1000);
                    }
            }
            if(a.data==temp.data){
                return true;
            }else{
                return false;
            }
        } else if(a.unit==b.unit && a.data==b.data){
            return true;
        }else{
            return false;
        }
    }else if((a.unit>=3 || a.unit<=5) && (b.unit>=3 || b.unit<=5)){
        if(a.unit < b.unit){
            switch (a.unit){
                case 3:switch (b.unit){
                        case 4:temp.setData(b.data *60);
                        case 5:temp.setData(b.data * 3600);
                    }
                case 4:switch (b.unit){
                        case 3:temp.setData(b.data /60);
                        case 5:temp.setData(b.data *60);

                    }
                case 5:switch (b.unit){
                        case 3:temp.setData(b.data /3600);
                        case 4:temp.setData(b.data /60);
                    }
            }
            if(a.data==temp.data){
                return true;
            }else{
                return false;
            }
        } else if(a.unit==b.unit && a.data==b.data){
            return true;
        }else{
            return false;
        }
    }else if((a.unit>=6 || a.unit<=8)  && (b.unit>=6 || b.unit<=8)){
        if(a.unit < b.unit){
            switch (a.unit){
                case 3:switch (b.unit){
                        case 4:temp.setData(b.data *1000);
                        case 5:temp.setData(b.data * 1000000);
                    }
                case 4:switch (b.unit){
                        case 3:temp.setData(b.data /1000);
                        case 5:temp.setData(b.data *1000);
                    }
                case 5:switch (b.unit){
                        case 3:temp.setData(b.data /1000000);
                        case 4:temp.setData(b.data /1000);
                    }
            }
            if(a.data==temp.data){
                return true;
            }else{
                return false;
            }
        }else if(a.unit==b.unit && a.data==b.data){
            return true;
        }else{
            return false;
        }
    }
    }else{
        throw invalid_argument("bad data");
    }
}

bool ariel::operator>=(const PhysicalNumber &a,const PhysicalNumber &b) {
    return !(a < b);
}

bool ariel::operator <= (const  PhysicalNumber &a,const PhysicalNumber &b) {
    return ((a < b) || (a == b));
}

bool ariel::operator>(const  PhysicalNumber &a,const  PhysicalNumber &b) {
    return !(a<=b);
}

bool ariel::operator<(const PhysicalNumber &a,const PhysicalNumber &b) {
    PhysicalNumber temp;
    temp.SetUnit(a.unit);
    if(a.data>=0 && b.data>=0){
        if((a.unit>=0 || a.unit<=2) && (b.unit>=0 || b.unit<=2)){
            if(a.unit < b.unit){
                switch (a.unit){
                    case 0:switch (b.unit){
                            case 1:temp.setData(b.data *100);
                            case 2:temp.setData(b.data * 100000);
                        }
                    case 1:switch (b.unit){
                            case 0:temp.setData(b.data /100);
                            case 2:temp.setData(b.data /100000);

                        }
                    case 2:switch (b.unit){
                            case 0:temp.setData(b.data *100000);
                            case 1:temp.setData(b.data *1000);
                        }
                }
                if(a.data<temp.data){
                    return true;
                }else{
                    return false;
                }
            } else if(a.unit==b.unit && a.data<b.data){
                return true;
            }else{
                return false;
            }
        }else if((a.unit>=3 || a.unit<=5) && (b.unit>=3 || b.unit<=5)){
            if(a.unit < b.unit){
                switch (a.unit){
                    case 3:switch (b.unit){
                            case 4:temp.setData(b.data *60);
                            case 5:temp.setData(b.data * 3600);
                        }
                    case 4:switch (b.unit){
                            case 3:temp.setData(b.data /60);
                            case 5:temp.setData(b.data *60);

                        }
                    case 5:switch (b.unit){
                            case 3:temp.setData(b.data /3600);
                            case 4:temp.setData(b.data /60);
                        }
                }
                if(a.data<temp.data){
                    return true;
                }else{
                    return false;
                }
            } else if(a.unit==b.unit && a.data<b.data){
                return true;
            }else{
                return false;
            }
        }else if((a.unit>=6 || a.unit<=8)  && (b.unit>=6 || b.unit<=8)){
            if(a.unit < b.unit){
                switch (a.unit){
                    case 3:switch (b.unit){
                            case 4:temp.setData(b.data *1000);
                            case 5:temp.setData(b.data * 1000000);
                        }
                    case 4:switch (b.unit){
                            case 3:temp.setData(b.data /1000);
                            case 5:temp.setData(b.data *1000);
                        }
                    case 5:switch (b.unit){
                            case 3:temp.setData(b.data /1000000);
                            case 4:temp.setData(b.data /1000);
                        }
                }
                if(a.data<temp.data){
                    return true;
                }else{
                    return false;
                }
            }else if(a.unit==b.unit && a.data<b.data){
                return true;
            }else{
                return false;
            }
        }
    }else{
        throw invalid_argument("bad data");
    }
}


bool ariel::operator!=(const PhysicalNumber &a,const  PhysicalNumber &b){
    if(a.unit>=0 || a.unit<=2 && b.unit>=0 || b.unit<=2){
        return !(a==b);
    }else if(a.unit>=3 || a.unit<=5 && b.unit>=3 || b.unit<=5){
        return !(a==b);
    }else if(a.unit>=6 || a.unit<=8 && b.unit>=6 || b.unit<=8){
        return !(a==b);
    }else{
        throw invalid_argument("No data good");
    }
}

ariel::PhysicalNumber ariel::operator++(ariel::PhysicalNumber &a, int) {
    PhysicalNumber temp(a.data, a.unit);
    a.setData(a.data+1);
    return temp;
}

ariel::PhysicalNumber &ariel::operator++(ariel::PhysicalNumber &a) {
    a.setData(a.data+1);
    return a;
}

ariel::PhysicalNumber ariel::operator--(ariel::PhysicalNumber &a, int) {
    PhysicalNumber temp(a.data, a.unit);
    a.setData(a.data-1);
    return temp;
}
ariel::PhysicalNumber &ariel::operator--(ariel::PhysicalNumber &a) {
    a.setData(a.data-1);
    return a;
}

istream& ariel::operator>>(istream& in, ariel::PhysicalNumber &a) {
    string s;
    in>>a.data;
    in>>s;
    string s2=s.substr(1,s.length()-2);
    std::cout<<s<<endl;
    std::cout<<s2<<endl;
    if(s2=="cm")a.SetUnit(CM);
    else if(s2=="m")a.SetUnit(M);
    else if(s2=="km")a.SetUnit(KM);
    else if(s2=="sec")a.SetUnit(SEC);
    else if(s2=="min")a.SetUnit(MIN);
    else if(s2=="hour")a.SetUnit(HOUR);
    else if(s2=="g")a.SetUnit(G);
    else if(s2=="kg")a.SetUnit(KG);
    else if(s2=="ton")a.SetUnit(TON);
    else{
        throw invalid_argument("Not a unit in this program");
    }
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


ariel::PhysicalNumber ariel::PhysicalNumber::operator-() {//unary -
    PhysicalNumber a(-(this->data),this->unit);
    return a;
}

ariel::PhysicalNumber ariel::PhysicalNumber::operator+() const{//unary +
    return *this;
}
//ariel::PhysicalNumber r =calco(r, r);
    ariel::PhysicalNumber calco (ariel::PhysicalNumber& a, ariel::PhysicalNumber& b);
 ariel::PhysicalNumber calco( ariel::PhysicalNumber &a, ariel::PhysicalNumber &b) {
    ariel::PhysicalNumber temp;
    temp.SetUnit(a.getUnitNum());
    if (a.getUnitNum() == 0 && b.getUnitNum() == 0) { //case 1 : unit first is CM
        temp.setData(b.GetData());//"cm"+"cm"
    } else if (a.getUnitNum() == 0 && b.getUnitNum() == 1) {
        temp.setData(b.GetData() * 100);//"cm"+"m"*100
    } else if (a.getUnitNum() == 0 && b.getUnitNum() == 2) {
        temp.setData(b.GetData() * 100000);//"cm"+"km"*100,000
    } else if (a.getUnitNum() == 1 && b.getUnitNum() == 0) {//case 2 : unit first is Meters
        temp.setData(b.GetData() / 100);//"m"+"cm"/100
    } else if (a.getUnitNum() == 1 && b.getUnitNum() == 1) {
        temp.setData(b.GetData());//"m"+"m"
    } else if (a.getUnitNum() == 1 && b.getUnitNum() == 2) {
        temp.setData(b.GetData()* 1000);//"m"+"km"*1000
    } else if (a.getUnitNum() == 2 && b.getUnitNum() == 0) {//case 3: unit first is KM
        temp.setData(b.GetData()/ 100000);//"km"+"sm"/100,000
    } else if (a.getUnitNum() == 2 && b.getUnitNum() == 1) {
        temp.setData(b.GetData() / 1000);//"km"+"m"/1000
    } else if (a.getUnitNum() == 2 && b.getUnitNum() == 2) {
        temp.setData(b.GetData());//"km"+"km"
    } else if (a.getUnitNum() == 3 && b.getUnitNum() == 3) {//case 1 : unit first is sec
        temp.setData(b.GetData());//"sec"+"sec"
    } else if (a.getUnitNum() == 3 && b.getUnitNum() == 4) {
        temp.setData(b.GetData() * 60);//"sec"+"min"*60
    } else if (a.getUnitNum() == 3 && b.getUnitNum() == 5) {
        temp.setData(b.GetData() * 3600);//"sec"+"hour"*3600
    } else if (a.getUnitNum() == 4 && b.getUnitNum() == 3) {//case 2 : unit first is min
        temp.setData(b.GetData()/ 60);//"min"+"sec"/60
    } else if (a.getUnitNum()== 4 && b.getUnitNum() == 4) {
        temp.setData(b.GetData());//"min"+"min"
    } else if (a.getUnitNum() == 4 && b.getUnitNum() == 5) {
        temp.setData(b.GetData() * 60);//"min"+"hour"*60
    } else if (a.getUnitNum() == 5 && b.getUnitNum() == 3) {//case 3: unit first is hour
        temp.setData(b.GetData() / 3600);//"hour"+"sec"/3600
    } else if (a.getUnitNum() == 5 && b.getUnitNum() == 4) {
        temp.setData(b.GetData() / 60);//"hour"+"min"/60
    } else if (a.getUnitNum() == 5 && b.getUnitNum() == 5) {
        temp.setData(b.GetData());//"hour"+"hour"
    } else if (a.getUnitNum() == 6 && b.getUnitNum() == 6) { //case 1 : unit first is gram
        temp.setData(b.GetData());//"gram"+"gram"
    } else if (a.getUnitNum() == 6 && b.getUnitNum() == 7) {
        temp.setData(b.GetData() * 1000);//"gram"+"kg"*1000
    } else if (a.getUnitNum() == 6 && b.getUnitNum() == 8) {
        temp.setData(b.GetData() / 1000000);//"gram"+"ton"*1,000,000
    } else if (a.getUnitNum() == 7 && b.getUnitNum() == 6) {//case 2 : unit first is kg
        temp.setData(b.GetData() / 1000);//"kg"+"gram"/1000
    } else if (a.getUnitNum() == 7 && b.getUnitNum() == 7) {
        temp.setData(b.GetData());//"kg"+"kg"
    } else if (a.getUnitNum() == 7 && b.getUnitNum() == 8) {
        temp.setData(b.GetData()* 1000);//"kg"+"ton"*1,000
    } else if (a.getUnitNum() == 8 && b.getUnitNum() == 6) {//case 3: unit first is ton
        temp.setData(b.GetData()/ 1000000);//"ton"+"gram"/1,000,000
    } else if (a.getUnitNum() == 8 && b.getUnitNum() == 7) {
        temp.setData(b.GetData() / 1000);//"ton"+"kg"/1000
    } else if (a.getUnitNum() == 8 && b.getUnitNum() == 8) {
        temp.setData(b.GetData());//"ton"+"ton"
    }
    return temp;
}
