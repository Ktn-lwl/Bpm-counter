#include <iostream>
#include <ctime>
#include <thread>
#include <typeinfo>

using namespace std;

time_t x;
bool counting = true;

void timer(time_t target){
    time_t now = time(NULL);
    *(&x) = time(NULL);

    while (*(&x)-now < target){
        *(&x) = time(NULL);
    }

    *(&counting) = false;
}

int main(){
    int clicks = 0;

    cout << "Hit enter to start counting " << endl;
    system("pause");
    cout << "tick"; 
    clicks++;

    thread t1 (timer, 10);
    
    while (counting){
        char click = getchar();
        system("cls");

        if (click == *"\n"){
            cout << "tick"; 
            clicks++;
        }
    }

    t1.join(); 
    system("cls");
    int bpm = clicks*6;

    cout << clicks << " ticks x 10 seconds = " << bpm << " bpm" << endl;

    system("pause");
    return 0;
}
