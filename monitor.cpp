/*==================================================================================================================
*
* Author: Rong Zhang
*  Date: 11/10/2016
*  
*  File name: monitor.cpp
*  Description: reference monitor
		if the instruction command is well formed, read and write will be executed in monitor class
*  		if subject and object obey the rull of Bell-Lapudula (no read up, no write down), the current state of 
*			subject and object will be displayed; otherwise, it will show "Access Denied"
*
*==================================================================================================================*/


#include "header.h"
#include "class.h"
#include "monitor.h"


monitor::monitor(){}

monitor::~monitor(){}

void monitor::createobject(string obname,secure slevel)
{
		
				
	
//----------------operation in struct------------------------------
			
			sob.obname=obname;	//set object name ( in sturct mapobject)
			sob.oblevel=slevel;	//set object security ( in sturct mapobject)
			vecmapob.push_back(sob);	//save one mapobject(struct) called sob in vector call vecmapob[0...]

//----------------operation in class------------------------------------------------

			ob.createobject(obname);	//set object name (in class object)
			//ob.createobjectva(value);	//set object value (in class object)
			vecob.push_back(ob);		//save one object(class) called ob in vector called vecob[0....]
			//cin.get();			//clear buffer

//-----------------------------------------------------------------------------------		

		vector<object>::iterator it;
		for(it=vecob.begin();it != vecob.end(); it++)	//save all instances in vector with object class type
		{
			it->printobjectna();
		}
	
}




void monitor::createsubject(string subname,secure slevel)
{
		

	
//----------------operation in struct------------------------------
			ssub.subname=subname;		//set subject name ( in sturct mapsubject)
			ssub.sublevel=slevel;		//set subject security ( in sturct mapsubject)
			vecmapsub.push_back(ssub);	//save one mapsubject called sob in vector call vecmapob[0...]

//----------------operation in class--------------------------------
			sub.createsubject(subname);	//set subject name (in class object)
			vecsub.push_back(sub);		//save one subject called ob in vector called vecob[0....]
			//cin.get();			//clear buffer
		

		vector<subject>::iterator it;
		for(it=vecsub.begin();it != vecsub.end(); it++)	//save all instances in vector with subject class type
		{
			it->printsubjectna();
		}
}





void monitor::printstate()
{
		vector<subject>::iterator it;
		vector<object>::iterator i;



	cout << "+-------------------- The current state is --------------------------------+"<<endl;

		cout << "|  "<<"subject  "<<"|  ";

	for(it=vecsub.begin();it != vecsub.end();it++){
		
		cout<<it->printsubjectna()<<"  |  ";
	}
	cout << endl;


		cout << "|  "<<"value  "<<"  |   ";
	for(it=vecsub.begin();it != vecsub.end(); it++){
		cout<<it->printsubjectva()<<"     |   ";
	}
 	cout<<endl;

	cout << "+--------------------------------------------------------------------------+"<<endl;

		cout << "|  "<<"object   "<<"|  ";
	for(i=vecob.begin();i != vecob.end();i++){
		cout<<i->printobjectna() <<"   |  ";
	}
	cout << endl;
	

		cout << "|  "<<"value  "<<"  |   ";
	for(i=vecob.begin();i != vecob.end();i++){
		cout<<i->printobjectva() <<"     |   ";
	}
	cout << endl;


	cout << "+--------------------------------------------------------------------------+"<<endl;



}



void monitor::executeread(string *temp){

	int set=0;
	int no_subject=0;
	int no_object=0;

	//----------------------------allow read down----------------------------------------------------

		vector<subject>::iterator it;
		vector<object>::iterator i;

		vector<mapobject>::iterator a;
		vector<mapsubject>::iterator b;

/*--------------------------------------------------------------------------

first, check if both subject and object are in struct vector matches the imput command;
second, check the secure level of subject and object, if secure level obey the policy "no read up";
third, check if both subject and object name are in class vector matches ine input name;
fourth, set subject temp equal to the object value

------------------------------------------------------------------------------*/

		for(b=vecmapsub.begin();b != vecmapsub.end();b++)
		{		//for loop go through subject vector with struct type
			if ((b->subname+" " )== temp[1])		//if there exist a subject in vector with struct type match input subject name from command, do below
			{
				no_subject=1;
				for(a=vecmapob.begin();a != vecmapob.end(); a++)
				{	
					if((a->obname+" ") == temp[2])		//if there exist a object in vector with struct type match input object name from command, do below
					{	no_object=1;

						if(b->sublevel >= a->oblevel)	//if the secure level of subject is greater than secure level ofobject, execute read
						{
								
							cout<<"Access Granted : "<<b->subname<<" reads "<<a->obname<<endl;
							set=1;
					
						}
						
					}
				}
			}		
		}
							
			

		if((no_object == 0))
		{
			cout<<"Bad Instruction:  ";	//check if the first string of instruction are neither read or write, then treat it as bad instruction
			for(unsigned m=0;m<sizeof(temp);m++){
						cout<<temp[m]<<" ";
					}cout<<endl;
		}
		else if((no_subject == 0))
		{
			cout<<"Bad Instruction:  ";	//check if the first string of instruction are neither read or write, then treat it as bad instruction
			for(unsigned m=0;m<sizeof(temp);m++)
			{
				cout<<temp[m]<<" ";
			}
			
			cout<<endl;
		}
		
				
		else if(set == 1)
		{
			for(it=vecsub.begin();it != vecsub.end();it++)		//for loop go through subject vector with class type
			{
				if((it->printsubjectna()+" ") == temp[1])
				{						//if there exist a subject in vector with class type match input subject name from command, do below
		
					for(i=vecob.begin();i != vecob.end(); i++)	//go through object vector with class type
					{	
						if((i->printobjectna()+" ") == temp[2])		//if there exist a object in vector with class type match input object name from command, do below
						{						
							//cout<<"subject in class can read"<<endl;
							int k;
							k=i->printobjectva();
							it->createsubjectva(k);		//execute read, set subject temp equal to the object value
							printstate();	
							}
						}
					}	
						

				}
			}
						
		else	
		{
			cout<<"Access Denied  :  ";
			for(unsigned m=0;m<sizeof(temp);m++)
			{
				cout<<temp[m]<<" ";
			}
			cout<<endl;
		}

					
			
}
	//----------------------------------------------end read---------------------------------------------------





void monitor::executewrite(string *temp){
	

	//--------------------------allow write up--------------------------------------------------------

		vector<subject>::iterator it;
		vector<object>::iterator i;

		vector<mapobject>::iterator a;
		vector<mapsubject>::iterator b;
		
		int see=0;
		int no_subject=0;
		int no_object=0;


/*-------------------------------------------------------------------------------

first, check if both subject and object are in struct vector matches the imput command;
second, check the secure level of subject and object, if secure level obey the policy "no write down";
third, check if both subject and object name are in class vector matches ine input name;
fourth, set object value equal to the input value

-----------------------------------------------------------------------------*/

		for(b=vecmapsub.begin();b != vecmapsub.end();b++)
		{	
			//cout<<b->subname<<endl;
			if ((b->subname+" " )== temp[1])	//if there exist a subject in vector match input from command, do below
			{	
				no_subject=1;

				for(a=vecmapob.begin();a != vecmapob.end(); a++){
					//cout<<a->obname<<endl;
					if((a->obname+" ") == temp[2])	//if there exist a object in vector match input from command, do below
					{	
						no_object=1;					
						if(b->sublevel <= a->oblevel)	//if the secure level of subject is less than secure level ofobject, execute write
						{
							cout<<"Access Granted :  "<<b->subname<<" writes value "<<temp[3] <<" to "<<a->obname<<endl;
							
							see=1;
						}
					}
				}
			}
		}

		if((no_object == 0))
		{
			cout<<"Bad Instruction:  ";	//check if the first string of instruction are neither read or write, then treat it as bad instruction
			for(unsigned m=0;m<sizeof(temp);m++)
			{
				cout<<temp[m]<<" ";
			}
			cout<<endl;
		}
		else if((no_subject == 0))
		{
			cout<<"Bad Instruction:  ";	//check if the first string of instruction are neither read or write, then treat it as bad instruction
			for(unsigned m=0;m<sizeof(temp);m++)
			{
				cout<<temp[m]<<" ";
			}
			cout<<endl;
		}

		else if(see == 1)
		{
				
			for(it=vecsub.begin();it != vecsub.end();it++)  //for loop go through subject vector with class type
			{
								
				if((it->printsubjectna()+" ") == temp[1]){ 	//if there exist a subject in vector with class type match input subject name from command, do below
					for(i=vecob.begin();i != vecob.end(); i++)	//go through object vector with class type
					{
						if((i->printobjectna()+" ") == temp[2])	//if there exist a object in vector with class type match input object name from command, do below
						{
							int k;
							k =atoi(temp[3].c_str());	//convert string to int 

							i->createobjectva(k);		//set object value as the input value
							printstate();	
						}
					}
				}	
			}
		}
		else	
		{
			cout<<"Access Denied  :  ";
			for(unsigned m=0;m<sizeof(temp);m++)
			{
   				cout<<temp[m]<<" ";
			}
				cout<<endl;						
		}



			

	//--------------------------------------------------end write------------------------------------------------------

	
}






