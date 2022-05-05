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
	Memo1->Clear() ;
	Memo2->Clear() ;
	Memo3->Clear() ;
	Memo4->Clear() ;
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
		//Form1-> Memo1 -> Lines -> Add('\n') ;
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
	Memo1 -> Lines -> Add("-------------------------�`�@��"+IntToStr(d)+"�رƦC��k!!!----------------------------------------------") ;
	if( CheckBox1->Checked ){
		Memo2 -> Lines -> Add("-----------------------------------------------------------------------------------------------") ;
		Memo2 -> Lines -> Add('\n') ;
	}
	Memo1 -> Lines -> Add('\n') ;
}
//---------------------------------------------------------------------------

void hanoi(int n ,char a ,char b ,char c){
	AnsiString s = a ;
	AnsiString s1 = c ;
	AnsiString s2 = "" ;
	if ( n == 1 ){
		Form1 -> Memo3 -> Lines -> Add( "Moving the top disk from tower " +s+" to tower "+s1 ) ;
		if(Form1 -> CheckBox2 -> Checked ){
			for ( int i = h  ; i >= n ; i-- ) {
				s2 += "     " ;
			}
			Form1 -> Memo4 -> Lines -> Add( s2+"<1>  Try to move the top disk from tower " +s+" to tower "+s1 ) ;
			Form1 -> Memo4 -> Lines -> Add( "( Step "+ IntToStr(count)+"): ""Move the top number 1 disk from tower " +s+" to tower "+s1 ) ;
		}
		count++ ;
	}
	else{
		for ( int i = h  ; i >= n ; i-- ) {
			s2 += "     " ;
		}
		if(Form1 -> CheckBox2 -> Checked ){
			Form1 -> Memo4 -> Lines -> Add( s2+ "<"+IntToStr(n)+">  ""Try to move Number "+IntToStr(n)+ " disk from "+s+" tower to tower "+s1 ) ;
		}
		hanoi(n-1 ,a ,c ,b) ;
		if(Form1 -> CheckBox2 -> Checked ){
			s2 = "" ;
			for ( int i = h  ; i >= 1 ; i-- ) {
				s2 += "     " ;
			}
			Form1 -> Memo4 -> Lines -> Add( s2+"<1>  Try to move the top disk from tower " +s+" to tower "+s1 ) ;
			Form1 -> Memo4 -> Lines -> Add( "( Step "+ IntToStr(count)+"): ""Move the top number 1 disk from tower " +s+" to tower "+s1 ) ;
		}
		Form1 -> Memo3 -> Lines -> Add( "Moving the top disk from tower " +s+" to tower "+s1 ) ;
		count++ ;
		hanoi(n-1 ,b ,a ,c) ;
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	count = 1 ;
	h = Edit3->Text.ToInt() ;
	hanoi(h ,'A' ,'B' ,'C') ;
	Memo3 -> Lines -> Add("-----------------�`�@�h���F"+IntToStr(count)+"��----------------");
	if(Form1 -> CheckBox2 -> Checked ){
		Memo4 -> Lines -> Add("-----------------------------------------------------------------------------------------------") ;
	}
}
//---------------------------------------------------------------------------



