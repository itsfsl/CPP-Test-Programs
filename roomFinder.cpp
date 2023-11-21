#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

string getSuffix(int n) {
    if (n >= 11 && n <= 13) {
        return "th";
    } else {
        switch (n % 10) {
            case 1: return "st";
            case 2: return "nd";
            case 3: return "rd";
            default: return "th";
        }
    }
}

int main() {
    
    int roomNumber;
    char roomType[4];

    cout << "Enter a room number (100-120): ";
    cin >> roomNumber;

    if (roomNumber <= 99 || roomNumber >= 121) {
        cout << "You've entered incorrect room number.";
    }
    else {
        cout << "Enter a room type (NTR/ALH): ";
        cin >> roomType;

        // CHECK ROOMTYPE ARRAY IS NOT EMPTY
        for (int i = 0; i < sizeof(roomType) - 1; i++) {
            if(roomType[i] == '\0') {
                cout << "You've entered less characters.";  
                return 0;
            }
        }

        // CHECK NO NUMBERS PRESENT
        for (int i = 0; i < sizeof(roomType); i++) {
            if (isdigit(roomType[i])) {
                cout << "You've entered incorrect room type.";    
                return 0;
            }
        }

        // UPPERCASE LETTERS
        for (int i = 0; i < sizeof(roomType); i++) {
            roomType[i] = toupper(roomType[i]);
        }

        // VALIDATE ROOM TYPE
        if (strcmp(roomType, "NTR") == 0) {
            // FIND ROOM POSITION
            int roomPosition = 0;

            if (roomNumber % 2 == 0) {
                roomPosition = (roomNumber - 100) / 2 + 1;
                cout << "Take the first right on Floor 1 and your room number " << roomNumber << roomType << " will be the " << roomPosition << getSuffix(roomPosition) << " room on the RHS of the corridor.";
            }
            else {
                roomPosition = (roomNumber - 101) / 2 + 1;
                cout << "Take the first right on Floor 1 and your room number " << roomNumber << roomType << " will be the " << roomPosition << getSuffix(roomPosition) << " room on the LHS of the corridor.";
            }
        }
        else if (strcmp(roomType, "ALH") == 0) {
            // FIND ROOM POSITION
            int roomPosition = 0;

            if (roomNumber % 2 == 0) {
                roomPosition = (roomNumber - 100) / 2 + 1;
                cout << "Take the first left on Floor 1 and your room number " << roomNumber << roomType << " will be the " << roomPosition << getSuffix(roomPosition) << " room on the RHS of the corridor.";
            }
            else {
                roomPosition = (roomNumber - 101) / 2 + 1;
                cout << "Take the first left on Floor 1 and your room number " << roomNumber << roomType << " will be the " << roomPosition << getSuffix(roomPosition) << " room on the LHS of the corridor.";
            }
        }
        else {
            cout << "You've entered an incorrect room type. Please enter either 'NTR' or 'ALH'." << endl;
        }
    }
    return 0;
}