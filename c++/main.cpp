#include <iostream>
#include <bitset>

using namespace std;

int main()

{
    cout << "=======================================================\n";
    cout <<"                        ArmorCrypt\n";
    cout <<"                   Make your data secret\n";
    cout << "=======================================================\n";

    //=================================
    //THIS IS FRIST LEVEL ENCRYPTIPON
    //=================================

    //**secret arr for alg
    int arrLen = 1000;
    char arr[arrLen+1]={"ABCDEFGHIJKLMN12345abcdefghijklmnopqrstuvwxyzOPQRSTUVWXYZ67890abcdefghijklmnopqrstuvwxyz !@#$%^&*,.;:/?abcdefghijklmnopqrstuvwxyz"};

    //secret arr
    char secret[arrLen+1];
    //decima arr
    int decimaArr[arrLen+1];

    // Message input as a array.
    int msgArrLen =1000;
    char message[msgArrLen+1];
    cout << "Write your message => ";
    cin.getline(message, msgArrLen);

    //for 1 s
    int i;
    for(i=0; i < sizeof(message);++i){

        //shiftData
        char data[1];

        if(message[i] == '\0'){
            break;
        }else{
            //for 2 s
            for(int x =0; x < sizeof(arr); x++){
                if(arr[x] == message[i]){
                    data[0] = arr[x+3]; //here 3 is the secret shifting.
                    break;
                }
            }//for 2 e
            //add to secret arr
            secret[i] = data[0];
        }
    }//for 1 e

    //<<<<<<<<output>>>>>>>>>>>>
    cout << "\n";
    cout << "\n";
    cout << "[+] FRIST LEVEL ENCRYPTIPON: \n" << secret;
    cout << "\n";
    cout << "\n";

    //=================================
    //THIS IS SECOND LEVEL ENCRYPTIPON
    //=================================

    int c=0;
    while(secret[c]!='\0'){
        char character = secret[c];
        // CONVART TO DECIMAL
        int decimalValue = static_cast<int>(character);
        //add to decimaArr
         decimaArr[c] = decimalValue*3;//here 3 is the secret shifting.
        c++;
    }


    //<<<<<<<<output>>>>>>>>>>>>
    cout << "=================================\n\n";
    cout << "[+] SECOND LEVEL ENCRYPTIPON: \n";
    int x=0;
    while(decimaArr[x]!='\0'){
        cout << decimaArr[x];
        x++;
    }
    cout << "\n";
    cout << "\n";


    //=================================
    //THIS IS THIRD LEVEL ENCRYPTIPON
    //=================================
    cout << "=================================\n\n";
    cout << "[+] THIRD LEVEL ENCRYPTIPON: \n";
    int u=0;
    while(decimaArr[u]!='\0'){
        int decimalNumber = decimaArr[u];
        bitset<9> binary(decimalNumber);
        string b_n = binary.to_string();
        cout << (stoi(b_n)+3)*3;//<<<<<<<<output>>>>>>>>>>>>
        u++;
    }



    //reset secret arr
    secret[0]={};

    return 0;
}

