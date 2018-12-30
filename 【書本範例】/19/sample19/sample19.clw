; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNEWS
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sample19.h"
LastPage=0

ClassCount=9
Class1=CCSTATION
Class2=CMainFrame
Class3=CNEWS
Class4=CSample19App
Class5=CAboutDlg
Class6=CSample19Doc
Class7=CSample19View

ResourceCount=8
Resource1=IDD_DIALOG2
Resource2=IDD_DIALOG3
Resource3=IDD_DIALOG4
Resource4=IDD_ABOUTBOX
Resource5=IDR_MAINFRAME
Class8=CSEARCHDLG
Resource6=IDD_DIALOG1
Class9=CSEARCHNEWS
Resource7=IDR_MAINFRAME (Chinese (P.R.C.))
Resource8=IDD_DIALOG5

[CLS:CCSTATION]
Type=0
BaseClass=CDialog
HeaderFile=CSTATION.h
ImplementationFile=CSTATION.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CNEWS]
Type=0
BaseClass=CDialog
HeaderFile=NEWS.h
ImplementationFile=NEWS.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CSample19App]
Type=0
BaseClass=CWinApp
HeaderFile=sample19.h
ImplementationFile=sample19.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=sample19.cpp
ImplementationFile=sample19.cpp
LastObject=CAboutDlg

[CLS:CSample19Doc]
Type=0
BaseClass=CDocument
HeaderFile=sample19Doc.h
ImplementationFile=sample19Doc.cpp

[CLS:CSample19View]
Type=0
BaseClass=CView
HeaderFile=sample19View.h
ImplementationFile=sample19View.cpp
Filter=C
VirtualFilter=VWC
LastObject=IDC_LIST1

[DLG:IDD_DIALOG2]
Type=1
Class=?
ControlCount=5
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_EDIT1,edit,1350631428
Control3=IDOK,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG3]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631428
Control3=IDC_STADIUM,static,1342308608
Control4=IDC_TIME,static,1342308608

[DLG:IDD_ABOUTBOX]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=6
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_VIEW,button,1342242816
Control6=IDC_GO,button,1342242816

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDC_START
Command18=IDC_REPORTS
Command19=IDC_STATION
Command20=IDC_SEARCH
Command21=IDC_EXIT
Command22=IDM_LEFT
Command23=IDM_RIGHT
Command24=IDM_UP
Command25=IDM_DOWN
Command26=IDM_LARGE
Command27=IDM_SMALL
CommandCount=27

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=IDM_NULL1
Command10=IDM_NULL2
Command11=IDM_NULL3
Command12=IDM_NULL4
Command13=IDM_LEFT
Command14=IDM_RIGHT
Command15=IDM_UP
Command16=IDM_DOWN
Command17=IDM_LARGE
Command18=IDM_SMALL
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_DIALOG4]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344339970
Control4=IDC_STATIC,static,1342308352

[CLS:CSEARCHDLG]
Type=0
HeaderFile=SEARCHDLG.h
ImplementationFile=SEARCHDLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EXIT

[DLG:IDD_DIALOG5]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SEARCH_STADIUM,static,1342308608
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BEGINTIME,static,1342308608
Control7=IDC_ENDTIME,static,1342308608
Control8=IDC_STATIC,static,1342308352

[CLS:CSEARCHNEWS]
Type=0
HeaderFile=SEARCHNEWS.h
ImplementationFile=SEARCHNEWS.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[TB:IDR_MAINFRAME (Chinese (P.R.C.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=IDM_NULL1
Command10=IDM_NULL2
Command11=IDM_NULL3
Command12=IDM_NULL4
Command13=IDM_LEFT
Command14=IDM_RIGHT
Command15=IDM_UP
Command16=IDM_DOWN
Command17=IDM_LARGE
Command18=IDM_SMALL
CommandCount=18

[ACL:IDR_MAINFRAME (Chinese (P.R.C.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

