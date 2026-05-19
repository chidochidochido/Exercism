#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    attack_status_t returnAttackStatus = CAN_NOT_ATTACK;

    if(((queen_1.row == queen_2.row) && (queen_1.column == queen_2.column)) ||
        queen_1.row > 7 ||
        queen_2.row > 7 ||
        queen_1.column > 7 ||
        queen_2.column > 7
       )
    {
        returnAttackStatus = INVALID_POSITION;
    }
    else if((queen_1.row == queen_2.row) || (queen_1.column == queen_2.column))
    {
        returnAttackStatus = CAN_ATTACK;
    }
    else
    {
        short testRow = queen_1.row + 1;
        short testColumn = queen_1.column - 1;

        while (testColumn >= 0 && returnAttackStatus != CAN_ATTACK)
        {
            if(queen_2.row == testRow && queen_2.column == testColumn)
            {
                returnAttackStatus = CAN_ATTACK;
            }

            testRow++;
            testColumn--;
        }

        if(returnAttackStatus != CAN_ATTACK)
        {
            testRow = queen_1.row - 1;
            testColumn = queen_1.column + 1;
            
            while (testRow >= 0 && returnAttackStatus != CAN_ATTACK)
            {
                if(queen_2.row == testRow && queen_2.column == testColumn)
                {
                    returnAttackStatus = CAN_ATTACK;
                }
    
                testRow--;
                testColumn++;
            }
        }

        if(returnAttackStatus != CAN_ATTACK)
        {
            testRow = queen_1.row - 1;
            testColumn = queen_1.column - 1;
            
            while (testRow >= 0 && testColumn >= 0 && returnAttackStatus != CAN_ATTACK)
            {
                if(queen_2.row == testRow && queen_2.column == testColumn)
                {
                    returnAttackStatus = CAN_ATTACK;
                }
    
                testRow--;
                testColumn--;
            }
        }  
    }
    
    return returnAttackStatus;
}