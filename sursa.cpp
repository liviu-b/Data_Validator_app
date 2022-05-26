#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int validare(string cnp)
{
	int k[12] = { 2,7,9,1,4,6,3,5,8,2,7,9 }; 
	int s = 0;
	for (int i = 0; i < 12; i++)
	{
		s = (s + (cnp[i] - '0') * k[i]) % 11;
	}
	if (s == 10)
		s = 1;
	if (s == (cnp[12] - '0'))
		return 1;
	else
		return 0;
}
int an(string cnp)
{
	int a;
	a = (cnp[1] - '0') * 10;
	a += (cnp[2] - '0');
	if (cnp[0] == '1' || cnp[0] == '2')
		a += 1900;
	if (cnp[0] == '3' || cnp[0] == '4')
		a += 1800;
	if (cnp[0] == '5' || cnp[0] == '6')
		a += 2000;
	return a;
}
int luna(string cnp)
{
	int l;
	l = (cnp[3] - '0') * 10;
	l += (cnp[4] - '0');
	return l;
}
int ziua(string cnp)
{
	int z;
	z = (cnp[5] - '0') * 10;
	z += (cnp[6] - '0');
	return z;
}
bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}


bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}


bool is_valid(string email)
{

	if (!isChar(email[0])) {

		
		return 0;
	}

	int At = -1, Dot = -1;

	
	for (int i = 0;
		i < email.length(); i++) {

		if (email[i] == '@') {

			At = i;
		}

		else if (email[i] == '.') {

			Dot = i;
		}
	}

	if (At == -1 || Dot == -1)
		return 0;


	if (At > Dot)
		return 0;

	
	return !(Dot >= (email.length() - 1));
}

int main()
{
	string nume;
	string prenume ;
	string cnp;
	string telefon;
	string email;

	cout << "Nume: ";
	getline(cin, nume);

	cout << "Prenume: ";
	getline(cin, prenume);
	 
	cout << "CNP: ";
	getline(cin, cnp);

	cout << "Telefon: ";
	getline(cin, telefon);

	cout << "Email: ";
	getline(cin, email);


	 
	cout << endl;
	int greseala = 0;

	for (int i = 0; i < nume.length(); i++)
	{
		if ('A' > nume[i] || nume[i] > 'Z')
		{
			greseala++;
			cout << "Nume invalid" << endl;
			break;
		}
	}

	string word = "";
	vector<string> prenumeVect;
	
	for (auto x : prenume)
	{
		if (x == ' ')
		{
			prenumeVect.push_back(word);
			word = "";
		}
		else {
			word = word + x;
		}
	}

	prenumeVect.push_back(word);
	
	for (int i = 0; i < prenumeVect.size(); i++)
	{
		 
		if ('A' > prenumeVect[i][0] || prenumeVect[i][0] > 'Z')
		{
			cout << "Prenume invalid" << endl;
			greseala++;
			break;
		}
	}

	 
	if (cnp.length() != 13)
	{
		greseala++;
		cout << "Lungime CNP invalida" << endl;
	}
	else if(validare(cnp)!=1 && cnp.length()==13)

	{
		greseala++;
		cout << "Validare CNP invalida" << endl;
	}
	
	
	if (telefon.length() != 10)
	{
		greseala++;
		cout << "Lungime numar telefon invalida" << endl;

	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (telefon[i] > '9' || telefon[i] < '0')
			{
				cout << "Format telefon invalid" << endl;
				greseala++;
				break;
			}
		}
	}


	bool valid_email = is_valid(email);

	if (valid_email != 1)
	{
		cout << "Format email invalid"<<endl;
		greseala++;
	}
	 
	if (greseala == 0)
	{
		cout << "Datele au fost introduse corect" << endl;
		cout << "Data nasterii: " << ziua(cnp) << "\\" << luna(cnp) << "\\" << an(cnp);
	}
	else

	{
		cout << "Au fost semnalizate " << greseala << " campuri invalide";
	}

}

 