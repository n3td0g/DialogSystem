#include "Dialog/DialogScript.h"
#include "Kismet/GameplayStatics.h"


ADialogScript::ADialogScript()
{
}

AActor* ADialogScript::GetPlayer()
{
	return UGameplayStatics::GetPlayerCharacter(GetNPC()->GetWorld(), 0);
}

AActor* ADialogScript::GetNPC()
{
	return Implementer->NPC;
}
