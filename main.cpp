
// lab1View.cpp: Clab1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "lab1.h"
#endif

#include "lab1Doc.h"
#include "lab1View.h"

#include "pch.h"
#include "lab1.h"
#include "lab1View.h"
#include <ctime>
#include <cstdlib>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab1View

IMPLEMENT_DYNCREATE(Clab1View, CView)

BEGIN_MESSAGE_MAP(Clab1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()



// Clab1View 생성/소멸

Clab1View::Clab1View() noexcept  //윈도우 창이 열리면서초기 셋팅을할떄 실행 되는 코드 이다
{
	SetTimer(1, 1000, NULL); // 이 줄을 추가합니다.
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

Clab1View::~Clab1View() //윈도우 창이 종료가 되면서 작업 시키는 코드를 작성하는 곳이다
{
	KillTimer(1);
}

BOOL Clab1View::PreCreateWindow(CREATESTRUCT& cs)  //윈도우창이 열리기전 실행 되는 코드 부분이며 도구창과 윈도우 창의 설정을 하는 코드이다
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Clab1View 그리기

void Clab1View::OnDraw(CDC* pDC) // 주 코드가 실핼 되는 곳이며 우리가 만드는 것응 ui적인 요소이기 때문에 ondraw로 클래스를 만든것이다.
{
	Clab1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	DrawRandomRectangle(pDC);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Clab1View 인쇄

BOOL Clab1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Clab1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Clab1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Clab1View 진단

#ifdef _DEBUG
void Clab1View::AssertValid() const
{
	CView::AssertValid();
}

void Clab1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab1Doc* Clab1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab1Doc)));
	return (Clab1Doc*)m_pDocument;
}
#endif //_DEBUG
// Clab1View 메시지 처리기
void Clab1View::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)  // 타이머 ID 확인
	{
		// 화면을 다시 그리기 위해 Invalidate() 호출 (WM_PAINT 메시지 트리거)
		Invalidate();  // 화면을 무효화해서 OnDraw 호출
	}

	CView::OnTimer(nIDEvent);  // 기본 처리
}

void Clab1View::DrawRandomRectangle(CDC* pDC)
{
	srand((unsigned)time(NULL)); // 랜덤 시드 설정
	CRect clientRect; // 클라이언트 영역 크기를 저장할 객체
	GetClientRect(&clientRect); // 클라이언트 영역 크기 가져오기

	// 랜덤한 위치와 크기의 사각형 좌표 생성
	int left = rand() % clientRect.Width();
	int top = rand() % clientRect.Height();
	int right = left + (rand() % 100 + 20);  // 최소 20에서 최대 120의 폭
	int bottom = top + (rand() % 100 + 20);  // 최소 20에서 최대 120의 높이

	// 사각형 그리기
	pDC->Rectangle(left, top, right, bottom);
}
