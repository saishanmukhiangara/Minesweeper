#include<bits/stdc++.h>
#include <random>
#define RESET     "\033[0m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN      "\033[36m"
#define WHITE     "\033[97m"
#define GRAY      "\033[90m"
#define BRIGHT_CYAN "\033[96m"

using namespace std;

random_device rd;
mt19937 gen(rd());



int rows,col,mines;
int reveals=0;
vector<vector<char>> board;
vector<vector<char>> display;
vector<vector<bool>> visited;
bool first_move=true;
int dr[8]={1,1,1,-1,-1,-1,0,0};
int dc[8]={1,-1,0,1,-1,0,1,-1};

void difficulty()
{
    while (true) {
int diff;
cout<<"Difficulty levels:"<<endl;
cout<<"1. Easy"<<endl;
cout<<"2. Medium"<<endl;
cout<<"3. Difficult"<<endl;
cout<<"Enter 1/2/3 for difficulty levels"<<endl;
cin>>diff;

        if (diff == 1) {
            rows = 9;
            col = 9;
            mines = 10;
            break;
        }
        else if (diff == 2) {
            rows = 16;
            col = 16;
            mines = 40;
            break;
        }
        else if (diff == 3) {
            rows = 16;
            col = 30;
            mines = 99;
            break;
        }
        else {
            cout << "Invalid difficulty. Please try again.\n";
        }
    }

    board = vector<vector<char>>(rows, vector<char>(col, '0'));
    display = vector<vector<char>>(rows, vector<char>(col, '*'));
    visited = vector<vector<bool>>(rows, vector<bool>(col, false));
}


void print_table() {
    cout << "   ";
    for (int i = 0; i < col; i++) cout << BRIGHT_CYAN <<setw(3) << i;
    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout <<BRIGHT_CYAN<< setw(2) << i << ":";
        for (int j = 0; j < col; j++) {
            char ch = display[i][j];
            if (ch == '*') cout << RESET << setw(3) << "*";
            else if (ch == 'F') cout << RED << setw(3) << "F" << RESET;
            else if (ch == '0') cout << WHITE << setw(3) << "." << RESET;
            else if (ch == '1') cout << BLUE << setw(3) << "1" << RESET;
            else if (ch == '2') cout << GREEN << setw(3) << "2" << RESET;
            else if (ch == '3') cout << RED << setw(3) << "3" << RESET;
            else if (ch == '4') cout << MAGENTA << setw(3) << "4" << RESET;
            else if (ch == '5') cout << YELLOW << setw(3) << "5" << RESET;
            else if (ch == '6') cout << CYAN << setw(3) << "6" << RESET;
else if (ch == '7') cout << WHITE << setw(3) << "7" << RESET;
else if (ch == '8') cout << "\033[90m" << setw(3) << "8" << RESET; // gray

            else cout << setw(3) << ch;
        }
        cout << endl;
    }
}


bool is_valid(int r, int c, char command){
if((r>=0&&r<rows)&&(c>=0&&c<col)&&(command=='R'||command=='F')) return true;
else return false;
}

void place_mines(int ar, int ac)
{
    uniform_int_distribution<int> rowDist(0, rows - 1);
    uniform_int_distribution<int> colDist(0, col - 1);

    int m = 0;

    while (m < mines)
    {
        int ro = rowDist(gen);
        int co = colDist(gen);

        if ((ro != ar || co != ac) && board[ro][co] != '*')
        {
            board[ro][co] = '*';
            m++;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == '*')
                continue;

            int count = 0;

            for (int z = 0; z < 8; z++)
            {
                int nr = i + dr[z];
                int nc = j + dc[z];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < col &&
                    board[nr][nc] == '*')
                {
                    count++;
                }
            }

            board[i][j] = count + '0';
        }
    }
}


void reveal(int r, int c)
{
    if (r < 0 || r >= rows || c < 0 || c >= col || visited[r][c])
        return;

    if (display[r][c] == 'F')
    {
        cout << "Flagged cell cannot be revealed, unflag it to reveal\n";
        return;
    }

    visited[r][c] = true;
    display[r][c] = board[r][c];

    if (board[r][c] == '*')
    return;

    reveals++;

    if (board[r][c] == '0')
    {
        for (int z = 0; z < 8; z++)
        {
            reveal(r + dr[z], c + dc[z]);
        }
    }
}

bool is_win()
{
    return reveals == (rows * col) - mines;
}


int main(){
   difficulty();
   print_table();
   int r;
   int c;
   char command;
   while(true){
   
   cout<<"command 'R' means reveal, 'F' means flag"<<endl;
   cout<<"Enter command of the form(row col command)"<<endl;
   cin>>r>>c>>command;
   command = toupper(command);
   if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input format! Try again.\n";
    continue;
}
   if (is_valid(r, c, command) && first_move)
{
    if (command == 'R')
{
    if (display[r][c] == 'F')
    {
        cout << "Flagged cell cannot be revealed. Unflag it first.\n";
    }
    else
    {
        place_mines(r, c);
        first_move = false;
        reveal(r, c);
    }
}
    else
{
    if(display[r][c] >= '0' && display[r][c] <= '8')
    {
        cout << "Cannot flag a revealed cell!\n";
    }
    else
    {
        display[r][c] = (display[r][c] == 'F') ? '*' : 'F';
    }
}

    print_table();
}
   else if(is_valid(r,c,command)&&!first_move){
   if(command=='R') {
   reveal(r,c);
   if(display[r][c]=='*'){
   for(int i=0;i<rows;i++){
   for(int j=0;j<col;j++){
    display[i][j] = board[i][j];
   }
   }
   print_table();
      cout<<"Sorry, you activated a mine. GAME OVER"<<endl;
      break;
   }
   if(is_win()){
   print_table();
   cout<<"Congratulations, you won the game!!"<<endl;
   break;
   }
   }
   if(command=='F'){ 
    if(display[r][c] >= '0' && display[r][c] <= '8') {
    cout << "Cannot flag a revealed cell!\n";
}
    else display[r][c] = (display[r][c] == 'F') ? '*' : 'F';
   }
   print_table();
   }
   else{
   cout<<"Invalid command"<<endl;
   }
   }
}
