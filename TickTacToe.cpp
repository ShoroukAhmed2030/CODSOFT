#include<iostream>
#include<ctime>
using namespace std ;
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int choice;
void display_board();
void X_player();
void O_player();
void Computer_chice();
void count_board();
char check_win();
void computer_vs_player();
void player_vs_player();
int main (){
    while (true)
    {   
       int mode;
    cout<<"1.Computer Vs Player"<<endl;
    cout<<"2.Player X Vs Player O"<<endl;
    cout<<"Choose The Mode : "<<endl;
    cin>>mode;
    switch (mode){
    case 1 : computer_vs_player(); break;
    case 2 : player_vs_player();   break;
    default: cout<<"Invalid Mode"<<endl;  break;  } 
    } 
     return 0 ;
}
void clear_board() {
  for (int i = 0; i < 9; i++) {
    board[i] = ' ';
  }
}
void X_player(){
    while (true){
        cout<<"Choose Your Position[1:9] :";
        cin>>choice;
        choice--; //index 0
        if (choice<0||choice>8){ 
          cout<<"Invalid Positon"<<endl;
          }else if (board[choice] !=' '){
            cout<<"Please Choose Empty Position";
          }else{  board[choice]='X';
             break;  }    
     }
}
void O_player(){
    while (true){
        cout<<"Choose Your Position[1:9] :";
        cin>>choice;
        choice--; //index 0
        if (choice>8||choice<0){ 
          cout<<"Invalid Positon"<<endl;
          }else if (board[choice] !=' '){
            cout<<"Please Choose Empty Position";
         }else{  board[choice]='O';
           break;  } 
    }    
}
void computer_choice(){
    srand(time(0));
    do{
        choice=rand()%9;
    } while (board[choice] != ' ');
    board[choice]='O';
}
void display_board(){
    cout<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<< board[0]<<"  |   "<<board[1]<<"  |   "<<board[2]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"-------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<< board[3]<<"  |   "<<board[4]<<"  |   "<<board[5]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"-------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "   <<endl;
    cout<<"   "<< board[6]<<"  |   "<<board[7]<<"  |   "<<board[8]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
}
int count_board(char sympol){
    int total=0 ;
    for (int i = 0; i < 9 ; i++)
    {
        if(board[i]==sympol)
         total++;
    } return total ;
}
char check_win(){
  //horizontal winner
    if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=' ')
     return board[0];
    if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=' ')
     return board[3];
    if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=' ')
     return board[6];
  //vertical winner
    if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=' ')
     return board[0];
    if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=' ')
     return board[1];
    if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=' ')
     return board[2];
  // diagonal  winner    
   if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=' ')
     return board[0];
    if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=' ')
     return board[4];
  if (count_board('X') + count_board('O') <9){
      return 'C'; }
    else return 'D' ; }
void computer_vs_player(){
string player_name;
cout<<"Please,Enter Your Name : "<<endl;
cin>>player_name;
while(true){
    system ("cls");
    display_board();
    if (count_board('X')==count_board('O')){
        cout<<player_name<<" Now it's your turn"<<endl ;
         X_player(); 
    }else { 
        computer_choice() ;
    }char winner = check_win ();
    if( winner =='X'){
       system ("cls");
       display_board();
       cout<< player_name <<"is The winner"<<endl;
       break; 
    } else if (winner=='O'){
       system ("cls");
       display_board();
       cout<<"Computer is The winner"<<endl; 
       break;
    } else if (winner=='D'){
       cout<<"Game is draw"<< endl;
       break;} }
       clear_board();
  }
void player_vs_player(){
    string player_x , player_o ;
    cout<<"Player X ,Please Enter Your Name : "<<endl;
    cin>>player_x;
    cout<<"Player O ,Please Enter Your Name : "<<endl;
    cin>>player_o;
  while (true){
    system("cls");
    display_board();
    if (count_board('X')==count_board('O')){
        cout<<player_x<<" Now it's your turn"<<endl ;
         X_player();
    }else{
    cout<<player_o<<" Now it's your turn"<<endl ;
         O_player();
 }char winner = check_win ();
    if( winner =='X'){
       system ("cls");
       display_board();
       cout<< player_x <<" is The winner"<<endl;
       break; 
    } else if (winner=='O'){
       system ("cls");
       display_board();
       cout<< player_o <<" is The winner"<<endl; 
       break;
    } else if (winner=='D'){
       cout<<"Game is draw."<< endl;
       break; } } 
     clear_board(); 
}