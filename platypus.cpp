#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "platypus.h"
using namespace std;

//Constructors
Platypus::Platypus():alive(0){ }

Platypus::Platypus(float w, short a, char n, char g):weight(w),age(a),name(n),gender(g){

	if((g == 'M' || g == 'm' || g == 'F' || g == 'f')
		&& w >= 0
		&& a >= 0
		&& (!isdigit(n))) {	
		alive = 1;
		mutant = 0;}
	else {
		cout<<"Invalid Values, try again!"<<endl;
		exit(0);
	}
}



/* --->>>   Define Accessors functions   <<<--- */

//Define the function - getWeight()
float Platypus::getWeight() const {
    return weight;
}

//Define the function - getAge()
short Platypus::getAge() const {
    return age;
}

//Define the function - getGender()
char Platypus::getGender() const {
    return gender;
}

//Define the function - getName()
char Platypus::getName() const {
    return name;
}

//Define the function - getAlive()
//"1" - alive, "0" - dead
bool Platypus::getAlive() const {
    return alive;
}

//Define the function - getMutant()
//"1" - mutant, "0" - not mutant
bool Platypus::getMutant() const {
    return mutant;
}



/* --->>>   Define Setters functions   <<<--- */

//change object weight
void Platypus::setWeight(float newWeight){
	if(newWeight>=0)
		weight = newWeight;
	else	{
		cout<<"Weight value is not valid!"<<endl;
		return;
		//exit(0);
	}

}

//change object age
void Platypus::setAge(short newAge){
	if (newAge>=0)
		age = newAge;
	else {
		cout<<"Age value is not valid!"<<endl;
		return;
		//exit(0);		
	}
}

//change object name
void Platypus::setName(char newName){
	if (!isdigit(newName))
		name = newName;
	else	{
		cout<<"Name value is not valid!"<<endl;
		return;
		//exit(0);
	}
}

//change object gender
void Platypus::setGender(char newGender){
	if(newGender == 'M' || newGender == 'm' || newGender == 'F' || newGender == 'f')
		gender = newGender;
	else	{
		cout<<"Gender value is not valid!"<<endl;
		return;
		//exit(0);
	}
}

//change object alive/died
void Platypus::setAlive(short newAlive){
	if(newAlive == 0 || newAlive ==1)
		alive = newAlive;
	else	{
		cout<<"Alive value is not valid!"<<endl;
		//return;
		//exit(0);
	}
}

//change object mutant/not mutant
void Platypus::setMutant(short newMutant){
	if(newMutant == 0 || newMutant == 1)
		mutant = newMutant;
	else	{
		cout<<"Mutant value is not valid!"<<endl;
		return;
		//exit(0);
	}
}



/*----------------------------------------------
	Define the function - age_me():

	change object age;
	2% chance to become mutant;
	(weight*10)% chance to die;
	wight > 10 to die;
 
----------------------------------------------*/
void Platypus::age_me(){
	if(alive == 0){			//check, Platypus is alive?	
		cout<< "Platypus "<<name<<" is already dead!"<<endl;
		return;
	}

/*	
	//check, platypus weight is more than 10
	//but do not this check, because died chanse is (weight * 10)%, if platypus is more, than 10, died chanse is more than 100%
	if (weight >= 10){
		cout<<"Weight of Platypus   is "<<weight<<" pound, It is died"<<endl;
		alive = 0;
	}
*/


//2% chanse to becomes mutant (2%  chanse is same 1% from 50)
int temp_mutant = rand() % 50 + 1;  //rand % 50 returns int from 0-49, add 1 to get 1-50
	if(temp_mutant  == 1){
		mutant = 1;
		cout<<"Platypus has mutated!"<<endl;
	}

//chanse to died
double temp_died = weight * 10;
int temp_random = rand() % 100 + 1;
	if (temp_random<=temp_died) {
		alive = 0;
		cout<<"Platypus "<<name<<" died!"<<endl;
		return;
	}
 
	cout<<"Age of Platypus "<<name <<" is "<<age<<", New age is "<<age+1<<" month(s)."<<endl;
	age+=1;
}



/*----------------------------------------------
	Define the function - fight():

	fight_ratio = (calling_platypus weight /other_platypus weight) * 50;
	if fight_ratio less than randomly number from 1-100, survives calling platypus,
	otherwise  other_platypus survives.
 
----------------------------------------------*/

void Platypus::fight(Platypus & p2){

	if(alive == 0 && p2.getAlive() == 0) {
		cout<<"Platypus "<<name<<" and " << p2.getName()<<" are died. They could not fight!"<<endl;
	} 
	else if(alive == 0) { //check calling_platypus is alive?
		cout<<"Platypus "<<name<<" is died. It cann't fight!"<<endl;
		return;
	}
	else if (p2.getAlive()==0){ ////check other_platypus is alive?
		cout<<"Platypus "<<p2.getName()<<" is died. It canc't fight!"<<endl;
		return;
	}
	else
	{
		cout<<"Starting fight between of Platypuses: "<<name<<" and "<<p2.getName()<<endl;
		
		float fight_ratio=(weight/p2.getWeight())*50;

		if (fight_ratio>(rand()%100)+1){
			p2.setAlive(0);
			cout<<"Platypus "<<p2.getName()<<" killed!"<<name<<" is Winner!"<<endl;
			//cout<<"Platypus "<<name<<" is Winner!"<<endl;
		}
		else {
			alive = 0;
			cout<<"Platypus "<<name<<" killed! "<<p2.getName()<<" is Winner!"<<endl;
			//cout<<"Platypus "<<p2.getName()<<" is Winner!"<<endl;
		}
	}
}



/*----------------------------------------------
Define the function - eat():

increases the weight of the platypus by a random amount from 0.1% to 5.0% of the platypus current weight;
  
----------------------------------------------*/
void Platypus::eat(){
	//check platypus is alive?
	if(alive == 0){
		cout<<"Platypus "<<name<<" was died, It cann't eat!"<<endl;
		return;
	}

	cout<<"Platypus start Eating"<<endl;
	float eat_rand=(rand() % 50 + 1)/1000.;
	weight=weight+(weight*eat_rand);
	cout<<"Platypus "<<name <<" finished eating. New weight is "<<weight<<endl;

}



/*----------------------------------------------
Define the function - hatch():

Gender will randomly be 'M' or 'F' with equal probability;
Name will be assigned by the user depending on the gender OR 
		name could just be a character chosen randomly Note;
Weight will randomly be between 0.1 and 1.0 pounds;
A hatch function that will randomly set up a newborn platypus with 
alive=true, 
mutant=false, 
and age=0.

----------------------------------------------*/

void Platypus::hatch(){

	//define gender, 50% chanse 'M' or 'F'
	int gender_MF = rand() % 2;
	char new_Gender;
	if(gender_MF == 0){
		new_Gender = 'M';
	}
	else {
		new_Gender = 'F';
	}

	//define name
	//if user do not enter platypus name, name define randomly
	cout<< "Enter Valid Platypus Name: (Press Enter, if you want to generate random name of Platypus)"<<endl;
	auto new_Name = cin.get();
		if (new_Name == '\n') {
			char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ";
			new_Name = letters[rand() % 52];
		}
		else if (isdigit(new_Name)){
			cout<<"Invalid Platypus Name"<<endl;
			return;
		}
		else {

		//define weight randomly
		float new_weight = (rand()%100+1)/100;

		//create New objects
		Platypus newPlatipus(new_weight,0,(char)new_Name,new_Gender);
		cout<<"New Platypus has been created! Details:"<<endl;
		cout<<newPlatipus<<endl;
	}

}

//Define Function - print
void Platypus::print(ostream & out)const{

    out << setw(10)<< "Name: " << name << endl;
    out << setw(10)<< "Gender: " << gender << endl;
    out << setw(10)<< "Age: " << age << " month(s)" <<endl;
    out << setw(10)<< "Weight: " << weight << " pound" << endl;
    out << setw(10)<< "Alive: " << alive << endl;
    out << setw(10)<< "Mutant: " << mutant << endl;

}

//Define reset operators "<<"
ostream & operator<<(ostream & out, const Platypus & p)
{
  p.print(out);
  return out;
}
