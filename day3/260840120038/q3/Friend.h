#ifndef FRIEND_H
#define FRIEND_H

const int MAX_HOBBIES=10;
const int MAX_PHONES=10;
const int MAX_STR_LEN=100;

class Friend{
		private:
		//static variable to keep track of the number of friends created

		int id;
		char name[MAX_STR_LEN];
                //hobbies are alloacted a 
		char **hobbies;
		int hobbieCount;

		char **mobiles;
		int mobileCount;

		char bday[20];
		char *mail;

		public:
		Friend();
		~Friend();

		void acceptDetails();
		void displayDetails() const; //const at end means read only 

                //getters
		int getId() const;
	        const char* getName()const;
                                                          
                bool checkHobby(const char* hobby)const;// to check hobby of user by passing a char array

};		




#endif
