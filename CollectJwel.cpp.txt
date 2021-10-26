#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
/*
	INSTRUCTIONS
		1. Use key 'a' to move left  // x--
		2. Use key 's' to move right // x++
		3. Use key 'w' to move up    // y--
		4. Use key 'z' to move down  // y++
		5. Press 'q' To Quit The Game Any Time
*/
int width=50;
int height=10;
void drawBoundary(int x,int y,int *posX,int *posY,int *energyX,int *energyY,int noOfMoves, int *energy,int *noOfJwel,int *gameOver){
	int i,j;
	for(i=-1;i<=height;i++){
		for(j=-1;j<=width;j++){
			if(i==-1 || i==height || j==-1 || j==width ){
				cout<<"#";
			}
			else{
				if(i==y && j==x){
					cout<<"P";
					int k;
					for(k=0;k<4;k++){
						if(posX[k]==x && posY[k]==y){
							posX[k]=-1;
							posY[k]=-1;
							(*noOfJwel)++;
							(*gameOver)++;
						}
					}
					for(k=0;k<2;k++){
						if(energyX[k]==x && energyY[k]==y){
							energyX[k]=-1;
							energyY[k]=-1;
							(*energy)=(*energy)+10;
						}
					}
				}
				else{
					if(i==posY[0] && j==posX[0]){
						cout<<"a";
					}
					else if(i==posY[1] && j==posX[1]){
						cout<<"b";
					}
					else if(i==posY[2] && j==posX[2]){
						cout<<"c";
					}
					else if(i==posY[3] && j==posX[3]){
						cout<<"d";
					}
					else if(i==energyY[0] && j==energyX[0]){
						cout<<"E";
					}
					else if(i==energyY[1] && j==energyX[1]){
						cout<<"E";
					}
					else{
						cout<<" ";
					}	
				}
			}
		}
		cout<<endl;
	}
	cout<<"\n\nNo Of Moves : "<<noOfMoves;
	cout<<"\n\nEnergy Left : "<<(*energy);
	cout<<"\n\nCollected Jwel : "<<(*noOfJwel);
}
void changeUserLocationOnButtonClick(int *x,int *y,char keyPressed,int *noOfMoves,int *energy,int *gameQuit){
	int static step=0;
	if(step==5){
		(*energy)--;
		step=0;
	}
	switch(keyPressed){
		case 'a':
			if((*x)!=0){
				(*x)--;
				(*noOfMoves)++;
				step++;
			}
			break;
		case 's':
			if((*x)!=width-1){
				(*x)++;
				(*noOfMoves)++;
				step++;
			}
			break;
		case 'w':
			if((*y)!=0){
				(*y)--;
				(*noOfMoves)++;
				step++;
			}
			break;
		case 'z':
			if((*y)!=height-1){
				(*y)++;
				(*noOfMoves)++;
				step++;
			}
			break;
		case 'q':
			(*gameQuit)=1;	
			break;
	}
}
int main(){
	system("cls");
	int x=0,y=0; // position of persion
	char ch; // keyboard hit
	int noOfMoves=0,energy=10,noOfJwel=0,gameOver=0,gameQuit=0; 
	// Jwellery
	int positionX[4]={0}; // Jwel X Position
	int positionY[4]={0}; // Jwel Y Position
	
	// Energy 
	int energyX[2]={0};  // Energy X Position
	int energyY[2]={0};  // Energy Y Position
	
	int i,randomNum;
	srand(time(0)); 
	
	i=0;
	while(i<4){     
		randomNum=rand()%width; // 0 to 49  0 to 59 
		positionX[i]=randomNum;
		i++;
	}
	// Storing the random Y Position For JWEL
	i=0;
	while(i<4){
		randomNum=rand()%height;  // 0 to 9  0 to 19
		positionY[i]=randomNum;
		i++;
	}
	// Storing the random X Position For Energy
	i=0;
	while(i<2){
		randomNum=rand()%width;
		energyX[i]=randomNum;
		i++;
	}
	// Storing the random Y Position For Energy
	i=0;
	while(i<2){
		randomNum=rand()%height; 
		energyY[i]=randomNum;
		i++;
	}
	
	drawBoundary(x,y,positionX,positionY,energyX,energyY,noOfMoves,&energy,&noOfJwel,&gameOver);
	
	while(1){
		if(kbhit()){
			system("cls");
			ch=getch();
			changeUserLocationOnButtonClick(&x,&y,ch,&noOfMoves,&energy,&gameQuit);
			if(energy==0){
				system("cls");
                cout<<"\nOh No! You Lost!!\n";
                cout<<"\nYou Collected "<<noOfJwel<<" Jwels!\n";
                cout<<"\nAfter "<<noOfMoves<<" Moves You Quit!\n";
                cout<<"\nEnergy Left Is "<<energy<<endl;
                cout<<"\n[][][][] Game Over [][][][]\n";
				break;
			}
			if(gameQuit==1){
				system("cls");
                cout<<"\nOh No! You Quit!!\n";
                cout<<"\nYou Collected "<<noOfJwel<<" Jwels!\n";
                cout<<"\nAfter "<<noOfMoves<<" Moves You Quit!\n";
                cout<<"\nEnergy Left Is "<<energy<<endl;
                cout<<"\n[][][][] Game Over [][][][]\n";
				break;
			}
			if(gameOver==4){
				height=height+5;
				width=width+5;
				gameOver=0;
				i=0;                 //  
				while(i<4){     
					randomNum=rand()%width; // 0 to 49
					positionX[i]=randomNum;
					i++;
				}
				// Storing the random Y Position For JWEL
				i=0;
				while(i<4){
					randomNum=rand()%height;  // 0 to 9
					positionY[i]=randomNum;
					i++;
				}
				// Storing the random X Position For Energy
				i=0;
				while(i<2){
					randomNum=rand()%width;
					energyX[i]=randomNum;
					i++;
				}
				// Storing the random Y Position For Energy
				i=0;
				while(i<2){
					randomNum=rand()%height;
					energyY[i]=randomNum;
					i++;
				}
			}//enf of if
			drawBoundary(x,y,positionX,positionY,energyX,energyY,noOfMoves,&energy,&noOfJwel,&gameOver);  
		}
	}
	getch();
	return(0);
}





