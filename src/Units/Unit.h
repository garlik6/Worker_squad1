//
// Created by Grigory on 11.12.2020.
//
#ifndef UNTITLED6_UNIT_H
#define UNTITLED6_UNIT_H
#include <iostream>
#include "../vector.h"
namespace units {
    class Unit {
    protected:
        int id;
        int Age;
        my_template::vector<int> Friend_group;
        my_template::vector<int> Enemy_group;
        virtual std::ostream& show(std::ostream&)const = 0;
        virtual std::istream& get(std::istream&) = 0;
    public:
        explicit Unit(int id = 0,int Age = 18):id(id), Age(Age), Friend_group(), Enemy_group(){};
        Unit(const Unit &Unit);
        virtual Unit* clone() const = 0;
        friend std::ostream& operator <<(std::ostream &, const Unit &);
        friend std::istream& operator >>(std::istream &, Unit &);
        Unit & operator = (const Unit& Unit);
        virtual int iAm() const = 0;
        virtual int get_id() const = 0;
        virtual int get_Age() const = 0;
        virtual my_template::vector<int> *get_Friend_Group()  = 0;
        virtual my_template::vector<int> *get_Enemy_Group()  = 0;
        virtual void add_Friend(int Friend){};
        virtual void add_Enemy(int Enemy){};
        virtual void set_id(int id){};
        virtual void set_Age(int Age){};
        virtual void set_Work(int Work){};
    };

}
#endif //UNTITLED6_UNIT_H
