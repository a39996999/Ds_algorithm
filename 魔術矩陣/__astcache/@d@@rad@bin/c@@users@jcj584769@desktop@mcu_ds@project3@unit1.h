//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TEdit *Edit1;
	TButton *Button1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TMemo *Memo3;
	TTabSheet *TabSheet3;
	TMemo *Memo4;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TTabSheet *TabSheet4;
	TStaticText *StaticText3;
	TStringGrid *StringGrid1;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	TMemo *Memo2;
	TMemo *Memo5;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
