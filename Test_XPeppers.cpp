#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <cmath>

#include "data.h"

using namespace std;

struct shop
{
	string goods; // kind of goods 
	int type; // type=1 if good is food, book or medical product, 0 otherwise
	double price; // shelf price
	int import; // it is 1 if the object is imported, 0 otherwise
};

void define_tax(shop *s, int count);

int main()
{
	
int d=0;
cout<<"Do you want insert data? "<<endl;
cout<<"(1 for Yes, 0 for using the test): "<<endl;
cin>>d;

if (d==1)
{
	int cnt=0;
	cout<<"How much shopping? "<<endl;
	cin>>cnt;
	shop *test= new shop[cnt];
	for (int i=0;i<cnt;i++)
	{
		cout<<"Enter shopping (i.e book): "<<endl;
		cin.ignore();
		getline(cin,test[i].goods);
		cout<<"Enter 1 if book, food or medical product; 0 otherwise: "<<endl;
		cin>>test[i].type;
		cout<<"Enter price: "<<endl;
		cin>>test[i].price;
		cout<<"Enter 1 if the product is imported; 0 otherwise: "<<endl;
		cin>>test[i].import;
	}
	define_tax(test,cnt);
}
else if (d==0)
{
	shop *input1= new shop[3];
	input1[0]={"books", 1, 12.49, 0};
	input1[1]={"CD", 0, 14.99, 0};
	input1[2]={"chocolate bar", 1, 0.85, 0};
	
	shop *input2= new shop[2];
	input2[0]={"box chocolates", 1, 10.00, 1};
	input2[1]={"perfume", 0, 47.50, 1};
	
	shop *input3= new shop[4];
	input3[0]={"perfume", 0, 27.99, 1};
	input3[1]={"bottle of perfume", 0, 18.99, 0};
	input3[2]={"headache pills", 1, 9.75, 0};
	input3[3]={"box chocolate", 1, 11.25, 1};
	
	
	define_tax(input1,3);
	define_tax(input2,2);
	define_tax(input3,4);
}
else
{
	cout << "  ERROR: No value allowed" << endl;
}

return 0;
}


# define sales tax
void define_tax(shop *s, int count)
{
	double newprice[count]={}; 
	double tax=0;
	string str[count]=" ";
	for (int i=0; i<count; i++)
	{
		newprice[i]=s[i].price;
		if (s[i].type == 0)
		{
			newprice[i] = newprice[i] + floor((s[i].price*0.1)*20 + 0.5)/20;
			tax=tax + floor((s[i].price*0.1)*20 + 0.5)/20;
		}
		if (s[i].import == 1)
		{
			str[i]="(imported)";
			newprice[i] = newprice[i] + floor((s[i].price*0.05)*20 + 0.5)/20;
			tax=tax + floor((s[i].price*0.05)*20 + 0.5)/20;
		}	
		if (s[i].import != 1,0 && s[i].type != 1,0)
		{
			cout << "  ERROR: No value allowed" << endl;
		}
	}
	double total=0;
	cout<<setprecision(2)<<fixed;
	for (int i=0; i<count;i++)
	{
		total+=newprice[i];
		
		cout << "1"<<str[i]<<s[i].goods<<": "<<newprice[i]<<endl;
	}
	cout<<"Sales Taxes: "<<tax<<endl;
	cout<<"Total: "<<total<<endl;
	cout<<"\n";
}


