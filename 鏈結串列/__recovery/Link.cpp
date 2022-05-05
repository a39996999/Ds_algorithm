//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Link.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1-> Lines-> Clear() ;
	Memo2-> Lines-> Clear() ;
	Memo3-> Lines-> Clear() ;
}
//---------------------------------------------------------------------------
struct Node {
	int data ;
	Node *next ;
};
Node *head = NULL ;
Node *current ;
Node* createNode(int n){
	Node *temp = new Node() ;
	temp -> data = n ;
	temp -> next = NULL ;
	return temp ;
}
void printData(){
	AnsiString s = "" ;
	Node *p = head ;
	if (head == NULL) {
		Form1 -> Memo1 -> Lines -> Add("is Empty!") ;
	}
	else{
		while (p->next != NULL){
		   //	Form1 -> Memo1 -> Lines -> Add(IntToStr(head->data) +"->") ;
			s += IntToStr(p->data)+"->" ;
			p = p->next ;
		}

		//Form1 -> Memo1 -> Lines -> Add(IntToStr(head->data) +"-><-") ;
		s += IntToStr(p->data) +"-><-" ;
		Form1 -> Memo1 -> Lines -> Add(s) ;
	}
}
void printData_stack(){
	AnsiString s = "" ;
	Node *p = head ;
	if (head == NULL) {
		Form1 -> Memo1 -> Lines -> Add("is Empty!") ;
	}
	else{
		while (p->next != NULL){
		   //	Form1 -> Memo1 -> Lines -> Add(IntToStr(head->data) +"->") ;
			s += IntToStr(p->data)+"->" ;
			p = p->next ;
		}

		//Form1 -> Memo1 -> Lines -> Add(IntToStr(head->data) +"-><-") ;
		s += IntToStr(p->data) +"-><-" ;
		Form1 -> Memo3 -> Lines -> Add(s) ;
	}
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text) ;
   //	Node *node = createNode(n) ;
	Node *p = head ;
	if (head == NULL) {
		head = createNode(n) ;
	}
	else{
		while (p->next != NULL){
			p = p->next ;
		}
		p->next = createNode(n) ;
	}
	printData() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text) ;
	Node *p = new Node() ;
	Node *temp ;
	if (head == NULL) {
		head = createNode(n) ;
	}
	else{
		temp = head ;
		p->data = n ;
		p->next = head ;
		head = p ;
		p = temp ;
	}
	printData() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int n = StrToInt(Edit2->Text) ;
	bool check = false ;
	Node *p = head ;
	while (p->next != NULL){
		if (p->data == n) {
			check = true ;
			break ;
		}
		p = p->next ;
	}
	if (p->data == n) {
		check = true ;
	}
	if (check) {
		Memo1 -> Lines -> Add(IntToStr(n) + " is found!") ;
	}
	else{
		Memo1 -> Lines -> Add(IntToStr(n) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text) ;
	int n2 = StrToInt(Edit2->Text) ;
	bool check = false ;
	Node *p = head ;
	if (p->data == n2) {
		Node *temp = new Node() ;
		Node *temp2 ;
		temp2 = head ;
		temp->data = n ;
		temp->next = head ;
		head = temp ;
		temp = temp2 ;
		check = true ;
	}
	while (p->next != NULL && check != true){
		Node *temp2 = p->next ;
		if (temp2->data == n2) {
			Node *temp = new Node() ;
			temp->data = n ;
			p->next = temp ;
			temp->next = temp2 ;
			check = true ;
		}
		p = p->next ;
	}
	if (check) {
		printData() ;
		Memo1 -> Lines -> Add(IntToStr(n) + " Add successfully!") ;
	}
	else{
		Memo1 -> Lines -> Add(IntToStr(n2) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text) ;
	int n2 = StrToInt(Edit2->Text) ;
	bool check = false ;
	Node *p = head ;
	while (p->next != NULL){
		if (p->data == n2) {
		   Node *temp = new Node() ;
		   temp->data = n ;
		   temp->next = p->next ;
		   p->next = temp ;
		   check = true ;
		   break ;
		}
		p = p->next ;
	}
	if (p->data == n2 && check != true) {
		Node *temp = new Node() ;
		temp->data = n ;
		temp = p->next ;
		p->next = temp ;
		check = true ;
	}
	if (check) {
		printData() ;
		Memo1 -> Lines -> Add(IntToStr(n) + " Add successfully!") ;
	}
	else{
		Memo1 -> Lines -> Add(IntToStr(n2) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int n = StrToInt(Edit2->Text) ;
	bool check = false ;
	Node *p = head ;
	Node *temp ;
	if (p->data == n && p->next != NULL) {
		head = p->next ;
		delete p ;
		check = true ;
	}
	if (p->data == n && p->next == NULL) {
		delete p ;
		head = NULL ;
		check = true ;
	}
	while (p->next != NULL && check != true){
		temp = p->next ;
		if (temp->data == n) {
			p->next = temp->next ;
			delete temp ;
			check = true ;
		}
		p = p->next ;
	}
	if (p->data == n && check != true) {
		Node *temp2 = p ;
		delete temp2 ;
		check = true ;
	}
	if (check) {
		printData() ;
		Memo1 -> Lines -> Add(IntToStr(n) + " Delete successfully!") ;
	}
	else{
		Memo1 -> Lines -> Add(IntToStr(n) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	while (head != NULL){
		Node *temp = head ;
		head = head->next ;
		delete temp ;
	}
	Memo1 -> Lines -> Add("clear!") ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int n = StrToInt(Edit3->Text) ;
	Node *p = new Node() ;
	Node *temp ;
	if (head == NULL) {
		head = createNode(n) ;
	}
	else{
		temp = head ;
		p->data = n ;
		p->next = head ;
		head = p ;
		p = temp ;
	}
	Memo3 -> Lines -> Add(IntToStr(n)+" push successfully！") ;
	printData_stack() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{

	if (head == NULL) {
		Memo3 -> Lines -> Add("is Empty！") ;
	}
	else{
		Node *p = head ;
		int data = p->data ;
		head = head->next ;
		delete p ;
		Memo3 -> Lines -> Add(IntToStr(data)+" pop successfully！") ;
		printData_stack() ;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	while (head != NULL){
		Node *temp = head ;
		head = head->next ;
		delete temp ;
	}
	Memo3 -> Lines -> Add("clear!") ;
}
//---------------------------------------------------------------------------
struct node{
	int data ;
	node *before ,*next ;
};
node *head2 = NULL ;

node* createnode(int n){
	node *temp = new node() ;
	temp -> data = n ;
	temp -> next = NULL ;
	temp -> before = NULL ;

	return temp ;
}

void printData_d(){
	AnsiString s = "" ;
	node *p = head2 ;
	if (head2 == NULL) {
		Form1 -> Memo2 -> Lines -> Add("is Empty!") ;
	}
	else{
		while (p->next != NULL){
			s += IntToStr(p->data)+"<->" ;
			p = p->next ;
		}
		s += IntToStr(p->data) +"-><-" ;
		Form1 -> Memo2 -> Lines -> Add(s) ;
	}
}

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	int n = StrToInt(Edit4->Text) ;
	node *p = new node() ;
	node *temp ;
	if (head2 == NULL) {
		head2 = createnode(n) ;
	}
	else{
		head2->before = p ;
		temp = head2 ;
		p->data = n ;
		p->next = head2 ;
		head2 = p ;
		p = temp ;
	}
	printData_d() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
	int n = StrToInt(Edit4->Text) ;
	node *p = head2 ;
	if (head2 == NULL) {
		head2 = createnode(n) ;
	}
	else{
		while (p->next != NULL){
			p = p->next ;
		}
		p->next = createnode(n) ;
		node *temp = p->next ;
		temp->before = p ;
	}
	printData_d() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
	int n = StrToInt(Edit5->Text) ;
	bool check = false ;
	node *p = head2 ;
	while (p->next != NULL){
		if (p->data == n) {
			check = true ;
			break ;
		}
		p = p->next ;
	}
	if (p->data == n) {
		check = true ;
	}
	if (check) {
		Memo2 -> Lines -> Add(IntToStr(n) + " is found!") ;
	}
	else{
		Memo2 -> Lines -> Add(IntToStr(n) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
	int n = StrToInt(Edit4->Text) ;
	int n2 = StrToInt(Edit5->Text) ;
	bool check = false ;
	node *p = head2 ;
	if (p->data == n2) {
		node *temp = new node() ;
		node *temp2 ;
		head2->before = temp ;
		temp2 = head2 ;
		temp->data = n ;
		temp->next = head2 ;
		temp->before = NULL ;
		head2 = temp ;
		temp = temp2 ;
		check = true ;
	}
	while (p->next != NULL && check != true){
		node *temp2 = p->next ;
		if (temp2->data == n2) {
			node *temp = new node() ;
			temp2->before = temp ;
			temp->data = n ;
			temp->before = p ;
			p->next = temp ;
			temp->next = temp2 ;
			check = true ;
		}
		p = p->next ;
	}
	if (check) {
		printData_d() ;
		Memo2 -> Lines -> Add(IntToStr(n) + " Add successfully!") ;
	}
	else{
		Memo2 -> Lines -> Add(IntToStr(n) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender)
{
	int n = StrToInt(Edit4->Text) ;
	int n2 = StrToInt(Edit5->Text) ;
	bool check = false ;
	node *p = head2 ;
	while (p->next != NULL){
		if (p->data == n2) {
		   node *temp = new node() ;
		   node *temp2 = p->next ;
		   temp->data = n ;
		   temp->before = p ;
		   temp->next = p->next ;
		   temp2->before = temp ;
		   p->next = temp ;
		   check = true ;
		   break ;
		}
		p = p->next ;
	}
	if (p->data == n2 && check != true) {
		node *temp = new node() ;
		temp->data = n ;
		temp->before = p ;
		temp->next = p->next ;
		p->next = temp ;
		check = true ;
	}
	if (check) {
		printData_d() ;
		Memo2 -> Lines -> Add(IntToStr(n) + " Add successfully!") ;
	}
	else{
		Memo2 -> Lines -> Add(IntToStr(n2) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
	int n = StrToInt(Edit5->Text) ;
	bool check = false ;
	node *p = head2 ;
	if (p->data == n && p->next != NULL) {
		node *temp = p->next ;
		temp->before = NULL ;
		head2 = p->next ;
		delete p ;
		check = true ;
	}
	if (p->data == n && p->next == NULL) {
		delete p ;
		head2 = NULL ;
		check = true ;
	}
	while (p->next != NULL && check != true){
		node *temp ,*temp2 ,*temp3 ;
		if (p->data == n) {
			temp3 = p ;
            temp2 = p->before ;
			temp = p->next ;
			temp->before = p->before ;
			temp2->next = p->next ;
			delete temp3 ;
			check = true ;
		}
		p = p->next ;
	}
	if (p->data == n && check != true) {
		node *temp = p->before ;
		node *temp2 = p ;
		temp->next = NULL ;
		delete temp2 ;
		check = true ;
	}
	if (check) {
		printData_d() ;
		Memo2 -> Lines -> Add(IntToStr(n) + " Delete successfully!") ;
	}
	else{
		Memo2 -> Lines -> Add(IntToStr(n) + " is not found!") ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
	while (head2 != NULL){
		node *temp = head2 ;
		head2 = head2->next ;
		delete temp ;
	}
	Memo2 -> Lines -> Add("clear!") ;
}
//---------------------------------------------------------------------------
