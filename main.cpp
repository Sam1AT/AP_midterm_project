#include <iostream>
#include "Cell.cpp"
#include "vector"
#include "Animal.cpp"
#include <math.h>

using namespace std;
/////////////////////////////////////////////////////////////
bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (isdigit(ch) == 0) 
            return false;
    }
    return true;
 }

void listAllAnimals(vector<string> s)
{

    for(int i=0; i < s.size(); i++)
    {
        cout << i + 1 <<") " << s[i] << endl;
    }
    if(s.size() == 0)
        cout << "! ! !   No animal is added yet   ! ! ! ";
    cout << endl;
}

void listAllViruses(vector<string> s , vector<Virus*> all)
{

    for(int i=0; i < s.size(); i++)
    {
        cout << i + 1 <<") " << s[i] ;
        cout <<" RNA: ";
        cout<< all[i]->r.RNA << endl;
    }
    if(s.size() == 0)
        cout << "! ! !   No virus is added yet   ! ! ! ";
    cout << endl;
}

void getValidValue(string &n)
{

    cin >> n;
    while(!isNumber(n))
    {
        cout << "! ! !   Invalid argument enter a number  ! ! !" << endl;
        cin >> n;
    }

}

bool validateSequence(string seq)
{
    for (char const &ch : seq) {
        if (ch != 'A' && ch != 'T' && ch != 'C' && ch != 'G') 
            return false;
    }
    return true;
 }

void getValidSequence(string &s)
{
    cin >> s;
        while(!validateSequence(s))
        {
            cout << "! ! !  Invalid strand. you must only use ATGC in your RNA or DNA  ! ! !" << endl;
            cin >> s;
        }
}
 /////////////////////////////////////////////////////////////


int main(){
    string option = "10";
    string n,n2;
    string AnimalNametmp;
    vector<string> AnimalName;
    vector<Animal> AnimalList;
    string VirusNametmp;
    vector<string> VirusName;
    vector<Virus*> VirusList;

    cout << "--------------------------------------------------------------------------------";
    cout << "|                       Welcome to the class of life app                       |" << endl;
    cout << "|                                 Authors :                                    |" << endl;
    cout << "|                           Sam Ahmadizadeh Tourzani                           |" << endl;
    cout << "|                           Elnaz Abbas Nejad                                  |" << endl;
    cout << "--------------------------------------------------------------------------------";

while(option != "0")
{
    cout << "--------------------------------------------------------------------------------" << endl;
    cout<<"Please choose one of the options below (Enter a number): "<<endl;
    cout << "1) List of Animals." << endl;
    cout << "2) Making a new animal." << endl;
    cout << "3) Adding Chromosome to an Animal." << endl;
    cout << "4) Making DNA from a RNA." << endl;
    cout << "5) Small mutation." << endl;
    cout << "6) Big mutation." << endl;
    cout << "7) Reversed mutation." << endl;
    cout << "8) Finding all the palindroms of a Chromosome." << endl;
    cout << "9) Detail about a specefic animal." << endl;
    cout << "10) List of Viruses." << endl;
    cout << "11) Making a new Virus." << endl;
    cout << "12) Check Virus infection." << endl;
    cout << "13) Check the simularity between two animal." << endl;
    cout << "14) Sexual reproduction for two animal." << endl;


    cout << "*** For exit please enter 0 ***" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "->";
    cin >> option;
    if(option == "1")
    {
        listAllAnimals(AnimalName);
    }
    else if(option == "2")
    {
        cout << "Choose a name for your animal(it could also include whitespaces)"  << endl;
        cin.ignore();
        getline(cin , AnimalNametmp);
        Animal* tmp = new Animal;
        AnimalName.push_back(AnimalNametmp);
        AnimalList.push_back(*tmp);
        cout << "How many Chromosomes you want to add to your animals' cell?" << endl;
        cout << "(After giving your number write your DNA strands)" << endl;
        getValidValue(n); // validating the value 
        AnimalList[AnimalList.size() - 1].c.add(stoi(n));
        cout << "Animal added ! ! !" << endl;
    }
    else if(option == "3")
    {
        listAllAnimals(AnimalName);
        cout << "Which animal you want to choose?";
        a:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto a;
        }
        AnimalList[stoi(n) - 1].c.add(1);
        cout << "Chromosome added ! ! !" << endl;
    }
    else if(option == "4")
    {
        cout << "Enter your RNA strand: ";
        getValidSequence(n);
        Genome seqc;
        seqc.getRNA(n);
        seqc.makeDNA();
    }
    else if(option == "5")
    {

        cout <<"Choose the animal that you want to make a mutation on it" << endl;
        listAllAnimals(AnimalName);
        b:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto b;
        }
        
        cout << "First enter the letter you want to be replaced then the letter that you want to raplace after all the times you want to replace and the number of Chromosome :(exp:A C 3 4) ";
        c:
        string a,b,c,d;
        cin >> a >> b;
        getValidValue(c);
        getValidValue(d);
        if(stoi(d) > AnimalList[stoi(n) - 1].c.CHR.size() || stoi(d) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto c;
        }
        if((a != "A" && a != "T" && a != "G" && a!="c") || (b != "A" && b != "T" && b != "G" && b != "c"))
        {
            cout << "! ! !   Enter a valid Nucleotide   ! ! !"<<endl;
            goto c;
        }
        AnimalList[stoi(n) - 1].c.jahesh_K_DNA(a, b , stoi(c) , stoi(d) - 1);
    }
    else if(option == "6")
    {
        cout <<"Choose the animal that you want to make a mutation on it" << endl;
        listAllAnimals(AnimalName);
        y:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto y;
        }
        
        cout << "First enter the strand then number of chromosome and repeat this for second one : (exp : AT TA 2 3)";
        f:
        string a,b,c,d;
        getValidSequence(a);
        getValidSequence(b);
        getValidValue(c);
        getValidValue(d);
        if(stoi(d) > AnimalList[stoi(n) - 1].c.CHR.size() || stoi(d) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto f;
        }
        if(stoi(c) > AnimalList[stoi(n) - 1].c.CHR.size() || stoi(c) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto f;
        }
        AnimalList[stoi(n) - 1].c.jahesh_B_DNA(a,stoi(c) - 1   , b  , stoi(d) - 1);
    }
    else if(option == "7")
    {
        
    }
    else if(option == "8")
    {
        
        cout <<"Choose the animal that you want to see the palindrom " << endl;
        listAllAnimals(AnimalName);
        ew:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto ew;
        }
        aqqq:
        string d;
        cout << "Enter the number of chromose." << endl;
        getValidValue(d);
        if(stoi(d) > AnimalList[stoi(n) - 1].c.CHR.size() || stoi(d) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto aqqq;
        }
     AnimalList[stoi(n) - 1].c.palindrome(stoi(d) - 1);

    }
    else if(option == "9")
    {
        cout <<"Choose the animal that you want to see the details: (Enter a number)" << endl;
        listAllAnimals(AnimalName);
        q:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto q;
        }
        cout << "Animal name : " << AnimalName[stoi(n) - 1] << endl;
        cout << "Chromosome count : " << AnimalList[stoi(n) - 1].c.CHR.size() << endl;
        cout << "Do you want to see details about it chromosomes ?(y/n)" << endl;
        char opt;
        cin >> opt;
        if(opt == 'y' || opt == 'Y')
        {
            for(int i=0;i < AnimalList[stoi(n) - 1].c.CHR.size();i++)
            {
                cout << i+1 << " Chromosome : "<<endl;
                cout<<"   The first DNA seq is : " <<AnimalList[stoi(n) - 1].c.CHR[i].DNA1 << endl;
                cout<<"   The second DNA seq is : " <<AnimalList[stoi(n) - 1].c.CHR[i].DNA2 << endl;
            }
        }
    }
    else if(option == "10")
    {
        listAllViruses(VirusName , VirusList);
    }
    else if(option == "11")
    {
        cout << "Choose a name for your virus(it could also include whitespaces)"  << endl;
        cin.ignore();
        getline(cin , VirusNametmp);
        Virus* tmpv = new Virus;
        VirusName.push_back(VirusNametmp);
        VirusList.push_back(tmpv);
        cout << "Enter a RNA strand for your virus: ";
        getValidSequence(n);
        tmpv->r.getRNA(n);
        cout << "Virus added ! ! !" << endl;
    }
     else if(option == "12")
    {
       cout <<"Choose the animal that you want to check infection for it" << endl;
        listAllAnimals(AnimalName);
        oi:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto oi;
        }

        cout <<"Choose the Virus that you want to check infection for it" << endl;
        listAllViruses(VirusName , VirusList);
        io:
        getValidValue(n2); // validating the value 
        if(stoi(n2) > VirusList.size() || stoi(n2) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto io;
        }

    if(VirusList[stoi(n2)-1]->canInfect(AnimalList[stoi(n)-1]))
    {
        cout << "+ + +  It infects it  + + +";
    }  
    else 
    {
        cout << "- - -   It doesn't infect it   - - -";
    }
        cout << endl;
    }
    else if(option == "13")
    {
        cout <<"Choose the first animal" << endl;
        listAllAnimals(AnimalName);
        ooo:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto ooo;
        }

        cout <<"Choose the Second one" << endl;
        listAllAnimals(AnimalName);
        ooi:
        getValidValue(n2); // validating the value 
        if(stoi(n2) > AnimalList.size() || stoi(n2) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto ooi;
        }



        cout << "The simularity is : " << AnimalList[stoi(n) - 1].simularity(AnimalList[stoi(n2) - 1])<<" percent." << endl;
    }
     else if(option == "14")
    {
        cout <<"Choose the first animal" << endl;
        listAllAnimals(AnimalName);
        oooii:
        getValidValue(n); // validating the value 
        if(stoi(n) > AnimalList.size() || stoi(n) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto oooii;
        }

        cout <<"Choose the Second one" << endl;
        listAllAnimals(AnimalName);
        oooi:
        getValidValue(n2); // validating the value 
        if(stoi(n2) > AnimalList.size() || stoi(n2) <= 0)
        {
            cout << "! ! !  Out of index ,enter another number   ! ! !" << endl;
            goto oooi;
        }

        Animal t = AnimalList[stoi(n) -1] + AnimalList[stoi(n2) -1];
        string sd;
        if(t.c.CHR.size() != 0)
        {
            cout << "Enter a name for your new animal." << endl;
            cin.ignore();
            getline(cin , sd);
            AnimalName.push_back(sd);
            AnimalList.push_back(t);
        }
        else
        {
            cout << "! ! !  Can't make a new animal  ! ! !"<< endl;
        }

    }
    else if(option != "0" || !isNumber(option))
    {
        cout << "! ! !    Invalid option please choose a valid one   ! ! !" << endl;
    }
}


cout << "Thanks for using our app =)";




}

