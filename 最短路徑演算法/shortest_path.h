//---------------------------------------------------------------------------

#ifndef shortest_pathH
#define shortest_pathH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TPanel *Panel3;
	TMemo *Memo2;
	TStaticText *StaticText1;
	TButton *Button1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TStringGrid *StringGrid1;
	TOpenDialog *OpenDialog1;
	TStaticText *StaticText6;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TCheckBox *CheckBox3;
	TStringGrid *StringGrid2;
	TTabSheet *TabSheet4;
	TStringGrid *StringGrid3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
