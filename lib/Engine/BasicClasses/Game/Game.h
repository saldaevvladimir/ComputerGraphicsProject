#pragma once


#include "../Ray/Ray.h"
#include "../EntitiesList/EntitiesList.h"
#include "../Configuration/Configuration.h"

#include <variant>
#include <string>
#include <any>


namespace Engine
{
    class Game
	{
	public:
		EntitiesList gameEntities;
		CoordinateSystem cs;

		Game();

		Game(CoordinateSystem cs, EntitiesList gameEntities);

		void operator = (Game game);

		void Run();

		void Update();

		void Exit();

		Entity GetEntityClass();

		Ray GetRayClass();


		class GameEntity : public Entity
		{
		public:
			GameEntity();
			GameEntity(Game& game);
		};

		class Object : public Game::GameEntity
		{
		public:
			Object();

			Object(GameEntity& gameEntity);

			Object(GameEntity& gameEntity, Point position, Vector direction);

			void Move(float distance);

			void PlanarRotate(int axisIndex1, int axisIndex2, float angle);

			void Rotate3D(float angle1, float angle2, float angle3);

			void SetPosition(Point position);

			void SetDirection(Vector direction);
		};


		class Camera : public Game::Object
		{
		public:

			Camera(Game::Object& object, float hfov, float drawDistance);

			Camera(Game::Object& object, float hfov, float vfov, float drawDistance);

			Camera(Game::Object& object, float hfov, Point lookAt, float drawDistance);

			Camera(Game::Object& object, float hfov, float vfov, Point lookAt, float drawDistance);
		
			std::vector<std::vector<Ray>> GetRaysMatrix(int height, int width);

		};
	};
}