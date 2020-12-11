//
// Created by Grigory on 11.12.2020.
//

#include "Unit.h"

std::ostream &units::operator<<(std::ostream &, const units::Unit &) {
}

std::istream &units::operator>>(std::istream &, units::Unit &) {

}

units::Unit::Unit(units::Unit const &Unit) {
    if(!Unit.Enemy_group.empty()){
        this->Enemy_group = Unit.Enemy_group;
        this->id = Unit.id;
        this->Age = Unit.Age;
    }
    if(!Unit.Friend_group.empty()){
        this->Friend_group = Unit.Friend_group;
        this->id = Unit.id;
        this->Age = Unit.Age;
    }
}

units::Unit &units::Unit::operator=(const units::Unit &Unit) {
    if (this != &Unit){
        Friend_group.clear();
        Enemy_group.clear();
        this->Enemy_group = Unit.Enemy_group;
        this->Friend_group = Unit.Friend_group;
    }
    return *this;
}
