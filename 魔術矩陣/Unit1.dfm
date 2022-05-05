object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Magic Square by G.Z Chen on 2019/10/20 Ver0.2'
  ClientHeight = 565
  ClientWidth = 864
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
    Top = 0
    Width = 844
    Height = 186
    TabOrder = 0
    object Panel3: TPanel
      Left = 440
      Top = 16
      Width = 329
      Height = 153
      Color = clMedGray
      ParentBackground = False
      TabOrder = 0
      object RadioButton1: TRadioButton
        Left = 40
        Top = 60
        Width = 113
        Height = 17
        Caption = 'Left-Top'
        DoubleBuffered = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Toledo'
        Font.Style = []
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 0
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 200
        Top = 60
        Width = 113
        Height = 17
        Caption = 'RightTop'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Toledo'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RadioButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 200
        Top = 100
        Width = 113
        Height = 17
        Caption = 'Right-Bottom'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Toledo'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = RadioButton3Click
      end
      object RadioButton4: TRadioButton
        Left = 40
        Top = 100
        Width = 113
        Height = 17
        Caption = 'Left-Bottom'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Toledo'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = RadioButton4Click
      end
      object Button2: TButton
        Left = 192
        Top = 13
        Width = 113
        Height = 32
        Caption = 'Generate'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Vivian'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = Button2Click
      end
    end
    object StaticText1: TStaticText
      Left = 454
      Top = 29
      Width = 139
      Height = 27
      Caption = 'Direction Option'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 65
      Top = 67
      Width = 129
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object Button1: TButton
      Left = 224
      Top = 61
      Width = 137
      Height = 41
      Caption = 'Generate'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tarzan'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button1Click
    end
    object StaticText3: TStaticText
      Left = 85
      Top = 116
      Width = 276
      Height = 30
      Caption = '( N < 20 &&&&& N '#28858#22855#25976')'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Vivian'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 192
    Width = 849
    Height = 364
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 847
      Height = 362
      ActivePage = TabSheet1
      Align = alClient
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #26032#32048#26126#39636
      Font.Style = []
      MultiLine = True
      ParentFont = False
      ScrollOpposite = True
      TabOrder = 0
      ExplicitLeft = 0
      ExplicitTop = 0
      object TabSheet5: TTabSheet
        Caption = 'Left Top '
        ImageIndex = 4
        ExplicitLeft = 0
        ExplicitTop = 23
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 839
          Height = 327
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Consolas'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet6: TTabSheet
        Caption = ' Right Bottom '
        ImageIndex = 5
        ExplicitLeft = 12
        ExplicitTop = 23
        object Memo5: TMemo
          Left = 0
          Top = 0
          Width = 839
          Height = 327
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Consolas'
          Font.Style = []
          Lines.Strings = (
            'Memo2')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet1: TTabSheet
        Caption = ' No-aligent Metrix '
        ExplicitWidth = 735
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 839
          Height = 327
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = []
          Lines.Strings = (
            'Memo1')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          ExplicitWidth = 735
        end
      end
      object TabSheet2: TTabSheet
        Caption = ' Aligent Metrix '
        ImageIndex = 1
        ExplicitWidth = 735
        object Memo3: TMemo
          Left = 0
          Top = 0
          Width = 839
          Height = 327
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Consolas'
          Font.Style = []
          Lines.Strings = (
            'Memo1')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          ExplicitWidth = 735
        end
      end
      object TabSheet3: TTabSheet
        Caption = '  Aligent-Metrix + Check '
        ImageIndex = 2
        ExplicitWidth = 735
        object Memo4: TMemo
          Left = 0
          Top = 0
          Width = 839
          Height = 327
          Align = alClient
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Consolas'
          Font.Style = []
          Lines.Strings = (
            'Memo1')
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
          ExplicitWidth = 735
        end
      end
      object TabSheet4: TTabSheet
        Caption = ' GridView Metrix '
        ImageIndex = 3
        ExplicitWidth = 735
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 839
          Height = 327
          Align = alClient
          ColCount = 20
          RowCount = 20
          TabOrder = 0
          ExplicitLeft = -72
          ExplicitTop = -41
          ExplicitWidth = 735
        end
      end
    end
  end
  object StaticText2: TStaticText
    Left = 32
    Top = 16
    Width = 93
    Height = 30
    Caption = #35531#36664#20837'N:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Vivian'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
end
