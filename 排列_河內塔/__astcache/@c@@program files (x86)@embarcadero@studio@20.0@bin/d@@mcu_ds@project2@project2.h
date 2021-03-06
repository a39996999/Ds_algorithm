//---------------------------------------------------------------------------

#ifndef project2H
#define project2H
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
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TLabel *Label1;
	TLabel *Label2;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	TMemo *Memo4;
	TEdit *Edit1;
	TLabel *Label4;
	TEdit *Edit2;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button1;
	TCheckBox *CheckBox1;
	TLabel *Label3;
	TEdit *Edit3;
	TCheckBox *CheckBox2;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
