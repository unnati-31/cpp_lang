#include <iostream> 
#include <cstdlib>
#include <ctime>

//ZOMBIE APOCALYPSE SURVIVAL GAME

int main() {

    std::srand(std::time(0));

    int day = 1;
    int totalDays = 14;
    int food = 14;
    int ammo = 7;
    int morale = 14;
    bool isAlive = true;
    int eventType;
    int choice;

    while(day <= totalDays && isAlive) {
        std::cout << "=====" << "Day " << day << "=====" << "\n";
        std::cout << "Food: " << food << "\n";
        std::cout << "Ammo: " << ammo << "\n";
        std::cout << "Morale: " << morale << "\n";

        eventType = std::rand() % 4;

        if (eventType == 0) {
            std::cout << "Zombies are pounding on the door!" << "\n";
            std::cout << "1. Fight them." << "\n";
            std::cout << "2. Stay silent and hope they leave." << "\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            if (choice == 1) {
                if(ammo >= 3) {
                    ammo -= 3;
                    morale += 2;
                    std::cout << "You fought them off successfully!!!" << "\n";
                }
                else {
                    food -= 3;
                    morale -=2;
                    std::cout << "OOPS!! You got hurt scavenging in a panic." << "\n";
                }
            }
            else if (choice == 2) {
                int outcome = std::rand() % 2;
                if (outcome == 0) {
                    morale -= 1;
                    std::cout << "They eventually leave." << "\n";
                }
                else {
                    food -= 4;
                    morale -= 3;
                    std::cout << "Oh no!!! They broke in. You lost supplies" << "\n";
                }
            }
            else {
                std::cout << "Please enter the right choice" << "\n";
            }
        }
    
        else if(eventType == 1) {
            std::cout << "A scavenger offers to trade 3 units of foods for 2 units of ammo" << "\n";
            std::cout << "1. Accept trade" << "\n";
            std::cout << "2. Decline" << "\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;
        
            if(choice == 1) {
                if(food >= 3) {
                    food -= 3;
                    ammo += 2;
                }
                else {
                    std::cout << "Not enough food to trade" << "\n";
                }
            }

            else if(choice == 2) {
                std::cout << "Good decision" << "\n";
            }

            else {
                std::cout << "Please enter the right choice" << "\n";
            }
        }

        else if(eventType == 2) {
            food -= 7;
            ammo -= 3;
            morale -= 3;
            std::cout << "Oh no!!! A storm destroyed your supplies" << "\n";
        }

        else if(eventType == 3) {
            std::cout << "It's eerily quiet. Nothing changes" << "\n";
        }

        if(food <= 0) {
            isAlive = false;
            std::cout << "You starved to death. Game over." << "\n";
        }

        else if(morale <= 0) {
            isAlive = false;
            std::cout << "Your group lost hope and abnadoned the bunker. Game Over." << "\n";
        }

        day += 1;
    }

    if(isAlive) {
        std::cout << "You survived " << totalDays << "days" << "\n";
        if (morale >= 8) {
            std::cout << "VICTORY!!!! You are thriving" << "\n";
        }
        else if (morale >= 4) {
            std::cout << "Battered but alive. VICTORY!!!" << "\n"; 
        }
        else {
            std::cout << "Barely hanging on, but you made it. VICTORY!!" << "\n";
        }
    }

    else {
        std::cout << "You did not survive the apocalypse. Hard luck!" << "\n";
    }
}