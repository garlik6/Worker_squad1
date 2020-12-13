//
// Created by Grigory on 11.12.2020.
//

#include "Master.h"

namespace units {
    std::ostream &Master::show(std::ostream & os) const {
        os << "W\n  -->id="<< id <<"\n  -->Age="<<"\n  -->busy="<<busy;
        os << "\n  -->Enemy_Groups:";
        for (int i : Enemy_group) {
            os<<i<<",";
        }
        os << "\n  -->Friend_Groups:";
        for (int i : Friend_group) {
            os<<i<<",";
        }
        return os<<"\n";
    }

    std::istream &Master::get(std::istream &is) {
        is >>id >>Age>>busy;
        for (int i : Enemy_group) {
            is>>i;
        }
        for (int i : Friend_group) {
            is>>i;
        }
        return is;
    }

    Master &Master::operator=(const Master &Master) {
        if (this != &Master){
            Friend_group.clear();
            Enemy_group.clear();
            this->Enemy_group = Master.Enemy_group;
            this->Friend_group = Master.Friend_group;
            this->Work_Count = Master.Work_Count;
            this->busy = Master.busy;
        }
        return *this;
    }

    Master::Master(const Master &Master)  : Unit(Master) {
        if (!Master.Enemy_group.empty()) {
            this->Enemy_group = Master.Enemy_group;

        }
        if (!Master.Friend_group.empty()) {
            this->Friend_group = Master.Friend_group;
        }
        this->id = Master.id;
        this->Age = Master.Age;
        this->busy = Master.busy;
        this->Work_Count = Master.Work_Count;
    }
}

