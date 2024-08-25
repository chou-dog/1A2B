#include <iostream>
#include <ctime>
using namespace std;
int generateRandomFourDigitNumber() {
    srand(time(NULL)); 
    return rand() % (9000+1) +1000 ;
}

int main() {
    srand (time (NULL));
    int random_number = generateRandomFourDigitNumber();
    string answer=to_string(random_number);
    //cout << "random :" << answer << endl; 
    int n=0,GuessTime=0;
    string n2;

    do {
        cout << "Please enter a 4-digit number: " << endl;
        cin >> n;

        n2 = to_string(n);

        int A = 0, B = 0;
        bool matched[4] = {0,0,0,0};

        for (int i = 0; i < 4; i++) {
            if (answer[i] == n2[i]) {
                A++;
                matched[i] = 1;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (answer[i] != n2[i]) { 
                for (int j = 0; j < 4; j++) {
                    if (matched[j]==0 && answer[i] == n2[j]) {
                        B++;
                        break;
                    }
                }
            }
        }
        GuessTime+=1;
        cout << "A: " << A << " B: " << B << endl;
        
    } while (n2 != answer);
    cout<<"totalGuessTimes="<<GuessTime<<endl;
    cout << "Guess is right!" << endl;
    return 0;
}

