#include <iostream>
#include <cstring>


using namespace std;


class book{
private:
 char *author,*title,*publisher;
 int *stock;
 float *price;
public:
 book(){
 author=new char[30];
 title=new char[30];
 publisher=new char[30];
 price=new float;
 stock=new int;
}
void newdata();
void editdata();
void showdata();
int search(char[],char[]);
void buybook();

};

void book::newdata(){
    cin.ignore();
    cout<<"\nEnter author's name: ";
    cin.getline(author,30);
    cout<<"\nEnter title name: ";
    cin.getline(title,30);
    cout<<"\nEnter the name of the publisher: ";
    cin.getline(publisher,30);
    cout<<"\nEnter the price: ";
    cin>>*price;
    cout<<"\nEnter stock position: ";
    cin>>*stock;
}

void book::editdata(){
    cout<<"\nEnter author's name: ";
    cin.getline(author,30);
    cout<<"\nEnter title name: ";
    cin.getline(title,30);
    cout<<"\nEnter the name of the publisher: ";
    cin.getline(publisher,30);
    cout<<"\nEnter the price: ";
    cin>>*price;
    cout<<"\nEnter stock position: ";
    cin>>*stock;
}

void book::showdata()	{
    cout<<"\nAuthor Name: "<<author;
    cout<<"\nTitle Name: "<<title;
    cout<<"\nPublisher Name: "<<publisher;
    cout<<"\nPrice: "<<*price;
    cout<<"\nStock Position: "<<*stock;

}


int book::search(char enteredtitle[30], char enteredauthor[30]){

    if(strcmp(enteredtitle,title)==0 && strcmp(enteredauthor,author)==0)
	    
           return 1;

    else
	   return 0;

	}

void book::buybook(){
    int count;
    cout<<"\nEnter the number of the books to you want to buy: ";
    cin>>count; 

	if(count<=*stock){
          *stock=*stock-count;
	  cout<<"\nBooks bought succesfully!";
	  cout<<"\nAmount: "<<(*price)*count;
	  }

    else

          cout<<"\nRequired books not in stock: ";

	}


 int main(){
         book *B[20];
	 int i=0,t,choice;
	 char enteredtitle[30],enteredauthor[30];
	 while(1)	{
		cout<<"\n\n======Book Shop Management System======"
		<<"\n1. Entry of the new book"
		<<"\n2. Buy the book"
		<<"\n3. Search for the book"
		<<"\n4. Edit details of the book"
		<<"\n5. Exit"
		<<"\n\nEnter your choice: ";
		cin>>choice;

        switch(choice){

          case 1:
		  B[i]=new book;
		  B[i]->newdata();
		  ++i;
	      break;

		
          case 2:
		  cin.ignore();
		  cout<<"\nEnter the title of the book: ";
		  cin.getline(enteredtitle,30);
		  cout<<"Enter the author's name: ";  
		  cin.getline(enteredauthor,30);
		  for(t=0;t<i;t++)	{
					if(B[t]->search(enteredtitle,enteredauthor))	{
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Not in Stock";

				break;

	  case 3: 
		        cin.ignore();
				cout<<"\nEnter the title of the book: "; 
				cin.getline(enteredtitle,30);
				cout<<"Enter the author's name:  ";  
				cin.getline(enteredauthor,30);

				for(t=0;t<i;t++)	{
					if(B[t]->search(enteredtitle,enteredauthor))	{
						cout<<"\nBook found successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis book is not in stock";
				break;


	 case 4: 
		        cin.ignore();
				cout<<"\nEnter the title of the book: "; 
				cin.getline(enteredtitle,30);
				cout<<"Enter the author of the book: ";  
				cin.getline(enteredauthor,30);

				for(t=0;t<i;t++)	{
					if(B[t]->search(enteredtitle,enteredauthor))	{
						cout<<"\nBook found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis book is not in stock";
				break;

        case 5: exit(0);


	default: cout<<"\nInvalid choice entered!";

		}
	}




	return 0;
}


