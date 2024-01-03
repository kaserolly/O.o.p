#include <iostream>
#include <string>
using namespace std;

class Spital
{
	const string cif;
	char* nume;
	string adresa;
	string* medici;
	int nrMedici;
	static int nrSpitale;
public:
	Spital() :cif("")
	{
		this->nume = nullptr;
		this->adresa = "";
		this->medici = nullptr;
		this->nrMedici = 0;
		Spital::nrSpitale++;
	}
	Spital(string _cif, const char* _nume, string _adresa, const string* _medici, int _nrMedici) :cif(_cif), adresa(_adresa), nrMedici(_nrMedici)
	{
		if (_nume != nullptr)
		{
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		else
			this->nume = nullptr;
		this->medici = new string[_nrMedici];
		for (int i = 0; i < _nrMedici; i++)
			this->medici[i] = _medici[i];
		Spital::nrSpitale++;
	}
	Spital(Spital& s):Spital(s.cif, s.nume, s.adresa, s.medici, s.nrMedici)
	{}
	Spital& operator = (Spital& s)
	{
		if (this == &s)
			return *this;
		delete[] this->nume;
		this->nume = new char[strlen(s.nume) + 1];
		strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		delete[] this->medici;
		this->nrMedici = s.nrMedici;
		this->medici = newstring[s.nrMedici];
		for (int i = 0; i < nrMedici; i++)
			this->medici[i] = s.medici[i];
		this->adresa = s.adresa;
		return *this;
	}
	void setNume(constr char* _nume)
	{
		if (_nume != nullptr)
		{
			delete[] this->nume;
			this->nume = new char[strlen(s.nume) + 1];
			strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		}
		else
			this->nume = nullptr;
	}
	void setAdresa(string _adresa) { this->adresa = _adresa; }
	void setMedici(const string* _medicic, int _nrMedici)
	{
		if (_medici != nullptr)
		{
			delete[]this->medici;
			this->nrMedici = _nrMedici;
			this->medici = newstring[s.nrMedici];
			for (int i = 0; i < nrMedici; i++)
				this->medici[i] = s.medici[i];
		}
		else
		{
			this->medici = nullptr;
			this->nrMedici = 0;
		}
	}
	char* getNume()
	{
		char* copy = new char[strlen(this->nume) + 1];
		strcpy_s(copy, strlen(this->nume) + 1, this->nume);
		return copy;
	}
	char* getMedici()
	{
		char* copy = new char[strlen(this->medici) + 1];
		strcpy_s(copy, strlen(this->medici) + 1, this->medici);
		return copy;
	}

	explicit operator int()
	{
		return Spitall::nrSpitale;
	}

	friend ostream& operator << (ostream& os, Spital s);
	friend istream& operator >> (istream& is, Spital& s)
	{
		char* tmp = new char[256];
		cout << endl << endl << "Nume: ";
		is.getline(tmp, 256);
		s.setNume(tmp);
		cout << "Adresa: ";
		is.getline(tmp, 256);
		s.setAdresa(tmp);
		cout << "Nr Medici: ";
		int tmpNr;
		is >> tmpNr;
		is.getline(tmp, 256);
		cout << "Numele pentru " << tmpNr << " medici: ";
		string* medici = new string[tmpNr];
		for (int i = 0; i < tmpNr; i++)
		{
			is.getline(tmp, 256);
			medici[i] = (string)tmp;
		}
		s.setMedici(medici, tmpNr);
		return is;
	}
	~Spital()
	{
		delete[] this->nume;
		delete[] this->adresa;
		//Spital::nrSpitale--;
	}
};

ostream& operator << (ostream& os, Spital& s)
{
	os << "CIF: " << s.cif << endl;
	os << "Nume: " << s.nume << endl;
	os << "Adresa: " << s.adresa << endl;
	os << "Nr medici: " << s.nrMedici << endl;
	for (int i = 0; i < s.nrMedici; i++)
		os << s.medici[i] << " ";
	return os;
}

int Spital::nrSpitale = 0;

int main()
{
	string* medici = new string[3];
	medici[0] = "Medic 1";
	medici[1] = "Medic 2";
	medici[2] = "Medic 3";
	Spital s1, s2("RO1234", "Floreasca", "Bucuresti", medici, 3);
	s2 = s2;
	s1 = s2;
	s1.setNume("Alt nume");
	cout << s2;
	Spital s3;
	cout << (int)s3;
	return 0;
}