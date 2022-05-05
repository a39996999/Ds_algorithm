//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "project2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
#define SWAP(x, y, z) (z = x , x = y , y = z)
int k ,n ,d ,h ,count ;
char w[9] = {'A','B','C','D','E','F','G','H','I'} ;
void permutation(char *w2 ,int a ,int b){
	int temp ;
	AnsiString s = "" ;
	if (a == b){
		for (int i = 0; i < n; i++) {
			s += AnsiString(w2[i]) ;
		}
	if( Form1 -> CheckBox1->Checked ){
		Form1 -> Memo2 -> Lines -> Add("                                ==>(k,n)=("+IntToStr(a)+","+IntToStr(n)+")! k=n-1 print!!!") ;
		Form1 -> Memo2 -> Lines -> Add(s+" ["+d+"]");
	}
		Form1-> Memo1 -> Lines -> Add(s+" ["+d+"]") ;
		Form1-> Memo1 -> Lines -> Add('\n') ;
		d++ ;
	}
	else{
		for ( int j = a ; j < n ; j++ ){
			SWAP(w2[a] ,w[j] ,temp) ;
			if( Form1 -> CheckBox1->Checked ){
                s = "" ;
				for (int i = 0; i < n; i++) {
					s += AnsiString(w[i]) ;
				}
				Form1 -> Memo2 -> Lines -> Add("                        >i="+IntToStr(j)+" (k,n)=("+IntToStr(a)+","+IntToStr(n)+"), swap[k,x]=["+IntToStr(a)+","+IntToStr(j)+"], list[]="+s);
			}
			permutation(w2 ,a+1 ,b) ;
			SWAP(w2[a] ,w[j] ,temp) ;
			if( Form1 -> CheckBox1->Checked ){
				s = "" ;
				for (int i = 0; i < n; i++) {
					s += AnsiString(w[i]) ;
				}
				Form1 -> Memo2 -> Lines -> Add("                        <i="+IntToStr(j)+" (k,n)=("+IntToStr(a)+","+IntToStr(n)+"), swap[k,x]=["+IntToStr(a)+","+IntToStr(j)+"], list[]="+s);
			}
		}
	}
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	d = 0 ;
	int temp ;
	AnsiString s = "" ;
	k = Edit1 -> Text.ToInt() ;
	n = Edit2 -> Text.ToInt() ;
	if(	CheckBox1->Checked	){
		Memo2 -> Lines -> Add("            Go==>(k,n)=("+IntToStr(k)+","+IntToStr(n)+")");
	}
	for ( int i = k ; i < n ; i++){
		SWAP(w[k] ,w[i] ,temp) ;
		if( CheckBox1->Checked ){
			s = "";
			for (int i = 0; i < n; i++) {
			s += AnsiString(w[i]) ;
			}
			Memo2 -> Lines -> Add("                    >i="+IntToStr(i)+" (k,n)=("+IntToStr(k)+","+IntToStr(n)+"), swap[k,x]=["+IntToStr(k)+","+IntToStr(i)+"], list[]="+s);
		}
		permutation(w ,k+1 ,n-1) ;
		SWAP(w[k] ,w[i] ,temp) ;
		if( CheckBox1->Checked ){
			s = "" ;
			for (int i = 0; i < n; i++) {
			s += AnsiString(w[i]) ;
			}
			Memo2 -> Lines -> Add("                    <i="+IntToStr(i)+" (k,n)=("+IntToStr(k)+","+IntToStr(n)+"), swap[k,x]=["+IntToStr(k)+","+IntToStr(i)+"], list[]="+s);
		}
	}
	Memo1 -> Lines -> Add("-------------------------總共有"+IntToStr(d)+"種排列方法!!!----------------------------------------------") ;
	Memo2 -> Lines -> Add("-----------------------------------------------------------------------------------------------") ;
	Memo1 -> Lines -> Add('\n') ;
    Memo2 -> Lines -> Add('\n') ;
}
//---------------------------------------------------------------------------

void hanoi(int n ,char a ,char b ,char c){
	AnsiString s = a ;
	AnsiString s1 = c ;
	if ( n == 1 ){
		Form1 -> Memo3 -> Lines -> Add( "Moving the top disk from tower " +s+" to tower "+s1 ) ;
		count++ ;
	}
	else{
		if(Form1 -> CheckBox2 -> Checked ){
            Form1 -> Memo3 -> Lines -> Add( "TMoving the top disk from tower " +s+" to tower "+s1 ) ;
		}
		hanoi(n-1 ,a ,c ,b) ;
		Form1 -> Memo3 -> Lines -> Add( "Moving the top disk from tower " +s+" to tower "+s1 ) ;
		count++ ;
		hanoi(n-1 ,b ,a ,c) ;
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	count = 0 ;
	h = Edit3->Text.ToInt() ;
	hanoi(h ,'A' ,'B' ,'C') ;
	Memo3 -> Lines -> Add("-----------------總共搬移了"+IntToStr(count)+"次----------------");
}
//---------------------------------------------------------------------------

