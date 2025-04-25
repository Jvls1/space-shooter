#include "gameplay/HealthComponent.hpp"

namespace ss {
    HealthComponent::HealthComponent(float health, float maxHealth)
        : mHealth{health},
        mMaxHealth{maxHealth} {

    }

    void HealthComponent::ChangeHealth(float amt) {
        if (amt == 0) return;
        if (mHealth == 0) return;

        mHealth += amt;
        if (mHealth < 0) {
            mHealth = 0;
        }
        if (mHealth > mMaxHealth) {
            mHealth = mMaxHealth;
        }
        if (amt < 0) {
            TakenDamage(-amt);
            if (mHealth <= 0) {
                HealthEmpty();
            }
        } else {
            HealthRegen(amt);
        }

        onHealthChanged.Broadcast(amt, mHealth, mMaxHealth);
    }

    void HealthComponent::TakenDamage(float amt) {
        onTakenDamage.Broadcast(amt, mHealth, mMaxHealth);
    }

    void HealthComponent::HealthRegen(float amt) {

    }
    
    void HealthComponent::HealthEmpty() {
        onHealthEmpty.Broadcast();
    }
}
