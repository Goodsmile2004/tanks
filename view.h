#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;
void getplayercoordinateforview(sf::Vector2f c) { //������� ��� ���������� ��������� ������

	view.setCenter(c.x, c.y); //������ �� �������, ��������� ��� ���������� ������. +100 - �������� ������ �� ���� ������. �����������������

}

