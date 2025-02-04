
// cyhDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "cyh.h"
#include "cyhDlg.h"
#include "afxdialogex.h"

#include <CString>

#define MENU1 800 // 파워에이드 가격
#define MENU2 1100 // 제로 콜라 가격
#define MENU3 900 // 게토레이 가격
#define MENU4 700 // 삼다수 가격

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcyhDlg 대화 상자



CcyhDlg::CcyhDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CYH_DIALOG, pParent)
	, m_resulttext(_T(""))
	, m_resultmoney(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcyhDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_resultmoney);
	DDX_Text(pDX, IDC_TEXT, m_resulttext);
}

BEGIN_MESSAGE_MAP(CcyhDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcyhDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcyhDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcyhDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcyhDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcyhDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcyhDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcyhDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcyhDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcyhDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CcyhDlg 메시지 처리기

BOOL CcyhDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CcyhDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CcyhDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CcyhDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcyhDlg::OnBnClickedButton1()
{
	UpdateData(true);

	int beforeMoney = _ttoi(m_resultmoney);			// 돈은 정수형이기 때문에 5000원이 숫자로 바뀌어야한다.
	int afterMoney = beforeMoney + 5000;			// 돈 넣기 전의 상태에 5000원을 더하고 돈 넣은 후 상태에 대입한다.
	m_resultmoney.Format(_T("%d"), afterMoney);		// 정수형의 값을 CString 으로 바꿔준다.
	m_resulttext = _T("5000원이 투입되었습니다.");	// static message 의 변수에 결과 메세지를 출력한다.

	UpdateData(false);
}


void CcyhDlg::OnBnClickedButton2()
{
	UpdateData(true);

	int beforeMoney = _ttoi(m_resultmoney);			// 돈은 정수형이기 때문에 1000원이 숫자로 바뀌어야한다.
	int afterMoney = beforeMoney + 1000;			// 돈 넣기 전의 상태에 1000원을 더하고 돈 넣은 후 상태에 대입한다.
	m_resultmoney.Format(_T("%d"), afterMoney);		// 정수형의 값을 CString 으로 바꿔준다.
	m_resulttext = _T("1000원이 투입되었습니다.");	// static message 의 변수에 결과 메세지를 출력한다.

	UpdateData(false);
}


void CcyhDlg::OnBnClickedButton3()
{
	UpdateData(true);

	int beforeMoney = _ttoi(m_resultmoney);			// 돈은 정수형이기 때문에 500원이 숫자로 바뀌어야한다.
	int afterMoney = beforeMoney + 500;			// 돈 넣기 전의 상태에 500원을 더하고 돈 넣은 후 상태에 대입한다.
	m_resultmoney.Format(_T("%d"), afterMoney);		// 정수형의 값을 CString 으로 바꿔준다.
	m_resulttext = _T("500원이 투입되었습니다.");	// static message 의 변수에 결과 메세지를 출력한다.

	UpdateData(false);
}


void CcyhDlg::OnBnClickedButton4()
{
	UpdateData(true);

	int beforeMoney = _ttoi(m_resultmoney);			// 돈은 정수형이기 때문에 100원이 숫자로 바뀌어야한다.
	int afterMoney = beforeMoney + 100;			// 돈 넣기 전의 상태에 100원을 더하고 돈 넣은 후 상태에 대입한다.
	m_resultmoney.Format(_T("%d"), afterMoney);		// 정수형의 값을 CString 으로 바꿔준다.
	m_resulttext = _T("100원이 투입되었습니다.");	// static message 의 변수에 결과 메세지를 출력한다.

	UpdateData(false);
}


void CcyhDlg::OnBnClickedButton5()
{
	UpdateData(true); // 대화 상자 컨트롤의 데이터를 변수에 업데이트합니다.

	int beforeMoney = _ttoi(m_resultmoney); // m_resultmoney 문자열을 정수로 변환합니다.

	if (beforeMoney >= MENU1) // beforeMoney가 MENU1보다 크거나 같은지 확인합니다.
	{
		int afterMoney = beforeMoney - 800; // beforeMoney에서 800을 뺀 값을 afterMoney에 저장합니다.
		m_resultmoney.Format(_T("%d"), afterMoney); // afterMoney 값을 문자열로 변환하여 m_resultmoney에 저장합니다.
		m_resulttext = _T("파워에이드가 나왔습니다."); // m_resulttext에 메시지를 저장합니다.
	}
	else
	{
		m_resulttext = _T("돈이 부족합니다."); // m_resulttext에 메시지를 저장합니다.
	}

	UpdateData(false); // 변수의 값을 대화 상자 컨트롤에 업데이트합니다.
}


void CcyhDlg::OnBnClickedButton6()
{
	UpdateData(true); // 대화 상자 컨트롤의 데이터를 변수에 업데이트합니다.

	int beforeMoney = _ttoi(m_resultmoney); // m_resultmoney 문자열을 정수로 변환합니다.

	if (beforeMoney >= MENU2) // beforeMoney가 MENU1보다 크거나 같은지 확인합니다.
	{
		int afterMoney = beforeMoney - 1100; // beforeMoney에서 1100을 뺀 값을 afterMoney에 저장합니다.
		m_resultmoney.Format(_T("%d"), afterMoney); // afterMoney 값을 문자열로 변환하여 m_resultmoney에 저장합니다.
		m_resulttext = _T("제로 콜라가 나왔습니다."); // m_resulttext에 메시지를 저장합니다.
	}
	else
	{
		m_resulttext = _T("돈이 부족합니다."); // m_resulttext에 메시지를 저장합니다.
	}

	UpdateData(false); // 변수의 값을 대화 상자 컨트롤에 업데이트합니다.
}


void CcyhDlg::OnBnClickedButton7()
{
	UpdateData(true); // 대화 상자 컨트롤의 데이터를 변수에 업데이트합니다.

	int beforeMoney = _ttoi(m_resultmoney); // m_resultmoney 문자열을 정수로 변환합니다.

	if (beforeMoney >= MENU3) // beforeMoney가 MENU1보다 크거나 같은지 확인합니다.
	{
		int afterMoney = beforeMoney - 900; // beforeMoney에서 900을 뺀 값을 afterMoney에 저장합니다.
		m_resultmoney.Format(_T("%d"), afterMoney); // afterMoney 값을 문자열로 변환하여 m_resultmoney에 저장합니다.
		m_resulttext = _T("게토레이가 나왔습니다."); // m_resulttext에 메시지를 저장합니다.
	}
	else
	{
		m_resulttext = _T("돈이 부족합니다."); // m_resulttext에 메시지를 저장합니다.
	}

	UpdateData(false); // 변수의 값을 대화 상자 컨트롤에 업데이트합니다.
}


void CcyhDlg::OnBnClickedButton8()
{
	UpdateData(true); // 대화 상자 컨트롤의 데이터를 변수에 업데이트합니다.

	int beforeMoney = _ttoi(m_resultmoney); // m_resultmoney 문자열을 정수로 변환합니다.

	if (beforeMoney >= MENU4) // beforeMoney가 MENU1보다 크거나 같은지 확인합니다.
	{
		int afterMoney = beforeMoney - 700; // beforeMoney에서 700을 뺀 값을 afterMoney에 저장합니다.
		m_resultmoney.Format(_T("%d"), afterMoney); // afterMoney 값을 문자열로 변환하여 m_resultmoney에 저장합니다.
		m_resulttext = _T("삼다수가 나왔습니다."); // m_resulttext에 메시지를 저장합니다.
	}
	else
	{
		m_resulttext = _T("돈이 부족합니다."); // m_resulttext에 메시지를 저장합니다.
	}

	UpdateData(false); // 변수의 값을 대화 상자 컨트롤에 업데이트합니다.
}


void CcyhDlg::OnBnClickedButton9()
{
	UpdateData(true); // 대화 상자 컨트롤의 데이터를 변수에 업데이트합니다.

	m_resultmoney = _T("0"); // m_resultmoney에 0을 대입하여 초기화합니다.
	m_resulttext = _T("돈이 반환되었습니다."); // m_resulttext에 메시지를 저장합니다.

	UpdateData(false); // 변수의 값을 대화 상자 컨트롤에 업데이트합니다.
}
