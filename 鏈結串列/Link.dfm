object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'G.Z.Chen link-list ver0.2'
  ClientHeight = 727
  ClientWidth = 910
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
    Width = 1040
    Height = 793
    Caption = 'Panel1'
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 1038
      Height = 791
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Single Link-List'
        ExplicitLeft = 0
        ExplicitTop = 28
        object Panel2: TPanel
          Left = 0
          Top = 0
          Width = 1030
          Height = 763
          Align = alClient
          Color = cl3DLight
          ParentBackground = False
          TabOrder = 0
          ExplicitLeft = 3
          ExplicitWidth = 885
          ExplicitHeight = 289
          object StaticText1: TStaticText
            Left = 50
            Top = 32
            Width = 89
            Height = 33
            Caption = 'Element'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object StaticText2: TStaticText
            Left = 50
            Top = 96
            Width = 74
            Height = 33
            Caption = 'Target'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
          object Button1: TButton
            Left = 336
            Top = 40
            Width = 75
            Height = 33
            Caption = 'Insert First'
            TabOrder = 2
            OnClick = Button1Click
          end
          object Button2: TButton
            Left = 472
            Top = 42
            Width = 89
            Height = 31
            Caption = 'Insert Last'
            TabOrder = 3
            OnClick = Button2Click
          end
          object Button3: TButton
            Left = 336
            Top = 104
            Width = 75
            Height = 33
            Caption = 'Search Target'
            TabOrder = 4
            OnClick = Button3Click
          end
          object Button4: TButton
            Left = 456
            Top = 104
            Width = 129
            Height = 33
            Caption = 'Search_Insert Previous'
            TabOrder = 5
            OnClick = Button4Click
          end
          object Button7: TButton
            Left = 776
            Top = 174
            Width = 75
            Height = 34
            Caption = 'Clear all'
            TabOrder = 6
            OnClick = Button7Click
          end
          object Button8: TButton
            Left = 616
            Top = 100
            Width = 121
            Height = 33
            Caption = 'Search_Insert Next'
            TabOrder = 7
            OnClick = Button8Click
          end
          object Edit1: TEdit
            Left = 169
            Top = 42
            Width = 121
            Height = 21
            TabOrder = 8
          end
          object Edit2: TEdit
            Left = 169
            Top = 106
            Width = 121
            Height = 21
            TabOrder = 9
          end
          object Button5: TButton
            Left = 776
            Top = 104
            Width = 75
            Height = 33
            Caption = 'Delete'
            TabOrder = 10
            OnClick = Button5Click
          end
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Double Link-List'
        ImageIndex = 1
        object Panel4: TPanel
          Left = 0
          Top = 0
          Width = 1030
          Height = 763
          Align = alClient
          Caption = 'Panel4'
          Color = cl3DLight
          ParentBackground = False
          TabOrder = 0
          ExplicitLeft = 24
          ExplicitTop = 16
          object Edit4: TEdit
            Left = 232
            Top = 47
            Width = 121
            Height = 21
            TabOrder = 0
          end
          object Edit5: TEdit
            Left = 232
            Top = 112
            Width = 121
            Height = 21
            TabOrder = 1
          end
          object StaticText3: TStaticText
            Left = 108
            Top = 105
            Width = 76
            Height = 28
            Caption = 'target'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = #27161#26999#39636
            Font.Style = []
            ParentFont = False
            TabOrder = 2
          end
          object StaticText4: TStaticText
            Left = 108
            Top = 40
            Width = 88
            Height = 28
            Caption = 'Element'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = #27161#26999#39636
            Font.Style = []
            ParentFont = False
            TabOrder = 3
          end
          object Button11: TButton
            Left = 424
            Top = 45
            Width = 75
            Height = 25
            Caption = 'Insert_first'
            TabOrder = 4
            OnClick = Button11Click
          end
          object Button12: TButton
            Left = 544
            Top = 45
            Width = 75
            Height = 25
            Caption = 'Insert_last'
            TabOrder = 5
            OnClick = Button12Click
          end
          object Button13: TButton
            Left = 424
            Top = 105
            Width = 75
            Height = 30
            Caption = 'search_target'
            TabOrder = 6
            OnClick = Button13Click
          end
          object Button14: TButton
            Left = 521
            Top = 110
            Width = 136
            Height = 25
            Caption = 'Search_Insert Previous'
            TabOrder = 7
            OnClick = Button14Click
          end
          object Button15: TButton
            Left = 680
            Top = 110
            Width = 105
            Height = 25
            Caption = 'Search_Insert Next'
            TabOrder = 8
            OnClick = Button15Click
          end
          object Button16: TButton
            Left = 736
            Top = 189
            Width = 75
            Height = 25
            Caption = 'clear'
            TabOrder = 9
            OnClick = Button16Click
          end
          object Button17: TButton
            Left = 808
            Top = 109
            Width = 64
            Height = 28
            Caption = 'Delete'
            TabOrder = 10
            OnClick = Button17Click
          end
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Link-Stack'
        ImageIndex = 2
        ExplicitLeft = 0
        ExplicitTop = 16
        object Panel3: TPanel
          Left = -8
          Top = 3
          Width = 896
          Height = 241
          Color = cl3DLight
          ParentBackground = False
          TabOrder = 0
          object s: TStaticText
            Left = 96
            Top = 80
            Width = 89
            Height = 31
            Caption = 'Element'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -27
            Font.Name = #26032#32048#26126#39636'-ExtB'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object Edit3: TEdit
            Left = 208
            Top = 88
            Width = 121
            Height = 23
            TabOrder = 1
          end
          object Button6: TButton
            Left = 440
            Top = 32
            Width = 89
            Height = 41
            Caption = 'push'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnClick = Button6Click
          end
          object Button9: TButton
            Left = 440
            Top = 96
            Width = 89
            Height = 41
            Caption = 'pop'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnClick = Button9Click
          end
          object Button10: TButton
            Left = 440
            Top = 160
            Width = 89
            Height = 33
            Caption = 'clear'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 4
            OnClick = Button10Click
          end
        end
      end
    end
  end
  object PageControl2: TPageControl
    Left = -5
    Top = 264
    Width = 910
    Height = 446
    ActivePage = TabSheet4
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #27161#26999#39636
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object TabSheet4: TTabSheet
      Caption = 'TabSheet4'
      ExplicitTop = 24
      ExplicitHeight = 418
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 902
        Height = 409
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #27161#26999#39636
        Font.Style = []
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        TabOrder = 0
        ExplicitHeight = 418
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'TabSheet5'
      ImageIndex = 1
      ExplicitTop = 24
      ExplicitHeight = 418
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 902
        Height = 409
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #27161#26999#39636
        Font.Style = []
        Lines.Strings = (
          'Memo2')
        ParentFont = False
        TabOrder = 0
        ExplicitLeft = 1
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'TabSheet6'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 902
        Height = 409
        Align = alClient
        Lines.Strings = (
          'Memo3')
        TabOrder = 0
        ExplicitLeft = 1
        ExplicitTop = 1
        ExplicitWidth = 1028
        ExplicitHeight = 761
      end
    end
  end
end
