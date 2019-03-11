#pragma once
#include "../IComponent.h"
#include "DebugCollision.service.h"

class DebugComponent : public IComponent
{
public:
	DebugComponent() : IComponent("DEBUG") {
		this->AddGameService<DebugCollisionService>();
	}

	virtual void RenderMenu() {
		Start(2);

		ImGui::Checkbox("Debug Collision", &g_Options.enable_debug_collision);
		ImGui::Checkbox("Show LastHit Targets", &g_Options.show_lasthit_targets);

		ImGui::NextColumn();

		End();
	}
};

//	if (g_Options.show_lasthit_targets)
//	{
//		auto AARange = ObjectManager::GetPlayer()->GetUnitStats()->mAttackRange;
//		auto AADamage = Common::Damage::GetStaticAutoAttackDamage();
//
//		ObjectIterator it = ObjectIterator();
//		while (!it.End())
//		{
//			Obj_AI_Base* currObject = (Obj_AI_Base*)it.Next();
//
//			if (!currObject->IsMinion()) continue;
//			if (!Common::ObjectHelper::IsValidTarget(currObject, AARange))continue;
//
//			auto damageOnTarget = Common::Damage::GetAutoAttackDamage(currObject, AADamage);
//			if (*currObject->GetHealth() < damageOnTarget) {
//				Draw.CircleFilled(currObject->GetPos(), currObject->GetBoundingRadius() / 2, GREEN());
//			}
//		}
//	}
//}