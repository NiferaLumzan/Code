#include <string>
#include <vector>
#include <iostream>
#include<typeinfo>

using namespace std;

// String to int converter by utilizing intra spaces
vector<int> strToInt(string s){
    vector<int> c;
    bool flagMinus = false;
    for(auto x: s){
        if(x == ' ')
            continue;
        else{
            if(x == '-'){
                flagMinus = true;
                continue;
            }
            if(flagMinus){
                int k = x-'0';
                c.push_back(-k);
                flagMinus = false;
            }
            else{
                c.push_back(x-'0');
            }

        }
    }
    return c;
}

void horner(vector<int> co, int x)
{
    int result = co[0]; // Initialize result
    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<co.size(); i++)
        result = (result*x) + co.at(i);

    cout << result << " ";
//    return result;
}

int main(){

    string line;
    vector<string> inputLines;

    //getting multiple lines from user in console
    while(std::getline(cin, line)){
        if (line.empty()){
            break;
        }
        inputLines.push_back(line);
    }

    vector<int> c;
    vector<int> x;

    /*Pair of lines are selected and first one take as Coefficient set
      and second one take as value set of x.
    */
    if(inputLines.size()%2 == 0 && inputLines.size()>0){
        for(int i = 0;  i < inputLines.size(); i++){
            if(i%2 == 0)
                c = strToInt(inputLines.at(i)); // Coefficient set
            else{
                x = strToInt(inputLines.at(i)); // Value of x set
                for(int i = 0; i<x.size(); i++){
//                        cout << "x: " << x.at(i) << endl; // << ": " << typeid(c.at(i)).name() << endl;
                        horner(c,x.at(i));
                    }
                    cout << endl;
                }
            } // end of test cases
        }

    return 0;
}
