#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.h"
#include "Config.h"
#include "map.h"
#include "view.h"
using namespace sf;
// �������� GitHub
int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");

	Player p("tank.png", "player", sf::Vector2f(500, 500), 3, 0.2, 3, 5);

	//view.reset(sf::FloatRect(0, 0, 640, 480));//������ "����" ������ ��� �������� ������� ���� ������. (����� ����� ������ ��� �����) ��� �� ���� �������������.
	int framerate = 100;
	float elapsedMillisecondsExpected = 1000.f / framerate,offsetX = 0;

	Image map_image;//������ ����������� ��� �����
	map_image.loadFromFile("images/map.png");
	Texture map;//�������� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	Sprite s_map;//������ ������ ��� �����
	s_map.setTexture(map);//�������� �������� ��������

	while (window.isOpen())
	{
		sf::Clock clock;
		float elapsedMilliseconds = clock.restart().asMicroseconds();

		p.control(window);
		p.rotateTurret();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
		for (int i = 0; i < frames; ++i) p.Update(elapsedMillisecondsExpected);

		std::cout << p.m_speedMovement << std::endl;
		

		
		window.clear();
		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 64, 64)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(128, 0, 64, 64));//���� ��������� ������ s, �� ������ 2� ���������
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 128, 64, 64));//���� ��������� ������ 0, �� ������ 3� ���������
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(64,0, 64, 64));

				s_map.setPosition(j * 128, i * 128);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				window.draw(s_map);//������ ���������� �� �����
			}
		p.draw(window);
		window.display();
	}
	return 0;
}