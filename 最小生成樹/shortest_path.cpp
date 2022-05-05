//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <stack>
#include <queue>
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
struct point{
  int x ,y ,w ;

  point(){}

  point(int x ,int y ,int w):x(x) ,y(y) ,w(w){}
};

vector<vector<int>> g ;
vector<vector<pair<int ,int>>> g2 ;
int to_weight = 1e6 ;
int n ;
bool printCpu = true ;

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	n = StrToInt(Edit1 -> Text) ;
	int weight = StrToInt(Edit2 -> Text) ;
	int max_weight = StrToInt(Edit3 -> Text) ;

	g = vector<vector<int>>(n ,vector<int>(n ,0)) ;
	g2 = vector<vector<pair<int ,int>>>(n) ;

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
				g2[i].push_back({j ,temp}) ;
				g2[j].push_back({i ,temp}) ;
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
					StringGrid1 -> Cells[j][i] = "¡Û" ;
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
						StringGrid1 -> Cells[j][i] = "¡Û" ;
					}
					else
						StringGrid1 -> Cells[j][i] = g[i-1][j-1] ;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

struct cmp{
	bool operator() (const point& a ,const point& b){
		return a.w > b.w ;
	}
};
void prim(vector<point>& res){
	priority_queue<point ,vector<point> ,cmp> q ; // (w ,v)
	vector<int> visit(n ,0) ;
	visit[0] = 1 ;

	for (auto p : g2[0]){
		q.emplace(point(0 ,p.first ,p.second)) ; // (-w ,v)
	}
	for (int i = 1 ; i < n && !q.empty() ; i++){
		while (!q.empty()){
			int x = q.top().x ;
			int y = q.top().y ;
			int w = q.top().w ;
			q.pop() ;

			if (visit[y]++) continue ;

			//visit[y] = 1 ;
			for (const auto p : g2[y]){
				if (visit[p.first]) continue ;

				q.emplace(point(y ,p.first ,p.second)) ;
			}
			//Form1 -> Memo2 -> Lines -> Add(IntToStr(i) + " " +IntToStr(v) + " " +IntToStr(w) + " " ) ;
			res.push_back(point(x ,y ,w)) ;
			break ;
		}
	}
}


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	vector<point> res ;
	double tS ,tE ,tdiff;


	tS = clock() ;  // Start

	prim(res) ;

	tE = clock() ;   // End
	tdiff = (tE-tS)/CLOCKS_PER_SEC ; // Start - End
	AnsiString s = tdiff ;

	Memo2 -> Lines -> Add("----Prim algorithm---") ;

	if (res.size() == n-1){
		for (int i = 0 ; i < res.size() ; i++){
			Memo2 -> Lines -> Add("Edge " + IntToStr(i) + ":("
								+IntToStr(res[i].x) + "," + IntToStr(res[i].y) + ")"
								+ "[" + IntToStr(res[i].w) + "]") ;
		}
		if (printCpu)
			Memo2 -> Lines -> Add("CPU Runtime : " + s)  ;
	}
	else{
		Memo2 -> Lines -> Add("No Minmum Spanning Tree") ;
	}
}
//---------------------------------------------------------------------------

int find(int x ,vector<int>& parent){
	return x == parent[x] ? x : parent[x] = find(parent[parent[x]] ,parent) ;
}

bool mycmp(const point& a ,const point& b){
	return  a.w < b.w ;
}

void Kruskal(vector<point>& res){
	vector<point> edge ;

	for (int i = 0 ; i < n ; i++){
		for (int j = i+1 ; j < n ; j++){
			if (g[i][j] < to_weight)
				edge.push_back(point(i ,j ,g[i][j])) ;
		}
	}
	sort(edge.begin() ,edge.end() , mycmp) ;

	vector<int> parent(n ,0) ;
	for (int i = 0 ; i < n ; i++){
		parent[i] = i ;
	}

	for (const auto p : edge){
		int x = p.x ;
		int y = p.y ;
		int w = p.w ;

		int fx = find(x ,parent) ;
		int fy = find(y ,parent) ;
		if (fx == fy) continue ;

		parent[fx] = fy ;
		res.push_back(point(x ,y ,w)) ;
	}
}


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	vector<point> res ;
	double tS ,tE ,tdiff;


	tS = clock() ;  // Start

	Kruskal(res) ;

	tE = clock() ;     // End
	tdiff = (tE-tS)/CLOCKS_PER_SEC ; // Start - End
	AnsiString s = tdiff ;

	Memo2 -> Lines -> Add("----Kruskal algorithm---") ;

	if (res.size() == n-1){
		for (int i = 0 ; i < res.size() ; i++){
			Memo2 -> Lines -> Add("Edge " + IntToStr(i) + ":("
								+IntToStr(res[i].x) + "," + IntToStr(res[i].y) + ")"
								+ "[" + IntToStr(res[i].w) + "]") ;
		}
		if (printCpu)
			Memo2 -> Lines -> Add("CPU Runtime : " + s)  ;
	}
	else{
		Memo2 -> Lines -> Add("No Minmum Spanning Tree") ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if (CheckBox2 -> Checked == false)
		printCpu = false ;
	else
		printCpu = true ;
}
//---------------------------------------------------------------------------


