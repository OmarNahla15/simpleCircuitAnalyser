#include <iostream>
#include <string>
#include <vector>

using namespace std;

// the possible values of circuit vector is only ("p" or "s" or "e" or string as double)
int* Handle(char connection, vector<string> circuit, int start){
    int equ_R = 0;
    int i = start;
    for (; i < circuit.size(); ++i){

        // check for the 
        if(1/*to be written*/);

        //check for the end of connection "e"
        else if (circuit.at(i) == "e"){
            if (connection == 'p')
                equ_R = 1/equ_R;
            int result[2] = {equ_R, i};
            return result;
        }

        // check for the double and calculate according to the connection
        else{
            double x = stod(circuit.at(i));
            if (connection == 'p')
                equ_R += 1/x;
            else
                equ_R += x;
        }
    }
}


int main(){

    // impelmentation of the circuit
    string circuit_in;
    getline(cin, circuit_in);

    vector<string> circuit;
    string buff = "";

    for (int i = 0; i < circuit_in.length(); ++i){
        switch(circuit_in[i]){
            case 'p':
            case 'P':
                circuit.push_back("p");
            break;
            case 's':
            case 'S':
                circuit.push_back("s");
            break;
            case 'e':
                circuit.push_back("e");
            break;
            default:
                if((circuit_in[i] >= '0' && circuit_in[i] <='9') || circuit_in[i] == '.'){
                    buff += circuit_in[i];
                }
                else if(circuit_in[i] == ' ' || circuit_in[i] == ','){
                    if (circuit_in[i-1] >= '0' && circuit_in[i-1] <='9'){
                        circuit.push_back(buff);
                        buff = "";
                    }
                }
                else{
                    cout << "Fuck you bitch";
                    return 1;
                }
        }
    }
    cout << Handle(circuit_in[0], circuit, 0);
}