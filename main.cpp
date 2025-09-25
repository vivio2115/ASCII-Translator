#include <iostream>
#include <string>
using namespace std;

int main() {
    char letters[] = {
    ' ', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
    };

    string binaries[] = {
    "00100000", // spacja
    "01100001","01100010","01100011","01100100","01100101","01100110","01100111",
    "01101000","01101001","01101010","01101011","01101100","01101101","01101110",
    "01101111","01110000","01110001","01110010","01110011","01110100","01110101",
    "01110110","01110111","01111000","01111001","01111010"
    };

    string input;
    string output;
    int op;
    int i = 0;
    int start = 0;
    int len;


    cout << "Wpisz 1 aby zamienić tekst na kod binarny, wybierz 2 aby zamienic kod binarny na tekst: ";
    cin >> op;
    cin.ignore();

    switch (op)
    {
    case 1:
        cout << "Podaj wyraz lub zdanie (male litery): ";
        getline(cin, input);

        len = input.size();

        while (i < len) {
            char znak = input[i];

            int j = 0;
            while (j < sizeof(letters) / sizeof(letters[0]))
            {
                if (letters[j] == znak) 
                {
                    output = output + binaries[j];
                    output = output + " ";
                    break;
                }
                j++;
            }

            i++;
        }

        cout << "Binarnie: " << output << endl;
        break;
    case 2:
        cout << "Podaj kod binarny: ";
        getline(cin, input);
       

        while (start < input.size())
        {
            int end = input.find(' ', start);
            if (end == string::npos)
            {
                end = input.size();
            }

            string blok = input.substr(start, end - start);
            cout << "Blok binarny: " << blok << endl;

            start = end + 1;
            int j = 0;

            while (j < sizeof(binaries) / sizeof(binaries[0]))
            {
                if (binaries[j] == blok)
                {
                    output = output + letters[j];
                    break;
                }
                j++;
            }
        }


        cout << "Wiadomosc: " << output << endl;
        break;
    default:
        break;
    }
}
