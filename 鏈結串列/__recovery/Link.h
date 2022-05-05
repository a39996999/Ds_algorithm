//---------------------------------------------------------------------------

#ifndef LinkH
#define LinkH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TPanel *Panel1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TPageControl *PageControl2;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TMemo *Memo1;
	TMemo *Memo2;
	TPanel *Panel2;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button7;
	TButton *Button8;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button5;
	TPanel *Panel3;
	TStaticText *s;
	TEdit *Edit3;
	TTabSheet *TabSheet6;
	TMemo *Memo3;
	TButton *Button6;
	TButton *Button9;
	TButton *Button10;
	TPanel *Panel4;
	TEdit *Edit4;
	TEdit *Edit5;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
