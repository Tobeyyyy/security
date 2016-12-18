/*==============================================
* Author: Rong Zhang
*  Date: 11/10/2016
*  
*  File name: main.cpp
*  Description: secure system
*		This project implement a simple “secure” system in C++ following the Bell-LaPadula
*		(BLP) security rules. It have subjects and objects. Each object has a name and an integer value (initially 0)
*		while each subject has a name and an integer variable called temp that records the value it most
*		recently read (also initially 0). 
*		The project implements subjects and objects as a class. Subjects can perform READ and WRITE operations on objects.
*		For a READ, the subject reads the current value of the object and saves that value into its temp variable (a subsequent READ will smash, or change, it).
*		When a subject does a WRITE, the object’s value is updated
*  
*============================================*/

#include "header.h"
#include "class.h"
#include "monitor.h"
  


//void read(string);

int main(int argc,char *argv[]){  

	monitor moni;
	

//-------------create subject----------------------

	moni.createsubject("adam",LOW);
	moni.createsubject("james",MEDIUM);
	moni.createsubject("tim",HIGH);
	moni.createsubject("sara",LOW);
	moni.createsubject("kristy",MEDIUM);
	moni.createsubject("liz",HIGH);
	

//-------------create object----------------------

	moni.createobject("aobj",LOW);
	moni.createobject("jobj",MEDIUM);
	moni.createobject("tobj",HIGH);
	moni.createobject("sobj",LOW);
	moni.createobject("kobj",MEDIUM);
	moni.createobject("lobj",HIGH);
	
//---------------------------------------------------
	

	//read(argv[1]);



	string command[100];
	ifstream file;
	file.open(argv[1]);
	int i=0;
	
	while (!file.eof())
	{
		
		getline (file,command[i]);	//save each line into command array
		i++;	
	}
	


	for(int k=0;k<i;k++)
	{	
transform( command[k].begin(), command[k].end(), command[k].begin(), ::tolower );
	}
	
		
	
	
	for(int k=0;k<i;k++){
	int count=0;
	string* temp; 	//temporary array for each word in command[]

	temp=new string[100];

	
	for(unsigned j=0; j<command[k].length();j++)
	{
		temp[count]+=command[k][j];

		if(command[k][j] == ' ')
		{
			count++;
		}
	}

		if((temp[0] != "read ") && (temp[0] != "write "))
		{
			cout<<"Bad Instruction:  "<<command[k]<<endl;	//check if the first string of instruction are neither read or write, then treat it as bad instruction
		}
	
	else
	{
		
		
		if ((temp[0] == "read ")&&(count == 3)){
			moni.executeread(temp);
	
		}
		else if ((temp[0] == "write ") && (count ==4) && ((atoi(temp[3].c_str()))!=0))
		{
			moni.executewrite(temp);
		
		}
		else
		{
			cout<<"Bad Instruction:  "<<command[k]<<endl;	//check if the first string of instruction are neither read or write, then treat it as bad instruction

		}
	}
		delete[] temp;

	}

	return 0;
}
