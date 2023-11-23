#pragma once
#include "GameObject.h"
#include <vector>

class Zombie : public GameObject
{
private:
    int                    m_Speed;
    int                    m_Hp;
    int                    m_HpMax;
    float                m_Damage;
    std::vector<float>    m_vDirection;

public:

	Zombie(int m_id);

    void    SetSpeed(int value);
    float   GetHp();
    float   GetDmg();
    void    DecreaseLife(float value);
    bool    CheckCollision(GameObject* object);
    void    setStats(float fSpeed, float fHp, float fMaxHp, float fDamage);

    void    move(float fDeltaTime);
};
