#ifndef ACCOUNT_H
#define ACCOUNT_H




class Account{
	protected:

         int accountId;
	 char* fname;
         char* lname;
         char* email; 

	 char*  mobile;
   
         int pin  ;
	 double balance;
         double interestRate;
         double minBalance;	


	public:
        Account();
	Account(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, double ir, double minB);
	virtual  ~Account();

	 //setters
        

	 //getters
	int getAccountId() const;
        char*  getName()const ;
        char*  getMail(char* mail)const;
        double   getMob(double mobile)const;
        int  getPin()const;
        virtual const char* getType() const = 0;

       virtual  void display()const;
       virtual void acceptData();
       

       virtual double getBalance() const;
       
       virtual bool withdraw(double amount, int inputPin);
       virtual void deposit(double amount);
       bool validatePin(int inputPin) const;
       void setPin(int newPin);




};









#endif
