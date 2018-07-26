#include "stdafx.h"
#include "CreateScene1.h"


//////추가 사항
static bool checkEvent = false;

static PlayerTest* p_player = nullptr;

struct infoEquip
{
	string name;
	size_t number;
};

static infoEquip firstInfoArray[5];
static infoEquip secondInfoArray[5];
static infoEquip thirdInfoArray[3];
static infoEquip fourInfoArray[2];
static infoEquip fiveInfoArray[3];
static int firstArrayIndex = 0;
static int secondArrayIndex = 0;
static int thirdArrayIndex = 0;
static int fourArrayIndex = 0;
static int fiveArrayIndex = 0;

CreateScene1::~CreateScene1()
{
}

void CreateScene1::Init(HWND hWnd)
{

	IMG_MGR->FileFindDir(L".\\Img\\CreateScene1\\");
	SOUND_MGR->FileFindDir(L".\\Sound\\");

	p_player = &m_player;
	//m_player.PutLongcoat();

	m_player.m_isCreate = true;

	m_player.m_CharacInfo.m_Base = 100;
	m_player.m_CharacInfo.m_Face = 23000;
	m_player.m_CharacInfo.m_Hair = 30000;
	m_player.m_CharacInfo.m_Coat = 200;
	m_player.m_CharacInfo.m_Shoes = 1072833;
	m_player.m_CharacInfo.m_Weapon = 1322005;

	m_player.m_CharacInfo.m_X = 200;
	m_player.m_CharacInfo.m_Y = 900;
	m_player.m_CharacInfo.m_Map = MNAME_COKETOWN;

	//m_player.m_CharacInfo.m_Name = "Test";
	m_player.m_CharacInfo.m_Level = 1;
	m_player.m_CharacInfo.m_Exp = 0.0f;
	m_player.m_CharacInfo.m_Pants = 0;
	m_player.m_CharacInfo.m_HP = 200;
	m_player.m_CharacInfo.m_HPmax = 200;
	m_player.m_CharacInfo.m_MP = 200;
	m_player.m_CharacInfo.m_MPmax = 200;

	m_player.m_CharacInfo.m_STR = 12;
	m_player.m_CharacInfo.m_DEX = 5;
	m_player.m_CharacInfo.m_INT = 4;
	m_player.m_CharacInfo.m_LUK = 4;

	m_player.Init();
	m_player.SetPos({ 600,433 });
	m_player.SetScale(-1.0f, 1.0f);

	//	mouse default image 
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseDefault"));	//0
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseClick"));		// 1

	//mouse animation
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver0"));		// 2
	obj.m_Renderer.AddBitmap(IMG_MGR->GetImage(L"mouseOver1"));		// 3
	obj.m_Renderer.AddAnimation(0, 2, 3, 0.5, 0.5);
	obj.m_Renderer.m_State = 0;
	//////////////////////////////////////////////
	//BackGround
	UI_MGR->AddImage("CreateScene1_Background1", L"CreateScene1_Background1", { 0,0,1200,800 });
	//////////////////////////////////////////////
	//default setting

	firstInfoArray[0] = { "활기찬 모험가 얼굴", (size_t)23000 };
	firstInfoArray[1] = { "용간한 모험가 얼굴", (size_t)23001 };
	firstInfoArray[2] = { "도전적인 얼굴", (size_t)20000 };
	firstInfoArray[3] = { "자신있는 얼굴", (size_t)20001 };
	firstInfoArray[4] = { "신중한 얼굴", (size_t)20002 };

	secondInfoArray[0] = { "토벤 머리", 30000 };
	secondInfoArray[1] = { "페리온 헤어", 36780	};
	secondInfoArray[2] = { "커닝시티 헤어", 36790};
	secondInfoArray[3] = { "더벅 머리", 30020	};
	secondInfoArray[4] = { "빡빡 머리", 30030	};

	thirdInfoArray[0] = { "블루 머플러 한벌", (size_t)200};
	thirdInfoArray[1] = { "퍼플 머플러 한벌", (size_t)201 };
	thirdInfoArray[2] = { "레드 머플러 한벌", (size_t)202 };

	fourInfoArray[0] = { "옐로 어드벤쳐 슈즈", 1072833 };
	fourInfoArray[1] = { "퍼플 어드벤쳐 슈즈", 1072834 };

	fiveInfoArray[0] = { "몽둥이", 1322005 };
	fiveInfoArray[1] = { "검", 1302000 };
	fiveInfoArray[2] = { "손도끼", 1312004 };

	////////////////////////////////////////////////
	//Menu
	UI_MGR->AddImage("CreateScene1_Menu", L"CreateScene1_Menu", { 884,411 }, { 1.5f, 1.33333f });
	UI_MGR->FindUI("CreateScene1_Menu")->m_isActive = false;
	//////////////////////////////////////////////
	// arrow  
	// 1 y :: -101
	// 2 y :: -83
	// 3 y :: -47
	// 4 y :: -30
	// 5 y :: -13

	//1
	UI_MGR->AddButton("CreateScene1_LeftArrow_default1", L"CreateScene1_LeftArrow_default", { -43,-101 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_LeftArrow_default1")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_LeftArrow_default1", L"CreateScene1_LeftArrow_Over");
	auto CreateScene1Func_Menu_Arrow1 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default1")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow2 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default1")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow1_Left = [](void) { 
		if (firstArrayIndex > 0)
		{
			firstArrayIndex--;
		}
		else
		{
			firstArrayIndex = 4;
		}
		MK_LOG("%d", firstArrayIndex);

		p_player ->ChangeFace(firstInfoArray[firstArrayIndex].number);
		UI_MGR->FindUI("firstText")->m_Text = firstInfoArray[firstArrayIndex].name;
	};
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default1", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow1);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default1", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow2);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default1", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow1_Left);

	UI_MGR->AddButton("CreateScene_RightArrow_default1", L"CreateScene_RightArrow_default", { 73,-101 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene_RightArrow_default1")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene_RightArrow_default1", L"CreateScene_RightArrow_Over");
	auto CreateScene1Func_Menu_Arrow3 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default1")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow4 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default1")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow1_Right = [](void) {
		if (firstArrayIndex < 4)
		{
			firstArrayIndex++;
		}
		else
		{
			firstArrayIndex = 0;
		}
		MK_LOG("%d", firstArrayIndex);
		p_player->ChangeFace(firstInfoArray[firstArrayIndex].number);
		UI_MGR->FindUI("firstText")->m_Text = firstInfoArray[firstArrayIndex].name;
	};
	UI_MGR->AddEvent("CreateScene_RightArrow_default1", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow3);
	UI_MGR->AddEvent("CreateScene_RightArrow_default1", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow4);
	UI_MGR->AddEvent("CreateScene_RightArrow_default1", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow1_Right);

	//CreateScene1_TextBox
	UI_MGR->AddImage("CreateScene1_TextBox1", L"CreateScene1_TextBox", { 15,-101 }, { 1.1f, 1.0f });
	UI_MGR->AddText("firstText", firstInfoArray[firstArrayIndex].name, { 15,0 });
	UI_MGR->SetParent("CreateScene1_TextBox1", "firstText");
	p_player->ChangeFace(firstInfoArray[firstArrayIndex].number);


	//2
	UI_MGR->AddButton("CreateScene1_LeftArrow_default2", L"CreateScene1_LeftArrow_default", { -43,-83 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_LeftArrow_default2")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_LeftArrow_default2", L"CreateScene1_LeftArrow_Over");
	auto CreateScene1Func_Menu_Arrow5 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default2")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow6 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default2")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow2_Left = [](void) {
		if (secondArrayIndex > 0)
		{
			secondArrayIndex--;
		}
		else
		{
			secondArrayIndex = 4;
		}
		MK_LOG("%d", secondArrayIndex);

		p_player->ChangeHair(secondInfoArray[secondArrayIndex].number);
		UI_MGR->FindUI("secondText")->m_Text = secondInfoArray[secondArrayIndex].name;
	};

	UI_MGR->AddEvent("CreateScene1_LeftArrow_default2", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow5);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default2", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow6);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default2", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow2_Left);

	UI_MGR->AddButton("CreateScene_RightArrow_default2", L"CreateScene_RightArrow_default", { 73,-83 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene_RightArrow_default2")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene_RightArrow_default2", L"CreateScene_RightArrow_Over");
	auto CreateScene1Func_Menu_Arrow7 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default2")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow8 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default2")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow2_Right = [](void) {
		if (secondArrayIndex < 4)
		{
			secondArrayIndex++;
		}
		else
		{
			secondArrayIndex = 0;
		}
		MK_LOG("%d", secondArrayIndex);
		p_player->ChangeHair(secondInfoArray[secondArrayIndex].number);
		UI_MGR->FindUI("secondText")->m_Text = secondInfoArray[secondArrayIndex].name;
	};
	UI_MGR->AddEvent("CreateScene_RightArrow_default2", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow7);
	UI_MGR->AddEvent("CreateScene_RightArrow_default2", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow8);
	UI_MGR->AddEvent("CreateScene_RightArrow_default2", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow2_Right);

	//CreateScene1_TextBox
	UI_MGR->AddImage("CreateScene1_TextBox2", L"CreateScene1_TextBox", { 15,-83 }, { 1.1f, 1.0f });
	UI_MGR->AddText("secondText", secondInfoArray[secondArrayIndex].name, { 15, 25 });
	UI_MGR->SetParent("CreateScene1_TextBox2", "secondText");
	p_player->ChangeHair(secondInfoArray[secondArrayIndex].number);

	//3
	UI_MGR->AddButton("CreateScene1_LeftArrow_default3", L"CreateScene1_LeftArrow_default", { -43,-47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_LeftArrow_default3")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_LeftArrow_default3", L"CreateScene1_LeftArrow_Over");
	auto CreateScene1Func_Menu_Arrow9 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default3")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow10 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default3")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow3_Left = [](void) {
		if (thirdArrayIndex > 0)
		{
			thirdArrayIndex--;
		}
		else
		{
			thirdArrayIndex = 2;
		}
		MK_LOG("%d", thirdArrayIndex);

		p_player->ChangeCoat(thirdInfoArray[thirdArrayIndex].number);
		UI_MGR->FindUI("thirdText")->m_Text = thirdInfoArray[thirdArrayIndex].name;
	};
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default3", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow9);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default3", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow10);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default3", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow3_Left);

	UI_MGR->AddButton("CreateScene_RightArrow_default3", L"CreateScene_RightArrow_default", { 73,-47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene_RightArrow_default3")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene_RightArrow_default3", L"CreateScene_RightArrow_Over");
	auto CreateScene1Func_Menu_Arrow11 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default3")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow12 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default3")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow3_Right = [](void) {
		if (thirdArrayIndex < 2)
		{
			thirdArrayIndex++;
		}
		else
		{
			thirdArrayIndex = 0;
		}
		MK_LOG("%d", thirdArrayIndex);
		p_player->ChangeCoat(thirdInfoArray[thirdArrayIndex].number);
		UI_MGR->FindUI("thirdText")->m_Text = thirdInfoArray[thirdArrayIndex].name;
	};
	UI_MGR->AddEvent("CreateScene_RightArrow_default3", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow11);
	UI_MGR->AddEvent("CreateScene_RightArrow_default3", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow12);
	UI_MGR->AddEvent("CreateScene_RightArrow_default3", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow3_Right);

	UI_MGR->AddImage("CreateScene1_TextBox3", L"CreateScene1_TextBox", { 15,-47 }, { 1.1f, 1.0f });
	UI_MGR->AddText("thirdText", thirdInfoArray[thirdArrayIndex].name, { 15, 70 });
	UI_MGR->SetParent("CreateScene1_TextBox3", "thirdText");
	p_player->ChangeCoat(thirdInfoArray[thirdArrayIndex].number);

	//4
	UI_MGR->AddButton("CreateScene1_LeftArrow_default4", L"CreateScene1_LeftArrow_default", { -43,-30 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_LeftArrow_default4")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_LeftArrow_default4", L"CreateScene1_LeftArrow_Over");
	auto CreateScene1Func_Menu_Arrow13 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default4")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow14 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default4")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow4_Left = [](void) {
		if (fourArrayIndex > 0)
		{
			fourArrayIndex--;
		}
		else
		{
			fourArrayIndex = 1;
		}
		MK_LOG("%d", fourArrayIndex);

		p_player->ChangeShoes(fourInfoArray[fourArrayIndex].number);
		UI_MGR->FindUI("fourText")->m_Text = fourInfoArray[fourArrayIndex].name;
	};

	UI_MGR->AddEvent("CreateScene1_LeftArrow_default4", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow13);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default4", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow14);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default4", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow4_Left);

	UI_MGR->AddButton("CreateScene_RightArrow_default4", L"CreateScene_RightArrow_default", { 73,-30 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene_RightArrow_default4")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene_RightArrow_default4", L"CreateScene_RightArrow_Over");
	auto CreateScene1Func_Menu_Arrow15 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default4")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow16 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default4")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow4_Right = [](void) {
		if (fourArrayIndex < 1)
		{
			fourArrayIndex++;
		}
		else
		{
			fourArrayIndex = 0;
		}
		MK_LOG("%d", fourArrayIndex);
		p_player->ChangeShoes(fourInfoArray[fourArrayIndex].number);
		UI_MGR->FindUI("fourText")->m_Text = fourInfoArray[fourArrayIndex].name;
	};

	UI_MGR->AddEvent("CreateScene_RightArrow_default4", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow15);
	UI_MGR->AddEvent("CreateScene_RightArrow_default4", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow16);
	UI_MGR->AddEvent("CreateScene_RightArrow_default4", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow4_Right);

	UI_MGR->AddImage("CreateScene1_TextBox4", L"CreateScene1_TextBox", { 15,-30 }, { 1.1f, 1.0f });
	UI_MGR->AddText("fourText", fourInfoArray[fourArrayIndex].name, { 15, 95 });
	UI_MGR->SetParent("CreateScene1_TextBox4", "fourText");
	p_player->ChangeShoes(fourInfoArray[fourArrayIndex].number);

	//5
	UI_MGR->AddButton("CreateScene1_LeftArrow_default5", L"CreateScene1_LeftArrow_default", { -43,-13 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_LeftArrow_default5")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_LeftArrow_default5", L"CreateScene1_LeftArrow_Over");
	auto CreateScene1Func_Menu_Arrow17= [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default5")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow18 = [](void) { UI_MGR->FindUI("CreateScene1_LeftArrow_default5")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow5_Left = [](void) {
		if (fiveArrayIndex > 0)
		{
			fiveArrayIndex--;
		}
		else
		{
			fiveArrayIndex = 2;
		}
		MK_LOG("%d", fiveArrayIndex);

		p_player->ChangeWeapon(fiveInfoArray[fiveArrayIndex].number);
		UI_MGR->FindUI("fiveText")->m_Text = fiveInfoArray[fiveArrayIndex].name;
	};
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default5", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow17);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default5", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow18);
	UI_MGR->AddEvent("CreateScene1_LeftArrow_default5", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow5_Left);

	UI_MGR->AddButton("CreateScene_RightArrow_default5", L"CreateScene_RightArrow_default", { 73,-13 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene_RightArrow_default5")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene_RightArrow_default5", L"CreateScene_RightArrow_Over");
	auto CreateScene1Func_Menu_Arrow19 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default5")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_Menu_Arrow20 = [](void) { UI_MGR->FindUI("CreateScene_RightArrow_default5")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_Menu_Arrow5_Right = [](void) {
		if (fiveArrayIndex < 2)
		{
			fiveArrayIndex++;
		}
		else
		{
			fiveArrayIndex = 0;
		}
		MK_LOG("%d", fiveArrayIndex);
		p_player->ChangeWeapon(fiveInfoArray[fiveArrayIndex].number);
		UI_MGR->FindUI("fiveText")->m_Text = fiveInfoArray[fiveArrayIndex].name;
	};
	UI_MGR->AddEvent("CreateScene_RightArrow_default5", ADDEVENT_OnMouseOver, CreateScene1Func_Menu_Arrow19);
	UI_MGR->AddEvent("CreateScene_RightArrow_default5", ADDEVENT_OnMouseExit, CreateScene1Func_Menu_Arrow20);
	UI_MGR->AddEvent("CreateScene_RightArrow_default5", ADDEVENT_OnMouseClick, CreateScene1Func_Menu_Arrow5_Right);
	
	UI_MGR->AddImage("CreateScene1_TextBox5", L"CreateScene1_TextBox", { 15,-13 }, { 1.1f, 1.0f });
	UI_MGR->AddText("fiveText", fiveInfoArray[fiveArrayIndex].name, { 15, 117 });
	UI_MGR->SetParent("CreateScene1_TextBox5", "fiveText");
	p_player->ChangeWeapon(fiveInfoArray[fiveArrayIndex].number);
	
	// arrow end
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	// ColorBox
	UI_MGR->AddButton("CreateScene1_Color_Black_default", L"CreateScene1_Color_Black_default", { -37,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Black_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Black_default", L"CreateScene1_Color_Black_Over");
	auto CreateScene1Func_ColorBlackDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Black_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorBlackOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Black_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorBlackClick = [](void) {
		//if (secondInfoArray) {}
		//UI_MGR->FindUI("CreateScene1_Color_Black_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; 
		//switch (secondArrayIndex)
		//{
		//case 0:
		//{
			p_player->ChangeHair(secondInfoArray[secondArrayIndex].number);
		//}break;



		//}
	};
	UI_MGR->AddEvent("CreateScene1_Color_Black_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorBlackDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Black_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorBlackOver);
	UI_MGR->AddEvent("CreateScene1_Color_Black_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorBlackClick);

	UI_MGR->AddButton("CreateScene1_Color_Red_default", L"CreateScene1_Color_Red_default", { -22,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Red_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Red_default", L"CreateScene1_Color_Red_Over");
	auto CreateScene1Func_ColorRedDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Red_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorRedOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Red_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorRedClick = [](void) {		p_player->ChangeHair((secondInfoArray[secondArrayIndex].number)+1 );	};
	UI_MGR->AddEvent("CreateScene1_Color_Red_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorRedDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Red_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorRedOver);
	UI_MGR->AddEvent("CreateScene1_Color_Red_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorRedClick);

	UI_MGR->AddButton("CreateScene1_Color_Orange_default", L"CreateScene1_Color_Orange_default", { -7,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Orange_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Orange_default", L"CreateScene1_Color_Orange_Over");
	auto CreateScene1Func_ColorOrangeDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Orange_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorOrangeOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Orange_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorOrangeClick = [](void) {		p_player->ChangeHair((secondInfoArray[secondArrayIndex].number) + 2);	};
	UI_MGR->AddEvent("CreateScene1_Color_Orange_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorOrangeDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Orange_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorOrangeOver);
	UI_MGR->AddEvent("CreateScene1_Color_Orange_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorOrangeClick);

	UI_MGR->AddButton("CreateScene1_Color_Yellow_default", L"CreateScene1_Color_Yellow_default", { 8,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Yellow_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Yellow_default", L"CreateScene1_Color_Yellow_Over");
	auto CreateScene1Func_ColorYellowDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Yellow_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorYellowOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Yellow_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorYellowClick = [](void) {		p_player->ChangeHair((secondInfoArray[secondArrayIndex].number) + 3);	};
	UI_MGR->AddEvent("CreateScene1_Color_Yellow_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorYellowDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Yellow_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorYellowOver);
	UI_MGR->AddEvent("CreateScene1_Color_Yellow_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorYellowClick);

	UI_MGR->AddButton("CreateScene1_Color_Green_default", L"CreateScene1_Color_Green_default", { 23,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Green_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Green_default", L"CreateScene1_Color_Green_Over");
	auto CreateScene1Func_ColorGreenDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Green_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorGreenOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Green_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorGreenClick = [](void) {		p_player->ChangeHair((secondInfoArray[secondArrayIndex].number) + 4);	};
	UI_MGR->AddEvent("CreateScene1_Color_Green_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorGreenDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Green_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorGreenOver);
	UI_MGR->AddEvent("CreateScene1_Color_Green_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorGreenClick);

	UI_MGR->AddButton("CreateScene1_Color_Blue_default", L"CreateScene1_Color_Blue_default", { 38,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Blue_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Blue_default", L"CreateScene1_Color_Blue_Over");
	auto CreateScene1Func_ColorBlueDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Blue_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorBlueOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Blue_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorBlueClick = [](void) {		p_player->ChangeHair((secondInfoArray[secondArrayIndex].number) + 5);	};
	UI_MGR->AddEvent("CreateScene1_Color_Blue_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorBlueDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Blue_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorBlueOver);
	UI_MGR->AddEvent("CreateScene1_Color_Blue_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorBlueClick);

	UI_MGR->AddButton("CreateScene1_Color_Purple_default", L"CreateScene1_Color_Purple_default", { 53,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Purple_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Purple_default", L"CreateScene1_Color_Purple_Over");
	auto CreateScene1Func_ColorPurpleDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Purple_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorPurpleOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Purple_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorPurpleClick = [](void) {		p_player->ChangeHair((secondInfoArray[secondArrayIndex].number) + 6);	};
	UI_MGR->AddEvent("CreateScene1_Color_Purple_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorPurpleDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Purple_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorPurpleOver);
	UI_MGR->AddEvent("CreateScene1_Color_Purple_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorPurpleClick);

	UI_MGR->AddButton("CreateScene1_Color_Brown_default", L"CreateScene1_Color_Brown_default", { 68,-66 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("CreateScene1_Color_Brown_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Color_Brown_default", L"CreateScene1_Color_Brown_Over");
	auto CreateScene1Func_ColorBrownDefault = [](void) { UI_MGR->FindUI("CreateScene1_Color_Brown_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_ColorBrownOver = [](void) { UI_MGR->FindUI("CreateScene1_Color_Brown_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_ColorBrownClick = [](void) {		p_player->ChangeHair((secondInfoArray[secondArrayIndex].number) + 7);	};
	UI_MGR->AddEvent("CreateScene1_Color_Brown_default", ADDEVENT_OnMouseOver, CreateScene1Func_ColorBrownDefault);
	UI_MGR->AddEvent("CreateScene1_Color_Brown_default", ADDEVENT_OnMouseExit, CreateScene1Func_ColorBrownOver);
	UI_MGR->AddEvent("CreateScene1_Color_Brown_default", ADDEVENT_OnMouseClick, CreateScene1Func_ColorBrownClick);

	// ColorBox end
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	//				부모설정
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_LeftArrow_default1");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene_RightArrow_default1");

	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_LeftArrow_default2");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene_RightArrow_default2");

	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_LeftArrow_default3");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene_RightArrow_default3");

	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_LeftArrow_default4");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene_RightArrow_default4");

	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_LeftArrow_default5");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene_RightArrow_default5");

	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Black_default");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Red_default");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Orange_default");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Yellow_default");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Green_default");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Blue_default");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Purple_default");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_Color_Brown_default");

	//CreateScene1_TextBox
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_TextBox1");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_TextBox2");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_TextBox3");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_TextBox4");
	UI_MGR->SetParent("CreateScene1_Menu", "CreateScene1_TextBox5");

	//				부모설정 end
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	//MaleSelect
	UI_MGR->AddButton("CreateScene1_MaleSelect_default", L"CreateScene1_MaleSelect_default", { 820,355 }, { 1.5f, 1.33333f });
	UI_MGR->FindUI("CreateScene1_MaleSelect_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_MaleSelect_default", L"CreateScene1_MaleSelect_Over");
	auto CreateScene1Func_MaleSelect0 = [](void) { UI_MGR->FindUI("CreateScene1_MaleSelect_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func_MaleSelect1 = [](void) { UI_MGR->FindUI("CreateScene1_MaleSelect_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1Func_MaleSelect2 = [](void) { 
	UI_MGR->FindUI("CreateScene1_MaleSelect_default")->m_isActive = false;
	UI_MGR->FindUI("CreateScene1_Menu")->m_isActive = true;
	UI_MGR->FindUI("CreateScene1_Ok1_default")->m_Transform.SetPos(831, 519);
	UI_MGR->FindUI("CreateScene1_No1_default")->m_Transform.SetPos(942, 520);
	};
	UI_MGR->AddEvent("CreateScene1_MaleSelect_default", ADDEVENT_OnMouseOver, CreateScene1Func_MaleSelect0);
	UI_MGR->AddEvent("CreateScene1_MaleSelect_default", ADDEVENT_OnMouseExit, CreateScene1Func_MaleSelect1);
	UI_MGR->AddEvent("CreateScene1_MaleSelect_default", ADDEVENT_OnMouseClick, CreateScene1Func_MaleSelect2);

	//확인
	UI_MGR->AddButton("CreateScene1_Ok1_default", L"CreateScene1_Ok1_default", { 831,552 }, { 1.5f, 1.33333f });
	UI_MGR->FindUI("CreateScene1_Ok1_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_Ok1_default", L"CreateScene1_Ok1_Over");
	auto CreateScene1Func2 = [](void) { UI_MGR->FindUI("CreateScene1_Ok1_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1Func3 = [](void) { UI_MGR->FindUI("CreateScene1_Ok1_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };

	auto InGameScene = [](void) { 

		//DATA_MGR->Create_Character(p_player->m_CharacInfo);
		//DATA_MGR->m_CharacterName = p_player->m_CharacInfo.m_Name;

		//SCENE_MGR->ChangeScene(SCENE_LOBBY);

		UI_MGR->FindUI("CreateScene1_Menu")->m_isActive = false;
		UI_MGR->FindUI("캐릭터이름")->m_isActive = true;
		UI_MGR->FindUI("캐릭터이름_인풋필드")->m_isActive = true;

		UI_MGR->DrawFirst(UI_MGR->FindUI("캐릭터이름"));
		UI_MGR->DrawFirst(UI_MGR->FindUI("캐릭터이름_인풋필드"));

		//UI_MGR->FindUI("CreateScene1_Ok1_default")->m_Transform.SetPos(831, 352);
		//UI_MGR->FindUI("CreateScene1_No1_default")->m_Transform.SetPos(943, 352);
	
	};
	UI_MGR->AddEvent("CreateScene1_Ok1_default", ADDEVENT_OnMouseOver, CreateScene1Func2);
	UI_MGR->AddEvent("CreateScene1_Ok1_default", ADDEVENT_OnMouseExit, CreateScene1Func3);
	UI_MGR->AddEvent("CreateScene1_Ok1_default", ADDEVENT_OnMouseClick, InGameScene);
	
	//취소
	UI_MGR->AddButton("CreateScene1_No1_default", L"CreateScene1_No1_default", { 943,552 }, { 1.5f, 1.33333f });
	UI_MGR->FindUI("CreateScene1_No1_default")->m_RayCast = true;
	UI_MGR->BitMapAdd("CreateScene1_No1_default", L"CreateScene1_No1_Over");
	auto CreateScene1_No0 = [](void) { UI_MGR->FindUI("CreateScene1_No1_default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene1_No1 = [](void) { UI_MGR->FindUI("CreateScene1_No1_default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	auto CreateScene1_No2 = [](void) { 
		if (UI_MGR->FindUI("CreateScene1_Menu")->m_isActive == true)
		{
			UI_MGR->FindUI("CreateScene1_Menu")->m_isActive = false;
			UI_MGR->FindUI("CreateScene1_MaleSelect_default")->m_isActive = true;
			UI_MGR->FindUI("CreateScene1_Ok1_default")->m_Transform.SetPos(831, 552);
			UI_MGR->FindUI("CreateScene1_No1_default")->m_Transform.SetPos(943, 552);
		}
	};
	UI_MGR->AddEvent("CreateScene1_No1_default", ADDEVENT_OnMouseOver, CreateScene1_No0);
	UI_MGR->AddEvent("CreateScene1_No1_default", ADDEVENT_OnMouseExit, CreateScene1_No1);
	UI_MGR->AddEvent("CreateScene1_No1_default", ADDEVENT_OnMouseClick, CreateScene1_No2);


	// 캐릭터 이름

	UI_MGR->AddImage("캐릭터이름", L"CreateScene_Name", { 884, 415 }, { 1.5f, 1.33333f },1.0f, true);
	UI_MGR->FindUI("캐릭터이름")->m_isActive = false;
	UI_MGR->AddInputField("캐릭터이름_인풋필드", L"CreateScene1_IF", { 884, 281 }, {1.5f,1.33333f}, ColorF(ColorF::White), L"고딕", 1.0f, 15.0f);
	UI_MGR->FindUI("캐릭터이름_인풋필드")->m_isActive = false;

	//확인
	UI_MGR->AddButton("캐릭터이름_확인", L"CreateScene1_Ok1_default", { -36, -18 }, { 1.0f, 1.0f });

	UI_MGR->BitMapAdd("캐릭터이름_확인", L"CreateScene1_Ok1_Over");
	auto CNO1 = [](void) { UI_MGR->FindUI("캐릭터이름_확인")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CNO2 = [](void) { UI_MGR->FindUI("캐릭터이름_확인")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };

	auto CNO3 = [](void) {

		UI_MGR->FindUI("캐릭터이름")->m_isActive = false;
		UI_MGR->FindUI("캐릭터이름_인풋필드")->m_isActive = false;

		p_player->m_CharacInfo.m_Name = UI_MGR->FindUI("캐릭터이름_인풋필드")->m_SonUI[0]->m_Text;

		DATA_MGR->Create_Character(p_player->m_CharacInfo);
		DATA_MGR->m_CharacterName = p_player->m_CharacInfo.m_Name;

		SCENE_MGR->ChangeScene(SCENE_LOBBY);

		
	};
	UI_MGR->AddEvent("캐릭터이름_확인", ADDEVENT_OnMouseOver, CNO1);
	UI_MGR->AddEvent("캐릭터이름_확인", ADDEVENT_OnMouseExit, CNO2);
	UI_MGR->AddEvent("캐릭터이름_확인", ADDEVENT_OnMouseClick, CNO3);

	UI_MGR->SetParent("캐릭터이름", "캐릭터이름_확인");

	//취소
	UI_MGR->AddButton("캐릭터이름_취소", L"CreateScene1_No1_default", { 38, -18 }, { 1.0f, 1.0f });

	UI_MGR->BitMapAdd("캐릭터이름_취소", L"CreateScene1_No1_Over");
	auto CNC1 = [](void) { UI_MGR->FindUI("캐릭터이름_취소")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CNC2 = [](void) { UI_MGR->FindUI("캐릭터이름_취소")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };

	auto CNC3 = [](void) {

		UI_MGR->FindUI("캐릭터이름")->m_isActive = false;
		UI_MGR->FindUI("캐릭터이름_인풋필드")->m_isActive = false;
	};
	UI_MGR->AddEvent("캐릭터이름_취소", ADDEVENT_OnMouseOver, CNC1);
	UI_MGR->AddEvent("캐릭터이름_취소", ADDEVENT_OnMouseExit, CNC2);
	UI_MGR->AddEvent("캐릭터이름_취소", ADDEVENT_OnMouseClick, CNC3);

	UI_MGR->SetParent("캐릭터이름", "캐릭터이름_취소");

	//UI_MGR->SetParent("캐릭터이름", "캐릭터이름_인풋필드");

	//이전으로
	UI_MGR->AddButton("ChannelReturn_Default", L"LobbyScene_ChannelReturn_Default", { 59,694 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("ChannelReturn_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("ChannelReturn_Default", L"LobbyScene_ChannelReturn_Over");
	auto CreateScene0_Func10 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func11 = [](void) { UI_MGR->FindUI("ChannelReturn_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseOver, CreateScene0_Func10);
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseExit, CreateScene0_Func11);
	auto CreateScene0_Func16 = [](void) {SCENE_MGR->ChangeScene(SCENE_CREATE0); };
	UI_MGR->AddEvent("ChannelReturn_Default", ADDEVENT_OnMouseClick, CreateScene0_Func16);


	//처음으로
	UI_MGR->AddButton("returnLogin_Default", L"ChannelScene_returnLogin_Default", { 59,747 }, { 1.50f, 1.33333f });
	UI_MGR->FindUI("returnLogin_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnLogin_Default", L"ChannelScene_returnLogin_Over");
	auto CreateScene0_Func8 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func9 = [](void) { UI_MGR->FindUI("returnLogin_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseOver, CreateScene0_Func8);
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseExit, CreateScene0_Func9);


	UI_MGR->AddButton("returnPage", L"ChannelScene_returnPage", { 600,400 }, { 1.50f, 1.33333f });

	UI_MGR->AddButton("returnPage_no_Default", L"ChannelScene_returnPage_no_Default", { 30,47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("returnPage_no_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_no_Default", L"ChannelScene_returnPage_no_Over");
	auto CreateScene0_Func1 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func2 = [](void) { UI_MGR->FindUI("returnPage_no_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseOver, CreateScene0_Func1);
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseExit, CreateScene0_Func2);

	UI_MGR->AddButton("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Default", { -30,47 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("returnPage_ok_Default")->m_RayCast = true;
	UI_MGR->BitMapAdd("returnPage_ok_Default", L"ChannelScene_returnPage_ok_Over");
	auto CreateScene0_Func3 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto CreateScene0_Func4 = [](void) { UI_MGR->FindUI("returnPage_ok_Default")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseOver, CreateScene0_Func3);
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseExit, CreateScene0_Func4);
	UI_MGR->SetParent("returnPage", "returnPage_no_Default");
	UI_MGR->SetParent("returnPage", "returnPage_ok_Default");
	UI_MGR->FindUI("returnPage")->m_isActive = false;
	auto CreateScene0_Func5 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = true; };
	UI_MGR->AddEvent("returnLogin_Default", ADDEVENT_OnMouseClick, CreateScene0_Func5);
	auto CreateScene0_Func6 = [](void) { UI_MGR->FindUI("returnPage")->m_isActive = false; };
	UI_MGR->AddEvent("returnPage_no_Default", ADDEVENT_OnMouseClick, CreateScene0_Func6);
	auto CreateScene0_Func7 = [](void) {SCENE_MGR->ChangeScene(SCENE_LOGIN); };
	UI_MGR->AddEvent("returnPage_ok_Default", ADDEVENT_OnMouseClick, CreateScene0_Func7);


	//============================================================================================
	//게임 종료 창
	UI_MGR->AddButton("gameEnd", L"Game_End", { 600,400 }, { 1.50f, 1.33333f });

	// 취소 버튼
	UI_MGR->AddButton("gameEnd_No", L"ChannelScene_returnPage_no_Default", { 30,47 }, { 1.0f, 1.0f });
	UI_MGR->FindUI("gameEnd_No")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameEnd_No", L"ChannelScene_returnPage_no_Over");
	auto End_Func0 = [](void) { UI_MGR->FindUI("gameEnd_No")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto End_Func1 = [](void) { UI_MGR->FindUI("gameEnd_No")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseOver, End_Func0);
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseExit, End_Func1);

	// 확인 버튼
	UI_MGR->AddButton("gameEnd_Ok", L"ChannelScene_returnPage_ok_Default", { -30,47 }, { 1.0f, 1.0 });
	UI_MGR->FindUI("gameEnd_Ok")->m_RayCast = true;
	UI_MGR->BitMapAdd("gameEnd_Ok", L"ChannelScene_returnPage_ok_Over");
	auto End_Func2 = [](void) { UI_MGR->FindUI("gameEnd_Ok")->m_Renderer.ChangeBitmap(1); checkEvent = true; };
	auto End_Func3 = [](void) { UI_MGR->FindUI("gameEnd_Ok")->m_Renderer.ChangeBitmap(0);  checkEvent = false; };
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseOver, End_Func2);
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseExit, End_Func3);

	// 부모 설정
	UI_MGR->SetParent("gameEnd", "gameEnd_No");
	UI_MGR->SetParent("gameEnd", "gameEnd_Ok");
	// 초기값 안보이게
	UI_MGR->FindUI("gameEnd")->m_isActive = false;

	//게임 종료 취소 이벤트
	auto End_Func5 = [](void) { UI_MGR->FindUI("gameEnd")->m_isActive = false; };
	UI_MGR->AddEvent("gameEnd_No", ADDEVENT_OnMouseClick, End_Func5);
	//게임 종료 확인 이벤트
	auto End_Func6 = [](void) {		DATA_MGR->AllMgrDestroy();  PostQuitMessage(WM_DESTROY); };
	UI_MGR->AddEvent("gameEnd_Ok", ADDEVENT_OnMouseClick, End_Func6);
	//============
}

void CreateScene1::Update(float _DelayTime)
{
	if (UI_MGR->m_ExitField == true)
	{
		m_szBuf = "";
		m_szMixingString[0] = NULL;

		UI_MGR->m_ExitField = false;

	}

	UI_MGR->Update(_DelayTime);

	m_player.UpdateCreateSceneIdle(_DelayTime);
	//m_player2.Update(_DelayTime);
	obj.Update(_DelayTime);

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (UI_MGR->m_isChating == false)
		{
			UI_MGR->m_isChating = true;
		}
	}
}

void CreateScene1::Render()
{

	UI_MGR->Render();
	m_player.Render();
	//m_player2.Render();
	obj.Render();
}

void CreateScene1::SendText()
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

LRESULT CreateScene1::MyWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		//case WM_SETCURSOR: SetCursor(NULL); break;

	case WM_MOUSEMOVE:
	{
		m_MousePos.x = GET_X_LPARAM(lParam);
		m_MousePos.y = GET_Y_LPARAM(lParam);

		obj.m_Transform.SetPos((float)m_MousePos.x + 11.0f, (float)m_MousePos.y + 12.0f);

		if (checkEvent)
		{
			obj.m_Renderer.m_State = 0;
		}
		else
		{
			obj.m_Renderer.m_State = -1;
			obj.m_Renderer.ChangeBitmap(0);
		}

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
		//SOUND_MGR->SoundResume(L"btMouseClick");
		obj.m_Renderer.m_State = -1;
		obj.m_Renderer.ChangeBitmap(1);
		MK_LOG("%d, %d 클릭", m_MousePos.x, m_MousePos.y);

		UI_MGR->OnMouseDown(m_MousePos);

		m_isClicked = true;

	}break;

	case WM_LBUTTONUP:
	{
		//obj.m_Renderer.ChangeBitmap(0);
		if (checkEvent)
		{
			obj.m_Renderer.m_State = 0;
			//obj.m_Renderer.AddAnimation(PLAYER_IDLE, 2, 3, 0.5, 0.5);

		}
		else
		{
			obj.m_Renderer.m_State = -1;
			obj.m_Renderer.ChangeBitmap(0);
		}
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
	//==================================================================================================
	// 게임 종료
	case WM_CLOSE:
		UI_MGR->FindUI("gameEnd")->m_isActive = true;
		return 0;
		/*default:
		return FALSE;*/
		//====
	}



	return (DefWindowProcA(hWnd, iMessage, wParam, lParam));
}

