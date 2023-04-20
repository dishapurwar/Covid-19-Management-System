#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <windows.h>

using namespace std;
class menu
{
    public:
    virtual void login()=0;
    virtual void registration()=0;
    void getdata(){
    B:
    system("cls");
    int user_choice;
    cout << "===================================================================================================================="<<endl;
    cout << "|                                                                                                                  |"<<endl;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                                                                                                  |"<<endl;
    cout << "===================================================================================================================="<<endl<<endl<<endl;
    cout << "\t\t\t                      <<<<<<<<< MENU >>>>>>>>>                 "<<endl<<endl;
    cout << "\t\t\t                            [1] Login                               "<<endl;
    cout << "\t\t\t                            [2] Registration                        "<<endl;
    cout << "\t\t\t                            [3] Exit                                "<<endl<<endl;
    cout << "\t\t\t                           Enter Choice : ";
    cin >> user_choice;

    switch(user_choice)
    {
        case 1:
            login();
            break;
        case 2:
             registration();
             break;
        case 3:
            system("cls");
            cout <<endl<<endl;
            cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
            cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
            cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
            break;
        default:
            cout << "\n\n\t\t\t\t\t Invalid Choice... Please Try Again....";
            cout<<"\n\t\t\t\t\t\tPress Enter to continue.....";
            getchar();
            getchar();
            goto B;
    }

}
};

class sub_menu:public menu
{
protected:
    string user1,pass1,u,p,signuser,signpass;
    char name[100];
    char gender[100];
    int age;
    string mob_no;
    string vaccine_name;
    string center;
    string adhaar;
    int dose;

    public:
    void user();
    void search_center1();
    void search_center2();
    void search_center3();       // 1
    void add_patient_data();    // 2
    void update_patient_data();
    void patient_show_data(); // 4
    void show_data();

    void login()
    {
        system("cls");
        int flag2=0;
        cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
        cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
        cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl<<endl;
        cout << "\t\t\t                   <<<<<<<<< LOGIN WINDOW >>>>>>>>>                 "<<endl<<endl;
        cout << "\t\t\t\t\t     Enter Your Username: ";
        cin >> user1;
        cout << "\n\t\t\t\t\t     Enter Your Password: ";
        cin >> pass1;
        ifstream input("records.txt",ios:: in);
        while(input>>u>>p)
        {
            if(user1==u && pass1==p)
            {
                flag2=1;
            }
        }
        input.close();
        if(flag2==1)
        {
            cout <<"\n\t\t\t\t\t   You are successfully logged in :)";
            cout<<"\n\n\t\t\t\t\t     Press Enter to continue......";
            getchar();
            getchar();
            user();
        }
        else
        {
            cout <<"\n\t\t\t\tYou are not registered or entered credentials are wrong :(\n";
            cout<<"\n\n\t\t\t\t\t     Press Enter to go back.....";
            getchar();
            getchar();
            getdata();
        }

    }
    void registration ()
    {
        system("cls");
        cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
        cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
        cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl<<endl;
        cout << "\t\t\t                <<<<<<<<<  CREATE YOUR ACCOUNT >>>>>>>>>                 "<<endl<<endl;
        cout << "\t\t\t\t\t       Enter Your Username: ";
        cin >> signuser;
        cout << "\n\t\t\t\t\t       Enter Your Password: ";
        cin >> signpass;
        ofstream f1("records.txt",ios::app);
        f1<<signuser<<' '<<signpass<<'\n'<<endl;
        f1.close();
        cout<<"\n\t\t\t\t\t    Your Account is creating please wait";
        for(int i=0; i<4;i++)
        {
        cout<<".";
        Sleep(1000);
        }
        cout <<"\n\n\t\t\t\t\t    You are successfully registered :)";
        cout<<"\n\n\t\t\t\t\t       Press Enter to continue......";
        getchar();
        getchar();
        login();
    }

};

void sub_menu::user()
{

B:
    system("cls");
    int user_choice;
    string date;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl<<endl;
    // USER MENU OPTIONS
    cout << "\t\t\t                     <<<<<<<<< USER MENU >>>>>>>>>                 "<<endl<<endl;
    cout << "\t\t\t                      [1] Search for vaccination center                             "<<endl;
    cout << "\t\t\t                      [2] Apply for vaccine 1st dose                                "<<endl;
    cout << "\t\t\t                      [3] Apply for vaccine 2nd dose                                "<<endl;
    cout << "\t\t\t                      [4] Certificate                                               "<<endl;
    cout << "\t\t\t                      [5] EXIT                                                      "<<endl<<endl;
    cout << "\t\t\t                       Enter Choice : ";
    cin >> user_choice;
    system("cls");
    switch (user_choice)
    {
    case 1:
        int center_choice;
        cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
        cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
        cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl<<endl;
        cout << "\t\t\t     <<<<<<<<< VARIOUS VACCINATION CENTERS IN YOUR CITY >>>>>>>>>                 "<<endl<<endl;
        cout << "\t\t\t                          [1] Center 1"<<endl;
        cout << "\t\t\t                          [2] Cenetr 2"<<endl;
        cout << "\t\t\t                          [3] cenetr 3"<<endl<<endl;
        C:
        cout << "\n\t\t\t                        Enter your Choice : ";
        cin>>center_choice;
        switch (center_choice){
            case 1:
            search_center1();
            cout<<"\t\t\t\t\tEnter Date : ";
            cin>>date;
            goto B;
            case 2:
            search_center2();
            cout<<"\t\t\t\t\tEnter Date : ";
            cin>>date;
            goto B;
            case 3:
            search_center3();
            cout<<"\t\t\t\t\tEnter Date : ";
            cin>>date;
            goto B;
            default:
            cout << "\n\n\t\t\t\t\tInvalid Choice.. Please Try Again :(\n";
            cout << "\n\n\t\t\t\t\t  Press Enter To Continue..";
            getchar();
            getchar();
            goto C;

        }

    case 2:
        add_patient_data();
        goto B;
    case 3:
        update_patient_data();
        goto B;
    case 4:
        patient_show_data();
    case 5:
        exit(0);
    default:
        cout << "\n\n\t\t\t\t\tInvalid Choice.. Please Try Again :(\n";
        cout << "\n\n\t\t\t\t\t  Press Enter To Continue..";
        getchar();
        getchar();
        goto B;
    }
}

void sub_menu::search_center1()
{
    system("cls");
    ifstream file;
    file.open("center1.txt");
    cout<<endl;
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        string ch;
        while (1)
        {
            file >> ch;
            if (file.eof())
                break;
            cout << ch<<endl;
        }
    }
    file.close();
}

    void sub_menu::search_center2()
{
    system("cls");
    ifstream file;
    file.open("center2.txt");
    cout<<endl;
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        string ch;
        while (1)
        {
            file >> ch;
            if (file.eof())
                break;
            cout << ch<<endl;
        }
    }
    file.close();
}

    void sub_menu::search_center3()
{
    system("cls");
    ifstream file;
    file.open("center3.txt");
    cout<<endl;
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        string ch;
        while (1)
        {
            file >> ch;
            if (file.eof())
                break;
            cout << ch<<endl;
        }
    }
    file.close();
}

void sub_menu::add_patient_data()
{
    ofstream file("add_patient_data.txt",ios :: app | ios :: binary);
    system("cls");
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl;
    cout << "\n\n\t\t                        <<<<<< APPLY FOR VACCINE FIRST DOSE >>>>>>";
    cout << "\n\n\t\t\t\t\t        Enter Name: ";
    fflush(stdin);
    cin.getline(name, 100);
B:
    cout << "\n\t\t\t\t\t        Enter Your Mobile Number: ";
    cin >> mob_no;
    if (mob_no.length() != 10)
    {
        cout << "\n\t\t\t\t\t           Invalid Phone Number";
        cout<<endl<<"\t\t\t\t\t           Enter again ...."<<endl;
        goto B;
    }
    else
    {
        if (mob_no[0] == '0' || mob_no[0] == '1')
        {
            cout << "\n\t\t\t\t\t        Invalid Phone Number";
            cout<<endl<<"\t\t\t\t\t        Enter again ...."<<endl;
            goto B;
        }
    }
    cout << "\n\t\t\t\t\t        Enter Gender (M/F): ";
    cin >> gender;
    cout << "\n\t\t\t\t\t        Enter Age: ";
    cin >> age;
    C:
    cout<<"\n\t\t\t\t\t        Enter Adhaar Number:";
    cin>> adhaar;
    if (adhaar.length() != 12)
    {
        cout << "\n\t\t\t\t\tInvalid Aadhar Card Number";
        goto C;
    }
    else
    {
        // The first letter should not start with 0 or 1
        if (adhaar[0] == '0' || adhaar[0] == '1')
        {
            cout << "\n\t\t\t\t\tInvalid Aadhar Card Number";
            goto C;
        }
    }
    cout << "\n\t\t\t\t\t        Enter Vaccine Name [Covishield & Covaxin]: ";
    cin >> vaccine_name;
    cout << "\n\t\t\t\t\t        Enter Dose: ";
    cin >> dose;
    cout << "\n\t\t\t\t\t        Enter Center Allotted: ";
    cin >> center;
    file<<endl<<"Adhaar number : "<<adhaar<<endl<<"Name : "<<name<<endl<<"Mobile no. : "<<mob_no<<endl<<"Gender : "<<gender<<endl<<"Age : "<<age<<endl<<"Vaccine name : "
        <<vaccine_name<<endl<<"Dose : "<<dose<<endl<<"Center : "<<center<<endl << "objectend" << endl;
    cout << "\n\n\t\t\t\t\t YOU HAVE SUCCESSFULLY REGISTERED FOR 1ST DOSE :)";
    cout << "\n\n\t\t\t\t\t         Press Enter To Continue..";
    getchar();
    getchar();
    file.close();
}

void sub_menu::update_patient_data()
{
    string maadhaar;
    system("cls");
    int count = 0;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl;
    cout << "\n\n <<<<<< APPLY FOR VACCINE SECOND DOSE >>>>>>";
    C:
    cout<<"\n\nEnter Adhaar Number:";
    cin>>maadhaar;
    if (maadhaar.length() != 12)
    {
        cout << "\n Invalid Aadhar Card Number\n";
        goto C;
    }
    else
    {
        // The first letter should not start with 0 or 1
        if (maadhaar[0] == '0' || maadhaar[0] == '1')
        {
            cout << "\n Invalid Aadhar Card Number\n";
            goto C;
        }
    }
    string word;
    fstream file("add_patient_data.txt", ios:: in | ios::out);
    while(file >> word)
    {
        if (maadhaar.compare(word) == 0)
        {
            count++;
            while(getline(file, word))
            {
                if(word.compare("Dose : 1") == 0)
                {
                    fstream temp("add_patient_data.txt", ios:: in | ios::out);
                    string tmpsentence;
                    while(temp >> tmpsentence)
                    {
                        if (maadhaar.compare(tmpsentence) == 0)

                            while(getline(temp, tmpsentence))
                            {
                                if(tmpsentence.compare("Vaccine name : Covaxin") == 0 || tmpsentence.compare("Vaccine name : Covidshield") == 0)
                                {
                                    temp << "Dose : 2";
                                }
                                if(tmpsentence.compare("objectend") == 0)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
                if(word.compare("objectend") == 0)
                {
                    break;
                }
            }
        }
    if (count == 0)
    {
        cout << "\n\n Record not found!!";
    }
    ifstream output("add_patient_data.txt");
    string ch;
    while(output >> ch)
    {
        if (maadhaar.compare(ch) == 0)
        {
            while(getline(output, ch))
            {
                if(ch.compare("objectend") == 0)
                {
                    break;
                }
                else{
                    cout << ch << endl;
                }
            }
        }
    }
    output.close();
    file.close();
    cout << "\n\nYOU HAVE SUCCESSFULLY REGISTERED FOR 2ND DOSE :)";
    cout << "\n\nPress Enter To Continue..";
    getchar();
    getchar();
}

void sub_menu::patient_show_data()
{
    int count = 0;
    string vadhaar;
    system("cls");
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                        COVID-19 VACCINE REGISTRATION SYSTEM                                      |"<<endl;
    cout << "| -----------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl;
    cout << "\n\n<<<<<< SEARCH DATA BY AADHAR >>>>>>";
    C:
    cout<<"\n\nEnter Adhaar Number:";
    cin >> vadhaar;
    if (vadhaar.length() != 12)
    {
        cout << "\nInvalid Aadhar Card Number\n";
        goto C;
    }
    else
    {
        // The first letter should not start with 0 or 1
        if (vadhaar[0] == '0' || adhaar[0] == '1')
        {
            cout << "\nInvalid Aadhar Card Number\n";
            goto C;
        }
    }
    cout<<"\n\n|-------------------------------|"<<endl;
    cout<<"|      *   CERTICATE    *       |"<<endl;
    cout<<"|-------------------------------|"<<endl<<endl;
    ifstream file("add_patient_data.txt");
    string word;
    while(file >> word)
    {
        if (vadhaar.compare(word) == 0)
        {
            count++;
            while(getline(file, word))
            {
                if(word.compare("objectend") == 0)
                {
                    break;
                }
                else{
                    cout << word << endl;
                }
            }
            cout<<"\n|--------------------------------|"<<endl<<endl;
        }
    }
    if (count == 0)
    {
        cout << "\n\n\t\t\t\t\t         Record not found!!";
    }
    file.close();
    cout << "\n\nYOU HAVE SUCCESSFULLY VACCINATED :)";
    cout << "\n\nPress Enter To Continue..";
    getchar();
    getchar();
    getdata();
}

int main()
{
    system("color A");
    sub_menu system;
    system.getdata();
}

