object Form1: TForm1
  Left = 0
  Top = 0
  AutoSize = True
  BorderWidth = 5
  Caption = 'Form1'
  ClientHeight = 457
  ClientWidth = 876
  Color = clWhite
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel9: TPanel
    Left = 210
    Top = 0
    Width = 473
    Height = 73
    BevelInner = bvRaised
    BorderWidth = 5
    Color = cl3DLight
    ParentBackground = False
    TabOrder = 0
    object Label14: TLabel
      Left = 12
      Top = 27
      Width = 121
      Height = 13
      Caption = #1042#1067#1041#1045#1056#1048#1058#1045' '#1057#1053#1040#1056#1071#1044'       :'
    end
    object ComboBox4: TComboBox
      Left = 125
      Top = 24
      Width = 90
      Height = 21
      TabOrder = 0
      Text = '76_BERRIER'
      Items.Strings = (
        '130_SHTAT'
        '130_TARAN'
        '100'
        '30'
        '76_SHTAT'
        '76_BERRIER'
        'UNKNOWN')
    end
    object LabeledEdit16: TLabeledEdit
      Left = 360
      Top = 24
      Width = 76
      Height = 21
      EditLabel.Width = 108
      EditLabel.Height = 13
      EditLabel.Caption = #1056#1072#1089#1089#1077#1103#1085#1080#1077' '#1040#1059', '#1084#1083#1088#1076' :'
      LabelPosition = lpLeft
      TabOrder = 1
      Text = '0,4'
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 79
    Width = 876
    Height = 378
    BevelInner = bvRaised
    BorderWidth = 5
    Color = clActiveCaption
    Ctl3D = True
    ParentBackground = False
    ParentCtl3D = False
    TabOrder = 1
    object Label5: TLabel
      Left = 35
      Top = 111
      Width = 261
      Height = 16
      AutoSize = False
      Caption = #1044#1048#1056' '#1056#1045#1047#1059#1051#1068#1058#1040#1058#1054#1042'  '#1057'  .SHP  '#1060#1040#1049#1051#1040#1052#1048' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 327
      Top = 144
      Width = 198
      Height = 33
      Caption = #1056#1040#1057#1063#1048#1058#1040#1058#1068' '#1054#1058#1051#1048#1063#1048#1071' EPS BET '#1043#1057#1050' '#1048' '#1050#1043#1057#1050
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 0
      WordWrap = True
      OnClick = Button1Click
    end
    object Button5: TButton
      Left = 667
      Top = 104
      Width = 44
      Height = 25
      Caption = '...'
      TabOrder = 1
      OnClick = Button5Click
    end
    object Edit2: TEdit
      Left = 302
      Top = 108
      Width = 331
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object Panel5: TPanel
      Left = 11
      Top = 10
      Width = 334
      Height = 73
      BorderStyle = bsSingle
      TabOrder = 3
      object Label6: TLabel
        Left = 96
        Top = 8
        Width = 167
        Height = 13
        Caption = #1059#1043#1051#1067' '#1055#1056#1048#1062#1045#1051#1048#1042#1040#1053#1048#1071' '#1043#1057#1050', '#1075#1088#1072#1076
      end
      object LabeledEdit7: TLabeledEdit
        Left = 189
        Top = 40
        Width = 121
        Height = 21
        EditLabel.Width = 18
        EditLabel.Height = 13
        EditLabel.Caption = 'BET'
        TabOrder = 0
        Text = '90'
      end
      object LabeledEdit6: TLabeledEdit
        Left = 18
        Top = 40
        Width = 121
        Height = 21
        EditLabel.Width = 17
        EditLabel.Height = 13
        EditLabel.Caption = 'Eps'
        TabOrder = 1
        Text = '10'
      end
    end
    object Panel6: TPanel
      Left = 389
      Top = 10
      Width = 380
      Height = 87
      BorderStyle = bsSingle
      TabOrder = 4
      object Label7: TLabel
        Left = 96
        Top = 8
        Width = 181
        Height = 13
        Caption = #1042#1045#1050#1058#1054#1056' '#1057#1050#1054#1056#1054#1057#1058#1048' '#1050#1054#1056#1040#1041#1051#1071' '#1042' '#1043#1057#1050
      end
      object LabeledEdit9: TLabeledEdit
        Left = 138
        Top = 40
        Width = 111
        Height = 21
        EditLabel.Width = 113
        EditLabel.Height = 13
        EditLabel.Caption = #1089#1082#1086#1088#1086#1089#1090#1100' '#1089#1085#1072#1088#1103#1076#1072', '#1084'/'#1089
        TabOrder = 0
        Text = '980'
      end
      object LabeledEdit11: TLabeledEdit
        Left = 10
        Top = 40
        Width = 111
        Height = 21
        EditLabel.Width = 113
        EditLabel.Height = 13
        EditLabel.Caption = #1089#1082#1086#1088#1086#1089#1090#1100' '#1082#1086#1088#1072#1073#1083#1103', '#1084'/'#1089
        TabOrder = 1
        Text = '10'
      end
    end
    object Panel1: TPanel
      Left = 29
      Top = 183
      Width = 617
      Height = 156
      TabOrder = 5
      object Panel7: TPanel
        Left = 13
        Top = 12
        Width = 398
        Height = 85
        TabOrder = 0
        object Label8: TLabel
          Left = 30
          Top = 8
          Width = 120
          Height = 13
          Caption = #1055#1040#1051#1059#1041#1053#1067#1045' '#1059#1043#1051#1067', '#1043#1056#1040#1044
        end
        object LabeledEdit17: TLabeledEdit
          Left = 285
          Top = 44
          Width = 98
          Height = 21
          EditLabel.Width = 78
          EditLabel.Height = 13
          EditLabel.Caption = #1041#1086#1088#1090'. '#1082#1088#1077#1085', Tet'
          TabOrder = 0
          Text = '10'
        end
        object LabeledEdit19: TLabeledEdit
          Left = 149
          Top = 44
          Width = 98
          Height = 21
          EditLabel.Width = 76
          EditLabel.Height = 13
          EditLabel.Caption = #1050#1086#1088#1084'. '#1082#1088#1077#1085', Psi'
          TabOrder = 1
          Text = '5'
        end
        object LabeledEdit18: TLabeledEdit
          Left = 30
          Top = 44
          Width = 98
          Height = 21
          EditLabel.Width = 65
          EditLabel.Height = 13
          EditLabel.Caption = #1050#1091#1088#1089'. '#1091#1075#1086#1083' Q'
          TabOrder = 2
          Text = '0'
        end
      end
      object Button2: TButton
        Left = 181
        Top = 113
        Width = 198
        Height = 33
        Caption = #1055#1054#1057#1058#1056#1054#1048#1058#1068' '#1043#1056#1040#1060#1048#1050#1048' '#1057#1050#1047' '#1054#1064#1048#1041#1054#1050' '#1054#1058#1056#1040#1041#1054#1058#1050#1048' '#1059#1043#1051#1054#1042' '#1053#1040#1042#1045#1044#1045#1053#1048#1071' '
        DoubleBuffered = True
        ParentDoubleBuffered = False
        TabOrder = 1
        WordWrap = True
        OnClick = Button2Click
      end
      object LabeledEdit1: TLabeledEdit
        Left = 434
        Top = 52
        Width = 98
        Height = 21
        EditLabel.Width = 99
        EditLabel.Height = 13
        EditLabel.Caption = #1056#1072#1073#1086#1090#1085#1086#1077' '#1074#1088#1077#1084#1103', '#1084#1089
        TabOrder = 2
        Text = '0'
      end
      object LabeledEdit2: TLabeledEdit
        Left = 434
        Top = 92
        Width = 98
        Height = 21
        EditLabel.Width = 63
        EditLabel.Height = 13
        EditLabel.Caption = 'Y '#1040#1059'  '#1055#1057#1050', '#1084
        TabOrder = 3
        Text = '10'
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 736
    Top = 56
  end
  object OpenDialog2: TOpenDialog
    Left = 816
    Top = 56
  end
  object OpenDialog3: TOpenDialog
    Left = 96
    Top = 48
  end
end
