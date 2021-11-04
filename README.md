# SDL 2D Game Engine
A 2D Game framework written in C++ with SDL, following the entity-component-system architecture. This framework implements a few basic features that would be useful in a 2D game.

## Overview
### RenderSystem
This system simply renders entities based on their sprites and transforms. Different entities may have the same textures but different transforms, allowing them to appear at different positions with different sizes.

### TextureManager
Contains utility functions to load and draw textures.

### InputManager
This class handles keyboard events, mapping inputs to actions which the game logic (i.e. systems) sees and responds to. Functions are provided for changing and removing keybinds.

### MovementSystem
This system moves the player based on the commands active in the InputManager.

### Tilemap
Loads and draws the tilemap for the background.

### CollisionSystem
Detects collisions between entities that have RectCollider components. This system uses axis-aligned bounding boxes for collision detection, and can render bounding boxes for debug purposes.

### BasicEnemyAISystem
This system can be used to give enemies basic behaviour. Enemies can be in two states: idle or angered. When an enemy is idle it moves from left to right, paying no attention to the player. However once the enemy collides with the player it becomes aggressive and follows the player around the screen.

## ECS Architecture
### Definitions
**Entity:** An entity is an object in the game world and is represented as an ID that is used to group several components.

**Component:** A component is structured data that stores information about an entity.

**System:** A system is something that performs some function on every entity matching its signature (whether that be manipulating the data in the entity's components, or using the component data to render something).

**Signature:** The signature of an entity is a representation of the components it needs access to in order to perform its functionality.
