object Form4: TForm4
  Left = 0
  Top = 0
  Caption = #1052#1054#1056#1057#1050#1040#1071' '#1062#1045#1051#1068
  ClientHeight = 704
  ClientWidth = 1086
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 0
    Top = 16
    Width = 224
    Height = 122
    TabOrder = 0
    object Label9: TLabel
      Left = 48
      Top = 16
      Width = 55
      Height = 13
      Caption = #1042#1067#1041#1045#1056#1048#1058#1045':'
    end
    object Label7: TLabel
      Left = 7
      Top = 38
      Width = 47
      Height = 13
      Caption = '1. '#1062#1045#1051#1068' :'
    end
    object Label4: TLabel
      Left = 8
      Top = 67
      Width = 55
      Height = 13
      Caption = '2. '#1040#1059'        :'
    end
    object Label5: TLabel
      Left = 0
      Top = 100
      Width = 48
      Height = 13
      Caption = '  3. '#1042#1059'    :'
    end
    object ComboBox3: TComboBox
      Left = 117
      Top = 33
      Width = 92
      Height = 21
      ItemIndex = 0
      TabOrder = 0
      Text = #1069#1089#1084#1080#1085#1077#1094
      Items.Strings = (
        #1069#1089#1084#1080#1085#1077#1094
        #1050#1072#1090#1077#1088)
    end
    object ComboBox1: TComboBox
      Left = 119
      Top = 70
      Width = 90
      Height = 21
      ItemIndex = 0
      TabOrder = 1
      Text = 'A_192M'
      Items.Strings = (
        'A_192M'
        'A_190_01'
        '')
    end
    object ComboBox2: TComboBox
      Left = 117
      Top = 97
      Width = 90
      Height = 21
      ItemIndex = 0
      TabOrder = 2
      Text = 'D4MRM'
      Items.Strings = (
        'D4MRM'
        'MFIVU'
        ''
        ''
        '')
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 318
    Width = 649
    Height = 233
    Hint = #1057#1050#1047' '#1057#1048#1053#1057'= 0,41,  '#1057#1050#1047' '#1057#1050#1054#1056' '#1057#1048#1053#1057' =0,3'
    Color = clMoneyGreen
    ParentBackground = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    object Label2: TLabel
      Left = 119
      Top = 11
      Width = 170
      Height = 16
      Caption = #1056#1040#1057#1057#1063#1045#1058' '#1069#1060#1060#1045#1050#1058#1048#1042#1053#1054#1057#1058#1048
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabeledEdit46: TLabeledEdit
      Left = 24
      Top = 186
      Width = 113
      Height = 25
      AutoSize = False
      EditLabel.Width = 71
      EditLabel.Height = 17
      EditLabel.Caption = #1042#1077#1088#1086#1103#1090#1085' P'
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -15
      EditLabel.Font.Name = 'Arial'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object LabeledEdit34: TLabeledEdit
      Left = 208
      Top = 184
      Width = 114
      Height = 21
      EditLabel.Width = 109
      EditLabel.Height = 13
      EditLabel.Caption = #1042#1077#1088#1086#1103#1090#1085' 1 '#1080#1089#1087#1099#1090#1072#1085#1080#1103
      ReadOnly = True
      TabOrder = 1
    end
    object Panel1: TPanel
      Left = 16
      Top = 33
      Width = 521
      Height = 131
      TabOrder = 2
      object Label3: TLabel
        Left = 12
        Top = 38
        Width = 137
        Height = 16
        AutoSize = False
        Caption = #1055#1072#1087#1082#1072' '#1089' '#1075#1088#1072#1092#1080#1082#1072#1084#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Button4: TButton
        Left = 461
        Top = 37
        Width = 27
        Height = 25
        Caption = '...'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button4Click
      end
      object Edit2: TEdit
        Left = 155
        Top = 39
        Width = 286
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object Panel4: TPanel
        Left = 14
        Top = 77
        Width = 465
        Height = 41
        TabOrder = 2
        object Button3: TButton
          Left = 21
          Top = 8
          Width = 154
          Height = 25
          Hint = #1058#1088#1072#1076#1080#1094#1080#1086#1085#1085#1099#1081' '#1088#1072#1089#1095#1077#1090' '#1101#1092#1092#1077#1082#1090#1080#1074#1085#1086#1089#1090#1080
          Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100' '#1101#1092#1092#1077#1082#1090#1080#1074#1085#1086#1089#1090#1100
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = Button3Click
        end
        object Button6: TButton
          Left = 181
          Top = 8
          Width = 180
          Height = 25
          Hint = #1058#1088#1072#1076#1080#1094#1080#1086#1085#1085#1099#1081' '#1088#1072#1089#1095#1077#1090' '#1101#1092#1092#1077#1082#1090#1080#1074#1085#1086#1089#1090#1080
          Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100' '#1086#1089#1088#1077#1076#1085#1077#1085#1085#1091#1102' '#1101#1092#1092#1077#1082#1090
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = Button6Click
        end
      end
    end
  end
  object Panel10: TPanel
    Left = 519
    Top = 159
    Width = 498
    Height = 137
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object Label1: TLabel
      Left = 191
      Top = 6
      Width = 146
      Height = 16
      Caption = #1061#1040#1056#1040#1050#1058#1045#1056#1048#1057#1058#1048#1050#1048' '#1040#1059': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabeledEdit49: TLabeledEdit
      Left = 16
      Top = 42
      Width = 113
      Height = 21
      EditLabel.Width = 88
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1077#1084#1087' '#1089#1090#1088#1077#1083#1100#1073#1099', '#1089
      TabOrder = 0
      Text = '2'
    end
    object LabeledEdit51: TLabeledEdit
      Left = 168
      Top = 42
      Width = 121
      Height = 21
      EditLabel.Width = 111
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1077#1093#1085' '#1088#1072#1089#1089#1077#1103#1085#1080#1077', '#1084#1088#1072#1076
      ReadOnly = True
      TabOrder = 1
      Text = '1'
    end
    object LabeledEdit52: TLabeledEdit
      Left = 344
      Top = 42
      Width = 113
      Height = 21
      EditLabel.Width = 143
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1095#1085' '#1087#1088#1080#1074#1086#1076#1072' '#1087#1086' '#1091#1075#1083#1091', '#1084#1088#1072#1076
      TabOrder = 2
      Text = '0'
    end
    object LabeledEdit53: TLabeledEdit
      Left = 16
      Top = 91
      Width = 121
      Height = 21
      EditLabel.Width = 157
      EditLabel.Height = 16
      EditLabel.Caption = #1058#1086#1095#1085' '#1087#1088#1080#1074' '#1087#1086' '#1089#1082#1086#1088', '#1084#1088#1072#1076'/'#1089
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Tahoma'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '0'
    end
    object LabeledEdit50: TLabeledEdit
      Left = 177
      Top = 88
      Width = 112
      Height = 21
      EditLabel.Width = 105
      EditLabel.Height = 13
      EditLabel.Caption = #1057#1050#1047' '#1079#1072#1076#1077#1088#1078#1082#1080'  '#1040#1059', c'
      TabOrder = 4
      Text = '0'
    end
    object LabeledEdit2: TLabeledEdit
      Left = 344
      Top = 90
      Width = 113
      Height = 21
      EditLabel.Width = 40
      EditLabel.Height = 13
      EditLabel.Caption = #1050#1040#1051#1048#1041#1056
      ReadOnly = True
      TabOrder = 5
    end
  end
  object Panel7: TPanel
    Left = 0
    Top = 152
    Width = 513
    Height = 145
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object Label8: TLabel
      Left = 152
      Top = 6
      Width = 120
      Height = 16
      Caption = #1044#1040#1053#1053#1067#1045' '#1055#1045#1051#1045#1053#1043#1040
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 10
      Top = 46
      Width = 99
      Height = 16
      Caption = '5. '#1044#1040#1051#1068#1053#1054#1057#1058#1068' :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LabeledEdit25: TLabeledEdit
      Left = 12
      Top = 109
      Width = 121
      Height = 21
      EditLabel.Width = 85
      EditLabel.Height = 16
      EditLabel.Caption = #1057#1082#1086#1088#1086#1089#1090#1100', '#1084'./'#1089
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Tahoma'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '10'
    end
    object LabeledEdit27: TLabeledEdit
      Left = 188
      Top = 109
      Width = 121
      Height = 21
      EditLabel.Width = 95
      EditLabel.Height = 16
      EditLabel.Caption = #1057#1050#1047' '#1096#1091#1084#1072', '#1084'/'#1089'/'#1089
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Tahoma'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = '0,01'
    end
    object LabeledEdit29: TLabeledEdit
      Left = 374
      Top = 46
      Width = 121
      Height = 21
      EditLabel.Width = 60
      EditLabel.Height = 16
      EditLabel.Caption = #1050#1091#1088#1089', '#1075#1088#1072#1076
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Tahoma'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = '180'
    end
    object LabeledEdit23: TLabeledEdit
      Left = 220
      Top = 46
      Width = 121
      Height = 21
      EditLabel.Width = 75
      EditLabel.Height = 16
      EditLabel.Caption = #1055#1077#1083#1077#1085#1075', '#1075#1088#1072#1076
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Tahoma'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '0'
    end
    object LabeledEdit28: TLabeledEdit
      Left = 374
      Top = 107
      Width = 121
      Height = 21
      EditLabel.Width = 64
      EditLabel.Height = 16
      EditLabel.Caption = #1069#1055#1056' '#1094#1077#1083#1080': '
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Tahoma'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      Text = '50'
    end
    object ComboBox5: TComboBox
      Left = 115
      Top = 46
      Width = 90
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      Text = '18000'
      Items.Strings = (
        '7000'
        '10000'
        '12000'
        '14000'
        '16000'
        '18000'
        '20000')
    end
  end
  object Button1: TButton
    Left = 727
    Top = 397
    Width = 154
    Height = 25
    Caption = #1047#1040#1050#1056#1067#1058#1068' '#1060#1054#1056#1052#1059
    TabOrder = 4
    OnClick = Button1Click
  end
  object LabeledEdit10: TLabeledEdit
    Left = 348
    Top = 67
    Width = 106
    Height = 21
    EditLabel.Width = 105
    EditLabel.Height = 13
    EditLabel.Caption = #1052#1072#1082#1089'. '#1082'-'#1074#1086' '#1089#1085#1072#1088#1103#1076#1086#1074
    NumbersOnly = True
    TabOrder = 5
    Text = '76'
  end
  object Panel5: TPanel
    Left = 0
    Top = 557
    Width = 648
    Height = 93
    Hint = #1044#1051#1071' '#1043#1054#1057#1053#1048#1048'...'
    Color = clMoneyGreen
    ParentBackground = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    object Label11: TLabel
      Left = 38
      Top = 31
      Width = 215
      Height = 16
      AutoSize = False
      Caption = #1055#1059#1058#1068' '#1050' '#1060#1040#1049#1051#1059' '#1057' '#1048#1044' '#1055#1054' '#1058#1040#1056#1040#1053#1059
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Button2: TButton
      Left = 188
      Top = 53
      Width = 134
      Height = 25
      Hint = #1050#1086#1088#1088#1077#1083#1103#1094#1080#1083#1085#1085#1099#1077' '#1084#1072#1090#1088#1080#1094#1099'  '#1085#1072' '#1089#1077#1090#1082#1077' '
      Caption = #1057#1054#1047#1044#1040#1058#1068' CSV '#1060#1040#1049#1051' '#1057' '#1048#1044
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button5: TButton
      Left = 553
      Top = 21
      Width = 27
      Height = 25
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = Button5Click
    end
    object Edit1: TEdit
      Left = 271
      Top = 23
      Width = 254
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 520
    Top = 144
  end
  object SaveDialog1: TSaveDialog
    Left = 1020
    Top = 305
  end
end
