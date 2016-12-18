/*===============================================================
* Author: Rong Zhang
*  Date: 11/6/2016
*  
*  File name: class.cpp
*  Description: method for object and subject class
*  
*===============================================================*/



#include "header.h"
#include "class.h"




//======================class for object=====================

object::object(){
	value=0;
	}

object::~object(){}

object::object(string name,int obvalue){
	value=obvalue;
	ob_name=name;
}

	//---------create and object with name and value-----------

void object::createobject(string name){
	ob_name=name;
	
}

void object::createobjectva(int obvalue){
	value=obvalue;
}
	//------------------------------------------------

	

	//print out object name-----------------------

string object::printobjectna() {
	return ob_name;

}

	//print out object value------------------------------

int object::printobjectva(){
	return value;
}

//========================end of class for object ================





//===================class for subject===========================


subject::subject(){
	temp=0;
}
subject::~subject(){}
subject::subject(string name,int sbtemp){
	sb_name=name;
	temp=sbtemp;

}

	//------------create and osubject with name and temp-----------

void subject::createsubject(string name){
	sb_name=name;
	
}

void subject::createsubjectva(int sbtemp)
{
	temp=sbtemp;
}
	//--------------------------------------------------




	//print out subject name-----------------------

string subject::printsubjectna(){
	//cout<<"subject name: "<<sb_name<<endl;
	return sb_name;
}

	//print out subject temp value------------------------------

int subject::printsubjectva(){

	return temp;
}

//===================end of class for subject========================



