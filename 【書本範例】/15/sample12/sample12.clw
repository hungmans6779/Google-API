; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSample12Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sample12.h"

ClassCount=4
Class1=CSample12App
Class2=CSample12Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SAMPLE12_DIALOG
Class4=CSEARCH
Resource4=IDD_SEARCH

[CLS:CSample12App]
Type=0
HeaderFile=sample12.h
ImplementationFile=sample12.cpp
Filter=N

[CLS:CSample12Dlg]
Type=0
HeaderFile=sample12Dlg.h
ImplementationFile=sample12Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=sample12Dlg.h
ImplementationFile=sample12Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SAMPLE12_DIALOG]
Type=1
Class=?
ControlCount=6
Control1=IDC_START,button,1342242816
Control2=IDC_SEARCH,button,1342242816
Control3=IDC_EXIT,button,1342242816
Control4=IDC_LIST1,listbox,1352728835
Control5=IDC_SHOW,button,1342242816
Control6=IDC_SHOW2,button,1342251008

[DLG:IDD_SEARCH]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_RADIO1,button,1342308361
Control7=IDC_RADIO2,button,1342177289
Control8=IDC_RADIO3,button,1342177289
Control9=IDC_RADIO4,button,1342177289

[CLS:CSEARCH]
Type=0
HeaderFile=SEARCH.h
ImplementationFile=SEARCH.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

