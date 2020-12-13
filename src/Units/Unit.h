//
// Created by Grigory on 11.12.2020.
//
#pragma once
#ifndef UNTITLED6_UNIT_H
#define UNTITLED6_UNIT_H
#include <iostream>
#include <utility>
#include "../vector.h"
namespace units {
    /*!
\brief Абстрактный базовый класс юнит
*/
    class Unit {
    protected:
        virtual ~Unit(){};
        int id;
        int Age;
        int busy;
        my_template::vector<int> Friend_group;
        my_template::vector<int> Enemy_group;
        virtual std::ostream& show(std::ostream&)const = 0;
        virtual std::istream& get(std::istream&) = 0;
    public:        /*!
        \brief Инициализирующий конструктор
        \param Age возраст
        \param busy участок работы
        \param id персональный уникальный идентифткатор
        */
        explicit Unit(int id=0,int Age = 20, int busy = -1):id(id), Age(Age), Friend_group(), Enemy_group(), busy(busy){};
        /*!
\brief Инициализирующий конструктор со всеми полями
        \param Age возраст
        \param busy участок работы
        \param id персональный уникальный идентифткатор
         \param Enemy_group вектор содержащий номера групп врагов
         \param Friend_group вектор содержащий номера групп друзей
*/
        Unit(int id,int Age, my_template::vector<int> Friend_group, my_template::vector<int> Enemy_group, int busy):
                id(id), Age(Age), Friend_group(std::move(Friend_group)), Enemy_group(std::move(Enemy_group)), busy(busy){};
        /*!
\brief Копирующий конструктор

*/
        Unit(const Unit &Unit);
        /*!
\brief метод клонирования

*/
        virtual Unit* clone() const = 0;
        /*!
\brief перегруженный оператор вывода

*/
        friend std::ostream& operator <<(std::ostream &, const Unit &);
        /*!
\brief перегруженный оператор ввода

*/
        friend std::istream& operator >>(std::istream &, Unit &);
        /*!
\brief перегруженный оператор присваивания

*/
        Unit & operator = (const Unit& Unit);
        /*!
\brief Функция показывающая вид рабочего

*/
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
        virtual int get_Work() = 0;
        virtual void set_Busy(int busy){};
        virtual int get_Busy(){return busy;};

    };

}
#endif //UNTITLED6_UNIT_H
