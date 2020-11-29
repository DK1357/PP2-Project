// PP2 Client Information.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <limits>
#include <iterator>
#include <regex>
#include <vector>

using namespace std;
// structure class that stores the variables for the lines being read in the file
struct clients {
    string First_Name;
    string Last_Name;
    string clientaddress;
    string clientsales;
};

// gets the inputs for an added client vector from the addAClient function
class ClientInfo {
private:
    string firstName;
    string lastName;
    string setAddress;
    string sales;
    string var;
public:
    //mutator functions
    void SetFirstName(string first);
    void SetLastName(string last);
    void SetAddress(string address);
    void SetSales(string setSales);

    string GetFirstName();
    string GetLastName();
    string GetAddress();
    string GetSales();
    string AddVariables();
};
//sets the private variable firstName equal to the user inputted first name(first)
void ClientInfo::SetFirstName(string first) {
    cout << "Enter clients first name." << endl;
    cin >> first;
    firstName = first;
}
//sets the private variable lastName equal to the user inputted last name(last)
void ClientInfo::SetLastName(string last) {
    cout << "Enter clients last name." << endl;
    cin >> last;
    lastName = last;
}
//sets the private variable setAddress equal to the user inputted address(address)
void ClientInfo::SetAddress(string address) {
    cout << "Enter address." << endl;
    cin.ignore();
    getline(cin, address);
    setAddress = address;
}
//sets the private variable sales equal to the user inputted sales(setSales)
void ClientInfo::SetSales(string setSales) {
    cout << "Enter sales." << endl;
    cin >> setSales;
    sales = setSales;
}
//returns the value stored in the private variable(firstName)
string ClientInfo::GetFirstName() {
    return firstName;
}
//returns the value stored in the private variable(lastName)
string ClientInfo::GetLastName() {
    return lastName;
}
//returns the value stored in the private variable(setAddress)
string ClientInfo::GetAddress() {
    return setAddress;
}
//returns the value stored in the private variable(sales)
string ClientInfo::GetSales() {
    return sales;
}
//adds all the private variables together seperated by commas
//the comma seperation is necessary for the client info to be read correctly when it is added to the file
//and when the file is read again any added client information will be read correctly
string ClientInfo::AddVariables() {
    var = firstName + "," + lastName + "," + setAddress + "," + sales;
    return var;
}

void print_client_vector(vector<clients> clientlist) {
    // input: clients vector ()
    // ouput: clientlist vector
    // Loop through clientlist and print out each item in clients structure
    //   if empty record found break to avoid printing extraneous values


    //stores last name length 
    int lName_length;
    int address_Name;
    // write client header
    cout << "First Name\tLast Name\taddress\t\t\tsales\n";
    cout << "-------------------------------------------------------------\n";
    // outputs a client list with first name, last name, address, and sales
    for (unsigned int i = 0; i < clientlist.size(); i++) {
        if (clientlist[i].First_Name == "") {
            break;
        }
        //get last name's size
        lName_length = clientlist[i].Last_Name.size();
        address_Name = clientlist[i].clientaddress.size();
        //if the last name's Last_Name.size() is greater than 7 the last name gets one tab after the name
        // else the name gets two tabs after the name
        if (lName_length > 7 || address_Name > 14)
        {
            //cout << i << ":";
            // print for testing
            cout << clientlist[i].First_Name << "\t\t";
            cout << clientlist[i].Last_Name << "\t\t";
            cout << clientlist[i].clientaddress << "\t";
            cout << clientlist[i].clientsales << "\t";
            cout << endl;
        }
        else {
            //cout << i << ":";
            // print for testing
            cout << clientlist[i].First_Name << "\t\t";
            cout << clientlist[i].Last_Name << "\t\t";
            cout << clientlist[i].clientaddress << "\t\t";
            cout << clientlist[i].clientsales << "\t";
            cout << endl;
        }

    }
}

void clientSearch(vector<clients> clientsearch, string firstName, string lastName)
{
    //input: client first name and last name
    //output: the client information of that client 
    //uses the client innformation from the clients vector
    for (int i = 0; i < clientsearch.size(); i++)
    {
        if (clientsearch[i].First_Name == "")
        {
            break;
        }
        else
        {
            if (clientsearch[i].First_Name == firstName && clientsearch[i].Last_Name == lastName)
            {
                cout << clientsearch[i].First_Name << " " << clientsearch[i].Last_Name << " ";
                cout << clientsearch[i].clientaddress << " " << clientsearch[i].clientsales << endl;
            }
    
            else
            {
                break;
            }
        }
    }
    return;
}

string ChooseAFile()
{
    //input: file name
    //output: file name 

    //default file for testing
    string deffname = "PP2Tester.txt";

    string fname = "";
    cout << "Enter filename (default PP2Tester.txt): " << flush;

    //user inputs filename
    getline(cin, fname);
    // if enter pressed or input empty then use deffname
    if (fname.empty()) {
        fname = deffname;
    }
    else {
        //otherwise use what was entered
    }
    //cout << "DEBG: Got " << fname << endl;
    return fname;
}

vector<clients> AddClientToFile(vector<clients> origFile, vector<clients> addedClient  ) {
    //input: added clients vector
    //output: the clietns vector with the added clients vector included
    origFile.insert(origFile.end(), addedClient.begin(), addedClient.end());
    return origFile;
}


int main()
{
    bool debug = false;
    // chosenfile stores what file was inputted in choose a file
    string chosenFile = ChooseAFile();
    //cout << chosenFile;
    // needed to find where files were being stored 
    //system("dir"); //system("pause");

    //read = 1 line of client info read
    string read;

    // open input file filename for read    
    ifstream infile(chosenFile);

    //create a vector to hold client structure data of no more than 50 entries
    vector<clients> client(50);
    clients currentClient;

    if (infile.is_open())
    {
        if (debug == true) { cout << "DEBG: " << chosenFile << " open success." << endl; }
        // Now read each line, format is
        // Firstname LastName address sales
        string input_line;
        int loopcount = 0;  // track where we are in the loop to put into array
        //if the file does not err
        while (infile.good()) {
            // read each line and store into vector client
            // once entire file is read, close file and update client vector
            //getline reads each row and stores that into input_line which is then stored into read
            getline(infile, input_line);
            read = input_line;
            smatch regex_matches;

            stringstream ray(read);
            if (debug == true) { cout << "DGB: InputLine = " << read << endl; }
            // regex function that gets the individual variables of the string read, if they match (First Name, Last Name, address, sales)
            //The pattern in parenthesis is stored in regex_matches
            // The ^ is the start of the matching
            // The ([a-zA-Z]) means that the first part of the line has to be a word with either upper or lower case letters
            // The \\s+ designates all white space 
            // The ([a-zA-Z0-9\\s\\.\\!\\@\\?_]+) gets all letters, numbers, spaces and special characters listed so ., !, @, ?,_ 
            // The ([0-9.]+) gets any number containing the numbers 0-9 at any size, and the . matches if there is a decimal or there is not decimal 
            // The .*$ means to match everything from the start to the end
            regex regex_pattern("^([a-zA-Z]+)\\,([a-zA-Z]+)\\,([a-zA-Z0-9\\s\\.\\!\\@\\?_]+)\\,([0-9.]+).*$");
            regex_match(read, regex_matches, regex_pattern);

            client[loopcount].First_Name = regex_matches[1];
            client[loopcount].Last_Name = regex_matches[2];
            client[loopcount].clientaddress = regex_matches[3];
            client[loopcount].clientsales = regex_matches[4];

            //debug to see what input line is 
            if (debug == true) {
                cout << "DEBG: " << input_line << endl;
                cout << "DEBG:  " << client[loopcount].First_Name << endl;
                cout << "DEBG:  " << client[loopcount].Last_Name << endl;
                cout << "DEBG:  " << client[loopcount].clientaddress << endl;
                cout << "DEBG:  " << client[loopcount].clientsales << endl;
            }

            loopcount = loopcount + 1;
            //cout << endl;

        }
    }
    else {
        cout << "Error: " << chosenFile << " open failure." << endl;
    }
    //prints client vector of the original file
    print_client_vector(client);

    //start of adding clients
    ClientInfo newClient;
    vector<clients> createdClient(50);
    clients mergedClients;
    string addResponse;
    string addFirstName;
    string addLastName;
    string addAddress;
    string addSales;
    string addedClient;
    int loop = 0;
    //until user enters no will continue to ask if the user wants to add a client
    //if user enters yes they will input the first name, last name, address, and sales of the client
    while (addResponse != "No" || addResponse != "no") {
        cout << "Do you wish to add a client? Enter Yes or No" << endl;
        cin >> addResponse;
        if (addResponse == "yes" || addResponse == "Yes") {
            //all the variables inputed go though the class ClientInfo which is called newClient in main
            //calls the class functions SetFirstName, SetLastName, SetAddress, and SetSales which will input the inputs of their respective variable
            newClient.SetFirstName(addFirstName);
            newClient.SetLastName(addLastName);
            newClient.SetAddress(addAddress);
            newClient.SetSales(addSales);
            ofstream updateFile;
           // cout << "DEBG: " << newClient.AddVariables();
            //all variables get added together in the AddVariables function and is stored in addList 
            string addList = newClient.AddVariables();

            //the new client is then appended to the original filewhich is opened and closed
            updateFile.open(chosenFile, std::ios_base::app);
            updateFile << endl;
            updateFile << addList;
            updateFile.close();
        }
        if (addResponse == "No" || addResponse == "no") {
            break;
        }
    }
    
    //start of clientsearch 
    string clientsearch;
    string clientfirstN;
    string clientlastN;
    while (clientsearch != "No" || clientsearch != "no") {
        //until no is enterd will continue to ask for a client to search
        //if yes is entered will get users input of the first and last name of the client
        //this is then searched in the clientSearch function which wil return the client information if it is there
        cout << "Do you wish to search for a client? Enter Yes or No" << endl;
        cin >> clientsearch;
        if (clientsearch == "yes" || clientsearch == "Yes") {
            cout << "Enter clients first name." << endl;
            cin >> clientfirstN;
            cout << "Enter clients last name." << endl;
            cin >> clientlastN;
        }
        clientSearch(client, clientfirstN, clientlastN);
        if (clientsearch == "No" || clientsearch == "no") {
            break;
        }
    }
    
return 0;
}