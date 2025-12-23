#include "header.h"

int main() {
    setlocale(LC_ALL, "lt_LT.UTF-8");

    string filename;
    getline(cin, filename);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Klaida atidarant failą: " << filename << endl;
        return 1;
    }

    cout << "Rezultatus išvesti į failą ar į terminalą? (failas / terminalas): ";
    string choice;
    getline(cin, choice);

    if (choice == "failas") {
        cout << "Rezultatai bus išvesti į failus" << endl;
        cout << "...MENIU..." << endl;
        cout << "1. Žodžių pasikartojimų skaičius" << endl;
        cout << "2. Žodžių ir eilučių numerių lentelė" << endl;
        cout << "3. URL adresai" << endl;

        cout << "Pasirinkite veiksmus (galite pasirinkti vieną arba kelis): 1, 2, 3: ";
        string actions;
        getline(cin, actions);

        readFromFile(filename);

        if (actions.find('1') != string::npos) {
            writeFile_1("word_count.txt");
            cout << "Failas 'word_count.txt' sukurtas." << endl;
        }

        if (actions.find('2') != string::npos) {
            writeFile_2("cross_reference.txt");
            cout << "Failas 'cross_reference.txt' sukurtas." << endl;
        }

        if (actions.find('3') != string::npos) {
            printURLs(urls, "urls.txt");
            cout << "Failas 'urls.txt' sukurtas." << endl;
        }
    }
    else {
        cout << "Rezultatai bus išvesti į terminalą" << endl;
        cout << "...MENIU..." << endl;
        cout << "1. Žodžių pasikartojimų skaičius" << endl;
        cout << "2. Žodžių ir eilučių numerių lentelė" << endl;
        cout << "3. URL adresai" << endl;

        cout << "Pasirinkite veiksmus (galite pasirinkti vieną arba kelis): 1, 2, 3: ";
        string actions;
        getline(cin, actions);

        readFromFile(filename);

        if (actions.find('1') != string::npos) {
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Žodžių pasikartojimų skaičius:" << endl;
            cout << "----------------------------------------" << endl;
            printResults();
        }

        if (actions.find('2') != string::npos) {
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Žodžių ir eilučių numerių lentelė:" << endl;
            cout << "----------------------------------------" << endl;
            printCrossReference();
        }

        if (actions.find('3') != string::npos) {
            cout << endl;
            cout << "----------------------------------------" << endl;
            cout << "Rasti URL adresai:" << endl;
            cout << "----------------------------------------" << endl;
            printURLs_terminal(urls);
        }
    }
}
