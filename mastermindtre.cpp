/*
    mastermindtre.cpp
    Author:Manila Mingozzi
    Date: 08-03-2021
    *Master Mind corretto
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Mastermind{
    private:
    int map[5];
    int test[5];

    void init(){
        srand (time(NULL));
        for (int i=0; i<5; i++){
            map [i]= (rand () % 10) +1;
            for (int j=0; j<i; j++){
                if (map [i]== map[j]){
                    i--;
                    break;
                }
            }
        }
    }

    public:
    Mastermind (){
        init();
    }

    void stampa (){
        for (int i=0; i<5; i++){
            cout<<map[i]<<"\t";
        }
        cout<<endl;
    }

    void play(){
        cout<<"Inserisci 5 numeri interi"<<endl;
        for (int i=0; i<5; i++){
            cin>>test[i];
            for (int j=0; j<i; j++){
                if (test [i]== test[j]){
                    system ("color 0c");
                    cout <<"ERRORE: NUMERO RIPETUTO" <<endl;
                    cout <<"inserire un numero diverso dal/i precedenti: ";
                    cin>>test [i];
                    system ("color 0f");
                }
            }
        }

        for (int i=0; i<5; i++){
            cout<<test[i]<<"\t";
        }
    }

    bool check(){
        int strike=0, ball=0;
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if (test[i]==map[j]){
                    if (i==j){
                        strike++;
                    }
                    else{
                        ball++;
                    }
                }
            }
        }
        cout<<endl<<"Strike: "<<strike<<endl<<"Ball: "<<ball<<endl;
        return strike==5;
    }

};

int main(){
    cout<<"Programma Mastermind avviato"<<endl;
    Mastermind m;

    m.stampa();
    do{
        m.play();

    } while (!m.check());

    return 0;
}