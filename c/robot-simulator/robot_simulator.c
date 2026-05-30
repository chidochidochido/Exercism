#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t movingRobot = {direction, {x, y}};

    return movingRobot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    unsigned short int index = 0;
    
    while(commands[index] != '\0')
    {
        switch(commands[index])
        {
            case 'R':
                robot->direction++;
                if(robot->direction >= DIRECTION_MAX)
                    robot->direction = DIRECTION_NORTH;
                break;

            case 'A':
                if(robot->direction == DIRECTION_EAST)
                    robot->position.x++;
                else if(robot->direction == DIRECTION_WEST)
                    robot->position.x--;
                else if(robot->direction == DIRECTION_NORTH)
                    robot->position.y++;
                else if(robot->direction == DIRECTION_SOUTH)
                    robot->position.y--;
                break;
        
            case 'L':
                if(robot->direction == DIRECTION_NORTH)
                    robot->direction = DIRECTION_WEST;
                else
                    robot->direction--;
                break;        
        }
        index++;
    }
}