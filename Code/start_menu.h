#ifndef START_MENU_H
#define START_MENU_H
#include "difficulty.h"
void start_menu()
{    
	while(true)
	{
		system("CLS");
		cout<<"1)select difficulty"<<endl;
	    cout<<"2)Back"<<endl;
	    char get; //entekhab
	    cin>>get;
	    if(get=='1')
	    {
		    difficulty();
	    }     
	    else
	        return;
	}
} 
#endif