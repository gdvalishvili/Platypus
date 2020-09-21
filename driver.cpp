#include <iostream>
#include <cstdlib>
#include <ctime>
#include "platypus.h"

using namespace std;

int main(){

srand(time(0));
//Platypus(float weight, short age, char name, char gender)

    //Create object p1
    Platypus p1(1.5,7,'P','M');
    cout<<p1<<endl;

    //Check constructors
    p1.setWeight(-6.3);
    p1.setAge(-3);
    p1.setName('9');
    p1.setGender('K');
    p1.setAlive(4);
    p1.setMutant(5);
    cout<<p1<<endl;



    /* --- >>>   Test age_me() function   <<< --- */

    //Create object p2
    Platypus p2(1.5,8,'Q','F');

    //increase age of p2 platypus
    p2.age_me();
    cout<<p2<<endl;
    
    //increase weight of p2 platypus
    p2.setWeight(4.3);
    p2.age_me();
    cout<<p2<<endl;

    //again increase weight of p2 platypus 
    p2.setWeight(7.7);
    p2.age_me();
    cout<<p2<<endl;

    //check platypus, when it is over 10 pounds
    p2.setAlive(1);
    p2.setWeight(10.2);
    p2.age_me();

    //Check when the mutant becomes a platypus
    p2.setAlive(1);
    p2.setWeight(0.1);
    p2.setAge(1);
    p2.age_me();
    cout<<p2<<endl;
    /*

    while (true) {
        p2.age_me();
        if (p2.getMutant()==1)
            break;
    }
    */



    /* --- >>>   Test fight() function   <<< --- */

    Platypus p3(4.2,17,'X','F');    //Create object p3
    Platypus p4(5.1,24,'Y','F');    //Create object p4

    p3.setAlive(0);                 //p3 platypus is died
    p4.setAlive(0);                 //p4 platypus is died
    p3.fight(p4);                   //call fight functions

    p3.setAlive(1);                 //p3 platypus is alive
    p4.setAlive(0);                 //p4 platypus is died
    p3.fight(p4);                   //call fight functions

    p3.setAlive(0);                 //p3 platypus is died
    p4.setAlive(1);                 //p4 platypus is alive
    p3.fight(p4);                   //call fight functions

    p3.setAlive(1);                 //p3 platypus is alive
    p4.setAlive(1);                 //p4 platypus is alive
    p3.fight(p4);                   //call fight functions



    /* --- >>>   Test eat() function   <<< --- */
    
    Platypus p5(4.4,18,'Z','M');    //Create object p5
    p5.eat();                       //call eat() functions

    p5.setAlive(0);                 //died a platypus p5
    p5.eat();                       //call eat() functions
   


    /* --- >>>   Test hatch() function   <<< --- */

    Platypus p6;        //Create object p5
    p6.hatch();         //call hatch() functions
}