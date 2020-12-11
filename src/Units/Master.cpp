//
// Created by Grigory on 11.12.2020.
//

#include "Master.h"

namespace units {

    std::ostream &Master::show(std::ostream & os) const {
        os << "M id="<< id <<"Age="<<Age;
        os << "Enemy_Groups:";
        for (int i : Enemy_group) {
            os<<i;
        }
        os << "Friend_Groups:";
        for (int i : Friend_group) {
            os<<i;
        }
        return os;
    }

    std::istream &Master::get(std::istream &is) {
        is >>id >>Age;
        for (int i : Enemy_group) {
            is>>i;
        }
        for (int i : Friend_group) {
            is>>i;
        }
        return is;
    }
    }

