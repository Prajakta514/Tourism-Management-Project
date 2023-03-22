#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int mat1[8][3][15];
int mat2[5][2][15];

void Login()
{
    string uName,name, email, gender;
    string pass2,logname, logpass;
    string valname, valpass;
    int idd,flag1=0,flag2=0,flag3=0,i=0;
    long int phone;
    int choice, len;
    cout<<"\t\t\t\tEnter choice"<<endl;
    cout<<"\t\t\t1.Register\t 2.Login"<<endl;
    cin>>choice;
    if (choice==1)
    {
        ofstream output("record.txt",ios::app | ios::binary | ios::in | ios:: out);
        cout<<"Enter username: ";
        cin>>uName;
       
        while(1)
        {
        cout<<"Enter password: ";
        cin>>pass2;
       
        len =pass2.length();
               for(i=0;i<=len; i++)
               {
                   
                   if(pass2[i]=='@' || pass2[i]=='!' || pass2[i]=='#' || pass2[i]=='$' || pass2[i]=='*' || pass2[i]=='&')
                    {
                        flag1=1;
                        break;
                    }
               }
               for(i=0;i<=len; i++)
               {
                    if(pass2[i]>=48 && pass2[i]<=57)
                    {
                        flag2=1;
                        break;
                    }
               }
               for(i=0;i<=len; i++)
               {
                    if((pass2[i]>=65 && pass2[i]<=90) || (pass2[i]>=97 && pass2[i]<=122))
                    {
                        flag3=1;
                        break;
                    }
               }
          try
            {
               if(flag1!=1 || flag2!=1 || flag3!=1)
                    throw(1);
                else
                    break;
            }
            catch(int a)
            {
                cout<<"Password must contain atleast one special character, digit and alphabet\n";
            }
           
        }
       
        cout<<"\nConfirm your password :";
        cin>>pass2;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Email : ";
        cin>>email;
        cout<<"Enter Gender: ";
        cin>>gender;
        while(1)
        {
            cout<<"Enter phone number : ";
            cin>>phone;
            try
            {
                if(phone<=999999999 || phone>9999999999)
                    throw(phone);
                else
                    break;
            }
            catch(long int phone)
            {
                cout<<"Please Enter valid phone number!\n";
            }    
        }
       
        output<<uName<<" "<<pass2<<" "<<name<<" "<<email<<" "<<gender<<" "<<phone<<endl;
       
        output.close();
        cout<<"Registration complete!"<<endl;
    }
   
   else if(choice==2)
   {
        // login
        string un,up,u,p;
        int count;
        cout<<"Enter Username :";
        cin>>un;
        cout<<"Enter Password:";
        cin>>up;
        ifstream input("record.txt");
            while(input>>u>>p)
            {
                if(u==un && p==up)
                {
                    count=1;
                }
            }
            input.close();
            if(count==1)
            {
                cout<<"\tLogin successfully...";
            }
            else
            {
                cout<<"\tLogin Failed !";
                Login();
            }
    }
}

class credential
{
    private:
        char email[15],name[15],no[10];
    public:
        virtual void display()=0;
       
};

void book_matrix1()
{
    for(int k=0;k<8;k++)
    {
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<15;j++)
            mat1[k][i][j]=0;
    }
    }
   
}

void update_bookmatrix1(int ch1,int ch2,int n)
{
    int i,no;
   
    cout<<"\nAvailable seats: ";
    for(int j=0;j<15;j++)
    {
        if(mat1[ch1-1][ch2-1][j]==0)
            cout<<j+1<<" ";
    }
    cout<<"\nSelect seat numbers: ";
    for(i=0;i<n;i++)
    {
        cin>>no;
        mat1[ch1-1][ch2-1][no-1]=1;
    }
       
}

void book_matrix2()
{
    for(int k=0;k<5;k++)
    {
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<15;j++)
            mat2[k][i][j]=0;
    }
    }
}

void update_bookmatrix2(int ch1,int ch2,int n)
{
    int i,no;
   
    cout<<"Available seats: ";
    for(int j=0;j<15;j++)
    {
        if(mat2[ch1-1][ch2-1][j]==0)
            cout<<j+1<<" ";
    }
    cout<<"\nSelect seat numbers: ";
    for(i=0;i<n;i++)
    {
        cin>>no;
        mat2[ch1-1][ch2-1][no-1]=1;
    }
       
}

class Indian_tour:public credential
{
    public:
         int ch,ch2,ch3;
         char book;
        void display();
        void MH(int ch2);
        void GOA(int ch2);
        void RJ(int ch2);
        void KERALA(int ch2);
        void HIMACHAL(int ch2);
        void JK(int ch2);
        void UK(int ch2);
        void SK(int ch2);
        void book_trip(int st,int loc);
       
};

class International_tour:public credential
{
    public:
    int ch1,ch2,ch3;
    char book;
        void display();
        void SG(int ch2);
        void USA(int ch2);
        void AUS(int ch2);
        void DUBAI(int ch2);
        void EUROPE(int ch2);
        void book_trip(int st2,int loc2);
};


void Indian_tour::MH(int ch2)
{
cout<<"\n\t\t1. Lonavala and Khandala 4 nights 5 days : Rs.25000 per person";
cout<<"\n\t\t2. Matheran 2 nights : Rs.11000 per person";
cout<<"\n\t\t3. Best of Konkan(Panshet,Mulshi,kolad,Alibaug etc) 6 days 5 nights: Rs.18350 per person";
cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}

void Indian_tour::GOA(int ch2)
{char book;
cout<<"\n\n\t\t1. 5 Days 4 nights in Goa : Rs.37000 per person";
cout<<"\n\t\t2. 3 Days 2 nights in Goa : Rs. 25000 per person";
cout<<"\n\t\t3. 4 Days 3 nights in Goa(South goa sightseeing + Mandovi River cruise + photography session : Rs. 35000 per person";

cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}

void Indian_tour::RJ(int ch2)
{
cout<<"\n\n\t\t1. Ranthambore 3 nights 4 days : Rs.20000 per person";
cout<<"\n\t\t2. Ajmer Pushkar Tour 3 nights 4 days : Rs.11000 per person";
cout<<"\n\t\t3. Royal Rajasthan Tour(Jaipur-Udaipur-Mount Abu-Jodhpur-Jaisalmer-Pushkar) 9 nights 10 days : Rs.55000 pp";

cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}

void Indian_tour::KERALA(int ch2)
{

cout<<"\n\t\t1. Land of peace Kerala 2 days Munnar 1 day thekkady and Alleppey and 2 days cochin 5 nights 6 days : Rs.15999 pp";
cout<<"\n\t\t2. Backwaters Kumarakom, Alleppey, cochin each day thus 2 nights 3 days : Rs.9800 per person";
cout<<"\n\t\t3. Beach wonders cochin 2 days and Kovalam and Trivandrum 1 day each thus 3 nights 4 days : Rs.8700 per person";
cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}

void Indian_tour::HIMACHAL(int ch2)
{
cout<<"\n\n\t\t1. 5 nights 6 days 2 nights Shimla 3 nights manali : Rs.15500 per person";
cout<<"\n\t\t2. 6 nights 7 days 2 nights Shimla 1 night Kullu 3 nights manali : Rs.19400 per person";
cout<<"\n\t\t3. 11 days 10 nights shimla(2) manali(3) dharmashala(2) dalhousie(2) Amritsar(1) : Rs.32000 per person";

cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}

void Indian_tour::JK(int ch2)
{
cout<<"\n\n\t\t1. 5 nights 6 days Srinagar(2) Pahalgam(1) Gulmarg(1) houseboat(1) : Rs.10000 per person";
cout<<"\n\t\t2. 4 nights 5 days : Rs.20000 per person";
cout<<"\n\t\t3. Ladakh 4 night 5 days : Rs.27000 per person";

cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}

void Indian_tour::UK(int ch2)
{
cout<<"\n\n\t\t1. 7 nights 8 days : Rs.15000 per person";
cout<<"\n\t\t2. Nainital with Jim Corbett 4 nights 5 days : Rs.8000 per person";

cout<<"\n\t\t3. Mussoorie with Dhanautli 3 nights 4 days : Rs.6500 per person";
cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}

void Indian_tour::SK(int ch2)
{
cout<<"\n\n\t\t1. Sikkim with Nathula pass 3 nights 4 days : Rs.9000 per person";
cout<<"\n\t\t2. Gangtok Darjeeling 5 nights 4 days : Rs.16000 per person";
cout<<"\n\t\t3. Gangtok tsomgo lake baba mandir lachen gurudongmar lake leachung yumthang vallry Gangtok darjeeling 7 nights 8 days : Rs.23999 per person";

cout<<"\n\n\tDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch3;
book_trip(ch2,ch3); //passing which trip has to be booked

}
else
return;
}



void Indian_tour::display()
 {
     cout<<"MENU:";
cout<<"\n\t🌟 1.Maharashtra\n\t🌟 2.Goa\n\t🌟 3.Rajasthan\n\t🌟 4.Kerala\n\t🌟 5.Himachal\n\t🌟 6.J&K\n\t🌟 7.Uttarakhand\n\t🌟 8.Sikkim.";
      cout<<"\nEnter your choice : ";
      cin>>ch2;
      switch(ch2)
      {
      case 1:
      MH(ch2);
      break;
     
      case 2:
      GOA(ch2);
      break;
     
      case 3:
      RJ(ch2);
      break;
     
      case 4:
      KERALA(ch2);
      break;
     
      case 5:
      HIMACHAL(ch2);
      break;
     
      case 6:
      JK(ch2);
      break;
     
      case 7:
      UK(ch2);
      break;
     
      case 8:
      SK(ch2);
      break;

      }
           
     
 }


void Indian_tour::book_trip(int st,int loc)
{   string s1,s2;
    int c;  
   if(st==1 )
    {  s1="MAHARASHTRA";
        if(loc==1)
              c=25000;
             s2=" Lonavala and Khandala 4 nights 5 days ";
        if(loc==2)
            c= 11000;
            s2="Matheran 2 nights  ";
        if(loc==3)
            c =18350;
            s2="Best of Konkan(Panshet,Mulshi,kolad,Alibaug etc)";
    }
    if(st==2)
    {  s1="GOA";
        if(loc==1)
             c=37000;
             s2="5 Days 4 nights in Goa";
        if(loc==2)
            c= 25000;
             s2=" 3 Days 2 nights in Goa ";
        if(loc==3)
            c= 35000;
             s2="4 Days 3 nights in Goa(South goa sightseeing+Mandovi River cruise+photography session)";
    }
    if(st==3 )
    { s1="RAJASTHAN";
        if(loc==1)
             c=20000;
              s2="Ranthambore 3 nights 4 days ";
        if(loc==2)
           c=11000;
            s2=" Ajmer Pushkar Tour 3 nights 4 days ";
        if(loc==3)
           c=55000;
            s2="Royal Rajasthan Tour(Jaipur-Udaipur-Mount Abu-Jodhpur-Jaisalmer-Pushkar) 9 nights 10 days ";
    }
    if(st==4 )
    { s1="KERALA";
        if(loc==1)
             c= 15999;
              s2="Land of peace Kerala 2 days Munnar 1 day thekkady and Alleppey and 2 days cochin 5 nights 6 days";
        if(loc==2)
            c=9800;
             s2="Backwaters Kumarakom, Alleppey, cochin each day thus 2 nights 3 days ";
        if(loc==3)
            c= 8700;
             s2="Beach wonders cochin 2 days and Kovalam and Trivandrum 1 day each thus 3 nights 4 days ";
    }
    if(st==5)
    { s1="HIMACHAL";
        if(loc==1)
             c= 15500;
              s2=" 5 nights 6 days 2 nights Shimla 3 nights manali ";
        if(loc==2)
            c= 19400;
             s2="6 nights 7 days 2 nights Shimla 1 night Kullu 3 nights manali ";
        if(loc==3)
            c= 32000;
             s2="11 days 10 nights shimla(2) manali(3) dharmashala(2) dalhousie(2) Amritsar(1) ";
    }
    if(st==6 )
    { s1="J&K";
        if(loc==1)
             c= 10000;
              s2="5 nights 6 days Srinagar(2) Pahalgam(1) Gulmarg(1) houseboat(1) ";
        if(loc==2)
            c= 20000;
             s2=" 4 nights 5 days ";
        if(loc==3)
            c= 27000;
             s2=" Ladakh 4 night 5 days ";
    }
    if(st==7 )
    {
        s1="UTTARAKHAND";
        if(loc==1)
             c= 20000;
              s2=" 7 nights 8 days ";
        if(loc==2)
            c= 8000;
             s2=" Nainital with Jim Corbett 4 nights 5 days";
        if(loc==3)
            c= 6500 ;
            s2="Mussoorie with Dhanautli 3 nights 4 days ";
    }
    if(st==8 )
    { s1="SIKKIM";
        if(loc==1)
             c= 9000;
              s2="Sikkim with Nathula pass 3 nights 4 days ";
        if(loc==2)
            c= 16000;
             s2="Gangtok Darjeeling 5 nights 4 days ";
        if(loc==3)
            c= 23999;
             s2=" Gangtok tsomgo lake baba mandir lachen gurudongmar lake leachung yumthang vallry Gangtok darjeeling 7 nights 8 days ";
    }
     int n;
     char C;
        cout<<"Enter Number of Passengers : ";
        cin>>n;
         string Name[n],age[n];
        for(int i=0;i<n;i++)
        {
            cout<<"Enter details of Passenger no. "<<i+1<<endl;
            cout<<"Enter Name:";
            cin>>Name[i];
            cout<<"Enter age :";
            cin>>age[i];
        }
        update_bookmatrix1(st,loc,n);
       
        int m;
       cout<<"\n\n\t\tTOTAL TRIP COST : "<<c*n;
       cout<<"\nDo you want to cancel the trip(Y/N): ";
       cin>>C;
       if(C=='Y' || C=='y')
            return;
       cout<<"\nENTER 1 FOR PAYMENT :";
       cin>>m;
       cout<<"\n ✅   PAYMENT SUCCESSFULL !   "       ;
 
   
    cout<<" \n\n\t\t\t** 🔸 RECEIPT 🔸 ** " ;
       
         cout<<"\n\n\t\tSelected Type : Indian Tour Package";
         cout<<"\n\t\tPackage : "<<s1;
          cout<<"\n\t\tLOCATION: "<<s2;
         cout<<"\n\t\tTOTAL COST :"<<c*n<<endl;
          cout<<"\n\t\t----------------------------------------------------------\n";
         cout<<"\t\t| Passenger No.\t|\tPassenger Name\t|\tAge \t|\n"<<endl;
         for(int j=0;j<n;j++)
         {
         cout<<"\t \t|\t"<<j+1<<" |\t\t"<<Name[j]<<" |\t\t"<< age[j] <<" |"<<endl;
         }
         cout<<"\t\t---------------------------------------------------------\n";
}

void International_tour::SG(int ch2)
{
cout<<"\n1. 5 days 4 nights : Rs.85000 per person"<<endl;
cout<<"2. 7 days 6 nights(with cruise) : Rs.100000 per person";

cout<<"\nDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch1;
book_trip(ch2,ch1); //passing which trip has to be booked

}
else
return;
}

void International_tour::AUS(int ch2)
{
cout<<"\n1. 9 days 8 nights : Rs.319500 per person"<<endl;

cout<<"\nDo you want to book the trip? (Y/N): ";
cin>>book;
if(book=='Y')
{
book_trip(ch2,1); //passing which trip has to be booked
}
else
return;
}

void International_tour::USA(int ch2)
{
cout<<"\n1. East USA->5 nights 6 Days : Rs.115000 per person"<<endl;
cout<<"2. West USA-> 6 nights 7 days : Rs.126000 per person";

cout<<"\nDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch1;
book_trip(ch2,ch1); //passing which trip has to be booked

}
else
return;
}

void International_tour::EUROPE(int ch2)
{
cout<<"\n1. 6 days 5 nights : Rs.165000 per person"<<endl;
cout<<"2. 16 days 17 nights : Rs.455000";

cout<<"\nDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch1;
book_trip(ch2,ch1); //passing which trip has to be booked

}
else
return;
}

void International_tour::DUBAI(int ch2)
{
cout<<"\n1. 6 days 5 nights : Rs.75000 per person"<<endl;
cout<<"2. 7 days 6 nights : Rs.90000 per person";

cout<<"\nDo you want to book any? (Y/N): ";
cin>>book;
if(book=='Y')
{
cout<<"Which trip do you wish to book? ";
cin>>ch1;
book_trip(ch2,ch1); //passing which trip has to be booked

}
else
return;
}

void International_tour::display()
{
   
     cout<<"MENU:";
     cout<<"\n\t🌟 1.Singapore";
     cout<<"\n\t🌟 2.Australia";
     cout<<"\n\t🌟 3.United states of America";
     cout<<"\n\t🌟 4.Europe";
     cout<<"\n\t🌟 5.Dubai";
     cout<<"\nEnter your choice : ";
     cin>>ch2;
     cout<<endl;
     switch(ch2)
     {
      case 1:
      SG(ch2);
      break;
     
      case 2:
      AUS(ch2);
      break;
     
      case 3:
      USA(ch2);
      break;
     
      case 4:
      EUROPE(ch2);
      break;
     
      case 5:
      DUBAI(ch2);
      break;  
     }
}

void International_tour::book_trip(int st2,int loc2)
{
    int c,money;
    string s1,s2;
    //cout<<"st2: "<<st2;
   if(st2==1 )
    {  s1="Singapore";
        if(loc2==1)
              c=85000;
              s2="5 days 4 nights ";
        if(loc2==2)
            c=100000;
            s2=" 7 days 6 nights(with cruise) ";
    }
    if(st2==2)
    {if(loc2==1)
             c=319500;
             s1="Australia";
             s2="9 days 8 nights ";
    }
    if(st2==3 )
    {   s1="United states of America";
        if(loc2==1)
             c=115000;
              s2=" East USA->5 nights 6 Days";
        if(loc2==2)
           c=126000;
             s2="West USA-> 6 nights 7 days ";
    }
    if(st2==4 )
    { s1="Europe";
        if(loc2==1)
             c= 165000;
              s2="  6 days 5 nights";
        if(loc2==2)
            c=455000;
             s2="16 days 17 nights ";
    }
    if(st2==5)
    { s1="DUBAI";
        if(loc2==1)
             c= 75000;
              s2="6 days 5 nights";
        if(loc2==2)
            c= 90000;
            s2="7 days 6 nights";
    }
   
     int n;
     char C;
        cout<<"Enter Number of Passengers : ";
        cin>>n;
         string Name[n],age[n];
        for(int i=0;i<n;i++)
        {
            cout<<"Enter details of Passenger no. "<<i+1<<endl;
            cout<<"Enter Name:";
            cin>>Name[i];
            cout<<"Enter age :";
            cin>>age[i];
        }
       
        update_bookmatrix2(st2,loc2,n);
        int m;
       cout<<"\n\t\tTOTAL TRIP COST : "<<c*n;
       cout<<"\nDo you want to cancel the trip(Y/N): ";
       cin>>C;
       if(C=='Y' || C=='y')
            return;
       cout<<"\nENTER 1 FOR PAYMENT :";
       cin>>m;
       cout<<"\n ✅   PAYMENT SUCCESSFULL !   "       ;
   cout<<"\n\nEnter the money(for currency change): ";
   cin>>money;
   //cout<<"st2: "<<st2;
   if(st2==1)
   {
        cout<<"1 Singapore Dollar = 61.73 Indian Rupee";
       cout<<"\nAfter currency conversion you will get: "<<money/61.73<<" Singapore dollars\n";

   }
   if(st2==2)
   {
               cout<<"1 Australian Dollar = 56.31 Indian Rupee";
       cout<<"\nAfter currency conversion you will get: "<<money/56.31<<" Australian dollars\n";    
   }
   if(st2==3)
   {
       cout<<"1 United States  Dollar = 82.75 Indian Rupee";
       cout<<"\nAfter currency conversion you will get: "<<money/82.75<<" United States  dollars\n";
   }
   if(st2==4)
   {
       cout<<"1 Euro = 88.76 Indian Rupee";
       cout<<"\nAfter currency conversion you will get: "<<money/88.76<<" Euros\n";
   }
   if(st2==5)
   {
       cout<<"1 United Arab Emirates Dirham = 22.53 Indian Rupee";
       cout<<"\nAfter currency conversion you will get: "<<money/22.53<<" United Arab Emirates Dirham\n";
   }
    cout<<"\n\n\t\t\t\t ** 🔸 RECEIPT 🔸 ** " ;
       
         cout<<"\n\n\t\tSelected Type : INTERNATIONAL Tour Package";
         //cout<<c;
         cout<<"\n\t\tPackage : "<<s1;
          cout<<"\n\t\tLocation : "<<s2;
         cout<<"\n\t\t\tTOTAL COST :"<<c*n<<endl;
          cout<<"\n\t\t----------------------------------------------------------\n";
         cout<<"\t\t| Passenger No.\t|\tPassenger Name\t|\tAge \t|\n"<<endl;
         for(int j=0;j<n;j++)
         {
         cout<<"\t \t|\t"<<j+1<<" |\t\t"<<Name[j]<<" |\t\t"<< age[j] <<" |"<<endl;
         }
         cout<<"\t\t---------------------------------------------------------\n";
}


int main()
{

    int ch,rating;
    Indian_tour obj;
    International_tour ob;
    book_matrix1();
    book_matrix2();
    do
    {
    cout<<"\n\t\t\t================================";
cout<<"\n\t\t\t ✈ TOURISM MANAGEMENT SYSTEM ✈ ";
cout<<"\n\t\t\t================================\n";
    cout<<"\n\t\t\t   ** 🟢  WELCOME 🟢 **\n";
    Login();
    cout<<"\n====================================================================";
    cout<<" \nMENU :\n\t🔷 1.INTERNATIONAL TOUR PACKAGE\n\t🔷 2.INDIAN TOUR PACKAGE\n\t🔷 3.Exit\n ";
    cout<<"Enter your choice : ";
    cin>>ch;
     switch(ch)
        {
            case 1:
                   ob.display();
                break;
            case 2:
                    obj.display();
                break;
            case 3: break;
            default :
                cout<<"Enter correct choice ";
        }
       
    cout<<"\nGive Rating(from 5 stars) : ";
    cin>>rating;
   
    cout<<"\n\t\t ********* 😊  Thank you for visiting (¬‿¬) 😊 *********\n";
   cout<<"_______________________________________________________________________________________\n";
   
}while(ch!=3);
    return 0;
}
 