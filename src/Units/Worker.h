//
// Created by Grigory on 11.12.2020.
//

#ifndef UNTITLED6_WORKER_H
#define UNTITLED6_WORKER_H
#include "Unit.h"
namespace units {
    class Master : public Unit {
    private:
        int Work_Count;
        std::ostream& show(std::ostream&)const override;
        std::istream& get(std::istream&) override;
    public:
        Master();
        virtual Master* clone() const
        {
            return new Master(*this);
        }
        int iAm() const override
        {
            return 2;
        }
        int get_Ageconst() const override
        {
            return Age;
        }
        int get_Enemy_Group() const override
        {
            return Enemy_group;
        }
        int get_Friend_Group() const override
        {
            return Friend_group;
        }
        int get_id() const override
        {
            return id;
        }
        void set_id(int id) override
        {
            this->id = id;
        }
        void set_Age(int Age) override
        {
            this->Age = Age;
        }
        void add_Enemy(int Enemy) override
        {
            this->Enemy_group = Enemy;
        }
        void add_Friend(int Friend) override
        {
            this->Friend_group = Friend;
        }
        void set_Work(int Multiplier) override
        {
            this->Work_Count = Multiplier;
        }
    };
}
#endif //UNTITLED6_MASTER_H
