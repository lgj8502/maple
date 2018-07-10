#include "stdafx.h"
#include "IngameScene.h"

bool checkEvent = false;
bool menuCheck = false;

IngameScene::~IngameScene()
{

}

void IngameScene::Init(HWND hWnd)
{
	IMG_MGR->FileFindDir(L".\\Img\\IngameScene\\");

	MAP_MGR->ChangeMap(MNAME_EREB);

	m_player.Init();

	m_player.SetPos({ 200,900 });

	MAP_MGR->m_CameraPos = {0, 300};

	///////////////////////////////////

	UI_MGR->AddImage("800.back", L"800.back", { 600, 794 }, { 1.5f, 1.3333f });

	UI_MGR->AddImage("800.gauge", L"800.gauge", { 612, 794 }, { 1.5f, 1.3333f });  // 조정해야함 경험치 게이지

	UI_MGR->AddImage("800.cover", L"800.cover", { 600, 794 }, { 1.5f, 1.3333f });
	UI_MGR->AddImage("number.]", L"number.]", { 630, 794 }, { 1.5f, 1.3333f });
	UI_MGR->AddImage("number.%", L"number.%", { 620, 794 }, { 1.0f, 1.0f });
	// 케릭터 경험치에 따라 변화해야할 ui // 숫자간 간격 10
	UI_MGR->AddImage("number.0.1", L"number.0", { 610, 794 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("number.0.2", L"number.0", { 600, 794 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("number..", L"number..", { 592, 797 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("number.0.3", L"number.0", { 582, 794 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("number.0.4", L"number.0", { 572, 794 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("number.[", L"number.[", { 560, 794 }, { 1.5f, 1.3333f });

	float ingameScenePosX = -575.0f;

	UI_MGR->AddImage("backgrnd", L"backgrnd", { 743 + ingameScenePosX, 750 }, { 1.5f, 1.3333f });
	// 조정해야함 hp :: 간격 8
	UI_MGR->AddImage("gauge.hp.layer0", L"gauge.hp.layer0", { 756 + ingameScenePosX, 739 }, { 1.5f, 1.3333f });
	UI_MGR->AddImage("status.1.0", L"status.1", { 726 + ingameScenePosX, 740 }, { 1.5f, 1.0f });
	UI_MGR->AddImage("status.0.0", L"status.0", { 734 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.0.1", L"status.0", { 742 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.slash.0", L"status.slash", { 750 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.1.1", L"status.1", { 758 + ingameScenePosX, 740 }, { 1.5f, 1.0f });
	UI_MGR->AddImage("status.0.2", L"status.0", { 766 + ingameScenePosX, 740 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.0.3", L"status.0", { 774 + ingameScenePosX, 740 }, { 1.0f, 1.0f });

	// 조정해야함 mp ::
	UI_MGR->AddImage("gauge.mp.layer0", L"gauge.mp.layer0", { 756 + ingameScenePosX, 760 }, { 1.5f, 1.3333f });
	UI_MGR->AddImage("status.1.2", L"status.1", { 726 + ingameScenePosX, 761 }, { 1.5f, 1.0f });
	UI_MGR->AddImage("status.0.4", L"status.0", { 734 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.0.5", L"status.0", { 742 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.slash.1", L"status.slash", { 750 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.1.3", L"status.1", { 758 + ingameScenePosX, 761 }, { 1.5f, 1.0f });
	UI_MGR->AddImage("status.0.6", L"status.0", { 766 + ingameScenePosX, 761 }, { 1.0f, 1.0f });
	UI_MGR->AddImage("status.0.7", L"status.0", { 774 + ingameScenePosX, 761 }, { 1.0f, 1.0f });

	UI_MGR->AddImage("status.layer.cover", L"status.layer.cover", { 743 + ingameScenePosX, 740 }, { 1.5f, 1.3333f }); // 600

	UI_MGR->AddImage("status.layer.lv", L"status.layer.lv", { 648 + ingameScenePosX, 710 }, { 1.5f, 1.3333f }); // 
																												// 케릭터 레벨에 따라 변화해야할 ui  // 525 부터 시작하여 15 간격
	UI_MGR->AddImage("lvNumber.1", L"lvNumber.1", { 668 + ingameScenePosX, 710 }, { 1.5f, 1.3333f }); // 525
	UI_MGR->AddImage("lvNumber.0", L"lvNumber.0", { 683 + ingameScenePosX, 710 }, { 1.5f, 1.3333f }); // 540
																									  ///////////////////////////////////////////////////////////////////////////////////
																									  //quickSlot

	UI_MGR->AddImage("quickSlot.backgrnd", L"quickSlot.backgrnd", { 1052, 734 }, { 1.42f, 1.3333f });

	UI_MGR->AddImage("quickSlot.backgrnd.cover", L"quickSlot.backgrnd.cover", { 0, 0 }, { 1.0f, 1.0f });


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



	UI_MGR->AddImage("button.fold800.normal", L"button.fold800.normal", { -282, 0 }, { 1.0f, 1.0f }); //extend와 3차이
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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////// menu 780 ::  923 - 780 = 143
	//캐시샵
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

	//이벤트
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
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
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

	UI_MGR->AddImage("dailyGift.normal", L"dailyGift.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("dailyGift.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("dailyGift.normal", L"dailyGift.pressed");
	auto eventFunc3 = [](void) { UI_MGR->FindUI("dailyGift.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto eventFunc4 = [](void) { UI_MGR->FindUI("dailyGift.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("dailyGift.normal", ADDEVENT_OnMouseOver, eventFunc3);
	UI_MGR->AddEvent("dailyGift.normal", ADDEVENT_OnMouseExit, eventFunc4);

	UI_MGR->SetParent("submenu.backgrnd.0.event", "title.event");
	UI_MGR->SetParent("submenu.backgrnd.0.event", "schedule.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.event", "dailyGift.normal");

	UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.event", "submenu.backgrnd.1.event");
	UI_MGR->SetParent("submenu.backgrnd.0.event", "submenu.backgrnd.2.event");

	//케릭터정보
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
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		//UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
	}};
	UI_MGR->AddEvent("mainBar.menu.button.character.normal.0", ADDEVENT_OnMouseOver, IngameFunc6);
	UI_MGR->AddEvent("mainBar.menu.button.character.normal.0", ADDEVENT_OnMouseExit, IngameFunc7);
	UI_MGR->AddEvent("mainBar.menu.button.character.normal.0", ADDEVENT_OnMouseClick, IngameFunc8);


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
	UI_MGR->AddEvent("info.normal", ADDEVENT_OnMouseExit, characterFunc2);

	UI_MGR->AddImage("stat.normal", L"stat.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("stat.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("stat.normal", L"stat.pressed");
	auto characterFunc3 = [](void) { UI_MGR->FindUI("stat.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc4 = [](void) { UI_MGR->FindUI("stat.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("stat.normal", ADDEVENT_OnMouseOver, characterFunc3);
	UI_MGR->AddEvent("stat.normal", ADDEVENT_OnMouseExit, characterFunc4);

	UI_MGR->AddImage("skill.normal", L"skill.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("skill.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("skill.normal", L"skill.pressed");
	auto characterFunc5 = [](void) { UI_MGR->FindUI("skill.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc6 = [](void) { UI_MGR->FindUI("skill.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("skill.normal", ADDEVENT_OnMouseOver, characterFunc5);
	UI_MGR->AddEvent("skill.normal", ADDEVENT_OnMouseExit, characterFunc6);

	UI_MGR->AddImage("Equip.normal", L"Equip.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("Equip.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("Equip.normal", L"Equip.pressed");
	auto characterFunc7 = [](void) { UI_MGR->FindUI("Equip.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc8 = [](void) { UI_MGR->FindUI("Equip.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("Equip.normal", ADDEVENT_OnMouseOver, characterFunc7);
	UI_MGR->AddEvent("Equip.normal", ADDEVENT_OnMouseExit, characterFunc8);

	UI_MGR->AddImage("inven.normal", L"inven.normal", { 0, 150 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("inven.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("inven.normal", L"inven.pressed");
	auto characterFunc9 = [](void) { UI_MGR->FindUI("inven.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc10 = [](void) { UI_MGR->FindUI("inven.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("inven.normal", ADDEVENT_OnMouseOver, characterFunc9);
	UI_MGR->AddEvent("inven.normal", ADDEVENT_OnMouseExit, characterFunc10);

	UI_MGR->AddImage("cabinet.normal", L"cabinet.normal", { 0, 180 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("cabinet.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("cabinet.normal", L"cabinet.pressed");
	auto characterFunc11 = [](void) { UI_MGR->FindUI("cabinet.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto characterFunc12 = [](void) { UI_MGR->FindUI("cabinet.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("cabinet.normal", ADDEVENT_OnMouseOver, characterFunc11);
	UI_MGR->AddEvent("cabinet.normal", ADDEVENT_OnMouseExit, characterFunc12);

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

	//커뮤니티
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
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		//UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
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

	UI_MGR->AddImage("bossParty.normal", L"bossParty.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("bossParty.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("bossParty.normal", L"bossParty.pressed");
	auto communityFunc3 = [](void) { UI_MGR->FindUI("bossParty.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc4 = [](void) { UI_MGR->FindUI("bossParty.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("bossParty.normal", ADDEVENT_OnMouseOver, communityFunc3);
	UI_MGR->AddEvent("bossParty.normal", ADDEVENT_OnMouseExit, communityFunc4);

	UI_MGR->AddImage("guild.normal", L"guild.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("guild.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("guild.normal", L"guild.pressed");
	auto communityFunc5 = [](void) { UI_MGR->FindUI("guild.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc6 = [](void) { UI_MGR->FindUI("guild.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("guild.normal", ADDEVENT_OnMouseOver, communityFunc5);
	UI_MGR->AddEvent("guild.normal", ADDEVENT_OnMouseExit, communityFunc6);

	UI_MGR->AddImage("notice.normal", L"notice.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("notice.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("notice.normal", L"notice.pressed");
	auto communityFunc7 = [](void) { UI_MGR->FindUI("notice.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc8 = [](void) { UI_MGR->FindUI("notice.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("notice.normal", ADDEVENT_OnMouseOver, communityFunc7);
	UI_MGR->AddEvent("notice.normal", ADDEVENT_OnMouseExit, communityFunc8);

	UI_MGR->AddImage("mapleChat.normal", L"mapleChat.normal", { 0, 150 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("mapleChat.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("mapleChat.normal", L"mapleChat.pressed");
	auto communityFunc9 = [](void) { UI_MGR->FindUI("mapleChat.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto communityFunc10 = [](void) { UI_MGR->FindUI("mapleChat.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("mapleChat.normal", ADDEVENT_OnMouseOver, communityFunc9);
	UI_MGR->AddEvent("mapleChat.normal", ADDEVENT_OnMouseExit, communityFunc10);

	UI_MGR->SetParent("submenu.backgrnd.0.community", "title.community");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "friends.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "bossParty.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "guild.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "notice.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "mapleChat.normal");

	UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.community", "submenu.backgrnd.1.community");
	UI_MGR->SetParent("submenu.backgrnd.0.community", "submenu.backgrnd.2.community");

	//옵션
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
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		//UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;
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

	UI_MGR->AddImage("option.normal", L"option.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("option.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("option.normal", L"option.pressed");
	auto settingFunc3 = [](void) { UI_MGR->FindUI("option.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingFunc4 = [](void) { UI_MGR->FindUI("option.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("option.normal", ADDEVENT_OnMouseOver, settingFunc3);
	UI_MGR->AddEvent("option.normal", ADDEVENT_OnMouseExit, settingFunc4);

	UI_MGR->AddImage("keySetting.normal", L"keySetting.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("keySetting.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("keySetting.normal", L"keySetting.pressed");
	auto settingFunc5 = [](void) { UI_MGR->FindUI("keySetting.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingFunc6 = [](void) { UI_MGR->FindUI("keySetting.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("keySetting.normal", ADDEVENT_OnMouseOver, settingFunc5);
	UI_MGR->AddEvent("keySetting.normal", ADDEVENT_OnMouseExit, settingFunc6);

	UI_MGR->AddImage("gameQuit.normal", L"gameQuit.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("gameQuit.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameQuit.normal", L"gameQuit.pressed");
	auto settingFunc7 = [](void) { UI_MGR->FindUI("gameQuit.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto settingFunc8 = [](void) { UI_MGR->FindUI("gameQuit.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameQuit.normal", ADDEVENT_OnMouseOver, settingFunc7);
	UI_MGR->AddEvent("gameQuit.normal", ADDEVENT_OnMouseExit, settingFunc8);

	UI_MGR->SetParent("submenu.backgrnd.0.setting", "title.setting");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "channel.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "option.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "keySetting.normal");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "gameQuit.normal");

	UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;

	UI_MGR->SetParent("submenu.backgrnd.0.setting", "submenu.backgrnd.1.setting");
	UI_MGR->SetParent("submenu.backgrnd.0.setting", "submenu.backgrnd.2.setting");

	//메뉴 1030 
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
	}
	else {
		UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = true;
		UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
		UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
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

	UI_MGR->AddImage("medal.normal", L"medal.normal", { 0, 60 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("medal.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("medal.normal", L"medal.pressed");
	auto menuFunc3 = [](void) { UI_MGR->FindUI("medal.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc4 = [](void) { UI_MGR->FindUI("medal.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("medal.normal", ADDEVENT_OnMouseOver, menuFunc3);
	UI_MGR->AddEvent("medal.normal", ADDEVENT_OnMouseExit, menuFunc4);

	UI_MGR->AddImage("union.normal", L"union.normal", { 0, 90 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("union.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("union.normal", L"union.pressed");
	auto menuFunc5 = [](void) { UI_MGR->FindUI("union.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc6 = [](void) { UI_MGR->FindUI("union.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("union.normal", ADDEVENT_OnMouseOver, menuFunc5);
	UI_MGR->AddEvent("union.normal", ADDEVENT_OnMouseExit, menuFunc6);

	UI_MGR->AddImage("monsterCollection.normal", L"monsterCollection.normal", { 0, 120 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("monsterCollection.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("monsterCollection.normal", L"monsterCollection.pressed");
	auto menuFunc7 = [](void) { UI_MGR->FindUI("monsterCollection.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc8 = [](void) { UI_MGR->FindUI("monsterCollection.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("monsterCollection.normal", ADDEVENT_OnMouseOver, menuFunc7);
	UI_MGR->AddEvent("monsterCollection.normal", ADDEVENT_OnMouseExit, menuFunc8);
	///////////////
	UI_MGR->AddImage("auction.normal", L"auction.normal", { 0, 150 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("auction.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("auction.normal", L"auction.pressed");
	auto menuFunc9 = [](void) { UI_MGR->FindUI("auction.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc10 = [](void) { UI_MGR->FindUI("auction.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("auction.normal", ADDEVENT_OnMouseOver, menuFunc9);
	UI_MGR->AddEvent("auction.normal", ADDEVENT_OnMouseExit, menuFunc10);

	UI_MGR->AddImage("mosterLife.normal", L"mosterLife.normal", { 0, 180 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("mosterLife.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("mosterLife.normal", L"mosterLife.pressed");
	auto menuFunc11 = [](void) { UI_MGR->FindUI("mosterLife.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc12 = [](void) { UI_MGR->FindUI("mosterLife.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("mosterLife.normal", ADDEVENT_OnMouseOver, menuFunc11);
	UI_MGR->AddEvent("mosterLife.normal", ADDEVENT_OnMouseExit, menuFunc12);

	UI_MGR->AddImage("battleStats.normal", L"battleStats.normal", { 0, 210 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("battleStats.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("battleStats.normal", L"battleStats.pressed");
	auto menuFunc13 = [](void) { UI_MGR->FindUI("battleStats.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc14 = [](void) { UI_MGR->FindUI("battleStats.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("battleStats.normal", ADDEVENT_OnMouseOver, menuFunc13);
	UI_MGR->AddEvent("battleStats.normal", ADDEVENT_OnMouseExit, menuFunc14);

	UI_MGR->AddImage("achievement.normal", L"achievement.normal", { 0, 240 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("achievement.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("achievement.normal", L"achievement.pressed");
	auto menuFunc15 = [](void) { UI_MGR->FindUI("achievement.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc16 = [](void) { UI_MGR->FindUI("achievement.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("achievement.normal", ADDEVENT_OnMouseOver, menuFunc15);
	UI_MGR->AddEvent("achievement.normal", ADDEVENT_OnMouseExit, menuFunc16);

	UI_MGR->AddImage("help.normal", L"help.normal", { 0, 270 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("help.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("help.normal", L"help.pressed");
	auto menuFunc17 = [](void) { UI_MGR->FindUI("help.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc18 = [](void) { UI_MGR->FindUI("help.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("help.normal", ADDEVENT_OnMouseOver, menuFunc17);
	UI_MGR->AddEvent("help.normal", ADDEVENT_OnMouseExit, menuFunc18);

	UI_MGR->AddImage("claim.normal", L"claim.normal", { 0, 300 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("claim.normal")->m_RayCast = true;
	UI_MGR->BitMapAdd("claim.normal", L"claim.pressed");
	auto menuFunc19 = [](void) { UI_MGR->FindUI("claim.normal")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto menuFunc20 = [](void) { UI_MGR->FindUI("claim.normal")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("claim.normal", ADDEVENT_OnMouseOver, menuFunc19);
	UI_MGR->AddEvent("claim.normal", ADDEVENT_OnMouseExit, menuFunc20);
	//부모 설정


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
	m_player.Update(_DelayTime);

	UI_MGR->Update(_DelayTime);

	//MAP_MGR->m_CameraPos.x = m_player.GetPos().x - WIN_WIDTH / 2.0f;
	//MAP_MGR->m_CameraPos.y = m_player.GetPos().y - WIN_HEIGHT / 2.0f;

	D2D1_POINT_2F start = MAP_MGR->m_CameraPos;

	D2D1_POINT_2F end = {};

	end.x = m_player.GetPos().x - WIN_WIDTH / 2.0f;
	end.y = m_player.GetPos().y - WIN_HEIGHT / 2.0f;

	MAP_MGR->m_CameraPos = Lerp(start, end, 0.02f);

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

	if (StayKeyDown(VK_DOWN))
	{
		m_player.DownLadder(_DelayTime);

		if (OnceKeyDown(VK_MENU))
		{
			m_player.BlowJumpTile();
		}
	}

	if (OnceKeyDown(VK_UP))
	{
		m_player.PortalIn();
	}


	if (StayKeyDown(VK_UP))
	{
		m_player.ClimbLadder(_DelayTime);

	}
	if (OnceKeyUp(VK_UP) || OnceKeyUp(VK_DOWN))
	{
		m_player.StopLadder();

	}

	if (StayKeyDown(VK_LEFT))
	{
		m_player.LeftWalk(_DelayTime);

	}
	if (OnceKeyUp(VK_LEFT) || OnceKeyUp(VK_RIGHT))
	{
		m_player.StopWalk();

	}

	if (StayKeyDown(VK_RIGHT))
	{
		m_player.RightWalk(_DelayTime);

	}

	if (OnceKeyDown(VK_F1))
	{
		m_player.ChangeCoat(101);
	}

	if (OnceKeyDown(VK_F2))
	{
		m_player.ChangeCoat(100);
	}


	if (OnceKeyDown(VK_MENU))
	{
		m_player.JumpMove();
	}
}

void IngameScene::Render()
{

	MAP_MGR->BackRender();
	//m_monster.Render();

	if (m_player.PlayerState() == PLAYER_LADDER)
	{
		MAP_MGR->LadderRender();
		m_player.Render();
	}
	else
	{
		m_player.Render();
		MAP_MGR->LadderRender();
	}


	MAP_MGR->FrontRender();

	UI_MGR->Render();
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

D2D1_POINT_2F IngameScene::Lerp(D2D1_POINT_2F _start, D2D1_POINT_2F _end, float _rate)
{
	D2D1_POINT_2F result = {};

	result.x = _start.x * (1 - _rate) + _end.x * _rate;
	result.y = _start.y * (1 - _rate) + _end.y * _rate;

	return result;
}

LRESULT IngameScene::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
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


	case WM_SYSKEYDOWN:
	{
		if (wParam == VK_MENU)
		{
			return 0;
		}
	}break;

	case WM_LBUTTONDOWN:
	{
		MK_LOG("%d, %d 클릭", m_MousePos.x, m_MousePos.y);

		UI_MGR->OnMouseDown(m_MousePos);

		m_isClicked = true;

		if (
			UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive == true ||
			UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive == true
			)
		{
			UI_MGR->FindUI("submenu.backgrnd.0.event")->m_isActive = false;
			UI_MGR->FindUI("submenu.backgrnd.0.character")->m_isActive = false;
			UI_MGR->FindUI("submenu.backgrnd.0.community")->m_isActive = false;
			UI_MGR->FindUI("submenu.backgrnd.0.setting")->m_isActive = false;
			UI_MGR->FindUI("submenu.backgrnd.0.menu")->m_isActive = false;

		}

	}break;


	case WM_LBUTTONUP:
	{
		UI_MGR->OnMouseUp(m_MousePos);

		m_isClicked = false;

	}break;

	// IME 용

	case WM_CHAR:
	{
		if (UI_MGR->m_isChating == false) break;


		char cWord = (char)wParam;

		//	백스페이스 버튼 클릭
		if (cWord == VK_BACK &&
			m_szMixingString[0] == NULL)
		{
			int nLen = m_szBuf.length();

			if (nLen > 0)
			{
				//	지워야할 문자가 조합체 인경우
				if (m_szBuf[nLen - 1] < 0)
				{
					m_szBuf = m_szBuf.substr(0, nLen - 2);
				}

				//	일반 문자를 지울 경우
				else
				{
					m_szBuf = m_szBuf.substr(0, nLen - 1);
				}
			}
		}
		//	엔터
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

	//	조합이 완전히 끝난 경우 조합중인 문자열을 비운다.
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

	//	IME 안에 있는 조합에 대한 내용을 얻을 수 있다.
	case WM_IME_COMPOSITION:
	{
		if (UI_MGR->m_isChating == false) break;

		if (m_szBuf.size() >= m_maxText)
		{
			break;
		}
		//	조합중일 경우 현재 조합중인 단어를 얻어온다.
		if (lParam & GCS_COMPSTR)
		{
			m_szMixingString[0] = CHAR(wParam >> 8);
			m_szMixingString[1] = CHAR(wParam);
		}

		//	조합이 끝난 경우	WM_IME_CHAR 와 같은 역활
		else if (lParam & GCS_RESULTSTR)
		{
			char szFinalString[3];

			szFinalString[0] = CHAR(wParam >> 8);
			szFinalString[1] = CHAR(wParam);
			szFinalString[2] = NULL;

			//	완성된 문자열을 추가 한다.
			m_szBuf += szFinalString;
		}
		SendText();
		//	기본 IME 에게 전달하지 않기 위해 바로 프로시저를 끝낸다.
		return 0;
	}
	break;

	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}
