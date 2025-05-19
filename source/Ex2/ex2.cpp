#include <iostream>
#include <stdlib.h> //Καρφωτά
#include <time.h> //Καρφωτά
#include <string>
#include <vector>
using namespace std;



bool checkForZ(string s){
    bool hasIt = false;
    for (char c : s) { //Με τη σειρά τα γράμματα τα παίρνει από αριστερά προς τα δεξιά
        if (c == 'Z') {
            hasIt = true;
        }
    }
    return hasIt;
}

bool checkForK(string s){
    bool hasIt = false;
    for (char c : s) { //Με τη σειρά τα γράμματα τα παίρνει από αριστερά προς τα δεξιά
        if (c == 'K') {
            hasIt = true;
        }
    }
    return hasIt;
}

bool checkForG(string s){
    bool hasIt = false;
    for (char c : s) { //Με τη σειρά τα γράμματα τα παίρνει από αριστερά προς τα δεξιά
        if (c == 'G') {
            hasIt = true;
        }
    }
    return hasIt;
}

bool checkForM(string s){
    bool hasIt = false;
    for (char c : s) { //Με τη σειρά τα γράμματα τα παίρνει από αριστερά προς τα δεξιά
        if (c == 'M') {
            hasIt = true;
        }
    }
    return hasIt;
}

int countCharacter(string str, char target) {
    int count = 0;
    for (char ch : str) {
        if (ch == target) {
            count++;
        }
    }
    return count;
}

//Βρίσκει τη 2η πχ θέση στο string που εμφανίζεται ο χαρακτήρας Κ
int positionOfTheCharacterInMyString(string str, char target,int whatOccurrence){
    int count = 0;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == target) {
            count++;

            if (count == whatOccurrence) {
                return i; // Return the position of the xth occurrence
            }
        }
    }
    return -10; //Αν και πότε δε θα γίνει αυτό
}

int chooseWhichProductionRuleToDo(string s1){
    int whatItChose = 0; //Σε περίπτωση που δεν υπάρχει μη-τελικό σύμβολο
    bool isThereZ = checkForZ(s1);
    bool isThereK = checkForK(s1);
    bool isThereG = checkForG(s1);
    bool isThereM = checkForM(s1);
    bool isThereAtLeastOne = isThereZ || isThereK || isThereG || isThereM; //

    // Declare an empty vector of integers
    vector<int> myVector;

    //ΑΝΑΛΟΓΑ ΜΕ ΤΟ ΤΙ ΕΧΩ ΣΤΗ ΛΕΞΗ ΜΟΥ ΠΡΟΣΘΕΤΩ ΣΤΟ VECTOR ΤΟΥΣ ΔΙΑΘΕΣΙΜΟΥΣ ΚΑΝΌΝΕΣ ΠΟΥ ΜΠΟΡΩ ΝΑ ΕΦΑΡΜΟΣΩ
    if (isThereZ) {
        // Add the numbers to the vector
        myVector.push_back(1);
    }

    if (isThereK) {
        // Add the numbers to the vector
        myVector.push_back(2);
    }

    if (isThereG) {
        // Add the numbers to the vector
        myVector.push_back(3);
        myVector.push_back(4);
    }

    if (isThereM) {
        // Add the numbers to the vector
        myVector.push_back(5);
        myVector.push_back(6);
        myVector.push_back(7);
    }

    int sizeOfMyVector = myVector.size();

    if (isThereAtLeastOne) {
        int index = rand()%sizeOfMyVector; //Το rand()%sizeOfMyVector θα μου επιστρέψει έναν αριθμό από το 0
        // μέχρι rand()%sizeOfMyVector-1

        // Index 0 for the first element
        //Index 1 for the second element


        whatItChose =  myVector[index]; //Επιλέγω 1 κανόνα

    }

    /*
    for (int num : myVector) {
        std::cout << num << " ";
    }
    */

    return whatItChose;
}

int main() {
    srand(time(NULL)); //Καρφωτά χρειάζεται για να βγάζει διαφορετικά ανάλογα με την ώρα


    string myWord="Z"; //Αρχικό σύμβολο
    int count = 0; //Για να το αναγκάσω να μην ξεπεράσει ένα πολύ μεγάλο όριο
    bool forced=false;

    cout<<endl;
    while (true) {
        count++;
        if (count==1){
            cout<<"Arxiko symbolo Z\n";
        }
        cout<<myWord<<endl<<endl;
        if(count == 20){
            forced=true;
            break;
        } else { //Κάνω τη διαδικασία στην αρχή χωρίς να έχω θέμα με τις φορές

            int theRuleIAmAboutToPerform = chooseWhichProductionRuleToDo(myWord);
            if (theRuleIAmAboutToPerform == 0) {
                break; //Μπορεί και κατευθείαν (από την αρχή να μην είχα μη-τελικό σύμβολο) ή και μετά από την εκτέλεση κάποιων κανόνων παραγωγής
            } else {
                int iHaveThisManyCharactersInsideMyWord;
                int randomOccurrence;

                if (theRuleIAmAboutToPerform == 1) { //Το Ζ θα γίνει (Κ)
                    iHaveThisManyCharactersInsideMyWord = countCharacter(myWord, 'Z');
                    //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
                    randomOccurrence = 1 + rand() % iHaveThisManyCharactersInsideMyWord;
                    int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'Z',
                                                                                                       randomOccurrence);

                    //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
                    if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                        myWord = "(K)" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
                    } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                        myWord = myWord.substr(0, myWord.size() - 1) + "(K)";
                    } else { //Κάπου ενδιάμεσα
                        myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "(K)" +
                                 myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                               myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                    }
                    cout<<"Antikatashash toy "<<randomOccurrence<<"ou Z me (K)"<<endl;

                } else if (theRuleIAmAboutToPerform == 2) { //Το Κ θα γίνει GM
                    iHaveThisManyCharactersInsideMyWord = countCharacter(myWord, 'K');
                    //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
                    randomOccurrence = 1 + rand() % iHaveThisManyCharactersInsideMyWord;
                    int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'K',
                                                                                                       randomOccurrence);

                    //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
                    if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                        myWord = "GM" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
                    } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                        myWord = myWord.substr(0, myWord.size() - 1) + "GM";
                    } else { //Κάπου ενδιάμεσα
                        myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "GM" +
                                 myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                               myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                    }
                    cout<<"Antikatashash toy "<<randomOccurrence<<"ou K me GM"<<endl;

                } else if (theRuleIAmAboutToPerform == 3 || theRuleIAmAboutToPerform == 4) {
                    if (theRuleIAmAboutToPerform == 3) { //To G θα γίνει v
                        iHaveThisManyCharactersInsideMyWord = countCharacter(myWord, 'G');
                        //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
                        randomOccurrence = 1 + rand() % iHaveThisManyCharactersInsideMyWord;
                        int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'G',
                                                                                                           randomOccurrence);

                        //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
                        if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                            myWord = "v" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
                        } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                            myWord = myWord.substr(0, myWord.size() - 1) + "v";
                        } else { //Κάπου ενδιάμεσα
                            myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "v" +
                                     myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                                   myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                        }
                        cout<<"Antikatashash toy "<<randomOccurrence<<"ou G me v"<<endl;
                    } else if (theRuleIAmAboutToPerform == 4) {//To G θα γίνει Z
                        iHaveThisManyCharactersInsideMyWord = countCharacter(myWord, 'G');
                        //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
                        randomOccurrence = 1 + rand() % iHaveThisManyCharactersInsideMyWord;
                        int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'G',
                                                                                                           randomOccurrence);

                        //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
                        if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                            myWord = "Z" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
                        } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                            myWord = myWord.substr(0, myWord.size() - 1) + "Z";
                        } else { //Κάπου ενδιάμεσα
                            myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "Z" +
                                     myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                                   myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                        }
                        cout<<"Antikatashash toy "<<randomOccurrence<<"ou G me Z"<<endl;
                    }


                } else if (theRuleIAmAboutToPerform == 5 || theRuleIAmAboutToPerform == 6 ||
                           theRuleIAmAboutToPerform == 7) {
                    if (theRuleIAmAboutToPerform == 5) { //To M θα γίνει -K
                        iHaveThisManyCharactersInsideMyWord = countCharacter(myWord, 'M');
                        //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
                        randomOccurrence = 1 + rand() % iHaveThisManyCharactersInsideMyWord;
                        int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'M',
                                                                                                           randomOccurrence);

                        //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
                        if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                            myWord = "-K" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
                        } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                            myWord = myWord.substr(0, myWord.size() - 1) + "-K";
                        } else { //Κάπου ενδιάμεσα
                            myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "-K" +
                                     myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                                   myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                        }
                        cout<<"Antikatashash toy "<<randomOccurrence<<"ou M me -K"<<endl;
                    } else if (theRuleIAmAboutToPerform == 6) {//To M θα γίνει +K
                        iHaveThisManyCharactersInsideMyWord = countCharacter(myWord, 'M');
                        //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
                        randomOccurrence = 1 + rand() % iHaveThisManyCharactersInsideMyWord;
                        int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'M',
                                                                                                           randomOccurrence);

                        //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
                        if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                            myWord = "+K" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
                        } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                            myWord = myWord.substr(0, myWord.size() - 1) + "+K";
                        } else { //Κάπου ενδιάμεσα
                            myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "+K" +
                                     myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                                   myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                        }
                        cout<<"Antikatashash toy "<<randomOccurrence<<"ou M me +K"<<endl;
                    } else if (theRuleIAmAboutToPerform == 7) {//To M θα γίνει ε
                        iHaveThisManyCharactersInsideMyWord = countCharacter(myWord, 'M');
                        //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
                        randomOccurrence = 1 + rand() % iHaveThisManyCharactersInsideMyWord;
                        int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'M',
                                                                                                           randomOccurrence);

                        //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
                        if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                            myWord = myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
                        } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                            myWord = myWord.substr(0, myWord.size() - 1);
                        } else { //Κάπου ενδιάμεσα
                            myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) +
                                     myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                                   myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                        }
                        cout<<"Antikatashash toy "<<randomOccurrence<<"ou M me keno"<<endl;
                    }
                }
            }
        }






    }

    if (forced){ //Στην ουσία αυτό που κάνω είναι ενώ πριν το G το άφηνα να αντικατασταθεί με v ή Ζ και το Μ με -Κ ή +Κ
        // ή ε τώρα το G μόνο με v και το Μ μόνο με ε έτσι ώτσε να επιλέγει μόνο τερματικά σύμβολα για να σταματήσει
        //κάποια στιγμή η διαδικασία


        //ΠΡΕΠΕΙ με αυτήν τη σειρά
        //cout<<"Whats left after force:"<<myWord<<endl;

        //Βγάζω πρώτα τα Z
        while (checkForZ(myWord)){
            //cout<<"Removing remaining Z:\n";
            int howManyLeft= countCharacter(myWord,'Z');
            //cout<<"I have this many Z remaining "<<howManyLeft<<endl;



            //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
            int randomOccurrence = 1 + rand() % howManyLeft;
            int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'Z',
                                                                                                   randomOccurrence);

            //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
            if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                myWord = "(K)" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
            } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                myWord = myWord.substr(0, myWord.size() - 1) + "(K)";
            } else { //Κάπου ενδιάμεσα
                myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "(K)" +
                        myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                      myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
            }
            cout<<"Antikatashash toy "<<randomOccurrence<<"ou Z me (K)"<<endl;
            cout<<myWord<<endl<<endl;
            }



        //Μετά τα K
        while (checkForK(myWord)){
            //cout<<"Removing remaining K:\n";
            int howManyLeft= countCharacter(myWord,'K');
            //cout<<"I have this many K remaining "<<howManyLeft<<endl;


            //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
            int randomOccurrence = 1 + rand()%howManyLeft;
            int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'K',
                                                                                                   randomOccurrence);

            //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
            if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                myWord = "GM" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
            } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                myWord = myWord.substr(0, myWord.size() - 1) + "GM";
            } else { //Κάπου ενδιάμεσα
                myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "GM" +
                        myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                      myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
            }
            cout<<"Antikatashash toy "<<randomOccurrence<<"ou K me GM"<<endl;
            cout<<myWord<<endl<<endl;
            }




        //Μετά τα G
        while(checkForG(myWord)){
            //cout<<"Removing remaining G:\n";
            int howManyLeft= countCharacter(myWord,'G');
            //cout<<"I have this many G remaining "<<howManyLeft<<endl;


            //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
            int randomOccurrence = 1 + rand() % howManyLeft;
            int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'G',
                                                                                                   randomOccurrence);

            //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
            if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                myWord = "v" + myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
            } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                myWord = myWord.substr(0, myWord.size() - 1) + "v";
            } else { //Κάπου ενδιάμεσα
                myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) + "v" +
                        myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                      myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                }
            cout<<"Antikatashash toy "<<randomOccurrence<<"ou G me v"<<endl;
            cout<<myWord<<endl<<endl;

        }


        while(checkForM(myWord)){
            //cout<<"Removing remaining M:\n";
            int howManyLeft= countCharacter(myWord,'M');
            //cout<<"I have this many M remaining "<<howManyLeft<<endl;


            //Διαλέγω έναν τυχαίο από αυτούς τους μη-τελικούς χαρακτήρες
            int randomOccurrence = 1 + rand() % howManyLeft;
            int thePositionOfThatRandomOccurrenceInMyString = positionOfTheCharacterInMyString(myWord, 'M',
                                                                                               randomOccurrence);

            //ΠΑΙΡΝΩ ΠΕΡΙΠΤΩΣΕΙΣ ΓΙΑ ΤΟ ΠΟΥ ΒΡΙΣΚΕΤΑΙ
            if (thePositionOfThatRandomOccurrenceInMyString == 0) { //Αρχή
                myWord = myWord.substr(1, myWord.size() - 1); //Άρα μόνο το πρώτο αλλάζει
            } else if (thePositionOfThatRandomOccurrenceInMyString == myWord.size() - 1) { //Τέλος
                myWord = myWord.substr(0, myWord.size() - 1);
            } else { //Κάπου ενδιάμεσα
                myWord = myWord.substr(0, thePositionOfThatRandomOccurrenceInMyString) +
                        myWord.substr(thePositionOfThatRandomOccurrenceInMyString + 1,
                                      myWord.size() - thePositionOfThatRandomOccurrenceInMyString);
                }
            cout<<"Antikatashash toy "<<randomOccurrence<<"ou M me keno"<<endl;
            cout<<myWord<<endl<<endl;
            }







    }












}