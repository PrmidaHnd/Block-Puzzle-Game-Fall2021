#ifndef PLAY_H
#define PLAY_H
#include "hint.h"
void play()
{
	while(true)
	{
		system("CLS");
	    if(next_block2==1)
	    {
		    char block[1][1];
	        block[0][0]='#';
	        for(int i=0;i<1;i++)
	        {
		        cout<<block[0][i];
	        }
	        cout<<endl;
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
    	    cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	    cout<<"SCORE: "<<game.score<<endl;
    	    for(int i=0;i<size;i++)
    	    {
    		    for(int j=0;j<size;j++)
    	    	{
    			    cout<<puzzle[i][j];
    	    	}
    	 	    cout<<endl;
        	}
    	    int x=rand();
    	    int y=x%4;
    	    if(y==1)
    	    {
    		    next_block2=1;
    		    char next_block[1][1];
    		    next_block[0][0]='#';
			    cout<<next_block[0][0];	
		    }
		    else
	    	{  
			    if(y==2)
		    	{
			    	next_block2=2;
				    char next_block[1][2];
	                for(int i=0;i<1;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                next_block[i][j]='#';
		                }
	                }
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
			    }
			    else
			    {
			    	if(y==3)
			    	{
					    next_block2=3;
				        char next_block[2][1];
                	    for(int i=0;i<2;i++)
                	    {
		                    for(int j=0;j<1;j++)
	                	    {
			                    next_block[i][j]='#';
		                    }
	                    }
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
				    }
			    	else
				    {
				    	next_block2=4;
					    char next_block[2][2];
	                    for(int i=0;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    next_block[i][j]='#';
		                    }
	                    }
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
		    	}
		    }
	    	cout<<endl;
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
    	    cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	    cout<<"SCORE: "<<game.score<<endl;
    	    if(puzzle[0][3]=='#')
        	{
    		    return;
		    }
		    else
		    {
			    puzzle[0][3]=block[0][0];
			    int y=3;
			    int x=0;
		    }
		    for(int i=0;i<size;i++)
		    {
		    	for(int j=0;j<size;j++)
		    	{
		    		cout<<puzzle[i][j];
				}
				cout<<endl;
			}
			char a;
	    	while(tolower(a)!='s')
	    	{
            	cin>>a;
    	        if(a=='2')
            	{
    	        	hint();
            	}
    	        else
            	{
		            if(a=='3')
		        	{
		    	    	return;
	    	    	}
	                else
		    	        if(tolower(a)=='a')
		            	{
		    	        	if(y!=0&&puzzle[x][y-1]=='-')
		    		        {
		    		        	puzzle[x][y-1]='#';
		    		            puzzle[x][y]='-';
		    		            y-=1;
				        	}
				            for(int i=0;i<size;i++)
		    		        {
		    		            for(int j=0;j<size;j++)
		    		            {
		    		            	cout<<puzzle[i][j];
								}
								cout<<endl;
							}
		    			
				   	    }
                        if(tolower(a)=='d')
		    		    {
		    		        if(y!=size-1&&puzzle[x][y+1]=='-')
		    		        {
		    		    	    puzzle[x][y]='-';
		    		    	    puzzle[x][y+1]='#';
		    		        	y+=1;
		    		        	for(int i=0;i<size;i++)
		    		        	{
		    		        		for(int j=0;j<size;j++)
		    		        		{
		    		        			cout<<puzzle[i][j];
									}
									cout<<endl;
								}
					    	}
		    	    	}
	    	    }
    	    }
            if(tolower(a)=='s')
            {
        	    while(x!=size-1&&puzzle[x+1][y]=='-')
        	    {
        	    	puzzle[x][y]='-';
        	    	puzzle[x+1][y]='#';
        	    	x+=1;
			    }
	    	}
		    for(int i=0;i<size;i++)
		    {
			    for(int j=0;j<size;j++)
		    	{
			    	cout<<puzzle[i][j];
		    	}
			    cout<<endl;
		    }
    	    for(int i=size-1;i<0;i--)
        	{
    		    int counting=0;
    	    	for(int j=0;j<size;j++)
    	    	{
    		    	if(puzzle[i][j]=='#')
    		    	{
    			    	counting++;
    		    	}
    	    	}
    		    if(counting==size)
    	    	{
    			    game.score++;
    		    	for(int k=i;k<size-1;k++)
    		    	{
    			    	for(int j=0;j<size;j++)
    			    	{
    			    		puzzle[i][j]=puzzle[i+1][j];
    			    	}
    		    	}
    			   for(int j=0;j<size;j++)
    			   {
    			    	puzzle[size-1][j]='-';
    		    	}
    	    	}
            }
			for(int j=0;j<size;j++)
        	{
    	    	int counting=0;
    	    	for(int i=0;i<size;i++)
    	    	{
    		    	if(puzzle[i][j]=='#')
    		    	{
    				    counting++;
    			    }
		     	}
			    if(counting==size)
		    	{
			    	game.score++;
			    	if(game.score>game.high_score)
			    	{
					game.high_score=game.score;
			    	}
				    for(int i=0;i<size;i++)
			    	{
					puzzle[i][j]='-';
			    	}
		    	}
		    }
		    for(int i=0;i<size;i++)
		    {
		    	for(int j=0;j<size;j++)
		    	{
			    	cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}
	    }
        if(next_block2==2)
    	{
	    	int y1,y2,x;
	        char block[1][2];
	        for(int i=0;i<1;i++)
	        {
		        for(int j=0;j<2;j++)
		        {
		    	    block[i][j]='#';
		        }
	        }
	        for(int i=0;i<2;i++)
	        {
		        cout<<block[0][i];
	        }
	        cout<<endl;
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
    	    cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	    cout<<"SCORE: "<<game.score<<endl;
    	    for(int i=0;i<size;i++)
        	{
    		    for(int j=0;j<size;j++)
    		    {
    			    cout<<puzzle[i][j];
    		    }
    		    cout<<endl<<endl;
    	    }
    	    int z=rand();
    	    int y=z%4;
    	    if(y==1)
        	{
    		    next_block2=1;
    		    char next_block[1][1];
    		    next_block[0][0]='#';
			    cout<<next_block[0][0];	
	    	}
	    	else
	    	{
			    if(y==2)
			    {
				    next_block2=2;
				    char next_block[1][2];
	                for(int i=0;i<1;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                next_block[i][j]='#';
		                }
	                }
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][y];
	                }
	                cout<<endl;
		    	}
		    	else
		    	{
				    if(y==3)
				    {
				    	next_block2=3;
				        char next_block[2][1];
                	    for(int i=0;i<2;i++)
                    	{
		                    for(int j=0;j<1;j++)
	                    	{
			                    next_block[i][j]='#';
		                    }
	                    }
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
				    }
				    else
				    {
					    next_block2=4;
				    	char next_block[2][2];
	                    for(int i=0;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    next_block[i][j]='#';
		                    }
	                    }
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][y];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    }
		    }
		    cout<<endl;
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
    	    cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	    cout<<"SCORE: "<<game.score<<endl;
    	    if(puzzle[0][3]=='#'||puzzle[0][4]=='#')
        	{
    	    	return;
	    	}
	    	else
	    	{
	    		puzzle[0][3]=block[0][0];
	    		puzzle[0][4]=block[0][1];
	    		y1=3;
	    		y2=4;
	    		x=0;
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
				}
				cout<<endl;
			}
		    char a;
	    	while(tolower(a)!='s')
	    	{
    	        cin>>a;
    	        if(a=='2')
            	{
    	        	hint();
            	}
            	else
            	{
	        	    if(a=='3')
        		    {
        		        return;
        	    	}
        	    	else
        		    	if(tolower(a)=='a')
        		    	{
        		    		if(y1!=0&&puzzle[x][y1-1]=='-')
        		    		{
        		    		    puzzle[x][y1-1]='#';
        		    		   	puzzle[x][y2]='-';
        		    		    y1-=1;
        		    		    y2-=1;
        					}
		            	    for(int i=0;i<size;i++)
		            	    {
		            	    	for(int j=0;j<size;j++)
		            	    	{
		            	    		cout<<puzzle[i][j];
								}
								cout<<endl;
							}
						}
                        if(tolower(a)=='d')
		    	        {
		    	        	if(y2!=size-1&&puzzle[x][y2+1]=='-')
		            	   {
		            		    puzzle[x][y1]='-';
		            		    puzzle[x][y2+1]='#';
		            		    y1+=1;
		            		    y2+=1;
		        			}
	        	    	    for(int i=0;i<size;i++)
	        	    	    {
	        	    	    	for(int j=0;j<size;j++)
	        	    	    	{
	        	    	    		cout<<puzzle[i][j];
								}
								cout<<endl;
							}
						}
            	}
           }
		    if(tolower(a)=='s')
            {
            	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y2]=='-')
            	{
            		puzzle[x][y1]='-';
            		puzzle[x+1][y1]='#';
            		puzzle[x][y2]='-';
            		puzzle[x+1][y2]='#';
            		x+=1;
		    	}
	    	}
		    for(int i=0;i<size;i++)
		    {
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
	    		}
	    		cout<<endl;
	    	}
        	for(int i=size-1;i<0;i--)
        	{
        		int counting=0;
        		for(int j=0;j<size;j++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
        			}
        		}
    	    	if(counting==size)
    	    	{
    	    		game.score++;
    	    		for(int k=i;k<size-1;k++)
    	    		{
    	    			for(int j=0;j<size;j++)
    	    			{
    	    				puzzle[i][j]=puzzle[i+1][j];
    	    			}
    	    		}
        			for(int j=0;j<size;j++)
        			{
        				puzzle[size-1][j]='-';
        			}
        		}
        	}
        	for(int j=0;j<size;j++)
        	{
        		int counting=0;
        		for(int i=0;i<size;i++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
	    			}
		    	}
		    	if(counting==size)
	    		{
	    			game.score++;
	    			if(game.score>game.high_score)
	    			{
	    				game.high_score=game.score;
	    			}
	    			for(int i=0;i<size;i++)
	    			{
	    				puzzle[i][j]='-';
	    			}
	    		}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
    				cout<<puzzle[i][j];
    			}
	    		cout<<endl;
    		}
	    }
	    if(next_block2==3)
    	{
	    	int y,x;
	    	char block[2][1];
	        for(int i=0;i<2;i++)
	        {
	    	    for(int j=0;j<1;j++)
	    	    {
		    	    block[i][j]='#';
		        }
	        }
	        for(int i=0;i<1;i++)
	        {
		        cout<<block[0][i];
	        }
	        cout<<endl;
	        for(int i=1;i<2;i++)
  	       {
	    	    for(int j=0;j<1;j++)
	    	    {
	    		    cout<<block[i][j];
	    	    }
		        cout<<endl;
	        }
	       cout<<"* Retry(1)   *"<<endl;
	       cout<<"* Hint (2)   *"<<endl;
	       cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	for(int i=0;i<size;i++)
        	{
        		for(int j=0;j<size;j++)
        		{
        			cout<<puzzle[i][j];
        		}
        		cout<<endl;
        	}
    	    int z=rand();
        	int h=z%4;
        	if(h==1)
        	{
        		next_block2=1;
        		char next_block[1][1];
        		next_block[0][0]='#';
	    		cout<<next_block[0][0];	
	    	}
    		else
    		{
    			if(h==2)
    			{
    				next_block2=2;
    				char next_block[1][2];
    	            for(int i=0;i<1;i++)
    	            {
    		            for(int j=0;j<2;j++)
    		            {
    			            next_block[i][j]='#';
    		            }
    	            }
    	            for(int j=0;j<2;j++)
    	            {
    		            cout<<next_block[0][y];
    	            }
    	            cout<<endl;
    			}
			    else
			    {
			    	if(h==3)
			    	{
			    		next_block2=3;
			    	    char next_block[2][1];
                    	for(int i=0;i<2;i++)
                    	{
		                    for(int j=0;j<1;j++)
	                    	{
			                    next_block[i][j]='#';
		                    }
	                    }
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
				    else
			    	{
				    	next_block2=4;
				    	char next_block[2][2];
	                    for(int i=0;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    next_block[i][j]='#';
		                    }
	                    }
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    }
	    	}
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	if(puzzle[0][3]=='#'||puzzle[1][3]=='#')
        	{
        		return;
	    	}
	    	else
	    	{
	    		puzzle[0][3]=block[0][0];
	    		puzzle[1][3]=block[1][0];
	    		y=3;
	    		x=1;
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
				}
				cout<<endl;
			}
			char a;
	    	while(tolower(a)!='s')
	    	{
        	    cin>>a;
            	if(a=='2')
            	{
        	        hint();
            	}
    	        else
    	        {
		            if(a=='3')
		            {
		                return;
	        	    }
	        	    else
		        	    if(tolower(a)=='a')
		        	    {
		    	        	if(y!=0&&puzzle[x-1][y-1]=='-'&&puzzle[x][y-1]=='-')
		    	        	{
		    		            puzzle[x-1][y]='-';
		    	    	        puzzle[x][y]='-';
		    		            puzzle[x-1][y-1]='#';
		    		            puzzle[x][y-1]='#';
		    		            y-=1;
					        }
		    	    		for(int i=0;i<size;i++)
	    	                {
	    	                	for(int j=0;j<size;j++)
	    	                	{
	    		                	cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
		                	}
						}
                        if(tolower(a)=='d')
		    	        {
		    	        	if(y!=size-1&&puzzle[x-1][y+1]=='-'&&puzzle[x][y+1]=='-')
		    	            {
		    	        	    puzzle[x-1][y]='-';
		    	    	        puzzle[x][y]='-';
		    	    	        puzzle[x-1][y+1]='#';
		    	    	        puzzle[x][y+1]='#';
		    	    	        y+=1;
				    	    }
		    	        	for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	    	                	{
	    	                		cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
		                	}
						}
	    	    }
    	    }
           if(tolower(a)=='s')
           {
            	while(x!=size-1&&puzzle[x+1][y]=='-')
            	{
            		puzzle[x-1][y]='-';
            		puzzle[x+1][y]='#';
            		x+=1;
		    	}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
     			for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}
        	for(int i=size-1;i<0;i--)
        	{
        		int counting=0;
        		for(int j=0;j<size;j++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
        			}
    	    	}
    	    	if(counting==size)
    	    	{
    	    		game.score++;
    	    		for(int k=i;k<size-1;k++)
    		    	{
    			    	for(int j=0;j<size;j++)
    			    	{
    			    		puzzle[i][j]=puzzle[i+1][j];
    			    	}
    		    	}
    			    for(int j=0;j<size;j++)
    		    	{
    			    	puzzle[size-1][j]='-';
    			    }
    	    	}
        	}
    	    for(int j=0;j<size;j++)
    	    {
    	    	int counting=0;
    	    	for(int i=0;i<size;i++)
    	    	{
    	    		if(puzzle[i][j]=='#')
    		    	{
    		    		counting++;
			    	}
		    	}
			    if(counting==size)
			    {
			    	game.score++;
			    	if(game.score>game.high_score)
			    	{
			    		game.high_score=game.score;
			    	}
			    	for(int i=0;i<size;i++)
			    	{
			    		puzzle[i][j]='-';
			    	}
		    	}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
		    		cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}
    	}
        if(next_block2==4)
	    {
	    	int y1,y2,x;
	    	char block[2][2];
	        for(int i=0;i<2;i++)
	        {
	    	    for(int j=0;j<2;j++)
		        {
		    	    block[i][j]='#';
		        }
    	    }
	        for(int i=0;i<2;i++)
	        {
	    	    cout<<block[0][i];
	        }
	        cout<<endl;
	        for(int i=1;i<2;i++)
	        {
	    	    for(int j=0;j<2;j++)
    		    {
	    		    cout<<block[i][j];
	    	    }
	    	    cout<<endl;
	        }
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
    	    cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	for(int i=0;i<size;i++)
        	{
        		for(int j=0;j<size;j++)
        		{
        			cout<<puzzle[i][j];
        		}
        		cout<<endl<<endl;
        	}
        	int z=rand();
        	int y=z%4;
        	if(y==1)
        	{
        		next_block2=1;
    	    	char next_block[1][1];
        		next_block[0][0]='#';
	    		cout<<next_block[0][0];	
	    	}
	    	else
	    	{
	    		if(y==2)
	    		{
	    			next_block2=2;
    				char next_block[1][2];
    	            for(int i=0;i<1;i++)
    	            {
    		            for(int j=0;j<2;j++)
    		            {
    			            next_block[i][j]='#';
    		            }
    	            }
    	            for(int j=0;j<2;j++)
    	            {
    		            cout<<next_block[0][j];
    	            }
    	            cout<<endl;
    			}
		    	else
		    	{
		    		if(y==3)
		    		{
		    			next_block2=3;
		    		    char next_block[2][1];
                    	for(int i=0;i<2;i++)
                    	{
		                    for(int j=0;j<1;j++)
	                    	{
			                    next_block[i][j]='#';
		                    }
	                    }
    	                for(int j=0;j<1;j++)
	                    {
	    	                cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
	    	                for(int j=0;j<1;j++)
	    	                {
	    		                cout<<next_block[i][j];
	    	                }
		                    cout<<endl;
	                    }
			    	}
				    else
				    {
				    	next_block2=4;
				    	char next_block[2][2];
	                    for(int i=0;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    next_block[i][j]='#';
		                    }
	                    }
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
		    	                cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
		    	}
		    }
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	if(puzzle[0][3]=='#'||puzzle[0][4]=='#')
        	{
        		return;
	    	}
	    	else
	    	{
		    	puzzle[0][3]=block[0][0];
		    	puzzle[0][4]=block[0][1];
		    	puzzle[1][3]=block[1][0];
		    	puzzle[1][4]=block[1][1];
		    	y1=3;
		    	y2=4;
		    	x=1;
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
				}
				cout<<endl;
			}
			char a;
	    	while(tolower(a)!='s')
	    	{
        	    cin>>a;
        		if(a=='2')
        		{
        			hint();
        		}
        		else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	        		}
	    	    	else
		        		if(tolower(a)=='a')
		        	    {
		        		    if(y1!=0&&puzzle[0][y1-1]=='-'&&puzzle[1][y1-1]=='-')
		        		    {
		    		        	puzzle[0][y2]='-';
		    		        	puzzle[1][y2]='-';
		    		        	puzzle[0][y1-1]='#';
		    		        	puzzle[1][y1-1]='#';
		    		        	y1-=1;
		    		        	y2-=1;
					    	}
		    			    for(int i=0;i<size;i++)
	                      	{
	    	                	for(int j=0;j<size;j++)
	    	                  	{
	    		                	cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
		                  	}
						}
                        if(tolower(a)=='d')
		    	    	{
		    	    	    if(y2!=size-1&&puzzle[0][y2+1]=='-'&&puzzle[1][y2+1]=='-')
		    	    	    {
		    	    	    	puzzle[0][y1]='-';
		    	    	    	puzzle[1][y1]='-';
		    	    	    	puzzle[0][y2+1]='#';
		    	    	    	puzzle[1][y2+1]='#';
		    	    	    	y1+=1;
		    	    	    	y2+=1;
				    		}
		    	    		for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	                    		{
	                    			cout<<puzzle[i][j];
		                 		}
		                		cout<<endl;
		                	}
						}
	    	   }
	        }
            if(tolower(a)=='s')
            {
            	while(x!=size-1&&puzzle[x+2][y1]=='-'&&puzzle[x+2][y2]=='-')
            	{
            		puzzle[x][y1]='-';
            		puzzle[x+2][y1]='#';
            		puzzle[x][y2]='-';
            		puzzle[x+2][y2]='#';
            		x+=1;
	    		}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
	    		}
	    		cout<<endl;
	    	}
        	for(int i=size-1;i<0;i--)
        	{
        		int counting=0;
        		for(int j=0;j<size;j++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
        			}
        		}
        		if(counting==size)
        		{
        			game.score++;
        			for(int k=i;k<size-1;k++)
        			{
    	    			for(int j=0;j<size;j++)
    	    			{
    	    				puzzle[i][j]=puzzle[i+1][j];
    	    			}
        			}
    	    		for(int j=0;j<size;j++)
    	    		{
        				puzzle[size-1][j]='-';
    		    	}
    	    	}
        	}
        	for(int j=0;j<size;j++)
        	{
        		int counting=0;
        		for(int i=0;i<size;i++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
	    			}
	    		}
	    		if(counting==size)
	    		{
	    			game.score++;
	    			if(game.score>game.high_score)
	    			{
	    				game.high_score=game.score;
	    			}
	    			for(int i=0;i<size;i++)
	    			{
	    				puzzle[i][j]='-';
	    			}
		    	}
	     	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
	    		}
	    		cout<<endl;
	    	}
    	}
        if(next_block2==5)
	    {
    		int y1,y2,x;
    		char block[2][2];
    	    block[0][0]=' ';
    	    block[0][1]='#';
	        block[1][0]='#';
	        block[1][1]='#';
	        for(int i=0;i<2;i++)
	        {
	    	    cout<<block[0][i];
	        }
	        cout<<endl;
	       for(int i=1;i<2;i++)
	       {
	    	    for(int j=0;j<2;j++)
	    	    {
	    		    cout<<block[i][j];
	    	    }
	    	    cout<<endl;
	        }
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	for(int i=0;i<size;i++)
        	{
    	    	for(int j=0;j<size;j++)
    	    	{
    	    		cout<<puzzle[i][j];
    	    	}
    	    	cout<<endl;
        	}
        	int z=rand();
        	int y=z%8;
        	if(y==1)
        	{	
        	    next_block2=5;
    	        char next_block[2][2];
	            next_block[0][0]='-';
	            next_block[0][1]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
	            for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[0][j];
		    	}
		    	cout<<endl;
		    	for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[1][j];
		    	}
		    	cout<<endl;
	    	}
	    	else
	    	{
	    		if(y==2)
	    		{
	    			next_block2=6;
	    			char next_block[2][2];
	                next_block[0][0]='#';
	                next_block[0][1]='-';
	                next_block[1][0]='#';
	                next_block[1][1]='#';
	                for(int j=0;j<2;j++)
	                {
	            	    cout<<next_block[0][j];
	    		    }
			        for(int j=0;j<2;j++)
	                {
	            	    cout<<next_block[1][j];
			        }
			        cout<<endl;
		    	}
			    else
			    {
			    	if(y==3)
			    	{
			    		next_block2=7;
			    		char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='-';
	                    next_block[1][1]='#';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                   cout<<endl;
	                    }
			    	}
			    	else
			    	{
			     	   if(y==4)
			    	   {
			    		    next_block2=8;
			    		    char next_block[2][2];
	                        next_block[0][0]='#';
	                        next_block[0][1]='#';
	                        next_block[1][0]='#';
	                        next_block[1][1]='-';
	                        for(int j=0;j<1;j++)
	                        {
		                        cout<<next_block[0][j];
	                        }
	                        cout<<endl;
	                        for(int i=1;i<2;i++)
	                        {
		                        for(int j=0;j<1;j++)
		                        {
			                        cout<<next_block[i][j];
		                        }
		                        cout<<endl;
	                        }
			        	}
			        	else
			        	{
			        		if(y==5)
				            {
				    	        next_block2=9;
				    	        char next_block[1][3];
	                            for(int i=0;i<1;i++)
                        	    {
		                            for(int j=0;j<3;j++)
		                            {
			                            next_block[i][j]='#';
		                            }
	                            }
	                            cout<<endl;
			        	    }
			        	    else
			        	    {
			    	    	    if(y==6)
				                {
					                next_block2=10;
					                char next_block[3][1];
	                                for(int i=0;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
                                	}
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
			    	            else
			    	            {
			    	            	if(y==7)
				                    {
					                    next_block2=11;
					                    char next_block[1][4];
	                                    for(int i=0;i<1;i++)
	                                    {
		                                    for(int j=0;j<4;j++)
		                                    {
			                                    next_block[i][j]='#';
		                                    }
	                                    }
	                                    for(int j=0;j<4;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
			    	                }
			    	                else
				                    {
					                    next_block2=12;
					                    char next_block[4][1];
	                                    for(int i=0;i<4;i++)
	                                    {
		                                    for(int j=0;j<1;j++)
	                                    	{
			                                    next_block[i][j]='#';
		                                    }
	                                    }					            
    	                                for(int j=0;j<1;j++)
    	                                {
    		                                cout<<next_block[0][j];
    	                                }
    	                                cout<<endl;
    	                                for(int i=1;i<4;i++)
    	                                {
    		                                for(int j=0;j<1;j++)
    		                                {
    			                                cout<<next_block[i][j];
    		                                }
    		                                cout<<endl;
    	                                }
			    	                }
						    	}
					    	}
				    	}
			    	}
		    	}
	     	}
	    	cout<<endl;
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	if(puzzle[1][4]=='#'||puzzle[1][3]=='#'||puzzle[0][4]=='#')
        	{
        		return;
	    	}
	    	else
	    	{
	    		puzzle[0][4]=block[0][1];
	     		puzzle[1][3]=block[1][0];
	    		puzzle[1][4]=block[1][1];
	    		y1=3;
	    		y2=4;
	    		x=1;
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
				}
				cout<<endl;
			}
			char a;
	    	while(tolower(a)!='s')
	    	{
        	    cin>>a;
        		if(a=='2')
        		{
        			hint();
        		}
        		else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	        		}
	    		    else
		    	    	if(tolower(a)=='a')
		    	        {
		    	    	    if(y1!=0&&puzzle[x-1][y2-1]=='-'&&puzzle[x][y1-1]=='-')
		    		        {
		    		        	puzzle[x-1][y2]='-';
		    		        	puzzle[x-1][y2-1]='#';
		    		        	puzzle[x][y1-1]='#';
		    		        	puzzle[x][y2]='-';
		    		        	y1-=1;
		    		        	y2-=1;
					    	}
		    			    for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	    	                	{
	    		                	cout<<puzzle[i][j];
		                		}
			                	cout<<endl;
		                 	}
				      	}
                       if(tolower(a)=='d')
		    	    	{
		    		        if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2+1]=='-')
		    		        {
		    		        	puzzle[x][y1]='-';
		    		        	puzzle[x-1][y1+1]='-';
		    		        	puzzle[x-1][y2+1]='#';
		    		        	puzzle[x][y2+1]='#';
		    		        	y1+=1;
		    		        	y2+=1;
					    	}
		    	    	    for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	    	                	{
	    		                	cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
		                	}
						}
	           }
            }
		    if(tolower(a)=='s')
            {
            	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y2]=='-')
            	{
            		puzzle[x][y1]='-';
        	    	puzzle[x+1][y1]='#';
        	    	puzzle[x-1][y2]='-';
        	    	puzzle[x+1][y2]='#';
        	    	x+=1;
	    		}
    		}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
	    		}
	    		cout<<endl;
	    	}
        	for(int i=size-1;i<0;i--)
        	{
        		int counting=0;
        		for(int j=0;j<size;j++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
        			}
    	    	}
    	    	if(counting==size)
    	    	{
    	    		game.score++;
    	    		for(int k=i;k<size-1;k++)
    	    		{
    	    			for(int j=0;j<size;j++)
    		    		{
    		    			puzzle[i][j]=puzzle[i+1][j];
    			    	}
    		     	}
    			    for(int j=0;j<size;j++)
    		    	{
    			    	puzzle[size-1][j]='-';
    		    	}
    	    	}
        	}
    	    for(int j=0;j<size;j++)
        	{
        		int counting=0;
    	    	for(int i=0;i<size;i++)
    	    	{
    	    		if(puzzle[i][j]=='#')
    		    	{
    		    		counting++;
			    	}
		    	}
		    	if(counting==size)
		    	{
		    		game.score++;
		    		if(game.score>game.high_score)
		    		{
		    			game.high_score=game.score;
		    		}
			    	for(int i=0;i<size;i++)
			    	{
			    		puzzle[i][j]='-';
			    	}
		    	}
    		}
		    for(int i=0;i<size;i++)
		    {
		    	for(int j=0;j<size;j++)
		    	{
		    		cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}	
    	}
        if(next_block2==6)
    	{
    		int y1,y2,x;
    	    char block[2][2];
    	    block[0][0]='#';
    	    block[0][1]=' ';
    	    block[1][0]='#';
    	    block[1][1]='#';
    	    for(int i=0;i<2;i++)
    	    {
    		    cout<<block[0][i];
    	    }
	        cout<<endl;
	        for(int i=1;i<2;i++)
	        {
		        for(int j=0;j<2;j++)
		        {
		    	    cout<<block[i][j];
		        }
		        cout<<endl;
	        }
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	for(int i=0;i<size;i++)
        	{
        		for(int j=0;j<size;j++)
        		{
        			cout<<puzzle[i][j];
        		}
        		cout<<endl<<endl;
        	}
        	int z=rand();
        	int y=z%8;
        	if(y==1)
        	{	
        	    next_block2=5;
        	    char next_block[2][2];
    	        next_block[0][0]='-';
    	        next_block[0][1]='#';
    	        next_block[1][0]='#';
    	        next_block[1][1]='#';
    	        for(int j=0;j<2;j++)
    	        {
    	        	cout<<next_block[0][j];
    			}
    			cout<<endl;
    			for(int j=0;j<2;j++)
    	        {
    	        	cout<<next_block[1][j];
    			}
    			cout<<endl;
    		}
    		else
    		{
    			if(y==2)
    			{
    				next_block2=6;
    				char next_block[2][2];
    	            next_block[0][0]='#';
    	            next_block[0][1]='-';
    	            next_block[1][0]='#';
    	            next_block[1][1]='#';
    	            for(int j=0;j<2;j++)
    	            {
    	        	    cout<<next_block[0][j];
    			    }
    			    cout<<endl;
    			    for(int j=0;j<2;j++)
    	            {
    	        	    cout<<next_block[1][j];
    			    }
    			    cout<<endl;
		    	}
		    	else
		    	{
		    		if(y==3)
		    		{
		    			next_block2=7;
		    			char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='-';
	                    next_block[1][1]='#';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    	   if(y==4)
			    	   {
			    		    next_block2=8;
			    		    char next_block[2][2];
	                        next_block[0][0]='#';
	                        next_block[0][1]='#';
	                        next_block[1][0]='#';
	                        next_block[1][1]='-';
	                        for(int j=0;j<1;j++)
	                        {
		                        cout<<next_block[0][j];
	                        }
	                        cout<<endl;
	                        for(int i=1;i<2;i++)
	                        {
		                        for(int j=0;j<1;j++)
		                        {
			                        cout<<next_block[i][j];
		                        }
		                        cout<<endl;
	                        }
			        	}
			        	else
			        	{
			        		if(y==5)
				            {
				    	        next_block2=9;
				    	        char next_block[1][3];
	                            for(int i=0;i<1;i++)
                        	    {
		                            for(int j=0;j<3;j++)
		                            {
			                            next_block[i][j]='#';
		                            }
	                            }
	                            for(int i=0;i<1;i++)
	                            {
	                            	for(int j=0;j<3;j++)
	                            	{
	                            		cout<<next_block[i][j];
									}
									cout<<endl;
								}
			    	        }
			    	       else
			    	       {
			    	        	if(y==6)
				                {
					                next_block2=10;
					                char next_block[3][1];
	                                for(int i=0;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
                                	}
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
			    	            else
			    	            {
			    	            	if(y==7)
				                    {
					                    next_block2=11;
					                    char next_block[1][4];
	                                    for(int i=0;i<1;i++)
	                                    {
		                                    for(int j=0;j<4;j++)
		                                    {
			                                    next_block[i][j]='#';
		                                    }
	                                    }
	                                    for(int j=0;j<4;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
			    	                }
			    	                else
				                    {
					                    next_block2=12;
					                    char next_block[4][1];
	                                    for(int i=0;i<4;i++)
	                                    {
		                                    for(int j=0;j<1;j++)
	                                    	{
			                                    next_block[i][j]='#';
		                                    }
	                                    }					            
	                                    for(int j=0;j<1;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<4;i++)
	                                    {
		                                    for(int j=0;j<1;j++)
		                                    {
			                                    cout<<next_block[i][j];
		                                    }
		                                    cout<<endl;
	                                    }
			    	                }
						    	}
					    	}
					    }
			    	}
		    	}
	    	}
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	if(puzzle[1][4]=='#'||puzzle[1][3]=='#'||puzzle[0][4]=='#')
        	{
        		return;
	    	}
	    	else
	    	{
	    		puzzle[0][3]=block[0][0];
	    		puzzle[1][3]=block[1][0];
	    		puzzle[1][4]=block[1][1];
	    		y1=3;
	    		y2=4;
	    		x=1;
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
				}
				cout<<endl;
			}
		    char a;
	    	while(tolower(a)!='s')
	    	{
        	    cin>>a;
        		if(a=='2')
        		{
        			hint();
        		}
        		else
        		{
	    	    	if(a=='3')
	    	    	{
	    	    		return;
	        		}
	        		else
		        		if(tolower(a)=='a')
		        	    {
		        		    if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1-1]=='-')
		        		    {
		        		    	puzzle[x-1][y2-1]='-';
		        		    	puzzle[x-1][y1-1]='#';
		        		    	puzzle[x][y1-1]='#';
		        		    	puzzle[x][y2]='-';
		        		    	y1-=1;
		        		    	y2-=1;
			    			}
			    			for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	    	                	{
	    	                		cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
		                 	}
		    			}
                        if(tolower(a)=='d')
		    	    	{
		    	    	    if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2+1]=='-')
		    		        {
		    		        	puzzle[x][y1]='-';
		    		        	puzzle[x-1][y1]='-';
		    	    	    	puzzle[x-1][y1+1]='#';
		    	    	    	puzzle[x][y2+1]='#';
		    	    	    	y1+=1;
		    	    	    	y2+=1;
				    		}
				    		for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	    	                	{
	    		                	cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
		                	}
		    	    	}
	            }
	        }
            if(tolower(a)=='s')
            {
            	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y2]=='-')
            	{
            		puzzle[x][y2]='-';
            		puzzle[x+1][y1]='#';
            		puzzle[x-1][y1]='-';
            		puzzle[x+1][y2]='#';
            		x+=1;
	    		}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}
        	for(int i=size-1;i<0;i--)
        	{
        		int counting=0;
        		for(int j=0;j<size;j++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
        			}
        		}
    	    	if(counting==size)
    	    	{
    	    		game.score++;
    	    		for(int k=i;k<size-1;k++)
    	    		{
    	    			for(int j=0;j<size;j++)
    	    			{
    	    				puzzle[i][j]=puzzle[i+1][j];
    		    		}
    		    	}
    		    	for(int j=0;j<size;j++)
    		    	{
    		    		puzzle[size-1][j]='-';
    		    	}
    	    	}
        	}
        	for(int j=0;j<size;j++)
        	{
        		int counting=0;
        		for(int i=0;i<size;i++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
	    			}
		    	}
		    	if(counting==size)
	    		{
		    		game.score++;
		    		if(game.score>game.high_score)
		    		{
		    			game.high_score=game.score;
		     		}
		    		for(int i=0;i<size;i++)
			    	{
			    		puzzle[i][j]='-';
			    	}
		    	}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
		    	for(int j=0;j<size;j++)
		    	{
		    		cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}	
    	}
        if(next_block2==7)
    	{
    		int y1,y2,x;
    		char block[2][2];
    	    block[0][0]='#';
    	    block[0][1]='#';
	        block[1][0]='-';
	        block[1][1]='#';
	        for(int i=0;i<2;i++)
	        {
	    	    cout<<block[0][i];
	        }
	        cout<<endl;
	        for(int i=1;i<2;i++)
            {
	    	    for(int j=0;j<2;j++)
	    	    {
	    		    cout<<block[i][j];
	    	    }
		        cout<<endl;
	        }
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	for(int i=0;i<size;i++)
        	{
        		for(int j=0;j<size;j++)
        		{
        			cout<<puzzle[i][j];
        		}
        		cout<<endl<<endl;
        	}
        	int z=rand();
        	int y=z%8;
        	if(y==1)
        	{	
        	    next_block2=5;
        	    char next_block[2][2];
	            next_block[0][0]='-';
	            next_block[0][1]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
	            for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[0][j];
		    	}
		    	cout<<endl;
			    for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[1][j];
		    	}
		    	cout<<endl;
	    	}
	    	else
	    	{
	    		if(y==2)
	    		{
	    			next_block2=6;
	    			char next_block[2][2];
	                next_block[0][0]='#';
	                next_block[0][1]='-';
	                next_block[1][0]='#';
	                next_block[1][1]='#';
	                for(int j=0;j<2;j++)
	                {
	            	    cout<<next_block[0][j];
	    		    }
			        cout<<endl;
			        for(int j=0;j<2;j++)
	                {
	            	    cout<<next_block[1][j];
			        }
			        cout<<endl;
		    	}
		    	else
		    	{
		    		if(y==3)
		    		{
		    			next_block2=7;
		    			char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='-';
	                    next_block[1][1]='#';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
		    		{
		     		   if(y==4)
		    		   {
			    		    next_block2=8;
			     		    char next_block[2][2];
	                        next_block[0][0]='#';
	                        next_block[0][1]='#';
	                        next_block[1][0]='#';
	                        next_block[1][1]='-';
	                        for(int j=0;j<1;j++)
	                        {
		                        cout<<next_block[0][j];
	                        }
	                        cout<<endl;
	                        for(int i=1;i<2;i++)
	                        {
		                        for(int j=0;j<1;j++)
		                        {
			                    cout<<next_block[i][j];
		                        }
		                        cout<<endl;
	                        }
			        	}
			        	else
			        	{
			        		if(y==5)
				            {
					            next_block2=9;
					            char next_block[1][3];
	                            for(int i=0;i<1;i++)
                    	        {
		                            for(int j=0;j<3;j++)
		                            {
			                            next_block[i][j]='#';
		                            }
	                            }
	                            for(int i=0;i<1;i++)
	                            {
	                            	for(int j=0;j<3;j++)
	                            	{
	                            		cout<<next_block;
									}
									cout<<endl;
								}
			    	        }
			    	        else
			    	        {
			    	        	if(y==6)
				                {
					                next_block2=10;
					                char next_block[3][1];
	                                for(int i=0;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
                                	}
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
			    	           else
			    	           {
			    	            	if(y==7)
				                    {
					                    next_block2=11;
					                    char next_block[1][4];
	                                    for(int i=0;i<1;i++)
	                                    {
		                                    for(int j=0;j<4;j++)
		                                    {
			                                    next_block[i][j]='#';
		                                    }
	                                    }
	                                    for(int j=0;j<4;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
			    	                }
			    	                else
				                    {
					                    next_block2=12;
					                    char next_block[4][1];
	                                    for(int i=0;i<4;i++)
	                                    {
		                                    for(int j=0;j<1;j++)
	                                    	{
			                                    next_block[i][j]='#';
		                                    }
	                                    }					            
	                                    for(int j=0;j<1;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<4;i++)
	                                    {
		                                    for(int j=0;j<1;j++)
		                                    {
			                                    cout<<next_block[i][j];
		                                    }
		                                    cout<<endl;
	                                    }
			    	                }
							    }
					    	}
				    	}
			    	}
		    	}
	    	}
	    	cout<<endl;
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	if(puzzle[1][4]=='#'||puzzle[0][3]=='#'||puzzle[0][4]=='#')
        	{
        		return;
	    	}
	    	else
	    	{
	    		puzzle[0][3]=block[0][0];
		    	puzzle[0][4]=block[0][1];
		    	puzzle[1][4]=block[1][1];
		    	y1=3;
		    	y2=4;
		    	x=1;
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
				}
				cout<<endl;
			}
	    	char a;
	    	while(tolower(a)!='s')
	    	{
        	    cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
    	    	}
    	    	else
    	    	{
		        	if(a=='3')
		        	{
		    	    	return;
	    		    }
	    	    	else
		        		if(tolower(a)=='a')
		        	    {
		        		    if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y2-1]=='-')
		        		    {
		        		    	puzzle[x-1][y2]='-';
		        		    	puzzle[x-1][y1-1]='#';
		        		    	puzzle[x][y2-1]='#';
		        		    	puzzle[x][y2]='-';
		        		    	y1-=1;
		        		    	y2-=1;
					    	}
					    	for(int i=0;i<size;i++)
	    	                {
	    	                	for(int j=0;j<size;j++)
	    	                	{
	    		                	cout<<puzzle[i][j];
		                		}
			                	cout<<endl;
		                	}
		    		   	}
                       if(tolower(a)=='d')
		    	    	{
		    		        if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2+1]=='-')
		    		        {
		    		        	puzzle[x][y2]='-';
		    		        	puzzle[x-1][y1]='-';
		    		        	puzzle[x-1][y2+1]='#';
		    		        	puzzle[x][y2+1]='#';
		    		        	y1+=1;
		    		        	y2+=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	    	                	{
	                     			cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
		                	}
		    	    	}
	    	    }
        	}
            if(tolower(a)=='s')
            {
            	while(x!=size-1&&puzzle[x][y1]=='-'&&puzzle[x+1][y2]=='-')
            	{
            		puzzle[x-1][y2]='-';
            		puzzle[x][y1]='#';
            		puzzle[x-1][y1]='-';
            		puzzle[x+1][y2]='#';
            		x+=1;
		    	}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}
        	for(int i=size-1;i<0;i--)
        	{
    	    	int counting=0;
    	    	for(int j=0;j<size;j++)
    	    	{
    	    		if(puzzle[i][j]=='#')
    	    		{
    	    			counting++;
    	    		}
    	    	}
    		    if(counting==size)
    	    	{
    		    	game.score++;
    		    	for(int k=i;k<size-1;k++)
    		    	{
    		    		for(int j=0;j<size;j++)
    			    	{
    			    		puzzle[i][j]=puzzle[i+1][j];
    			    	}
    		    	}
    		    	for(int j=0;j<size;j++)
    		    	{
    		    		puzzle[size-1][j]='-';
    		    	}
    	    	}
        	}
    	   for(int j=0;j<size;j++)
        	{
        		int counting=0;
    	    	for(int i=0;i<size;i++)
    	    	{
    	    		if(puzzle[i][j]=='#')
    	    		{
    	    			counting++;
		    		}
		    	}
	    		if(counting==size)
	    		{
	    			game.score++;
	    			if(game.score>game.high_score)
	    			{
					game.high_score=game.score;
		    		}
			    	for(int i=0;i<size;i++)
		    		{
		    			puzzle[i][j]='-';
		    		}
		    	}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
		    		cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
		    }
    	}
        if(next_block2==8)
    	{
    		int y1,y2,x;
    		char block[2][2];
    	    block[0][0]='#';
    	    block[0][1]='#';
    	    block[1][0]='#';
    	    block[1][1]=' ';
    	    for(int i=0;i<2;i++)
    	    {
    		    cout<<block[0][i];
    	    }
    	    cout<<endl;
    	    for(int i=1;i<2;i++)
    	    {
    		    for(int j=0;j<2;j++)
    		    {
    			    cout<<block[i][j];
    		    }
		        cout<<endl;
	        }
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	for(int i=0;i<size;i++)
        	{
        		for(int j=0;j<size;j++)
        		{
        			cout<<puzzle[i][j];
        		}
    		    cout<<endl<<endl;
        	}
        	int z=rand();
        	int y=z%8;
        	if(y==1)
        	{	
        	    next_block2=5;
        	    char next_block[2][2];
	            next_block[0][0]='-';
	            next_block[0][1]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
	            for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[0][j];
	    		}
	    		cout<<endl;
		    	for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[1][j];
		    	}
		    	cout<<endl;
	    	}
	    	else
	    	{
	    		if(y==2)
	    		{
	    			next_block2=6;
	    			char next_block[2][2];
	                next_block[0][0]='#';
	                next_block[0][1]='-';
	                next_block[1][0]='#';
	                next_block[1][1]='#';
	                for(int j=0;j<2;j++)
	                {
	            	    cout<<next_block[0][j];
		    	    }
			        cout<<endl;
			        for(int j=0;j<2;j++)
	                {
	        	        cout<<next_block[1][j];
			        }
			        cout<<endl;
		    	}
		    	else
		    	{
		    		if(y==3)
		    		{
		    			next_block2=7;
		    			char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='-';
	                    next_block[1][1]='#';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    	   if(y==4)
			    	   {
			    		    next_block2=8;
			    		    char next_block[2][2];
	                        next_block[0][0]='#';
	                        next_block[0][1]='#';
	                        next_block[1][0]='#';
	                        next_block[1][1]='-';
	                        for(int j=0;j<1;j++)
	                        {
		                        cout<<next_block[0][j];
	                        }
	                        cout<<endl;
	                        for(int i=1;i<2;i++)
	                        {
		                        for(int j=0;j<1;j++)
		                        {
			                        cout<<next_block[i][j];
		                        }
		                        cout<<endl;
	                        }
			        	}
			        	else
			    	    {
			    	    	if(y==5)
				            {
					            next_block2=9;
					            char next_block[1][3];
	                            for(int i=0;i<1;i++)
                        	    {
		                            for(int j=0;j<3;j++)
		                            {
			                            next_block[i][j]='#';
		                            }
	                            }
	                            for(int i=0;i<1;i++)
	                            {
	                            	for(int j=0;j<3;j++)
	                            	{
	                            		cout<<next_block[i][j];
									}
									cout<<endl;
								}
			    	        }
			    	        else
			    	        {
			    	        	if(y==6)
				                {
					                next_block2=10;
					                char next_block[3][1];
	                                for(int i=0;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
                                	}
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
			    	            else
			    	            {
			    	            	if(y==7)
				                    {
					                    next_block2=11;
					                    char next_block[1][4];
	                                    for(int i=0;i<1;i++)
	                                    {
		                                    for(int j=0;j<4;j++)
		                                    {
			                                    next_block[i][j]='#';
		                                    }
	                                    }
	                                    for(int j=0;j<4;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
			    	                }
			    	                else
				                    {
					                    next_block2=12;
					                    char next_block[4][1];
	                                    for(int i=0;i<4;i++)
	                                    {
		                                    for(int j=0;j<1;j++)
	                                    	{
			                                    next_block[i][j]='#';
		                                    }
	                                    }					            
	                                    for(int j=0;j<1;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<4;i++)
	                                    {
		                                    for(int j=0;j<1;j++)
		                                    {
			                                    cout<<next_block[i][j];
		                                    }
		                                   cout<<endl;
	                                    }
			    	                }
						    	}
					    	}
				    	}
			    	}
		    	}
	    	}
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	if(puzzle[1][4]=='#'||puzzle[0][3]=='#'||puzzle[0][4]=='#')
        	{
        		return;
	     	}
	    	else
	    	{
	    		puzzle[0][3]=block[0][0];
	    		puzzle[0][4]=block[0][1];
	    		puzzle[1][3]=block[1][0];
	    		y1=3;
	    		y2=4;
	    		x=1;
	    	}
	    	for(int i=0;i<size;i++)
	    	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
				}
				cout<<endl;
			}
	    	char a;
	    	while(tolower(a)!='s')
	    	{
        	    cin>>a;
        		if(a=='2')
        		{
        			hint();
        		}
    	    	else
    	    	{
		        	if(a=='3')
		        	{
		        	    return;
	        		}
	    	    	else
		        		if(tolower(a)=='a')
		    	        {
		    	    	    if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1-1]=='-')
		    	    	    {
		    	    	    	puzzle[x-1][y2]='-';
		    	    	    	puzzle[x-1][y1-1]='#';
		    	    	    	puzzle[x][y1-1]='#';
		    	    	    	puzzle[x][y2-1]='-';
		    	    	    	y1-=1;
		    	    	    	y2-=1;
				    		}
				    		for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
	                    		{
	    	                		cout<<puzzle[i][j];
			                	}
			                	cout<<endl;
	                 		}
		    			}
                        if(tolower(a)=='d')
		    	    	{
		    	    	    if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y1+1]=='-')
		    	    	    {
		    	    	    	puzzle[x][y1]='-';
		    	    	    	puzzle[x-1][y1]='-';
		    	    	    	puzzle[x-1][y2+1]='#';
		    	    	    	puzzle[x][y1+1]='#';
		    	    	    	y1+=1;
		    	    	    	y2+=1;
				    		}
				    		for(int i=0;i<size;i++)
	                    	{
	    	                	for(int j=0;j<size;j++)
	                    		{
	    	                		cout<<puzzle[i][j];
		                		}
		                		cout<<endl;
		                	}
		    	    	}
	    	    }
            }
           if(tolower(a)=='s')
           {
            	while(x!=size-1&&puzzle[x][y2]=='-'&&puzzle[x+1][y1]=='-')
            	{
            		puzzle[x-1][y2]='-';
            		puzzle[x][y2]='#';
            		puzzle[x-1][y1]='-';
            		puzzle[x+1][y1]='#';
            		x+=1;
		    	}
	    	}
	    	for(int i=0;i<size;i++)
	     	{
	    		for(int j=0;j<size;j++)
	    		{
	    			cout<<puzzle[i][j];
	    		}
	    		cout<<endl;
	    	}
        	for(int i=size-1;i<0;i--)
        	{
    	    	int counting=0;
    	    	for(int j=0;j<size;j++)
    	    	{
    	    		if(puzzle[i][j]=='#')
    	    		{
    	    			counting++;
    	    		}
    	    	}
    	    	if(counting==size)
    	    	{
    	    		game.score++;
    	    		for(int k=i;k<size-1;k++)
    	    		{
    		    		for(int j=0;j<size;j++)
    		    		{
    			    		puzzle[i][j]=puzzle[i+1][j];
    			    	}
    		    	}
    		    	for(int j=0;j<size;j++)
    		    	{
    		    		puzzle[size-1][j]='-';
    		    	}
    	    	}
        	}
        	for(int j=0;j<size;j++)
        	{
        		int counting=0;
        		for(int i=0;i<size;i++)
        		{
        			if(puzzle[i][j]=='#')
        			{
        				counting++;
	    			}
	    		}
		    	if(counting==size)
		    	{
		    		game.score++;
		    		if(game.score>game.high_score)
		    		{
		    			game.high_score=game.score;
		    		}
			    	for(int i=0;i<size;i++)
			    	{
			    		puzzle[i][j]='-';
			    	}
		    	}
	    	}
	    	for(int i=0;i<size;i++)
	    	{
		    	for(int j=0;j<size;j++)
	    		{
		    		cout<<puzzle[i][j];
		    	}
		    	cout<<endl;
	    	}
		}	
        if(next_block2==9)
	    {
	    	int y1,y2,x;
	    	char block[1][3];
	        for(int i=0;i<1;i++)
	        {
	    	    for(int j=0;j<3;j++)
	    	    {
	    		    block[i][j]='#';
	    	    }
	        }
	        for(int i=0;i<3;i++)
	        {
	    	    cout<<block[0][i];
	        }
	        cout<<endl;
	        cout<<"* Retry(1)   *"<<endl;
	        cout<<"* Hint (2)   *"<<endl;
	        cout<<"* Exit (3)   *"<<endl;
        	cout<<"HIGH SCORE: "<<game.high_score<<endl;
        	cout<<"SCORE: "<<game.score<<endl;
        	for(int i=0;i<size;i++)
        	{
    	    	for(int j=0;j<size;j++)
    	    	{
    	    		cout<<puzzle[i][j];
    	    	}
    	    	cout<<endl<<endl;
        	}
        	int z=rand();
        	int y=z%8;
        	if(y==1)
        	{	
        	    next_block2=5;
        	    char next_block[2][2];
	            next_block[0][0]='-';
	            next_block[0][1]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
	            for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[0][j];
	    		}
	    		cout<<endl;
	    		for(int j=0;j<2;j++)
	            {
	            	cout<<next_block[1][j];
	    		}
	    	}
	    	else
	    	{
	    		if(y==2)
	    		{
	    			next_block2=6;
	    			char next_block[2][2];
	                next_block[0][0]='#';
	                next_block[0][1]='-';
	                next_block[1][0]='#';
	                next_block[1][1]='#';
	                for(int j=0;j<2;j++)
	                {
	        	        cout<<next_block[0][j];
			        }
			        cout<<endl;
			        for(int j=0;j<2;j++)
	                {
	            	    cout<<next_block[1][j];
			        }
			        cout<<endl;
		    	}
		    	else
		    	{
		    		if(y==3)
		    		{
		    			next_block2=7;
		    			char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='-';
	                    next_block[1][1]='#';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    	   if(y==4)
				      {
				    	    next_block2=8;
				    	    char next_block[2][2];
	                        next_block[0][0]='#';
	                        next_block[0][1]='#';
	                        next_block[1][0]='#';
	                        next_block[1][1]='-';
	                        for(int j=0;j<1;j++)
	                        {
		                        cout<<next_block[0][j];
	                        }
	                        cout<<endl;
	                        for(int i=1;i<2;i++)
	                        {
		                        for(int j=0;j<1;j++)
		                        {
			                        cout<<next_block[i][j];
		                        }
		                        cout<<endl;
	                        }
			    	    }
			    	    else
			        	{
			    		    if(y==5)
				            {
					            next_block2=9;
					            char next_block[1][3];
	                            for(int i=0;i<1;i++)
                    	        {
		                            for(int j=0;j<3;j++)
		                            {
			                            next_block[i][j]='#';
		                            }
	                            }
	                            for(int i=0;i<1;i++)
	                            {
	                            	for(int j=0;j<3;j++)
	                            	{
	                            		cout<<next_block[i][j];
									}
								}
			    	        }
			    	        else
			    	        {
			    	        	if(y==6)
				                {
					                next_block2=10;
					                char next_block[3][1];
	                                for(int i=0;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
                                	}
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
			    	           else
			    	           {
			    	            	if(y==7)
				                    {
					                    next_block2=11;
					                    char next_block[1][4];
	                                    for(int i=0;i<1;i++)
	                                    {
		                                    for(int j=0;j<4;j++)
		                                    {
			                                    next_block[i][j]='#';
		                                    }
	                                    }
	                                    for(int j=0;j<4;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
			    	                }
			    	                else
				                    {
					                    next_block2=12;
					                    char next_block[4][1];
	                                   for(int i=0;i<4;i++)
	                                   {
		                                    for(int j=0;j<1;j++)
	                                    	{
			                                    next_block[i][j]='#';
		                                    }
	                                    }					            
	                                   for(int j=0;j<1;j++)
	                                   {
		                                    cout<<next_block[0][j];
	                                    }
	                                   cout<<endl;
	                                   for(int i=1;i<4;i++)
	                                   {
		                                    for(int j=0;j<1;j++)
		                                    {
			                                    cout<<next_block[i][j];
		                                    }
		                                    cout<<endl;
	                                    }
			    	                }
						    	}
						}
					    }
			    	}
			    }
	    	}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[1][4]=='#'||puzzle[0][3]=='#'||puzzle[0][4]=='#')
    	{
    		return;
		}
		else
		{
			puzzle[0][3]=block[0][0];
			puzzle[0][4]=block[0][1];
			puzzle[0][5]=block[0][2];
			y1=3;
			y2=5;
			x=0;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
		}
		cout<<endl;
		    char a;
		    while(tolower(a)!='s')
	    	{
    	        cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
    	    	}
    	    	else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	        		}
	    	    	else
		    	    	if(tolower(a)=='a')
		    	        {
		    	    	    if(y1!=0&&puzzle[x][y1-1]=='-')
		    	    	    {
		    	    	    	puzzle[x][y1-1]='#';
				    			puzzle[x][y2]='-';
		    	    	    	y1-=1;
		    	    	    	y2-=1;
				    		}
				    		for(int i=0;i<size;i++)
		                    {
	                    		for(int j=0;j<size;j++)
	                    		{
		                    		cout<<puzzle[i][j];
		                    	}
	                     	}
	                    	cout<<endl;
		    			}
                        if(tolower(a)=='d')
		    	    	{
		    		        if(y2!=size-1&&puzzle[x][y2+1]=='-')
		    		        {
		    		        	puzzle[x][y1]='-';
		    		        	puzzle[x][y2+1]='#';
		    		        	y1+=1;
		    		        	y2+=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
                    			for(int j=0;j<size;j++)
	                    		{
	                    			cout<<puzzle[i][j];
		                    	}
                     		}
                    		cout<<endl;
		    	    	}
               }
            }
		if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y2]=='-'&&puzzle[x+1][y1+1]=='-')
        	{
        		for(int j=y1;j<=y2;j++)
        		{
        			puzzle[x][j]='-';
        			puzzle[x+1][j]='#';
				}
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
        if(next_block2==10)
    	{
    		int y,x1,x2;
    		char block[3][1];
    	    for(int i=0;i<3;i++)
    	    {
     		    for(int j=0;j<1;j++)
      		    {
			    block[i][j]='#';
    		    }
    	    }
	        for(int i=0;i<1;i++)
     	    {
     		    cout<<block[0][i];
     	    }
       	    cout<<endl;
     	    for(int i=1;i<3;i++)
     	    {
    	    	for(int j=0;j<1;j++)
    	    	{
    	    		cout<<block[i][j];
    			}
     			cout<<endl;
    		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl;
    	}
    	int x=rand();
    	int z=x%8;
    	if(z==1)
    	{	
    	    next_block2=5;
    	    char next_block[2][2];
	        next_block[0][0]='-';
	        next_block[0][1]='#';
	        next_block[1][0]='#';
	        next_block[1][1]='#';
	        for(int j=0;j<2;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<2;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(z==2)
			{
				next_block2=6;
				char next_block[2][2];
	            next_block[0][0]='#';
	            next_block[0][1]='-';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
	            for(int j=0;j<2;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=0;j<2;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(z==3)
				{
					next_block2=7;
					char next_block[2][2];
	                next_block[0][0]='#';
	                next_block[0][1]='#';
	                next_block[1][0]='-';
	                next_block[1][1]='#';
	                for(int j=0;j<1;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<2;i++)
	                {
		                for(int j=0;j<1;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(z==4)
				   {
					    next_block2=8;
					    char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='#';
	                    next_block[1][1]='-';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(z==5)
				        {
					        next_block2=9;
					        char next_block[1][3];
	                        for(int i=0;i<1;i++)
                    	    {
		                        for(int j=0;j<3;j++)
		                        {
			                        next_block[i][j]='#';
		                        }
	                        }
	                        for(int i=0;i<1;i++)
	                        {
	                        	for(int j=0;j<3;j++)
	                        	{
	                        		cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(z==6)
				            {
					            next_block2=10;
					            char next_block[3][1];
	                            for(int i=0;i<3;i++)
	                            {
		                            for(int j=0;j<1;j++)
	                            	{
			                            next_block[i][j]='#';
		                            }
                            	}
	                            for(int j=0;j<1;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<3;i++)
	                            {
		                            for(int j=0;j<1;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(z==7)
				                {
					                next_block2=11;
					                char next_block[1][4];
	                                for(int i=0;i<1;i++)
	                                {
		                                for(int j=0;j<4;j++)
		                                {
			                                next_block[i][j]='#';
		                                }
	                                }
	                                for(int j=0;j<4;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
			    	            }
			    	            else
				                {
					                next_block2=12;
					                char next_block[4][1];
	                                for(int i=0;i<4;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
	                                }					            
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<4;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
			puzzle[0][3]=block[0][0];
			puzzle[1][3]=block[1][0];
			puzzle[2][3]=block[2][0];
			y=3;
			x1=0;
			x2=2;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
		    while(tolower(a)!='s')
	    	{
    	        cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
    	    	}
    	    	else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	        		}
	    	    	else
		    	    	if(tolower(a)=='a')
		    	        {
		    	    	    if(y!=0&&puzzle[x1][y-1]=='-'&&puzzle[x1+1][y-1]=='-'&&puzzle[x2][y-1]=='-')
		    		        {
		    		        	for(int i=x1;i<=x2;i++)
		    		        	{
		    		    	    	puzzle[i][y-1]='#';
		    		    	    	puzzle[i][y]='-';
						    	}
						    	y-=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
                    			for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                    		}
		    		 	}
                        if(tolower(a)=='d')
		    		    {
		    		        if(y!=size-1&&puzzle[x1][y+1]=='-'&&puzzle[x1+1][y+1]=='-'&&puzzle[x2][y+1]=='-')
		    		        {
		    		        	for(int i=x1;i<=x2;i++)
		    		        	{
		    		        		puzzle[i][y]='-';
		    		        		puzzle[i][y+1]='#';
						    	}
						    	y+=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
                    			for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                     			}
                    			cout<<endl;
                       		}
		    	    	}
                }
            }
		if(tolower(a)=='s')
        {
        	while(x2!=size-1&&puzzle[x2+1][y]=='-')
        	{
        		puzzle[x1][y]='-';
        		puzzle[x2+1][y]='+';
        		x1+=1;
        		x2+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
	if(next_block2==11)
	{
		int y1,y2,x;
		char block[1][4];
	    for(int i=0;i<1;i++)
	    {
		    for(int j=0;j<4;j++)
		    {
			    block[i][j]='#';
		    }
        }
	    for(int i=0;i<4;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%8;
    	if(y==1)
    	{	
    	    next_block2=5;
    	    char next_block[2][2];
	        next_block[0][0]='-';
	        next_block[0][1]='#';
	        next_block[1][0]='#';
	        next_block[1][1]='#';
	        for(int j=0;j<2;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<2;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=6;
				char next_block[2][2];
	            next_block[0][0]='#';
	            next_block[0][1]='-';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
	            for(int j=0;j<2;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=0;j<2;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=7;
					char next_block[2][2];
	                next_block[0][0]='#';
	                next_block[0][1]='#';
	                next_block[1][0]='-';
	                next_block[1][1]='#';
	                for(int j=0;j<1;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<2;i++)
	                {
		                for(int j=0;j<1;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=8;
					    char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='#';
	                    next_block[1][1]='-';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=9;
					        char next_block[1][3];
	                        for(int i=0;i<1;i++)
                    	    {
		                        for(int j=0;j<3;j++)
		                        {
			                        next_block[i][j]='#';
		                        }
	                        }
	                        for(int i=0;i<1;i++)
	                        {
	                        	for(int j=0;j<3;j++)
	                        	{
	                        		cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=10;
					            char next_block[3][1];
	                            for(int i=0;i<3;i++)
	                            {
		                            for(int j=0;j<1;j++)
	                            	{
			                            next_block[i][j]='#';
		                            }
                            	}
	                            for(int j=0;j<1;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<3;i++)
	                            {
		                            for(int j=0;j<1;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=11;
					                char next_block[1][4];
	                                for(int i=0;i<1;i++)
	                                {
		                                for(int j=0;j<4;j++)
		                                {
			                                next_block[i][j]='#';
		                                }
	                                }
	                                for(int j=0;j<4;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
			    	            }
			    	            else
				                {
					                next_block2=12;
					                char next_block[4][1];
	                                for(int i=0;i<4;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
	                                }					            
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<4;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[0][4]=='#'||puzzle[0][5]=='#'||puzzle[0][6]=='#')
    	{
    		return;
		}
		else
		{
			puzzle[0][3]=block[0][0];
			puzzle[0][4]=block[0][1];
			puzzle[0][5]=block[0][2];
			puzzle[0][6]=block[0][3];
			y1=3;
			y2=6;
			x=0;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
		    while(tolower(a)!='s')
		    {
    	       cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
        		}
    	    	else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	    	    	}
	    		    else
		    	    	if(tolower(a)=='a')
		    	        {
		    		        if(y1!=0&&puzzle[x][y1-1]=='-')
		    		        {
		    		        	puzzle[x][y1-1]='#';
		    		        	puzzle[x][y2]='-';
						    	y1-=1;
						    	y2-=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
		                    	{
	                    			cout<<puzzle[i][j];
	                      		}
		                    	cout<<endl;
	                    	}
		    			}
                        if(tolower(a)=='d')
		    	    	{
		    		        if(y2!=size-1&&puzzle[x][y2+1]=='-')
		    		        {
		    		        	puzzle[x][y1]='-';
		    		        	puzzle[x][y2+1]='#';
						    	y1+=1;
						    	y2+=1;
						    }
						    for(int i=0;i<size;i++)
                    		{
                    			for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                     		}
                        }
                }
		    }
		if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y1+1]=='-'&&puzzle[x+1][y1+2]=='-'&&puzzle[x+1][y2]=='-')
        	{
        		for(int i=y1;i<=y2;i++)
        		{
        			puzzle[x][i]='-';
        			puzzle[x+1][i]='#';
				}
				x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==12)
	{
		int y,x1,x2;
		char block[4][1];
	    for(int i=0;i<4;i++)
	    {
		    for(int j=0;j<1;j++)
		    {
			    block[i][j]='#';
		    }
	    }
	    for(int i=0;i<1;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<4;i++)
	    {
	    	for(int j=0;j<1;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int x=rand();
    	int z=x%8;
    	if(z==1)
    	{	
    	    next_block2=5;
    	    char next_block[2][2];
	        next_block[0][0]='-';
	        next_block[0][1]='#';
	        next_block[1][0]='#';
	        next_block[1][1]='#';
	        for(int j=0;j<2;j++)
	        {
	        	cout<<next_block[0][j];
			}
			for(int j=0;j<2;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(z==2)
			{
				next_block2=6;
				char next_block[2][2];
	            next_block[0][0]='#';
	            next_block[0][1]='-';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
	            for(int j=0;j<2;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    for(int j=0;j<2;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(z==3)
				{
					next_block2=7;
					char next_block[2][2];
	                next_block[0][0]='#';
	                next_block[0][1]='#';
	                next_block[1][0]='-';
	                next_block[1][1]='#';
	                for(int j=0;j<1;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<2;i++)
	                {
		                for(int j=0;j<1;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(z==4)
				   {
					    next_block2=8;
					    char next_block[2][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='#';
	                    next_block[1][0]='#';
	                    next_block[1][1]='-';
	                    for(int j=0;j<1;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<2;i++)
	                    {
		                    for(int j=0;j<1;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(z==5)
				        {
					        next_block2=9;
					        char next_block[1][3];
	                        for(int i=0;i<1;i++)
                    	    {
		                        for(int j=0;j<3;j++)
		                        {
			                        next_block[i][j]='#';
		                        }
	                        }
	                        for(int i=0;i<1;i++)
	                        {
	                        	for(int j=0;j<3;j++)
	                        	{
	                        		cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(z==6)
				            {
					            next_block2=10;
					            char next_block[3][1];
	                            for(int i=0;i<3;i++)
	                            {
		                            for(int j=0;j<1;j++)
	                            	{
			                            next_block[i][j]='#';
		                            }
                            	}
	                            for(int j=0;j<1;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<3;i++)
	                            {
		                            for(int j=0;j<1;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(z==7)
				                {
					                next_block2=11;
					                char next_block[1][4];
	                                for(int i=0;i<1;i++)
	                                {
		                                for(int j=0;j<4;j++)
		                                {
			                                next_block[i][j]='#';
		                                }
	                                }
	                                for(int j=0;j<4;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
			    	            }
			    	            else
				                {
					                next_block2=12;
					                char next_block[4][1];
	                                for(int i=0;i<4;i++)
	                                {
		                                for(int j=0;j<1;j++)
	                                	{
			                                next_block[i][j]='#';
		                                }
	                                }					            
	                                for(int j=0;j<1;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<4;i++)
	                                {
		                                for(int j=0;j<1;j++)
		                                {
			                                cout<<next_block[i][j];
		                                }
		                                cout<<endl;
	                                }
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
			puzzle[0][3]=block[0][0];
			puzzle[1][3]=block[1][0];
			puzzle[2][3]=block[2][0];
			puzzle[3][3]=block[3][0];
			y=3;
			x1=0;
			x2=3;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
		    while(tolower(a)!='s')
		    {
    	        cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
    	    	}
    	    	else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	    	    	}
	    	    	else
		    		    if(tolower(a)=='a')
		    	        {
		    		        if(y!=0&&puzzle[x1][y-1]=='-'&&puzzle[x1+1][y-1]=='-'&&puzzle[x1+2][y-1]=='-'&&puzzle[x2][y-1]=='-')
		    		        {
		    		        	for(int i=x1;i<=x2;i++)
		    		        	{
		    		        		puzzle[i][y-1]='#';
		    		        		puzzle[i][y]='-';
						    	}
							    y-=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
	                    		{
	                    			cout<<puzzle[i][j];
		                    	}
	                    		cout<<endl;
                    		}
		    			}
                        if(tolower(a)=='d')
		    		    {
		    		        if(y!=size-1&&puzzle[x1][y+1]=='-'&&puzzle[x1+1][y+1]=='-'&&puzzle[x1+2][y+1]=='-'&&puzzle[x2][y+1]=='-')
		    		        {
		    		        	for(int i=x1;i<=x2;i++)
		    		        	{
		    		    	    	puzzle[i][y]='-';
		    		    	    	puzzle[i][y+1]='#';
						    	}
							   y+=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
								{
		                    		cout<<puzzle[i][j];
		                    	}
		                    	cout<<endl;
	                    	}
		            	}
                }
            }
		if(tolower(a)=='s')
        {
        	while(x2!=size-1&&puzzle[x2+1][y]=='-')
        	{
        		puzzle[x1][y]='-';
        		puzzle[x2+1][y]='+';
        		x1+=1;
        		x2+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==13)
	{
		int y1,y2,x;
	    char block[2][3];
	    block[0][0]='#';
	    block[0][1]='#';
	    block[0][2]=' ';
	    block[1][0]=' ';
	    block[1][1]='#';
	    block[1][2]='#';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
				    next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
		    puzzle[0][3]=block[0][0];
	        puzzle[0][4]=block[0][1];
	        puzzle[1][4]=block[1][1];
	        puzzle[1][5]=block[1][2];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
		    while(tolower(a)!='s')
		    {
    	        cin>>a;
    	    	if(a=='2')
    	    	{
    		    	hint();
    		    }
    		    else
    		    {
		        	if(a=='3')
		        	{
		        		return;
	    	    	}
	    		    else
		    	    	if(tolower(a)=='a')
		    	        {
		    		        if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1]=='-')
		    		        {
					    		puzzle[x-1][y1-1]='#';
					    		puzzle[x][y1]='#';
					    		puzzle[x-1][y1+1]='-';
					    		puzzle[x][y2]='-';
					    		y1-=1;
					    		y2-=1;
					    	}
					        for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                     			}
                    			cout<<endl;
                      		}
		                }
                        if(tolower(a)=='d')
		    		    {
		    		      if(y2!=size-1&&puzzle[x-1][y2]=='-'&&puzzle[x][y2+1]=='-')
		    		      {
		    		        	puzzle[x-1][y2]='#';
						    	puzzle[x][y2+1]='#';
						    	puzzle[x-1][y1]='-';
						    	puzzle[x][y1+1]='-';
						    	y1+=1;
						    	y2+=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
	                    		{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                     		}
		    	    	}
                }
           }
		if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1+1]=='-'&&puzzle[x+1][y2]=='-')
        	{
        		puzzle[x][y1]='#';
        		puzzle[x+1][y1+1]='#';
        		puzzle[x+1][y2]='#';
        		puzzle[x-1][y1]='-';
        		puzzle[x-1][y1+1]='-';
        		puzzle[x][y2]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==14)
	{
		int y1,y2,x;	
		char block[2][3];
    	block[0][0]=' ';
	    block[0][1]='#';
	    block[0][2]='#';
	    block[1][0]='#';
	    block[1][1]='#';
	    block[1][2]=' ';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}

	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
		    puzzle[0][4]=block[0][1];
	        puzzle[0][5]=block[0][2];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
		    while(tolower(a)!='s')
		    {
    	        cin>>a;
    	    	if(a=='2')
    	    	{
    	    	    hint();
    	    	}
    	    	else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	        		}
	    		    else
		    		    if(tolower(a)=='a')
		    	        {
		    		        if(y1!=0&&puzzle[x-1][y1]=='-'&&puzzle[x][y1-1]=='-')
		    		        {
						    	puzzle[x][y1-1]='#';
						    	puzzle[x-1][y1]='#';
						    	puzzle[x-1][y2]='-';
						    	puzzle[x][y2-1]='-';
						    	y1-=1;
						    	y2-=1;
						   }
						   	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
	                    		{
	                     			cout<<puzzle[i][j];
	                    		}
		                    	cout<<endl;
                     		}
		    			}
                       if(tolower(a)=='d')
		    		   {
		    		        if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2]=='-')
		    		        {
		    		        	puzzle[x-1][y2+1]='#';
						    	puzzle[x][y2]='#';
						    	puzzle[x-1][y1+1]='-';
						    	puzzle[x][y1]='-';
						    	y1+=1;
						    	y2+=1;
					    	}
					    	for(int i=0;i<size;i++)
		                    {
	                    		for(int j=0;j<size;j++)
	                    		{
	                    			cout<<puzzle[i][j];
	                    		}
	                    		cout<<endl;
	                    	}
		    		   }
	    	    }
    	    }
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y1+1]=='-'&&puzzle[x][y2]=='-')
        	{
        		puzzle[x][y2]='#';
        		puzzle[x+1][y1+1]='#';
        		puzzle[x+1][y1]='#';
        		puzzle[x-1][y2]='-';
        		puzzle[x-1][y1+1]='-';
        		puzzle[x][y1]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
	}
    if(next_block2==15)
	{
		int y1,y2,x;	
		char block[3][2];
    	block[0][0]='#';
        block[0][1]='-';
    	block[1][0]='#';
    	block[1][1]='#';
    	block[2][0]='-';
        block[2][1]='#';
	    for(int i=0;i<2;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<3;i++)
	    {
	    	for(int j=0;j<2;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
		    puzzle[0][3]=block[0][0];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
	        puzzle[2][4]=block[2][1];
			y1=3;
			y2=4;
			x=2;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
		    while(tolower(a)!='s')
		    {
    	      cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
    	    	}
    		    else
    		    {
		        	if(a=='3')
		        	{
		        		return;
	    	    	}
	    	    	else
		    	    	if(tolower(a)=='a')
		    	        {
		    		        if(y1!=0&&puzzle[x-2][y1-1]=='-'&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1]=='-')
		    		        {
		    		        	puzzle[x-2][y1-1]='#';
					    		puzzle[x-1][y1-1]='#';
					    		puzzle[x][y1]='#';
					    		puzzle[x-2][y1]='-';
					    		puzzle[x-1][y2]='-';
					    		puzzle[x][y2]='-';
						    	y1-=1;
						    	y2-=1;
					    	}
					        for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                    		}
		    			}
                        if(tolower(a)=='d')
		    		    {
		    		        if(y2!=size-1&&puzzle[x-2][y2]=='-'&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2+1]=='-')
		    		        {
		    		        	puzzle[x-2][y2]='#';
						    	puzzle[x-1][y2+1]='#';
						    	puzzle[x][y2+1]='#';
						    	puzzle[x-2][y1]='-';
						    	puzzle[x-1][y1]='-';
						    	puzzle[x][y2]='-';
						    	y1+=1;
						    	y2+=1;
						    }
						    for(int i=0;i<size;i++)
		                    {
	                    		for(int j=0;j<size;j++)
	                    		{
	                    			cout<<puzzle[i][j];
	                    		}
	                    		cout<<endl;
	                    	}
		    	    	}
	    	    }
    	    }
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y2]=='-'&&puzzle[x+1][y1]=='-')
        	{
        		puzzle[x+1][y2]='#';
				puzzle[x+1][y1]='#';
				puzzle[x-2][y1]='-';
				puzzle[x-1][y2]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
	}
    if(next_block2==16)
	{
		int y1,y2,x;	
		char block[3][2];
	    block[0][0]='-';
	    block[0][1]='#';
	    block[1][0]='#';
	    block[1][1]='#';
	    block[2][0]='#';
    	block[2][1]='-';
	    for(int i=0;i<2;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<3;i++)
	    {
	    	for(int j=0;j<2;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
		    puzzle[0][4]=block[0][1];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
	        puzzle[2][3]=block[2][0];
			y1=3;
			y2=4;
			x=2;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
		    while(tolower(a)!='s')
	    	{
    	        cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
    	    	}
    		    else
    		    {
		        	if(a=='3')
		        	{
		        		return;
	    	    	}
	    	    	else
		    	    	if(tolower(a)=='a')
		    	        {
		    		        if(y1!=0&&puzzle[x-2][y1]=='-'&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1-1]=='-')
		    		        {
		    		        	puzzle[x-2][y1]='#';
						    	puzzle[x-1][y1-1]='#';
						    	puzzle[x][y1-1]='#';
						    	puzzle[x-2][y2]='-';
						    	puzzle[x-1][y2]='-';
						    	puzzle[x][y1]='-';
						    	y1-=1;
						    	y2-=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                    		}
		    			}
                        if(tolower(a)=='d')
		    		    {
		    		        if(y2!=size-1&&puzzle[x-2][y2+1]=='-'&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2]=='-')
		    		        {
		    		        	puzzle[x-2][y2+1]='#';
						    	puzzle[x-1][y2+1]='#';
						    	puzzle[x][y2]='#';
						    	puzzle[x-2][y2]='-';
						    	puzzle[x-1][y1]='-';
						    	puzzle[x][y1]='-';
						    	y1+=1;
						    	y2+=1;
						   }
						   	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                    			}
                     			cout<<endl;
                    		}
		    		    }
                }
            }
		if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x][y2]=='-'&&puzzle[x+1][y1]=='-')
        	{
        		puzzle[x+1][y1]='#';
				puzzle[x][y2]='#';
				puzzle[x-2][y2]='-';
				puzzle[x-1][y1]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}	
	}
    if(next_block2==17)
	{
		int y1,y2,x;	
		char block[2][3];
	    block[0][0]='#';
	    block[0][1]='#';
	    block[0][2]='#';
	    block[1][0]='-';
	    block[1][1]='#';
	    block[1][2]='-';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[0][4]=='#'||puzzle[0][5]=='#'||puzzle[1][4]=='#')
    	{
    		return;
		}
		else
		{
	        puzzle[0][3]=block[0][0];
	        puzzle[0][4]=block[0][1];
	        puzzle[0][5]=block[0][2];
	        puzzle[1][4]=block[1][1];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		    char a;
	    	while(tolower(a)!='s')
	    	{
    	        cin>>a;
    	    	if(a=='2')
    		    {
    			    hint();
    		    }
    	    	else
    		    {
		        	if(a=='3')
		    	    {
		    	    	return;
	    	    	}
	    		    else
		    	    	if(tolower(a)=='a')
		    	        {
		    	    	    if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1]=='-')
		    	    	    {
					    		puzzle[x-1][y1-1]='#';
						    	puzzle[x][y1]='#';
						    	puzzle[x-1][y2]='-';
						    	puzzle[x][y1+1]='-';
						    	y1-=1;
						    	y2-=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
                    			for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                     		}
		    			}
                        if(tolower(a)=='d')
		    		    {
		    		        if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2]=='-')
		    		        {
						    	puzzle[x-1][y2+1]='#';
						    	puzzle[x][y2]='#';
						    	puzzle[x-1][y1]='-';
						    	puzzle[x][y1+1]='-';
						    	y1+=1;
						    	y2+=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
	                    		{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                    		}
		                }
                }
            }
		if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x][y2]=='-'&&puzzle[x][y1]=='-'&&puzzle[x+1][y1+1]=='-')
        	{
        		puzzle[x][y1]='#';
				puzzle[x][y2]='#';
				puzzle[x+1][y1+1]='#';
				puzzle[x-1][y2]='-';
				puzzle[x-1][y1]='-';
				puzzle[x-1][y1+1]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
	}
    if(next_block2==18)
	{
		int y1,y2,x;	
		char block[2][3];
    	block[0][0]='-';
	    block[0][1]='#';
	    block[0][2]='-';
    	block[1][0]='#';
    	block[1][1]='#';
    	block[1][2]='#';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][4]=='#'||puzzle[1][4]=='#'||puzzle[1][5]=='#'||puzzle[1][3]=='#')
    	{
    		return;
		}
		else
		{
	        puzzle[0][4]=block[0][1];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
	        puzzle[1][5]=block[1][2];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
	    	char a;
		    while(tolower(a)!='s')
	    	{
    	        cin>>a;
    	    	if(a=='2')
    	    	{
    	    		hint();
    	    	}
        		else
    	    	{
		        	if(a=='3')
		        	{
		        		return;
	        		}
	    	    	else
		        		if(tolower(a)=='a')
		        	    {
		    		        if(y1!=0&&puzzle[x-1][y1]=='-'&&puzzle[x][y1-1]=='-')
		    		        {
					    		puzzle[x-1][y1]='#';
					    		puzzle[x][y1-1]='#';
					    		puzzle[x-1][y1+1]='-';
					    		puzzle[x][y2]='-';
					    		y1-=1;
					    		y2-=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
	                    		{
	                    			cout<<puzzle[i][j];
	                    		}
	                    		cout<<endl;
	                    	}
		    		 	}
                        if(tolower(a)=='d')
		    	    	{
		    		        if(y2!=size-1&&puzzle[x-1][y2]=='-'&&puzzle[x][y2+1]=='-')
		    		        {
						    	puzzle[x-1][y2]='#';
						    	puzzle[x][y2+1]='#';
						    	puzzle[x-1][y1+1]='-';
						    	puzzle[x][y1]='-';
						    	y1+=1;
						    	y2+=1;
					    	}
					    	for(int i=0;i<size;i++)
	                    	{
	                    		for(int j=0;j<size;j++)
                    			{
                    				cout<<puzzle[i][j];
                    			}
                    			cout<<endl;
                    		}
		    	    	}
               }
           }
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y1+1]=='-'&&puzzle[x+1][y2]=='-')
        	{
        		puzzle[x+1][y1]='#';
				puzzle[x+1][y2]='#';
				puzzle[x+1][y1+1]='#';
				puzzle[x-1][y1+1]='-';
				puzzle[x][y1]='-';
				puzzle[x][y2]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==19)
	{
		int y1,y2,x;	
		char block[3][2];
	    block[0][0]='-';
	    block[0][1]='#';
	    block[1][0]='#';
	    block[1][1]='#';
	    block[2][0]='-';
    	block[2][1]='#';
	    for(int i=0;i<2;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<3;i++)
	    {
	    	for(int j=0;j<2;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][4]=='#'||puzzle[1][3]=='#'||puzzle[1][4]=='#'||puzzle[2][4]=='#')
    	{
    		return;
		}
		else
		{
	        puzzle[0][4]=block[0][1];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
	        puzzle[2][4]=block[2][1];
			y1=3;
			y2=4;
			x=2;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		char a;
		while(tolower(a)!='s')
		{
    	    cin>>a;
    		if(a=='2')
    		{
    			hint();
    		}
    		else
    		{
		    	if(a=='3')
		    	{
		    		return;
	    		}
	    		else
		    		if(tolower(a)=='a')
		    	    {
		    		    if(y1!=0&&puzzle[x-2][y1]=='-'&&puzzle[x][y1]=='-'&&puzzle[x-1][y1-1]=='-')
		    		    {
							puzzle[x-2][y1]='#';
							puzzle[x][y1]='#';
							puzzle[x-1][y1-1]='#';
							puzzle[x-2][y2]='-';
							puzzle[x-1][y2]='-';
							puzzle[x][y2]='#';
							y1-=1;
							y2-=1;
						}
		    			for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
	                		{
	                			cout<<puzzle[i][j];
                 			}
                  			cout<<endl;
                		}
				   	}
                    if(tolower(a)=='d')
		    		{
		    		    if(y2!=size-1&&puzzle[x-2][y2+1]=='-'&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2+1]=='-')
		    		    {
							puzzle[x-2][y2+1]='#';
							puzzle[x-1][y2+1]='#';
							puzzle[x][y2+1]='#';
							puzzle[x-2][y2]='-';
							puzzle[x-1][y1]='-';
							puzzle[x][y2]='-';
							y1+=1;
							y2+=1;
						}
						for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
                			{
                				cout<<puzzle[i][j];
                			}
                			cout<<endl;
                   		}
		    		}
            }
        }
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y2]=='-'&&puzzle[x][y1]=='-')
        	{
        		puzzle[x+1][y2]='#';
				puzzle[x][y1]='#';
				puzzle[x-2][y2]='-';
				puzzle[x-1][y1]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==20)
	{
		int y1,y2,x;	
		char block[3][2];
	    block[0][0]='#';
    	block[0][1]=' ';
    	block[1][0]='#';
    	block[1][1]='#';
    	block[2][0]='#';
    	block[2][1]=' ';
	    for(int i=0;i<2;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<3;i++)
	    {
	    	for(int j=0;j<2;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[1][4]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
	        puzzle[0][3]=block[0][0];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
	        puzzle[2][3]=block[2][0];
			y1=3;
			y2=4;
			x=2;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		char a;
		while(tolower(a)!='s')
		{
    	    cin>>a;
    		if(a=='2')
    		{
    			hint();
    		}
    		else
    		{
		    	if(a=='3')
		    	{
		    		return;
	    		}
	    		else
		    		if(tolower(a)=='a')
		    	    {
		    		    if(y1!=0&&puzzle[x-2][y1-1]=='-'&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1-1]=='-')
		    		    {
							puzzle[x-2][y1-1]='#';
							puzzle[x][y1-1]='#';
							puzzle[x-1][y1-1]='#';
							puzzle[x-2][y1]='-';
							puzzle[x-1][y2]='-';
							puzzle[x][y1]='-';
							y1-=1;
							y2-=1;
						}
						for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
	                		{
	                			cout<<puzzle[i][j];
                			}
	                		cout<<endl;
                		}
		    			
				   	}
                    if(tolower(a)=='d')
		    		{
		    		    if(y2!=size-1&&puzzle[x-2][y2]=='-'&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2]=='-')
		    		    {
							puzzle[x-2][y2]='#';
							puzzle[x-1][y2+1]='#';
							puzzle[x][y2]='#';
							puzzle[x-2][y1]='-';
							puzzle[x-1][y1]='-';
							puzzle[x][y1]='-';
							y1+=1;
							y2+=1;
						}
						for(int i=0;i<size;i++)
	                	{
                			for(int j=0;j<size;j++)
                			{
                				cout<<puzzle[i][j];
                			}
                			cout<<endl;
                		}
		    		}
	    	}
    	}
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x][y2]=='-')
        	{
        		puzzle[x+1][y1]='#';
				puzzle[x][y2]='#';
				puzzle[x-2][y1]='-';
				puzzle[x-1][y2]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==21)
	{
		int y1,y2,x;	
		char block[2][3];
	    block[0][0]='#';
	    block[0][1]='#';
	    block[0][2]='#';
    	block[1][0]='#';
	    block[1][1]='-';
    	block[1][2]='-';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[0][4]=='#'||puzzle[0][5]=='#')
    	{
    		return;
		}
		else
		{
	        puzzle[0][3]=block[0][0];
	        puzzle[0][4]=block[0][1];
	        puzzle[0][5]=block[0][2];
	        puzzle[1][3]=block[1][0];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		char a;
		while(tolower(a)!='s')
		{
    	     cin>>a;
    		if(a=='2')
    		{
    			hint();
    		}
    		else
    		{
		    	if(a=='3')
		    	{
		    		return;
	    		}
	    		else
		    		if(tolower(a)=='a')
		    	    {
		    		    if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1-1]=='-')
		    		    {
							puzzle[x-1][y1-1]='#';
							puzzle[x][y1-1]='#';
							puzzle[x-1][y2]='-';
							puzzle[x][y1]='-';
							y1-=1;
							y2-=1;
						}
		    			for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
	                		{
	                			cout<<puzzle[i][j];
	                		}
	                		cout<<endl;
	                	}
				   	}
                    if(tolower(a)=='d')
		    		{
		    		    if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y1+1]=='-')
		    		    {
							puzzle[x-1][y2+1]='#';
							puzzle[x][y1+1]='#';
							puzzle[x-1][y1]='-';
							puzzle[x][y1]='-';
							y1+=1;
							y2+=1;
						}
						for(int i=0;i<size;i++)
                		{
                			for(int j=0;j<size;j++)
                			{
                				cout<<puzzle[i][j];
                			}
                			cout<<endl;
                 		}
		    		}
            }
     }
		if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x][y2]=='-'&&puzzle[x][y1+1]=='-')
        	{
        		puzzle[x+1][y1]='#';
				puzzle[x][y2]='#';
				puzzle[x][y1+1]='#';
				puzzle[x-1][y1]='-';
				puzzle[x-1][y2]='-';
				puzzle[x-1][y1+1]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==22)
	{
		int y1,y2,x;	
		char block[2][3];
    	block[0][0]='#';
    	block[0][1]='-';
    	block[0][2]='-';
    	block[1][0]='#';
    	block[1][1]='#';
    	block[1][2]='#';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[1][3]=='#'||puzzle[1][4]=='#'||puzzle[2][3]=='#')
    	{
    		return;
		}
		else
		{
	        puzzle[0][3]=block[0][0];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
	        puzzle[1][5]=block[1][2];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		char a;
		while(tolower(a)!='s')
		{
    	    cin>>a;
    		if(a=='2')
    		{
    			hint();
    		}
    		else
    		{
		    	if(a=='3')
		    	{
		    		return;
	    		}
	    		else
		    		if(tolower(a)=='a')
		    	    {
		    		    if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1-1]=='-')
		    		    {
							puzzle[x][y1-1]='#';
							puzzle[x-1][y1-1]='#';
							puzzle[x-1][y1]='-';
							puzzle[x][y2]='-';
							y1-=1;
							y2-=1;
						}
		    			for(int i=0;i<size;i++)
	                	{
                			for(int j=0;j<size;j++)
                			{
                				cout<<puzzle[i][j];
                  			}
                			cout<<endl;
                		}
				   	}
                    if(tolower(a)=='d')
		    		{
		    		    if(y2!=size-1&&puzzle[x-1][y1+1]=='-'&&puzzle[x][y2+1]=='-')
		    		    {
							puzzle[x-1][y1+1]='#';
							puzzle[x][y2+1]='#';
							puzzle[x-1][y1]='-';
							puzzle[x][y1]='-';
							y1+=1;
							y2+=1;
						}
						for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
	                		{
                				cout<<puzzle[i][j];
	                		}
	                		cout<<endl;
                   		}
		    		}
        }
    }
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y1+1]=='-'&&puzzle[x+1][y2]=='-')
        	{
        		puzzle[x+1][y1]='#';
				puzzle[x+1][y2]='#';
				puzzle[x+1][y1+1]='#';
				puzzle[x-1][y1]='-';
				puzzle[x][y1+1]='-';
				puzzle[x][y2]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==23)
	{
		int y1,y2,x;	
		char block[2][3];
	    block[0][0]='#';
	    block[0][1]='#';
	    block[0][2]='#';
    	block[1][0]='-';
    	block[1][1]='-';
    	block[1][2]='#';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][3]=='#'||puzzle[0][4]=='#'||puzzle[0][5]=='#'||puzzle[1][5]=='#')
    	{
    		return;
		}
		else
		{
	        puzzle[0][3]=block[0][0];
	        puzzle[0][4]=block[0][1];
	        puzzle[0][5]=block[0][2];
	        puzzle[1][5]=block[1][2];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		char a;
		while(tolower(a)!='s')
		{
    	    cin>>a;
    		if(a=='2')
    		{
    			hint();
    		}
    		else
    		{
		    	if(a=='3')
		    	{
		    		return;
	    		}
	    		else
		    		if(tolower(a)=='a')
		    	    {
		    		    if(y1!=0&&puzzle[x-1][y1-1]=='-'&&puzzle[x][y1+1]=='-')
		    		    {
							puzzle[x-1][y1-1]='#';
							puzzle[x][y1+1]='#';
							puzzle[x-1][y2]='-';
							puzzle[x][y2]='-';
							y1-=1;
							y2-=1;
						}
		    			for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
                			{
                				cout<<puzzle[i][j];
                			}
                			cout<<endl;
                		}
				   	}
                    if(tolower(a)=='d')
		    		{
		    		    if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2+1]=='-')
		    		    {
							puzzle[x-1][y2+1]='#';
							puzzle[x][y2+1]='#';
							puzzle[x-1][y1]='-';
							puzzle[x][y2]='-';
							y1+=1;
							y2+=1;
						}
						for(int i=0;i<size;i++)
                		{
                			for(int j=0;j<size;j++)
                			{
                				cout<<puzzle[i][j];
                 			}
                 			cout<<endl;
                		}
		    		}
        }
    }
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y2]=='-'&&puzzle[x][y1]=='-'&&puzzle[x][y1+1]=='-')
        	{
        		puzzle[x+1][y2]='#';
				puzzle[x][y1]='#';
				puzzle[x][y1+1]='#';
				puzzle[x-1][y1]='-';
				puzzle[x-1][y1+1]='-';
				puzzle[x-1][y2]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
    if(next_block2==24)
	{
		int y1,y2,x;	
		char block[2][3];
	    block[0][0]='-';
    	block[0][1]='-';
    	block[0][2]='#';
    	block[1][0]='#';
    	block[1][1]='#';
    	block[1][2]='#';
	    for(int i=0;i<3;i++)
	    {
		    cout<<block[0][i];
	    }
	    cout<<endl;
	    for(int i=1;i<2;i++)
	    {
	    	for(int j=0;j<3;j++)
	    	{
	    		cout<<block[i][j];
			}
			cout<<endl;
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<size;j++)
    		{
    			cout<<puzzle[i][j];
    		}
    		cout<<endl<<endl;
    	}
    	int z=rand();
    	int y=z%12;
    	if(y==1)
    	{	
    	    next_block2=13;
	        char next_block[2][3];
	        next_block[0][0]='#';
	        next_block[0][1]='#';
	        next_block[0][2]=' ';
	        next_block[1][0]=' ';
	        next_block[1][1]='#';
	        next_block[1][2]='#';
	        for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[0][j];
			}
			cout<<endl;
			for(int j=0;j<3;j++)
	        {
	        	cout<<next_block[1][j];
			}
			cout<<endl;
		}
		else
		{
			if(y==2)
			{
				next_block2=14;
	            char next_block[2][3];
	            next_block[0][0]=' ';
	            next_block[0][1]='#';
	            next_block[0][2]='#';
	            next_block[1][0]='#';
	            next_block[1][1]='#';
            	next_block[1][2]=' ';
	            for(int j=0;j<3;j++)
	            {
	        	    cout<<next_block[0][j];
			    }
			    cout<<endl;
			    for(int j=1;j<3;j++)
	            {
	        	    cout<<next_block[1][j];
			    }
			    cout<<endl;
			}
			else
			{
				if(y==3)
				{
					next_block2=15;
					char next_block[3][2];
                	next_block[0][0]='#';
                	next_block[0][1]=' ';
                	next_block[1][0]='#';
                	next_block[1][1]='#';
                	next_block[2][0]=' ';
                   	next_block[2][1]='#';
	                for(int j=0;j<2;j++)
	                {
		                cout<<next_block[0][j];
	                }
	                cout<<endl;
	                for(int i=1;i<3;i++)
	                {
		                for(int j=0;j<2;j++)
		                {
			                cout<<next_block[i][j];
		                }
		                cout<<endl;
	                }
				}
				else
				{
				   if(y==4)
				   {
					    next_block2=16;
					    char next_block[3][2];
	                    next_block[0][0]='#';
	                    next_block[0][1]='-';
                    	next_block[1][0]='#';
	                    next_block[1][1]='#';
	                    next_block[2][0]='-';
                     	next_block[2][1]='#';
	                    for(int j=0;j<2;j++)
	                    {
		                    cout<<next_block[0][j];
	                    }
	                    cout<<endl;
	                    for(int i=1;i<3;i++)
	                    {
		                    for(int j=0;j<2;j++)
		                    {
			                    cout<<next_block[i][j];
		                    }
		                    cout<<endl;
	                    }
			    	}
			    	else
			    	{
			    		if(y==5)
				        {
					        next_block2=17;
					        char next_block[2][3];
                        	next_block[0][0]='#';
                        	next_block[0][1]='#';
                        	next_block[0][2]='#';
                        	next_block[1][0]='-';
                        	next_block[1][1]='#';
                        	next_block[1][2]='-';
                        	for(int j=0;j<3;j++)
                        	{
                        		cout<<next_block[0][j];
							}
							cout<<endl;
							for(int i=1;i<2;i++)
							{
								for(int j=0;j<3;j++)
								{
									cout<<next_block[i][j];
								}
								cout<<endl;
							}
			    	    }
			    	    else
			    	    {
			    	    	if(y==6)
				            {
					            next_block2=18;
					            char next_block[2][3];
                            	next_block[0][0]=' ';
                            	next_block[0][1]='#';
                            	next_block[0][2]=' ';
                            	next_block[1][0]='#';
                            	next_block[1][1]='#';
                            	next_block[1][2]='#';
	                            for(int j=0;j<3;j++)
	                            {
		                            cout<<next_block[0][j];
	                            }
	                            cout<<endl;
	                            for(int i=1;i<2;i++)
	                            {
		                            for(int j=0;j<3;j++)
		                            {
			                            cout<<next_block[i][j];
		                            }
		                            cout<<endl;
	                            }
			    	        }
			    	        else
			    	        {
			    	        	if(y==7)
				                {
					                next_block2=19;
					                char next_block[3][2];
                                	next_block[0][0]='-';
                                	next_block[0][1]='#';
                                	next_block[1][0]='#';
                                	next_block[1][1]='#';
                                	next_block[2][0]='-';
                                 	next_block[2][1]='#';
	                                for(int j=0;j<2;j++)
	                                {
		                                cout<<next_block[0][j];
	                                }
	                                cout<<endl;
	                                for(int i=1;i<3;i++)
	                                {
	                                	for(int j=0;j<2;j++)
	                                	{
	                                		cout<<next_block[i][j];								
										}
										cout<<endl;
									}
			    	            }
			    	            else
				                {
									if(y==8)
				                    {
					                    next_block2=20;
					                    char next_block[3][2];
	                                    next_block[0][0]='#';
	                                    next_block[0][1]=' ';
	                                    next_block[1][0]='#';
	                                    next_block[1][1]='#';
                                    	next_block[2][0]='#';
                                    	next_block[2][1]=' ';
	                                    for(int j=0;j<2;j++)
	                                    {
		                                    cout<<next_block[0][j];
	                                    }
	                                    cout<<endl;
	                                    for(int i=1;i<3;i++)
	                                    {
	                                	    for(int j=0;j<2;j++)
	                                	    {
	                                		    cout<<next_block[i][j];								
										    }
										    cout<<endl;
									    }
			    	                }
			    	                else
			    	                {
			    	                	if(y==9)
				                        {
					                        next_block2=21;
					                        char next_block[2][3];
	                                        next_block[0][0]='#';
	                                        next_block[0][1]='#';
                                    	    next_block[0][2]='#';
                                        	next_block[1][0]='#';
                                        	next_block[1][1]='-';
                                        	next_block[1][2]='-';
	                                        for(int j=0;j<3;j++)
	                                        {
		                                        cout<<next_block[0][j];
	                                        }
	                                        cout<<endl;
	                                        for(int i=1;i<2;i++)
	                                        {
	                                	        for(int j=0;j<3;j++)
	                                	        {
	                                		        cout<<next_block[i][j];								
										        }
										        cout<<endl;
									        }
			    	                    }
			    	                    else
			    	                    {
			    	                    	if(y==10)
				                            {
					                            next_block2=22;
					                            char next_block[2][3];
	                                            next_block[0][0]='#';
	                                            next_block[0][1]='-';
	                                            next_block[0][2]='-';
	                                            next_block[1][0]='#';
                                            	next_block[1][1]='#';
                                            	next_block[1][2]='#';
	                                            for(int j=0;j<3;j++)
	                                            {
		                                            cout<<next_block[0][j];
	                                            }
	                                            cout<<endl;
	                                            for(int i=1;i<2;i++)
	                                            {
	                                	            for(int j=0;j<3;j++)
	                                	            {
	                                		            cout<<next_block[i][j];								
										            }
										            cout<<endl;
									            }
			    	                        }
			    	                        else
			    	                        {
			    	                        	if(y==11)
				                                {
					                                next_block2=23;
					                                char next_block[2][3];
	                                                next_block[0][0]='#';
	                                                next_block[0][1]='#';
	                                                next_block[0][2]='#';
	                                                next_block[1][0]='-';
                                                	next_block[1][1]='-';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
			    	                            }
			    	                            else
			    	                            {
			    	                            	next_block2=24;
			    	                            	char next_block[2][3];
                                                	next_block[0][0]='-';
                                                	next_block[0][1]='-';
                                                	next_block[0][2]='#';
                                                	next_block[1][0]='#';
                                                	next_block[1][1]='#';
                                                	next_block[1][2]='#';
	                                                for(int j=0;j<3;j++)
	                                                {
		                                                cout<<next_block[0][j];
	                                                }
	                                                cout<<endl;
	                                                for(int i=1;i<2;i++)
	                                                {
	                                	                for(int j=0;j<3;j++)
	                                	                {
	                                		                cout<<next_block[i][j];								
										                }
										                cout<<endl;
									                }
												}
											}
										}
									}
			    	            }
							}
						}
					}
				}
			}
		}
	    cout<<"* Retry(1)   *"<<endl;
	    cout<<"* Hint (2)   *"<<endl;
	    cout<<"* Exit (3)   *"<<endl;
    	cout<<"HIGH SCORE: "<<game.high_score<<endl;
    	cout<<"SCORE: "<<game.score<<endl;
    	if(puzzle[0][5]=='#'||puzzle[1][3]=='#'||puzzle[1][4]=='#'||puzzle[1][5]=='#')
    	{
    		return ;
		}
		else
		{
	        puzzle[0][5]=block[0][2];
	        puzzle[1][3]=block[1][0];
	        puzzle[1][4]=block[1][1];
	        puzzle[1][5]=block[1][2];
			y1=3;
			y2=5;
			x=1;
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		char a;
		while(tolower(a)!='s')
		{
    	    cin>>a;
    		if(a=='2')
    		{
    			hint();
    		}
    		else
    		{
		    	if(a=='3')
		    	{
		    		return;
	    		}
	    		else
		    		if(tolower(a)=='a')
		    	    {
		    		    if(y1!=0&&puzzle[x-1][y1+1]=='-'&&puzzle[x][y1-1]=='-')
		    		    {
							puzzle[x-1][y1+1]='#';
							puzzle[x][y1-1]='#';
							puzzle[x-1][y2]='-';
							puzzle[x][y2]='-';
							y1-=1;
							y2-=1;
						}
		    			for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
	                		{
	                			cout<<puzzle[i][j];
	                 		}
                			cout<<endl;
                		}
				   	}
                    if(tolower(a)=='d')
		    		{
		    		    if(y2!=size-1&&puzzle[x-1][y2+1]=='-'&&puzzle[x][y2+1]=='-')
		    		    {
							puzzle[x-1][y2+1]='#';
							puzzle[x][y2+1]='#';
							puzzle[x-1][y2]='-';
							puzzle[x][y1]='-';
							y1+=1;
							y2+=1;
						}
						for(int i=0;i<size;i++)
	                	{
	                		for(int j=0;j<size;j++)
                			{
                				cout<<puzzle[i][j];
                			}
	                		cout<<endl;
	                	}
		    		}
        }
    }
        if(tolower(a)=='s')
        {
        	while(x!=size-1&&puzzle[x+1][y1]=='-'&&puzzle[x+1][y2]=='-'&&puzzle[x+1][y1+1]=='-')
        	{
        		puzzle[x+1][y1]='#';
				puzzle[x+1][y2]='#';
				puzzle[x+1][y1+1]='#';
				puzzle[x-1][y2]='-';
				puzzle[x][y1]='-';
				puzzle[x][y1+1]='-';
        		x+=1;
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
    	for(int i=size-1;i<0;i--)
    	{
    		int counting=0;
    		for(int j=0;j<size;j++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
    			}
    		}
    		if(counting==size)
    		{
    			game.score++;
    			for(int k=i;k<size-1;k++)
    			{
    				for(int j=0;j<size;j++)
    				{
    					puzzle[i][j]=puzzle[i+1][j];
    				}
    			}
    			for(int j=0;j<size;j++)
    			{
    				puzzle[size-1][j]='-';
    			}
    		}
    	}
    	for(int j=0;j<size;j++)
    	{
    		int counting=0;
    		for(int i=0;i<size;i++)
    		{
    			if(puzzle[i][j]=='#')
    			{
    				counting++;
				}
			}
			if(counting==size)
			{
				game.score++;
				if(game.score>game.high_score)
				{
					game.high_score=game.score;
				}
				for(int i=0;i<size;i++)
				{
					puzzle[i][j]='-';
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<puzzle[i][j];
			}
			cout<<endl;
		}
		play();	
	}
}
}
#endif
