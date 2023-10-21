#include <iostream>
#include <bitset>

using namespace std;

int main()

{
    //=================================
    //THIS IS MY FRIST LEVEL ENCRYPTIPON
    //=================================

    //**secret arr for alg
    int arrLen = 1000;
    char arr[arrLen+1]={"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz !@#$%^&*,.;:/?abcdefghijklmnopqrstuvwxyz"};

    //newarr
    char secret[arrLen+1];


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
                    data[0] = arr[x+1]; //here 1 is the secret shifting.
                    break;
                }
            }//for 2 e

            //add to arr
            secret[i] = data[0];


        }
    }//for 1 e


    //<<<<<<<<output>>>>>>>>>>>>
    //cout << "ENC: " << secret << "\n";




    //=================================
    //THIS IS MY SECOND LEVEL ENCRYPTIPON
    //=================================
    cout << "Bainary: ";
    int c =0;
    while(secret[c]!='\0'){
        char character = secret[c];
        bitset<8> binaryRepresentation(character);
        cout << binaryRepresentation;
        c++;
    }







    //reset secret arr
    secret[0]={};

    return 0;
}

