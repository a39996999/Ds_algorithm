//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <stack>
#pragma hdrstop

#include "sort.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std ;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
  Memo2 -> Clear() ;

}
//---------------------------------------------------------------------------
int times ;
int n ;
int range ;


void printall(vector<int> data){
	AnsiString s = "" ;

	for (int i = 0 ; i < data.size() ; i++){
		s += IntToStr(data[i]) + " " ;
	}

	Form1 -> Memo2 -> Lines -> Add(s) ;
}

void Bubble_sort(vector<int> data){
	for (int i = 0 ; i < data.size() ; i++){
		for (int j = i+1 ; j < data.size() ; j++){
			if (data[i] > data[j])
				swap(data[i] ,data[j]) ;
		}
	}
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("Bubble sort :") ;
		printall(data) ;
	}
}

void insert_sort(vector<int> data){
	int m = data.size() ;
	int j ;

	for (int i = 1 ; i < m ; i++){
		int temp = data[i] ;

		for (j = i ; j > 0 && temp < data[j-1] ; j--){
			data[j] = data[j-1] ;
		}
		data[j] = temp ;
	}
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("insert sort :") ;
		printall(data) ;
	}
}

void select_sort(vector<int> data){
	for (int i = 0 ; i < data.size() ; i++){
		int max = i ;

		for (int j = i ; j < data.size() ; j++){
			if (data[j] < data[max]){
				max = j ;
			}
		}

		swap(data[i] ,data[max]) ;
	}
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("select sort :") ;
		printall(data) ;
	}
}

void quick_sort(vector<int>& data ,int l ,int r){
	if (l >= r) return ;

	int i = l ;
	int j = r ;
	int p = data[l] ;

	while (i <= j){
		while (data[i] < p && i <= j) i++ ;
		while (data[j] > p && i <= j) j-- ;

		if (i <= j)
			swap(data[i++] ,data[j--]) ;
	}
	if (l <= j)
		swap(data[l] ,data[j]) ;

	quick_sort(data ,l ,j) ;
	quick_sort(data ,i ,r) ;

	return ;
}
void rquick(vector<int> data){
	vector<int> temp(data) ;

	quick_sort(temp ,0 ,data.size()-1) ;
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("rquick sort :") ;
		printall(temp) ;
	}
}

void nrquick(vector<int> data){
    vector<int> temp(data) ;
	stack<int> sk ;

	sk.push(data.size()-1) ;
	sk.push(0) ;

	while(!sk.empty()){
		int i = sk.top() ; sk.pop() ;
		int j = sk.top() ; sk.pop() ;
		int l = i ;
		int r = j ;
		int p = data[l] ;

        while (i <= j){
			while (data[i] < p && i <= j) i++ ;
			while (data[j] > p && i <= j) j-- ;

		if (i <= j)
			swap(data[i++] ,data[j--]) ;
		}

		if (l <= j)
			swap(data[l] ,data[j]) ;
		if (l < j){
			sk.push(j) ;
			sk.push(l) ;
		}
		if (i < r){
			sk.push(r) ;
			sk.push(i) ;
		}
	}
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("nrquick sort :") ;
		printall(data) ;
	}
}

void merge_sort(vector<int>& data ,int l ,int r){
	if (l+1 >= r) return ;

	int m = l + (r - l)/2 ;

	merge_sort(data ,l ,m) ;
	merge_sort(data ,m ,r) ;

	int i = l ;
	int j = m ;
	int index = 0 ;
	vector<int> temp(data.size()) ;

	while (i < m || j < r){
		if (j == r || (i < m && data[i] < data[j]))
			temp[index++] = data[i++] ;
		else
			temp[index++] = data[j++] ;
	}
	for (int i = 0 ; i < index ; i++){
		data[l+i] = temp[i] ;
	}
}

void merge(vector<int>& data ,int le ,int m ,int re){
	vector<int> temp(data.size() ,0) ;
	int i = le ;
	int j = m ;
	int index = 0 ;

	while (i < m || j < re){
		if (j == re || (i < m && data[i] < data[j]))
			temp[index++] = data[i++] ;
		else{
			temp[index++] = data[j++] ;
		}
	}
	for (int k = 0 ; k < index ; k++){
		data[le+k] = temp[k] ;
	}
}
void nrmerge(vector<int> data){
	int len = 2 ;

	while (len/2 <= data.size()){
		int l ;
		for (l = 0 ; l <= data.size() ; l += len){
			merge(data ,l ,l+len/2 ,l+len) ;

			if (l+len*2 > data.size()) break ;
		}
		if (l+len < n){
			merge(data ,l ,l+len ,n) ;
		}
		len *= 2 ;
	}
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("NRmerge sort :") ;
		printall(data) ;
	}
}

void rmerge(vector<int> data){
	vector<int> temp(data) ;

	merge_sort(temp ,0 ,data.size()) ;
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("Rmerge sort :") ;
		printall(temp) ;
	}
}

void restore(vector<int>& data ,int s ,int t){
	int i = s ,j ;

	while (i <= t/2){
		if (2*i+1 > n ||data[2*i] < data[2*i+1]){
			j = 2*i ;
		}
		else
			j = 2*i+1 ;

		if (data[i] < data[j]) break ;

		swap(data[i] ,data[j]) ;
		i = j ;
	}
}
void heap_sort(vector<int> data){
	vector<int> temp(data.size()+1 ,0) ;
	AnsiString s = "" ;

	for (int i = 1 ; i <= data.size() ; i++){
		temp[i] = data[i-1] ;
	}

	for (int i = (temp.size()-1)/2 ; i >= 1 ; i--){
		restore(temp ,i ,temp.size()-1) ;
	}

	for (int i = temp.size()-1 ; i >= 1 ; i--){
	   s += IntToStr(temp[1]) + " " ;
	   temp[1] = temp[i] ;

	   restore(temp ,1 ,i-1) ;
	}
	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("heap sort :") ;
		Form1 -> Memo2 -> Lines -> Add(s) ;
	}
}

void radix_sort(vector<int> data){
	const int c = 10;
	vector<vector<int>> buckets(c);

	int max = 0 ;
	for (int i = 0 ; i < data.size() ; i++){
		if (data[i] > max)
			max = data[i] ;
	}
	int radix = log10(max)+1 ;

	for (int pos = 0; pos <= radix; pos++)
	{
		int d = (int)(pow(10, pos));
		for (int i = 0 ; i < data.size() ; i++)
			buckets[(data[i] / d) % 10].push_back(data[i]);

		int index = 0;


		for (int i = 0 ; i < buckets.size() ; i++){
			for (int j = 0 ; j < buckets[i].size() ;j++){
				data[index++] = buckets[i][j] ;
			}
			buckets[i].clear() ;
		}
	}

	AnsiString s = ""  ;
	for (int j = 0 ; j < data.size() ; j++)
		s += IntToStr(data[j]) + " " ;

	if (Form1 -> CheckBox11 -> Checked){
		Form1 -> Memo2 -> Lines -> Add("radix sort :") ;
		Form1 -> Memo2 -> Lines -> Add(s) ;
	}
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Sorting");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++)
	{
		TLineSeries *Series=new TLineSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}

	Chart1->Series[0]->Title =  "Bubble Sort" ;
	Chart1->Series[1]->Title =  "Insertion Sort" ;
	Chart1->Series[2]->Title =  "Select Sort" ;
	Chart1->Series[3]->Title =  "RQuick Sort" ;
	Chart1->Series[4]->Title =  "NRQuick Sort" ;
	Chart1->Series[5]->Title =  "RMerge Sort" ;
	Chart1->Series[6]->Title =  "NRMerge Sort" ;
	Chart1->Series[7]->Title =  "Heap Sort" ;
	Chart1->Series[8]->Title =  "Radix Sort" ;

	times = StrToInt(Edit1 -> Text) ;
	n = StrToInt(Edit2 -> Text) ;
	range = StrToInt(Edit3 -> Text) ;

	for (int j = 1 ; j <= times ; j++){
		vector<int> data(j*n ,0) ;
		AnsiString s = "" ;

		for (int i = 0 ; i < j*n ; i++){
			data[i] = rand()%range+1 ;  // 產生數組
			s += IntToStr(data[i]) + " " ;
		}
		if (Form1 -> CheckBox11 -> Checked)
			Memo2 -> Lines -> Add(s) ;


		if (CheckBox1 -> Checked){
			double start = clock() ;
			select_sort(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[0]->Add( diff ,j*n ,clHighlight);
		}

		if (CheckBox2 -> Checked){
			double start = clock() ;
			insert_sort(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[1]->Add( diff ,j*n ,clMaroon);
		}

		if (CheckBox3 -> Checked){
			double start = clock() ;
			Bubble_sort(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[2]->Add( diff ,j*n ,clPurple);
		}


		if (CheckBox4 -> Checked){
			double start = clock() ;
			rquick(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[3]->Add( diff ,j*n ,clMoneyGreen);

		}
		if (CheckBox5 -> Checked){
			double start = clock() ;
			nrquick(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[4]->Add( diff ,j*n ,clNavy);
		}
		if (CheckBox6 -> Checked){
			double start = clock() ;
			rmerge(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[5]->Add( diff ,j*n ,clTeal);

		}
		if (CheckBox7 -> Checked){
			double start = clock() ;
			nrmerge(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[6]->Add( diff ,j*n ,clRed);
		}
		if (CheckBox8 -> Checked){
			double start = clock() ;
			heap_sort(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[7]->Add( diff ,j*n ,clOlive);

		}
		if (CheckBox9 -> Checked){
			double start = clock() ;
			radix_sort(data) ;
			double end = clock() ;
			double diff = (end-start)/ CLOCKS_PER_SEC ;
			Chart1->Series[8]->Add( diff ,j*n ,clGreen);
		}


		Memo2 -> Lines -> Add("--------------") ;
	}
}
//---------------------------------------------------------------------------
