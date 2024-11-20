#include <iostream>
#include <string>
#include <vector>

using namespace std;

int itr = 1;

// the possible values of circuit vector is only ("p" or "s" or "e" or string as double)
double Handle(string connection, vector<string> circuit){
    double equ_R = 0;
    for (; itr < circuit.size(); ++itr){

        // check for the next connection
        if (circuit.at(itr) == "p" || circuit.at(itr) == "s"){
            double temp = Handle(circuit.at(itr++), circuit);
            if (connection == "p")
                equ_R += 1/temp;
            else 
                equ_R += temp;
        }

        //check for the end of connection "e"
        else if (circuit.at(itr) == "e"){
            if (connection == "p")
                equ_R = 1/equ_R;
            return equ_R;
        }

        // check for the double and calculate according to the connection
        else{
            double x = stod(circuit.at(itr));
            if (connection == "p")
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
    double result = Handle(circuit.at(0), circuit);
    cout << result;
}