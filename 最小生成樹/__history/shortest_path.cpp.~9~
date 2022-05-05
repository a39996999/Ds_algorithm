//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#pragma hdrstop

#include "shortest_path.h"
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


vector<vector<int>> g ;
int to_weight = 1e6 ;

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n = StrToInt(Edit1 -> Text) ;
	int weight = StrToInt(Edit2 -> Text) ;
	int max_weight = StrToInt(Edit3 -> Text) ;

	g = vector<vector<int>>(n ,vector<int>(n ,0)) ;

	if (CheckBox1 -> State == false){
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < n; j++) {
				if (i == j){
					g[i][j] = to_weight ;
					continue ;
				}
				int temp = rand()%weight+1 ;

				if (temp > max_weight)
					g[i][j] = to_weight ;
				else
					g[i][j] = temp ;
			}
		}
	}
	if (CheckBox1 -> State == true){
		for (int i = 0 ; i < n ; i++){
			for (int j = i ; j < n ; j++){
				if (i == j){
					g[i][j] = 0 ;
					continue ;
				}

				int temp = rand()%weight+1 ;

				if (temp > max_weight){
					g[i][j] = to_weight ;
					g[j][i] = to_weight ;
				}
				else{
					g[i][j] = temp ;
					g[j][i] = temp ;
				}
			}
		}
	}

	if (CheckBox2 -> State == false)
		return ;

	StringGrid1 -> RowCount = n+1 ;
	StringGrid1 -> ColCount = n+1 ;

	for (int i = 0 ; i <= n ; i++){
		for (int j = 0 ; j <= n ; j++){
			if (i == 0 && j == 0) continue ;

			if (i == 0 && j >= 1){
				StringGrid1 -> Cells[j][i] = j-1 ;
			}
			else if (j == 0 && i > 0){
				StringGrid1 -> Cells[j][i] = i-1 ;
			}
			else{
				if (g[i-1][j-1] >= to_weight){
					StringGrid1 -> Cells[j][i] = "∞" ;
				}
				else
					StringGrid1 -> Cells[j][i] = g[i-1][j-1] ;
			}
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	FILE*  fp ;
	AnsiString fname ;
	int n ,weight ,max_weight ;

	if (OpenDialog1 -> Execute()){
		fname = OpenDialog1 -> FileName ;
		fp = fopen(fname.c_str() ,"r") ;
		fscanf(fp ,"%d %d %d %d" ,&n ,&weight ,&max_weight ,&to_weight) ;

		g = vector<vector<int>>(n ,vector<int>(n ,0)) ;

		for (int i = 0 ; i < n ; i++){
			for (int j = 0 ; j < n ; j++){
				fscanf(fp ,"%d" ,&g[i][j]) ;
			}
		}
	}

	if (CheckBox2 -> State == true){
		StringGrid1 -> RowCount = n+1 ;
		StringGrid1 -> ColCount = n+1 ;

		for (int i = 0 ; i <= n ; i++){
			for (int j = 0 ; j <= n ; j++){
				if (i == 0 && j == 0) continue ;

				if (i == 0 && j >= 1){
					StringGrid1 -> Cells[j][i] = j-1 ;
				}
				else if (j == 0 && i > 0){
					StringGrid1 -> Cells[j][i] = i-1 ;
				}
				else{
					if (g[i-1][j-1] >= to_weight){
						StringGrid1 -> Cells[j][i] = "∞" ;
					}
					else
						StringGrid1 -> Cells[j][i] = g[i-1][j-1] ;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

int mind(int source ,int n ,const vector<int>& d ,const vector<int>& visit){
	int dmin = INT_MAX ;
	int k = source ;

	for (int i = 0 ; i < n ; i++){
		if (i == source) continue ;

		if (d[i] < dmin && !visit[i]){
			k = i ;
			dmin = d[i] ;
		}
	}

	return k ;
}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int n = g.size() ;
	int source = StrToInt(Edit4 -> Text) ;
	vector<int> visit(n ,0) ;
	vector<int> p(n ,source) ;
	vector<int> d(g[source].begin() ,g[source].end()) ;

	for (int i = 0 ; i < n ; i++){
		if (i == source)
			continue ;

		int k = mind(source ,n ,d ,visit) ;
		visit[k] = 1 ;

		for (int j = 0 ; j < n ; j++){
			if (j == k)
				continue ;
			if (!visit[j] && d[k]+g[k][j] < d[j]){
				d[j] = d[k] + g[k][j] ;
				p[j] = k ;
			}
		}
	}
	for (int i = 0 ; i < n ; i++){
		AnsiString path = IntToStr(source)+ " " ;
		int temp = i ;
		stack<int> sk ;

		if (i == source || d[i] >= to_weight){
			Memo2 -> Lines -> Add("The minmum of distance of " + IntToStr(source) + " to " + IntToStr(i) + " is not exit.") ;
		}
		else{
			Memo2 -> Lines -> Add("The minmum of distance of " + IntToStr(source) + " to " + IntToStr(i) + " is " + IntToStr(d[i]) + "." ) ;
			if (CheckBox3 -> State == true){
				while (temp != source){
					sk.push(temp) ;
					temp = p[temp] ;
				}
				while (!sk.empty()){
					temp = sk.top() ;
					sk.pop() ;
					path = path + "--" + IntToStr(g[p[temp]][temp]) + "-->" + IntToStr(temp) + " " ;
				}
				Memo2 -> Lines -> Add("The minmum of distance of " + IntToStr(source) + " to " + IntToStr(i) + " with path " + path ) ;
			}
		}
	}
	Memo2 -> Lines -> Add("-------------------------") ;
}
//---------------------------------------------------------------------------


void dfs(int t ,int s,const int n ,const vector<vector<int>>& res ,vector<vector<int>>& path ,vector<int> cur ,int w){
	if (t == s && w == 0){
		path.push_back(cur) ;

		return ;
	}

	for (int i = 0 ; i < n ; i++){
		if (g[t][i] > w || i == t)
			continue ;

		cur.push_back(i) ;
		dfs(i ,s ,n ,res ,path ,cur ,w - g[t][i]) ;
		cur.pop_back() ;
	}

	return ;
}
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int n = g.size() ;
	vector<vector<int>> res ;

	res.assign(g.begin() ,g.end()) ;

	for (int i = 0 ; i < n ; i++){      //經過 i 點
		for (int j = 0 ; j < n ; j++){
			if (i == j)
				continue ;

			for (int k = 0 ; k < n ; k++){
				if (j == k)
					continue ;

				res[j][k] = min(res[j][k] ,res[j][i] + res[i][k]) ;
			}
		}
	}

	StringGrid2 -> RowCount = n+1 ;
	StringGrid2 -> ColCount = n+1 ;

	for (int i = 0 ; i <= n ; i++){
		for (int j = 0 ; j <= n ; j++){
			if (i == 0 && j == 0) continue ;

			if (i == 0 && j >= 1){
				StringGrid2 -> Cells[j][i] = j-1 ;
			}
			else if (j == 0 && i > 0){
				StringGrid2 -> Cells[j][i] = i-1 ;
			}
			else{
				if (res[i-1][j-1] >= to_weight){
					StringGrid2 -> Cells[j][i] = "∞" ;
				}
				else
					StringGrid2 -> Cells[j][i] = res[i-1][j-1] ;
			}
		}
	}

	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++){
			if (i == j || res[i][j] >= to_weight)
				continue ;

			vector<vector<int>> path ;
			vector<int> cur ;

			dfs(i ,j ,n ,res ,path ,cur ,res[i][j]) ;

			AnsiString s = IntToStr(i) ;

			if (path.empty())
				continue ;

			int temp = i ;

			for (int k = 0 ; k < path[0].size() ; k++){
				if (g[temp][path[0][k]]  >= to_weight){
					 Memo2 -> Lines -> Add("The minmum of distance of " + IntToStr(i) + " to " + IntToStr(j) + " is not exit.") ;
					 break ;
				}
				else
					s = s + " --" + IntToStr(g[temp][path[0][k]]) + "--> " + IntToStr(path[0][k]) ;
				temp = path[0][k] ;
			}

			Memo2 -> Lines -> Add("The minmum of distance of " + IntToStr(i) + " to " + IntToStr(j) + " with path " + s ) ;
		}
		 Memo2 -> Lines -> Add("-------------------------") ;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button5Click(TObject *Sender)
{
	vector<vector<int>> res ;
	int n = g.size() ;
	res.assign(g.begin() ,g.end()) ;

	for (int i = 0 ; i < n ; i++){      //經過 i 點
		for (int j = 0 ; j < n ; j++){
			if (i == j)
				continue ;

			for (int k = 0 ; k < n ; k++){
				if (j == k)
					continue ;

				res[j][k] = min(res[j][k] ,res[j][i] + res[i][k]) ;
			}
		}
	}

	StringGrid3 -> RowCount = n+1 ;
	StringGrid3 -> ColCount = n+1 ;

	for (int i = 0 ; i <= n ; i++){
		for (int j = 0 ; j <= n ; j++){
			if (i == 0 && j == 0) continue ;

			if (i == 0 && j >= 1){
				StringGrid3 -> Cells[j][i] = j-1 ;
			}
			else if (j == 0 && i > 0){
				StringGrid3 -> Cells[j][i] = i-1 ;
			}
			else{
				if (res[i-1][j-1] >= to_weight){
					StringGrid3 -> Cells[j][i] = 0 ;
				}
				else
					StringGrid3 -> Cells[j][i] = 1 ;
			}
		}
	}
}
//---------------------------------------------------------------------------

