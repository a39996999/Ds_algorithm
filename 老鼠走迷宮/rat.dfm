object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'b'
  ClientHeight = 654
  ClientWidth = 756
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 184
    Top = 0
    Width = 577
    Height = 657
    Caption = 'Panel2'
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 575
      Height = 655
      ActivePage = TabSheet1
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Maze'
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 567
          Height = 617
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          Lines.Strings = (
            'Memo1')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          ExplicitLeft = 3
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Mouse'
        ImageIndex = 1
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 567
          Height = 617
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = #26032#32048#26126#39636
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'StringGrid'
        ImageIndex = 2
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 567
          Height = 617
          Align = alClient
          ColCount = 4
          DefaultColWidth = 58
          DefaultRowHeight = 58
          FixedCols = 0
          RowCount = 4
          FixedRows = 0
          TabOrder = 0
          OnDrawCell = StringGrid1DrawCell
        end
      end
    end
  end
  object Panel1: TPanel
    Left = -7
    Top = -30
    Width = 190
    Height = 682
    TabOrder = 1
    object Button1: TButton
      Left = 40
      Top = 104
      Width = 97
      Height = 49
      Caption = 'Read file'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Toledo'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object StaticText1: TStaticText
      Left = 25
      Top = 54
      Width = 144
      Height = 31
      Caption = #32769#40736#36208#36855#23470
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #27161#26999#39636
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object Button2: TButton
      Left = 40
      Top = 176
      Width = 97
      Height = 49
      Caption = 'Play'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Toledo'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button2Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 5
    Top = 609
  end
end
