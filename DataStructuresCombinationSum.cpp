
#include <bits/stdc++.h> 
using namespace std;


void findNumbers(vector<int>& ar, int sum,
	vector<vector<int> >& res,
	vector<int>& r, int i)
{
	//Eðer Mevcut toplam negatif olursa
	if (sum < 0)
		return;


	if (sum == 0)
	{
		res.push_back(r);
		return;
	}

	//toplam deðerinden listenin elamanlarýný çýkar 
	//örnek olarak 8-2-2-2-2=0
	while (i < ar.size() && sum - ar[i] >= 0)
	{

		// Dizideki her eleman
		 // toplamýna katkýda bulunabilecek  
		r.push_back(ar[i]); // elamanlarý listeye ekle

		// recursive:özyinelemeli mantýk fonksiyonun içinde koþuldan sonra tekrar fonksiyonu çaðýr.
		findNumbers(ar, sum - ar[i], res, r, i);
		i++;

		//listeden elamanlarý çýkar
		r.pop_back();
	}
}


// verilmiþ olan  toplam deðerine tüm  liste  kombinasyonlarýný döndüren veri yapýsý
// 
vector<vector<int> > combinationSum(vector<int>& ar,
	int sum)
{
	// listeyi sýrala
	sort(ar.begin(), ar.end());

	// ayný elamanlarý indexten sil 
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

	int sum = 8; // verilen toplam deðeri
	vector<vector<int> > res = combinationSum(ar, sum);

	// liste boþ ise
	if (res.size() == 0)
	{
		cout << "Emptyn";
		return 0;
	}

	// Sonuçta saklanan tüm kombinasyonlarý ekrana yazdýr
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