
// CaculatorDlg.h: 头文件
//

#pragma once
#include<math.h>
// CCaculatorDlg 对话框
class CCaculatorDlg : public CDialogEx
{
// 构造
public:
	CCaculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数
	double tempvalue;
	double result;
	int sort;
	int append;
	double point;
	int ab;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CACULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton1();
	double m_editl;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButtonzero();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtononequal();
	afx_msg void OnBnClickedButtonclean();
	afx_msg void OnBnClickedButtonminus();
	afx_msg void OnBnClickedButtonmulti();
	afx_msg void OnBnClickedButtondid();
	afx_msg void OnBnClickedsin();
	afx_msg void OnBnClickedcos();
	afx_msg void OnBnClickedtan();
	afx_msg void OnBnClickedlog10();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonpoint();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton1pingfang();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButtonkaifang();
};
