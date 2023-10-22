#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Patient{
public:
    string name;
    string IC;
    Patient* next;
    Patient(){
        name = "";
        IC = "";
    }
    Patient(string n, string ic){
        name=n;
        IC = ic;
    }
};
class Queue{
public:
    Patient* front ;
    int max_queue=5;//set maximum queue
    Patient* back;
    Queue()//constructor
	{
        front = NULL;
        back = NULL;
    }
    ~Queue()//destructor
	{
        Patient* temp = front;
        while(temp){
            front =  temp->next;
            delete temp;
            temp = front;
        }
    }
    bool isEmpty(){
        if(front== NULL && back== NULL)

            return true;
        else
            return false;
    }


    void enQueue(){
        string newName, newIC;
    	
    	cout<<endl;
        if(max_queue==0)//Check condition if queue is full
		{
		cout<<"Queue is full!"<<endl<<endl;
		return;}
		system("CLS");
        cout<<"<<<<<<< Insert New Patient >>>>>>>"<<endl<<endl;
        //insert at back
        cout<<"Name: ";
        getline(cin, newName);
        cout<<"IC Number: ";
        getline(cin, newIC);


        Patient* newPatient = new Patient(newName, newIC);
        if(isEmpty())//If queue is empty front and back will point to newPatient
		{
        	newPatient->next=NULL;
            front = newPatient;
            back = newPatient;
        }else//If queue is not empty back will point to newPatient
		{
        	newPatient->next=NULL;
            back->next = newPatient;
            back = newPatient;
        }
        max_queue--;//Decrese the queue size
        cout<<endl;
    }

	void displayQueue(){
		system("CLS");
		cout<<endl;
	    if(isEmpty())//if queue is not empty
		{
	        cout<<"Queue is empty"<<endl<<endl;
	    }
	    else{
	        Patient* ptr=front;
	        int num=1;
	        cout<<"<<<<<<<<<<<<<<<<Patients in waiting list: >>>>>>>>>>>>>>>>>>>>"<<endl;
	        while(ptr!=NULL)
			{
	            cout<<"["<<num<<"] "<<"Name: "<<ptr->name<<endl;
		  		cout<<"    IC Number: "<<ptr->IC<<endl<<endl;;
	            ptr = ptr->next;
	            num++;
	        }
	    }
	}

	void deQueue(){
		displayQueue();
	    if(isEmpty())//Check condition if queue is empty
		{
	    	cout<<endl;
	        cout<<"Queue is empty, no patient to remove"<<endl<<endl;
	    }
	    else
		{
	        Patient* current = front;
	        Patient* prev = NULL;
	        
	        string oldName, oldIC;
	        cout<<endl;
	        cout<<"<<<<<<< Delete Patient >>>>>>>"<<endl<<endl;
	        cout<<"Name: ";
	        getline(cin, oldName);
	        cout<<"IC Number: ";
	        getline(cin, oldIC);
	        
	        while(current != NULL){
	            if(current->name == oldName){
	                if(prev == NULL){
	                    // this is the first element in the queue
	                    front = current->next;
	                }
	                else{
	                    prev->next = current->next;
	                }
	                delete current;
	                max_queue++;//increase the queue size
	                cout<<"Patient with name: "<<oldName<<" IC Number "<<oldIC<<" has been removed from the queue"<<endl<<endl;
	                return;
	            }
	            prev = current;
	            current = current->next;
	        }
	        cout<<"Patient with name: "<<oldName<<" IC Number "<<oldIC<<" not found in the queue"<<endl<<endl;
	    }
	}
	
	void searchPatient(){
		
		
		if(isEmpty()){
	    	cout<<endl;
	        cout<<"Queue is empty, can not proceed with searching!"<<endl<<endl;			
			
		}else{
			displayQueue();
			string oldName, oldIC;
			cout<<"<<<<<<< Search Patient >>>>>>>"<<endl<<endl;
	        cout<<endl;
	        cout<<"Name: ";
	        getline(cin, oldName);
	        cout<<"IC Number: ";
	        getline(cin, oldIC);
	        Patient *curr = front;
	        	        
	        while(curr!=NULL){
	        	
	        		if(curr->name == oldName && curr->IC == oldIC){
	        			 cout<<endl;
	        			 cout<<"Patient with name: "<<oldName<<" IC Number "<<oldIC<<" exist in the queue"<<endl<<endl;
	        			 return;
					}

					curr = curr->next;
			}
		 	cout<<"Patient with name: "<<oldName<<" IC Number "<<oldIC<<" does not exist in the queue"<<endl<<endl;

		}
	}

    
};

void dispMenu(){
	
	cout<<"UTM PKU APPOINTMENT SYSTEM"<<endl;
	
	cout<<"WELCOME!"<<endl<<endl;
	
	cout<<"<<<<<<<<<<<<<<<<Main Menu>>>>>>>>>>>>>>>>>>>>"<<endl;

	cout<<"\n\t1. Insert New Patient"<<endl;

	cout<<"\n\t2. Display List of Patient"<<endl;
	
	cout<<"\n\t3. Delete Patient Queue"<<endl;
	
	cout<<"\n\t4. Search Patient "<<endl;

	cout<<"\n\t5. Exit"<<endl;
}


int main(){

    Queue patient;

	int choice;
	do
	{
	
		dispMenu();

		cout<<"\nEnter your choice [1-4]: ";

		cin>>choice;

		cin.ignore();

		switch(choice){
		//Insert Patient
		case 1: patient.enQueue();
			break;
		//Display patient
		case 2: patient.displayQueue();
			break;
		//Delete patient
		case 3: patient.deQueue();
			break;
		//Search patient
		case 4: patient.searchPatient();
			break;
		//End system
		case 5:
		cout<<"\nThank you.. see you again.."<<endl;
		break;
		//If user enter other than 1-5
		default: cout<<"\nWrong input. Please try again"<<endl;
		}
	}
    while((choice>0)&&(choice<5));
	return 0;
}
