#include "../Game.h"

namespace Engine
{
    Game::GameEntity::GameEntity() : Entity(CoordinateSystem()) 
    {
        
    }
    
    Game::GameEntity::GameEntity(Game& game) : Entity(game.cs)
    {
        
    }
}