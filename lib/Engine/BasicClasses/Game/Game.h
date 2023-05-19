#pragma once

#include "..\Ray\Ray.h"
#include "..\EntitiesList\EntitiesList.h"


namespace Engine
{
    class Game
	{
	public:
		EntitiesList gameEntities;
		CoordinateSystem cs;

		Game(CoordinateSystem cs, EntitiesList gameEntities);

		void Run();

		void Update();

		void Exit();

		Entity GetEntityClass();

		Ray GetRayClass();


		class Object : public Entity
		{
		public:
			Point position;
			Vector direction;

			Object(Game& game);

			Object(Game& game, Point position, Vector direction);

			void Move(float distance);

			void PlanarRotate(int axisIndex1, int axisIndex2, float angle);

			void Rotate3D(float angle1, float angle2, float angle3);

			void SetPosition(Point position);

			void SetDirection(Vector direction);
		};


		class Camera : public Object
		{
		public:
			float hfov;
			float vfov;
			float drawDistance;

			Camera(Game& game, float hfov, float drawDistance);

			Camera(Game& game, float hfov, float vfov, float drawDistance);

			Camera(Game& game, float hfov, Point lookAt, float drawDistance);

			Camera(Game& game, float hfov, float vfov, Point lookAt, float drawDistance);
		};


	};
}