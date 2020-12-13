//
// Created by Grigory on 12.12.2020.
//

#include "Field.h"

std::ostream &fields::operator<<(std::ostream &os, const fields::Field &Field) {
    os << "\n  -->#:"<< Field.n;
    os << "\n  -->work_amount="<< Field.work_amount <<"\n  -->commander_here="<<Field.commander_here;
    os << "\n  -->Ids:";

    for (int i : Field.IDs) {
        os<<i<<",";
    }
    return os<<"\n";
}

std::istream &fields::operator>>(std::istream &is, fields::Field & Field) {
    is>> Field.n >>Field.work_amount >>Field.commander_here;
    for (int i : Field.IDs) {
        is>>i;
    }
    return is;
}

fields::Field &fields::Field::operator=(const fields::Field &Field) {
    if (this != &Field){
        IDs.clear();
        this->IDs = Field.IDs;
        this->work_amount =Field.work_amount;
        this->commander_here = Field.commander_here;
        this->n = Field.n;
    }
    return *this;
}


fields::Field::Field(const fields::Field &Field) {
    if(!Field.IDs.empty()){
        this->IDs = Field.IDs;
        this->work_amount =Field.work_amount;
        this->commander_here = Field.commander_here;
        this->n = Field.n;
    }

}
