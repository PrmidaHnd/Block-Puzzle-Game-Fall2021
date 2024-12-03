#ifndef MENU_H
#define MENU_H
#include "start_menu.h"
#include "difficulty.h"

void menu()
{         
	while(true)
	{
		system("CLS");
		cout<<endl<<"1)Start"<<endl;
	    cout<<"2)Select Difficulty"<<endl;
	    cout<<"3)Exit"<<endl;
	    char a;
	    cin>>a;
	    if(a=='1')
	    {
		    start_menu();
	    }           
	    else
	    {
		    if(a=='2')
		    {
			    difficulty();
	    	}           
	    	else
		    {
			    return;
	    	}          
    	}
	}
}
#endif