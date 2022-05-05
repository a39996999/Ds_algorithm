object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Minmum Spanning Tree by G.Z Chen Ver 0.1 2020/6/6'
  ClientHeight = 699
  ClientWidth = 1002
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
    Top = 0
    Width = 265
    Height = 689
    TabOrder = 0
    object Panel3: TPanel
      Left = 0
      Top = 0
      Width = 265
      Height = 377
      TabOrder = 0
      object StaticText1: TStaticText
        Left = 8
        Top = 8
        Width = 143
        Height = 33
        Caption = 'Input Control'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object Button1: TButton
        Left = 78
        Top = 47
        Width = 93
        Height = 34
        Caption = 'Read Graph'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = Button1Click
      end
      object StaticText2: TStaticText
        Left = 8
        Top = 88
        Width = 163
        Height = 27
        Caption = 'Number of vertices'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object StaticText3: TStaticText
        Left = 8
        Top = 121
        Width = 142
        Height = 27
        Caption = 'Range of weight'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object StaticText4: TStaticText
        Left = 8
        Top = 154
        Width = 169
        Height = 27
        Caption = 'Maximum of weight'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
      object Edit1: TEdit
        Left = 177
        Top = 88
        Width = 72
        Height = 21
        TabOrder = 5
      end
      object Edit2: TEdit
        Left = 177
        Top = 121
        Width = 72
        Height = 21
        TabOrder = 6
      end
      object Edit3: TEdit
        Left = 177
        Top = 154
        Width = 72
        Height = 21
        TabOrder = 7
      end
      object Button2: TButton
        Left = 40
        Top = 204
        Width = 161
        Height = 37
        Caption = 'Generate Graph'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        OnClick = Button2Click
      end
      object CheckBox2: TCheckBox
        Left = 49
        Top = 263
        Width = 152
        Height = 26
        Caption = 'Echo print graph'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 9
      end
    end
    object M: TStaticText
      Left = 8
      Top = 383
      Width = 239
      Height = 33
      Caption = 'MinmumSpanningTree'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object Button3: TButton
      Left = 40
      Top = 465
      Width = 161
      Height = 41
      Caption = 'Prim'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 40
      Top = 528
      Width = 161
      Height = 41
      Caption = 'Kruskal'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button4Click
    end
    object CheckBox1: TCheckBox
      Left = 49
      Top = 422
      Width = 161
      Height = 17
      Caption = 'Print CPU Runtime'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 4
      OnClick = CheckBox1Click
    end
  end
  object Panel2: TPanel
    Left = 271
    Top = -8
    Width = 730
    Height = 705
    Caption = 'Panel2'
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 0
      Top = 8
      Width = 729
      Height = 697
      ActivePage = TabSheet2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Adjacency matrix'#39's graph'
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 721
          Height = 663
          Align = alClient
          ColCount = 8
          RowCount = 8
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Minimum Spanning Tree'
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 721
          Height = 663
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Tahoma'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 40
    Top = 48
  end
end
