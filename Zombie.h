#pragma once
#include "GameObject.h"
#include <vector>

class Zombie : public GameObject
{
private:

    // Main Attributes

    int                     m_CurrentSpeed;
    int                     m_Speed;
    
    int                     m_Hp;
    int                     m_HpMax;
    float                   m_Damage;
    std::vector<float>      m_vDirection;

public:

	bool                    m_Idle;

	Zombie(int m_id);

    // Get Methods

    float                   GetHp();
    float                   GetDmg();
    float	                GetSpeed();

    // Set Methods

    void                    SetSpeed(int value);
    void                    setStats(float fSpeed, float fHp, float fMaxHp, float fDamage);

    // Main Methods
   
    void                    DecreaseLife(float value);
    bool                    CheckCollision(GameObject* object);
    void                    move(float fDeltaTime);
};
