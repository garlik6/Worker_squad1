//
// Created by Grigory on 12.12.2020.
//

#ifndef UNTITLED7_CREW_H
#define UNTITLED7_CREW_H
#include <utility>
#include"../vector.h"
#include "../Units/Unit.h"
#include "../Units/Master.h"
#include"../Units/Worker.h"
#include "../Fields/Field.h"
namespace crew {
    class crew {
    private:
        my_template::vector<units::Unit *> squad;
        my_template::vector<fields::Field> real_estate;
        bool commander_here;
    public:
        explicit crew(bool commander_here = true):commander_here(commander_here),squad(), real_estate(){};
        crew (bool commander_here,my_template::vector<units::Unit *> squad, my_template::vector<fields::Field> real_estate):
                                    commander_here(commander_here),squad(std::move(squad)), real_estate(std::move(real_estate)){};
        void add_field(const fields::Field& s){real_estate.push_back(s);};
        my_template::vector<fields::Field> get_Fields(){return real_estate;};
        my_template::vector<units::Unit*> get_Squad(){return squad;};
        void add_unit(units::Unit* unit){this->squad.push_back(unit);};
        int find_unit_on_field(units::Unit*unit);
        int find_unit_in_squad(int id);
        int add_unit(int id, int n);
        void between_jobs(int id);
        int workforce(int n);
        void show_progress ();
        int check_remaining_work();
        int get_initial_work();
        int update_workload();
        void show_friends(int n);
        void show_enemy(int n);
        void random_friend();
        void random_enemy();
        void set_commander_here(bool commander_here){this->commander_here = commander_here;}
        bool get_commander_here() const {return commander_here;}
    };
}















class pBar {
public:
    void update(double newProgress) {
        currentProgress += newProgress;
        amountOfFiller = (int)((currentProgress / neededProgress)*(double)pBarLength);
    }
    void print() {
        currUpdateVal %= pBarUpdater.length();
        std::cout << "\r" //Bring cursor to start of line
             << firstPartOfpBar; //Print out first part of pBar
        for (int a = 0; a < amountOfFiller; a++) { //Print out current progress
            std::cout << (pBarFiller);
        }
        std::cout << pBarUpdater[currUpdateVal];
        for (int b = 0; b < pBarLength - amountOfFiller; b++) { //Print out spaces
            std::cout << " ";
        }
        std::cout << lastPartOfpBar //Print out last part of progress bar
             << " (" << (int)(100*(currentProgress/neededProgress)) << "%)" //This just prints out the percent
             << std::flush;
        currUpdateVal += 1;
    }
    std::string firstPartOfpBar = "[", //Change these at will (that is why I made them public)
    lastPartOfpBar = "]",
            pBarFiller = "|",
            pBarUpdater = "/-\\|";
private:
    int amountOfFiller,
            pBarLength = 50, //I would recommend NOT changing this
    currUpdateVal = 0; //Do not change
    double currentProgress = 0, //Do not change
    neededProgress = 100; //I would recommend NOT changing this
};






#endif //UNTITLED7_CREW_H
