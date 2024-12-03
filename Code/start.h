#ifndef START_H
#define START_H
#include "play.h"

void start()
{
    for(int i=0;i<size;i++)
    {
    	for(int j=0;j<size;j++)
    	{
    		puzzle[i][j]='-';
    	}
	}
	int x;
	x=rand();
	if(dif=='3')
    {
    	int y=x%12;
    	switch(y)
    	{
    		case 1 :  next_block2=13;
    		        break;
    		case 2 :  next_block2=14;
    		        break;
    		case 3 :  next_block2=15;
    		        break;
    		case 4 :  next_block2=16;
    	        	break;
    		case 5 :  next_block2=17;
    	        	break;
    		case 6 :  next_block2=18;
    		        break;
    		case 7 :  next_block2=19;
    	        	break;
    		case 8 :  next_block2=20;
    	        	break;
    		case 9 :  next_block2=21;
    	        	break;
    		case 10 :  next_block2=22;
    		        break;
    		case 11 :  next_block2=23;
    		        break;
    		case 0 :  next_block2=24;
    		        break;
		}
	}
	else
	{
		if(dif=='2')
    	{
    			int y=x%8;
    			switch(y)
    			{
    			    case 1 :  next_block2=5;
    			            break;
    		        case 2 :  next_block2=6;
    		                break;
    	    	    case 3 :  next_block2=7;
    	    	            break;
    		        case 4 :  next_block2=8;
    		                break;
    		        case 5 :  next_block2=9;
    		                break;
    		        case 6 :  next_block2=10;
    		                break;
    		        case 7 :  next_block2=11;
    		                break;
    		        case 0 :  next_block2=12;
    		                break;
    			}
		}
		else
		{
			int y=x%4;
		    switch(y)
		    {
			    case 1 :  next_block2=1;
			            break;
    	        case 2 :  next_block2=2;
    	                break;
    	        case 3 :  next_block2=3;
    	                break;
    	        case 0 :  next_block2=4;
    	                break;
	    	}
		}
	}
	play();
}
#endif