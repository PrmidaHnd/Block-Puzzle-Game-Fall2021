#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#include "start.h"
void difficulty()
{
	while(true)
	{
		system("CLS");
	    cout<<"1)Continue"<<endl<<"2)Back"<<endl;
	    char get;
	    cin>>get ;
	    if(get=='2')
	    {
		    return;
	    }           
	    else if(get=='1')
	    {
		    cout<<"1)defult"<<endl<<"2)your choice"<<endl;
		    char get2;
		    cin>>get2;
		    if(get2=='2')
		    {
			   cin>>size; 
			   while(size<=11)
			   {
			        cout<<"the size should be greater than 11"<<endl;
			        cin>>size;
		        }
		        while(size>100)
			    {
			        cout<<"the size should be less than 100"<<endl;
			        cin>>size;
		        }
		        cout<<endl<<"Please select a difficulty level"<<endl;
				cout<<"1)easy"<<endl;
				cout<<"2)medium"<<endl;
				cout<<"3)hard"<<endl;
				cin>>dif;
		    }  
			start();
	    }
	}
}
#endif