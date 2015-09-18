// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>
#include "words.h"
#include <chrono>
#include <future>
#include <ctime>
#include <Windows.h>
#include <mmsystem.h>
#include "resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg dialog




CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  IDC_SLUSAC = 0;


}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_GLAVNITEXT, &CMFCApplication1Dlg::OnStnClickedGlavnitext)
	ON_STN_CLICKED(IDC_BODOVI, &CMFCApplication1Dlg::OnStnClickedBodovi)
	ON_STN_CLICKED(IDC_TIMER, &CMFCApplication1Dlg::OnStnClickedTimer)
	ON_WM_KEYUP()
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()

	ON_WM_TIMER()

END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	game = false;

	CFont *font = new CFont();
	CFont *l_font = new CFont();
	font->CreatePointFont(280, _T("Traditional Arabic"));

	CWnd *text = GetDlgItem(IDC_GLAVNITEXT);
	text->SetFont(font, TRUE);


	l_font->CreatePointFont(150, _T("Traditional Arabic"));

	CWnd *points = GetDlgItem(IDC_BODOVI);
	points->SetFont(l_font, TRUE);

	CWnd *_time = GetDlgItem(IDC_TIMER);
	_time->SetFont(l_font, TRUE);

	CWnd *_help = GetDlgItem(IDC_INST);
	_help->SetFont(l_font, TRUE);



	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnStnClickedGlavnitext()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnStnClickedBodovi()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnStnClickedTimer()
{
	// TODO: Add your control notification handler code here
}



void CMFCApplication1Dlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox(_T("Pritisnuta je tipka"), _T("Nesto"));
	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);


}


void CMFCApplication1Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);

}

BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg) {
	CWnd* temp_time = GetDlgItem(IDC_TIMER);
	CString t_time;

	switch (pMsg->message)
	{
		

		case WM_TIMER:
			if (game == true) {
				duration -= 0.1;
				if (duration < 0)
					game_over();
				t_time.Format(_T("%.1f"), duration);
				temp_time->SetWindowText(LPCTSTR(t_time));
				return false;
			}

		case WM_KEYUP:
			if (pMsg->wParam == VK_RETURN) {
				new_game();
				CWnd *_help = GetDlgItem(IDC_INST);
				_help->SetWindowText(_T(""));
			}
			else if (pMsg->wParam == VK_ESCAPE) {
				ExitProcess(0);
				EndDialog(0);

			}
			else if (GetAsyncKeyState(current_word[0]) && game == true) {

				if (current_word.Mid(1).IsEmpty()) {

					set_score();
					new_word();
				}

				else {

					PlaySound(MAKEINTRESOURCE(IDR_WAVE4), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
					current_word = current_word.Mid(1);
					change_text();
				}
			}
			else if (GetAsyncKeyState('H') && game == false)
			{
				res.LoadString(IDS_M_HELP);
				res2.LoadString(IDS_M_HELP_T);
				MessageBox(res, res2);
			}
			else if (game == true)
				game_over();

			return true;
	}

}


void CMFCApplication1Dlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnClose();
}

void CMFCApplication1Dlg::new_game() {

	game = false;
	set_score();
	game = true;
	new_word();
	//std::async(std::launch::async, &CMFCApplication1Dlg::timer, this);
	srand(time(NULL));
	timer();
}

void CMFCApplication1Dlg::new_word() {


	int i = 0;

	i = rand() % 200;

	if (score <100) {
		current_word = words.four[i];
	}

	else if (score >= 100 && score <200) {
		current_word = words.five[i];
	}

	else if (score >= 200 && score <300) {
		current_word = words.six[i];
	}

	else if (score >= 300 && score <400) {
		current_word = words.seven[i];
	}

	else if (score >= 400 && score <500) {
		current_word = words.eight[i];
	}

	else if (score >= 500 && score <600) {
		current_word = words.nine[i];
	}

	else if (score >= 600) {
		current_word = words.ten[i];
	}

	change_text();
	timer();

}

void CMFCApplication1Dlg::change_text() {
	CWnd *text = GetDlgItem(IDC_GLAVNITEXT);
	text->SetWindowText(LPCTSTR(current_word));
}

void CMFCApplication1Dlg::set_score() {
	if(game == false){
		score = 0;
	}
	else {
		score += 10;
		if (score % 100 == 0) {

			PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
		}
		else {
			PlaySound(MAKEINTRESOURCE(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
		}
	}

	CWnd *score_text = GetDlgItem(IDC_BODOVI);
	CString score_temp;
	score_temp.Format(_T("%d"), score);
	score_text->SetWindowText(LPCTSTR(score_temp));
}

void CMFCApplication1Dlg::game_over() {

	PlaySound(MAKEINTRESOURCE(IDR_WAVE2), GetModuleHandle(NULL),  SND_RESOURCE | SND_ASYNC);

	CWnd *_help = GetDlgItem(IDC_INST);
	res.LoadString(IDS_INST);
	_help->SetWindowText(res);

	CWnd *_time = GetDlgItem(IDC_TIMER);
	res.LoadString(IDS_TIMER);
	_time->SetWindowText(res);

	game = false;
	res.LoadString(IDS_GAMEOVER);
	res2.LoadString(IDS_GAMEOVER_T);
	MessageBox(res,res2);
}

void CMFCApplication1Dlg::timer() {
	SetTimer(0, 100, NULL);
	CWnd* temp_time = GetDlgItem(IDC_TIMER);
	CString t_time;
	duration = 3;
	t_time.Format(_T("%.1f"), duration);
	temp_time->SetWindowText(LPCTSTR(t_time));


}

void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedHbutton()
{
	// TODO: Add your control notification handler code here
	//MessageBox(_T("Nesto"), _T("Nesto"));
}
