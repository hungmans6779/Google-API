; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSEEING
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sample9.h"

ClassCount=4
Class1=CSample9App
Class2=CSample9Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SAMPLE9_DIALOG
Class4=CSEEING
Resource4=IDD_SEEING

[CLS:CSample9App]
Type=0
HeaderFile=sample9.h
ImplementationFile=sample9.cpp
Filter=N

[CLS:CSample9Dlg]
Type=0
HeaderFile=sample9Dlg.h
ImplementationFile=sample9Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSample9Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=sample9Dlg.h
ImplementationFile=sample9Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SAMPLE9_DIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDC_START,button,1342242816
Control2=IDC_DYNAMIC,button,1342242816
Control3=IDC_EXIT,button,1342242816

[DLG:IDD_SEEING]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SEEING,static,1342308608

[CLS:CSEEING]
Type=0
HeaderFile=SEEING.h
ImplementationFile=SEEING.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SEEING
VirtualFilter=dWC

