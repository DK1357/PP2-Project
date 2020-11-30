// PP2 Sales.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
struct Sales {
    string First_Name;
    string Last_Name;
    string Month1;
    string Month2;
    string Month3;
    string Month4;
    string Month5;
    string Month6;
    string Month7;
    string Month8;
    string Month9;
    string Month10;
    string Month11;
    string Month12;
};

struct Products {
    string product;
    int price;
};

void print_product_vector(vector<Products> productlist) {
    // input: Products vector ()
    // ouput: productlist vector
    // Loop through productlist and print out each item in product structure
    //   if empty record found break to avoid printing extraneous values


    //stores products length 
    int ProductName_length;
    // write client header
    cout << "Product/Service\t\tPrice\n";
    cout << "------------------------------------------------------------------------\n";
    // outputs product/services name, and price
    for (unsigned int i = 0; i < productlist.size(); i++) {
        if (productlist[i].product == "") {
            break;
        }
        //get last name's size
        ProductName_length = productlist[i].product.size();
        //if the product name's size is greater than 7 the product name gets one tab after the name
        // else the product name gets two tabs after the name
        if (ProductName_length > 7)
        {
            //cout << i << ":";
            // print for testing
            cout << productlist[i].product << "\t\t";
            cout << productlist[i].price << "\t";
            cout << endl;
        }
        else {
            //cout << i << ":";
            // print for testing
            cout << productlist[i].product << "\t\t\t";
            cout << productlist[i].price << "\t";
            cout << endl;
        }

    }
}

void print_sales_vector(vector<Sales> salelist) {
    // input: Sales vector ()
    // ouput: salelist vector
    // Loop through studentlist and print out each item in student structure
    //   if empty record found break to avoid printing extraneous values


    //stores last name length 
    int lName_length;
    int address_Name;
    // write client header
    cout << "First Name\tLast Name\tJanuary\t\tFebruary\tMarch\tApril\tMay\tJune\tJuly\tAugust\t\tSeptember\tOctober\t\tNovemeber\tDecember\n";
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    // outputs clients first name, last name, and sales for every month
    for (unsigned int i = 0; i < salelist.size(); i++) {
        if (salelist[i].First_Name == "") {
            break;
        }
        //get last name's size
        lName_length = salelist[i].Last_Name.size();
        //if the last name's Last_Name.size() is greater than 7 the last name gets one tab after the name
        // else the name gets two tabs after the name
        if (lName_length > 7)
        {
            //cout << i << ":";
            // print for testing
            cout << salelist[i].First_Name << "\t\t";
            cout << salelist[i].Last_Name << "\t";
            cout << salelist[i].Month1 << "\t\t";
            cout << salelist[i].Month2 << "\t\t";
            cout << salelist[i].Month3 << "\t";
            cout << salelist[i].Month4 << "\t";
            cout << salelist[i].Month5 << "\t";
            cout << salelist[i].Month6 << "\t";
            cout << salelist[i].Month7 << "\t";
            cout << salelist[i].Month8 << "\t\t";
            cout << salelist[i].Month9 << "\t\t";
            cout << salelist[i].Month10 << "\t\t";
            cout << salelist[i].Month11 << "\t\t";
            cout << salelist[i].Month12 << "\t";
            cout << endl;
        }
        else {
            //cout << i << ":";
            // print for testing
            cout << salelist[i].First_Name << "\t\t";
            cout << salelist[i].Last_Name << "\t\t";
            cout << salelist[i].Month1 << "\t\t";
            cout << salelist[i].Month2 << "\t\t";
            cout << salelist[i].Month3 << "\t";
            cout << salelist[i].Month4 << "\t";
            cout << salelist[i].Month5 << "\t";
            cout << salelist[i].Month6 << "\t";
            cout << salelist[i].Month7 << "\t";
            cout << salelist[i].Month8 << "\t\t";
            cout << salelist[i].Month9 << "\t\t\t";
            cout << salelist[i].Month10 << "\t\t";
            cout << salelist[i].Month11 << "\t\t";
            cout << salelist[i].Month12 << "\t";
            cout << endl;
        }

    }
}


string ChooseAFile()
{
    //input: file name
    //output: file name 

    //default file for testing
    string deffname = "SalesTester.txt";

    string fname = "";
    cout << "Enter filename (default SalesTester.txt): " << flush;

    //user inputs filename
    getline(cin, fname);
    // if enter pressed or input empty then use deffname
    if (fname.empty()) {
        fname = deffname;
    }
    else {
        //otherwise use what was entered
    }
    cout << "DEBG: Got " << fname << endl;
    return fname;
}

void BuyaProduct(vector<Products> boughtProduct)
{
    //input: product vector
    //output: boughtProduct 
    //determines which product the client wishes to buy
    //then confirms if that is the product they wished to buy
    string selected;
    string confirmation;
    cout << "Type the product/service you wish to purchase." << endl;
    cin >> selected;
    for (int i = 0; i < boughtProduct.size(); i++)
    {
        if (boughtProduct[i].product == "")
        {
            break;
        }
        else
        {
            if (boughtProduct[i].product == selected)
            {
                cout << "You are purchasing " << selected << " for $" << boughtProduct[i].price << " correct? Type Yes or No" << endl;
                cin >> confirmation;
                if (confirmation == "Yes" || confirmation == "yes")
                {
                    cout << "Thank you for shopping with us." << endl;
                }
                else { break; }
            }
        }
    }
}

void updateSales(vector<Sales> updatedSales)
{
    //input: sales vector
    //output: updated sales vector
    // gets the user inputs to determine the location of the change in sales and then updates the sales.
    //puts the updated line in a seperate file
    string newsale;
    int month;
    string first;
    string last;
    cout << "Which clients sales is being updated? Type their First name then Last name." << endl;
    cin >> first;
    cin >> last;
    cout << "Type the number for a month for example January is 1 and December is 12." << endl;
    cin >> month;
    ofstream outfile("output.txt", ios::app);
    for (int i = 0; i < updatedSales.size(); i++)
    {
        if (updatedSales[i].First_Name == first && updatedSales[i].Last_Name == last)
        {
            if (month == 1) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month1 << endl;
                updatedSales[i].Month1 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," <<updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 2) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month2 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 3) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month3 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 4) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month4 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 5) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month5 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 6) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month6 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 7) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month7 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 8) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month8 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 9) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month9 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 10) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month10 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 11) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month11 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
            if (month == 12) {
                cout << "Type the new sale number." << endl;
                cin >> newsale;
                //cout << updatedSales[i].Month2 << endl;
                updatedSales[i].Month12 = newsale;
                outfile << updatedSales[i].First_Name << "," << updatedSales[i].Last_Name << ",";
                outfile << updatedSales[i].Month1 << "," << updatedSales[i].Month2 << "," << updatedSales[i].Month3 << "," << updatedSales[i].Month4 << ",";
                outfile << updatedSales[i].Month5 << "," << updatedSales[i].Month6 << "," << updatedSales[i].Month7 << "," << updatedSales[i].Month8 << ",";
                outfile << updatedSales[i].Month9 << "," << updatedSales[i].Month10 << "," << updatedSales[i].Month11 << "," << updatedSales[i].Month12 << ",";
                outfile << "\n";
            }
        }
    }
    outfile.close();
    
    return;
}

void clientSaleSearch(vector<Sales> clientsearch, string firstName, string lastName)
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
                cout << clientsearch[i].Month1 << " " << clientsearch[i].Month2 << " ";
                cout << clientsearch[i].Month3 << " " << clientsearch[i].Month4 << " ";
                cout << clientsearch[i].Month5 << " " << clientsearch[i].Month6 << " ";
                cout << clientsearch[i].Month7 << " " << clientsearch[i].Month8 << " ";
                cout << clientsearch[i].Month9 << " " << clientsearch[i].Month10 << " ";
                cout << clientsearch[i].Month11 << " " << clientsearch[i].Month12 << endl;
            }

            else
            {
                break;
            }
        }
    }
    return;
}


int main()
{
    bool debug = false;
    // chosenfile stores what file was inputted in choose a file
    string chosenFile = ChooseAFile();
    //cout << chosenFile;
    // needed to find where files were being stored 
    //system("dir"); //system("pause");

    //read = 1 line of sale info read
    string read;

    // open salesfile for read    
    ifstream infile(chosenFile);
   
    //create a vector to hold sale structure data of no more than 300 entries
    vector<Sales> sale(300);
    Sales sales;

    if (infile.is_open())
    {
        if (debug == true) { cout << "DEBG: " << chosenFile << " open success." << endl; }
        // Now read each line, format is
        // Firstname LastName Month1 up to Month12
        string input_line;
        int loopcount = 0;  // track where we are in the loop to put into array
        //if the file does not err
        while (infile.good()) {
            // read each line and store into vector sale
            //getline reads each row and stores that into input_line which is then stored into read
            getline(infile, input_line);
            read = input_line;
            smatch regex_matches;

            stringstream ray(read);
            if (debug == true) { cout << "DGB: InputLine = " << read << endl; }
            // regex function that gets the individual variables of the string read, if they match (First Name, Last Name, Month1, ... , Month12)
            //The pattern in parenthesis is stored in regex_matches
            // The ^ is the start of the matching
            // The ([a-zA-Z]) means that the first part of the line has to be a word with either upper or lower case letters
            // The \\s+ designates all white space 
            // The ([a-zA-Z0-9\\s\\.\\!\\@\\?_]+) gets all letters, numbers, spaces and special characters listed so ., !, @, ?,_ 
            // The ([0-9.]+) gets any number containing the numbers 0-9 at any size, and the . matches if there is a decimal or there is not decimal 
            // The .*$ means to match everything from the start to the end
            regex regex_pattern("^([a-zA-Z]+)\\,([a-zA-Z]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+)\\,([0-9.]+).*$");
            regex_match(read, regex_matches, regex_pattern);

            sale[loopcount].First_Name = regex_matches[1];
            sale[loopcount].Last_Name = regex_matches[2];
            sale[loopcount].Month1 = regex_matches[3];
            sale[loopcount].Month2 = regex_matches[4];
            sale[loopcount].Month3 = regex_matches[5];
            sale[loopcount].Month4 = regex_matches[6];
            sale[loopcount].Month5 = regex_matches[7];
            sale[loopcount].Month6 = regex_matches[8];
            sale[loopcount].Month7 = regex_matches[9];
            sale[loopcount].Month8 = regex_matches[10];
            sale[loopcount].Month9 = regex_matches[11];
            sale[loopcount].Month10 = regex_matches[12];
            sale[loopcount].Month11 = regex_matches[13];
            sale[loopcount].Month12 = regex_matches[14];

            //debug to see what input line is 
            if (debug == true) {
                cout << "DEBG: " << input_line << endl;
                cout << "DEBG:  " << sale[loopcount].First_Name << endl;
                cout << "DEBG:  " << sale[loopcount].Last_Name << endl;
                cout << "DEBG:  " << sale[loopcount].Month1 << endl;
                cout << "DEBG:  " << sale[loopcount].Month2 << endl;
                cout << "DEBG:  " << sale[loopcount].Month3 << endl;
                cout << "DEBG:  " << sale[loopcount].Month4 << endl;
                cout << "DEBG:  " << sale[loopcount].Month5 << endl;
                cout << "DEBG:  " << sale[loopcount].Month6 << endl;
                cout << "DEBG:  " << sale[loopcount].Month7 << endl;
                cout << "DEBG:  " << sale[loopcount].Month8 << endl;
                cout << "DEBG:  " << sale[loopcount].Month9 << endl;
                cout << "DEBG:  " << sale[loopcount].Month10 << endl;
                cout << "DEBG:  " << sale[loopcount].Month11 << endl;
                cout << "DEBG:  " << sale[loopcount].Month12 << endl;
            }

            loopcount = loopcount + 1;
            //cout << endl;

        }
    }
    else {
        cout << "Error: " << chosenFile << " open failure." << endl;
    }

    //open product file for client to see
    ifstream productfile("ProductTester.txt");

    vector<Products> product(20);
    Products products;

    if (productfile.is_open())
    {
        string productline;
        int productcount = 0;// track where we are in the loop to put into array
        //if the file does not err
        while (productfile.good())
        {
            getline(productfile, productline);
            smatch matches;
            stringstream readproduct(productline);

            // regex function that gets the individual variables of the string read, if they match (First Name, Last Name, Month1, ... , Month12)
            //The pattern in parenthesis is stored in regex_matches
            // The ^ is the start of the matching
            // The ([a-zA-Z]) means that the first part of the line has to be a word with either upper or lower case letters
            // The \\s+ designates all white space 
            // The ([0-9.]+) gets any number containing the numbers 0-9 at any size, and the . matches if there is a decimal or there is not decimal 
            // The .*$ means to match everything from the start to the end
            regex productpattern("^([a-zA-Z0-9\\s\\.\\!\\@\\?_]+)\\,\\$([0-9.]+).*$");
            regex_match(productline, matches, productpattern);
            product[productcount].product = matches[1];
            product[productcount].price = stod(matches[2]);

            if (debug == true) {
                cout << "DEBG: " << productline << endl;
                cout << "DEBG:  " << product[productcount].product << endl;
                cout << "DEBG:  " << product[productcount].price << endl;
            }
            productcount = productcount + 1;
        }
    }
    //Buy a product
    string productResponse;
    print_product_vector(product);
    while (productResponse != "No" || productResponse != "no") {
        cout << "Do you wish to buy a product? Yes, or No?" << endl;
        cin >> productResponse;
        if (productResponse == "Yes" || productResponse == "yes") {
            BuyaProduct(product);
        }
        if (productResponse == "No" || productResponse == "no") {
            break;
        }
    }
    //prints sale vector of the original file
    print_sales_vector(sale);
    string clientsalesearch;
    string firstN;
    string lastN;
    while (clientsalesearch != "No" || clientsalesearch != "no") {
        //until no is enterd will continue to ask for a client to search
        //if yes is entered will get users input of the first and last name of the client
        //this is then searched in the clientSearch function which wil return the client information if it is there
        cout << "Do you wish to search for a client? Enter Yes or No" << endl;
        cin >> clientsalesearch;
        if (clientsalesearch == "yes" || clientsalesearch == "Yes") {
            cout << "Enter clients first name." << endl;
            cin >> firstN;
            cout << "Enter clients last name." << endl;
            cin >> lastN;
        }
        clientSaleSearch(sale, firstN, lastN);
        if (clientsalesearch == "No" || clientsalesearch == "no") {
            break;
        }
    }

    //update sales
    string saleupdate;

    while (saleupdate != "No" || saleupdate != "no") {
        //until no is enterd will continue to ask for a client to search
        //if yes is entered will get users input of the first and last name of the client
        //this is then searched in the clientSearch function which wil return the client information if it is there
        cout << "Do you wish to update a sale? Enter Yes or No" << endl;
        cin >> saleupdate;
        if (saleupdate == "yes" || saleupdate == "Yes") {
            updateSales(sale);
        }
        if (saleupdate == "No" || saleupdate == "no") {
            break;
        }
    }
    return 0;
}