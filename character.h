#pragma once


class Character
{
public:
    Character(
        int x,
        int y,
        int healthpoints,
        int attack,
        int defence);
    Character();

    int x;
    int y;
    int healthpoints;
    int attack;
    int defence;
};