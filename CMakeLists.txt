cmake_minimum_required(VERSION 3.12)
project(CPROGLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/module)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_library(CPROG STATIC CPROG.cpp EventLoop.cpp  Sprite.cpp Window.cpp Entity.cpp SpriteEntity.cpp ControlledSpriteEntity.cpp ControlledSpriteEntity.h Background.cpp Background.h Tile.cpp Tile.h Map.cpp Map.h DebugInfo.cpp DebugInfo.h PhysicsObject.cpp PhysicsObject.h MemPtrCommand.cpp MemPtrCommand.h KeyCommand.cpp KeyCommand.h Collider.h Collider.cpp BoundingBoxCollider.cpp BoundingBoxCollider.h PerPixelCollider.cpp PerPixelCollider.h Collider.cpp AnimatedSprite.cpp AnimatedSprite.h MapCollisionObj.h TextField.cpp TextField.h FuncPtrCommand.cpp FuncPtrCommand.h AnimatedControlledSpriteEntity.cpp AnimatedControlledSpriteEntity.h AnimatedSpriteEntity.cpp AnimatedSpriteEntity.h Scene.cpp Scene.h)
set_target_properties(CPROG PROPERTIES PUBLIC_HEADER
        "CPROG.h;EventLoop.h;Sprite.h;Window.h;Entity.h;SpriteEntity.h;ControlledSpriteEntity.h;Background.h;Tile.h;Map.h;DebugInfo.h;PhysicsObject.h;KeyCommand.h;MemPtrCommand.h;Collider.h;PerPixelCollider.h;BoundingBoxCollider.h;MapCollisionObj.h;FuncPtrCommand.h;AnimatedSprite.h;AnimatedSpriteEntity.h;Scene.h")

target_link_libraries(CPROG PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY} ${SDL2_TTF_LIBRARY})
install(TARGETS CPROG DESTINATION C:/cproginc/lib
        PUBLIC_HEADER DESTINATION C:/cproginc/include)