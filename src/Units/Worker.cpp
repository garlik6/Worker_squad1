//
// Created by Grigory on 11.12.2020.
//

#include "Worker.h"
#include "Master.h"

namespace units{
    std::ostream &Worker::show(std::ostream & os) const {
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

    std::istream &Worker::get(std::istream &is) {
        is >>id >>Age>>busy;
        for (int i : Enemy_group) {
            is>>i;
        }
        for (int i : Friend_group) {
            is>>i;
        }
        return is;
    }

    Master Worker::upgrade() {
        Master Upper = Master(id, Age, Friend_group, Enemy_group, Work_Count, busy);
        Enemy_group.clear();
        Friend_group.clear();
        return  Upper;
    }

    Worker &Worker::operator=(const Worker &Worker) {
            if (this != &Worker){
                Friend_group.clear();
                Enemy_group.clear();
                this->Enemy_group = Worker.Enemy_group;
                this->Friend_group = Worker.Friend_group;
                this->Work_Count = Worker.Work_Count;
                this->busy = Worker.busy;
            }
            return *this;

    }

    Worker::Worker(const Worker &Worker)  : Unit(Worker) {
        if(!Worker.Enemy_group.empty()){
            this->Enemy_group = Worker.Enemy_group;


        }
        if(!Worker.Friend_group.empty()){
            this->Friend_group = Worker.Friend_group;

        }
        this->id = Worker.id;
        this->Age = Worker.Age;
        this->busy = Worker.busy;
        this->Work_Count = Worker.Work_Count;

    }



}