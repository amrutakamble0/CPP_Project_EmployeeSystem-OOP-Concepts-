//DYNAMIC CASTNG :CPP PROJECT : EMPLOYEE PROJECT.

#include<iostream> 
#include<string.h> 
using namespace std; 
 
class Employee
{ 
 int id; 
 char name[20]; 
 double sal; 
 public: 
   
  Employee(int g,char* arr,double d) 
  { 
   this->id=g; 
   strcpy(this->name,arr); 
   this->sal=d;  
  } 
   
  void seetid(int g) 
  { 
   this->id=g; 
  } 
  void setname(char* brr) 
  { 
   strcpy(this->name,brr); 
  } 
  void setsal(double j) 
  { 
   this->sal=j; 
  } 
   
  int getid() 
  { 
   return this->id; 
  } 
   
  char* getname() 
  { 
   return this->name; 
  } 
  double getsal() 
  { 
  return this->sal; 
  } 
   
 virtual void display() 
  { 
   cout<<"\n Employee Details---->";
   cout<<"\n Employee Id:"<<this->id; 
   cout<<"\n Employee Name:"<<this->name; 
   cout<<"\n Employee Salary:"<<this->sal; 
  } 
    virtual double calsal()=0; 
}; //Employeeee class ends here...
 
 
class SalesManager:public Employee
{ 
 double inc; 
 int tar; 
 public: 
   
  SalesManager(int i,char* crr,double r,double w,int p):Employee(i,crr,r) 
  { 
   this->inc=w; 
   this->tar=r; 
  } 
  void setinc(double w) 
  { 
   this->inc=w; 
  } 
  void settar(int h) 
  { 
   this->tar=h; 
  } 
  double getinc() 
  { 
   return this->inc; 
  } 
  int gettar() 
  { 
   return this->tar; 
  } 
  void display() 
  { 
   Employee::display(); 
   cout<<"\n\n SalesManager Incentive is:"<<this->inc; 
   cout<<"\n SalesManagerTarget is :"<<this->tar; 
  } 
   
  double calsal() 
  { 
   return this->getsal()+this->inc; //adding incentive into Employeeee basic salary
  } 
};/*sales manager class end*/ 

 
class Admin:public Employee
{ 
 double all; 
 public: 
   
  Admin(int y,char* jkk,double q,double r):Employee(y,jkk,q) 
  { 
   this->all=r; 
  } 
  void setall(double t) 
  { 
   this->all=t; 
  } 
  double getall() 
  { 
   return this->all; 
  } 
   void display() 
   { 
    Employee::display();
    cout<<"\n\n Admin Allowance is:"<<this->all; 
  } 
   
  double calsal() 
  { 
   return this->getsal()+this->all; //adding allowance into Employeeee basic salary.
  } 
   
}; //Admin class ends here...


void myfun(Employee*); 
int main() 
{ 
 Employee*ep; 
 SalesManager s1(101,"Amruta",30000,5000,60000); 
 ep=&s1; 
 ep->display(); 
 cout<<"\n\n Salary of the SaleSalesManagernager after adding basic salary:"<<ep->calsal(); 
  myfun(&s1); 
  cout<<"\n\n";
 
 Admin a1(102,"Prafull",20000,50000); 
 ep=&a1; 
 ep->display(); 
 cout<<"\n\n Salary of the Admin after adding basic salary:"<<ep->calsal(); 
 myfun(&a1); 
} 

void myfun(Employee* ep) 
{ 
 SalesManager* sp= dynamic_cast<SalesManager*>(ep); 
 if(sp!=NULL) 
 { 
  cout<<"\n\n Woohh!! It's nice to work with u Manager Sir."; 
 } 
 Admin*ap=dynamic_cast<Admin*>(ep); 
 if(ap!=NULL) 
 { 
  cout<<"\n\n I love to work like this Admin sir......Thank You...!!"; 
  cout<<"\n\n";
 } 
}

