////#include "SplashScreen.h"
//
#include "FvZoneTest.h"
#include <FvCommand.h>
#include "FvFlora.h"
void ToPos(char* ch)
{
	int i=0;
	while (ch[i]!='\0'&& i<127)
	{
		if (ch[i]=='/')
		{
			ch[i]=' ';
		}
		if (ch[i]=='+')
		{
			ch[i]='-';
		}
		i++;
	}
}
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE hOtherInst, LPSTR pcCmdLine, INT iMode)
{
	FvCommand kCommand(pcCmdLine);
	char acT[128] = {0};
	char Pos[128] = {0};
	float Time = 10.0f;
	FvVector3 KPos(0.0f,0.0f,30.0f);
	kCommand.String("WorkMap",acT,128);
	kCommand.String("XYZ",Pos,128);
	kCommand.Float("Time",Time);
	ToPos(Pos);
	sscanf( Pos, "%f%f%f", &KPos.x, &KPos.y, &KPos.z );
	
	FILE* pkFile = fopen("GraphicTest.xml","rb");
	if(pkFile)
	{
		Ogre::DataStreamPtr spDataStream(OGRE_NEW Ogre::FileHandleDataStream(pkFile));
		FvXMLSectionPtr spAvatarSec = FvXMLSection::OpenSection(spDataStream);
		
		
		TestApplication::SetInstanceReference(hInst);
		TestApplication::SetAcceleratorReference(hOtherInst);
		TestApplication::SetCommandLine(pcCmdLine);
		FvGameTimer::Create(1);

		TestApplication *pkApp = new TestApplication;
		FvString PathConfigFile = spAvatarSec->GetAttributeString(FvString("ConfigFile"),FvString("Path"));
		FvString PathData       = spAvatarSec->GetAttributeString(FvString("DataPath"),FvString("Path"));
		FvString PathCursorFile = spAvatarSec->GetAttributeString(FvString("CursorFile"),FvString("Path"));
		FvString PathAnimShell  = spAvatarSec->GetAttributeString(FvString("AnimShell"),FvString("Path"));
		FvString PathAvatarRes  = spAvatarSec->GetAttributeString(FvString("AvatarRes"),FvString("Path"));
		pkApp->m_GameUnit.m_spd = spAvatarSec->GetAttributeFloat(FvString("Spd"),FvString("Value"),10.0f);
		if(pkApp->Initialize(PathConfigFile.c_str(),PathData.c_str(),PathCursorFile.c_str()))//��ʼ��
		{
			pkApp->MouseSpd=10.0f;
			pkApp->kPos=Vector3(KPos.x,KPos.y,KPos.z);
			pkApp->CreateSpace(PathAnimShell.c_str(),acT);//����������WorkMap��ʾ�������·��
			pkApp->RefreshPlayerAvatar(1,1,1,1,1);//�������� ����������һЩ���ͻ���ͷ����ID
			pkApp->m_GameUnit.SetAvatar(PathAvatarRes.c_str(),PathAnimShell.c_str());//���ﶯ��
			pkApp->m_GameUnit.Initialize();//���������һЩ��ʼ������
			pkApp->m_GameUnit.SetPos(KPos);
			pkApp->CreateController();//����������
			pkApp->m_Time = Time;
			pkApp->FreeCamera=false;
			FvGraphicsCommon::SetClock(Time);//����ʱ��
			FvFlora::Enabled(false);
			pkApp->pkAttachment->SetPosition(KPos);
			pkApp->MainLoop();
		}

		pkApp->Terminate();
		delete pkApp;
	}
	
}
