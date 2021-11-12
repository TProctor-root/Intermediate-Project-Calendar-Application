#include <iostream>
#include <iomanip>
using namespace std;

bool decideMath(int year) {
   return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int monthDay (int month, int year) {
   switch (month) {
	  case 2:
	    return decideMath(year) ? 29 : 28;
	  case 11: 
	    return 30;
	  default: 
	    return 31;
  }   
}

int weekLimit(int month, int year) {	
   int x = 1;
   int y = year - (month < 3);
   int num[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
   return (y + y / 4 - y / 100 + y / 400 + num[month - 1] + x) % 7;
}

int main() {
	int year, month;
	cout << "Input year: ";
	cin >> year;
	cout << "Input month: ";
	cin >> month;
	
	string Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   
    int a = monthDay(month, year);
    int b = weekLimit(month, year);
    
    cout << endl;
   
    cout << "\t" << Months[month-1] << " " << year << endl;
    cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
   
    for(int x = 0; x < b; x++) { 
        cout << "    ";
    }
   
    for(int x = 1; x <= a; x++) {
	   cout << setw(3) << x << " ";
	   if (++b > 6) { 
	       b = 0; 
	       cout << endl << " "; 
	   }
    }
    return 0;
}
