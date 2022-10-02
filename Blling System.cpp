#include <iostream>
#include <fstream>
using namespace std;
class BMS{
    int pid,quantity;
    float price;
    string name;
    
    public:
    // Add product in catalog
    void add()
         {
             m:
             int id,p;
             int counter=0;
             string n;
             fstream data;
            
            cout<<"Enter products ID\n";
            cin>>pid;
            cout<<"Enter product name\n";
            cin>>name;
            cout<<"Enter product Price\n";
            cin>>price;
            data.open("products.txt", ios::in);
            if(!data)
            {
                data.open("products.txt" , ios::app | ios:: out);
                data<<pid<<"\t"<<name<<"\t"<<price<<endl;
                data.close();
            }
            else
            {
                data>>id>>n>>p;
                while(!data.eof())
                {
                    if(id==pid)
                    {
                        counter++;

                    }
                data>>id>>n>>p;
                }
                data.close();
            
            if(counter == 1)
                
                goto m;
            
            
            else
            {
                data.open("products.txt", ios::app | ios::out);
                data<<pid<<"\t"<<name<<"\t"<<price<<endl;
                data.close();

            }
                        cout<<"Product added\n";

            }

            admin();

            
            
         }

    // Edit products's id,price or name
    void edit(){
        fstream data,data1;
        int id,pkey,counter=0,p;
        string n;
    
        cout<<"Enter product id to edit the record\n";
        cin>>pkey;
        data.open("products.txt" , ios::in);
        if(!data)
        {
            cout<<"file doesn't exist\n";
        }
        else
        {
            data1.open("temp.txt", ios::app | ios::out);
            data>>pid>>name>>price;
            while (!data.eof()) 
            {
                if(pkey==pid)
                    {
                        cout<<"Enter new products ID\n";
                        cin>>id;
                        cout<<"Enter New product name\n";
                        cin>>n;
                        cout<<"Enter new product price is Rs\n";
                        cin>>p;
                        data1<<id<<"\t"<<n<<"\t"<<p<<endl;
                        cout<<"Done\n";
                        counter++;
                    }
                else
                {
                        data1<<pid<<"\t"<<name<<"\t"<<price<<endl;

                }
                    data>>pid>>name>>price;

            }
            data.close();
            data1.close();

           remove("products.txt");
           rename("temp.txt" , "products.txt");
           if (counter==0)
           {
               cout<<"invalid id\n";
           }
           
            
        }
        cout<<endl;
        admin();
    }
    
    void Delete(){
         fstream data,data1;
        int pkey,counter=0;
        
    
        cout<<"Enter product id to Remove the record\n";
        cin>>pkey;
        data.open("products.txt" , ios::in);
        if(!data)
        {
            cout<<"file doesn't exist\n";
        }
        else
        {
            data1.open("temp.txt", ios::app | ios::out);
            data>>pid>>name>>price;
            while (!data.eof()) 
            {
                if(pid==pkey)
                    {
                        cout<<"Product Deleted\n";
                        counter++;
                    }
                else
                {
                        data1<<pid<<"\t"<<name<<"\t"<<price<<endl;

                }
                    data>>pid>>name>>price;

            }
            data.close();
            data1.close();

           remove("products.txt");
           rename("temp.txt" , "products.txt");
           if (counter==0)
           {
               cout<<"invalid id\n";
           }
           
            
        }
        cout<<endl;
        admin();
    }
    
    //Show product's detail to customer
    void show(){
        fstream data;
        data.open("products.txt" , ios::in);
        cout<<"Id\tName\tPrice\n";
        data>>pid>>name>>price;
        while (!data.eof())
        {
            cout<<pid<<"\t"<<name<<"\t"<<price<<endl;
            data>>pid>>name>>price;

        }
        data.close();
        

        
    }
    //Show total bill to customer
    void bill()
    {
        fstream data;
        int ids[100];
        int quan[100];
        char choice;
        int amount=0,x=0,total=0;
        data.open("products.txt" , ios::in);
        
            if(!data)
            {
                cout<<"Nothing to display\n";
            }
            else
            {
            data.close();
            show();
            
            cout<<"\n**********************************************\n";
            cout<<"                                                \n";
            cout<<"               Select items below               \n";
            cout<<"                                                \n";
            cout<<"\n**********************************************\n";
            cout<<endl;
            do
            {
                m:
                cout<<"Enter product code to add in cart\n";
                cin>>ids[x];
                cout<<"Enter quantity\n";
                cin>>quan[x];
                for (int i = 0; i < x; i++)
                {
                    if(ids[x]==ids[i])
                    {
                        cout<<"Product already added\n";
                        goto m;
                    }

                }
                x++;
                cout<<"Do you want to buy another product? y/n\n";
                cin>>choice;
            }
            while(choice == 'y');
            for (int i = 0; i < x; i++)
            {
                cout<<ids[i]<<endl;
            }
            

            
            
            cout<<"**************Receipt**************\n";
            cout<<"Id\tName\tPrice\tAmount\n";
            for(int i=0; i<x; i++)
            {
                data.open("products.txt", ios::in);
                data>>pid>>name>>price;

                while(!data.eof())
                {
                    if(pid==ids[i])
                    {
                        amount = price * quan[i];
                        total+=amount;
                        
                        cout<<pid<<"\t"<<name<<"\t"<<quan[i]<<"\t"<<amount<<"\t"<<endl;
                    }
                    data>>pid>>name>>price;

                }
            }
            data.close();
    }
    cout<<"\n\n Total Payable amount is "<<total;
            
            
        
    }
    void showMenu(){
    int choice;
    string email,pass;
	cout<<"Enter 1 for Admin\n\nEnter 2 for Customer\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
            cout<<"Enter Email\n";
            cin>>email;
            cout<<"Enter Password\n";
            cin>>pass;
            if(email=="1" && pass=="1")
            admin();
            else
            cout<<"Invalid email or password. Exiting.........\n";
        break;
    case 2:
        customer();
        break;
    default:
        cout<<"Invalid choice";
        break;  
    }           

}
    //admin panel
    void admin(){
        int choice;
        cout<<"1.Add Product\n2.Remove Product\n3.Edit Product\n0.Main Menu"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            Delete();
            break;
        case 3:
            edit();
            break;
        case 0:
            showMenu();
            break;        
        default:
            cout<<"Invalid\n";
            break;
        }
    }
    //customer panel
    void customer(){
        bill();
    }
    
};


int main(){
BMS b;
b.showMenu();


}


