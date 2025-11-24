int js(int hp, char* name)
{
    // HP가 낮을수록 더 강하게 회복
    if (hp < 50) {
        return Heal(hp, name);   // HP가 위급하면 무조건 +20
    }

    // HP가 넉넉하면 안전한 방어만 수행
    return Wait(hp, name);        // 절대 죽지 않게 +10
}