#include <iostream>
#include "Array.h"
#include <iomanip>
#include <string>
using namespace std;

//<<<<<<< HEAD
// Address Class
class Address
{
private:
    string streetNum;
    string streetName;
    string town;
    string state;

public:
    // Constructor Default and intialized
    Address(string streetNum = "10", string streetName = "Arabi_street", string town = "zagazig", string state = "Sharqia")
    {
        this->streetNum = streetNum;
        this->streetName = streetName;
        this->town = town;
        this->state = state;
    }

    // Set and Get For All Data Member
    void setStreetNum(string streetNum) { this->streetNum = streetNum; }
    string getStreetNum() const { return streetNum; }
    void setStreetName(string streetName) { this->streetName = streetName; }
    string getStreetName() const { return streetName; }
    void setTown(string town) { this->town = town; }
    string getTown() const { return town; }
    void setState(string state) { this->state = state; }
    string getState() const { return state; }

    void setAddress(string streetNum, string streetName, string town, string state)
    {
        setStreetNum(streetNum);
        setStreetName(streetName);
        setTown(town);
        setState(state);
    }

    void printAddress() const
    {
        cout << getStreetNum() << ", "
             << getStreetName() << ", "
             << getTown() << ", "
             << getState();
    }
};

// Contact Class
class Contact
{
private:
    string firstName, lastName, classification;
    int favourite;
    Address *address;
    string *Phone;
    string *Mail;
    int static id;
    int phoneSize, mailSize, phoneCounter, mailCounter;

public:
    Contact() : address(new Address()), phoneSize(0), mailSize(0), favourite(0), phoneCounter(-1), mailCounter(-1)
    {
        Phone = new string[phoneSize];
        Mail = new string[mailSize];
    }

    ~Contact()
    {
        /*delete[] Phone;
        delete[] Mail;
        delete address;*/
    }
    // get & set FirstName
    void setFirstName(string firstName) { this->firstName = firstName; }
    string getFirstName() const { return firstName; }

    // get & set LastName
    void setLastName(string lastName) { this->lastName = lastName; }
    string getLastName() const { return lastName; }

    // Set Classification ( Friend, work , family , other )
    void setClass(string Classchoice) { classification = Classchoice; }
    string getClass() const { return classification; }

    // set & get Favorite
    void setFav(int favStatus)
    {
        if (favStatus == 1)
        {
            favourite = 1;
        }
        else
        {
            favourite = 0;
        }
    }
    int getFav() const { return favourite; }

    Address getAddress() const { return *address; }

    // Set and Get Phone numbers
    void setPhoneNumbers(int phoneSize)
    {
        delete[] Phone;
        Phone = new string[phoneSize];
        this->phoneSize = phoneSize;
        for (int i = 0; i < phoneSize; i++)
        {
            cout << "Phone #" << i + 1 << " : ";
            cin >> Phone[i];
        }
    }

    /*string getPhoneNumbers()
    {
        // phoneCounter++;
        return Phone[++phoneCounter];
    }*/
    string getPhoneNumbers(int index) const
    {
        if (index >= 0 && index < phoneSize)
        {
            return Phone[index];
        }
        return ""; // or throw an exception
    }

    string getMails(int index) const
    {
        if (index >= 0 && index < mailSize)
        {
            return Mail[index];
        }
        return ""; // or throw an exception
    }

    // Set and Get Mails
    void setMails(int mailSize)
    {
        delete[] Mail;
        Mail = new string[mailSize];
        this->mailSize = mailSize;
        for (int i = 0; i < mailSize; i++)
        {
            cout << "Mail #" << i + 1 << " : ";
            cin >> Mail[i];
        }
    }

    /*string getMails()
    {
        // mailCounter++;
        return Mail[++mailCounter];
    }*/

    void readContactDetails()
    {
        cout << "\t\t\t -------------- Add New Contact ------------- \n ";
        cout << "First Name : ";
        cin >> firstName;
        setFirstName(firstName);
        cout << "Last Name : ";
        cin >> lastName;
        setLastName(lastName);
        cout << "Class (friend , work , family , other ) : ";
        cin >> classification;
        setClass(classification);
        cout << "Set as Favourite (Press 1 (fav) or  0 (Not fav)) : ";
        cin >> favourite;
        setFav(favourite);
        cout << "How Many Numbers ?: ";
        cin >> phoneSize;
        setPhoneNumbers(phoneSize);
        cout << "How Many Mails ?: ";
        cin >> mailSize;
        setMails(mailSize);
        cout << "\t\t :: Enter Address Details :: \n";
        cout << "Street Number : ";
        string streetNum;
        cin >> streetNum;
        cout << "Street Name : ";
        string streetName;
        cin >> streetName;
        cout << "Town : ";
        string town;
        cin >> town;
        cout << "State : ";
        string state;
        cin >> state;
        address->setAddress(streetNum, streetName, town, state);
    }

    // Display
    void printHeader()
    {
        cout << "First Name " << "\t" << "Last Name " << "\t" << "Classification " << "\t" << "Favourite " << "\t" << "Address " << "\t\t" << "Phone Number/s " << "\t   " << "Mails" << endl;
    }

    void displayContactDetails()
    {
        cout << getFirstName();
        cout << "\t" << getLastName();
        cout << "\t  \t" << getClass();
        cout << "\t\t" << getFav();
        cout << "\t\t";
        address->printAddress();
        // Display phone numbers
        cout << "\t  ";
        for (int i = 0; i < phoneSize; i++)
        {
            if (i == phoneSize - 1)
            {
                cout << getPhoneNumbers(i);
            }
            else
            {
                cout << getPhoneNumbers(i) << " , ";
            }
        }
        // Display emails
        cout << "\t  ";
        for (int i = 0; i < mailSize; i++)
        {
            if (i == mailSize - 1)
            {
                cout << getMails(i);
            }
            else
            {
                cout << getMails(i) << " , ";
            }
        }
        cout << endl;
    }
};

int Contact::id = 0;

// ContactBook Class
class contactBook
{
private:
    DArray<Contact> obj;

public:
    // Add New Contact
    // Assuming DArray has a method to append
    void addNewContact(const Contact &newCon)
    {
        obj.append(newCon);
    }

    // Search By lastName
    void searchByLastName(string lastName)
    {
        for (int i = 0; i < obj.getSize(); i++)
        {
            if (obj[i].getLastName() == lastName)
            {
                obj[i].displayContactDetails();
            }
        }
    }

    // Search
    // Search By Classification (friend , work , family , other )
    void searchByClas(string classification)
    {
        for (int i = 0; i < obj.getSize(); i++)
        {
            if (obj[i].getClass() == classification)
            {
                obj[i].displayContactDetails();
            }
        }
    }

    // Print All Contacts
    void printAllContacts()
    {
        if (obj.getSize() == 0)
        {
            cout << "No contacts to display." << endl;
            return;
        }
        obj[0].printHeader(); // Print the header once
        for (int i = 0; i < obj.getSize(); i++)
        {
            obj[i].displayContactDetails();
        }
    }

    // Print Fav Contacts
    bool printFavContacts()
    {
        bool hasFavContacts = false;
        for (int i = 0; i < obj.getSize(); i++)
        {
            if (obj[i].getFav() == 1)
            {
                obj[i].displayContactDetails();
                hasFavContacts = true;
            }
        }
        if (!hasFavContacts)
        {
            cout << "No favorite contacts found." << endl;
        }
        return hasFavContacts;
    }

    // Delete Contact
    void DeleteContact(int index)
    {
        obj.Delete(index);
    }

    // Update Contact
    void update(Contact con, int index)
    {
        obj.insert(con, index);
    }

    // Reverse Contacts book
    void reverseContactBook()
    {
        obj.reverse();
    }
};

// Some Helper Function :
int ReadNumberInRange(int From, int To)
{
    int Number;
    do
    {
        cout << "Enter Your Choice : ";
        cin >> Number;
    } while (Number > To || Number < From);
    return Number;
}

int DisplayMenu()
{
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "                                      Contact book menu:\n";
    cout << "========================================================================================\n";
    cout << "     1. Add new contact\n";
    cout << "     2. Search by last name (Enter last name correctly)\n";
    cout << "     3. Search by classification (Enter classification correctly)\n";
    cout << "     4. Print all contacts\n";
    cout << "     5. Print favorite contacts\n";
    cout << "     6. Delete contact\n";
    cout << "     7. Update contact information\n";
    cout << "     8. Reverse contact book\n";
    cout << "     9. Exit\n";
    cout << "----------------------------------------------------------------------------------------\n";
    return ReadNumberInRange(1, 9);
}

void ChoseOrder(int order, contactBook &contact)
{
    Contact con;
    string lastName, Classification;
    switch (order)
    {
    case 1:
        system("cls");
        con.readContactDetails();
        contact.addNewContact(con);
        break;
    case 2:
        system("cls");
        cout << "Enter Last Name In Correct Form: ";
        cin >> lastName;
        contact.searchByLastName(lastName);
        break;
    case 3:
        system("cls");
        cout << "Enter Classification In Correct Form (friend, family, work, other): ";
        cin >> Classification;
        contact.searchByClas(Classification);
        break;
    case 4:
        system("cls");
        contact.printAllContacts();
        break;
    case 5:
        system("cls");
        contact.printFavContacts();
        break;
    case 6:
        int indexToDelete;
        cout << "Enter the index of contact to delete: ";
        cin >> indexToDelete;
        contact.DeleteContact(indexToDelete);
        break;
    case 7:
        system("cls");
        int indexToUpdate;
        cout << "Enter the index of contact to update: ";
        cin >> indexToUpdate;
        con.readContactDetails();
        contact.update(con, indexToUpdate);
        break;
    case 8:
        system("cls");
        contact.reverseContactBook();
        break;
    case 9:
        system("cls");
        cout << "Exiting...\n";
        break;
    default:
        break;
    }
}

// Main
int main()
{
    Contact con;
    contactBook contact;
    string lastName, Classification;
    int order = 0;
    do
    {
        order = DisplayMenu();
        ChoseOrder(order, contact);
    } while (order != 9);
    system("pause");
    return 0;
}
