#include<iostream>
using namespace std;

class Date{
    int day;
    int month;
    int year;

    public:

    Date():day(0),month(0),year(0){}

    Date(int day,int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
        
     }
    
    void setDate(int day){
        this->day=day;
    }

    void setMonth(int month){
        this->month=month;
    }
    void setYear(int year){
        this->year=year;
    }

    void acceptDate(){
        cout<<"Enter Date :- ";
        cin>>day;
        cout<<"Entre month :- ";
        cin>>month;
        cout<<"Enter Year :- ";
        cin>>year;
        
    }

    void displayDate(){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }

};

class Employee : public Date{
    int empID;
    double sal;
    string dept;
    Date doj;
    public:
    Employee():empID(),dept(" "){}

    Employee(int empID, double sal ,string dept, int day, int month, int year){
        this->empID=empID;
        this->sal=sal;
        this->dept=dept;
        this->doj.setDate(day);
        this->doj.setMonth(month);
        this->doj.setYear(year);
    }

    void setempId(int id){
        this->empID=id;
    }

    void setsal(double sal){
        this->sal=sal;
    }

    void setDept(string dept){
        this->dept=dept;
    }

    void acceptDetails(){
        cout<<"Employee ID :- ";
        cin>>empID;
        cout<<endl;
        cout<<"Salary :- ";
        cin>>sal;
        cout<<endl;
        cout<<"dept :- ";
        cin>>dept;
        cout<<endl;
        cout<<"Date of Joining :- ";
        doj.acceptDate();
    }
    void displayDetails(){
        cout<<"Employee empID :- "<<empID<<endl;
        cout<<"Department of the Employee :- "<<dept<<endl;
        cout<<"Joining Date of Employee ";
        doj.displayDate();
        
    }
};

class Person : public Employee{
    string name;
    string address;
    Date *dob;

    public :

    Person():name(""),address(""){
        dob=NULL;
    }

    Person(string name, string address, int empID, double sal, string dept, int date, int month, int year)
    {
        this->name = name;
        this->address=address;
        this->setempId(empID);
        this->setsal(sal);
        this->setDept(dept);
        this->setDate(date);
        this->setMonth(month);
        this->setYear(year);
        }

     void acceptPersonDetails()
     {
        cout<<"Name  :- ";
        cin>>name;
        cout<<endl;
        cout<<"Address :- ";
        cin>>address;
        cout<<endl;
        acceptDetails();

     }   

     void displayPersonDetails()
     {
        cout<<"Name of Person :- "<<name<<endl;
        cout<<"Address of the person :- "<<address<<endl;
        displayDetails();
        if(dob!=NULL){

        }
     }

     void acceptDateofBirth()
     {
        dob = new Date;
        cout<<"Date of Birth of the person :- "<<endl;
        dob->acceptDate();
     }

     ~Person(){
        if(dob!=NULL){
            delete dob;
            dob=NULL;
        }
     }
};

int main()
{
    Person p1;
    Person p2("Aadarsh","Civil lines katni",1002,58300,"Manager",13,11,2001);
    p2.acceptDateofBirth();
    Person p3;
    p3.acceptPersonDetails();
    p1.displayPersonDetails();
    p2.displayPersonDetails();
    p3.displayPersonDetails();


    cout<<"Thank You ";
    return 0;
}