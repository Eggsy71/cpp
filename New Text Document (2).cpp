#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h> // For Windows color (optional)

using namespace std;

// Function to set console color (Windows)
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Clear screen
void clearScreen() {
    system("cls");
}

// Display animated birthday cake
void showCake() {
    setColor(12); // Red
    cout << "\n";
    cout << "         *         " << endl;
    cout << "        ***        " << endl;
    cout << "       *****       " << endl;
    cout << "      *******      " << endl;
    cout << "     *********     " << endl;
    cout << "    ***********    " << endl;
    cout << "   *************   " << endl;
    cout << "  ****   ***   ****" << endl;
    cout << " ****   *****   ****" << endl;
    cout << "*********************" << endl;
    cout << "*********************" << endl;
    setColor(14); // Yellow
    cout << "     ||||||||||     " << endl;
    cout << "     ||||||||||     " << endl;
    setColor(7); // White
    cout << endl;
}

// Birthday wishes array
vector<string> wishes = {
    "On your special day, I wish you endless joy, boundless love, and a year filled with beautiful memories! 💖",
    "Happy Birthday! You're not getting older, you're increasing in value! 😂🎉",
    "Happy Birthday! May this year bring you closer to your dreams! 🌟",
    "Happy Birthday! Wishing you laughter, love, and lots of cake! 🥳",
    "Another year wiser, another year stronger! Happy Birthday! 🎈",
    "May all your dreams come true! Happy Birthday! ✨"
};

// Display main title with animation
void showTitle() {
    clearScreen();
    setColor(14);
    for (int i = 0; i < 3; i++) {
        cout << "\t\t🎉 ";
        Sleep(200);
        cout << "HAPPY BIRTHDAY! ";
        Sleep(200);
        cout << "🎉" << endl;
        Sleep(500);
    }
    setColor(7);
}

// Display all wishes
void showAllWishes() {
    cout << "\n🌟 CHOOSE A WISH (1-6) OR 0 FOR RANDOM: 🌟\n" << endl;
    for (int i = 0; i < wishes.size(); i++) {
        setColor(10 + (i % 6)); // Different colors
        cout << i + 1 << ". " << wishes[i] << endl;
        setColor(7);
    }
    cout << "\n0. 🎲 Random Wish" << endl;
}

// Generate custom wish
void customWish() {
    string name;
    cout << "\n✨ Enter name (or press Enter for 'you'): ";
    getline(cin, name);
    if (name.empty()) name = "you";
    
    vector<string> customMessages = {
        "Happy Birthday " + name + "! May your day be as wonderful as you are! 🎈",
        "Cheers to " + name + "! Another trip around the sun! ☀️",
        name + ", Happy Birthday! Health, happiness, and cake! 🎂"
    };
    
    srand(time(0));
    int random = rand() % customMessages.size();
    setColor(14);
    cout << "\n🎉 " << customMessages[random] << " 🎉" << endl;
    setColor(7);
}

int main() {
    srand(time(0));
    
    // Title animation
    showTitle();
    showCake();
    
    int choice;
    do {
        showAllWishes();
        
        cout << "\nEnter choice (0-6) or -1 for custom: ";
        cin >> choice;
        cin.ignore(); // Clear buffer
        
        if (choice == -1) {
            customWish();
        } else if (choice == 0) {
            // Random wish
            int random = rand() % wishes.size();
            setColor(14);
            cout << "\n🎲 " << wishes[random] << " 🎲" << endl;
            setColor(7);
        } else if (choice > 0 && choice <= wishes.size()) {
            setColor(14);
            cout << "\n🎉 " << wishes[choice - 1] << " 🎉" << endl;
            setColor(7);
        } else {
            setColor(12);
            cout << "\n❌ Invalid choice! Try again.\n" << endl;
            setColor(7);
        }
        
        cout << "\nPress Enter to continue...";
        cin.get();
        
    } while (true);
    
    return 0;
}