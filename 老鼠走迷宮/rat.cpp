//--------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "rat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Lines->Clear() ;
	Memo2->Lines->Clear() ;
}
//---------------------------------------------------------------------------
int maze[30][30] ,m ,n ,Case = 1;
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  for (int i = 0 ; i < 30 ; i++ ) {
	for (int j = 0 ; j < 30 ; j++ ) {
		maze[i][j] = 1 ;
	}
  }
  FILE *fp;

  AnsiString out, fname;

  int i, j;

  if (OpenDialog1->Execute())
  {
	fname = OpenDialog1->FileName;
	fp = fopen(fname.c_str(), "r+");
	fscanf(fp, "%d %d", &m, &n);
	Memo1->Lines->Add("�g�c "+IntToStr(Case));
	Memo1->Lines->Add("m = "+IntToStr(m));
	Memo1->Lines->Add("n  = "+IntToStr(n));

	  for (i=1; i<=m; i++)

		 for (j=1; j<=n; j++)

             fscanf(fp, "%d", &maze[i][j]);

	 for (i=1; i<=m; i++)

	 {   out = "";

		 for (j=1; j<=n; j++)

			 out += "  "+IntToStr(maze[i][j]);

		 Memo1->Lines->Add(out);

	 }
	 StringGrid1->RowCount = m+1;

	 StringGrid1->ColCount = n+1;

	 for (i=1; i<=m; i++)

	 {   for (j=1; j<=n; j++)

		 {   StringGrid1->Cells[j-1][i-1] = maze[i][j];

		 }

	 }
	 fclose(fp);

  }

  else  Memo1->Lines->Add("Nothing happens.");
  Memo1->Lines->Add("------------------------");
}
//---------------------------------------------------------------------------
typedef struct{
	int x ,y ;
	int dir ;
	int dir_x[4] = {1 ,0 ,-1 ,0},dir_y[4] = {0 ,1 ,0 ,-1} ;
}mouse ;
typedef struct{
	mouse w[100] = {} ;
	int top = 0 ;

	void push(mouse m){
		w[top++] =  m;
	}
	int getx(void){
		return  w[top-1].x ;
	}
	int gety(void){
		return  w[top-1].y ;
	}
	int getdir(void){
		return w[top-1].dir ;
	}
	void pop(){
		top-- ;
	}
	bool empty(){
		if (top == 0) {
			return 1 ;
		}
		return 0 ;
	}

}Stack ;
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Stack stack ;
	mouse p ;
	p.x = 1 ;
	p.y = 1 ;
	p.dir = 0 ;
	stack.push(p) ;
	int decord[30][30] = {} ;
	decord[1][1] = 2 ;
	maze[p.y][p.x] = 4 ;
	bool check = true ;
	while (p.y != m ||  p.x != n  ){
		int flag = 0 ;
		for (int i = 0 ; i < 4 ; i++){
			if (maze[p.y+p.dir_y[i]][p.x+p.dir_x[i]] != 1
				&& decord[p.y+p.dir_y[i]][p.x+p.dir_x[i]] != 2) {
				p.dir = i ;
				stack.push(p) ;
				decord[p.y][p.x] = 2 ;
				maze[p.y][p.x] = 2 ;
                p.x = p.x+p.dir_x[i] ;
				p.y = p.y+p.dir_y[i] ;
				break ;
			}
			else{
				flag ++ ;
			}
		}
		if (flag == 4) {
			maze[p.y][p.x] = 2 ;
			decord[p.y][p.x] = 2 ;
			stack.pop() ;
			p.x = stack.getx() ;
			p.y = stack.gety() ;
			p.dir = stack.getdir() ;
			int k = 1 ;
			while (maze[p.y+p.dir_y[(p.dir+k)%4]][p.x+p.dir_x[(p.dir+k)%4]] == 1
				|| decord[p.y+p.dir_y[(p.dir+k)%4]][p.x+p.dir_x[(p.dir+k)%4]] == 2){
				k++ ;
				if (k == 3) {
					stack.pop() ;
                    p.x = stack.getx() ;
					p.y = stack.gety() ;
					p.dir = stack.getdir() ;
					k = 1 ;
				}
				if (stack.empty()) {
					check = false ;
				}
			}
			p.x = stack.getx() ;
			p.y = stack.gety() ;
			p.dir = stack.getdir() ;
		}
		if (check == false) {
			break ;
		}
	}
	maze[m][n] = 4 ;
	maze[1][1] = 4 ;
	AnsiString out ;
	Memo2->Lines->Add("�g�c "+IntToStr(Case++));
	for (int i=1; i<=m ; i++)
	{
		{
			out = "";
			for (int j=1; j<=n; j++)
				out += "  "+IntToStr(maze[i][j]);
			Memo2->Lines->Add(out);
		}
	}
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;
	 for (int i=1; i<=m; i++)

	 {   for (int j=1; j<=n; j++)

		 {   StringGrid1->Cells[j-1][i-1] = maze[i][j];

		 }

	 }
	if (check == false) {
		Memo2->Lines->Add("------------�ѹ��䤣��X�f------------");
	}
	else
		Memo2->Lines->Add("------------�ѹ����\��X�f------------");
}
//---------------------------------------------------------------------------





void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	StringGrid1->Canvas->Brush->Color = clWhite;

	 StringGrid1->Canvas->Font->Color = clBlue;

	 StringGrid1->Canvas->FillRect(Rect);

	 AnsiString text = StringGrid1->Cells[ACol][ARow];

	 StringGrid1->Canvas->TextRect(Rect, Rect.Left+8, Rect.Top+8, text);
}
//---------------------------------------------------------------------------

