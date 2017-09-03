#include <iostream>
#include <fstream>
#include<string>
#include<ctime>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>

#define iter 3   // Number of selected rows for tesing

using namespace std;

struct shop
{
	string goods; // kind of goods 
	int type; // type=1 if good is food, book or medical product, 0 otherwise
	double price; // shelf price
	int import; // it is 1 if the object is imported, 0 otherwise
};
void define_tax(shop *s, int count);

int main () {
	
shop *test= new shop[iter];

// import data from txt file
string line;
ifstream file ("data.txt");

int random = 0;
int numOfLines = 0;

// select random line from table and store data in vectors
if (file.is_open())
{
	string a[9]=" "; 
	int b[9]={};
	double c[9]={};
	int d[9]={};
	srand(time(NULL));
	for (int j=0; j<iter; j++)
	{
		file.clear();
		file.seekg(0, ios::beg);
		for (int g=0; g<9; g++)
		{
			file>>a[g]>>b[g]>>c[g]>>d[g];
		}
		random = rand() % 9;

		test[j]={a[random], b[random], c[random], d[random]};  // fill the shop basket
	}
	define_tax(test,3);  // print receipt

	file.close();
}
else cout << "Unable to open file"; 

return 0;
}

// define sales tax and print receipt
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

