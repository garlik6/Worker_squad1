//
// Created by Grigory on 12.12.2020.
//

#ifndef UNTITLED7_RAND_H
#define UNTITLED7_RAND_H

#endif //UNTITLED7_RAND_H
#include"../../crew/crew.h"
#include<random>
#include<ctime>
namespace random_ {
    int rand_age() {
        srand(time(nullptr)); // автоматическая рандомизация
        int Age = 18 + rand() % 44;
        return Age;
    }

    int rand_unique_id(crew::crew Crew) {
        int id;
        bool flag = true;
        while (flag) {
            flag = false;
            srand(time(nullptr)); // автоматическая рандомизация
            id = 100 + rand() % 800;
            for (int i = 0; i < Crew.get_Squad().length(); ++i) {
                if (Crew.get_Squad()[i]->get_id() == id)
                    flag = true;
            }
        }
        return id;
    }
}