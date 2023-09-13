#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
using namespace std;

class menu
{
private:
    int itemcode;
    char itemname[50];
    float price;
    friend void removeitem();
    friend void updateitem();
public:
    void accept()
    {
        cout<<endl<<"Enter Item Code";
        cin>>itemcode;
        cout<<endl<<"Enter Itemname";
        cin>>itemname;
        cout<<endl<<"Enter Price";
        cin>>price;
    }
    void display()
    {
        cout<<endl<<setw(5)<<itemcode<<setw(45)<<itemname<<setw(15)<<price;
    }
};
menu obj;// this is a global object available to all functions not inside class
//class ends here

void removeitem()
{

    // Input item code you want to delete

    int icode;
    cout<<endl<<"Enter item Code for Deletion";
    cin>>icode;

    //calculate number of objects in file

    fstream rd;
    rd.open("e:\\vmm\\menu.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg();
    int count=s/sizeof(obj);
    rd.seekg(0,ios::beg);


    fstream wr;
    wr.open("e:\\vmm\\temp.txt",ios::out);


    //read each object from file one by one and match itemcode in object to icode that has been taken as input

    for(int i=1;i<=count;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(icode==obj.itemcode)
        {
            cout<<endl<<"Object Deleted";
        }
        else
        {
            wr.write((char *)&obj,sizeof(obj));

        }

    }
    //close file connections
    rd.close();
    wr.close();

    //delete menu.txt
    remove("e:\\vmm\\menu.txt");

    //rename temp to menu
    rename("e:\\vmm\\temp.txt","e:\\vmm\\menu.txt");




}

void updateitem()
{

    // Input item code you want to delete

    int icode;
    cout<<endl<<"Enter item Code for Deletion";
    cin>>icode;

    //calculate number of objects in file

    fstream rd;
    rd.open("e:\\vmm\\menu.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg();
    int count=s/sizeof(obj);
    rd.seekg(0,ios::beg);


    fstream wr;
    wr.open("e:\\vmm\\temp.txt",ios::out);


    //read each object from file one by one and match itemcode in object to icode that has been taken as input

    for(int i=1;i<=count;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(icode==obj.itemcode)
        {
            obj.accept();
            wr.write((char *)&obj,sizeof(obj));
            cout<<endl<<"Object Deleted";
        }
        else
        {
            wr.write((char *)&obj,sizeof(obj));

        }

    }
    //close file connections
    rd.close();
    wr.close();

    //delete menu.txt
    remove("e:\\vmm\\menu.txt");

    //rename temp to menu
    rename("e:\\vmm\\temp.txt","e:\\vmm\\menu.txt");




}


void addmenu() // This function is not part of class but a normal function that we used to make in C
{
    obj.accept();
    fstream wr;
    wr.open("e:\\vmm\\menu.txt",ios::app);
    wr.write((char *) &obj,sizeof(obj)); //writing Object to file
    wr.close();
    cout<<endl<<"Menu Written Successfully";
}

void readmenu()
{
    fstream rd;
    rd.open("e:\\vmm\\menu.txt",ios::in);

    int s;
    rd.seekg(0,ios::end); // i have taken cursor to last of file
    s=rd.tellg();  // this will get me number of characters

    cout<<"Size of file"<<s<<endl;
    rd.seekg(0,ios::beg);

    int c=s/sizeof(obj);
    cout<<"Number of objects are "<<c<<endl;

    for(int i=1;i<=c;i++)
    {

    rd.read((char *)&obj,sizeof(obj));
    obj.display();
    }
}
main()
{
    int e=0;
    while(e!=1)
    {
        cout<<endl<<"************************************************";
        cout<<endl<<"Press 1 to Add New Menu Item";
        cout<<endl<<"Press 2 to View Menu List";
        cout<<endl<<"Press 3 to remove Item from Menu";
        cout<<endl<<"Press 4 to update Item from Menu";
        cout<<endl<<"Press 5 to Raise New Invoice";
        cout<<endl<<"Press 6 to exit";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
            addmenu();
            break;
            }
        case 2:
            {
                readmenu();
                break;
            }
        case 3:
            {

                removeitem();
                break;
            }
        case 4:
            {
                updateitem();
                break;
            }
        case 6:
            {
                e=1;
                break;

            }

        }

    }





}

