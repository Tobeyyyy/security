/*============================================================
* Author: Rong Zhang
*  Date: 11/6/2016
*  
*  File name: class.cpp
*  Description: declaration of both subject class and object class
*  
*==============================================================*/


class object{
	private:
		string ob_name;
		int value;	   
		
	public:
		object();		//default constructor
		object(string,int);	//overload constructor
		~object();		//destructor
		void createobject(string);	//create object name
		void createobjectva(int);	//create object value
		string printobjectna();		//print object name
		int printobjectva();		//print object value
};



//****************************************************************************



class subject{
	private:
		string sb_name;
		int temp;
	
	public:
		subject();
		subject(string, int);
		~subject();
		void createsubject(string);	//create subject name
		void createsubjectva(int);	//create subject temp
		string printsubjectna();	//print subject name
		int printsubjectva();		//print subject temp

};


