
#include <bits/stdc++.h> 
using namespace std;


void findNumbers(vector<int>& ar, int sum,
	vector<vector<int> >& res,
	vector<int>& r, int i)
{
	//E�er Mevcut toplam negatif olursa
	if (sum < 0)
		return;


	if (sum == 0)
	{
		res.push_back(r);
		return;
	}

	//toplam de�erinden listenin elamanlar�n� ��kar 
	//�rnek olarak 8-2-2-2-2=0
	while (i < ar.size() && sum - ar[i] >= 0)
	{

		// Dizideki her eleman
		 // toplam�na katk�da bulunabilecek  
		r.push_back(ar[i]); // elamanlar� listeye ekle

		// recursive:�zyinelemeli mant�k fonksiyonun i�inde ko�uldan sonra tekrar fonksiyonu �a��r.
		findNumbers(ar, sum - ar[i], res, r, i);
		i++;

		//listeden elamanlar� ��kar
		r.pop_back();
	}
}


// verilmi� olan  toplam de�erine t�m  liste  kombinasyonlar�n� d�nd�ren veri yap�s�
// 
vector<vector<int> > combinationSum(vector<int>& ar,
	int sum)
{
	// listeyi s�rala
	sort(ar.begin(), ar.end());

	// ayn� elamanlar� indexten sil 
	ar.erase(unique(ar.begin(), ar.end()), ar.end());

	vector<int> r;
	vector<vector<int> > res;
	findNumbers(ar, sum, res, r, 0);

	return res;
}

// Driver code 
int main()
{
	vector<int> ar;
	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(8);
	int n = ar.size();

	int sum = 8; // verilen toplam de�eri
	vector<vector<int> > res = combinationSum(ar, sum);

	// liste bo� ise
	if (res.size() == 0)
	{
		cout << "Emptyn";
		return 0;
	}

	// Sonu�ta saklanan t�m kombinasyonlar� ekrana yazd�r
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i].size() > 0)
		{
			cout << " ( ";
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << ")";
		}
	}
}
}