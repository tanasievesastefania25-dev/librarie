#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
//2
class Librarie {
private:
const int idLibrarie;
char* nume;
int nrCarti;
float* preturiCarti;
int nrAngajati;
static int contor;
//3
public:
	Librarie():idLibrarie(contor++)
	{ 
	 this->nume=new char[strlen("NA")+1];
	 strcpy(this->nume,"NA");
	this->nrCarti=0;
	this->nrAngajati=2;
	this->preturiCarti=nullptr;
	}
	Librarie(const int idLibrarieInit, char* numeInit, int nrCartiInit, float* preturiCartiInit, int nrAngajatiInit):idLibrarie(contor++)
	{
	this->nume=new char[strlen(numeInit)+1];
	strcpy(this->nume,numeInit);
	this->nrCarti=nrCartiInit;
	this->preturiCarti=new float[nrCartiInit];
	for (int i = 0; i < nrCartiInit;i++) {
		this->preturiCarti[i]=preturiCartiInit[i];
	}

	this->nrAngajati=nrAngajatiInit;
	}
	~Librarie() {
		if (this->nume != nullptr)
		{
			delete[] this->nume;
		}
		if(this->preturiCarti !=nullptr)
		{
		delete[] this->preturiCarti;
		}
		}
		//4
		Librarie(const Librarie& f) : idLibrarie(contor++)
		{
			this->nume=new char[strlen(f.nume)+1];
			strcpy(this->nume,f.nume);
			this->nrCarti=f.nrCarti;
			this->preturiCarti=new float[f.nrCarti];
			for(int i=0;i<f.nrCarti;i++)
			{
			this->preturiCarti[i]=f.preturiCarti[i];
			}
			this->nrAngajati=f.nrAngajati;
		}
		//get si set 
		char* getNume() {
			char* copieNume=new char[strlen(this->nume)+1];
			strcpy(copieNume, this->nume);
			return copieNume;
		}
		void setNume(char* nume)
		{
			if (this->nume != nullptr)
			{
				delete[] this->nume;
			}
			this->nume=new char[strlen(nume)+1];
			strcpy(this->nume,nume);
		}
		int getNrCarti()
		{
			return this->nrCarti;
		}
		int getIdLibrarie()
		{
			return this->idLibrarie;
	}
	//5
		Librarie& operator=(const Librarie& f) {
			if (this->nume != nullptr)
			{
				delete[]this->nume;
			}
			if(this->preturiCarti !=nullptr)
			{
				delete[]this->preturiCarti;
			}
			this->nume=new char[strlen(f.nume)+1];
			strcpy(this->nume,f.nume);
			this->nrCarti=f.nrCarti;
			this->preturiCarti=new float[f.nrCarti];
			for(int i=0;i<f.nrCarti;i++)
			{
				this->preturiCarti[i]=f.preturiCarti[i];
				}
			this->nrAngajati = f.nrAngajati;
				return *this;
						
 

	}
	
};
int Librarie::contor = 0;
int main()
{
	// 1. constructor fara parametri
	Librarie l1;

	// 2. constructor cu parametri
	char numeLib[] = "Carturesti";
	float preturi[] = { 25.5f, 40.0f, 18.9f };
	Librarie l2(1, numeLib, 3, preturi, 5);

	// 3. al doilea obiect cu parametri, ca sa vezi ca id-ul difera
	char numeLib2[] = "Humanitas";
	float preturi2[] = { 30.0f, 55.5f };
	Librarie l3(2, numeLib2, 2, preturi2, 4);

	Librarie l4 = l2;//constr de copiere 
	cout << l2.getIdLibrarie() << endl;   // 1
	cout << l4.getIdLibrarie() << endl;   // 3
	cout << l4.getNrCarti() << endl;      // 3


	Librarie l5;
	l5 = l2;                              // apeleaza operator=
	cout << l5.getNrCarti() << endl;      // 3
	cout << l5.getIdLibrarie() << endl;   // id-ul lui l5, nu al lui l2

	return 0;

}