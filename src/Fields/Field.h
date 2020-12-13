//
// Created by Grigory on 12.12.2020.
//

#ifndef UNTITLED7_FIELD_H
#define UNTITLED7_FIELD_H

#include"../vector.h"
namespace fields {
    class Field {
    private:
        int n;
        int initial_work_amount;
        int work_amount;
        bool commander_here;
        my_template::vector<int> IDs;
    public:
        explicit Field(int work_amount = 20, bool commander_here = false, int n = 0, int initial_work_amount = 20)
                        :work_amount(work_amount), commander_here(commander_here), IDs(),n(n),initial_work_amount(initial_work_amount){};
        Field(int work_amount , bool commander_here, my_template::vector<int> IDs, int n,int initial_work_amount)
                        :work_amount(work_amount), commander_here(commander_here), IDs(std::move(IDs)), n(n),initial_work_amount(initial_work_amount){};

        friend std::ostream& operator <<(std::ostream &, const Field &);
        friend std::istream& operator >>(std::istream &, Field &);
        Field & operator = (const Field& Field);
        Field(const Field &Field);
        void set_work_amount(int work_amount){ this->work_amount = work_amount;};
        void set_initial_work_amount(int initial_work_amount){ this->initial_work_amount = initial_work_amount;};
        void set_n(int n){ this->n = n;};
        my_template::vector<int> get_IDs(){return IDs;};
        int get_work_amount() const{return work_amount;};
        int get_initial_work_amount() const{return initial_work_amount;};
        void add_worker(int id){IDs.push_back(id);};
        bool worker_check(int id);

    };
}

#endif //UNTITLED7_FIELD_H
