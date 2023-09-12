
// CaculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Caculator.h"
#include "CaculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
double f(double &point)
{
	double sum = 0.1;
	if (point >= 1)
	{
		point++;
	}
	if (point > 0)
	{
		return pow(sum, point - 1);
	}
	else
		return pow(sum, 0);
}
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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


// CCaculatorDlg 对话框



CCaculatorDlg::CCaculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CACULATOR_DIALOG, pParent)
	, m_editl(0)
{
	tempvalue = 0;
	result = 0;
	sort = 0;
	append = 0;
	point = 0;
	ab = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editl);
}

BEGIN_MESSAGE_MAP(CCaculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONplus, &CCaculatorDlg::OnBnClickedButtonplus)
	ON_BN_CLICKED(IDC_BUTTON7, &CCaculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &CCaculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCaculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCaculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCaculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCaculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCaculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CCaculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTONzero, &CCaculatorDlg::OnBnClickedButtonzero)
	ON_BN_CLICKED(IDC_BUTTON9, &CCaculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTONonequal, &CCaculatorDlg::OnBnClickedButtononequal)
	ON_BN_CLICKED(IDC_BUTTONclean, &CCaculatorDlg::OnBnClickedButtonclean)
	ON_BN_CLICKED(IDC_BUTTONminus, &CCaculatorDlg::OnBnClickedButtonminus)
	ON_BN_CLICKED(IDC_BUTTONmulti, &CCaculatorDlg::OnBnClickedButtonmulti)
	ON_BN_CLICKED(IDC_BUTTONdid, &CCaculatorDlg::OnBnClickedButtondid)
	ON_BN_CLICKED(IDC_sin, &CCaculatorDlg::OnBnClickedsin)
	ON_BN_CLICKED(IDC_cos, &CCaculatorDlg::OnBnClickedcos)
	ON_BN_CLICKED(IDC_tan, &CCaculatorDlg::OnBnClickedtan)
	ON_BN_CLICKED(IDC_log10, &CCaculatorDlg::OnBnClickedlog10)
	ON_EN_CHANGE(IDC_EDIT1, &CCaculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTONpoint, &CCaculatorDlg::OnBnClickedButtonpoint)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CCaculatorDlg::OnDtnDatetimechangeDatetimepicker1)
	ON_BN_CLICKED(IDC_BUTTON14, &CCaculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON1pingfang, &CCaculatorDlg::OnBnClickedButton1pingfang)
	ON_BN_CLICKED(IDC_BUTTONkaifang, &CCaculatorDlg::OnBnClickedButtonkaifang)
END_MESSAGE_MAP()


// CCaculatorDlg 消息处理程序

BOOL CCaculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCaculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCaculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCaculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCaculatorDlg::OnBnClickedButtonplus()
{

	switch (sort)
	{
	case 1:result = result + tempvalue; break;
	case 2:result = tempvalue - result; break;
	case 3:result = result * tempvalue; break;
	case 4: {
		if (result == 0)
			MessageBox(_T("0不能做除数"));
		else
				result = tempvalue / result; break;
			}
	}
	sort = 1;
	tempvalue = result;
	m_editl = result;
	append = 1;
	point = 0;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

void CCaculatorDlg::OnBnClickedButton7()
{
	if (ab == 1)
	{
		int temp = result;
		for (int i = 0; i < 7-1; i++)
		{
			result = temp* result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 7;
		else
			result = result + f(point) * 7;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
}

void CCaculatorDlg::OnBnClickedButton1()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 1-1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 1;
		else
			result = result + f(point) * 1;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}

void CCaculatorDlg::OnBnClickedButton2()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 2 - 1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 2;
		else
			result = result + f(point) * 2;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton3()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 3 - 1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 3;
		else
			result = result + f(point) * 3;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton4()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 4 - 1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 4;
		else
			result = result + f(point) * 4;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton5()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 5 - 1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 5;
		else
			result = result + f(point) * 5;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton6()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 6 - 1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 6;
		else
			result = result + f(point) * 6;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton8()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 8 - 1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 8;
		else
			result = result + f(point) * 8;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButtonzero()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		result = 1;
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 0;
		else
			result = result + f(point) * 0;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton9()
{
	if (append == 1)result = 0;
	if (ab == 1)
	{
		double temp = result;
		for (int i = 0; i < 9 - 1; i++)
		{
			result = temp * result;
		}
		m_editl = result;
		append = 0;
		ab = 0;
		UpdateData(FALSE);
	}
	else if (ab != 1) {
		if (point == 0)
			result = result * 10 + 9;
		else
			result = result + f(point) * 9;
		m_editl = result;
		append = 0;
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButtononequal()
{
	switch (sort)
	{
	case 1:result = result + tempvalue; break;
	case 2:result = tempvalue - result; break;
	case 3:result = result * tempvalue; break;
	case 4: {
		if (result == 0)
			MessageBox(_T("0不能做除数"));
		else
			result = tempvalue / result; break;
	}
	}
	sort = 0;
	m_editl = result;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButtonclean()
{
	tempvalue = 0;
	result = 0;
	m_editl = 0.0;
	point = 0;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButtonminus()
{
	switch (sort)
	{
	case 1:result = result + tempvalue; break;
	case 2:result = tempvalue - result; break;
	case 3:result = result * tempvalue; break;
	case 4: {
		if (result == 0)
			MessageBox(_T("0不能做除数"));
		else
			result = tempvalue / result; break;
	}
	}
	sort = 2;
	tempvalue = result;
	m_editl = result;
	append = 1;
	point = 0;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButtonmulti()
{
	switch (sort)
	{
	case 1:result = result + tempvalue; break;
	case 2:result = tempvalue - result; break;
	case 3:result = result * tempvalue; break;
	case 4: {
		if (result == 0)
			MessageBox(_T("0不能做除数"));
		else
			result = tempvalue / result; break;
	}
	}
	sort = 3;
	tempvalue = result;
	m_editl = result;
	append = 1;
	point = 0;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButtondid()
{
	switch (sort)
	{
	case 1:result = result + tempvalue; break;
	case 2:result = tempvalue - result; break;
	case 3:result = result * tempvalue; break;
	case 4: {
		if (result == 0)
			MessageBox(_T("0不能做除数"));
		else
			result = tempvalue / result; break;
	}
	}
	sort = 4;
	tempvalue = result;
	m_editl = result;
	append = 1;
	point = 0;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedsin()
{
	m_editl = sin(result);
	result = sin(result);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedcos()
{
	m_editl = cos(result);
	result = cos(result);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedtan()
{
	m_editl = tan(result);
	result = tan(result);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedlog10()
{
	m_editl = log10(result);
	result = tan(result);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CCaculatorDlg::OnBnClickedButtonpoint()
{
	point = 1;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnDtnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}




void CCaculatorDlg::OnBnClickedButton14()
{
	if (point > 0)
	{
		int temp = result * pow(10,point-1);
		temp =temp/ 10;
		point--;
		result = temp * pow(0.1, point-1);
		m_editl = result;
		if (point == 1)point = 0;
		UpdateData(FALSE);
		return;
	}
	 result = (int)(result / 10);
	m_editl = result;
	UpdateData(FALSE);

	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton15()
{

	// TODO: 在此添加控件通知处理程序代码
}


void CCaculatorDlg::OnBnClickedButton1pingfang()
{
	ab = 1;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}



void CCaculatorDlg::OnBnClickedButtonkaifang()
{
	result = sqrt(result);
	m_editl = result;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}
