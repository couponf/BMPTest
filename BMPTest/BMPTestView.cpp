
// BMPTestView.cpp: CBMPTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BMPTest.h"
#endif

#include "BMPTestDoc.h"
#include "BMPTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBMPTestView

IMPLEMENT_DYNCREATE(CBMPTestView, CView)

BEGIN_MESSAGE_MAP(CBMPTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBMPTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBMPTestView 构造/析构

CBMPTestView::CBMPTestView()
{
	// TODO: 在此处添加构造代码

}

CBMPTestView::~CBMPTestView()
{
}

BOOL CBMPTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBMPTestView 绘图

void CBMPTestView::OnDraw(CDC* /*pDC*/)
{
	CBMPTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CBMPTestView 打印


void CBMPTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBMPTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBMPTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBMPTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBMPTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBMPTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBMPTestView 诊断

#ifdef _DEBUG
void CBMPTestView::AssertValid() const
{
	CView::AssertValid();
}

void CBMPTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBMPTestDoc* CBMPTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBMPTestDoc)));
	return (CBMPTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CBMPTestView 消息处理程序
