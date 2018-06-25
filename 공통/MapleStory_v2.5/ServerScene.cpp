#include "stdafx.h"
#include "ServerScene.h"

ServerScene::~ServerScene()
{
	
}

void ServerScene::Init(HWND hWnd)
{

	UI_MGR->AddImage("ServerMain", L"ServerMain", { 0,0,1200,800 });


	UI_MGR->AddImage("�÷��̾�", L"test1", { 300,300 }, { 0.3f, 0.3f });

	UI_MGR->AddText("Son", "�ڽ�", { 100, 0 }, ColorF(ColorF::Black), L"���", 100.0f);

	UI_MGR->SetParent("�÷��̾�", "Son");

	UI_MGR->FindUI("�÷��̾�")->m_RayCast = true;

	UI_MGR->BitMapAdd("�÷��̾�", L"test2");	

	

	auto Func1 = [](void) { UI_MGR->FindUI("�÷��̾�")->m_Transform.SetPos({ 500,500 }); };
	auto Func2 = [](void) { UI_MGR->FindUI("�÷��̾�")->m_Renderer.ChangeBitmap(1); };
	auto Func3 = [](void) { UI_MGR->FindUI("�÷��̾�")->m_Renderer.ChangeBitmap(0); };


	//UI_MGR->AddEvent("�÷��̾�", ADDEVENT_OnMouseDown, Func1);
	UI_MGR->AddEvent("�÷��̾�", ADDEVENT_OnMouseOver, Func2);
	UI_MGR->AddEvent("�÷��̾�", ADDEVENT_OnMouseExit, Func3);


	UI_MGR->AddButton("���󼭹�", L"bera", { 100,500 }, { 1.0f, 1.0f });

	UI_MGR->FindUI("���󼭹�")->m_UseDrag = true;


//////////////////////// �ǹ� ���� //////////////////////////////////////////////////

	// ��� ��ư �߰�
	UI_MGR->AddToggle("���1", L"toggle1", { -80,-200 }, { 0.8f, 0.8f });
	UI_MGR->BitMapAdd("���1", L"toggle2");

	UI_MGR->AddToggle("���2", L"toggle1", { 80,-200 }, { 0.8f, 0.8f });
	UI_MGR->BitMapAdd("���2", L"toggle2");

	// ��� on/off �� �̹��� ���� �Լ�
	auto tog1_1 = [](void) { UI_MGR->FindUI("���1")->m_Renderer.ChangeBitmap(1); };
	auto tog1_2 = [](void) { UI_MGR->FindUI("���1")->m_Renderer.ChangeBitmap(0); };
	auto tog2_1 = [](void) { UI_MGR->FindUI("���2")->m_Renderer.ChangeBitmap(1); };
	auto tog2_2 = [](void) { UI_MGR->FindUI("���2")->m_Renderer.ChangeBitmap(0); };

	UI_MGR->AddEvent("���1", ADDEVENT_ToggleOn, tog1_1);
	UI_MGR->AddEvent("���1", ADDEVENT_ToggleOff, tog1_2);
	UI_MGR->AddEvent("���2", ADDEVENT_ToggleOn, tog2_1);
	UI_MGR->AddEvent("���2", ADDEVENT_ToggleOff, tog2_2);

	// ���1 ��ư�� Ȱ��ȭ
	UI_MGR->FindUI("���1")->m_isOn = true;
	UI_MGR->FindUI("���1")->m_Renderer.ChangeBitmap(1);

	// ��� �׷� ����
	vector<cUI*> vUI;

	vUI.push_back(UI_MGR->FindUI("���1"));
	vUI.push_back(UI_MGR->FindUI("���2"));

	UI_MGR->AddToggleGroup("��۱׷�", { 0, 0 }, vUI);

	// �ǹ� ��ü �߰�
	UI_MGR->AddImage("�ǹ�", L"TabBar", { 600,200 }, { 0.5f, 0.5f });

	// �ǹ� �巡�� ����
	UI_MGR->FindUI("�ǹ�")->m_RayCast = true;
	UI_MGR->FindUI("�ǹ�")->m_UseDrag = true;

	// �ǹ� ����
	UI_MGR->SetParent("�ǹ�", "��۱׷�");
	UI_MGR->AddImage("�ǹٱ۾�", L"�ǹٱ۾�", { 0, -300 }, { 0.8f, 0.8f });
	UI_MGR->SetParent("�ǹ�", "�ǹٱ۾�");

	// ���Ű Ŭ���� ���� ȭ�� ǥ��
	UI_MGR->AddImage("����", L"����", { 0, 100 }, { 0.6f, 0.6f });
	UI_MGR->AddImage("������", L"������", { 0, 100 }, { 0.6f, 0.6f });

	UI_MGR->SetParent("�ǹ�", "����");
	UI_MGR->SetParent("�ǹ�", "������");	

	auto tog1_3 = [](void) { UI_MGR->FindUI("����")->m_isActive = true; };
	auto tog1_4 = [](void) { UI_MGR->FindUI("����")->m_isActive = false; };
	auto tog2_3 = [](void) { UI_MGR->FindUI("������")->m_isActive = true; };
	auto tog2_4 = [](void) { UI_MGR->FindUI("������")->m_isActive = false; };

	UI_MGR->AddEvent("���1", ADDEVENT_ToggleOn, tog1_3);
	UI_MGR->AddEvent("���1", ADDEVENT_ToggleOff, tog1_4);

	UI_MGR->AddEvent("���2", ADDEVENT_ToggleOn, tog2_3);
	UI_MGR->AddEvent("���2", ADDEVENT_ToggleOff, tog2_4);

	UI_MGR->FindUI("������")->m_isActive = false;

	// â�ݱ� ��ư �߰�

	UI_MGR->AddButton("�ǹٴݱ�", L"â�ݱ�", { 200,-250 }, { 0.8f, 0.8f });

	UI_MGR->SetParent("�ǹ�", "�ǹٴݱ�");

	auto tabBar_off = [](void) { UI_MGR->FindUI("�ǹ�")->m_isActive = false; };

	UI_MGR->AddEvent("�ǹٴݱ�", ADDEVENT_OnMouseClick, tabBar_off);


	////////////////// ��ũ�ѹ� �߰� ////////////////////////////////////
	UI_MGR->AddScrollBar("��ũ�ѹ�", L"Scrollbar", L"ScrollHandle", { 200,100 }, 0.9f, { 0.8f, 1.2f });

	UI_MGR->SetParent("�ǹ�", "��ũ�ѹ�");

	UI_MGR->AddText("��ũ�Ѱ�", "��", { -20, 140 }, ColorF(ColorF::White));

	UI_MGR->SetParent("�ǹ�", "��ũ�Ѱ�");


	auto scrollvalue = [](void) { 
		char value[5] = "";

		sprintf_s(value, 5, "%.2f", UI_MGR->FindUI("��ũ�ѹ�")->m_Value);

		UI_MGR->FindUI("��ũ�Ѱ�")->m_Text = value;
	  };

	UI_MGR->AddEvent("��ũ�Ѱ�", ADDEVENT_Update, scrollvalue);


	////////////////// ��ǲ �ʵ� //////////////////////////////////////////////////////

	
	UI_MGR->AddInputField("��ǲ�ʵ�", L"InputField", { 200,400 }, { 0.5f , 0.7f });

	UI_MGR->FindUI("��ǲ�ʵ�")->m_UseDrag = true;

	//vUI.clear();
	//vUI.push_back(UI_MGR->FindUI("��ǲ�ʵ�"));

	//UI_MGR->AddPanel("�ǳ�", { 200,200 }, vUI);

	m_player.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"test2"));
	
}

void ServerScene::Update(float _DelayTime)
{
	UI_MGR->Update(_DelayTime);

	m_player.Update(_DelayTime);

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (UI_MGR->m_isChating == false)
		{
			UI_MGR->m_isChating = true;
		}
	}
}

void ServerScene::Render()
{
	UI_MGR->Render();

	m_player.Render();
}

void ServerScene::SendText()
{
	string sText = m_szBuf + m_szMixingString;

	UI_MGR->m_text = sText;
}

LRESULT ServerScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);

		if (m_isClicked == true)
		{
			UI_MGR->OnMouseDrag(m_MousePos);
		}
		else
		{
			UI_MGR->OnMouseOver(m_MousePos);
			UI_MGR->OnMouseExit(m_MousePos);
		}

	}break;

	case WM_LBUTTONDOWN:
	{
		MK_LOG("%d, %d Ŭ��", m_MousePos.x, m_MousePos.y);

		UI_MGR->OnMouseDown(m_MousePos);

		m_isClicked = true;

	}break;

	case WM_LBUTTONUP:
	{
		UI_MGR->OnMouseUp(m_MousePos);

		m_isClicked = false;

	}break;

	// IME ��

	case WM_CHAR:
	{
		if (UI_MGR->m_isChating == false) break;



		char cWord = (char)wParam;

		//	�齺���̽� ��ư Ŭ��
		if (cWord == VK_BACK &&
			m_szMixingString[0] == NULL)
		{
			int nLen = m_szBuf.length();

			if (nLen > 0)
			{
				//	�������� ���ڰ� ����ü �ΰ��
				if (m_szBuf[nLen - 1] < 0)
				{
					m_szBuf = m_szBuf.substr(0, nLen - 2);
				}

				//	�Ϲ� ���ڸ� ���� ���
				else
				{
					m_szBuf = m_szBuf.substr(0, nLen - 1);
				}
			}
		}
		//	����
		else if (cWord == VK_RETURN)
		{
			//CheckText = m_szBuf;
			m_szBuf = "";
			m_szMixingString[0] = NULL;

		}
		else
		{
			if (m_szBuf.size() > m_maxText)
			{
				break;
			}

			m_szBuf += (char)wParam;
		}

		SendText();


	}break;

	//	������ ������ ���� ��� �������� ���ڿ��� ����.
	case WM_IME_ENDCOMPOSITION:
	{
		if (UI_MGR->m_isChating == false) break;

		if (m_szBuf.size() >= m_maxText)
		{
			break;
		}

		m_szMixingString[0] = NULL;

		SendText();
	}
	break;

	//	IME �ȿ� �ִ� ���տ� ���� ������ ���� �� �ִ�.
	case WM_IME_COMPOSITION:
	{
		if (UI_MGR->m_isChating == false) break;

		if (m_szBuf.size() >= m_maxText)
		{
			break;
		}
		//	�������� ��� ���� �������� �ܾ ���´�.
		if (lParam & GCS_COMPSTR)
		{
			m_szMixingString[0] = CHAR(wParam >> 8);
			m_szMixingString[1] = CHAR(wParam);
		}

		//	������ ���� ���	WM_IME_CHAR �� ���� ��Ȱ
		else if (lParam & GCS_RESULTSTR)
		{
			char szFinalString[3];

			szFinalString[0] = CHAR(wParam >> 8);
			szFinalString[1] = CHAR(wParam);
			szFinalString[2] = NULL;

			//	�ϼ��� ���ڿ��� �߰� �Ѵ�.
			m_szBuf += szFinalString;
		}
		SendText();
		//	�⺻ IME ���� �������� �ʱ� ���� �ٷ� ���ν����� ������.
		return 0;
	}
	break;

	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
