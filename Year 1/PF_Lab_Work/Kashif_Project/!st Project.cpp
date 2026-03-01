#include<iostream>
using namespace std;
	void print_tasks(string tasks[], int tasks_count){
		cout<<"  tasks to do : "<<endl;
		cout<<"--------------------------------"<<endl;
		for(int i=0; i<tasks_count; i++){
			cout<<"task "<<i +1<<": "<<tasks[i]<<endl;
		}
		cout<<"--------------------------------"<<endl;
	}
int main(){
	string tasks[10]={""};
	
	int task_count=0;
	int option=-1;
	
	while(option!=0){
		
		cout<<"----To Do list Manager----"<<endl;
		cout<<"1 - To add new task "<<endl;
		cout<<"2 - View tasks "<<endl;
		cout<<"3 - Delete the tasks "<<endl;
		cout<<"0 - terminate the program "<<endl;
		cin>>option;
		
		
		
		if(option>3){
			cout<<"please enter valid number for options; "<<endl;
		}
		switch(option){
			case 1:{
				if(task_count>9){
					cout<<"task list is full "<<endl;
				}else{
					cout<<"enter a new task: ";
					cin.ignore();
					getline(cin,tasks[task_count]);
					task_count++;
				}
				break;
			}
			case 2:{
				print_tasks(tasks,task_count);
				break;
			}
			case 3:{
				int del_task=0;
				cout<<"enter a task to delete ";
				cin>>del_task;
				if(del_task<0 || del_task>9){
					cout<<"you entered invalid task no. "<<endl;
					break;
				}
				tasks[del_task - 1]= " ";
				break;
			}
			
		}
	}	
	
	return 0;
}