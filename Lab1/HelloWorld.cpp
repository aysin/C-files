#include <iostream>
using namespace std;

int main()
{
	int i, j, num;
	i = 1;
	j = 1;
    
	cout << "Enter a side of square: ";
	cin >> num;
    
	while ( i <= num ) {
		j = 1;
		while ( j <= num ) {
			if ( i == 1 || i == num || j == 1 || j == num )
				cout << "*";	// if any one out of 4 argument is true then it will print * otherwise ' '
			else
				cout << " ";	// prints if i=2 and j = 2
			j++;
		}
		cout << endl;
		i++;
	}
    
	return 0;
}