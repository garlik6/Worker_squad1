//
// Created by Grigory on 12.12.2020.
//
#include"../vector.h"
#include "../Units/Unit.h"
#include "../Units/Master.h"
#include"../Units/Worker.h"
#include "../Fields/Field.h"
#include "../crew/crew.h"
#include "dialog2.h"
#include"rand/rand.h"



namespace dialog_1 {
    int D_Create_Field(crew::crew *crew);
    int D_Add_Unit(crew::crew *crew);
    int D_Add_Unit_onField(crew::crew *crew);
    int Show_E_F(crew::crew *crew);
    int Start_Day(crew::crew *crew);
    int Calculate_Workload(crew::crew *crew);
    int dialog1();
    int Fire_Unit(crew::crew *crew);
    int (*fptr[])(crew::crew *) = {nullptr,D_Create_Field,D_Add_Unit, D_Add_Unit_onField,Show_E_F,Calculate_Workload,Start_Day,Fire_Unit}; //,find,delete,show

    const char *msgs[] = {"0.Quit", "1.Create Field", "2.Add Unit", "3.Add Unit on Field ",
                          "4.Calculate Workload", "5.Show Friends and Enemy's","6. Start the day", "7. Fire Unit", "8. Show Units"};
    const int N = sizeof(msgs) / sizeof(msgs[0]);

    int getInt(int *a) {
        int n;
        do {
            fflush(stdin);
            n = scanf("%i", a);
            if (n < 0)
                return 0;
            if (n == 0) {
                printf("%s\n", "Error! Repeat input");
                scanf("%*[^\n]", 0);
            }
        } while (n == 0);
        scanf("%*c");
        return 1;
    }

    int D_Create_Field(crew::crew *crew) {
        fields::Field Field;
        int a;
        std::cout << "Insert Workload for this field-->";
        getInt(&a);
        Field.set_work_amount(a);
        a = crew->get_Fields().length();
        Field.set_n(a);
        crew->add_field(Field);
        return 0;
    }

    int D_Add_Unit(crew::crew *crew)
    {
            //int a = dialog_2::dialog2();
            int a = 2;
            int work;
            if(a == 1)
            {   std::cout<< "Insert Multiplier-->";
                getInt(&work);
                units::Master master(random_::rand_unique_id(*crew),random_::rand_age(),work,-1);
                crew->add_unit(master.clone());
            } else
                    {
                        std::cout<< "Insert Work Addition-->";
                        work = 3;
                        //getInt(&work);
                        units::Worker worker(random_::rand_unique_id(*crew),random_::rand_age(),work,-1);
                        crew->add_unit(worker.clone());
                        std::cout<< " ID: "<< worker.get_id();
                    }
        return 0;
    }

    int D_Add_Unit_onField(crew::crew *crew){
        int id, n;
        int flag = 0;
        std::cout << "Insert Unit's ID-->";
        getInt(&id);
        std::cout << "Insert desired Field-->";
        getInt(&n);
        flag = crew->add_unit(id,n);
        if (flag == -1)
        {
            std::cout << "Not successful";
        }
        if (flag == 1)
        {
            std::cout << "Successful";
        }
        return 0;
    }

    int Show_E_F(crew::crew *crew){
        return 0;
    }

    int Start_Day(crew::crew *crew){
        return 1;
    }

    int Fire_Unit(crew::crew *crew)
    {   int id;
        std::cout << "Insert Unit's ID-->";
        getInt(&id);
        crew->between_jobs(id);
    }

    int dialog1() {
        char *errmsg = "";
        int rc;
        int i, n;

        do {
            puts(errmsg);
            errmsg = "You are wrong, repeat please";
            fflush(stdin);
            for (i = 0; i < N; ++i)
                puts(msgs[i]);
            puts("Make your choice: -->");
            n = getInt(&rc);
            if (n == 0)
                rc = 0;
        } while (rc < 0 || rc >= N);
        return rc;

    }
    int Calculate_Workload(crew::crew *crew){

    }

    }


