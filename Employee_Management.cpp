#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

class Employee{
    int age;
    char Name[100];
    char Designation[200];
    int Salary;
    char College[100];
    int ID;

    public:
    void displayDetails() const;
    void updateEmp();
    void setDetails();
    int return_ID() const;

    //Function Declarations done here. 

};

void Employee::setDetails(){

    cout<<"Enter Employee's First Name: ";
    cin.ignore();
    cin.clear(); cin.sync();
    cin.getline(Name,100);
    cout<<"Enter the Age for "<<Name<<": ";
    cin>>age;
    cout<<"Enter "<<Name<<"'s College: ";
    cin.ignore();
    cin.getline(College,100);
    cout<<"Enter "<<Name<<"'s Designation: ";
    cin.getline(Designation,100);
    cout<<"Enter The Salary: ";
    cin>>Salary;
    cout<<"Enter "<<Name<<"'s EID: ";
    cin.ignore();
    cin.clear();
    cin.sync();
    cin>>ID;
    return;
};

void Employee::displayDetails() const{

    cout<<"Name: "<<Name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"College: "<<College<<endl;
    cout<<"Designation: "<<Designation<<endl;
    cout<<"Salary: "<<Salary<<endl;
    cout<<"Employee ID: "<<ID<<endl;
    cout<<"======================================================================"<<endl;
};

int Employee::return_ID() const{
    cout<<ID;
}
void Employee::updateEmp(){
        cout<<"-1 coming from here. ";
        cout<<"Would you like to Review the Changes you made? Y/N "<<endl;
        char review;
        cin>>review;

        if(review == 'Y' || 'y'){
                system("clr");
                cout<<"Name: "<<Name;
                cout<<"Age: "<<age;
                cout<<"College: "<<College;
                cout<<"Designation: "<<Designation;
                cout<<"Salary: "<<Salary; 
                cout<<"Employee ID (EID) : "<<ID;
            }
                if(review == 'N' || 'n'){
                cout<<"Writing Contents to the File..."<<endl;
                cout<<"Updating Database.."<<endl;
                cout<<"Employee Record has been Updated Successfully!" <<endl;
            }
    return;
};

// Function Declaration
void create_Emp();
void update_Emp(int id);
void delete_Emp(int ID);
void view_Emp();
void view_Emp(int ID);


int main(){


    Employee Enew;
    int choice = 0;
    int EID = 0;
    while(1){
    system("cls");
    cout<<"\t \t \t Welcome to The Employee Management System!! "<<endl;
    cout<<endl;
    
    cout<<"1. Create an Employee. "<<endl;
    cout<<"2. Update Values of an Employee, using EID. "<<endl;
    cout<<"3. Delete the Record of an Employee. "<<endl;
    cout<<"4. View all Employee Details. "<<endl;
    cout<<"5. View the Details of the Employee, using EID. "<<endl;
    cout<<"0. Exit. "<<endl;

    cin.clear();
    cout<<"Enter your Choice: "<<flush;
    cin>>choice;
    
        switch(choice){
            while(choice>6){
                cout<<"Invalid Input!";
                break;
        }

            case 1: create_Emp();        break;
                                   

            case 2: 
                 {   
                    cout<<"Enter the EID: ";
                    cin>>EID;
                    update_Emp(EID);
                }   break;

            case 3: 
                {   
                    cout<<"Enter the EID: ";
                    cin.ignore();
                    cin>>EID;
                    delete_Emp(EID);  }       break;

            case 4: view_Emp();               break;

            case 5: 
                {   
                    cout<<"Enter the EID: ";
                    cin.ignore();
                    cin>>EID;
                    view_Emp(EID);  }         break;

            case 6: cout<<"Thank you for using Employee System! " ;
                    cin.get();
                    exit(0);
                    break;
                    
        }
       
    }
    return 0;     
};
            


// Writing the attributes of an Employee to a File. setDetails();
void create_Emp(){
        
        fstream Emp_dat;
        Employee newEmp;       
        Emp_dat.open("Employee.dat", ios::app | ios::out); 
        newEmp.setDetails();{
        Emp_dat.write(reinterpret_cast<char *>(&newEmp), sizeof(newEmp) );
        Emp_dat.close();
};
        cout<<"Employee Record has been Created. "<<endl;
        cout<<"Press ANY key to Main Menu... ";
        cin.ignore();
        cin.get();
        return;
        
}


    //Updating the Details of a particular Employee.
void update_Emp(int ID){
    
    bool found = false;
    Employee Emp_new;
    fstream Emp_dat;
    Emp_dat.open("Employee.dat",ios::app|ios::in|ios::out);
    if(!Emp_dat){
        cout<<"File Could not be Opened. Press any Key to Exit...";
        cin.ignore();
        cin.get();
        return;
        
    }
    
        while(!Emp_dat.eof() && found == false){
            Emp_dat.read((char *) &Emp_dat, sizeof(Emp_dat) );
            if(Emp_new.return_ID()==ID){
                Emp_new.displayDetails();
                cout<<"Press Any Key to Modify the Values.. "<<endl;
                cin.ignore();
                cin.get();
                Emp_new.setDetails();
                int pos=(-1)*static_cast<int>(sizeof(Emp_new));
                Emp_dat.seekp(pos,ios::cur);
                Emp_dat.write(reinterpret_cast<char *> (&Emp_dat), sizeof(Emp_dat));
               
                found = true;   
            };
        }

    Emp_dat.close();
    if(found==false){
        cout<<" \n \n \n Record Not Found -_- ";
        cout<<"Press any key to Exit...";
        cin.ignore();
        cin.get();
        return;
    }
}

                    // View Records of All Existing Employees displayDetails();
void view_Emp(){
    Employee Enew;
    fstream Emp_dat;
    Emp_dat.open("Employee.dat", ios::app | ios::out | ios::in); 
        if(!Emp_dat){
        cout<<"File Cannot be Opened/Found. Press any Key to Exit..";
        cin.ignore();
        cin.get();
        }
        cout<<"\n \n \n \t \t \t DISPLAYING ALL THE RECORDS!"<<endl;
        cout<<"\n======================================================================"<<endl;
    
    while(Emp_dat.read(reinterpret_cast<char *>(&Enew), sizeof(Enew) ) ) {
    
            Enew.displayDetails();
    }
    
    cout<<"Press ANY Key to Main Menu...";
        Emp_dat.close();
            cin.ignore();
                 cin.get();
};


                // View Records Based on Employee ID 
void view_Emp(int id){
    Employee Emp_new;
    fstream Emp_dat;
    Emp_dat.open("Employee.dat", ios::app|ios::out);
    if(!Emp_dat){
        cout<<"File Couldn't be Opened. Press Any Key to Exit! ";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while(Emp_dat.read(reinterpret_cast<char *> (&Emp_dat), sizeof(Emp_dat) ) ){
        if(Emp_new.return_ID() == id ){
            Emp_new.displayDetails();
            flag = true;
        }
    }

    Emp_dat.close();
    if(flag == false){
        cout<<" \n Record Doesn't Exist. Press any Key to exit!! ";
        cin.ignore();
        cin.get();
    }
};

 // Delete Employee with EID
void delete_Emp(int ID){
    Employee Enew;
    fstream Emp_Dat;
    Emp_Dat.open("Employee.dat", ios::binary |ios::out);
    if(!Emp_Dat){
        cout<<"The File Could not be Opened... Press ANY Key to Exit... ";
        cin.ignore();
        cin.get();
        return;
    }

    Emp_Dat.open("Temp.dat", ios::out);
    Emp_Dat.seekg(0,ios::beg);
    while(Emp_Dat.read(reinterpret_cast<char *>(&Enew), sizeof(Enew) ) );
    {
        if(Enew.return_ID() != ID ){
            Emp_Dat.write(reinterpret_cast<char *> (&Enew), sizeof(Enew) ) ;
        }
    }


    Emp_Dat.close();
    cin.ignore();
    remove("Employee.dat");
    cin.ignore();
    rename("Temp.dat", "Student.dat" );
    cin.clear();
    cout<<"Record, Succesfully Deleted!! Press Any Key to Continue..." <<flush;
    cin.ignore();
    cin.get();
};
