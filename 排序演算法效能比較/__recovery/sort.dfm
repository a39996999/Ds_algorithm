object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Sorting ver0.1  by Guan-Zhi Chen 2020/0626'
  ClientHeight = 699
  ClientWidth = 903
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = -6
    Width = 249
    Height = 697
    TabOrder = 0
    object StaticText1: TStaticText
      Left = 16
      Top = 16
      Width = 55
      Height = 29
      Caption = 'Input'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object StaticText2: TStaticText
      Left = 47
      Top = 72
      Width = 58
      Height = 23
      Caption = 'Times :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 112
      Top = 72
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit2: TEdit
      Left = 112
      Top = 112
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Edit3: TEdit
      Left = 112
      Top = 160
      Width = 121
      Height = 21
      TabOrder = 4
    end
    object StaticText5: TStaticText
      Left = 16
      Top = 216
      Width = 42
      Height = 29
      Caption = 'Sort'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object CheckBox1: TCheckBox
      Left = 48
      Top = 251
      Width = 129
      Height = 22
      Caption = 'Selection sort'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object Button1: TButton
      Left = 143
      Top = 519
      Width = 75
      Height = 25
      Caption = 'Sort'
      TabOrder = 7
      OnClick = Button1Click
    end
    object CheckBox2: TCheckBox
      Left = 48
      Top = 279
      Width = 129
      Height = 22
      Caption = 'Insert sort'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
    end
    object CheckBox3: TCheckBox
      Left = 48
      Top = 307
      Width = 129
      Height = 22
      Caption = 'Bubble sort'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
    end
    object CheckBox4: TCheckBox
      Left = 47
      Top = 335
      Width = 129
      Height = 22
      Caption = 'Quick sort (R)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
    end
    object CheckBox5: TCheckBox
      Left = 47
      Top = 363
      Width = 138
      Height = 22
      Caption = 'Quick sort (NR)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 11
    end
    object CheckBox6: TCheckBox
      Left = 47
      Top = 391
      Width = 129
      Height = 22
      Caption = 'Merge sort (R)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 12
    end
    object CheckBox7: TCheckBox
      Left = 48
      Top = 419
      Width = 129
      Height = 22
      Caption = 'Merge sort (NR)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 13
    end
    object CheckBox8: TCheckBox
      Left = 47
      Top = 447
      Width = 129
      Height = 22
      Caption = 'Heap sort'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 14
    end
    object CheckBox9: TCheckBox
      Left = 47
      Top = 475
      Width = 129
      Height = 22
      Caption = 'Radix sort'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 15
    end
    object CheckBox11: TCheckBox
      Left = 16
      Top = 519
      Width = 129
      Height = 22
      Caption = 'See data'
      Color = clWindow
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 16
    end
  end
  object Panel2: TPanel
    Left = 255
    Top = -6
    Width = 650
    Height = 703
    Caption = 'Panel2'
    TabOrder = 1
    object PageControl1: TPageControl
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 642
      Height = 695
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Data'
        ExplicitLeft = -4
        ExplicitTop = 26
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 634
          Height = 667
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Chart'
        ImageIndex = 1
        ExplicitLeft = 44
        ExplicitTop = 108
        ExplicitWidth = 281
        ExplicitHeight = 165
        object Chart1: TChart
          Left = 0
          Top = 0
          Width = 634
          Height = 667
          Title.Text.Strings = (
            'TChart')
          Align = alClient
          Color = clMenuBar
          TabOrder = 0
          ExplicitLeft = -199
          ExplicitTop = 144
          DefaultCanvas = 'TGDIPlusCanvas'
          ColorPaletteIndex = 13
          object Series1: TLineSeries
            Active = False
            Brush.BackColor = clDefault
            Pointer.InflateMargins = True
            Pointer.Style = psRectangle
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
        end
      end
    end
  end
  object StaticText3: TStaticText
    Left = 79
    Top = 104
    Width = 26
    Height = 23
    Caption = 'N :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object StaticText4: TStaticText
    Left = 47
    Top = 152
    Width = 59
    Height = 23
    Caption = 'Range :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
end
