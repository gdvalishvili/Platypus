/* Platypus.h -------------------------------------------------------------------

	Header ფაილი შეიცავს იხვნისკარტას მონაცემების შესახებ ინფორმაციას:
	  უპარამეტრო კონსტრუქტორი
	  პარამეტრებიანი კონსტრუქტორი
	  ბეჭდვის (ეკრანზე გამოტანის) ფუნქცია
	  utilite (დამხმარე ფუნქციები)
	  წვდომის ფუნქციები
	  set ფუნქციები
	  ოპერატორის გადატვირთვის ფუნქცია ინფორმაციის მარტივად გამოსატანად

---------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

#ifndef _Platypus
#define _Platypus


class Platypus
{
public:
	//Constructors
	Platypus();  

	Platypus(float initWeight, short initAge, char initName, char initGender);

	//Functions - display details 
	void print(ostream & out)const;

	//Utilities 
    void age_me();              //Functions - change object age
    void fight(Platypus & p2);  //Functions - fight other platypus
    void eat();                 //Functions - platypus eat
    void hatch();               //Functions - platypus birth

	//Accessors
    float getWeight() const; //return object weight
    short getAge() const;    //return object age
    char getName() const;    //return object name
    char getGender() const;  //return object gender
    bool getAlive() const;   //return object alive
    bool getMutant() const;  //return object mutant

    //Setters
    void setWeight(float newWeight);    //change object weight
    void setAge(short newAge);          //change object age
    void setName(char newName);         //change object name
    void setGender(char newGender);     //change object gender
    void setAlive(short newAlive);      //change object alive
    void setMutant(short newMutant);    //change object mutant

private:
    float weight; 	//weight (in pound)
    short age;		//age (in month)
    char name;		//name
    char gender;	//gender
    bool alive;		//is alive?
    bool mutant;	//is mutant?
};

//reset operators "<<"
ostream & operator<<(ostream & out, const Platypus & p);

#endif //_Platypus