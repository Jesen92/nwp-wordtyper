
// MFCApplication1Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <list>
#include <cstring>
#include <vector>

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedGlavnitext();
	afx_msg void OnStnClickedBodovi();
	afx_msg void OnStnClickedTimer();

	std::vector<std::string> list_words;

	bool game;
	int score;
	double duration;

	CString current_word;
	CString sound_path;
//	char IDC_SLUSAC;


	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	BOOL PreTranslateMessage(MSG * pMsg);
	afx_msg void OnClose();
	void new_game();
	void new_word();
	void change_text();
	void set_score();
	void game_over();
	void timer();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedHbutton();

};
