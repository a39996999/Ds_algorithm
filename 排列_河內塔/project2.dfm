object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Pemutations by G.Z Chen on 2019/10/10 Ver0.3'
  ClientHeight = 612
  ClientWidth = 916
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
    Left = 8
    Top = 8
    Width = 249
    Height = 605
    TabOrder = 0
    object Label1: TLabel
      Left = 40
      Top = 13
      Width = 153
      Height = 35
      Caption = 'Permutation'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Toledo'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 40
      Top = 294
      Width = 156
      Height = 35
      Caption = 'Hanoi Tower'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Toledo'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 18
      Top = 114
      Width = 54
      Height = 34
      Caption = 'N = '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Vivian'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 121
      Top = 156
      Width = 100
      Height = 28
      Caption = '( N <= 9 ) '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Toledo'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 18
      Top = 52
      Width = 57
      Height = 34
      Caption = 'K = '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Vivian'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 18
      Top = 351
      Width = 54
      Height = 34
      Caption = 'N = '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Vivian'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 100
      Top = 57
      Width = 121
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 100
      Top = 119
      Width = 121
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object Button1: TButton
      Left = 18
      Top = 200
      Width = 191
      Height = 33
      Caption = 'Permutation'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Toledo'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button1Click
    end
    object CheckBox1: TCheckBox
      Left = 121
      Top = 246
      Width = 109
      Height = 34
      Caption = 'tracing'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object Edit3: TEdit
      Left = 100
      Top = 356
      Width = 121
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
    end
    object CheckBox2: TCheckBox
      Left = 121
      Top = 475
      Width = 109
      Height = 34
      Caption = 'tracing'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object Button2: TButton
      Left = 19
      Top = 424
      Width = 190
      Height = 37
      Caption = 'Move'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Toledo'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = Button2Click
    end
  end
  object PageControl1: TPageControl
    Left = 244
    Top = 8
    Width = 669
    Height = 609
    ActivePage = TabSheet1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = '  Permutation'
      ExplicitWidth = 594
      ExplicitHeight = 520
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 661
        Height = 571
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitWidth = 594
        ExplicitHeight = 520
      end
    end
    object TabSheet2: TTabSheet
      Caption = '     Permutation_tracing  '
      ImageIndex = 1
      ExplicitWidth = 594
      ExplicitHeight = 520
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 661
        Height = 571
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitWidth = 594
        ExplicitHeight = 520
      end
    end
    object TabSheet3: TTabSheet
      Caption = '   All Moves  '
      ImageIndex = 2
      ExplicitWidth = 594
      ExplicitHeight = 520
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 661
        Height = 571
        Align = alClient
        Ctl3D = True
        Lines.Strings = (
          'Memo3')
        ParentCtl3D = False
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitLeft = -4
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Move_tracing'
      ImageIndex = 3
      ExplicitWidth = 594
      ExplicitHeight = 520
      object Memo4: TMemo
        Left = 0
        Top = 0
        Width = 661
        Height = 571
        Align = alClient
        Lines.Strings = (
          'Memo4')
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitWidth = 594
        ExplicitHeight = 520
      end
    end
  end
end
