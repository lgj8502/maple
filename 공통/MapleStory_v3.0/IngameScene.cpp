#include "stdafx.h"
#include "IngameScene.h"

bool checkEvent = false;
bool menuCheck = false;

IngameScene::~IngameScene()
{
	
}

void IngameScene::Init(HWND hWnd)
{
	m_SceneName = "Ingame";

	IMG_MGR->FileFindDir(L".\\Img\\IngameScene\\");
	SOUND_MGR->SoundStop(L"Sound_Login");
	//	mouse default image 
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseDefault"));	//0
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseClick"));		// 1

																	//mouse animation
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver0"));		// 2
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver1"));		// 3
	obj.m_Renderer.AddAnimation(0, 2, 3, 0.5, 0.5);
	obj.m_Renderer.m_State = -1;



	PLAYER_MGR->CreatePlayer();

	PLAYER_MGR->m_player->Init();

	PLAYER_MGR->m_player->SetPos({ PLAYER_MGR->m_player->m_CharacInfo.m_X, PLAYER_MGR->m_player->m_CharacInfo.m_Y });

	MAP_MGR->ChangeMap(PLAYER_MGR->m_player->m_CharacInfo.m_Map);

	MAP_MGR->m_CameraPos = {0, 300};


	UI_MGR->AddText("�г���Text", PLAYER_MGR->m_player->m_CharacInfo.m_Name, { -600,0 }, ColorF(ColorF::White), L"���", 15.0f);


	UI_MGR->FindUI("�г���Text")->TextRender();
	UI_MGR->FindUI("�г���Text")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_CENTER;

	float TextW = UI_MGR->FindUI("�г���Text")->m_Font.m_Metrics.width;

	UI_MGR->AddImage("�г���BG", L"NameBG", {  - TextW / 2.0f - 3.0f, -9, TextW / 2.0f + 3.0f, 9 }, 1.0f);

	UI_MGR->SetParent("�г���BG", "�г���Text");
	UI_MGR->FindUI("�г���BG")->m_Transform.m_isCamera = true;

	auto NickName1 = [](void) {
		D2D1_POINT_2F pos = PLAYER_MGR->m_player->GetPos();
		pos.y += 28.0f;
		UI_MGR->FindUI("�г���BG")->m_Transform.SetPos(pos);
	};

	UI_MGR->AddEvent("�г���BG", ADDEVENT_Update, NickName1);



	///// HP, MP, LV ���...

	UI_MGR->HPSetting(PLAYER_MGR->m_player->m_CharacInfo.m_HP);
	UI_MGR->HPMaxSetting(PLAYER_MGR->m_player->m_CharacInfo.m_HPmax);
	UI_MGR->MPSetting(PLAYER_MGR->m_player->m_CharacInfo.m_MP);
	UI_MGR->MPMaxSetting(PLAYER_MGR->m_player->m_CharacInfo.m_MPmax);
	UI_MGR->LevelSetting(PLAYER_MGR->m_player->m_CharacInfo.m_Level, { 95, 710 }, {1.5f, 1.5f});


	UI_MGR->ExpSetting(PLAYER_MGR->m_player->m_CharacInfo.m_Exp , (int)PLAYER_MGR->m_player->m_CharacInfo.m_ExpMax);
	///////////////////////////////////

	UI_MGR->AddImage("800.back", L"800.back", { 600, 794 }, { 1.5f, 1.3333f });
	
	UI_MGR->AddEXPgauge({ 0, 800 });
	//UI_MGR->AddImage("800.gauge", L"800.gauge", { 612, 794 }, { 1.5f, 1.3333f });  // �����ؾ��� ����ġ ������

	UI_MGR->AddImage("800.cover", L"800.cover", { 600, 794 }, { 1.5f, 1.3333f });
	//UI_MGR->AddImage("number.]", L"number.]", { 630, 794 }, { 1.5f, 1.3333f });
	//UI_MGR->AddImage("number.%", L"number.%", { 620, 794 }, { 1.0f, 1.0f });
	//// �ɸ��� ����ġ�� ���� ��ȭ�ؾ��� ui // ���ڰ� ���� 10
	//UI_MGR->AddImage("number.0.1", L"number.0", { 610, 794 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("number.0.2", L"number.0", { 600, 794 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("number..", L"number..", { 592, 797 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("number.0.3", L"number.0", { 582, 794 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("number.0.4", L"number.0", { 572, 794 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("number.[", L"number.[", { 560, 794 }, { 1.5f, 1.3333f });

	float ingameScenePosX = -575.0f;

	UI_MGR->AddImage("backgrnd", L"backgrnd", { 743 + ingameScenePosX, 750 }, { 1.5f, 1.3333f });

	// �����ؾ��� hp :: ���� 8

	UI_MGR->AddHPgauge({ 54, 747 });
	UI_MGR->AddMPgauge({ 54, 767 });


	//UI_MGR->AddImage("gauge.hp.layer0", L"gauge.hp.layer0", { 756 + ingameScenePosX, 739 }, { 1.5f, 1.3333f });
	//UI_MGR->AddImage("status.1.0", L"status.1", { 726 + ingameScenePosX, 740 }, { 1.5f, 1.0f });
	//UI_MGR->AddImage("status.0.0", L"status.0", { 734 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("status.0.1", L"status.0", { 742 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.slash.0", L"status.slash", { 750 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("status.1.1", L"status.1", { 758 + ingameScenePosX, 740 }, { 1.5f, 1.0f });
	//UI_MGR->AddImage("status.0.2", L"status.0", { 766 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("status.0.3", L"status.0", { 774 + ingameScenePosX, 740 }, { 1.0f, 1.0f });

	// �����ؾ��� mp ::
	//UI_MGR->AddImage("gauge.mp.layer0", L"gauge.mp.layer0", { 756 + ingameScenePosX, 760 }, { 1.5f, 1.3333f });
	//UI_MGR->AddImage("status.1.2", L"status.1", { 726 + ingameScenePosX, 761 }, { 1.5f, 1.0f });
	//UI_MGR->AddImage("status.0.4", L"status.0", { 734 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("status.0.5", L"status.0", { 742 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.slash.1", L"status.slash", { 750 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("status.1.3", L"status.1", { 758 + ingameScenePosX, 761 }, { 1.5f, 1.0f });
	//UI_MGR->AddImage("status.0.6", L"status.0", { 766 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("status.0.7", L"status.0", { 774 + ingameScenePosX, 761 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("status.layer.cover", L"status.layer.cover", { 743 + ingameScenePosX, 740 }, { 1.5f, 1.3333f }); // 600

	UI_MGR->AddText("�г���Text2", PLAYER_MGR->m_player->m_CharacInfo.m_Name, { -20, -30 }, ColorF(ColorF::White), L"���", 10.0f);
	UI_MGR->SetParent("status.layer.cover", "�г���Text2");

	UI_MGR->AddImage("status.layer.lv", L"status.layer.lv", { 648 + ingameScenePosX, 710 }, { 1.5f, 1.3333f }); // 
																												// �ɸ��� ������ ���� ��ȭ�ؾ��� ui  // 525 ���� �����Ͽ� 15 ����
	//UI_MGR->AddImage("lvNumber.1", L"lvNumber.1", { 668 + ingameScenePosX, 710 }, { 1.5f, 1.3333f }); // 525
	//UI_MGR->AddImage("lvNumber.0", L"lvNumber.0", { 683 + ingameScenePosX, 710 }, { 1.5f, 1.3333f }); // 540
																									  ///////////////////////////////////////////////////////////////////////////////////
																			 //quickSlot

	UI_MGR->AddImage("quickSlot.backgrnd", L"quickSlot.backgrnd", { 1052, 734 }, { 1.42f, 1.3333f });

	//UI_MGR->AddImage("quickSlot.backgrnd", L"quickSlot.backgrnd", {920, 734 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.backgrnd.cover", L"quickSlot.backgrnd.cover", { 0, 0 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("����Ű����Ʈ", L"itemTile", { -263, -18 }, { 1.0f, 1.0f }, 0.0f, true, true);

	auto Quick_ShiftDown = [](void) {

		if (UI_MGR->m_Skill != nullptr)
		{
			ID2D1Bitmap* pBitmap = UI_MGR->m_Skill->m_Renderer.GetBitmap();
			UI_MGR->BitMapAdd("����Ű����Ʈ", pBitmap);
			UI_MGR->FindUI("����Ű����Ʈ")->m_Renderer.ChangeBitmap(1);
			UI_MGR->FindUI("����Ű����Ʈ")->m_Renderer.SetAlpha(1.0f);
			UI_MGR->m_ShiftDown = UI_MGR->m_Skill->m_QuickFunc;
		}


		
	};

	UI_MGR->AddEvent("����Ű����Ʈ", ADDEVENT_OnMouseDown, Quick_ShiftDown);

	/////////////////////////// 1��
	UI_MGR->AddImage("quickSlot.shift", L"key.42", { -263, -25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.ins", L"key.82", { -233, -25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.hm", L"key.71", { -198, -25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.pup", L"key.73", { -161, -25 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("quickSlot.1", L"key.2", { -132,		-25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.2", L"key.3", { -95,		-25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.3", L"key.4", { -60,		-25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.4", L"key.5", { -25,		-25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.5", L"key.6", { 10,		-25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.6", L"key.7", { 45,		-25 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.7", L"key.8", { 79,		-25 }, { 1.0f, 1.0f });

	//////////////////////// 2��
	//icon.52
	UI_MGR->AddImage("quickSlot.����", L"icon.52", { -263, 17 }, { 1.0f, 1.0f }); // ���� ������ �߰�
	UI_MGR->AddImage("quickSlot.ctrl", L"key.29", { -266, 10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.del", L"key.83", { -233, 10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.end", L"key.79", { -197, 10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.pdn", L"key.81", { -161, 10 }, { 1.0f, 1.0f });


	UI_MGR->AddImage("quickSlot.q", L"key.16", { -132,		10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.w", L"key.17", { -95,		10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.e", L"key.18", { -60,		10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.r", L"key.19", { -25,		10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.t", L"key.20", { 10,		10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.y", L"key.21", { 45,		10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("quickSlot.u", L"key.22", { 79,		10 }, { 1.0f, 1.0f });



	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.del");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.ctrl");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.shift");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "����Ű����Ʈ");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.����");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.end");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.pdn");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.ins");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.hm");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.pup");

	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.1");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.2");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.3");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.4");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.5");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.6");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.7");

	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.q");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.w");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.e");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.r");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.t");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.y");
	UI_MGR->SetParent("quickSlot.backgrnd.cover", "quickSlot.u");


	UI_MGR->AddImage("button.extend800.normal", L"button.extend800.normal", { -285, 0 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("button.extend800.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("button.extend800.normal", L"button.extend800.mouseOver");
	UI_MGR->BitMapAdd("button.extend800.normal", L"button.extend800.pressed");
	auto quickSlotFunc0 = [](void) { UI_MGR->FindUI("button.extend800.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto quickSlotFunc1 = [](void) { UI_MGR->FindUI("button.extend800.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto quickSlotFunc2 = [](void) { UI_MGR->FindUI("button.extend800.normal")->m_Renderer.ChangeBitmap(2);
	UI_MGR->FindUI("button.extend800.normal")->m_isActive = false;


	UI_MGR->FindUI("quickSlot.backgrnd")->m_Transform.Translate(-299, 0);
	UI_MGR->FindUI("button.fold800.normal")->m_isActive = true;

	UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;

	};
	UI_MGR->AddEvent("button.extend800.normal", ADDEVENT_OnMouseOver, quickSlotFunc0);
	UI_MGR->AddEvent("button.extend800.normal", ADDEVENT_OnMouseExit, quickSlotFunc1);



	UI_MGR->AddImage("button.fold800.normal", L"button.fold800.normal", { -282, 0 }, { 1.0f, 1.0f }); //extend�� 3����
	UI_MGR->FindUI("button.fold800.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("button.fold800.normal", L"button.fold800.mouseOver");
	UI_MGR->BitMapAdd("button.fold800.normal", L"button.fold800.pressed");
	auto quickSlotFunc3 = [](void) { UI_MGR->FindUI("button.fold800.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto quickSlotFunc4 = [](void) { UI_MGR->FindUI("button.fold800.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto quickSlotFunc5 = [](void) { UI_MGR->FindUI("button.fold800.normal")->m_Renderer.ChangeBitmap(2);

	UI_MGR->FindUI("button.fold800.normal")->m_isActive = false;
	UI_MGR->FindUI("quickSlot.backgrnd")->m_Transform.Translate(299, 0);
	UI_MGR->FindUI("button.extend800.normal")->m_isActive = true;

	UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
	UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;	};

	UI_MGR->AddEvent("button.fold800.normal", ADDEVENT_OnMouseOver, quickSlotFunc3);
	UI_MGR->AddEvent("button.fold800.normal", ADDEVENT_OnMouseExit, quickSlotFunc4);


	UI_MGR->SetParent("quickSlot.backgrnd", "quickSlot.backgrnd.cover");
	UI_MGR->SetParent("quickSlot.backgrnd", "button.extend800.normal");
	UI_MGR->SetParent("quickSlot.backgrnd", "button.fold800.normal");

	UI_MGR->FindUI("button.fold800.normal")->m_isActive = false;
	//quickSlot end

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////// menu 780 ::  923 - 780 = 143
	//ĳ�ü�
	UI_MGR->AddImage("mainBar.menu.button.cashShop.normal.0", L"mainBar.menu.button.cashShop.normal.0", { 926 + ingameScenePosX, 763 }, { 1.42f, 1.3333f });
	UI_MGR->FindUI("mainBar.menu.button.cashShop.normal.0")->m_RayCast = true;
	UI_MGR->BitMapAdd("mainBar.menu.button.cashShop.normal.0", L"mainBar.menu.button.cashShop.mouseOver.0");
	UI_MGR->BitMapAdd("mainBar.menu.button.cashShop.normal.0", L"mainBar.menu.button.cashShop.pressed.0");
	//
	auto IngameFunc0 = [](void) { UI_MGR->FindUI("mainBar.menu.button.cashShop.normal.0")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto IngameFunc1 = [](void) { UI_MGR->FindUI("mainBar.menu.button.cashShop.normal.0")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto IngameFunc2 = [](void) { UI_MGR->FindUI("mainBar.menu.button.cashShop.normal.0")->m_Renderer.ChangeBitmap(2);   };
	UI_MGR->AddEvent("mainBar.menu.button.cashShop.normal.0", ADDEVENT_OnMouseOver, IngameFunc0);
	UI_MGR->AddEvent("mainBar.menu.button.cashShop.normal.0", ADDEVENT_OnMouseExit, IngameFunc1);
	UI_MGR->AddEvent("mainBar.menu.button.cashShop.normal.0", ADDEVENT_OnMouseClick, IngameFunc2);

	//�̺�Ʈ
	UI_MGR->AddImage("mainBar.menu.button.event.normal.0", L"mainBar.menu.button.event.normal.0", { 976 + ingameScenePosX, 763 }, { 1.42f, 1.3333f });
	UI_MGR->FindUI("mainBar.menu.button.event.normal.0")->m_RayCast = true;
	UI_MGR->BitMapAdd("mainBar.menu.button.event.normal.0", L"mainBar.menu.button.event.mouseOver.0");
	UI_MGR->BitMapAdd("mainBar.menu.button.event.normal.0", L"mainBar.menu.button.event.pressed.0");
	//
	auto IngameFunc3 = [](void) { UI_MGR->FindUI("mainBar.menu.button.event.normal.0")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto IngameFunc4 = [](void) { UI_MGR->FindUI("mainBar.menu.button.event.normal.0")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto IngameFunc5 = [](void) { UI_MGR->FindUI("mainBar.menu.button.event.normal.0")->m_Renderer.ChangeBitmap(2);
	if (UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive == true) {
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}};
	UI_MGR->AddEvent("mainBar.menu.button.event.normal.0", ADDEVENT_OnMouseOver, IngameFunc3);
	UI_MGR->AddEvent("mainBar.menu.button.event.normal.0", ADDEVENT_OnMouseExit, IngameFunc4);
	UI_MGR->AddEvent("mainBar.menu.button.event.normal.0", ADDEVENT_OnMouseClick, IngameFunc5);

	UI_MGR->AddImage("submenu.backgrnd.0.event", L"submenu.backgrnd.0", { 984 + ingameScenePosX, 630 }, { 1.42f, 1.3333f }); //1028
	UI_MGR->AddImage("submenu.backgrnd.1.event", L"submenu.backgrnd.1", { 0, 28 }, { 1.0f, 29.0f });
	UI_MGR->AddImage("submenu.backgrnd.2.event", L"submenu.backgrnd.2", { 0, 62 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("title.event", L"title.event", { 0, 0 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("schedule.normal", L"schedule.normal", { 0, 30 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("schedule.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("schedule.normal", L"schedule.pressed");
	auto eventFunc1 = [](void) { UI_MGR->FindUI("schedule.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto eventFunc2 = [](void) { UI_MGR->FindUI("schedule.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("schedule.normal", ADDEVENT_OnMouseOver, eventFunc1);
	UI_MGR->AddEvent("schedule.normal", ADDEVENT_OnMouseExit, eventFunc2);
	/////////////////////////////////////////////////////////////////
	//�غ���
	UI_MGR->AddImage("submenu.notReady", L"submenu.notReady", { 600, 400 }, { 1.5f, 1.33333f });
	UI_MGR->FindUI("submenu.notReady")->m_RayCast = true;
	UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	auto notReady = [](void) { 	
		if (UI_MGR->FindUI("submenu.notReady")->m_isActive == true)
		{
			UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
		}
		else
		{
			if (UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive == true)
			{
				UI_MGR->FindUI("submenu.notReady")->m_Transform.SetPos({ 716, 400 });
			}
			else
			{
				UI_MGR->FindUI("submenu.notReady")->m_Transform.SetPos({ 600, 400 });
			}
			UI_MGR->FindUI("submenu.notReady")->m_isActive = true;
		}
		 };
	UI_MGR->AddEvent("schedule.normal", ADDEVENT_OnMouseClick, notReady);

	//////////////////////////////////////////////////////////////////



	UI_MGR->AddImage("dailyGift.normal", L"dailyGift.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("dailyGift.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("dailyGift.normal", L"dailyGift.pressed");
	auto eventFunc3 = [](void) { UI_MGR->FindUI("dailyGift.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto eventFunc4 = [](void) { UI_MGR->FindUI("dailyGift.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("dailyGift.normal", ADDEVENT_OnMouseOver, eventFunc3);
	UI_MGR->AddEvent("dailyGift.normal", ADDEVENT_OnMouseExit, eventFunc4);
	UI_MGR->AddEvent("dailyGift.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->SetParent("submenu.backgrnd.0.event", "title.event");
	UI_MGR->SetParent("submenu.backgrnd.0.event", "schedule.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.event", "dailyGift.normal");

	UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.event", "submenu.backgrnd.1.event");
	UI_MGR->SetParent("submenu.backgrnd.0.event", "submenu.backgrnd.2.event");

	//�ɸ�������
	UI_MGR->AddImage("mainBar.menu.button.character.normal.0", L"mainBar.menu.button.character.normal.0", { 1025 + ingameScenePosX, 763 }, { 1.42f, 1.3333f });
	UI_MGR->FindUI("mainBar.menu.button.character.normal.0")->m_RayCast = true;
	UI_MGR->BitMapAdd("mainBar.menu.button.character.normal.0", L"mainBar.menu.button.character.mouseOver.0");
	UI_MGR->BitMapAdd("mainBar.menu.button.character.normal.0", L"mainBar.menu.button.character.pressed.0");
	//
	auto IngameFunc6 = [](void) { UI_MGR->FindUI("mainBar.menu.button.character.normal.0")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto IngameFunc7 = [](void) { UI_MGR->FindUI("mainBar.menu.button.character.normal.0")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto IngameFunc8 = [](void) { UI_MGR->FindUI("mainBar.menu.button.character.normal.0")->m_Renderer.ChangeBitmap(2);
	if (UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive == true) {
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		//UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}};
	UI_MGR->AddEvent("mainBar.menu.button.character.normal.0", ADDEVENT_OnMouseOver, IngameFunc6);
	UI_MGR->AddEvent("mainBar.menu.button.character.normal.0", ADDEVENT_OnMouseExit, IngameFunc7);
	UI_MGR->AddEvent("mainBar.menu.button.character.normal.0", ADDEVENT_OnMouseClick, IngameFunc8);

	vector<wstring> char_notify;
	char_notify.push_back(L"mainBar.menu.Notify.0");
	char_notify.push_back(L"mainBar.menu.Notify.1");
	char_notify.push_back(L"mainBar.menu.Notify.2");
	char_notify.push_back(L"mainBar.menu.Notify.3");
	char_notify.push_back(L"mainBar.menu.Notify.4");
	char_notify.push_back(L"mainBar.menu.Notify.5");

	UI_MGR->AddAnimation("ĳ���;˸�", { 10, -15 }, 0.2f ,char_notify);
	if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0)
	{
		UI_MGR->FindUI("ĳ���;˸�")->m_isActive = false;
	}
	UI_MGR->SetParent("mainBar.menu.button.character.normal.0", "ĳ���;˸�");

	UI_MGR->AddImage("submenu.backgrnd.0.character", L"submenu.backgrnd.0", { 1028 + ingameScenePosX, 470 }, { 1.42f, 1.3333f });
	UI_MGR->AddImage("submenu.backgrnd.1.character", L"submenu.backgrnd.1", { 0, 88 }, { 1.0f, 148.0f });
	UI_MGR->AddImage("submenu.backgrnd.2.character", L"submenu.backgrnd.2", { 0, 182 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("title.character", L"title.character", { 0, 0 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("info.normal", L"info.normal", { 0, 30 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("info.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("info.normal", L"info.pressed");
	auto characterFunc1 = [](void) { UI_MGR->FindUI("info.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc2 = [](void) { UI_MGR->FindUI("info.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };

	UI_MGR->AddEvent("info.normal", ADDEVENT_OnMouseOver, characterFunc1);
	UI_MGR->AddEvent("info.normal", ADDEVENT_OnMouseOver, characterFunc1);
	UI_MGR->AddEvent("info.normal", ADDEVENT_OnMouseExit, characterFunc2);
	UI_MGR->AddEvent("info.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("stat.normal", L"stat.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("stat.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("stat.normal", L"stat.pressed");
	auto characterFunc3 = [](void) { UI_MGR->FindUI("stat.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc4 = [](void) { UI_MGR->FindUI("stat.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto INFO_CLICK = [](void) {
		UI_MGR->FindUI("stat.normal")->m_Renderer.ChangeBitmap(0);
		UI_MGR->FindUI("����â")->m_isActive = true;
		UI_MGR->FindUI("���ȷ���")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Level);
		UI_MGR->FindUI("���Ȱ���ġ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Exp);

		ostringstream str;
		str << PLAYER_MGR->m_player->m_CharacInfo.m_HP << " / " << PLAYER_MGR->m_player->m_CharacInfo.m_HPmax;
		UI_MGR->FindUI("����HP")->m_Text = str.str();

		ostringstream str2;
		str2 << PLAYER_MGR->m_player->m_CharacInfo.m_MP << " / " << PLAYER_MGR->m_player->m_CharacInfo.m_MPmax;
		UI_MGR->FindUI("����MP")->m_Text = str2.str();

		UI_MGR->FindUI("���Ⱦ����Ƽ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Ability);
		UI_MGR->FindUI("������")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_STR);
		UI_MGR->FindUI("���ȹ�ø")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_DEX);
		UI_MGR->FindUI("��������")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_INT);
		UI_MGR->FindUI("���ȿ�")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_LUK);
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability != 0)
		{
			UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(1);
			UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(1);
			UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(1);
			UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(1);
			UI_MGR->FindUI("STRUP")->m_RayCast = true;
			UI_MGR->FindUI("DEXUP")->m_RayCast = true;
			UI_MGR->FindUI("INTUP")->m_RayCast = true;
			UI_MGR->FindUI("LUKUP")->m_RayCast = true;
		}

	};
	UI_MGR->AddEvent("stat.normal", ADDEVENT_OnMouseOver, characterFunc3);
	UI_MGR->AddEvent("stat.normal", ADDEVENT_OnMouseExit, characterFunc4);
	UI_MGR->AddEvent("stat.normal", ADDEVENT_OnMouseClick, INFO_CLICK);

	vector<wstring> Char_Noti_Stat;
	Char_Noti_Stat.push_back(L"Notify.0");
	Char_Noti_Stat.push_back(L"Notify.1");
	Char_Noti_Stat.push_back(L"Notify.2");
	Char_Noti_Stat.push_back(L"Notify.3");
	Char_Noti_Stat.push_back(L"Notify.4");
	Char_Noti_Stat.push_back(L"Notify.5");

	UI_MGR->AddAnimation("ĳ���;˸�����", { 40.0f, 0 }, 0.2f, Char_Noti_Stat);
	if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0)
	{
		UI_MGR->FindUI("ĳ���;˸�����")->m_isActive = false;
	}
	UI_MGR->SetParent("stat.normal", "ĳ���;˸�����");

	UI_MGR->AddImage("skill.normal", L"skill.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("skill.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("skill.normal", L"skill.pressed");
	auto characterFunc5 = [](void) { UI_MGR->FindUI("skill.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc6 = [](void) { UI_MGR->FindUI("skill.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto SkillWindow_Open = [](void) { 
		UI_MGR->FindUI("��ųâ1")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
	};
	UI_MGR->AddEvent("skill.normal", ADDEVENT_OnMouseOver, characterFunc5);
	UI_MGR->AddEvent("skill.normal", ADDEVENT_OnMouseExit, characterFunc6);
	UI_MGR->AddEvent("skill.normal", ADDEVENT_OnMouseClick, SkillWindow_Open);

	UI_MGR->AddImage("Equip.normal", L"Equip.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("Equip.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("Equip.normal", L"Equip.pressed");
	auto characterFunc7 = [](void) { UI_MGR->FindUI("Equip.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc8 = [](void) { UI_MGR->FindUI("Equip.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto EquipMenuClick = [](void) { 
		UI_MGR->FindUI("���â1")->m_isActive = true;
		UI_MGR->EquipRender();
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
	};

	UI_MGR->AddEvent("Equip.normal", ADDEVENT_OnMouseOver, characterFunc7);
	UI_MGR->AddEvent("Equip.normal", ADDEVENT_OnMouseExit, characterFunc8);
	UI_MGR->AddEvent("Equip.normal", ADDEVENT_OnMouseClick, EquipMenuClick);

	UI_MGR->AddImage("inven.normal", L"inven.normal", { 0, 150 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("inven.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("inven.normal", L"inven.pressed");
	auto characterFunc9 = [](void) { UI_MGR->FindUI("inven.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc10 = [](void) { UI_MGR->FindUI("inven.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto Invetory_window = [](void) { 
		UI_MGR->FindUI("�κ��丮â1")->m_isActive = true;
		UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
	};
	UI_MGR->AddEvent("inven.normal", ADDEVENT_OnMouseOver, characterFunc9);
	UI_MGR->AddEvent("inven.normal", ADDEVENT_OnMouseExit, characterFunc10);
	UI_MGR->AddEvent("inven.normal", ADDEVENT_OnMouseClick, Invetory_window);

	UI_MGR->AddImage("cabinet.normal", L"cabinet.normal", { 0, 180 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("cabinet.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("cabinet.normal", L"cabinet.pressed");
	auto characterFunc11 = [](void) { UI_MGR->FindUI("cabinet.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc12 = [](void) { UI_MGR->FindUI("cabinet.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("cabinet.normal", ADDEVENT_OnMouseOver, characterFunc11);
	UI_MGR->AddEvent("cabinet.normal", ADDEVENT_OnMouseExit, characterFunc12);
	UI_MGR->AddEvent("cabinet.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->SetParent("submenu.backgrnd.0.character", "title.character");
	UI_MGR->SetParent("submenu.backgrnd.0.character", "info.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.character", "stat.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.character", "skill.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.character", "Equip.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.character", "inven.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.character", "cabinet.normal");

	UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.character", "submenu.backgrnd.1.character");
	UI_MGR->SetParent("submenu.backgrnd.0.character", "submenu.backgrnd.2.character");

	//Ŀ�´�Ƽ
	UI_MGR->AddImage("mainBar.menu.button.community.normal.0", L"mainBar.menu.button.community.normal.0", { 1075 + ingameScenePosX, 763 }, { 1.42f, 1.3333f });
	UI_MGR->FindUI("mainBar.menu.button.community.normal.0")->m_RayCast = true;
	UI_MGR->BitMapAdd("mainBar.menu.button.community.normal.0", L"mainBar.menu.button.community.mouseOver.0");
	UI_MGR->BitMapAdd("mainBar.menu.button.community.normal.0", L"mainBar.menu.button.community.pressed.0");
	//
	auto IngameFunc9 = [](void) { UI_MGR->FindUI("mainBar.menu.button.community.normal.0")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto IngameFunc10 = [](void) { UI_MGR->FindUI("mainBar.menu.button.community.normal.0")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto IngameFunc11 = [](void) { UI_MGR->FindUI("mainBar.menu.button.community.normal.0")->m_Renderer.ChangeBitmap(2);
	if (UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive == true) {
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		//UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}};
	UI_MGR->AddEvent("mainBar.menu.button.community.normal.0", ADDEVENT_OnMouseOver, IngameFunc9);
	UI_MGR->AddEvent("mainBar.menu.button.community.normal.0", ADDEVENT_OnMouseExit, IngameFunc10);
	UI_MGR->AddEvent("mainBar.menu.button.community.normal.0", ADDEVENT_OnMouseClick, IngameFunc11);

	UI_MGR->AddImage("submenu.backgrnd.0.community", L"submenu.backgrnd.0", { 1070 + ingameScenePosX, 510 }, { 1.42f, 1.3333f }); //1112
	UI_MGR->AddImage("submenu.backgrnd.1.community", L"submenu.backgrnd.1", { 0, 73 }, { 1.0f, 118.0f });
	UI_MGR->AddImage("submenu.backgrnd.2.community", L"submenu.backgrnd.2", { 0, 152 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("title.community", L"title.community", { 0, 0 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("friends.normal", L"friends.normal", { 0, 30 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("friends.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("friends.normal", L"friends.pressed");
	auto communityFunc1 = [](void) { UI_MGR->FindUI("friends.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc2 = [](void) { UI_MGR->FindUI("friends.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("friends.normal", ADDEVENT_OnMouseOver, communityFunc1);
	UI_MGR->AddEvent("friends.normal", ADDEVENT_OnMouseExit, communityFunc2);
	UI_MGR->AddEvent("friends.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("bossParty.normal", L"bossParty.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("bossParty.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("bossParty.normal", L"bossParty.pressed");
	auto communityFunc3 = [](void) { UI_MGR->FindUI("bossParty.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc4 = [](void) { UI_MGR->FindUI("bossParty.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("bossParty.normal", ADDEVENT_OnMouseOver, communityFunc3);
	UI_MGR->AddEvent("bossParty.normal", ADDEVENT_OnMouseExit, communityFunc4);
	UI_MGR->AddEvent("bossParty.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("guild.normal", L"guild.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("guild.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("guild.normal", L"guild.pressed");
	auto communityFunc5 = [](void) { UI_MGR->FindUI("guild.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc6 = [](void) { UI_MGR->FindUI("guild.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("guild.normal", ADDEVENT_OnMouseOver, communityFunc5);
	UI_MGR->AddEvent("guild.normal", ADDEVENT_OnMouseExit, communityFunc6);
	UI_MGR->AddEvent("guild.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("notice.normal", L"notice.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("notice.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("notice.normal", L"notice.pressed");
	auto communityFunc7 = [](void) { UI_MGR->FindUI("notice.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc8 = [](void) { UI_MGR->FindUI("notice.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("notice.normal", ADDEVENT_OnMouseOver, communityFunc7);
	UI_MGR->AddEvent("notice.normal", ADDEVENT_OnMouseExit, communityFunc8);
	UI_MGR->AddEvent("notice.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("mapleChat.normal", L"mapleChat.normal", { 0, 150 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("mapleChat.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("mapleChat.normal", L"mapleChat.pressed");
	auto communityFunc9 = [](void) { UI_MGR->FindUI("mapleChat.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc10 = [](void) { UI_MGR->FindUI("mapleChat.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("mapleChat.normal", ADDEVENT_OnMouseOver, communityFunc9);
	UI_MGR->AddEvent("mapleChat.normal", ADDEVENT_OnMouseExit, communityFunc10);
	UI_MGR->AddEvent("mapleChat.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->SetParent("submenu.backgrnd.0.community", "title.community");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "friends.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "bossParty.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "guild.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "notice.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "mapleChat.normal");

	UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.community", "submenu.backgrnd.1.community");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "submenu.backgrnd.2.community");

	//�ɼ�
	UI_MGR->AddImage("mainBar.menu.button.setting.normal.0", L"mainBar.menu.button.setting.normal.0", { 1125 + ingameScenePosX, 763 }, { 1.42f, 1.3333f });
	UI_MGR->FindUI("mainBar.menu.button.setting.normal.0")->m_RayCast = true;
	UI_MGR->BitMapAdd("mainBar.menu.button.setting.normal.0", L"mainBar.menu.button.setting.mouseOver.0");
	UI_MGR->BitMapAdd("mainBar.menu.button.setting.normal.0", L"mainBar.menu.button.setting.pressed.0");
	//
	auto IngameFunc12 = [](void) { UI_MGR->FindUI("mainBar.menu.button.setting.normal.0")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto IngameFunc13 = [](void) { UI_MGR->FindUI("mainBar.menu.button.setting.normal.0")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto IngameFunc14 = [](void) { UI_MGR->FindUI("mainBar.menu.button.setting.normal.0")->m_Renderer.ChangeBitmap(2);
	if (UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive == true) {
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		//UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}	};
	UI_MGR->AddEvent("mainBar.menu.button.setting.normal.0", ADDEVENT_OnMouseOver, IngameFunc12);
	UI_MGR->AddEvent("mainBar.menu.button.setting.normal.0", ADDEVENT_OnMouseExit, IngameFunc13);
	UI_MGR->AddEvent("mainBar.menu.button.setting.normal.0", ADDEVENT_OnMouseClick, IngameFunc14);

	UI_MGR->AddImage("submenu.backgrnd.0.setting", L"submenu.backgrnd.0", { 1112 + ingameScenePosX, 551 }, { 1.42f, 1.3333f }); //310
	UI_MGR->AddImage("submenu.backgrnd.1.setting", L"submenu.backgrnd.1", { 0, 57 }, { 1.0f, 86.0f });
	UI_MGR->AddImage("submenu.backgrnd.2.setting", L"submenu.backgrnd.2", { 0, 121 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("title.setting", L"title.setting", { 0, 0 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("channel.normal", L"channel.normal", { 0, 30 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("channel.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("channel.normal", L"channel.pressed");
	auto settingFunc1 = [](void) { UI_MGR->FindUI("channel.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingFunc2 = [](void) { UI_MGR->FindUI("channel.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("channel.normal", ADDEVENT_OnMouseOver, settingFunc1);
	UI_MGR->AddEvent("channel.normal", ADDEVENT_OnMouseExit, settingFunc2);
	UI_MGR->AddEvent("channel.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("option.normal", L"option.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("option.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("option.normal", L"option.pressed");
	auto settingFunc3 = [](void) { UI_MGR->FindUI("option.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingFunc4 = [](void) { UI_MGR->FindUI("option.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("option.normal", ADDEVENT_OnMouseOver, settingFunc3);
	UI_MGR->AddEvent("option.normal", ADDEVENT_OnMouseExit, settingFunc4);
	UI_MGR->AddEvent("option.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("keySetting.normal", L"keySetting.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("keySetting.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("keySetting.normal", L"keySetting.pressed");
	auto settingFunc5 = [](void) { UI_MGR->FindUI("keySetting.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingFunc6 = [](void) { UI_MGR->FindUI("keySetting.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("keySetting.normal", ADDEVENT_OnMouseOver, settingFunc5);
	UI_MGR->AddEvent("keySetting.normal", ADDEVENT_OnMouseExit, settingFunc6);

	//UI_MGR->FindUI("keyConfig.backgrnd")->m_isActive = false;
	///
	//////////////////////////////////////////
	// keyConfig
	UI_MGR->AddImage("keyConfig.backgrnd", L"keyConfig.backgrnd", { 600, 400 }, { 1.5f, 1.33333f });
	UI_MGR->AddImage("keyConfig.backgrnd2", L"keyConfig.backgrnd2", { 0, 0 }, { 1.0f, 1.0f });
	//UI_MGR->AddImage("keyConfig.backgrnd3", L"keyConfig.backgrnd3", { 0, -80 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("keyConfig.backgrnd3", L"KeyConfigSetting", { 0, 0 }, { 1.0f, 1.0f });

	////////�⺻��ư
	//�ʱ�ȭ
	UI_MGR->AddImage("keyConfig.button.Default.normal", L"keyConfig.button.Default.normal", { -270, 215 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("keyConfig.button.Default.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("keyConfig.button.Default.normal", L"keyConfig.button.Default.mouseOver");
	UI_MGR->BitMapAdd("keyConfig.button.Default.normal", L"keyConfig.button.Default.pressed");
	auto settingkeyConfig_Clear0 = [](void) { UI_MGR->FindUI("keyConfig.button.Default.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingkeyConfig_Clear1 = [](void) { UI_MGR->FindUI("keyConfig.button.Default.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto settingkeyConfig_Clear2 = [](void) { UI_MGR->FindUI("keyConfig.button.Default.normal")->m_Renderer.ChangeBitmap(2);  };
	UI_MGR->AddEvent("keyConfig.button.Default.normal", ADDEVENT_OnMouseOver, settingkeyConfig_Clear0);
	UI_MGR->AddEvent("keyConfig.button.Default.normal", ADDEVENT_OnMouseExit, settingkeyConfig_Clear1);
	UI_MGR->AddEvent("keyConfig.button.Default.normal", ADDEVENT_OnMouseClick, settingkeyConfig_Clear2);
	//��ξ��ֱ�
	UI_MGR->AddImage("keyConfig.button.delete.normal", L"keyConfig.button.delete.normal", { -180, 215 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("keyConfig.button.delete.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("keyConfig.button.delete.normal", L"keyConfig.button.delete.mouseOver");
	UI_MGR->BitMapAdd("keyConfig.button.delete.normal", L"keyConfig.button.delete.pressed");
	auto settingkeyConfig_Delete0 = [](void) { UI_MGR->FindUI("keyConfig.button.delete.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingkeyConfig_Delete1 = [](void) { UI_MGR->FindUI("keyConfig.button.delete.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto settingkeyConfig_Delete2 = [](void) { UI_MGR->FindUI("keyConfig.button.delete.normal")->m_Renderer.ChangeBitmap(2);  };
	UI_MGR->AddEvent("keyConfig.button.delete.normal", ADDEVENT_OnMouseOver, settingkeyConfig_Delete0);
	UI_MGR->AddEvent("keyConfig.button.delete.normal", ADDEVENT_OnMouseExit, settingkeyConfig_Delete1);
	UI_MGR->AddEvent("keyConfig.button.delete.normal", ADDEVENT_OnMouseClick, settingkeyConfig_Delete2);
	////���
	UI_MGR->AddImage("keyConfig.button.cancel.normal", L"keyConfig.button.cancel.normal", { 180, 215 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("keyConfig.button.cancel.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("keyConfig.button.cancel.normal", L"keyConfig.button.cancel.mouseOver");
	UI_MGR->BitMapAdd("keyConfig.button.cancel.normal", L"keyConfig.button.cancel.pressed");
	auto settingkeyConfig_cancel0 = [](void) { UI_MGR->FindUI("keyConfig.button.cancel.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingkeyConfig_cancel1 = [](void) { UI_MGR->FindUI("keyConfig.button.cancel.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto settingkeyConfig_cancel2 = [](void) { UI_MGR->FindUI("keyConfig.button.cancel.normal")->m_Renderer.ChangeBitmap(2);  
	UI_MGR->FindUI("keyConfig.backgrnd")->m_isActive = false;
	};
	UI_MGR->AddEvent("keyConfig.button.cancel.normal", ADDEVENT_OnMouseOver, settingkeyConfig_cancel0);
	UI_MGR->AddEvent("keyConfig.button.cancel.normal", ADDEVENT_OnMouseExit, settingkeyConfig_cancel1);
	UI_MGR->AddEvent("keyConfig.button.cancel.normal", ADDEVENT_OnMouseClick, settingkeyConfig_cancel2);
	////Ȯ��
	UI_MGR->AddImage("keyConfig.button.ok.normal", L"keyConfig.button.ok.normal", { 270, 215 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("keyConfig.button.ok.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("keyConfig.button.ok.normal", L"keyConfig.button.ok.mouseOver");
	UI_MGR->BitMapAdd("keyConfig.button.ok.normal", L"keyConfig.button.ok.pressed");
	auto settingkeyConfig_ok0 = [](void) { UI_MGR->FindUI("keyConfig.button.ok.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingkeyConfig_ok1 = [](void) { UI_MGR->FindUI("keyConfig.button.ok.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto settingkeyConfig_ok2 = [](void) { UI_MGR->FindUI("keyConfig.button.ok.normal")->m_Renderer.ChangeBitmap(2); 
	UI_MGR->FindUI("keyConfig.backgrnd")->m_isActive = false;
	};
	UI_MGR->AddEvent("keyConfig.button.ok.normal", ADDEVENT_OnMouseOver, settingkeyConfig_ok0);
	UI_MGR->AddEvent("keyConfig.button.ok.normal", ADDEVENT_OnMouseExit, settingkeyConfig_ok1);
	UI_MGR->AddEvent("keyConfig.button.ok.normal", ADDEVENT_OnMouseClick, settingkeyConfig_ok2);

	UI_MGR->FindUI("keyConfig.backgrnd")->m_isActive = false;

	//�⺻��ư
	UI_MGR->SetParent("keyConfig.backgrnd", "keyConfig.button.ok.normal");
	UI_MGR->SetParent("keyConfig.backgrnd", "keyConfig.button.cancel.normal");
	UI_MGR->SetParent("keyConfig.backgrnd", "keyConfig.button.delete.normal");
	UI_MGR->SetParent("keyConfig.backgrnd", "keyConfig.button.Default.normal");
	UI_MGR->SetParent("keyConfig.backgrnd", "keyConfig.backgrnd3");
	UI_MGR->SetParent("keyConfig.backgrnd", "keyConfig.backgrnd2");
	//keyConfig end
	///////////////////////////////////////////////////
	UI_MGR->FindUI("keyConfig.backgrnd")->m_RayCast = true;
	
	auto keyConfigFunc = [](void) {
		if (UI_MGR->FindUI("keyConfig.backgrnd")->m_isActive == true)
		{
			UI_MGR->FindUI("keyConfig.backgrnd")->m_isActive = false;

		}
		else
		{
			UI_MGR->FindUI("keyConfig.backgrnd")->m_isActive = true;
			UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		}
	};
	UI_MGR->AddEvent("keySetting.normal", ADDEVENT_OnMouseClick, keyConfigFunc);
	////
	///
	UI_MGR->AddImage("gameQuit.normal", L"gameQuit.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("gameQuit.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameQuit.normal", L"gameQuit.pressed");
	auto settingFunc7 = [](void) { UI_MGR->FindUI("gameQuit.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingFunc8 = [](void) { UI_MGR->FindUI("gameQuit.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameQuit.normal", ADDEVENT_OnMouseOver, settingFunc7);
	UI_MGR->AddEvent("gameQuit.normal", ADDEVENT_OnMouseExit, settingFunc8);


	//============================================================================================
	//���� ���� â
	UI_MGR->AddButton("gameEnd", L"Game_End", { 600,400 }, { 1.50f, 1.33333f });

	// ��� ��ư
	UI_MGR->AddButton("gameEnd_No", L"ChannelScene_returnPage_no_Default", { 30,47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("gameEnd_No")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameEnd_No", L"ChannelScene_returnPage_no_Over");
	auto End_Func0 = [](void) { UI_MGR->FindUI("gameEnd_No")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto End_Func1 = [](void) { UI_MGR->FindUI("gameEnd_No")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseOver, End_Func0);
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseExit, End_Func1);

	// Ȯ�� ��ư
	UI_MGR->AddButton("gameEnd_Ok", L"ChannelScene_returnPage_ok_Default", { -30,47 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("gameEnd_Ok")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameEnd_Ok", L"ChannelScene_returnPage_ok_Over");
	auto End_Func2 = [](void) { UI_MGR->FindUI("gameEnd_Ok")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto End_Func3 = [](void) { UI_MGR->FindUI("gameEnd_Ok")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseOver, End_Func2);
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseExit, End_Func3);

	// �θ� ����
	UI_MGR->SetParent("gameEnd", "gameEnd_No");
	UI_MGR->SetParent("gameEnd", "gameEnd_Ok");
	// �ʱⰪ �Ⱥ��̰�
	UI_MGR->FindUI("gameEnd")->m_isActive = false;

	//���� ���� ��� �̺�Ʈ
	auto End_Func5 = [](void) { UI_MGR->FindUI("gameEnd")->m_isActive = false; };
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseClick, End_Func5);
	//���� ���� Ȯ�� �̺�Ʈ
	auto End_Func6 = [](void) {

		D2D1_POINT_2F pos = PLAYER_MGR->m_player->GetPos();

		pos.y -= 50.0f;
		PLAYER_MGR->m_player->m_CharacInfo.m_X = pos.x;
		PLAYER_MGR->m_player->m_CharacInfo.m_Y = pos.y;

		DATA_MGR->AllMgrDestroy();
		PostQuitMessage(WM_DESTROY); 
	};
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseClick, End_Func6);
	//============
	auto End_Func7 = [](void) {	UI_MGR->FindUI("gameEnd")->m_isActive = true; };

	UI_MGR->AddEvent("gameQuit.normal", ADDEVENT_OnMouseClick, End_Func7);



	UI_MGR->SetParent("submenu.backgrnd.0.setting", "title.setting");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "channel.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "option.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "keySetting.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "gameQuit.normal");

	UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.setting", "submenu.backgrnd.1.setting");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "submenu.backgrnd.2.setting");

	//�޴� 1030 
	UI_MGR->AddImage("mainBar.menu.button.menu.normal.0", L"mainBar.menu.button.menu.normal.0", { 1174 + ingameScenePosX, 763 }, { 1.42f, 1.3333f });
	UI_MGR->FindUI("mainBar.menu.button.menu.normal.0")->m_RayCast = true;
	UI_MGR->BitMapAdd("mainBar.menu.button.menu.normal.0", L"mainBar.menu.button.menu.mouseOver.0");
	UI_MGR->BitMapAdd("mainBar.menu.button.menu.normal.0", L"mainBar.menu.button.menu.pressed.0");
	//
	auto IngameFunc15 = [](void) { UI_MGR->FindUI("mainBar.menu.button.menu.normal.0")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto IngameFunc16 = [](void) { UI_MGR->FindUI("mainBar.menu.button.menu.normal.0")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto IngameFunc17 = [](void) { UI_MGR->FindUI("mainBar.menu.button.menu.normal.0")->m_Renderer.ChangeBitmap(2);
	if (UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive == true) {
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
		//UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
	}};
	UI_MGR->AddEvent("mainBar.menu.button.menu.normal.0", ADDEVENT_OnMouseOver, IngameFunc15);
	UI_MGR->AddEvent("mainBar.menu.button.menu.normal.0", ADDEVENT_OnMouseExit, IngameFunc16);
	UI_MGR->AddEvent("mainBar.menu.button.menu.normal.0", ADDEVENT_OnMouseClick, IngameFunc17);

	//
	UI_MGR->AddImage("submenu.backgrnd.0.menu", L"submenu.backgrnd.0", { 1112 + ingameScenePosX, 310 }, { 1.42f, 1.3333f });
	UI_MGR->AddImage("submenu.backgrnd.1.menu", L"submenu.backgrnd.1", { 0, 148 }, { 1.0f, 268.0f });
	UI_MGR->AddImage("submenu.backgrnd.2.menu", L"submenu.backgrnd.2", { 0, 302 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("title.menu", L"title.menu", { 0, 0 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("quest.normal", L"quest.normal", { 0, 30 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("quest.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("quest.normal", L"quest.pressed");
	auto menuFunc1 = [](void) { UI_MGR->FindUI("quest.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc2 = [](void) { UI_MGR->FindUI("quest.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("quest.normal", ADDEVENT_OnMouseOver, menuFunc1);
	UI_MGR->AddEvent("quest.normal", ADDEVENT_OnMouseExit, menuFunc2);
	UI_MGR->AddEvent("quest.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("medal.normal", L"medal.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("medal.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("medal.normal", L"medal.pressed");
	auto menuFunc3 = [](void) { UI_MGR->FindUI("medal.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc4 = [](void) { UI_MGR->FindUI("medal.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("medal.normal", ADDEVENT_OnMouseOver, menuFunc3);
	UI_MGR->AddEvent("medal.normal", ADDEVENT_OnMouseExit, menuFunc4);
	UI_MGR->AddEvent("medal.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("union.normal", L"union.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("union.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("union.normal", L"union.pressed");
	auto menuFunc5 = [](void) { UI_MGR->FindUI("union.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc6 = [](void) { UI_MGR->FindUI("union.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("union.normal", ADDEVENT_OnMouseOver, menuFunc5);
	UI_MGR->AddEvent("union.normal", ADDEVENT_OnMouseExit, menuFunc6);
	UI_MGR->AddEvent("union.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("monsterCollection.normal", L"monsterCollection.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("monsterCollection.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("monsterCollection.normal", L"monsterCollection.pressed");
	auto menuFunc7 = [](void) { UI_MGR->FindUI("monsterCollection.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc8 = [](void) { UI_MGR->FindUI("monsterCollection.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("monsterCollection.normal", ADDEVENT_OnMouseOver, menuFunc7);
	UI_MGR->AddEvent("monsterCollection.normal", ADDEVENT_OnMouseExit, menuFunc8);
	UI_MGR->AddEvent("monsterCollection.normal", ADDEVENT_OnMouseClick, notReady);
	///////////////
	UI_MGR->AddImage("auction.normal", L"auction.normal", { 0, 150 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("auction.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("auction.normal", L"auction.pressed");
	auto menuFunc9 = [](void) { UI_MGR->FindUI("auction.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc10 = [](void) { UI_MGR->FindUI("auction.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("auction.normal", ADDEVENT_OnMouseOver, menuFunc9);
	UI_MGR->AddEvent("auction.normal", ADDEVENT_OnMouseExit, menuFunc10);
	UI_MGR->AddEvent("auction.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("mosterLife.normal", L"mosterLife.normal", { 0, 180 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("mosterLife.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("mosterLife.normal", L"mosterLife.pressed");
	auto menuFunc11 = [](void) { UI_MGR->FindUI("mosterLife.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc12 = [](void) { UI_MGR->FindUI("mosterLife.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("mosterLife.normal", ADDEVENT_OnMouseOver, menuFunc11);
	UI_MGR->AddEvent("mosterLife.normal", ADDEVENT_OnMouseExit, menuFunc12);
	UI_MGR->AddEvent("mosterLife.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("battleStats.normal", L"battleStats.normal", { 0, 210 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("battleStats.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("battleStats.normal", L"battleStats.pressed");
	auto menuFunc13 = [](void) { UI_MGR->FindUI("battleStats.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc14 = [](void) { UI_MGR->FindUI("battleStats.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("battleStats.normal", ADDEVENT_OnMouseOver, menuFunc13);
	UI_MGR->AddEvent("battleStats.normal", ADDEVENT_OnMouseExit, menuFunc14);
	UI_MGR->AddEvent("battleStats.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("achievement.normal", L"achievement.normal", { 0, 240 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("achievement.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("achievement.normal", L"achievement.pressed");
	auto menuFunc15 = [](void) { UI_MGR->FindUI("achievement.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc16 = [](void) { UI_MGR->FindUI("achievement.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("achievement.normal", ADDEVENT_OnMouseOver, menuFunc15);
	UI_MGR->AddEvent("achievement.normal", ADDEVENT_OnMouseExit, menuFunc16);
	UI_MGR->AddEvent("achievement.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("help.normal", L"help.normal", { 0, 270 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("help.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("help.normal", L"help.pressed");
	auto menuFunc17 = [](void) { UI_MGR->FindUI("help.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc18 = [](void) { UI_MGR->FindUI("help.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("help.normal", ADDEVENT_OnMouseOver, menuFunc17);
	UI_MGR->AddEvent("help.normal", ADDEVENT_OnMouseExit, menuFunc18);
	UI_MGR->AddEvent("help.normal", ADDEVENT_OnMouseClick, notReady);

	UI_MGR->AddImage("claim.normal", L"claim.normal", { 0, 300 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("claim.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("claim.normal", L"claim.pressed");
	auto menuFunc19 = [](void) { UI_MGR->FindUI("claim.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc20 = [](void) { UI_MGR->FindUI("claim.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("claim.normal", ADDEVENT_OnMouseOver, menuFunc19);
	UI_MGR->AddEvent("claim.normal", ADDEVENT_OnMouseExit, menuFunc20);
	UI_MGR->AddEvent("claim.normal", ADDEVENT_OnMouseClick, notReady);


	//�θ� ����


	UI_MGR->SetParent("submenu.backgrnd.0.menu", "title.menu");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "quest.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "medal.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "union.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "monsterCollection.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "auction.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "mosterLife.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "battleStats.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "achievement.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "help.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "claim.normal");


	UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.menu", "submenu.backgrnd.1.menu");
	UI_MGR->SetParent("submenu.backgrnd.0.menu", "submenu.backgrnd.2.menu");


	///////////////////////////////////////////////////////////////////////////////////
	//ingame.death.panel
	UI_MGR->AddImage("ingame.death.panel", L"ingame.death.panel", { 600, 200 }, {1.0f, 1.0f});
	UI_MGR->AddImage("ingame.death.normal", L"ingame.death.normal", { 108, 42 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("ingame.death.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("ingame.death.normal", L"ingame.death.Over");
	auto deathFunc01 = [](void) { UI_MGR->FindUI("ingame.death.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto deathFunc02 = [](void) { UI_MGR->FindUI("ingame.death.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto deathFunc03 = [](void) { 
		UI_MGR->FindUI("ingame.death.panel")->m_isActive = false; 
		PLAYER_MGR->m_player->SetPos(MAP_MGR->m_pMap->m_RevivalPos);
		PLAYER_MGR->m_player->Revival();

		UI_MGR->HPSetting(PLAYER_MGR->m_player->m_CharacInfo.m_HP);
		UI_MGR->HPMaxSetting(PLAYER_MGR->m_player->m_CharacInfo.m_HPmax);
		UI_MGR->MPSetting(PLAYER_MGR->m_player->m_CharacInfo.m_MP);
		UI_MGR->MPMaxSetting(PLAYER_MGR->m_player->m_CharacInfo.m_MPmax);

		EFF_MGR->Destoy();

		
	};
	UI_MGR->AddEvent("ingame.death.normal", ADDEVENT_OnMouseOver, deathFunc01);
	UI_MGR->AddEvent("ingame.death.normal", ADDEVENT_OnMouseExit, deathFunc02);
	UI_MGR->AddEvent("ingame.death.normal", ADDEVENT_OnMouseClick, deathFunc03);
	UI_MGR->SetParent("ingame.death.panel", "ingame.death.normal");

	UI_MGR->FindUI("ingame.death.panel")->m_isActive = false;

	//////////////////////////////////////////
	// ����â

	UI_MGR->AddImage("����â", L"Stat.main.backgrnd", { 300, 400 }, { 1.0f, 1.0f }, 1.0f, false, true);
	UI_MGR->FindUI("����â")->m_UseDrag = true;
	UI_MGR->AddImage("����â2", L"Stat.main.backgrnd2", { 0, 8 }, { 1.0f, 1.0f }, 1.0f, true, true);
	UI_MGR->AddImage("����â3", L"Stat.main.backgrnd3", { 0, 40 }, { 1.0f, 1.0f }, 1.0f, true, true);
	UI_MGR->AddImage("����â�ڼ�������", L"Stat.main.BtDetailClose.disabled.0", { 60, 158 }, { 1.0f, 1.0f }, 1.0f, true, true);

	UI_MGR->AddButton("�ڵ����", L"Stat.main.BtAuto.normal.2", { 58, 0 }, { 1.0f, 1.0f }, 1.0f);
	UI_MGR->BitMapAdd("�ڵ����", L"Stat.main.BtAuto.mouseOver.0");
	UI_MGR->BitMapAdd("�ڵ����", L"Stat.main.BtAuto.pressed.0");
	UI_MGR->BitMapAdd("�ڵ����", L"Stat.main.BtAuto.disabled.0");

	auto AutoDOver = [](void) { UI_MGR->FindUI("�ڵ����")->m_Renderer.ChangeBitmap(1);};
	auto AutoDExit = [](void) { UI_MGR->FindUI("�ڵ����")->m_Renderer.ChangeBitmap(0); };
	auto AutoDDown = [](void) { UI_MGR->FindUI("�ڵ����")->m_Renderer.ChangeBitmap(2); };
	auto AutoDUp = [](void) { UI_MGR->FindUI("�ڵ����")->m_Renderer.ChangeBitmap(0); };
	UI_MGR->AddEvent("�ڵ����", ADDEVENT_OnMouseOver, AutoDOver);
	UI_MGR->AddEvent("�ڵ����", ADDEVENT_OnMouseExit, AutoDExit);
	UI_MGR->AddEvent("�ڵ����", ADDEVENT_OnMouseDown, AutoDDown);
	UI_MGR->AddEvent("�ڵ����", ADDEVENT_OnMouseUP, AutoDUp);

	UI_MGR->AddText("�����̸�", PLAYER_MGR->m_player->m_CharacInfo.m_Name, { -85, -197 }, ColorF(ColorF::Black));
	UI_MGR->AddText("��������", "���谡", { -85, -179 }, ColorF(ColorF::Black));
	UI_MGR->AddText("���ȷ���", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Level), { -85, -161 }, ColorF(ColorF::Black));
	UI_MGR->AddText("���Ȱ���ġ", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Exp), { -85, -143 }, ColorF(ColorF::Black));
	UI_MGR->AddText("���ȸ�����", "-", { -85, -125 }, ColorF(ColorF::Black));
	UI_MGR->AddText("���ȸ�ġ", "0", { -85, -107 }, ColorF(ColorF::Black));
	UI_MGR->AddText("���ȱ��", "-", { -85, -89 }, ColorF(ColorF::Black));
	UI_MGR->AddText("����HP", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_HP), { -85, -71 }, ColorF(ColorF::Black));
	UI_MGR->AddText("����MP", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_MP), { -85, -53 }, ColorF(ColorF::Black));
	UI_MGR->AddText("�����α⵵", "0", { -85, -35 }, ColorF(ColorF::Black));
	UI_MGR->AddText("���Ⱦ����Ƽ", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Ability), { -90, 7 }, ColorF(ColorF::Black));
	UI_MGR->AddText("������", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_STR), { -85, 34}, ColorF(ColorF::Black));
	UI_MGR->AddText("���ȹ�ø", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_DEX), { -85, 52 }, ColorF(ColorF::Black));
	UI_MGR->AddText("��������", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_INT), { -85, 70 }, ColorF(ColorF::Black));
	UI_MGR->AddText("���ȿ�", to_string(PLAYER_MGR->m_player->m_CharacInfo.m_LUK), { -85, 88 }, ColorF(ColorF::Black));
	
	UI_MGR->AddButton("HPUP", L"Stat.detail.BtHpUp.disabled.0", { 27, -189 }, { 1.0f, 1.0f }, 1.0f, true, false);

	UI_MGR->AddButton("MPUP", L"Stat.detail.BtHpUp.disabled.0", { 27, -171 }, { 1.0f, 1.0f }, 1.0f, true, false);

	UI_MGR->AddButton("STRUP", L"Stat.detail.BtHpUp.disabled.0", { 27, -84 }, { 1.0f, 1.0f }, 1.0f, true, false);
	UI_MGR->BitMapAdd("STRUP", L"Stat.main_xenon.BtHpUp.normal.0");
	UI_MGR->BitMapAdd("STRUP", L"Stat.main_xenon.BtHpUp.mouseOver.0");

	auto STRUPOver = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(2); };
	auto STRUPExit = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(1); };
	auto STRUPClick = [](void) {

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return;

		PLAYER_MGR->m_player->m_CharacInfo.m_STR++;	
		UI_MGR->FindUI("������")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_STR);	

		PLAYER_MGR->m_player->m_CharacInfo.m_Ability--;
		UI_MGR->FindUI("���Ⱦ����Ƽ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Ability);

		DATA_MGR->Save_Charater();

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0)
		{
			UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("STRUP")->m_RayCast = false;
			UI_MGR->FindUI("DEXUP")->m_RayCast = false;
			UI_MGR->FindUI("INTUP")->m_RayCast = false;
			UI_MGR->FindUI("LUKUP")->m_RayCast = false;
			UI_MGR->FindUI("ĳ���;˸�")->m_isActive = false;
			UI_MGR->FindUI("ĳ���;˸�����")->m_isActive = false;
		}
	};
	UI_MGR->AddEvent("STRUP", ADDEVENT_OnMouseOver, STRUPOver);
	UI_MGR->AddEvent("STRUP", ADDEVENT_OnMouseExit, STRUPExit);
	UI_MGR->AddEvent("STRUP", ADDEVENT_OnMouseClick, STRUPClick);

	UI_MGR->AddButton("DEXUP", L"Stat.detail.BtHpUp.disabled.0", { 27, -66 }, { 1.0f, 1.0f }, 1.0f, true, false);
	UI_MGR->BitMapAdd("DEXUP", L"Stat.main_xenon.BtHpUp.normal.0");
	UI_MGR->BitMapAdd("DEXUP", L"Stat.main_xenon.BtHpUp.mouseOver.0");

	auto DEXUPOver = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(2); };
	auto DEXUPExit = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(1); };
	auto DEXUPClick = [](void) {

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return;

		PLAYER_MGR->m_player->m_CharacInfo.m_DEX++;
		UI_MGR->FindUI("���ȹ�ø")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_DEX);

		PLAYER_MGR->m_player->m_CharacInfo.m_Ability--;
		UI_MGR->FindUI("���Ⱦ����Ƽ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Ability);

		DATA_MGR->Save_Charater();

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0)
		{
			UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("STRUP")->m_RayCast = false;
			UI_MGR->FindUI("DEXUP")->m_RayCast = false;
			UI_MGR->FindUI("INTUP")->m_RayCast = false;
			UI_MGR->FindUI("LUKUP")->m_RayCast = false;
			UI_MGR->FindUI("ĳ���;˸�")->m_isActive = false;
			UI_MGR->FindUI("ĳ���;˸�����")->m_isActive = false;
		}
	};
	UI_MGR->AddEvent("DEXUP", ADDEVENT_OnMouseOver, DEXUPOver);
	UI_MGR->AddEvent("DEXUP", ADDEVENT_OnMouseExit, DEXUPExit);
	UI_MGR->AddEvent("DEXUP", ADDEVENT_OnMouseClick, DEXUPClick);

	UI_MGR->AddButton("INTUP", L"Stat.detail.BtHpUp.disabled.0", { 27, -48 }, { 1.0f, 1.0f }, 1.0f, true, false);
	UI_MGR->BitMapAdd("INTUP", L"Stat.main_xenon.BtHpUp.normal.0");
	UI_MGR->BitMapAdd("INTUP", L"Stat.main_xenon.BtHpUp.mouseOver.0");

	auto INTUPOver = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(2); };
	auto INTUPExit = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(1); };
	auto INTUPClick = [](void) {

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return;

		PLAYER_MGR->m_player->m_CharacInfo.m_INT++;
		UI_MGR->FindUI("��������")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_INT);

		PLAYER_MGR->m_player->m_CharacInfo.m_Ability--;
		UI_MGR->FindUI("���Ⱦ����Ƽ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Ability);

		DATA_MGR->Save_Charater();

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0)
		{
			UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("STRUP")->m_RayCast = false;
			UI_MGR->FindUI("DEXUP")->m_RayCast = false;
			UI_MGR->FindUI("INTUP")->m_RayCast = false;
			UI_MGR->FindUI("LUKUP")->m_RayCast = false;
			UI_MGR->FindUI("ĳ���;˸�")->m_isActive = false;
			UI_MGR->FindUI("ĳ���;˸�����")->m_isActive = false;
		}
	};
	UI_MGR->AddEvent("INTUP", ADDEVENT_OnMouseOver, INTUPOver);
	UI_MGR->AddEvent("INTUP", ADDEVENT_OnMouseExit, INTUPExit);
	UI_MGR->AddEvent("INTUP", ADDEVENT_OnMouseExit, INTUPClick);

	UI_MGR->AddButton("LUKUP", L"Stat.detail.BtHpUp.disabled.0", { 27, -30 }, { 1.0f, 1.0f }, 1.0f, true, false);
	UI_MGR->BitMapAdd("LUKUP", L"Stat.main_xenon.BtHpUp.normal.0");
	UI_MGR->BitMapAdd("LUKUP", L"Stat.main_xenon.BtHpUp.mouseOver.0");

	auto LUKUPOver = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(2); };
	auto LUKUPExit = [](void) { if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return; UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(1); };
	auto LUKUPClick = [](void) {

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0) return;

		PLAYER_MGR->m_player->m_CharacInfo.m_LUK++;
		UI_MGR->FindUI("���ȿ�")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_LUK);

		PLAYER_MGR->m_player->m_CharacInfo.m_Ability--;
		UI_MGR->FindUI("���Ⱦ����Ƽ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Ability);

		DATA_MGR->Save_Charater();

		if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability == 0)
		{
			UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("STRUP")->m_RayCast = false;
			UI_MGR->FindUI("DEXUP")->m_RayCast = false;
			UI_MGR->FindUI("INTUP")->m_RayCast = false;
			UI_MGR->FindUI("LUKUP")->m_RayCast = false;
			UI_MGR->FindUI("ĳ���;˸�")->m_isActive = false;
			UI_MGR->FindUI("ĳ���;˸�����")->m_isActive = false;
		}
	};
	UI_MGR->AddEvent("LUKUP", ADDEVENT_OnMouseOver, LUKUPOver);
	UI_MGR->AddEvent("LUKUP", ADDEVENT_OnMouseExit, LUKUPExit);
	UI_MGR->AddEvent("LUKUP", ADDEVENT_OnMouseExit, LUKUPClick);

	UI_MGR->AddButton("��������", L"BtClose3.normal.0", { 35, -340 }, { 1.0f, 1.0f }, 1.0f);

	auto StatClose = [](void) { UI_MGR->FindUI("����â")->m_isActive = false; };
	UI_MGR->AddEvent("��������", ADDEVENT_OnMouseClick, StatClose);


	UI_MGR->SetParent("����â", "����â2");
	UI_MGR->SetParent("����â2", "����â3");
	UI_MGR->SetParent("����â2", "����â�ڼ�������");
	UI_MGR->SetParent("����â3", "�ڵ����");
	UI_MGR->SetParent("�ڵ����", "�����̸�");
	UI_MGR->SetParent("�����̸�", "��������");
	UI_MGR->SetParent("��������", "���ȷ���");
	UI_MGR->SetParent("���ȷ���", "���Ȱ���ġ");
	UI_MGR->SetParent("���Ȱ���ġ", "���ȸ�����");
	UI_MGR->SetParent("���ȸ�����", "���ȸ�ġ");
	UI_MGR->SetParent("���ȸ�ġ", "���ȱ��");
	UI_MGR->SetParent("���ȱ��", "����HP");
	UI_MGR->SetParent("����HP", "����MP");
	UI_MGR->SetParent("����MP", "�����α⵵");
	UI_MGR->SetParent("�����α⵵", "���Ⱦ����Ƽ");
	UI_MGR->SetParent("���Ⱦ����Ƽ", "������");
	UI_MGR->SetParent("������", "���ȹ�ø");
	UI_MGR->SetParent("���ȹ�ø", "��������");
	UI_MGR->SetParent("��������", "���ȿ�");
	UI_MGR->SetParent("����â�ڼ�������", "HPUP");
	UI_MGR->SetParent("����â�ڼ�������", "MPUP");
	UI_MGR->SetParent("����â�ڼ�������", "STRUP");
	UI_MGR->SetParent("����â�ڼ�������", "DEXUP");
	UI_MGR->SetParent("����â�ڼ�������", "INTUP");
	UI_MGR->SetParent("����â�ڼ�������", "LUKUP");
	UI_MGR->SetParent("����â�ڼ�������", "��������");


	/////////////////////////////////////////////
	//�κ��丮
	UI_MGR->AddImage("�κ��丮â1", L"Item.backgrnd", { 600, 300 }, { 1.0f, 1.0f }, 1.0f, false, true);	
	UI_MGR->FindUI("�κ��丮â1")->m_UseDrag = true;	

	UI_MGR->AddImage("�κ��丮â2", L"Item.backgrnd2", { 0, 8 }, { 1.0f, 1.0f }, 1.0f, true, false);
	UI_MGR->AddImage("�κ��丮â3", L"Item.backgrnd3", { 0, 0 }, { 1.0f, 1.0f }, 1.0f, true, false);
	
	UI_MGR->AddToggle("�����", L"Item.Tab.disabled.0", { -62, -136 }, { 1.0f, 1.0f });
	UI_MGR->BitMapAdd("�����", L"Item.Tab.enabled.0");
	UI_MGR->AddToggle("�Һ���", L"Item.Tab.disabled.1", { -31, -136 }, { 1.0f, 1.0f });
	UI_MGR->BitMapAdd("�Һ���", L"Item.Tab.enabled.1");
	UI_MGR->AddToggle("��Ÿ��", L"Item.Tab.disabled.2", { 0, -136 }, { 1.0f, 1.0f });
	UI_MGR->BitMapAdd("��Ÿ��", L"Item.Tab.enabled.2");
	UI_MGR->AddToggle("��ġ��", L"Item.Tab.disabled.3", { 31, -136 }, { 1.0f, 1.0f });
	UI_MGR->BitMapAdd("��ġ��", L"Item.Tab.enabled.3");
	UI_MGR->AddToggle("ĳ����", L"Item.Tab.disabled.4", { 62, -136 }, { 1.0f, 1.0f });
	UI_MGR->BitMapAdd("ĳ����", L"Item.Tab.enabled.4");

	// ��� on/off �� �̹��� ���� �Լ�
	auto Equip_toggleOn = [](void) { 
		UI_MGR->FindUI("�����")->m_Renderer.ChangeBitmap(1);	
		UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 0.0f;
		UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle();
		UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);

	};
	auto Equip_toggleoff = [](void) { UI_MGR->FindUI("�����")->m_Renderer.ChangeBitmap(0); };
	auto Usetem_toggleOn = [](void) { 
		UI_MGR->FindUI("�Һ���")->m_Renderer.ChangeBitmap(1); 
		UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 0.0f;
		UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle();
		UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_UseTem);
	};
	auto Usetem_toggleOff = [](void) { UI_MGR->FindUI("�Һ���")->m_Renderer.ChangeBitmap(0); };
	auto Etc_toggleOn = [](void) { 
		UI_MGR->FindUI("��Ÿ��")->m_Renderer.ChangeBitmap(1); 
		UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 0.0f;
		UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle();
		UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Etc); 
	};
	auto Etc_toggleOff = [](void) { UI_MGR->FindUI("��Ÿ��")->m_Renderer.ChangeBitmap(0); };
	auto Install_toggleOn = [](void) { 
		UI_MGR->FindUI("��ġ��")->m_Renderer.ChangeBitmap(1);
		UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 0.0f;
		UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle();
		UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Install);
	};
	auto Install_toggleOff = [](void) { UI_MGR->FindUI("��ġ��")->m_Renderer.ChangeBitmap(0); };
	auto Cash_toggleOn = [](void) { 
		UI_MGR->FindUI("ĳ����")->m_Renderer.ChangeBitmap(1); 
		UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 0.0f;
		UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle();
		UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Cash);
	};
	auto Cash_toggleOff = [](void) { UI_MGR->FindUI("ĳ����")->m_Renderer.ChangeBitmap(0); };

	UI_MGR->AddEvent("�����", ADDEVENT_ToggleOn, Equip_toggleOn);
	UI_MGR->AddEvent("�����", ADDEVENT_ToggleOff, Equip_toggleoff);
	UI_MGR->AddEvent("�Һ���", ADDEVENT_ToggleOn, Usetem_toggleOn);
	UI_MGR->AddEvent("�Һ���", ADDEVENT_ToggleOff, Usetem_toggleOff);
	UI_MGR->AddEvent("��Ÿ��", ADDEVENT_ToggleOn, Etc_toggleOn);
	UI_MGR->AddEvent("��Ÿ��", ADDEVENT_ToggleOff, Etc_toggleOff);
	UI_MGR->AddEvent("��ġ��", ADDEVENT_ToggleOn, Install_toggleOn);
	UI_MGR->AddEvent("��ġ��", ADDEVENT_ToggleOff, Install_toggleOff);
	UI_MGR->AddEvent("ĳ����", ADDEVENT_ToggleOn, Cash_toggleOn);
	UI_MGR->AddEvent("ĳ����", ADDEVENT_ToggleOff, Cash_toggleOff);

	// ���1 ��ư�� Ȱ��ȭ
	UI_MGR->FindUI("�����")->m_isOn = true;
	UI_MGR->FindUI("�����")->m_Renderer.ChangeBitmap(1);

	// ��� �׷� ����
	UI_MGR->AddToggleGroup("�κ����", { 0, 0 }, 5, UI_MGR->FindUI("�����"), UI_MGR->FindUI("�Һ���"), UI_MGR->FindUI("��Ÿ��"), UI_MGR->FindUI("��ġ��"), UI_MGR->FindUI("ĳ����"));

	UI_MGR->AddButton("�κ���ũ�Ѿ�", L"VScr100.enabled.prev0", { 10, 18 }, { 1.0f, 1.0f });
	UI_MGR->AddScrollBar("�κ���ũ�ѹ�", L"VScr100.enabled.base", L"VScr100.enabled.thumb0", { 0, 97 }, 0.0f);
	UI_MGR->AddButton("�κ���ũ�Ѵٿ�", L"VScr100.enabled.next0", { 0, 196 }, { 1.0f, 1.0f });

	auto Inven_scrollUp = [](void) { UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 0.0f;  UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle(); };
	auto Inven_scrollDown = [](void) { UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 1.0f;  UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle(); };
	auto Inven_scrollbarUpdate = [](void) {
		

		if (UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value < 0.5f)
		{
			UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 0.0f;
		}
		else
		{
			UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value = 1.0f;
		}

		if (UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value != UI_MGR->FindUI("�κ���ũ�ѹ�")->m_OldValue)
		{

			if (UI_MGR->FindUI("�����")->m_isOn == true)
			{
				UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);
			}
			else if (UI_MGR->FindUI("�Һ���")->m_isOn == true)
			{
				UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_UseTem);
			}

			UI_MGR->FindUI("�κ���ũ�ѹ�")->m_OldValue = UI_MGR->FindUI("�κ���ũ�ѹ�")->m_Value;

		}


		UI_MGR->FindUI("�κ���ũ�ѹ�")->SettingHandle(); 
	};

	UI_MGR->AddEvent("�κ���ũ�Ѿ�", ADDEVENT_OnMouseClick, Inven_scrollUp);
	UI_MGR->AddEvent("�κ���ũ�Ѵٿ�", ADDEVENT_OnMouseClick, Inven_scrollDown);
	UI_MGR->AddEvent("�κ���ũ�ѹ�", ADDEVENT_Update, Inven_scrollbarUpdate);


	UI_MGR->AddImage("�κ��޼�", L"Item.BtCoin3.normal.0", { -131, 24 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ�����������Ʈ", L"Item.BtPoint0.normal.0", { 23, 17 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ��ϴܸ޴�1", L"Item.BtDisassemble3.disabled.0", { -29, 21 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ��ϴܸ޴�2", L"Item.BtExtract3.disabled.0", { 26 , 0 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ��ϴܸ޴�3", L"Item.BtAppraise3.normal.0", { 26 , 0 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ��ϴܸ޴�4", L"Item.BtPot3.disabled.0", { 26 , 0 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ��ϴܸ޴�5", L"Item.BtToad3.normal.0", { 26 , 0 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ��ϴܸ޴�6", L"Item.BtUpgrade3.normal.0", { 26 , 0 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ����θ�����", L"Item.BtGather3.normal.0", { 111 , 0 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("�κ���ġ��", L"Item.BtGather3.normal.0", { 17 , 0 }, { 1.0f, 1.0f });
	
	UI_MGR->AddText("�޼ұݾ�", to_string(PLAYER_MGR->m_player->m_InvenInfo.m_Meso), { -1225,265 }, ColorF(ColorF::Black), L"���", 13.0f);
	UI_MGR->FindUI("�޼ұݾ�")->TextRender();
	UI_MGR->FindUI("�޼ұݾ�")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_TRAILING;

	UI_MGR->AddText("����������Ʈ", "0", { -1192,282 }, ColorF(ColorF::Black), L"���", 13.0f);
	UI_MGR->FindUI("����������Ʈ")->TextRender();
	UI_MGR->FindUI("����������Ʈ")->m_Font.m_WidthAlignment = DWRITE_TEXT_ALIGNMENT_TRAILING;

	UI_MGR->AddButton("�κ�����", L"BtClose3.normal.0", { 15, -265 }, { 1.0f, 1.0f }, 1.0f);

	auto InvenClose = [](void) { UI_MGR->FindUI("�κ��丮â1")->m_isActive = false; };
	UI_MGR->AddEvent("�κ�����", ADDEVENT_OnMouseClick, InvenClose);

	UI_MGR->SetParent("�κ��丮â1", "�κ��丮â2");
	UI_MGR->SetParent("�κ��丮â2", "�κ��丮â3");
	UI_MGR->SetParent("�κ��丮â3", "�κ����");
	UI_MGR->SetParent("ĳ����", "�κ���ũ�Ѿ�");
	UI_MGR->SetParent("�κ���ũ�Ѿ�", "�κ���ũ�ѹ�");
	UI_MGR->SetParent("�κ���ũ�Ѿ�", "�κ���ũ�Ѵٿ�");
	UI_MGR->SetParent("�κ���ũ�Ѵٿ�", "�κ��޼�");
	UI_MGR->SetParent("�κ��޼�", "�κ�����������Ʈ");
	UI_MGR->SetParent("�κ�����������Ʈ", "�κ��ϴܸ޴�1");
	UI_MGR->SetParent("�κ��ϴܸ޴�1", "�κ��ϴܸ޴�2");
	UI_MGR->SetParent("�κ��ϴܸ޴�2", "�κ��ϴܸ޴�3");
	UI_MGR->SetParent("�κ��ϴܸ޴�3", "�κ��ϴܸ޴�4");
	UI_MGR->SetParent("�κ��ϴܸ޴�4", "�κ��ϴܸ޴�5");
	UI_MGR->SetParent("�κ��ϴܸ޴�5", "�κ��ϴܸ޴�6");
	UI_MGR->SetParent("�κ��޼�", "�κ����θ�����");
	UI_MGR->SetParent("�κ����θ�����", "�κ���ġ��");
	UI_MGR->SetParent("�κ����θ�����", "�κ�����");
	UI_MGR->SetParent("�κ��޼�", "�޼ұݾ�");
	UI_MGR->SetParent("�κ��޼�", "����������Ʈ");


	auto InvenClick = [](void) { UI_MGR->InventoryClick(); };

	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			ostringstream str;
			str << "�κ�ĭ" << (i + j * 4);
			
			UI_MGR->AddImage(str.str(), L"itemTile", { i * 35.0f , -206 + j * 35.0f }, { 1.0f, 1.0f }, 0.0f, true, true);

			UI_MGR->SetParent("�κ��޼�", str.str());

			UI_MGR->FindUI(str.str())->m_InvenNum = i + j * 4;			

			UI_MGR->AddEvent(str.str(), ADDEVENT_OnMouseDown , InvenClick);
		}
	}

	/////////////////////////////////////////////
	//���â

	UI_MGR->AddImage("���â1", L"character.backgrnd", { 850, 300 }, { 1.0f, 1.0f }, 1.0f, false, true);
	UI_MGR->FindUI("���â1")->m_UseDrag = true;

	UI_MGR->AddImage("���â�߽�", L"Hide", { 0.0f, 0.0f }, { 1.0f, 1.0f });

	UI_MGR->AddImage("���â2", L"character.backgrnd2", { 0, 8 }, { 1.0f, 1.0f }, 1.0f, true, false);
	UI_MGR->AddImage("���â3", L"character.backgrnd3_dual", { 0, -2 }, { 1.0f, 1.0f }, 1.0f, true, false);
	UI_MGR->AddImage("���â�����߰�", L"character.BtSlot.normal.3", { 60, 126 }, { 1.0f, 1.0f }, 1.0f, true, false);

	auto EquipClick = [](void) {  };
	UI_MGR->AddImage("���ĭ����", L"itemTile", { -32, -100 }, { 1.0f, 1.0f }, 0.0f, true, true);
	UI_MGR->AddImage("���ĭ��", L"itemTile", { -32, -1 }, { 1.0f, 1.0f }, 0.0f, true, true);
	UI_MGR->AddImage("���ĭ����", L"itemTile", { -32, 32 }, { 1.0f, 1.0f }, 0.0f, true, true);
	UI_MGR->AddImage("���ĭ�Ź�", L"itemTile", { 1, 65 }, { 1.0f, 1.0f }, 0.0f, true, true);
	UI_MGR->AddImage("���ĭ����", L"itemTile", { 34, -1 }, { 1.0f, 1.0f }, 0.0f, true, true);

	UI_MGR->FindUI("���ĭ����")->m_ItemNum = PLAYER_MGR->m_player->m_CharacInfo.m_Cap;
	UI_MGR->FindUI("���ĭ��")->m_ItemNum = PLAYER_MGR->m_player->m_CharacInfo.m_Coat;
	UI_MGR->FindUI("���ĭ����")->m_ItemNum = PLAYER_MGR->m_player->m_CharacInfo.m_Pants;
	UI_MGR->FindUI("���ĭ�Ź�")->m_ItemNum = PLAYER_MGR->m_player->m_CharacInfo.m_Shoes;
	UI_MGR->FindUI("���ĭ����")->m_ItemNum = PLAYER_MGR->m_player->m_CharacInfo.m_Weapon;

	UI_MGR->AddButton("���â����", L"BtClose3.normal.0", { 75, -130 }, { 1.0f, 1.0f }, 1.0f);

	auto EquipClose = [](void) { UI_MGR->FindUI("���â1")->m_isActive = false; };
	UI_MGR->AddEvent("���â����", ADDEVENT_OnMouseClick, EquipClose);

	UI_MGR->SetParent("���â1", "���â�߽�");
	UI_MGR->SetParent("���â�߽�", "���â2");
	UI_MGR->SetParent("���â�߽�", "���â3");
	UI_MGR->SetParent("���â�߽�", "���â�����߰�");
	UI_MGR->SetParent("���â�߽�", "���ĭ����");
	UI_MGR->SetParent("���â�߽�", "���ĭ��");
	UI_MGR->SetParent("���â�߽�", "���ĭ����");
	UI_MGR->SetParent("���â�߽�", "���ĭ�Ź�");
	UI_MGR->SetParent("���â�߽�", "���ĭ����");
	UI_MGR->SetParent("���â�߽�", "���â����");

	/////////////////////////////////////////////
	//��ųâ

	UI_MGR->AddImage("��ųâ1", L"main.backgrnd", { 850, 500 }, { 1.0f, 1.0f }, 1.0f, false, true);
	UI_MGR->FindUI("��ųâ1")->m_UseDrag = true;
	UI_MGR->AddImage("��ųâ�߽�", L"Hide", { 0.0f, 0.0f }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųâ2", L"main.backgrnd2", { 0, 8 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųâ3", L"main.backgrnd3", { 0, 9 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("��ų��1", L"main.Tab.enabled.0", { -64, -113 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("��ų��1������", L"000.info.icon", { -58, -80 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("��ų��ũ�Ѿ�", L"VScr100.enabled.prev0", { 72, -50 }, { 1.0f, 1.0f });
	UI_MGR->AddScrollBar("��ų��ũ�ѹ�", L"VScr100.enabled.base", L"Hide", { 72, 20 }, 0.0f);
	UI_MGR->FindUI("��ų��ũ�ѹ�")->m_Transform.SetScale(1.0f, 0.7f);
	UI_MGR->AddImage("��ų��ũ�Ѵٿ�", L"VScr100.enabled.next0", { 72, 91 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("��ųĭ1", L"main.skill1", { -7, -39 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ų�ض���1", L"main.line", { -7, -19 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųĭ2", L"main.skill1", { -7, 1 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ų�ض���2", L"main.line", { -7, 21 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųĭ3", L"main.skill1", { -7, 41 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ų�ض���3", L"main.line", { -7, 61 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųĭ4", L"main.skill1", { -7, 81 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("��ųĭ1��ư", L"main.BtSpUp.disabled.0", { 55, -30 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųĭ2��ư", L"main.BtSpUp.disabled.0", { 55, 10 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųĭ3��ư", L"main.BtSpUp.disabled.0", { 55, 50 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ųĭ4��ư", L"main.BtSpUp.disabled.0", { 55, 90 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("��ųĭ1������", L"0001075.icon", { -59, -39 }, { 1.0f, 1.0f }, 1.0f, true, true);	
	UI_MGR->BitMapAdd("��ųĭ1������", L"0001075.iconMouseOver");
	UI_MGR->AddImage("��ųĭ2������", L"0001076.icon", { -59, 1 }, { 1.0f, 1.0f }, 1.0f, true, true);
	auto SoulDriver = [](void) { SKILL_MGR->SoulDriver(); };
	UI_MGR->FindUI("��ųĭ1������")->m_QuickFunc = SoulDriver;

	UI_MGR->BitMapAdd("��ųĭ2������", L"0001076.iconMouseOver");
	UI_MGR->AddImage("��ųĭ3������", L"1001005.icon", { -59, 41 }, { 1.0f, 1.0f }, 1.0f, true, true);
	UI_MGR->BitMapAdd("��ųĭ3������", L"1001005.iconMouseOver");
	UI_MGR->AddImage("��ųĭ4������", L"1121015.icon", { -59, 81 }, { 1.0f, 1.0f }, 1.0f, true, true);
	UI_MGR->BitMapAdd("��ųĭ4������", L"1121015.iconMouseOver");

	auto Skill1_Over = [](void) { UI_MGR->FindUI("��ųĭ1������")->m_Renderer.ChangeBitmap(1); };
	auto Skill1_Exit = [](void) { UI_MGR->FindUI("��ųĭ1������")->m_Renderer.ChangeBitmap(0); };
	auto Skill1_Down = [](void) { UI_MGR->SkillClick(); };
	auto Skill2_Over = [](void) { UI_MGR->FindUI("��ųĭ2������")->m_Renderer.ChangeBitmap(1); };
	auto Skill2_Exit = [](void) { UI_MGR->FindUI("��ųĭ2������")->m_Renderer.ChangeBitmap(0); };
	auto Skill3_Over = [](void) { UI_MGR->FindUI("��ųĭ3������")->m_Renderer.ChangeBitmap(1); };
	auto Skill3_Exit = [](void) { UI_MGR->FindUI("��ųĭ3������")->m_Renderer.ChangeBitmap(0); };
	auto Skill4_Over = [](void) { UI_MGR->FindUI("��ųĭ4������")->m_Renderer.ChangeBitmap(1); };
	auto Skill4_Exit = [](void) { UI_MGR->FindUI("��ųĭ4������")->m_Renderer.ChangeBitmap(0); };

	UI_MGR->AddEvent("��ųĭ1������", ADDEVENT_OnMouseOver, Skill1_Over);
	UI_MGR->AddEvent("��ųĭ1������", ADDEVENT_OnMouseExit, Skill1_Exit);
	UI_MGR->AddEvent("��ųĭ1������", ADDEVENT_OnMouseDown, Skill1_Down);
	UI_MGR->AddEvent("��ųĭ2������", ADDEVENT_OnMouseOver, Skill2_Over);
	UI_MGR->AddEvent("��ųĭ2������", ADDEVENT_OnMouseExit, Skill2_Exit);
	UI_MGR->AddEvent("��ųĭ3������", ADDEVENT_OnMouseOver, Skill3_Over);
	UI_MGR->AddEvent("��ųĭ3������", ADDEVENT_OnMouseExit, Skill3_Exit);
	UI_MGR->AddEvent("��ųĭ4������", ADDEVENT_OnMouseOver, Skill4_Over);
	UI_MGR->AddEvent("��ųĭ4������", ADDEVENT_OnMouseExit, Skill4_Exit);

	UI_MGR->AddText("��ųĭ1�̸�", "�ҿ� ����̹�", { 25, -129 }, ColorF(ColorF::Black), L"���", 12.0f);
	UI_MGR->AddText("��ųĭ1����", "1", { 25, -111 }, ColorF(ColorF::Black), L"���", 12.0f);
	UI_MGR->AddText("��ųĭ2�̸�", "�÷��� ���", { 25, -89 }, ColorF(ColorF::Black), L"���", 12.0f);
	UI_MGR->AddText("��ųĭ2����", "0", { 25, -71 }, ColorF(ColorF::Black), L"���", 12.0f);
	UI_MGR->AddText("��ųĭ3�̸�", "������ ����Ʈ", { 25, -49 }, ColorF(ColorF::Black), L"���", 12.0f);
	UI_MGR->AddText("��ųĭ3����", "0", { 25, -31 }, ColorF(ColorF::Black), L"���", 12.0f);
	UI_MGR->AddText("��ųĭ4�̸�", "�λ���¡", { 25, -9 }, ColorF(ColorF::Black), L"���", 12.0f);
	UI_MGR->AddText("��ųĭ4����", "0", { 25, 9 }, ColorF(ColorF::Black), L"���", 12.0f);

	UI_MGR->AddImage("��ų������", L"main.BtHyper.disabled.0", { -52, 113 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ų���", L"main.BtGuildSkill.disabled.0", { -52, 131 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ų���̵�", L"main.BtRide.disabled.0", { 0, 131 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("��ų��ũ��", L"main.BtMacro.disabled.0", { 52, 131 }, { 1.0f, 1.0f });

	UI_MGR->AddText("��ų���̸�", "���� ��ų", { -60, -210 }, ColorF(ColorF::White), L"���", 12.0f);
	UI_MGR->AddText("��ų����Ʈ", "0", { 65, 113 }, ColorF(ColorF::Black), L"���", 12.0f);

	UI_MGR->AddButton("��ųâ����", L"BtClose3.normal.0", { 75, -135 }, { 1.0f, 1.0f }, 1.0f);

	auto SkillClose = [](void) { UI_MGR->FindUI("��ųâ1")->m_isActive = false; };
	UI_MGR->AddEvent("��ųâ����", ADDEVENT_OnMouseClick, SkillClose);



	UI_MGR->SetParent("��ųâ1", "��ųâ�߽�");
	UI_MGR->SetParent("��ųâ�߽�", "��ųâ2");
	UI_MGR->SetParent("��ųâ�߽�", "��ųâ3");
	UI_MGR->SetParent("��ųâ�߽�", "��ų��1");
	UI_MGR->SetParent("��ųâ�߽�", "��ų��1������");
	UI_MGR->SetParent("��ųâ�߽�", "��ų��ũ�Ѿ�");
	UI_MGR->SetParent("��ųâ�߽�", "��ų��ũ�ѹ�");
	UI_MGR->SetParent("��ųâ�߽�", "��ų��ũ�Ѵٿ�");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ1");
	UI_MGR->SetParent("��ųâ�߽�", "��ų�ض���1");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ2");
	UI_MGR->SetParent("��ųâ�߽�", "��ų�ض���2");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ3");
	UI_MGR->SetParent("��ųâ�߽�", "��ų�ض���3");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ4");

	UI_MGR->SetParent("��ųâ�߽�", "��ųâ����");

	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ1��ư");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ2��ư");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ3��ư");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ4��ư");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ1������");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ2������");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ3������");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ4������");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ1�̸�");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ1����");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ2�̸�");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ2����");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ3�̸�");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ3����");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ4�̸�");
	UI_MGR->SetParent("��ųâ�߽�", "��ųĭ4����");

	UI_MGR->SetParent("��ųâ�߽�", "��ų������");
	UI_MGR->SetParent("��ųâ�߽�", "��ų���");
	UI_MGR->SetParent("��ųâ�߽�", "��ų���̵�");
	UI_MGR->SetParent("��ųâ�߽�", "��ų��ũ��");

	UI_MGR->SetParent("��ųâ�߽�", "��ų���̸�");
	UI_MGR->SetParent("��ųâ�߽�", "��ų����Ʈ");


	
	//////////////////////////////////////////
	// �̴ϸ� ĳ���� ǥ��
	UI_MGR->AddImage("�̴ϸ�����", L"minimap.user", { 100,100 }, { 1.0f, 1.0f });

	auto Mimimap_User = [](void) { 

		D2D1_POINT_2F pos = PLAYER_MGR->m_player->GetPos();

		pos.x = pos.x * 0.1f + 35.0f;
		pos.y = pos.y * 0.1f + 60.0f;

		UI_MGR->FindUI("�̴ϸ�����")->m_Transform.SetPos(pos);
	};

	UI_MGR->AddEvent("�̴ϸ�����", ADDEVENT_Update, Mimimap_User);



}

void IngameScene::Update(float _DelayTime)
{
	if (UI_MGR->m_ExitField == true)
	{
		m_szBuf = "";
		m_szMixingString[0] = NULL;

		UI_MGR->m_ExitField = false;
	}

	//m_monster.Update(_DelayTime);



	MAP_MGR->Update(_DelayTime);
	PLAYER_MGR->m_player->Update(_DelayTime);

	MOB_MGR->Update(_DelayTime);
	

	EFF_MGR->Update(_DelayTime);

	UI_MGR->Update(_DelayTime);

	//MAP_MGR->m_CameraPos.x = m_player.GetPos().x - WIN_WIDTH / 2.0f;
	//MAP_MGR->m_CameraPos.y = m_player.GetPos().y - WIN_HEIGHT / 2.0f;

	D2D1_POINT_2F start = MAP_MGR->m_CameraPos;

	D2D1_POINT_2F end = {};

	end.x = PLAYER_MGR->m_player->GetPos().x - WIN_WIDTH / 2.0f;
	end.y = PLAYER_MGR->m_player->GetPos().y - WIN_HEIGHT / 2.0f;

	MAP_MGR->m_CameraPos = DATA_MGR->Lerp(start, end, 0.02f);

	if (MAP_MGR->m_CameraPos.y > MAP_MGR->m_pMap->m_LayOut6_Size.y - WIN_HEIGHT)
	{
		MAP_MGR->m_CameraPos.y = MAP_MGR->m_pMap->m_LayOut6_Size.y - WIN_HEIGHT;
	}
	if (MAP_MGR->m_CameraPos.y < 0)
	{
		MAP_MGR->m_CameraPos.y = 0;
	}
	if (MAP_MGR->m_CameraPos.x > MAP_MGR->m_pMap->m_LayOut6_Size.x - WIN_WIDTH)
	{
		MAP_MGR->m_CameraPos.x = MAP_MGR->m_pMap->m_LayOut6_Size.x - WIN_WIDTH;
	}
	if (MAP_MGR->m_CameraPos.x < 0)
	{
		MAP_MGR->m_CameraPos.x = 0;
	}

	if (MAP_MGR->m_isPlaying == false)
	{
		MAP_MGR->m_isPlaying = true;
	}
	

	if (OnceKeyDown(VK_RETURN))
	{
		if (UI_MGR->m_isChating == false)
		{
			UI_MGR->m_isChating = true;
		}
	}

	//ATTACK
	if (OnceKeyDown(VK_CONTROL))
	{
		PLAYER_MGR->m_player->Attack();

	}

	if (StayKeyDown(VK_DOWN))
	{
		PLAYER_MGR->m_player->DownLadder(_DelayTime);

		PLAYER_MGR->m_player->Prone();

		if (OnceKeyDown(VK_MENU))
		{
			PLAYER_MGR->m_player->BlowJumpTile();
		}
	}

	//PRONESTEB
	if (StayKeyDown(VK_DOWN) && OnceKeyUp(VK_CONTROL))
	{
		PLAYER_MGR->m_player->ProneSteb();
	}

	if (OnceKeyDown(VK_UP))
	{
		PLAYER_MGR->m_player->PortalIn();
	}

	if (OnceKeyDown('Z'))
	{
		PLAYER_MGR->m_player->PickCoin();
		PLAYER_MGR->m_player->PickItem();
	}

	if (OnceKeyDown('I'))
	{
		if (UI_MGR->FindUI("�κ��丮â1")->m_isActive == false)
		{
			UI_MGR->FindUI("�κ��丮â1")->m_isActive = true;
			UI_MGR->InventoryRender(PLAYER_MGR->m_player->m_InvenInfo.m_Equip);
		}
		else
		{
			UI_MGR->FindUI("�κ��丮â1")->m_isActive = false;
		}

	}

	if (OnceKeyDown('E'))
	{
		if (UI_MGR->FindUI("���â1")->m_isActive == false)
		{
			UI_MGR->FindUI("���â1")->m_isActive = true;
			UI_MGR->EquipRender();
		}
		else
		{
			UI_MGR->FindUI("���â1")->m_isActive = false;
		}

	}

	if (OnceKeyDown('K'))
	{
		if (UI_MGR->FindUI("��ųâ1")->m_isActive == false)
		{
			UI_MGR->FindUI("��ųâ1")->m_isActive = true;

		}
		else
		{
			UI_MGR->FindUI("��ųâ1")->m_isActive = false;
		}

	}

	if (OnceKeyDown('S'))
	{
		if (UI_MGR->FindUI("����â")->m_isActive == false)
		{
			UI_MGR->FindUI("stat.normal")->m_Renderer.ChangeBitmap(0);
			UI_MGR->FindUI("����â")->m_isActive = true;
			UI_MGR->FindUI("���ȷ���")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Level);
			UI_MGR->FindUI("���Ȱ���ġ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Exp);

			ostringstream str;
			str << PLAYER_MGR->m_player->m_CharacInfo.m_HP << " / " << PLAYER_MGR->m_player->m_CharacInfo.m_HPmax;
			UI_MGR->FindUI("����HP")->m_Text = str.str();

			ostringstream str2;
			str2 << PLAYER_MGR->m_player->m_CharacInfo.m_MP << " / " << PLAYER_MGR->m_player->m_CharacInfo.m_MPmax;
			UI_MGR->FindUI("����MP")->m_Text = str2.str();

			UI_MGR->FindUI("���Ⱦ����Ƽ")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_Ability);
			UI_MGR->FindUI("������")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_STR);
			UI_MGR->FindUI("���ȹ�ø")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_DEX);
			UI_MGR->FindUI("��������")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_INT);
			UI_MGR->FindUI("���ȿ�")->m_Text = to_string(PLAYER_MGR->m_player->m_CharacInfo.m_LUK);
			UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;

			if (PLAYER_MGR->m_player->m_CharacInfo.m_Ability != 0)
			{
				UI_MGR->FindUI("STRUP")->m_Renderer.ChangeBitmap(1);
				UI_MGR->FindUI("DEXUP")->m_Renderer.ChangeBitmap(1);
				UI_MGR->FindUI("INTUP")->m_Renderer.ChangeBitmap(1);
				UI_MGR->FindUI("LUKUP")->m_Renderer.ChangeBitmap(1);
				UI_MGR->FindUI("STRUP")->m_RayCast = true;
				UI_MGR->FindUI("DEXUP")->m_RayCast = true;
				UI_MGR->FindUI("INTUP")->m_RayCast = true;
				UI_MGR->FindUI("LUKUP")->m_RayCast = true;
			}
		}
		else
		{
			UI_MGR->FindUI("����â")->m_isActive = false;
		}
	}

	if (StayKeyDown(VK_UP))
	{
		PLAYER_MGR->m_player->ClimbLadder(_DelayTime);

	}
	if (OnceKeyUp(VK_UP) || OnceKeyUp(VK_DOWN))
	{
		PLAYER_MGR->m_player->StopLadder();

		PLAYER_MGR->m_player->NotProne();

	}

	if (StayKeyDown(VK_LEFT))
	{
		PLAYER_MGR->m_player->LeftWalk(_DelayTime);

	}
	if (OnceKeyUp(VK_LEFT) || OnceKeyUp(VK_RIGHT))
	{
		PLAYER_MGR->m_player->StopWalk();

	}

	if (StayKeyDown(VK_RIGHT))
	{
		PLAYER_MGR->m_player->RightWalk(_DelayTime);

	}
	

	if (OnceKeyDown(VK_MENU))
	{
		PLAYER_MGR->m_player->JumpMove();
	}

	if (OnceKeyDown(VK_SHIFT))
	{
		UI_MGR->ShiftDown();
	}


	obj.Update(_DelayTime);
}

void IngameScene::Render()
{

	MAP_MGR->BackRender();

	MAP_MGR->PortalRender();

	MOB_MGR->Render();

	if (PLAYER_MGR->m_player->PlayerState() == PLAYER_LADDER || PLAYER_MGR->m_player->PlayerState() == PLAYER_LADDERMOVE)
	{
		MAP_MGR->LadderRender();

		if (PLAYER_MGR->m_player->PlayerState() == PLAYER_DIE)
		{
			EFF_MGR->Render();
			PLAYER_MGR->m_player->Render();
		}
		else
		{
			PLAYER_MGR->m_player->Render();
			EFF_MGR->Render();
		}

	}
	else
	{

		if (PLAYER_MGR->m_player->PlayerState() == PLAYER_DIE)
		{
			EFF_MGR->Render();
			PLAYER_MGR->m_player->Render();
		}
		else
		{
			PLAYER_MGR->m_player->Render();
			EFF_MGR->Render();
		}

		MAP_MGR->LadderRender();

	}		
		MAP_MGR->FrontRender();

		UI_MGR->Render();

		obj.Render();
}

void IngameScene::SendText()
{

	if (UI_MGR->m_InputField->m_SonUI[0]->m_isTyping == false)
	{
		m_oldText = UI_MGR->m_InputField->m_SonUI[0]->m_Text;

		string temp = m_szBuf;

		m_szBuf = m_oldText + temp;

		UI_MGR->m_InputField->m_SonUI[0]->m_isTyping = true;
	}

	string sText = m_szBuf + m_szMixingString;

	UI_MGR->m_InputField->m_SonUI[0]->m_Text = sText;
}

LRESULT IngameScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);

		obj.m_Transform.SetPos((float)m_MousePos.x + 11.0f, (float)m_MousePos.y + 12.0f);

		//if (checkEvent)
		//{
		//	obj.m_Renderer.m_State = 0;
		//}
		//else
		//{
		//	obj.m_Renderer.m_State = -1;
		//	obj.m_Renderer.ChangeBitmap(0);
		//}

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


	case WM_SYSKEYDOWN:
	{
		if (wParam == VK_MENU)
		{
			return 0;
		}
	}break;

	case WM_LBUTTONDOWN:
	{
		obj.m_Renderer.m_State = -1;
		obj.m_Renderer.ChangeBitmap(1);
		MK_LOG("%d, %d Ŭ��", m_MousePos.x, m_MousePos.y);

		if (UI_MGR->FindUI("������Ŭ��") != nullptr)
		{
			UI_MGR->DeleteUI(UI_MGR->FindUI("������Ŭ��"));
		}
		
		UI_MGR->OnMouseDown(m_MousePos);
		MAP_MGR->OnMouseDown(m_MousePos);

		m_isClicked = true;

		if (UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive == true &&
			!(m_MousePos.x > 329 && m_MousePos.x < 488 &&
				m_MousePos.y < 777 && m_MousePos.y> 614))
		{
			UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
			UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
		}

		if (UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive == true &&
			!(m_MousePos.x > 372 && m_MousePos.x < 531 &&
				m_MousePos.y < 777 && m_MousePos.y> 455))
		{
			UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
			UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
		}

		if (UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive == true &&
			!(m_MousePos.x > 414 && m_MousePos.x < 574 &&
				m_MousePos.y < 777 && m_MousePos.y> 492))
		{
			UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
			UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
		}


		if (UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive == true &&
			!(m_MousePos.x > 458 && m_MousePos.x < 614 &&
				m_MousePos.y < 777 && m_MousePos.y> 534))
		{
			UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
			UI_MGR->FindUI("submenu.notReady")->m_isActive = false;

		}

		if (UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive == true &&
			!(m_MousePos.x > 457 && m_MousePos.x < 616 &&
				m_MousePos.y < 777 && m_MousePos.y> 291))
		{
			UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
			UI_MGR->FindUI("submenu.notReady")->m_isActive = false;
		}

		if (
			UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive == true
			)
		{
			//UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
			//UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
			//UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
			//UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
			//UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;

		}

	}break;

	case WM_LBUTTONUP:
	{
		//if (checkEvent)
		//{
		//	obj.m_Renderer.m_State = 0;
		//	//obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);
		//
		//}
		//else
		//{
		//	obj.m_Renderer.m_State = -1;
		//	obj.m_Renderer.ChangeBitmap(0);
		//}

		obj.m_Renderer.ChangeBitmap(0);
		UI_MGR->OnMouseUp(m_MousePos);

		m_isClicked = false;

	}break;

	case WM_LBUTTONDBLCLK:
	{
		UI_MGR->InventoryDbClick();
		UI_MGR->EquipDbClick();
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

			m_oldText = "";

			UI_MGR->m_InputField->m_SonUI[0]->m_Text = "";

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

	case WM_CLOSE:
		UI_MGR->FindUI("gameEnd")->m_isActive = true;
		UI_MGR->DrawFirst(UI_MGR->FindUI("gameEnd"));
		return 0;
	/*default:
		return FALSE;*/
		//====
	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
