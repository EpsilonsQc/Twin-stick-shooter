
#include "AC_HealthComponent.h"

// Sets default values for this component's properties
UAC_HealthComponent::UAC_HealthComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
    // ...
}

// Called when the game starts
void UAC_HealthComponent::BeginPlay()
{
    Super::BeginPlay();

    GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UAC_HealthComponent::TakeDamage);
    //CurrentHealth = MaxHealth;
    // ...
}

// Called every frame
void UAC_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

void UAC_HealthComponent::Heal(float healAmount)
{
    CurrentHealth += healAmount;

    CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);
}

void UAC_HealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    CurrentHealth -= Damage;

    UE_LOG(LogTemp, Warning, TEXT("HP Left : %f"), CurrentHealth);

    if (CurrentHealth <= 0)
    {
        CurrentHealth = 0;
        Die();
    }
}

void UAC_HealthComponent::Die()
{
    GetOwner()->Destroy();
}