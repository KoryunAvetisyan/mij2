#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Crypto {
public:    
  void templateMethod(string, int, int);
  void rowColumnMethod(string, int, int);
  void rle(string, int);
};

void Crypto::templateMethod(string msg, int key, int choice) {
   if(choice == 1) {
      char ch;
      for(int i = 0; i < msg.length(); ++i) {
         ch = msg[i];
         if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
               ch = ch - 'z' + 'a' - 1;
            }  
            msg[i] = ch;
         } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z'){
               ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
         }
      }
      cout << "Encrypted message - " << msg;
   } else if(choice == 2) {
      char ch;
      for(int i = 0; i < msg.length(); ++i) {
         ch = msg[i];
         if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a') {
               ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
         } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
               ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
         }
      }
      cout << "Decrypted message - " << msg;
   }
}
void Crypto::rowColumnMethod(string msg, int n, int choice) {
    if(choice == 1) {
        int i, j, m = 0;
        char mat[n][n];
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(m < msg.length()) {
                    mat[i][j] = msg[m];
                } else {
                    mat[i][j] = '\0';
                }
                m++;
            }
        }        
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cout << mat[i][j] << "  ";
            }
            cout << endl;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(mat[j][i] != '\0') {
                    cout << mat[j][i];
                }else {
                    cout << '_';
                }
            }
        }
    } else if (choice == 2) {
        int i, j, m = 0;
        char mat[n][n];
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(m < msg.length()) {
                    mat[j][i] = msg[m];
                } else {
                    mat[j][i] = '\0';
                }
                m++;
            }
        }        
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cout << mat[j][i] << "  ";
            }
            cout << endl;
        }
        for(j = 0; j < n; j++) {
            for(i = 0; i < n; i++) {
                if(mat[j][i] != '\0') {
                    cout << mat[j][i];
                } else {
                    cout << '_';
                }
            }
        }
    }
}
void Crypto::rle(string str, int choice) {
    if(choice == 1) {
        int n = str.length();
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i < n - 1 && str[i] == str[i + 1]) {
                count++;
                i++;
            }
            cout << count << str[i];
        }
    } else if(choice == 2) {
        int i = 0;
        string ans = "";
        int n = str.length();
        while (i < n) {
            int j = i;
            while (isdigit(str[j]) && (j < n)) {
                j++;
            }
            int a = stoi(str.substr(i, j - i + 1));
            int k = j;
            while (isalpha(str[k]) && k < n) {
                k++;
            }
            auto t = str.substr(j, k - j);
            for (int k = 0; k < a; ++ k) {
                ans += t;
            }
            i = k;
        }
        cout << ans;
    }
}

int main() {
    Crypto o;
    int chooseMethod;
    cout << "Choose the method\n1. Template Method \n2. Row/Column Method \n3. RLE \n";
    cin >> chooseMethod;
    if(chooseMethod == 1) {
        int choice, key;
        
        // char message[100];
        // cout << "Enter the message - ";
        // cin.getline(message, 100);
        
        cout << "Enter the key - ";
        cin >> key;
        cout << "1. Encryption \n2. Decryption \n";
        cin >> choice;
        
        // o.templateMethod(message, key, choice);
        
        o.templateMethod("khoor zruog", key, choice);
    }
    if(chooseMethod == 2) {
        int choice, n;
        
        // char message[100];
        // cout << "Enter the message - ";
        // cin.getline(message, 100);
        // string msg = message;
        string msg = "hello world";
        
        cout << "Enter the size of square matrix - ";
        cin >> n;
        cout << "1. Encryption \n2. Decryption \n";
        cin >> choice;
        o.rowColumnMethod(msg, n, choice);
    }
    if(chooseMethod == 3) {
        int choice;
        
        // string str;
        // cout << "Enter the text - ";
        // getline(cin, str);
        
        cout << "1. Encryption \n2. Decryption \n";
        cin >> choice;
        o.rle("3B4A", choice);
    }
    return 0;
}