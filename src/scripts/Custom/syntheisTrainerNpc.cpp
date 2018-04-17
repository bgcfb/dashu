#include "GossipDef.h"
#include "Item.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "GuildMgr.h"
#pragma execution_character_set("UTF-8") // ��������cpp�ļ�
#define RESETTALENTCOST 0


void learnSkill(Player * player, Creature * creature)
{
	player->PlayerTalkClass->ClearMenus();
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_Mining.blp:20:20:-18:0|t �ɿ�ѵ��", 2, 1);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_Herbalism.blp:20:20:-18:0|t ��ҩѵ��.", 2, 2);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_Alchemy.blp:20:20:-18:0|t ����ѵ��.", 2, 3);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_Engraving.blp:20:20:-18:0|t ��ħѵ��", 2, 4);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_BlackSmithing.blp:20:20:-18:0|t ����ѵ��", 2, 5);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_Tailoring.blp:20:20:-18:0|t �÷�ѵ��", 2, 6);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_Engineering.blp:20:20:-18:0|t ����ѵ��", 2, 7);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/INV_Misc_Gem_01.blp:20:20:-18:0|t �鱦ѵ��", 2, 8);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_LeatherWorking.blp:20:20:-18:0|t ��Ƥѵ��", 2, 9);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/INV_Misc_Pelt_Wolf_01.blp:20:20:-18:0|t ��Ƥѵ��", 2, 10);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/INV_Inscription_Tradeskill01.blp:20:20:-18:0|t ����ѵ��", 2, 11);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/INV_Misc_Food_15.blp:20:20:-18:0|t ���ѵ��", 2, 12);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Trade_Fishing.blp:20:20:-18:0|t ����ѵ��", 2, 13);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Spell_Holy_SealOfSacrifice.blp:20:20:-18:0|t ����ѵ��", 2, 14);
	player->SEND_GOSSIP_MENU(1, creature->GetGUID());
}

class synthesisTrainer : public CreatureScript
{
public:
	synthesisTrainer() : CreatureScript("synthesis_Trainer") {}


	bool OnGossipHello(Player* player, Creature* creature) override
	{
		player->PlayerTalkClass->ClearMenus();
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Character_Bloodelf_Female.blp:35:35:-19:0|t ְҵ����ѵ��.", 1, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/INV_Axe_100.blp:35:35:-19:0|t ��������ѵ��.", 1, 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Achievement_Halloween_Witch_01.blp:35:35:-19:0|t ��������ѵ��.", 1, 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Trade_Mining.blp:35:35:-19:0|t ��ҵ����ѵ��.", 1, 4);
		player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/Spell_Shadow_AntiMagicShell.blp:35:35:-18:0|t ���ý�ɫ�츳", 1, 5, "\n���ý�ɫ�츳������Ҫ\n", RESETTALENTCOST * GOLD, false);
		player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_VENDOR, "|TInterface/ICONS/INV_Inscription_MajorGlyph09.blp:35:35:-18:0|t ����ɫ˫�츳", 1, 6, "\n��ͨ��ɫ˫�츳��Ҫ\n", RESETTALENTCOST * GOLD * 100, false);
		player->SEND_GOSSIP_MENU(1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
	{
		player->PlayerTalkClass->ClearMenus();
		if (sender == 1)
		{
			if (action == 1)
			{
				uint32 npcspellid = 1000;
				switch (player->getClass())
				{
				case CLASS_WARRIOR: npcspellid = 3042; break;
				case CLASS_PALADIN:    npcspellid = 16679; break;
				case CLASS_HUNTER:    npcspellid = 3352; break;
				case CLASS_ROGUE:    npcspellid = 3328; break;
				case CLASS_PRIEST:    npcspellid = 6014; break;
				case CLASS_DEATH_KNIGHT:    npcspellid = 28472; break;
				case CLASS_SHAMAN:    npcspellid = 3344; break;
				case CLASS_MAGE:    npcspellid = 16652; break;
				case CLASS_WARLOCK:    npcspellid = 988; break;
				case CLASS_DRUID:    npcspellid = 3036; break;
				}
				player->GetSession()->SendTrainerList(creature->GetGUID(), npcspellid);
			}
			else if (action == 2)
				player->GetSession()->SendTrainerList(creature->GetGUID(), 17005);
			else if (action == 3)
				player->GetSession()->SendTrainerList(creature->GetGUID(), 31238);
			else if (action == 4)
				learnSkill(player, creature);
			else if (action == 5)
			{
				if (player->HasEnoughMoney(RESETTALENTCOST * GOLD))
				{
					player->resetTalents(true);
					player->SendTalentsInfoData(false);
					player->ModifyMoney(-int32(RESETTALENTCOST * GOLD), true);
					player->CLOSE_GOSSIP_MENU();
				}
				else
				{
					ChatHandler(player->GetSession()).PSendSysMessage("|CFFFF0000 ���Ľ�Ҳ���%uö, ���������츳!", RESETTALENTCOST);
					player->CLOSE_GOSSIP_MENU();
				}
			}
			else if (action == 6)
			{
				if (player->HasEnoughMoney(RESETTALENTCOST * GOLD * 100))
				{
					if (player->GetSpecsCount() == 1 && player->getLevel() >= sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL))
					{
						// Cast spells that teach dual spec
						// Both are also ImplicitTarget self and must be cast by player
						player->CastSpell(player, 63680, true, NULL, NULL, player->GetGUID());
						player->CastSpell(player, 63624, true, NULL, NULL, player->GetGUID());
						player->ModifyMoney(-RESETTALENTCOST * GOLD * 100);
						// Should show another Gossip text with "Congratulations..."
						ChatHandler(player->GetSession()).PSendSysMessage("��ϲ, ��ͨ˫�츳�ɹ�!");
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						ChatHandler(player->GetSession()).PSendSysMessage("���Ѿ���ͨ��˫�츳���ܣ������ٴο�ͨ��!");
						player->PlayerTalkClass->SendCloseGossip();
					}
				}
				else
				{
					ChatHandler(player->GetSession()).PSendSysMessage("|CFFFF0000 ���Ľ�Ҳ���%uö, ���ܿ�ͨ˫�츳!", RESETTALENTCOST * 100);
					player->CLOSE_GOSSIP_MENU();
				}
			}
		}
		else if (sender == 2)
		{
			uint32 npcskillid = 1000;
			switch (action)
			{
			case 1:npcskillid = 33617; break;
			case 2:npcskillid = 33616; break;
			case 3:npcskillid = 33608; break;
			case 4:npcskillid = 33610; break;
			case 5:npcskillid = 33609; break;
			case 6:npcskillid = 33613; break;
			case 7:npcskillid = 33611; break;
			case 8:npcskillid = 33614; break;
			case 9:npcskillid = 33612; break;
			case 10:npcskillid = 33618; break;
			case 11:npcskillid = 33615; break;
			case 12:npcskillid = 33619; break;
			case 13:npcskillid = 33623; break;
			case 14:npcskillid = 33621; break;
			}
			player->GetSession()->SendTrainerList(creature->GetGUID(), npcskillid);
		}
		return true;
	}
};
/*
class Player_Login_AddGuild : public PlayerScript
{
public:
	Player_Login_AddGuild() :PlayerScript("Player_Login_AddGuild"){}

	void OnLogin(Player* player)override
	{
		if (player && player->GetTotalPlayedTime() < MINUTE)
		{

			if (player->GetTeamId() == TEAM_ALLIANCE) // �����LM
			{

				player->ADD_GOSSIP_ITEM_EXTENDED(1, "", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF, "\n\n�װ������, " + player->GetName() + "\n�������ҵθ�\n�Ͻ�����ܽ������˵� XXXX ����ɣ�\n\n\n", 0, false);
				player->PlayerTalkClass->GetGossipMenu().SetMenuId(200001);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
			}
			else if (player->GetTeamId() == TEAM_HORDE)// �����BL
			{

				player->ADD_GOSSIP_ITEM_EXTENDED(1, "", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF, "\n\n�װ������, " + player->GetName() + "\n�������ҵθ�\n�Ͻ�����ܽ��벿��� XXXX ����ɣ�\n\n\n", 0, false);
				player->PlayerTalkClass->GetGossipMenu().SetMenuId(200002);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
			}
		}
	}

};
*/
class Player_Login_AddGuildLM : public PlayerScript
{
public:
	Player_Login_AddGuildLM() :PlayerScript("Player_Login_AddGuildLM"){}


	void OnGossipSelect(Player* player, uint32 menu_id, uint32 sender, uint32 action)override
	{
		//sLog->outString("LMLM");
		if (menu_id != 200001)
			return;
		switch (action)
		{
		case GOSSIP_ACTION_INFO_DEF:
			Guild* guild = sGuildMgr->GetGuildById(1);
			if (guild && !player->GetGuild())
			{
				guild->AddMember(player->GetGUID(), 1);
			}
			//sLog->outString("BLBL");
			break;
		}

	}
};

class Player_Login_AddGuildBL : public PlayerScript
{
public:
	Player_Login_AddGuildBL() :PlayerScript("Player_Login_AddGuildBL"){}

	void OnGossipSelect(Player* player, uint32 menu_id, uint32 sender, uint32 action)override
	{
		//sLog->outString("BLBL");
		if (menu_id != 200002)return;
		switch (action)
		{
		case GOSSIP_ACTION_INFO_DEF:
			Guild* guild = sGuildMgr->GetGuildById(2);
			if (guild && !player->GetGuild())
			{
				guild->AddMember(player->GetGUID(), 1);
			}
			//sLog->outString("BLBL");
			break;
		}
	}
};

void AddSC_synthesis_Trainer()
{
	new synthesisTrainer();
	new Player_Login_AddGuildLM();
	new Player_Login_AddGuildBL();
}