//---------------------------------------------------------------------------

#ifndef ratH
#define ratH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TPageControl *PageControl1;
	TPanel *Panel1;
	TPanel *Panel2;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TStaticText *StaticText1;
	TOpenDialog *OpenDialog1;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TButton *Button2;
	TTabSheet *TabSheet3;
	TStringGrid *StringGrid1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
