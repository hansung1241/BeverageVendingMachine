
// cyhDlg.h: 헤더 파일
//

#pragma once


// CcyhDlg 대화 상자
class CcyhDlg : public CDialogEx
{
// 생성입니다.
public:
	CcyhDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CYH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	CString m_resultmoney; // 돈이 입력될 때 변하는 변수
	CString m_resulttext; // 돈이 얼마가 입력되고 무슨 음료수를 뽑았는지 알려주는 변수

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1(); // 5000원 버튼
	afx_msg void OnBnClickedButton2(); // 1000원 버튼
	afx_msg void OnBnClickedButton3(); // 500원 버튼
	afx_msg void OnBnClickedButton4(); // 100원 버튼
	afx_msg void OnBnClickedButton5(); // 파워에이드 버튼
	afx_msg void OnBnClickedButton6(); // 제로 콜라 버튼
	afx_msg void OnBnClickedButton7(); // 게토레이 버튼
	afx_msg void OnBnClickedButton8(); // 삼다수 버튼
	afx_msg void OnBnClickedButton9(); // 반환 버튼
};
