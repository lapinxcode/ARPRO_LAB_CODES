#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void user_guess(){
    srand(time(0));

    int x = rand() % 101;
    int y;

    cout << "[DEBUG] Answer: " << x << endl;

    while(x != y){
        cout << "Guess the number (0-100)" << endl;
        cin >> y;
        if(x != y){
            cout << "Wrong :(" << endl;
        }
    }
    cout << "Congrats! That is the right value" << endl;
}

void pc_guess(){

    int x;
    int y;
    int i = 1;

    while(y < 0 or y > 100){
        cout << "Input a number (0-100)" << endl;
        cin >> y;
    }

    while(x != y){
        x = rand() % 101;
        cout << "Computer guess: " << x << endl;

        if(x != y){
            cout << "Wrong :( Total number of guesses: " << i << endl;
            i = i+1;
        }
        else{
            cout << "The computer got it right in the guess number " << i << endl;
        }
    }
}

void pc_guess_smart(){

    int guess, answer;
    int min, max;
    int i = 1;

    while(answer < 0 or answer > 100){
        cout << "Input a number (0-100)" << endl;
        cin >> answer;
    }

    min = 0;
    max = 100;

    guess = (min+max)/2; // starts in the middle

    while(guess != answer){
        i = i+1;
        cout << "Computer guess: " << guess << endl;

        if(guess > answer){
            max = guess; // updates max value
            cout << "Wrong :( Total number of guesses: " << i << endl;
        }

        else if(guess < answer){
            min = guess; // updates min value

            cout << "Wrong :( Total number of guesses: " << i << endl;
        }
        guess = min + rand()%(max - min + 1);
    }

    cout << "Computer guess: " << guess << endl;
    i = i+1;
    cout << "The computer got it right in the guess number " << i << endl;
}

void r_p_s(){
    int user_option = 5; // init w out of bound value
    int pc_option;

    while(user_option < 0 or user_option > 2){
        cout << "Choose your weapon >:)" << endl;
        cout << "Rock = 0 ｜ Paper = 1 ｜ Scissor = 2" << endl;
        cin >> user_option;
    }

    pc_option = rand() % 3;
    cout << "PC Chose " << pc_option << endl;

    if(user_option == pc_option){
           cout << "Its a tie!" << endl;
    }

    else if(user_option == 0){
        if(pc_option == 1){
            cout << "PC Wins" << endl;
        }
        else if(pc_option == 2){
            cout << "User Wins" << endl;
        }
    }

    else if(user_option == 1){
        if(pc_option == 2){
            cout << "PC Wins" << endl;
        }
        else if(pc_option == 0){
            cout << "User Wins" << endl;
        }
    }

    else if(user_option == 2){
        if(pc_option == 0){
            cout << "PC Wins" << endl;
        }
        else if(pc_option == 1){
            cout << "User Wins" << endl;
        }
    }
}

void print_sticks(int num_sticks, int round_num){
    cout<< "Round " << round_num << endl;
    cout << "------------------------------------------" << endl;
     for(int i = 0; i < num_sticks; i++){
        cout << "｜";
    }
    cout << endl;
    cout << "------------------------------------------" << endl;
}



void stick_game(){
    auto num_sticks(21);
    int player_choice, pc_choice, round = 0;


    while(num_sticks > 1){

        print_sticks(num_sticks, round);

        while (player_choice < 1 or player_choice > 3){
            cout << "Select the number of sticks you want to remove (Remaining: " << num_sticks << ")" << endl;
            cin >> player_choice;
        }

        num_sticks = num_sticks - player_choice;

        if(num_sticks == 1){
            cout << "There is only one stick left" << endl;
            cout << "You won, congratulations!" << endl;
            break;
        }

        print_sticks(num_sticks, round);

        cout << player_choice << " sticks removed! (Remaining: " << num_sticks << ")" << endl;

        pc_choice = 1 + rand() % 3;

        cout << "The computer takes " << pc_choice << " stick(s)" << endl << endl;

        num_sticks = num_sticks - pc_choice;

        if(num_sticks == 1){
            cout << "There is only one stick left" << endl;
            cout << "PC won!" << endl;
            break;
        }

        player_choice = 0;
        round = round + 1;

    }

    print_sticks(num_sticks, round);
    cout << "End of the game! Thanks for playing!" << endl;

}

int main(){
    srand(time(0));
    //pc_guess();
    //pc_guess_smart();
    //r_p_s();
    stick_game();
    return 0;
}
