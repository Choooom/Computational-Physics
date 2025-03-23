
#include "Kinematics.h"
#include "ConsoleUtils.h"    

#include <iostream>
#include <windows.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"


#ifdef max
#undef max
#endif

using namespace std;

Kinematics::Kinematics() {

}

void Kinematics::runKinematics() {
    int choice = 1;

    while (choice != 0) {
        vector<string> arr = { "1.) delta d = d_f - d_i", "2.) delta t = t_f - t_i",  "3.) v = d/t",
        "4.) a = v/t","5.) d = 1/2(v_i + v_f)t", "6.) d = v_i*t + 1/2(at^2)", "7.) v_f = v_i + at", "8.) v_f^2 = v_i^2 + 2ad" };

        int title = 0;

        for (int i = 0; i < arr.size() / 2; i++) {
            for (int j = 0; j < 2; j++) {
                setCursorPosition(35 + (j * 24), 6 + i);
                cout << YELLOW << arr[title] << RESET;
                title++;
            }
        }

        setCursorPosition(35, 15);
        cout << YELLOW "Choose from the list above: " GREEN;
        cin >> choice;
        cout << RESET;

        switch (choice) {
        case 1:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation1();
            break;
        case 2:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation2();
            break;
        case 3:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation3();
            break;
        case 4:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation4();
            break;
        case 5:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation5();
            break;
        case 6:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation6();
            break;
        case 7:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation7();
            break;
        case 8:
            setCursorPosition(35, 6);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 7);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 8);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 9);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            setCursorPosition(35, 15);
            for (int i = 0; i < 49; i++) {
                cout << " ";
            }

            equation8();
            break;
        default:
            break;
        }
    }
}

void Kinematics::equation1() {
    double di, df;
    string unit;

    setCursorPosition(35, 8);
    cout << YELLOW "Enter unit of measurement: " GREEN;
    cin.ignore();
    getline(cin, unit);

    setCursorPosition(35, 9);
    cout << YELLOW "Enter initial position (d_i): " GREEN;
    cin >> di;
    if (cin.fail()) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Please enter a valid number." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 10);
    cout << YELLOW "Enter final position (d_f): " GREEN;
    cin >> df;
    if (cin.fail()) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Please enter a valid number." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 12);
    cout << YELLOW "Displacement (d): " << GREEN << df - di << unit;

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }
}

void Kinematics::equation2() {
    double ti, tf;
    string unit;

    setCursorPosition(35, 8);
    cout << YELLOW "Enter unit of measurement: " GREEN;
    cin.ignore();
    getline(cin, unit);

    setCursorPosition(35, 9);
    cout << YELLOW "Enter initial time (t_i): " GREEN;
    cin >> ti;
    if (cin.fail()) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Please enter a valid number." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 10);
    cout << YELLOW "Enter final time (t_f): " GREEN;
    cin >> tf;
    if (cin.fail()) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Please enter a valid number." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 12);
    cout << YELLOW "Time interval (t): " << GREEN << tf - ti << unit << RESET;

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }
}

void Kinematics::equation3() {
    double d, t;
    setCursorPosition(35, 9);
    cout << YELLOW "Enter distance (d): " GREEN;
    cin >> d;
    if (cin.fail()) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Please enter a valid number." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 10);
    cout << YELLOW "Enter time (t): " GREEN;
    cin >> t;
    if (cin.fail() || t == 0) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Time cannot be zero or non-numeric." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 12);
    cout << YELLOW "Velocity (v): " GREEN << d / t << "m/s";

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }


}

void Kinematics::equation4() {
    double v, t;
    setCursorPosition(35, 9);
    cout << YELLOW "Enter velocity (v): " GREEN;
    cin >> v;
    if (cin.fail()) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Please enter a valid number." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 10);
    cout << YELLOW "Enter time (t): " GREEN;
    cin >> t;
    if (cin.fail() || t == 0) {
        setCursorPosition(35, 11);
        cout << RED "Invalid input. Time cannot be zero or non-numeric." RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    setCursorPosition(35, 12);
    cout << YELLOW "Acceleration (a): " GREEN << v / t << "m/s";

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }
}

void Kinematics::equation5() {
    double vi, vf, t;
    setCursorPosition(35, 9);
    cout << YELLOW "Enter initial velocity (v_i): " GREEN;
    cin >> vi;
    setCursorPosition(35, 10);
    cout << YELLOW "Enter final velocity (v_f): " GREEN;
    cin >> vf;
    setCursorPosition(35, 11);
    cout << YELLOW "Enter time (t): " GREEN;
    cin >> t;
    setCursorPosition(35, 12);
    cout << YELLOW "Distance (d): " GREEN << 0.5 * (vi + vf) * t << "m";

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }
}

void Kinematics::equation6() {
    double vi, a, t;
    setCursorPosition(35, 9);
    cout << YELLOW "Enter initial velocity (v_i): " GREEN;
    cin >> vi;
    setCursorPosition(35, 10);
    cout << YELLOW "Enter acceleration (a): " GREEN;
    cin >> a;
    setCursorPosition(35, 11);
    cout << YELLOW "Enter time (t): " GREEN;
    cin >> t;
    setCursorPosition(35, 12);
    cout << YELLOW "Distance (d): " GREEN << (vi * t) + (0.5 * a * t * t) << "m";

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }
}

void Kinematics::equation7() {
    double vi, a, t;
    setCursorPosition(35, 9);
    cout << YELLOW "Enter initial velocity (v_i): " GREEN;
    cin >> vi;
    setCursorPosition(35, 10);
    cout << YELLOW "Enter acceleration (a): " GREEN;
    cin >> a;
    setCursorPosition(35, 11);
    cout << YELLOW "Enter time (t): " GREEN;
    cin >> t;
    setCursorPosition(35, 12);
    cout << YELLOW "Final velocity (v_f): " GREEN << vi + (a * t) << "m/s";

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }
}

void Kinematics::equation8() {
    double vi, a, d;
    setCursorPosition(35, 9);
    cout << YELLOW "Enter initial velocity (v_i): " GREEN;
    cin >> vi;
    setCursorPosition(35, 10);
    cout << YELLOW "Enter acceleration (a): " GREEN;
    cin >> a;
    setCursorPosition(35, 11);
    cout << YELLOW "Enter distance (d): " GREEN;
    cin >> d;
    setCursorPosition(35, 12);
    cout << YELLOW "Final velocity squared (v_f^2): " GREEN << (vi * vi) + (2 * a * d) << "m/s";

    setCursorPosition(35, 13);
    cout << YELLOW "Final velocity (v_f): " GREEN << sqrt((vi * vi) + (2 * a * d)) << "m/s";

    setCursorPosition(35, 15);
    cout << BLUE "Press any key to continue..." RESET;

    cin.get();
    cin.get();

    setCursorPosition(35, 8);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 9);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 11);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 10);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 12);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }

    setCursorPosition(35, 15);
    for (int i = 0; i < 49; i++) {
        cout << " ";
    }
}





