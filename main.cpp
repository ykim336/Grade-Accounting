// #include <iostream>
// #include <fstream>
// #include <cmath>
// #include <vector>
// #include <sstream>
// #include <string>

// using namespace std;

// void NewClass();
// void ChangePoints(string filename);
// void PrintResults(string filename);
// void PrintOptions(string filename);
// string ChangeClass();

// int main() {
//     string filename = "";
//     int option;

//     while (true) {
//         PrintOptions(filename);
//         cout << "Choose Option: ";
//         cin >> option;

//         if (option == 1) {
//             NewClass();
//             filename = ChangeClass();
//         }
//         else if (option == 2) {
//             ChangePoints(filename);
//         }
//         else if (option == 3) {
//             filename = ChangeClass();
//         }
//         else if (option == 4) {
//             PrintResults(filename);
//         }
//         else if (option == 5) {
//             break;
//         }
//     }
// }

// void NewClass () {
//     ofstream outFS;
//     string filename;

//     cout << "Filename (Add .txt at end): ";
//     cin >> filename;
//     cout << endl << endl;

//     outFS.open(filename);
//     if (!outFS.is_open()) {
//         cout << "Error: 2" << endl;
//         return;
//     }

//     cout << "IMPORTANT: DO NOT ADD SPACES IN INPUTS" << endl;
//     char confirmation = '~';

//     string className;
//     do {
//         cout << "Class Name: ";
//         cin >> className;
//         cout << "[Answer: " << className << "] Confirm? (Y/N): ";
//         cin >> confirmation;
//         cout << endl;

//     } while (confirmation == 'N' || confirmation == 'n');

//     int unitMax;
//     do {
//         cout << "Total Units of Class: ";
//         cin >> unitMax;
//         cout << "[Answer: " << unitMax << "] Confirm? (Y/N): ";
//         cin >> confirmation;
//         cout << endl;

//     } while (confirmation == 'N' || confirmation == 'n');

//     string className;
//     do {
//         cout << "Class Name: ";
//         cin >> className;
//         cout << "[Answer: " << className << "] Confirm? (Y/N): ";
//         cin >> confirmation;
//         cout << endl;

//     } while (confirmation == 'N' || confirmation == 'n');

//     vector<string> gradeSectionName;
//     string currName;
//     char cont = '~';
//     while (cont != 'y' || cont != 'Y') {
//         do {
//             cout << "Section Name: ";
//             cin >> currName;
//             cout << "[Answer: " << currName << "] Confirm? (Y/N): ";
//             cin >> confirmation;
//             cout << endl;

//         } while (confirmation == 'N' || confirmation == 'n');
//         gradeSectionName.push_back(className);
//         cout << "Continue? (Y/N): ";
//         cin >> cont;
//         cout << endl;
//     }

    
//     for (unsigned i = 0; i < gradeSectionName.size(); ++i) {
//         cout << "For " << gradeSectionName.at(i) << endl;
//         while (cont != 'y' || cont != 'Y') {
//             do {

//             } while (confirmation == 'N' || confirmation == 'n');
            
//         }
//     }
// }

// void ChangePoints(string filename) {
//     //FIXME
// }

// void PrintResults(string filename) {
//     ifstream inFS;
//     inFS.open(filename);

//     if (!inFS.is_open()) {
//         cout << "Error: 3" << endl;
//         return;
//     }

//     string className, tempString, tempVal2;
//     istringstream tempSS;
//     int unitEarned, unitUsed, unitMax, tempVal;
//     vector<int> gradePercentage, gradeSectionMax;
//     vector<string> gradeSectionName;
//     vector<vector<int>> gradeSectionEarned, gradeSectionUsed;
//     vector<string> gradeNames = {"F", "D", "C-", "C", "C+", "B-", "B", "B+", "A-", "A", "A+"};


// // GETTING BASIC INPUT

//     // Basic input
//     inFS >> className;
//     inFS >> unitEarned >> unitUsed >> unitMax;
    

//     // A+, A, A- ...
//     tempString = "";
//     getline(inFS, tempString);
//     tempSS.str(tempString);

//     while (tempSS >> tempVal) {
//         gradePercentage.push_back(tempVal);
//     }

//     // Labs, Final, Etc.
//     tempString = "";
//     getline(inFS, tempString);
//     tempSS.str(tempString);

//     while (tempSS >> tempString) {
//         gradeSectionName.push_back(tempString);
//     }

//     for (unsigned i = 0; i < gradeSectionName.size(); ++i) {
        
//         // Earned So Far
//         tempString = "";
//         getline(inFS, tempString);
//         tempSS.str(tempString);

//         while (tempSS >> tempVal2) {
//             gradeSectionEarned.at(i).push_back(stoi(tempVal2));
//         }

//         // Used So Far
//         tempString = "";
//         getline(inFS, tempString);
//         tempSS.str(tempString);

//         while (tempSS >> tempVal2) {
//             gradeSectionUsed.at(i).push_back(stoi(tempVal2));
//         }

//         // Max So Far
//         inFS >> tempVal2;
//         gradeSectionMax.push_back(stoi(tempVal2));
//     }

// // ARITHMETICS

//     // Grades
//     double grade = (unitEarned / (unitUsed * 1.0)) * 100;
//     double progress = (unitUsed / (unitMax * 1.0)) * 100;

//     vector<int> earnedSum, usedSum;

//     vector<double> gradeSectionPercentage;
//     for (unsigned i = 0; i < gradeSectionEarned.size(); ++i) {
//         earnedSum.push_back(0);
//         usedSum.push_back(0);
//         for (unsigned j = 0; j < gradeSectionEarned.at(i).size(); ++j) {
//             earnedSum.at(i) += gradeSectionEarned.at(i).at(j);
//             usedSum.at(i) += gradeSectionUsed.at(i).at(j);
//         }

//         gradeSectionPercentage.push_back((earnedSum.at(i) / (usedSum.at(i) * 1.0)) * 100);
//     }

//     vector<double> gradeSectionProgress;
//     for (unsigned i = 0; i < gradeSectionEarned.size(); ++i) {
//         gradeSectionProgress.push_back((usedSum.at(i) * 1.0) / gradeSectionMax.at(i));
//     }

//     unsigned index; 
//     for (index = 0; index < gradePercentage.size() - 1; ++index) {
//         if (grade < gradePercentage.at(index + 1)) {
//             break;
//         }
//     }

//     // ACTUAL REPORT
//     cout << "REPORT \n" << 
//         "--------------------- \n\n" << 
//         "CLASS: " << className << endl << endl << 
//         "TOTAL GRADE : " << gradeNames.at(index) << " or " << grade << "% " << endl <<
//         "TOTAL PROGRESS : " << progress << "% " << endl <<
//         "SECTION GRADES :" << endl;
            

//     for (unsigned i = 0; i < gradeSectionName.size(); ++i) {
//         cout << "   " << gradeSectionName.at(i) << " : " << endl << 
//         "       " << "[Grade]: " << gradeSectionPercentage.at(i) << "%" << endl <<
//         "       " << "[Points]: " << earnedSum.at(i) << " out of " << usedSum.at(i) << endl <<
//         "       " << "[Progress]: " << gradeSectionProgress.at(i) << "%" << endl;
//     }

//     cout << endl << "ASSIGMENTS: " << endl;

//     for (unsigned i = 0; i < gradeSectionName.size(); ++i) {
//         cout << "   " << gradeSectionName.at(i) << " : " << endl;
//         for (unsigned j = 0; j < gradeSectionName.size(); ++j) {
//             // gradeSectionEarned.at(i) gradeSectionUsed.at(i)
//             cout << "       " << j + 1 << ": " << gradeSectionEarned.at(i).at(j) << 
//             " out of " << gradeSectionUsed.at(i).at(j) << endl;
//         }
//     }

//     cout << endl << "END OF REPORT." << endl;

//     inFS.close();
// }

// void PrintOptions(string filename) {
//     string className;

//     if (filename != "") {
//         ifstream inFS;
//         inFS.open(filename);

//         if (!inFS.is_open()) {
//             cout << "Error: 1" << endl;
//             return;
//         }

//         inFS >> className;
//         inFS.close();
//     }
//     else {
//         className = "None";
//     }

//     cout << "CLASS: " << className << endl << endl;

//     cout << "OPTIONS \n" <<
//             "--------------------- \n\n" << 
//             "1: New Class \n" << 
//             "2: Add/Subtract Points \n" <<
//             "3: Change Class \n" << 
//             "4: Print Report \n" <<
//             "5: Quit \n";

    
// }

// string ChangeClass() {
//     string filename = "";

//     cout << "New Filename: ";
//     cin >> filename;
//     cout << endl;

//     return filename;
// }