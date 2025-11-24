int yunjun(int hp, char* name, int enemy_hp)
{
    // 🔹 1. 내 HP가 위험하면 무조건 힐
    // -> 살아야 공격도 가능하다
    if (hp <= 60) {
        return Heal(hp, name);
    }

    // 🔹 2. 상대 HP가 40~70 사이면 힐 타이밍일 가능성이 높음
    // -> 이때 Wait으로 공격해서 상대 회복 전에 데미지 줌
    if (enemy_hp <= 70 && enemy_hp > 40) {
        return Wait(hp, name);
    }

    // 🔹 3. 상대 HP가 40 이하 → 막판 마무리
    if (enemy_hp <= 40) {
        return Wait(hp, name);
    }

    // 🔹 4. 그 외의 상황에서는 조심스럽게 방어(Wait)
    // -> HP 유지 + 공격 밸런스
    return Wait(hp, name);
}