//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n ;
int w[20][20] ;
int c ,c2 ;
int r[25] = {} ;
int col[25] = {} ;
int dia = 0 ,dia2 = 0 ;
int flag = 0 ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear() ;
	Memo3->Clear() ;
	Memo4->Clear() ;
	Memo2->Clear() ;
	Memo5->Clear() ;
}
//---------------------------------------------------------------------------
void re(){
	for ( int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			w[i][j] = 0 ;
		}
	}
}
void generate_rT(){
	int i = 0 ;
	int j = n/2+1 ;
	for ( int key = 1 ; key <= n*n ; key++ ){
		if ( key%n == 1 ){
			i++ ;
		}
		else{
			i-- ;
			j++ ;
		}
		if ( i == 0 ){
			i = n ;
		}
		if ( j == n+1 ){
			j = 1 ;
		}
		w[i][j] = key ;
	}
}
void generate_lT(){
	int i = 0 ;
	int j = n/2+1 ;
	for ( int key = 1 ; key <= n*n ; key++ ){
		if ( key%n == 1 ){
			i++ ;
		}
		else{
			i-- ;
			j-- ;
		}
		if ( i == 0 ){
			i = n ;
		}
		if ( j == 0 ){
			j = n ;
		}
		w[i][j] = key ;
	}
}
void generate_lB(){
	int i = 2 ;
	int j = n/2+1 ;
	for ( int key = 1 ; key <= n*n ; key++ ){
		if ( key%n == 1 ){
			i-- ;
		}
		else{
			i++ ;
			j-- ;
		}
		if ( i == 0 ) {
			i = n ;
		}
		if ( i == n+1 ){
			i = 1 ;
		}
		if ( j == 0 ){
			j = n ;
		}
		w[i][j] = key ;
	}
}
void generate_rB(){
	int i = 2 ;
	int j = n/2+1 ;
	for ( int key = 1 ; key <= n*n ; key++ ){
		if ( key%n == 1 ){
			i-- ;
		}
		else{
			i++ ;
			j++ ;
		}
		if ( i == 0 ) {
			i = n ;
		}
		if ( i == n+1 ){
			i = 1 ;
		}
		if ( j == n+1 ){
			j = 1 ;
		}
		w[i][j] = key ;
	}
}
void Check (){
	for ( int i = 0 ; i < 25; i++) {
		col[i] = 0;
		r[i] = 0 ;
	}
	dia = dia2 = 0 ;
	for ( int i = 1 ; i <= n; i++) {
		int temp = 0 ,temp2 = 0;
		for (int j = 1; j <= n; j++) {
			temp += w[i][j] ;
			temp2 += w[j][i] ;
			if ( i == j ) {
				dia += w[i][j] ;
			}
			if ( (i + j) == n+1 ) {
				dia2 += w[i][j] ;
			}
		}
		r[i] = temp ;
		col[i] = temp2 ;
	}
	int temp3 = r[1] ;
	while (temp3){
		c2++ ;
		temp3 /= 10 ;
	}
}
void show(){
	AnsiString s ,s2 = "" ,s3 = "" ,space = "" ,space2 = "";
	int k = 0 ;
	Form1 -> Memo1 -> Lines -> Add("--------------?????@??"+IntToStr(n)+"*"+IntToStr(n)+"???]?N?x?}-------------\r\n") ;
	Form1 -> Memo3 -> Lines -> Add("--------------?????@??"+IntToStr(n)+"*"+IntToStr(n)+"???]?N?x?}-------------\r\n") ;
	Form1 -> Memo4 -> Lines -> Add("--------------?????@??"+IntToStr(n)+"*"+IntToStr(n)+"???]?N?x?}-------------\r\n") ;
	for ( int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			k = 0;
			space = "" ;
			space2 = "" ;
			int temp = w[i][j] ;
			while (temp){
			   k++ ;
			   temp /= 10 ;
			}
			for (int i = 0; i < c2-1; i++) {
				space2 += " " ;
			}
			for (int i = k; i < c; i++) {
				space += " " ;
			}
			s2 += space + IntToStr(w[i][j])+ " " ;
			s3 += space + space2  + IntToStr(w[i][j])+ " " ;
			s += IntToStr(w[i][j])+" " ;
		}
		s3 += " -"+IntToStr(r[i]) ;
		s3 += "\r\n" ;
		s2 += "\r\n" ;
		s += "\r\n" ;
	}
	for (int i = 1 ; i <= n; i++) {
		s3 += "|" + IntToStr(col[i]) + " " ;
		if ( n > 10 )
			s3 += " " ;
	}
	s3 += "\\"+IntToStr(dia) + "/"+IntToStr(dia2)+"\r\n";
	Form1 -> Memo1 -> Lines -> Add(s) ;
	Form1 -> Memo3 -> Lines -> Add(s2) ;
	Form1 -> Memo4 -> Lines -> Add(s3) ;
	Form1 -> StringGrid1 ->RowCount = n;
	Form1 -> StringGrid1 ->ColCount = n;
	for (int i = 0 , k = 1; i < n; i++ , k++) {
		for (int j  = 0 ,h = 1 ; j < n; j++ , h++) {
			Form1 -> StringGrid1 -> Cells[j][i] = IntToStr(w[k][h]) ;
		}
	}
}
void show2(){
	AnsiString s ,space = "" ;
	int k = 0 ;
	Form1 -> Memo2 -> Lines -> Add("--------------?????@??"+IntToStr(n)+"*"+IntToStr(n)+"???]?N?x?}-------------\r\n") ;
	for ( int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			k = 0;
			space = "" ;
			int temp = w[i][j] ;
			while (temp){
			   k++ ;
			   temp /= 10 ;
			}
			for (int i = k; i < c; i++) {
				space += " " ;
			}
			s += space + IntToStr(w[i][j]) + " " ;
		}
		s += "\r\n" ;
	}
	Form1 -> Memo2 -> Lines -> Add(s) ;
}
void show3(){
	AnsiString s ,space = "" ;
	int k = 0 ;
	Form1 -> Memo5 -> Lines -> Add("--------------?????@??"+IntToStr(n)+"*"+IntToStr(n)+"???]?N?x?}-------------\r\n") ;
	for ( int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			k = 0;
			space = "" ;
			int temp = w[i][j] ;
			while (temp){
			   k++ ;
			   temp /= 10 ;
			}
			for (int i = k; i < c; i++) {
				space += " " ;
			}
			s += space + IntToStr(w[i][j]) + " " ;
		}
		s += "\r\n" ;
	}
	Form1 -> Memo5 -> Lines -> Add(s) ;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	c = 0 ;
	c2 = 0 ;
	n = StrToInt(Edit1->Text) ;
	int temp = n*n ;
	if ( n%2 ) {
		while (temp){
			temp /= 10 ;
			c++ ;
		}
		re() ;
		generate_lT() ;
		show2() ;
		re() ;
		generate_rB() ;
		show3() ;
	}
    if ( n%2 == 0 ) {
		Memo2 -> Lines -> Add("--------------?????J?_??!--------------\r\n") ;
		Memo5 -> Lines -> Add("--------------?????J?_??!--------------\r\n") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	flag = 1 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	flag = 2 ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	flag = 4 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
    flag = 3 ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
     c = 0 ;
	c2 = 0 ;
	n = StrToInt(Edit1->Text) ;
	int temp = n*n ;

	while (temp){
		temp /= 10 ;
		c++ ;
	}
	if ( n%2 == 0 ) {
		Memo1 -> Lines -> Add("--------------?????J?_??!--------------\r\n") ;
		Memo3 -> Lines -> Add("--------------?????J?_??!--------------\r\n") ;
		Memo4 -> Lines -> Add("--------------?????J?_??!--------------\r\n") ;
	}
	else{
		re() ;
		switch(flag){
			case 1 : generate_lT() ;
					 Check() ;
					 show() ;
					 break;
			case 2 : generate_rT() ;
					 Check() ;
					 show() ;
					 break;
			case 3 : generate_lB() ;
					 Check() ;
					 show() ;
					 break;
			case 4 : generate_rB() ;
					 Check() ;
					 show() ;
					 break ;
			default :
				Memo1 -> Lines -> Add("--------------?????????V!--------------\r\n") ;
				Memo3 -> Lines -> Add("--------------?????????V!--------------\r\n") ;
				Memo4 -> Lines -> Add("--------------?????????V!--------------\r\n") ;
				break ;
		}
	}
}
//---------------------------------------------------------------------------

