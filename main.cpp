#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void to_Bin(string output, int size,vector<char> dane)
    {
        fstream plik_wy;
        int i=0;
        char ch;
        plik_wy.open(output,ios::out);
        while(i < size)
        {
            ch = dane[i];
            switch (ch) {
                case '0':
                    plik_wy << "00000";
                    break;
                case '1':
                    plik_wy << "00001";
                    break;
                case  '2':
                    plik_wy << "00010";
                    break;
                case '3':
                    plik_wy << "00011";
                    break;
                case '4':
                    plik_wy << "00100";
                    break;
                case '5':
                    plik_wy << "00101";
                    break;
                case '6':
                    plik_wy << "00110";
                    break;
                case '7':
                    plik_wy <<"00111";
                    break;
                case'8':
                    plik_wy <<"01000";
                    break;
                case'9':
                    plik_wy << "01001";
                    break;
                case'A':
                    plik_wy <<"01010";
                    break;
                case'B':
                    plik_wy << "01011";
                    break;
                case'C':
                    plik_wy <<"01100";
                    break;
                case'D':
                    plik_wy <<"01101";
                    break;
                case'E':
                    plik_wy << "01110";
                    break;
                case'F':
                    plik_wy << "01111";
                    break;
                case':':
                    plik_wy << "10000";
                    break;
                case 0xA:
                    plik_wy <<"10001";
                    break;
                case 0xD:
                    plik_wy << "10010";
                    break;

            }
            i++;
        }

        // dopisywanie bitów
        int bit = 8 - ((i*5)%8); // okreslenie ile bitow nalezy dopisac
        i=0;
        while (i<bit) {
            plik_wy << "0";
            i++;
        }
        plik_wy.close();
    }

    void to_IHex(string output,int size,vector<char> dane)
    {
        fstream plik_wy;
        int i=0;
        string s(dane.begin(), dane.end()); // char[] -> string

        plik_wy.open(output,ios::out);
        while(i<size)
        {
            if (s.substr(i,5) == "00000") plik_wy << "0";
            if (s.substr(i,5) == "00001") plik_wy << "1";
            if (s.substr(i,5) == "00010") plik_wy << "2";
            if (s.substr(i,5) == "00011") plik_wy << "3";
            if (s.substr(i,5) == "00100") plik_wy << "4";
            if (s.substr(i,5) == "00101") plik_wy << "5";
            if (s.substr(i,5) == "00110") plik_wy << "6";
            if (s.substr(i,5) == "00111") plik_wy << "7";
            if (s.substr(i,5) == "01000") plik_wy << "8";
            if (s.substr(i,5) == "01001") plik_wy << "9";
            if (s.substr(i,5) == "01010") plik_wy << "A";
            if (s.substr(i,5) == "01011") plik_wy << "B";
            if (s.substr(i,5) == "01100") plik_wy << "C";
            if (s.substr(i,5) == "01101") plik_wy << "D";
            if (s.substr(i,5) == "01110") plik_wy << "E";
            if (s.substr(i,5) == "01111") plik_wy << "F";
            if (s.substr(i,5) == "10000") plik_wy << ":";
            if (s.substr(i+5,5) == "10001" && s.substr(i,5) == "10010") plik_wy << endl;

            i=i+5;

        }
    plik_wy.close();
    }


const string output = "output.txt"; // nazwa pliku wyjsciowego
int main() {


    bool choice;
    string nazwa_plik_we; // test.hex
    ifstream plik_we;

    vector<char> dane; // vector bedzie przechowywal tablice znakow zczytaną z pliku
    cout << "Podaj nazwę pliku wejsciowego"<< endl;
    cin>>nazwa_plik_we;

    plik_we.open(nazwa_plik_we, ios::binary);
    plik_we.seekg(0, ios::end);
    int size = plik_we.tellg();
    dane.resize(size);               // przygotowanie miejsca w wektorze
    plik_we.seekg(0, std::ios::beg);
    plik_we.read(&dane[0], size); // odczytanie zawartości pliku do vectora dane
    plik_we.close();                // zamkniecie pliku wejsciowego

    cout << "Wcisnij 1, aby przekonwertować z IHex do systemu binarnego lub 0 aby przekonwertować z BIN do formatu IntelHex."<<endl;
    cin>>choice;
    if(choice) to_Bin(output,size,dane);
        else to_IHex(output,size,dane);


    return 0;
}
