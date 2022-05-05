//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BST.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1 -> Clear() ;
}
//---------------------------------------------------------------------------

struct TreeNode{
public:
	int data ;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	TreeNode(int n): data(n){} ;

	~TreeNode(){
		delete left ;
		delete right ;
		left = nullptr ;
		right = nullptr ;
	}
};
TreeNode* root = nullptr ;

struct stack{
	TreeNode* w[1000] ;
	int j = 0 ;

	void push(TreeNode* node){
		w[j++] = node ;
	}
	TreeNode* pop(){
	   return w[--j] ;
	}
	TreeNode* top(){
		int temp = j-1 ;
		return w[temp] ;
	}
	bool empty(){
		if (j == 0) {
			return true ;
		}
		else
			return false ;
	}
};

TreeNode* CreateNode(int n){
	TreeNode* node = new TreeNode(n) ;
	return node ;
}

TreeNode* insert(TreeNode* node ,int n){
	if (node == nullptr){
		return CreateNode(n) ;
	}
	else if (n < node->data) {
		node->left = insert(node->left ,n) ;
	}
	else{
		node->right = insert(node->right ,n) ;
	}
	return node ;
}

AnsiString s = "" ;

void rinorder(TreeNode* node){
	if (node != nullptr) {
		rinorder(node -> left) ;
		s = s+IntToStr(node -> data)+" " ;
		rinorder(node -> right) ;
	}
	return ;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text) ;
	if (root == nullptr) {
		root = CreateNode(n) ;
	}
	else{
		insert(root ,n) ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		rinorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------

 bool search(TreeNode* node ,int target){
	if (node == nullptr) {
		return false ;
	}
	if (node->data == target) {
		return true ;
	}
	if (target < node->data) {
		return search(node->left ,target) ;
	}
	else{
		return search(node->right ,target) ;
	}
 }

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n = StrToInt(Edit3->Text) ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		bool res = search(root ,n) ;
		if (res) {
		   Memo1 -> Lines -> Add(IntToStr(n) + " is found!") ;
		}
		else{
		   Memo1 -> Lines -> Add(IntToStr(n) + " is not found!") ;
		}
	}
}
//---------------------------------------------------------------------------

void preorder(TreeNode* node){
	if (node != nullptr) {
		s = s+IntToStr(node -> data)+" " ;
		preorder(node -> left) ;
		preorder(node -> right) ;
	}
	return ;
}

void inorder(TreeNode* node){
	if (node != nullptr) {
		inorder(node -> left) ;
		s = s+IntToStr(node -> data)+" " ;
		inorder(node -> right) ;
	}
	return ;
}

void postorder(TreeNode* node){
	if (node != nullptr) {
		postorder(node -> left) ;
		postorder(node -> right) ;
		s = s+IntToStr(node -> data)+" " ;
	}
	return ;
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		preorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		inorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		postorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	int n = StrToInt(Edit4->Text) ;
	int range = StrToInt(Edit2->Text) ;
	int num = rand()%range ;
	int j = 0 ;

	if (root == nullptr) {
		root = CreateNode(n) ;
		j++ ;
	}
	for (int i = j ; i < n; i++) {
		num = rand()%range ;
		insert(root ,num) ;
	}
}
//---------------------------------------------------------------------------

void clear(TreeNode* node){
	if (node != nullptr) {
		clear(node->left) ;
		clear(node->right) ;
		free(node) ;
	}
}
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		clear(root) ;
		root = nullptr ;
	}
}
//---------------------------------------------------------------------------

bool nrsearch(TreeNode *node ,int target){
	while (node != NULL){
	    if (node->data == target) {
	        return true ;
	    }
	    if (target < node->data) {
	        node = node->left ;
	    }
	    else{
	        node = node->right ;
		}
	}
    return false ;
}
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int n = StrToInt(Edit3->Text) ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		bool res = nrsearch(root ,n) ;
		if (res) {
		   Memo1 -> Lines -> Add(IntToStr(n) + " is found!") ;
		}
		else{
		   Memo1 -> Lines -> Add(IntToStr(n) + " is not found!") ;
		}
	}
}
//---------------------------------------------------------------------------

void nrinorder(TreeNode* node){
	stack res ;

	//Form1 -> Memo1 -> Lines -> Add(node->data) ;
	do{
		while (node != nullptr){
			//Form1 -> Memo1 -> Lines -> Add(temp->data) ;
			res.push(node) ;
			node = node->left ;
		}
		node = res.pop() ;
		s = s + IntToStr(node->data) + " " ;
		node = node->right ;
	}while (!res.empty() || node != nullptr) ;
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
   // Memo1 -> Lines -> Add(IntToStr(root->left->data)) ;
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		nrinorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------

void nrpreorder(TreeNode* node){
	stack res ;

	//Form1 -> Memo1 -> Lines -> Add(node->data) ;
	do{
		while (node != nullptr){
			//Form1 -> Memo1 -> Lines -> Add(temp->data) ;
			s = s + IntToStr(node->data) + " " ;
			res.push(node) ;
			node = node->left ;
		}
		node = res.pop() ;
		node = node->right ;
	}while (!res.empty() || node != nullptr) ;
}

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		nrinorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		nrpreorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------
void nrpostorder(TreeNode* node){
	stack res ;

	//Form1 -> Memo1 -> Lines -> Add(node->data) ;
	do{
		while (node != nullptr){
			//Form1 -> Memo1 -> Lines -> Add(temp->data) ;
			s = IntToStr(node->data) + " " + s ;
			res.push(node) ;
			node = node->right ;
		}
		if (!res.empty()) {
			node = res.pop() ;
			node = node->left ;
		}
	}while (!res.empty() || node != nullptr) ;
}



void __fastcall TForm1::Button13Click(TObject *Sender)
{
	s = "" ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("The tree has no node!") ;
	}
	else{
		nrpostorder(root) ;
		Memo1 -> Lines -> Add(s) ;
	}
}
//---------------------------------------------------------------------------

TreeNode* Findmax(TreeNode* node){
	if (node) {
		while (node ->right){
			node = node->right ;
		}
	}
	return node ;
}
TreeNode* Delet(TreeNode* node ,int target){
	TreeNode* temp ;

	if (node == nullptr) {
		Form1 -> Memo1 -> Lines -> Add("找不到節點!") ;
		return node ;
	}

	if (node->data > target) {
		node->left = Delet(node->left ,target) ;
	}
	else if (node->data < target) {
		node->right = Delet(node->right ,target) ;
	}
	else{
		if (node->left && node->right) {      // 有2個子節點
			temp = Findmax(node->left) ;     //找到左子樹最大節點替換
			node->data = temp->data ;      //
			node->left = Delet(node->left ,node->data) ; // 把左子樹最大值刪除
		}
		else{                   //只有單個或沒有子節點
			temp = node ;
			if (!node->left) {
				node = node->right ;
			}
			else
				node = node->left ;
			free(temp) ;
			Form1 -> Memo1 -> Lines -> Add("成功刪除節點!") ;
		}
	}

	return node ;
}

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
	int n = StrToInt(Edit1->Text) ;
	if (root == nullptr) {
		Memo1 -> Lines -> Add("空樹!") ;
	}
	else{
		root = Delet(root ,n) ;
	}
}
//---------------------------------------------------------------------------

