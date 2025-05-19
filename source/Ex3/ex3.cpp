#include <iostream>
#include <string>
using namespace std;


class TopDownParser {
private:
    string expression;
    char current; //Current character we are working with
    int position; //Position of current character inside the expression string
    int counter; //Used for tree spacing
    bool pipe; //Used to connect Y-Z in the tree
    int pipecounter; //Used to connect Y-Z in the tree

    void G() {
        print_spaces(counter);
        if(counter == 0 ){
            cout << "   G" << endl;
        }else {
            cout << "|--G" << endl;
        }
        if (current == '(') {
            counter++;
            if(pipe){pipecounter++;}
            matchchar('(');
            print_spaces(counter);
            cout << "|--(" <<endl;
            M();
            counter--;
        } else {
            cerr << "Expected (" << endl;
            exit(EXIT_FAILURE);
        }
    }

    void M() {
        print_spaces(counter);
        cout << "|--M" <<endl;
        Y();
        Z();
    }

    void Y() {
        print_spaces(counter);
        if (current == 'a' || current == 'b') {
            cout<< "   |--Y(" << current << ")" <<endl;
            matchchar(current);

        } else if (current == '(') {
            cout << "   |--Y" <<endl;
            counter++;
            counter++;
            pipe= true;
            G();
            pipe=false;
            pipecounter=0;
            counter--;
            counter--;

        } else {
            cerr << "Expected a,b or ( not " << current << endl;
            exit(EXIT_FAILURE);
        }
    }

    void Z() {
        print_spaces(counter);
        if (current == '*' || current == '-' || current == '+') {
            cout<< "   |--Z(" << current << ")" <<endl;
            matchchar(current);
            counter++;
            if(pipe){pipecounter++;}
            M();
            counter--;
            if(pipe){pipecounter--;}
        } else if (current == '$' || current == ')') {
            cout<< "   |--Z(" << "e" << ")" <<endl;
            matchchar(')');
            print_spaces(counter);
            cout<< "   |--)" <<endl;

        } else {
            cerr << "Didn't expect " << current << endl;
            exit(EXIT_FAILURE);
        }
    }

    void matchchar(char valid){
        if(current == valid){
            if(position < expression.length()){
                current = expression[position];
                position++;
            }else{
                current = '$';
            }
        }else{
            cerr << "Expected " << valid << " not " << current << endl;
            exit(EXIT_FAILURE);
        }
    }

    void print_spaces(int amount) {
        for (int i = 0; i < amount; i++) {
            if(pipe && i == amount-1-pipecounter){
                cout << "|  ";
            }else {
                cout << "   ";
            }
        }
    }
public:
    explicit TopDownParser(string string1) : expression(string1), current('\0'), position(0) , counter(0) ,pipe(false), pipecounter(0) {}

    void parser() {
        matchchar('\0');
        G();
        if(current == '$'){
            cout << "Successfully recognized " + expression + "!";
        }else{
            cout << "Failed to recognize " + expression +"!";
        }
    }

};

int main() {
    TopDownParser parse("((a-b)*(a+b))");
    parse.parser();

    return 0;
}
