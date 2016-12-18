/*=================================================================================================================

* Author: Rong Zhang
*  Date: 11/10/2016
*
*  
*  File name: monitor.h
*  Description: declaration of reference_monitor class
*  		 reference monitor will manage two mappings from the subject and object names to their security labels

*================================================================================================================*/

enum secure {LOW, MEDIUM, HIGH};
class monitor{
		private: 

	//---------------create struct for mappings from subject and object names to their security label----------
	//--------------set secuirty level as private so that it can not be modified by others-

			struct mapsubject{
				string subname;
				secure sublevel;	//subject secure level
			};

			struct mapobject{
				string obname;
				secure oblevel;		//object secure level
			};

	
		public:

	//need 4 vector here, before using vector in main function, we need to declare objects by "monitor Mon;Mon.vecmapsub[1]...."
			vector<mapobject> vecmapob;	//vector with struct type to mapping subject security level with subject name in subject class
			vector<mapsubject> vecmapsub;	//vector with struct type to mapping subject security level with subject name in object class
			
			vector<subject> vecsub;		//vector with class type to save subject name and temp
			vector<object> vecob;		//vector with class type to save subject name and temp
			

			subject sub;		
			object ob;
	
			struct mapobject sob;
			struct mapsubject ssub;
		
			monitor();
			~monitor();
			void createobject(string,secure);	//create object by passing object name and secure level
			void createsubject(string,secure);	//create subject by passing subject name ans secure level
			void executeread(string *);		//execute read command and pass a command array into
			void executewrite(string *);		//execute write command and pass a command array int
			void printstate();			//print state if command is accessed

	};
