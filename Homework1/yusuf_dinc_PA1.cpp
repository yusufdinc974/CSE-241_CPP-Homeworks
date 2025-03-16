#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(int argc, char *argv[]) {

    string user_input;
    char list[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e'};
    int iterator_counter = 0; // to check the fail 

    /* To generate different random number each time */
    srand(time(NULL));

    /* converting char array to string for useful purposes */
    string sdigit(argv[2]);

    /* Checking missing argument */
    if(argc < 3){

        cout << "E0" << endl;
        exit(1);

    }

    /* User selected the -r option */
    if(strcmp(argv[1],"-r") == 0){

        /* Computer's random list array */
        char random_list[15];
        int random;

        /* converting string to int to be able to make comparision */
        const int digit_number = stoi(sdigit); 

        /* Checking if user enters undefined input */
        if(digit_number <= 0 || digit_number > 15){

        cout << "E0" << endl;
        exit(1);

        }

        /* Assigning different random number from list to random list */
        for(int i=0; i<digit_number; ++i){

            /* default = 0; when random number is in the array already, it will be 1 */
            int flag = 0;            
            random = rand() % 16;

            /* checking if the random list already has the number */
            for(int j=0; j<digit_number; ++j){

                if(random_list[j] == list[random]){

                    --i; //to repeat same loop until it gets different random number
                    flag = 1;

                }

            }             
            
            /* Never catch same random number, random list is unique */
            if(flag == 0){

                random_list[i] = list[random];
      
            }    
    
        }
        
        while(iterator_counter < 100){

            /* to count misplaced and exact */
            int misplaced_counter = 0, exact_counter = 0;

            /* taking input from user */
            cin >> user_input;
            iterator_counter++;

            /* checks if the user enters more or less digit */
            if(user_input.length() != digit_number){

                cout << "E1" << endl;
                exit(1);

            }

            /* Checking if user entered a non-integer value */
            for(int i=0; i<user_input.length();++i){
                
                if(!((user_input[i] >= 48 && user_input[i] <= 57) || (user_input[i] >= 97 && user_input[i] <= 101))){

                    cout << "E2" << endl;
                    exit(1);

                }
            }

            for(int i=0; i<digit_number; ++i){
                
                /* if there is a digit where user's array and secret number's digit same, exact counter will be increased */
                if(random_list[i] == user_input[i]){

                    exact_counter++;

                    /* When exact counter reaches the digit number, which means all of digits are exact, game will be over */
                    if(exact_counter == digit_number){

                        cout << "FOUND " << iterator_counter <<endl;
                        exit(1);

                    }

                }

                else{
                    
                    /* if it isn't exact number then check for other secret number digits */
                    for(int j=0; j<digit_number; ++j){

                        /* if it's match then misplaced will be increased */
                        if(random_list[i] == user_input[j]){

                            misplaced_counter++;

                        }
                    }
                }
            }
            cout << exact_counter << " " << misplaced_counter << endl;
        }
    }

    /* User selected the -u option */
    else if(strcmp(argv[1],"-u") == 0){

        /* Checking for if entered number is unique */
        for(int i=0; i<sdigit.length(); i++){

            for(int j=i+1; j<sdigit.length(); j++){

                if(sdigit[i] == sdigit[j]){

                    cout << "E0" << endl;
                    exit(1);
                }
            }
        }

        while(iterator_counter < 100){

            int misplaced_counter = 0, exact_counter = 0;

            /* taking input from user */
            cin >> user_input;
            iterator_counter++;

            if(user_input.length() != sdigit.length()){

                cout << "E1" << endl;
                exit(1);

            }

            /* Checking if user entered a non-integer value */
            for(int i=0; i<user_input.length();++i){
                
                if(!((user_input[i] >= 48 && user_input[i] <= 57) || (user_input[i] >= 97 && user_input[i] <= 101))){

                    cout << "E2" << endl;
                    exit(1);

                }
            }

            for(int i=0; i<sdigit.length(); ++i){
                
                /* checking if there is a match between secret number user input  */
                if(argv[2][i] == user_input[i]){

                    exact_counter++;
                    
                    /* if all of the digit's match, then user won */
                    if(exact_counter == sdigit.length()){

                        cout << "FOUND " << iterator_counter <<endl;
                        exit(1);

                    }

                }

                else{
                     /* if there is no exact match, then check the other digit for mismatch */
                    for(int j=0; j<sdigit.length(); ++j){

                        if(argv[2][i] == user_input[j]){

                            misplaced_counter++;

                        }

                    }

                }

            }

            cout << exact_counter << " " << misplaced_counter << endl;

        }

        
    }

    /* This state means user entered wrong input type */
    else{

        cout << "E0" << endl;
        exit(1);
    }

}