
#ifndef __PlayerDefine_H__
#define __PlayerDefine_H__

#include "ScriptEntityDefine.h"
#include "GameUnitDefine.h"
//#include "ScriptFvDataType.h"
#include <string>
#include <FvDataObj.h>
#include <CEGUIInputEvent.h>

class PlayerDefine
{
public:
	enum _SettingConfig
	{
		HOTKEY_MOVING_FRONT	,//	ǰ��			�ƶ�����
		HOTKEY_MOVING_BACK	,//	����	
		HOTKEY_TURNING_LEFT	,//	��ת	
		HOTKEY_TURNING_RIGHT	,//	��ת	
		HOTKEY_MOVING_LEFT	,//	����ƽ��	
		HOTKEY_MOVING_RIGHT	,//	����ƽ��	
		HOTKEY_JUMPED	,//	��Ծ	
		HOTKEY_SWITCH_RUN_WALK	,//	��/��	
		HOTKEY_KEEPON_MOVE	,//	�����ƶ�	
		HOTKEY_SITDOWN	,//	����	
		HOTKEY_ACTION_RESERVE_0	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_1	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_2	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_3	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_4	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_5	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_6	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_7	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_8	,//	Ԥ��	
		HOTKEY_ACTION_RESERVE_9	,//	Ԥ��	
		HOTKEY_PET_ACTIVE	,//	������������			���ﰴ��
		HOTKEY_PET_PASSIVE	,//	���ﱻ������	
		HOTKEY_PET_FOLLOW	,//	�������	
		HOTKEY_PET_RESERVE_0	,//	Ԥ��	
		HOTKEY_PET_RESERVE_1	,//	Ԥ��	
		HOTKEY_PET_RESERVE_2	,//	Ԥ��	
		HOTKEY_PET_RESERVE_3	,//	Ԥ��	
		HOTKEY_PET_RESERVE_4	,//	Ԥ��	
		HOTKEY_PET_RESERVE_5	,//	Ԥ��	
		HOTKEY_PET_RESERVE_6	,//	Ԥ��	
		HOTKEY_PET_RESERVE_7	,//	Ԥ��	
		HOTKEY_PET_RESERVE_8	,//	Ԥ��	
		HOTKEY_PET_RESERVE_9	,//	Ԥ��	
		HOTKEY_DANCE	,//	����				 ���鰴��
		HOTKEY_CRY	,//	���	
		HOTKEY_ANGRY	,//	����	
		HOTKEY_KNEEL	,//	����	
		HOTKEY_WORSHIP	,//	����	
		HOTKEY_ROLL	,//	����ͷ	
		HOTKEY_RAGE	,//	��ŭ	
		HOTKEY_DREAD	,//	�־�	
		HOTKEY_EMOTION_RESERVE_0	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_1	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_2	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_3	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_4	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_5	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_6	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_7	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_8	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_9	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_10	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_11	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_12	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_13	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_14	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_15	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_16	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_17	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_18	,//	Ԥ��	
		HOTKEY_EMOTION_RESERVE_19	,//	Ԥ��	
		HOTKEY_UI_MAIN	,//	��/�ر�������				���水��
		HOTKEY_UI_CHARATAR	,//	��/�رս�ɫ����	
		HOTKEY_UI_PET	,//	��/�رճ������	
		HOTKEY_UI_BAG	,//	��/�رյ��߽���	
		HOTKEY_UI_SKILL	,//	��/�رռ��ܽ���	
		HOTKEY_UI_RELIGION	,//	��/�ر���������	
		HOTKEY_UI_QUEST	,//	��/�ر��������	
		HOTKEY_UI_HELP	,//	��/�رհ�������	
		HOTKEY_UI_MAP	,//	��/�رյ�ͼ����	
		HOTKEY_UI_MARKET	,//	��/�ر��̳ǽ���	
		HOTKEY_UI_PROCESSION	,//	��/�ر��Ŷӽ���	
		HOTKEY_UI_SOCIALITY	,//	��/�ر��罻����	
		HOTKEY_UI_GUIILD	,//	��/�رչ������	
		HOTKEY_UI_RANKING	,//	��/�ر���������	
		HOTKEY_UI_SYSTEM	,//	��/�ر�ϵͳ�˵�	
		HOTKEY_UI_CHAT	,//	��/�ر��������	
		HOTKEY_UI_RESERVE_0	,//	Ԥ��	
		HOTKEY_UI_RESERVE_1	,//	Ԥ��	
		HOTKEY_UI_RESERVE_2	,//	Ԥ��	
		HOTKEY_UI_RESERVE_3	,//	Ԥ��	
		HOTKEY_UI_RESERVE_4	,//	Ԥ��	
		HOTKEY_UI_RESERVE_5	,//	Ԥ��	
		HOTKEY_UI_RESERVE_6	,//	Ԥ��	
		HOTKEY_UI_RESERVE_7	,//	Ԥ��	
		HOTKEY_UI_RESERVE_8	,//	Ԥ��	
		HOTKEY_UI_RESERVE_9	,//	Ԥ��	
		HOTKEY_PRINTSCREEN	,//	��ͼ��	
		HOTKEY_MUSIC	,//	��/�رձ�������			��������
		HOTKEY_SOUND	,//	��/�ر���Ϸ��Ч	
		HOTKEY_VOLUME_UP	,//	���������	
		HOTKEY_VOLUME_DOWN	,//	����������	
		HOTKEY_SOUND_RESERVE_0	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_1	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_2	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_3	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_4	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_5	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_6	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_7	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_8	,//	Ԥ��	
		HOTKEY_SOUND_RESERVE_9	,//	Ԥ��	
		HOTKEY_SHORTCUT_0	,//	��ݼ�1				��ݰ���
		HOTKEY_SHORTCUT_1	,//	��ݼ�2	
		HOTKEY_SHORTCUT_2	,//	��ݼ�3	
		HOTKEY_SHORTCUT_3	,//	��ݼ�4	
		HOTKEY_SHORTCUT_4	,//	��ݼ�5	
		HOTKEY_SHORTCUT_5	,//	��ݼ�6	
		HOTKEY_SHORTCUT_6	,//	��ݼ�7	
		HOTKEY_SHORTCUT_7	,//	��ݼ�8	
		HOTKEY_SHORTCUT_8	,//	��ݼ�9	
		HOTKEY_SHORTCUT_9	,//	��ݼ�10	
		HOTKEY_SHORTCUT_10	,//	��ݼ�11	
		HOTKEY_SHORTCUT_11	,//	��ݼ�12	
		HOTKEY_SHORTCUT_12	,//	��ݼ�13	
		HOTKEY_SHORTCUT_13	,//	��ݼ�14	
		HOTKEY_SHORTCUT_14	,//	��ݼ�15	
		HOTKEY_SHORTCUT_15	,//	��ݼ�16	
		HOTKEY_SHORTCUT_16	,//	��ݼ�17	
		HOTKEY_SHORTCUT_17	,//	��ݼ�18	
		HOTKEY_SHORTCUT_18	,//	��ݼ�19	
		HOTKEY_SHORTCUT_19	,//	��ݼ�20	
		HOTKEY_SHORTCUT_20	,//	��ݼ�21	
		HOTKEY_SHORTCUT_21	,//	��ݼ�22	
		HOTKEY_SHORTCUT_22	,//	��ݼ�23	
		HOTKEY_SHORTCUT_23	,//	��ݼ�24	
		HOTKEY_SHORTCUT_24	,//	��ݼ�25	
		HOTKEY_SHORTCUT_25	,//	��ݼ�26	
		HOTKEY_SHORTCUT_26	,//	��ݼ�27	
		HOTKEY_SHORTCUT_27	,//	��ݼ�28	
		HOTKEY_SHORTCUT_28	,//	��ݼ�29	
		HOTKEY_SHORTCUT_29	,//	��ݼ�30	
		HOTKEY_SHORTCUT_30	,//	��ݼ�31	
		HOTKEY_SHORTCUT_31	,//	��ݼ�32	
		HOTKEY_SHORTCUT_32	,//	��ݼ�33	
		HOTKEY_SHORTCUT_33	,//	��ݼ�34	
		HOTKEY_SHORTCUT_34	,//	��ݼ�35	
		HOTKEY_SHORTCUT_35	,//	��ݼ�36	
		HOTKEY_SHORTCUT_36	,//	��ݼ�37	
		HOTKEY_SHORTCUT_37	,//	��ݼ�38	
		HOTKEY_SHORTCUT_38	,//	��ݼ�39	
		HOTKEY_SHORTCUT_39	,//	��ݼ�40	
		HOTKEY_SHORTCUT_40	,//	��ݼ�41	
		HOTKEY_SHORTCUT_41	,//	��ݼ�42	
		HOTKEY_SHORTCUT_42	,//	��ݼ�43	
		HOTKEY_SHORTCUT_43	,//	��ݼ�44	
		HOTKEY_SHORTCUT_44	,//	��ݼ�45	
		HOTKEY_SHORTCUT_45	,//	��ݼ�46	
		HOTKEY_SHORTCUT_46	,//	��ݼ�47	
		HOTKEY_SHORTCUT_47	,//	��ݼ�48	
		HOTKEY_SHORTCUT_48	,//	��ݼ�49	
		HOTKEY_SHORTCUT_49	,//	��ݼ�50	
		HOTKEY_SHORTCUT_50	,//	��ݼ�51	
		HOTKEY_SHORTCUT_51	,//	��ݼ�52	
		HOTKEY_SHORTCUT_52	,//	��ݼ�53	
		HOTKEY_SHORTCUT_53	,//	��ݼ�54	
		HOTKEY_SHORTCUT_54	,//	��ݼ�55	
		HOTKEY_SHORTCUT_55	,//	��ݼ�56	
		HOTKEY_SHORTCUT_56	,//	��ݼ�57	
		HOTKEY_SHORTCUT_57	,//	��ݼ�58	
		HOTKEY_SHORTCUT_58	,//	��ݼ�59	
		HOTKEY_SHORTCUT_59	,//	��ݼ�60	
		HOTKEY_SHORTCUT_60	,//	��ݼ�61	
		HOTKEY_SHORTCUT_61	,//	��ݼ�62	
		HOTKEY_SHORTCUT_62	,//	��ݼ�63	
		HOTKEY_SHORTCUT_63	,//	��ݼ�64	
		HOTKEY_SHORTCUT_RESERVE_0	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_1	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_2	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_3	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_4	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_5	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_6	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_7	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_8	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_9	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_10	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_11	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_12	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_13	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_14	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_15	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_16	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_17	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_18	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_19	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_20	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_21	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_22	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_23	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_24	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_25	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_26	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_27	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_28	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_29	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_30	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_31	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_32	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_33	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_34	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_35	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_36	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_37	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_38	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_39	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_40	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_41	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_42	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_43	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_44	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_45	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_46	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_47	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_48	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_49	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_50	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_51	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_52	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_53	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_54	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_55	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_56	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_57	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_58	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_59	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_60	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_61	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_62	,//	Ԥ��	
		HOTKEY_SHORTCUT_RESERVE_63	,//	Ԥ��	
		HOTKEY_ENTER	,//	��������������				���찴��
		HOTKEY_RESPOND	,//	���ٻظ��������	
		HOTKEY_INPUT_TEXT_PAGE_UP	,//	��������ı��Ϸ�	
		HOTKEY_INPUT_TEXT_PAGE_DOWN	,//	��������ı��·�	
		HOTKEY_LOG_PAGE_UP	,//	�����¼���Ϸ�ҳ	
		HOTKEY_LOG_PAGE_DOWN	,//	�����¼���·�ҳ	
		HOTKEY_LOG_PAGE_LAST	,//	�����¼�������¶�	
		HOTKEY_FIGHT_LOG	,//	��/�ر�ս����־	
		HOTKEY_FIGHT_LOG_PAGE_UP	,//	ս����־���Ϸ�ҳ	
		HOTKEY_FIGHT_LOG_PAGE_DOWN	,//	ս����־���·�ҳ	
		HOTKEY_FIGHT_LOG_PAGE_LAST	,//	ս����־�������¶�	
		HOTKEY_SELECT_CLOSEST_ENEMY	,//	ѡ������ĵ���				Ŀ�갴��
		HOTKEY_SELECT_CLOSEST_FRIEND	,//	ѡ��������Ѿ�	
		HOTKEY_SELECT_TARGET_TARGET	,//	ѡ��Ŀ���Ŀ��	
		HOTKEY_SELECT_CLOSEST_ENEMY_PLAYER	,//	ѡ������ĵж����	
		HOTKEY_SELECT_PREVIOUS_ENEMY_PLAYER	,//	ѡ����һ���ж����	
		HOTKEY_SELECT_CLOSEST_FRIEND_PLAYER	,//	ѡ��������ѷ����	
		HOTKEY_SELECT_PREVIOUS_FRIEND_PLAYER	,//	ѡ����һ���ѷ����	
		HOTKEY_SELECT_MEMBER_SELF	,//	ѡ���Լ�	
		HOTKEY_SELECT_MEMBER_FIRST	,//	ѡ���һ������	
		HOTKEY_SELECT_MEMBER_SECOND	,//	ѡ��ڶ�������	
		HOTKEY_SELECT_MEMBER_THIRD	,//	ѡ�����������	
		HOTKEY_SELECT_MEMBER_LAST	,//	ѡ����ĸ�����	
		HOTKEY_SELECT_PET_SELF	,//	ѡ���Լ�����	
		HOTKEY_SELECT_PET_FIRST	,//	ѡ���һ���ѳ���	
		HOTKEY_SELECT_PET_SECOND	,//	ѡ��ڶ����ѳ���	
		HOTKEY_SELECT_PET_THIRD	,//	ѡ��������ѳ���	
		HOTKEY_SELECT_PET_LAST	,//	ѡ����Ķ��ѳ���	
		HOTKEY_SHOW_PLAYER	,//	��ʾ/�����������	
		HOTKEY_ZOOM_IN	,//	�����ӽ�					�ӽǰ���
		HOTKEY_ZOOM_OUT	,//	��Զ�ӽ�	
		SET_UI_ZOOM	,//	��������	70-120
		SET_AUTO_PICK_UP	,//	�Զ�ʰȡ	
		SET_HIDE_CHAT_FRAME	,//	�Զ��������������	
		SET_SHOW_LOGGING_TIP	,//	�Զ���ʾ������ʾ	
		SET_SHOW_NEWBIE_HELP	,//	��ʾ���ְ���	
		SET_MOUSE_WALK	,//	�����·	
		SET_SHOW_QUEST_FOLLOW	,//	�����������	
		SET_SHOW_HP_SELF	,//	��ʾ�Լ�Ѫ��	
		SET_SHOW_HP_OTHER_PLAYER	,//	��ʾ�������Ѫ��	
		SET_SHOW_HP_NPC	,//	��ʾNPCѪ��	
		SET_SHOW_TITLE_SELF	,//	��ʾ������ҳƺ�	
		SET_SHOW_TITLE_OTHER_PLAYER	,//	��ʾNPC�ƺ�	
		SET_SHOW_TITLE_NPC	,//	��ʾ�Լ��ƺ�	
		SET_SHOW_NAME_SELF	,//	��ʾ�Լ�����	
		SET_SHOW_NAME_OTHER_PLAYER	,//	��ʾ�����������	
		SET_SHOW_NAME_NPC	,//	��ʾNPC����	
		SET_SHOW_PET_NAME_SELF	,//	��ʾ�Լ���������	
		SET_SHOW_PET_NAME_OTHER_PLAYER	,//	��ʾ������ҳ�������	
		SET_SHOW_GUILD_NAME_SELF	,//	��ʾ�Լ�������	
		SET_SHOW_GUILD_NAME_OTHER_PLAYER	,//	��ʾ���˹�����	
		SET_SHOW_DIALOGUE_PLAYER	,//	��ʾ��ҶԻ�����	
		SET_SHOW_DIALOGUE_NPC	,//	��ʾNPC�Ի�����	
		SET_SHOW_LOWER_LV_QUEST	,//	��ʾ�͵ȼ�����	
		SET_HIDE_HELM	,//	����ñ��	
		SET_HIDE_MANTLE	,//	��������	
		SET_SHOW_AREA_MAP	,//	��ʾ�����ͼ	
		SET_SHOW_TEAMMATE_QUEST_PROGRESS	,//	��ʾ��������״��	
		SET_SHOW_BAG_SPACE	,//	��ʾ�����ռ�	
		SET_SHOW_MAIN_SHORTCUTBAR	,//	���������	
		SET_SHOW_MAIN_SHORTCUTBAR_BACKGROUND	,//	��ʾ�����������	
		SET_SHOW_SUB_SHORTCUTBAR	,//	�򿪸������	
		SET_SHOW_SUB_SHORTCUTBAR_BACKGROUND	,//	��ʾ�����������1	
		SET_SHOW_USER1_SHORTCUTBAR	,//	���Զ�������1	
		SET_SHOW_USER1_SHORTCUTBAR_BACKGROUND	,//	��ʾ���������1	
		SET_SHOW_USER2_SHORTCUTBAR	,//	���Զ�������2	
		SET_SHOW_USER2_SHORTCUTBAR_BACKGROUND	,//	��ʾ���������2	
		SET_SHOW_SELF	,//	��ʾ�Լ�	
		SET_SHOW_TARGET	,//	��ʾĿ��	
		SET_SHOW_TARGET_TARGET	,//	��ʾĿ���Ŀ��	
		SET_SHOW_PET_SELF	,//	��ʾ�Լ�����	
		SET_SHOW_PET_TEAMMATE	,//	��ʾ���ѳ���	
		SET_SHOW_PROCESSION	,//	С��	
		SET_SHOW_EXPBAR	,//	��������ֵ	
		SET_SHOW_GROUP	,//	�Ŷ�	
		SET_PERCENTAGE_SHOW_VALUE	,//	�ٷֱ���ʾ	
		SET_SHOW_FIGHT_LOG_SELF	,//	��������ս����Ϣ	
		SET_SHOW_FIGHT_LOG_TARGET	,//	���������Ŀ��ս����Ϣ	
		SET_SHOW_FIGHT_LOG_TARGET_TARGET	,//	����Ŀ���Ŀ��ս����Ϣ	
		SET_SHOW_BUFF_TIME	,//	��ʾ����Ч��ʣ��ʱ��	
		SET_BUFF_ORDER	,//	����Ч������	0�����ҵ���1:������
		SET_SHOW_DEBUFF_TIME	,//	��ʾ����Ч��ʣ��ʱ��	
		SET_DEBUFF_ORDER	,//	����Ч������	0�����ҵ���1:������
		//
		SET_CHAT_FLAG_NORMAL,	 //	Ԥ��	
		SET_CHAT_PANEL_ALPHA,	 //	Ԥ��	
		SET_CHAT_PARTY_COLOUR,	 //	Ԥ��	
		SET_CHAT_GUILD_COLOUR,	 //	Ԥ��	
		SET_CHAT_CAMP_COLOUR,	 //	Ԥ��	
		SET_CHAT_SAY_COLOUR,	 //	Ԥ��	
		SET_CHAT_CONSTELLATION_COLOUR,	 //	Ԥ��	
		SET_CHAT_WHISPER_COLOUR, // Ԥ��
		SET_CHAT_WORLD_COLOUR,	 //	Ԥ��	
		SET_OTHER_RESERVE_9,	 //	Ԥ��	
		SET_OTHER_RESERVE_10	,//	Ԥ��	
		SET_OTHER_RESERVE_11	,//	Ԥ��	
		SET_OTHER_RESERVE_12	,//	Ԥ��	
		SET_OTHER_RESERVE_13	,//	Ԥ��	
		SET_OTHER_RESERVE_14	,//	Ԥ��	
		SET_OTHER_RESERVE_15	,//	Ԥ��	
		SET_OTHER_RESERVE_16	,//	Ԥ��	
		SET_OTHER_RESERVE_17	,//	Ԥ��	
		SET_OTHER_RESERVE_18	,//	Ԥ��	
		SET_OTHER_RESERVE_19	,//	Ԥ��	
		SET_OTHER_RESERVE_20	,//	Ԥ��	
		SET_OTHER_RESERVE_21	,//	Ԥ��	
		SET_OTHER_RESERVE_22	,//	Ԥ��	
		SET_OTHER_RESERVE_23	,//	Ԥ��	
		SET_OTHER_RESERVE_24	,//	Ԥ��	
		SET_OTHER_RESERVE_25	,//	Ԥ��	
		SET_OTHER_RESERVE_26	,//	Ԥ��	
		SET_OTHER_RESERVE_27	,//	Ԥ��	
		SET_OTHER_RESERVE_28	,//	Ԥ��	
		SET_OTHER_RESERVE_29	,//	Ԥ��	
		SET_OTHER_RESERVE_30	,//	Ԥ��	
		SET_OTHER_RESERVE_31	,//	Ԥ��	
		SET_OTHER_RESERVE_32	,//	Ԥ��	
		SET_OTHER_RESERVE_33	,//	Ԥ��	
		SET_OTHER_RESERVE_34	,//	Ԥ��	
		SET_OTHER_RESERVE_35	,//	Ԥ��	
		SET_OTHER_RESERVE_36	,//	Ԥ��	
		SET_OTHER_RESERVE_37	,//	Ԥ��	
		SET_OTHER_RESERVE_38	,//	Ԥ��	
		SET_OTHER_RESERVE_39	,//	Ԥ��	
		SET_OTHER_RESERVE_40	,//	Ԥ��	
		SET_OTHER_RESERVE_41	,//	Ԥ��	
		SET_OTHER_RESERVE_42	,//	Ԥ��	
		SET_OTHER_RESERVE_43	,//	Ԥ��	
		SET_OTHER_RESERVE_44	,//	Ԥ��	
		SET_OTHER_RESERVE_45	,//	Ԥ��	
		SET_OTHER_RESERVE_46	,//	Ԥ��	
		SET_OTHER_RESERVE_47	,//	Ԥ��	
		SET_OTHER_RESERVE_48	,//	Ԥ��	
		SET_OTHER_RESERVE_49	,//	Ԥ��	
		SET_CONFIG_TOTAL,
	};

};

class ShortCutButton
{
public:
	enum Idx
	{
		SLOT_0,
		SLOT_1,
		SLOT_2,
		SLOT_3,
		SLOT_4,
		SLOT_5,
		SLOT_6,
		SLOT_7,
		SLOT_8,
		SLOT_9,
		SLOT_10,
		SLOT_11,
		SLOT_12,
		SLOT_13,
		SLOT_14,
		SLOT_15,
		SLOT_16,
		SLOT_17,
		SLOT_18,
		SLOT_19,
		SLOT_20,
		SLOT_21,
		SLOT_22,
		SLOT_23,
		SLOT_24,
		SLOT_25,
		SLOT_26,
		SLOT_27,
		SLOT_28,
		SLOT_29,
		SLOT_30,
		SLOT_31,
		SLOT_32,
		SLOT_33,
		SLOT_34,
		SLOT_35,
		SLOT_36,
		SLOT_37,
		SLOT_38,
		SLOT_39,
		SLOT_40,
		SLOT_41,
		SLOT_42,
		SLOT_43,
		SLOT_44,
		SLOT_45,
		SLOT_46,
		SLOT_47,
		SLOT_48,
		SLOT_49,
		SLOT_50,
		SLOT_51,
		SLOT_52,
		SLOT_53,
		SLOT_54,
		SLOT_55,
		SLOT_56,
		SLOT_57,
		SLOT_58,
		SLOT_59,
		SLOT_60,
		SLOT_61,
		SLOT_62,
		SLOT_63,
		//
		RESERVE_0,
		RESERVE_1,
		RESERVE_2,
		RESERVE_3,
		RESERVE_4,
		RESERVE_5,
		RESERVE_6,
		RESERVE_7,
		RESERVE_8,
		RESERVE_9,
		RESERVE_10,
		RESERVE_11,
		RESERVE_12,
		RESERVE_13,
		RESERVE_14,
		RESERVE_15,
		RESERVE_16,
		RESERVE_17,
		RESERVE_18,
		RESERVE_19,
		RESERVE_20,
		RESERVE_21,
		RESERVE_22,
		RESERVE_23,
		RESERVE_24,
		RESERVE_25,
		RESERVE_26,
		RESERVE_27,
		RESERVE_28,
		RESERVE_29,
		RESERVE_30,
		RESERVE_31,
		RESERVE_32,
		RESERVE_33,
		RESERVE_34,
		RESERVE_35,
		RESERVE_36,
		RESERVE_37,
		RESERVE_38,
		RESERVE_39,
		RESERVE_40,
		RESERVE_41,
		RESERVE_42,
		RESERVE_43,
		RESERVE_44,
		RESERVE_45,
		RESERVE_46,
		RESERVE_47,
		RESERVE_48,
		RESERVE_49,
		RESERVE_50,
		RESERVE_51,
		RESERVE_52,
		RESERVE_53,
		RESERVE_54,
		RESERVE_55,
		RESERVE_56,
		RESERVE_57,
		RESERVE_58,
		RESERVE_59,
		RESERVE_60,
		RESERVE_61,
		RESERVE_62,
		RESERVE_63,
		//
		TOTAL,
	};
};

class ShortCutButtonType
{
public:
	enum Idx
	{
		NONE,
		SPELL,
		ITEM_TEMPLATE,
		ITEM_INSTANCE,
		TOTAL,
	};
};


struct HotKey
{
	HotKey()
	{
		m_uiKey[0] = 0;
		m_uiKey[1] = 0;
		m_uiKey[2] = 0;
		m_uiKey[3] = 0;
	}
	HotKey(FvUInt8 uiKeyA,FvUInt8 uiSysKeyA,
		FvUInt8 uiKeyB,FvUInt8 uiSysKeyB)
	{
		m_uiKey[0] = uiKeyA;
		m_uiKey[1] = uiSysKeyA;
		m_uiKey[2] = uiKeyB;
		m_uiKey[3] = uiSysKeyB;
	}
	FvUInt8 m_uiKey[4];
};

static const HotKey s_akDefaultHotKey[PlayerDefine::HOTKEY_ZOOM_OUT + 1] = 
{
	HotKey(CEGUI::Key::W,0,CEGUI::Key::ArrowUp,0),//HOTKEY_MOVING_FRONT	,//	ǰ��			�ƶ�����
	HotKey(CEGUI::Key::S,0,CEGUI::Key::ArrowDown,0),//HOTKEY_MOVING_BACK	,//	����	
	HotKey(CEGUI::Key::A,0,CEGUI::Key::ArrowLeft,0),//HOTKEY_TURNING_LEFT	,//	��ת	
	HotKey(CEGUI::Key::D,0,CEGUI::Key::ArrowRight,0),//HOTKEY_TURNING_RIGHT	,//	��ת	
	HotKey(CEGUI::Key::Q,0,0,0),//HOTKEY_MOVING_LEFT	,//	����ƽ��	
	HotKey(CEGUI::Key::E,0,0,0),//HOTKEY_MOVING_RIGHT	,//	����ƽ��	
	HotKey(CEGUI::Key::Space,0,0,0),//HOTKEY_JUMPED	,//	��Ծ	
	HotKey(CEGUI::Key::Grave,0,0,0),//HOTKEY_SWITCH_RUN_WALK	,//	��/��	
	HotKey(CEGUI::Key::NumLock,0,CEGUI::Key::MediaSelect+1,0),//HOTKEY_KEEPON_MOVE	,//	�����ƶ�	
	HotKey(CEGUI::Key::X,0,0,0),//HOTKEY_SITDOWN	,//	����	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_0	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_1	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_2	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_3	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_4	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_5	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_6	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_7	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_8	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_ACTION_RESERVE_9	,//	Ԥ��	
	HotKey(CEGUI::Key::T,CEGUI::Shift,0,0),//HOTKEY_PET_ACTIVE	,//	������������			���ﰴ��
	HotKey(CEGUI::Key::D,CEGUI::Shift,0,0),//HOTKEY_PET_PASSIVE	,//	���ﱻ������	
	HotKey(CEGUI::Key::F,CEGUI::Shift,0,0),//HOTKEY_PET_FOLLOW	,//	�������	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_0	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_1	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_2	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_3	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_4	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_5	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_6	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_7	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_8	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_PET_RESERVE_9	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_DANCE	,//	����				 ���鰴��
	HotKey(0,0,0,0),//HOTKEY_CRY	,//	���	
	HotKey(0,0,0,0),//HOTKEY_ANGRY	,//	����	
	HotKey(0,0,0,0),//HOTKEY_KNEEL	,//	����	
	HotKey(0,0,0,0),//HOTKEY_WORSHIP	,//	����	
	HotKey(0,0,0,0),//HOTKEY_ROLL	,//	����ͷ	
	HotKey(0,0,0,0),//HOTKEY_RAGE	,//	��ŭ	
	HotKey(0,0,0,0),//HOTKEY_DREAD	,//	�־�	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_0	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_1	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_2	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_3	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_4	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_5	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_6	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_7	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_8	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_9	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_10	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_11	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_12	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_13	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_14	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_15	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_16	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_17	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_18	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_EMOTION_RESERVE_19	,//	Ԥ��	
	HotKey(CEGUI::Key::Z,0,0,0),//HOTKEY_UI_MAIN	,//	��/�ر�������				���水��
	HotKey(CEGUI::Key::C,0,0,0),//HOTKEY_UI_CHARATAR	,//	��/�رս�ɫ����	
	HotKey(CEGUI::Key::P,0,0,0),//HOTKEY_UI_PET	,//	��/�رճ������	
	HotKey(CEGUI::Key::B,0,0,0),//HOTKEY_UI_BAG	,//	��/�رյ��߽���	
	HotKey(CEGUI::Key::K,0,0,0),//HOTKEY_UI_SKILL	,//	��/�رռ��ܽ���	
	HotKey(CEGUI::Key::I,0,0,0),//HOTKEY_UI_RELIGION	,//	��/�ر���������	
	HotKey(CEGUI::Key::L,0,0,0),//HOTKEY_UI_QUEST	,//	��/�ر��������	
	HotKey(CEGUI::Key::H,0,0,0),//HOTKEY_UI_HELP	,//	��/�رհ�������	
	HotKey(CEGUI::Key::M,0,0,0),//HOTKEY_UI_MAP	,//	��/�رյ�ͼ����	
	HotKey(CEGUI::Key::T,0,0,0),//HOTKEY_UI_MARKET	,//	��/�ر��̳ǽ���	
	HotKey(CEGUI::Key::N,0,0,0),//HOTKEY_UI_PROCESSION	,//	��/�ر��Ŷӽ���	
	HotKey(CEGUI::Key::O,0,0,0),//HOTKEY_UI_SOCIALITY	,//	��/�ر��罻����	
	HotKey(CEGUI::Key::G,0,0,0),//HOTKEY_UI_GUIILD	,//	��/�رչ������	
	HotKey(CEGUI::Key::V,0,0,0),//HOTKEY_UI_RANKING	,//	��/�ر���������	
	HotKey(CEGUI::Key::Escape,0,0,0),//HOTKEY_UI_SYSTEM	,//	��/�ر�ϵͳ�˵�	
	HotKey(CEGUI::Key::C,CEGUI::Alt,0,0),//HOTKEY_UI_CHAT	,//	��/�ر��������	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_0	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_1	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_2	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_3	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_4	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_5	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_6	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_7	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_8	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_UI_RESERVE_9	,//	Ԥ��	
	HotKey(CEGUI::Key::SysRq,0,0,0),//HOTKEY_PRINTSCREEN	,//	��ͼ��	
	HotKey(0,0,0,0),//HOTKEY_MUSIC	,//	��/�رձ�������			��������
	HotKey(0,0,0,0),//HOTKEY_SOUND	,//	��/�ر���Ϸ��Ч	
	HotKey(0,0,0,0),//HOTKEY_VOLUME_UP	,//	���������	
	HotKey(0,0,0,0),//HOTKEY_VOLUME_DOWN	,//	����������	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_0	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_1	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_2	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_3	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_4	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_5	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_6	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_7	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_8	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SOUND_RESERVE_9	,//	Ԥ��	
	HotKey(CEGUI::Key::One,0,0,0),//HOTKEY_SHORTCUT_0	,//	��ݼ�1				��ݰ���
	HotKey(CEGUI::Key::Two,0,0,0),//HOTKEY_SHORTCUT_1	,//	��ݼ�2	
	HotKey(CEGUI::Key::Three,0,0,0),//HOTKEY_SHORTCUT_2	,//	��ݼ�3	
	HotKey(CEGUI::Key::Four,0,0,0),//HOTKEY_SHORTCUT_3	,//	��ݼ�4	
	HotKey(CEGUI::Key::Five,0,0,0),//HOTKEY_SHORTCUT_4	,//	��ݼ�5	
	HotKey(CEGUI::Key::Six,0,0,0),//HOTKEY_SHORTCUT_5	,//	��ݼ�6	
	HotKey(CEGUI::Key::Seven,0,0,0),//HOTKEY_SHORTCUT_6	,//	��ݼ�7	
	HotKey(CEGUI::Key::Eight,0,0,0),//HOTKEY_SHORTCUT_7	,//	��ݼ�8	
	HotKey(CEGUI::Key::Nine,0,0,0),//HOTKEY_SHORTCUT_8	,//	��ݼ�9	
	HotKey(CEGUI::Key::Zero,0,0,0),//HOTKEY_SHORTCUT_9	,//	��ݼ�10	
	HotKey(CEGUI::Key::Minus,0,0,0),//HOTKEY_SHORTCUT_10	,//	��ݼ�11	
	HotKey(CEGUI::Key::Equals,0,0,0),//HOTKEY_SHORTCUT_11	,//	��ݼ�12	
	HotKey(CEGUI::Key::One,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_12	,//	��ݼ�13	
	HotKey(CEGUI::Key::Two,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_13	,//	��ݼ�14	
	HotKey(CEGUI::Key::Three,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_14	,//	��ݼ�15	
	HotKey(CEGUI::Key::Four,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_15	,//	��ݼ�16	
	HotKey(CEGUI::Key::Five,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_16	,//	��ݼ�17	
	HotKey(CEGUI::Key::Six,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_17	,//	��ݼ�18	
	HotKey(CEGUI::Key::Seven,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_18	,//	��ݼ�19	
	HotKey(CEGUI::Key::Eight,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_19	,//	��ݼ�20	
	HotKey(CEGUI::Key::Nine,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_20	,//	��ݼ�21	
	HotKey(CEGUI::Key::Zero,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_21	,//	��ݼ�22	
	HotKey(CEGUI::Key::Minus,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_22	,//	��ݼ�23	
	HotKey(CEGUI::Key::Equals,CEGUI::Alt,0,0),//HOTKEY_SHORTCUT_23	,//	��ݼ�24	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_24	,//	��ݼ�25	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_25	,//	��ݼ�26	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_26	,//	��ݼ�27	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_27	,//	��ݼ�28	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_28	,//	��ݼ�29	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_29	,//	��ݼ�30	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_30	,//	��ݼ�31	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_31	,//	��ݼ�32	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_32	,//	��ݼ�33	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_33	,//	��ݼ�34	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_34	,//	��ݼ�35	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_35	,//	��ݼ�36	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_36	,//	��ݼ�37	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_37	,//	��ݼ�38	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_38	,//	��ݼ�39	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_39	,//	��ݼ�40	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_40	,//	��ݼ�41	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_41	,//	��ݼ�42	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_42	,//	��ݼ�43	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_43	,//	��ݼ�44	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_44	,//	��ݼ�45	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_45	,//	��ݼ�46	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_46	,//	��ݼ�47	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_47	,//	��ݼ�48	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_48	,//	��ݼ�49	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_49	,//	��ݼ�50	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_50	,//	��ݼ�51	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_51	,//	��ݼ�52	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_52	,//	��ݼ�53	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_53	,//	��ݼ�54	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_54	,//	��ݼ�55	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_55	,//	��ݼ�56	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_56	,//	��ݼ�57	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_57	,//	��ݼ�58	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_58	,//	��ݼ�59	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_59	,//	��ݼ�60	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_60	,//	��ݼ�61	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_61	,//	��ݼ�62	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_62	,//	��ݼ�63	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_63	,//	��ݼ�64	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_0	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_1	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_2	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_3	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_4	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_5	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_6	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_7	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_8	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_9	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_10	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_11	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_12	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_13	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_14	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_15	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_16	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_17	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_18	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_19	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_20	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_21	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_22	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_23	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_24	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_25	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_26	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_27	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_28	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_29	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_30	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_31	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_32	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_33	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_34	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_35	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_36	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_37	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_38	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_39	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_40	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_41	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_42	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_43	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_44	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_45	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_46	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_47	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_48	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_49	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_50	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_51	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_52	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_53	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_54	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_55	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_56	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_57	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_58	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_59	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_60	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_61	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_62	,//	Ԥ��	
	HotKey(0,0,0,0),//HOTKEY_SHORTCUT_RESERVE_63	,//	Ԥ��	
	HotKey(CEGUI::Key::Return,0,0,0),//HOTKEY_ENTER	,//	��������������				���찴��
	HotKey(CEGUI::Key::R,0,0,0),//HOTKEY_RESPOND	,//	���ٻظ��������	
	HotKey(CEGUI::Key::ArrowUp,CEGUI::Alt,0,0),//HOTKEY_INPUT_TEXT_PAGE_UP	,//	��������ı��Ϸ�	
	HotKey(CEGUI::Key::ArrowDown,CEGUI::Alt,0,0),//HOTKEY_INPUT_TEXT_PAGE_DOWN	,//	��������ı��·�	
	HotKey(CEGUI::Key::PageUp,0,0,0),//HOTKEY_LOG_PAGE_UP	,//	�����¼���Ϸ�ҳ	
	HotKey(CEGUI::Key::PageDown,0,0,0),//HOTKEY_LOG_PAGE_DOWN	,//	�����¼���·�ҳ	
	HotKey(CEGUI::Key::PageDown,CEGUI::Shift,0,0),//HOTKEY_LOG_PAGE_LAST	,//	�����¼�������¶�	
	HotKey(CEGUI::Key::C,CEGUI::Shift,0,0),//HOTKEY_FIGHT_LOG	,//	��/�ر�ս����־	
	HotKey(CEGUI::Key::PageUp,CEGUI::Control,0,0),//HOTKEY_FIGHT_LOG_PAGE_UP	,//	ս����־���Ϸ�ҳ	
	HotKey(CEGUI::Key::PageDown,CEGUI::Control,0,0),//HOTKEY_FIGHT_LOG_PAGE_DOWN	,//	ս����־���·�ҳ	
	HotKey(CEGUI::Key::PageDown,CEGUI::Control|CEGUI::Shift,0,0),//HOTKEY_FIGHT_LOG_PAGE_LAST	,//	ս����־�������¶�	
	HotKey(CEGUI::Key::Tab,0,0,0),//HOTKEY_SELECT_CLOSEST_ENEMY	,//	ѡ������ĵ���				Ŀ�갴��
	HotKey(CEGUI::Key::Tab,CEGUI::Control,0,0),//HOTKEY_SELECT_CLOSEST_FRIEND	,//	ѡ��������Ѿ�	
	HotKey(CEGUI::Key::F,0,0,0),//HOTKEY_SELECT_TARGET_TARGET	,//	ѡ��Ŀ���Ŀ��	
	HotKey(0,0,0,0),//HOTKEY_SELECT_CLOSEST_ENEMY_PLAYER	,//	ѡ������ĵж����	
	HotKey(0,0,0,0),//HOTKEY_SELECT_PREVIOUS_ENEMY_PLAYER	,//	ѡ����һ���ж����	
	HotKey(0,0,0,0),//HOTKEY_SELECT_CLOSEST_FRIEND_PLAYER	,//	ѡ��������ѷ����	
	HotKey(0,0,0,0),//HOTKEY_SELECT_PREVIOUS_FRIEND_PLAYER	,//	ѡ����һ���ѷ����	
	HotKey(CEGUI::Key::F1,0,0,0),//HOTKEY_SELECT_MEMBER_SELF	,//	ѡ���Լ�	
	HotKey(CEGUI::Key::F2,0,0,0),//HOTKEY_SELECT_MEMBER_FIRST	,//	ѡ���һ������	
	HotKey(CEGUI::Key::F3,0,0,0),//HOTKEY_SELECT_MEMBER_SECOND	,//	ѡ��ڶ�������	
	HotKey(CEGUI::Key::F4,0,0,0),//HOTKEY_SELECT_MEMBER_THIRD	,//	ѡ�����������	
	HotKey(CEGUI::Key::F5,0,0,0),//HOTKEY_SELECT_MEMBER_LAST	,//	ѡ����ĸ�����	
	HotKey(CEGUI::Key::F1,CEGUI::Shift,0,0),//HOTKEY_SELECT_PET_SELF	,//	ѡ���Լ�����	
	HotKey(CEGUI::Key::F2,CEGUI::Shift,0,0),//HOTKEY_SELECT_PET_FIRST	,//	ѡ���һ���ѳ���	
	HotKey(CEGUI::Key::F3,CEGUI::Shift,0,0),//HOTKEY_SELECT_PET_SECOND	,//	ѡ��ڶ����ѳ���	
	HotKey(CEGUI::Key::F4,CEGUI::Shift,0,0),//HOTKEY_SELECT_PET_THIRD	,//	ѡ��������ѳ���	
	HotKey(CEGUI::Key::F5,CEGUI::Shift,0,0),//HOTKEY_SELECT_PET_LAST	,//	ѡ����Ķ��ѳ���	
	HotKey(CEGUI::Key::F12,0,0,0),//HOTKEY_SHOW_PLAYER	,//	��ʾ/�����������	
	HotKey(CEGUI::Key::MediaSelect+2,0,CEGUI::Key::Home,0),//HOTKEY_ZOOM_IN	,//	�����ӽ�					�ӽǰ���
	HotKey(CEGUI::Key::MediaSelect+3,0,CEGUI::Key::End,0)//HOTKEY_ZOOM_OUT	,//	��Զ�ӽ�	
};

class ChatSettingFlag
{
public:
	enum Idx
	{
		PANEL_SHOW				= 0x00000001,
		PANEL_LOCK				= 0x00000002,
		BATTLE_SHOW				= 0x00000004,
		BATTLE_LOCK				= 0x00000008,
		CHANNEL_PARTY			= 0x00000010,
		CHANNEL_GUILD			= 0x00000020,
		CHANNEL_CAMP			= 0x00000040,
		CHANNEL_SAY				= 0x00000080,
		CHANNEL_CONSTELLATION	= 0x00000100,
		CHANNEL_WHISPER			= 0x00000200,
		CHANNEL_WORLD			= 0x00000400,
	};
};

static const FvUInt32 s_auiDefaultChatSetting[PlayerDefine::SET_CHAT_WORLD_COLOUR - PlayerDefine::SET_CHAT_FLAG_NORMAL + 1] = 
{
	ChatSettingFlag::PANEL_SHOW |
	ChatSettingFlag::PANEL_LOCK |
	ChatSettingFlag::BATTLE_SHOW |
	ChatSettingFlag::BATTLE_LOCK |
	ChatSettingFlag::CHANNEL_PARTY |
	ChatSettingFlag::CHANNEL_GUILD |
	ChatSettingFlag::CHANNEL_CAMP |
	ChatSettingFlag::CHANNEL_SAY |
	ChatSettingFlag::CHANNEL_CONSTELLATION |
	ChatSettingFlag::CHANNEL_WHISPER |
	ChatSettingFlag::CHANNEL_WORLD,
	10000,
	0xff84a9e9,
	0xff5deb36,
	0xff49bcf1,
	0xffffffff,
	0xfffeffa7,
	0xffca7eff,
	0xfffccccc
};

class Constellation
{
public:
	enum Idx
	{
		ARIES, //������ ARIES ������
		TAURUS, //	��ţ�� TAURUS 
		GEMINI, //	˫���� GEMINI
		CANCER, //	��з�� CANCER
		LEO, //	ʨ���� LEO
		VIRGO, //	��Ů�� VIRGO ��Ů��
		LIBRA, //	����� LIBRA
		SCORPIUS, //	��Ы�� SCORPIUS
		SAGITTARIUS, //	������ SAGITTARIUS ������
		CAPRICORNUS, //	Ħ���� CAPRICORNUS ɽ����
		AQUARIUS, //	��ƿ�� AQUARIUS ˮƿ��
		PISCES, //	˫���� PISCES
		MAX
	};
};

class FriendFeild
{
public:
	enum Idx
	{
		DBID,///<FvInt64>
		NAME,///<String>
		STATE,///<FvUInt8><FriendState::Idx>
		GROUP_ID,///<FvUInt8>
	};
};
class FriendState
{
public:
	enum Idx
	{
		OFFLINE,
		ONLINE,
	};
};
class BlackMemberrFeild
{
public:
	enum Idx
	{
		DBID,///<FvInt64>
		NAME,///<String>
	};
};
class GroupFeild
{
public:
	enum Idx
	{
		GROUP_ID,///<FvUInt8>
		NAME,///<String>
	};
};

class PostBoxFeild
{
public:
	//Enum define
	enum MailType
	{
		SYSTEM				= 0x80,
		SOCIATY				= 0x40,
		SYSTEM_SEND_BACK	= 0xC0,
		HAS_READED			= 0x20,
		TEMPLATE			= 0x0,
		NORMAL				= 0x1,
		SELL				= 0x2,
		TYPE_MASK			= 0x3
	};

	struct MailOperateResult
	{
		enum
		{
			SUCCEED,
			WRONG_UNIT,
			WRONG_MAIL_ID,
			WRONG_TYPE,
			WRONG_EXTRA
		};
	};

	enum Result
	{
		SUCCEED,
		WRONG_UNIT,
		WRONG_TYPE,
		WRONG_EXTRA

	};

	struct SendMailResult
	{
		enum
		{
			SUCCEED,
			RECEIVER_NOT_EXIST,
			RECEIVER_SAME_ACCOUNT,
			RECEIVER_IS_FULL,
			RECEIVER_FULL,
			GET_ITEM_FAILED,
			UNKNOWN_ERROR
		};
	};

	struct GetMailItemResult
	{
		enum
		{
			SUCCEED,
			BAG_FAILED,
			MAIL_DIRTY,
			NOT_ENOUGH_MONEY,
			UNKNOWN_FAILED
		};
	};

	enum SystemTemplateID
	{
		RECEIVER_POST_FULL,
		SELL_SUCCEED,
		SELL_FAILED,
		MAIL_READ_TIME_OUT,
		AUCTION_ITEM_CANCEL,
		AUCTION_ITEM_BUY_IT_NOW,
		AUCTION_GET_SELL_MONEY,
		AUCTION_ITEM_TURNOVER,
		AUCTION_GET_AUCTION_MONEY,
		AUCTION_SEND_BACK_BID_MONEY,
		AUCTION_ITEM_TIME_OUT,
		AUCTION_ITEM_SEND_BACK_FULL
	};

	enum PostBoxState
	{
		HAS_NEW_MAIL = 0x1,
		POST_BOX_FULL = 0x2
	};

	struct Expire
	{
		enum ExpireType
		{
			SYSTEM,
			TRADE,
			NORMAL_DELETE,
			NORMAL_SEND_BACK
		};
	};
};


#define PAGE_MAIL_NUMBER (8)
#define SYSTEM_MAIL_SENDER_ID (-1)

#define MAX_MAIL_LIST_LENGTH (64)

#endif //__PlayerDefine_H__
