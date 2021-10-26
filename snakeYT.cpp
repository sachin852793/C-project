#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Snake{
	private:
		int x,y;
	public:
		Snake(){x=0; y=0;}
		void setSnake(int x1,int y1){x=x1; y=y1;}
		void showSnake(){cout<<"("<<x<<","<<y<<")"<<" ";}
		int getSnakeX(){return(x);}
		int getSnakeY(){return(y);}
		friend void changeSnakeHeadLocation(char, Snake&);
};
class FoodLocation{
	private:
		int x,y;
	public:
		FoodLocation(){x=30; y=14;}
		void setFood(int x1,int y1){ x=x1; y=y1; }
		void showFood(){cout<<x<<","<<y;}
		int getFoodX(){return(x);}
		int getFoodY(){return(y);}
};
FoodLocation changeFoodLocation(){
	FoodLocation foodLocation;
	srand(time(0));
	int x=rand()%71;  // 0 t0 70
	int y=rand()%21;  // 0 to 20
	foodLocation.setFood(x,y);
	return(foodLocation);
}
void drawBoundary(Snake snake,FoodLocation &foodLocation,Snake *snakeBody,int &snakeLength,int &score){
	int i,j,l;
	for(i=-1;i<=21;i++){
		for(j=-1;j<=71;j++){
			l=0;
			if(i==-1 || i==21 || j==-1 || j==71){
				cout<<"#";
			}
			else{
				if(i==snake.getSnakeY() && j==snake.getSnakeX()){
					cout<<"0";	
				}
				else if(i==foodLocation.getFoodY() && j==foodLocation.getFoodX()){
					cout<<"F";
				}
				else{
					for(int k=0;k<snakeLength;k++){
						if(i==snakeBody[k].getSnakeY() && j==snakeBody[k].getSnakeX()){
							cout<<"o";
							l=1;
						}
					}
					if(l==0)
						cout<<" ";
				}
			}
		}
		cout<<"\n";
	}
	if(snake.getSnakeX()==foodLocation.getFoodX() && snake.getSnakeY()==foodLocation.getFoodY()){
		foodLocation=changeFoodLocation();
		if(snakeLength>1){ 
			for(int q=snakeLength;q>=1;q--){
				snakeBody[q]=snakeBody[q-1];
			}
		}
		snakeLength++;
		score+=10;
	}
	for(int p=0;p<snakeLength;p++){
		snakeBody[p].showSnake();
	}
	snake.showSnake();
	cout<<"\nScore : "<<score;
}
void changeSnakeHeadLocation(char keyPressed, Snake &snake){
	switch(keyPressed){
		case 'a':
			(snake.x)--;
			break;
		case 's':
			(snake.x)++;
			break;
		case 'w':
			(snake.y)--;
			break;
		case 'z':
			(snake.y)++;
			break;
	}
}
void changeSnakeBody(Snake *snakeBody,Snake snake,int snakeLength){
	int i=0;
	for(i=0;i<snakeLength-1;i++){
		snakeBody[i]=snakeBody[i+1];
	}
	snakeBody[i]=snake;
}
int main(){
	system("cls");
	Snake snake;
	FoodLocation foodLocation;
	Snake snakeBody[100];  //o
	char ch=' ';
	int i,j,snakeLength=0,breakInfiniteloop=0,score=0;  
	while(1){   // a s w z 
		system("cls");
		if(snake.getSnakeX()==-1 || snake.getSnakeX()==71 || snake.getSnakeY()==-1 || snake.getSnakeY()==21){
			cout<<"\nyou Hit The Wall, Lost";
			cout<<endl<<"score : "<<score<<endl;
			break;
		}
		if(kbhit()){
			ch=getch();
		}
		drawBoundary(snake,foodLocation,snakeBody,snakeLength,score);
		if(ch=='a' || ch=='s' || ch=='w' || ch=='z'){
			changeSnakeBody(snakeBody,snake,snakeLength);
			changeSnakeHeadLocation(ch,snake);
		}
		else if(ch!=' '){
			cout<<"\nYou Lost";
			cout<<endl<<"score : "<<score<<endl;
			break;
		}
		for(i=1;i<=1000;i++){ 
			for(j=1;j<=10000;j++){
			} 
		}
		for(int k=0;k<snakeLength;k++){
			if(snake.getSnakeX()==snakeBody[k].getSnakeX() && snake.getSnakeY()==snakeBody[k].getSnakeY()){
				cout<<"\nYou Have Hit To Your Body..";
				cout<<endl<<"score : "<<score<<endl;
				breakInfiniteloop=1;
				break;
			}
		}
		if(breakInfiniteloop==1){
			break;
		}
	}//end of infinite loop
	           
	//getch();
	return(0);
}





