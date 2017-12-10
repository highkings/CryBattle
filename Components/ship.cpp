#include "StdAfx.h"

#include "ship.h"


#include <CrySchematyc/Reflection/TypeDesc.h>
#include <CrySchematyc/Utils/EnumFlags.h>
#include <CrySchematyc/Env/IEnvRegistry.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/Elements/EnvFunction.h>
#include <CrySchematyc/Env/Elements/EnvSignal.h>
#include <CrySchematyc/ResourceTypes.h>
#include <CrySchematyc/MathTypes.h>
#include <CrySchematyc/Utils/SharedString.h>



static void RegisterCShipComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CShip));
		// Functions
		{
		}
	}
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterCShipComponent)



void CShip::Initialize()
{

	// Set the model
	const int geometrySlot = 0;
	m_pEntity->LoadGeometry(geometrySlot, "Objects/Default/primitive_sphere.cgf");
	


	SEntityPhysicalizeParams physParams;
	physParams.type = PE_RIGID;
	physParams.mass = 20000.f;
	m_pEntity->Physicalize(physParams);
}

void CShip::shipHop()
{
	if (auto *pPhysics = GetEntity()->GetPhysics())
	{
		pe_action_impulse impulseAction;

		const float initialVelocity = 1000.f;

		// Set the actual impulse, in this cause the value of the initial velocity CVar in bullet's forward direction
		impulseAction.impulse = GetEntity()->GetWorldRotation().GetColumn1() * initialVelocity;

		// Send to the physical entity
		pPhysics->Action(&impulseAction);
	}
}
