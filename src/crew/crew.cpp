//
// Created by Grigory on 12.12.2020.
//

#include "crew.h"
#include <Windows.h>
#include <iostream>
#include <cstdlib>

int crew::crew::add_unit(int id, int n) {
            int i = find_unit_in_squad(id);
            if (i == -1) return -1;
            int busy = squad[i]->get_Busy();
            if (busy >= 0) {
                std::cout << "\n This Unit is busy on field" << busy;
                real_estate[busy].get_IDs().erase(this->find_unit_on_field(squad[i]));//вырезаем из IDs найденного работника
            }
            real_estate[n].get_IDs().push_back(id);
            squad[i]->set_Busy(n);
            return 1;
        }


void crew::crew::between_jobs(int id) {
    int i = find_unit_in_squad(id);
    if (i == -1) return;
    real_estate[squad[i]->get_Busy()].get_IDs().erase(find_unit_on_field(squad[i]));// вырезаем из IDs
    squad.erase(i);//вырезаем из squad
}

int crew::crew::workforce(int n) {
    int workforce = 0;
    int multiplier = 1;
    int n_unit;
    for (int i = 0; i < real_estate[n].get_IDs().length(); ++i) {
        n_unit = real_estate[n].get_IDs()[i];
        if (squad[this->find_unit_in_squad(n_unit)]->iAm() == 1)
            workforce += squad[this->find_unit_in_squad(n_unit)]->get_Work();
        if (squad[this->find_unit_in_squad(n_unit)]->iAm() == 2)
            multiplier *= squad[this->find_unit_in_squad(n_unit)]->get_Work();
    }
    return workforce*multiplier;
}

int crew::crew::check_remaining_work() {
    int wl;
    for (auto & i : real_estate) {
        wl += i.get_work_amount();
    }
    return wl;
}

void crew::crew::show_friends(int n) {

}

void crew::crew::show_enemy(int n) {

}

void crew::crew::random_friend() {

}

void crew::crew::random_enemy() {

}

int crew::crew::find_unit_on_field(units::Unit *unit) {
        for (int i = 0; i < real_estate[unit->get_Busy()].get_IDs().length(); ++i) {
            if(real_estate[unit->get_Busy()].get_IDs()[i] == unit->get_id())
            {
                return i;
            }
            return -1;
        }
    }

int crew::crew::find_unit_in_squad(int id) {
    for (int i = 0; i < squad.length(); ++i) {
        if (id == squad[i]->get_id()) {
            return i;
        }
        return -1;
    }
}

int crew::crew::update_workload() {
    int wa;
    for (int i = 0; i < real_estate.length(); ++i) {
        wa = real_estate[i].get_work_amount() - workforce(i);
        real_estate[i].set_work_amount(wa);
    }
    return 0;
}

void crew::crew::show_progress() {
    //Setup:
    pBar bar;
    //Main loop:
    for (int i= this->get_initial_work() - this->check_remaining_work(); i < this->check_remaining_work(); i++) { //This can be any loop, but I just made this as an example
        //Update pBar:
        bar.update(1); //How much new progress was added (only needed when new progress was added)
        //Print pBar:
        bar.print(); //This should be called more frequently than it is in this demo (you'll have to see what looks best for your program)
        Sleep(6);
    }
    std::cout << std::endl;
}

int crew::crew::get_initial_work() {
    int wl;
    for (auto & i : real_estate) {
        wl += i.get_work_amount();
    }
    return wl;
}


