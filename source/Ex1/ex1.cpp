#include <iostream>
#include <stack>
using namespace std;

class DeterministicStackAutomaton {
private:
    stack<char> charStack;
    string state = "q0";
public:
    bool recognizeExpression(const string& expression) {

        if(expression.empty()){return false;}
        string input = expression;
        cout << "Recognizing expression: " << expression << endl;
        cout << "Stack_Size  State  Input" <<endl;

        for (char c : expression) {
            if (c == 'x') {
                if(charStack.empty()){state = "q0";}
                charStack.push(c);
                input = input.substr(1); //Delete the first character 
                cout << "   " << to_string(charStack.size()) << "         " << state << "  " << input << endl;

            } else if (c == 'y' && !charStack.empty()) {
                charStack.pop();
                if(charStack.empty()){state = "q1";}
                input = input.substr(1);
                cout << "   " << to_string(charStack.size()) << "         " << state << "  " << input << endl;

            } else if(c == 'y') {
                cout << "Rejected - From left to right there are more y's than x's at this point" << endl;
                return false;
            }else {
                cout << "Rejected - Invalid Character" << endl;
                return false;
            }
        }


        if (state == "q1") {
            cout << "Expression Accepted" << endl;
            return true;
        } else {
            cout << "Rejected - There are more x's than y's" << endl;
            return false;
        }
    }
};

int main() {
    DeterministicStackAutomaton automaton;
    string expression = "xxxyyyxyx";

    if (automaton.recognizeExpression(expression)) {
        cout << "Recognition Successful" << endl;
    } else if(expression.empty()) {
        cout << "Expression is empty" << endl;
    }
    else {
        cout << "Recognition Failed" << endl;
    }


    return 0;
}