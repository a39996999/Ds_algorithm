//---------------------------------------------------------------------------

#ifndef BSTH
#define BSTH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TMemo *Memo1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TStaticText *StaticText1;
	TButton *Button5;
	TButton *Button6;
	TEdit *Edit3;
	TStaticText *StaticText2;
	TButton *Button7;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TButton *Button8;
	TStaticText *StaticText6;
	TButton *Button9;
	TEdit *Edit2;
	TStaticText *StaticText7;
	TStaticText *StaticText8;
	TEdit *Edit4;
	TButton *Button10;
	TStaticText *StaticText9;
	TStaticText *StaticText10;
	TButton *Delete;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
