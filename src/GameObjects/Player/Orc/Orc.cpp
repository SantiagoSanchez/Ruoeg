#include "Orc.h"

Orc::Orc(Dungeon &dungeon) : Player(Player::Race::Orc, dungeon)
{
	max_health_points_ = 150;
	health_points_ = max_health_points_;
	attack_points_ = 15;
	armor_points_ = 15;
	color_ = GameObject::Color::White_Green;
}

Orc::~Orc()
{
}

void Orc::levelUp()
{
	max_health_points_ += 15;
	health_points_ = max_health_points_;
	attack_points_ += 10;
	armor_points_ += 10;
	experience_points_ = 0;
	max_experience_points_ = static_cast<int>(max_experience_points_ * 1.50);
	level_ += 1;
}

void Orc::draw(WINDOW *win)
{
	doFOV();

	Curses::mvwaddch(win, location_.y, location_.x, 
		static_cast<char>(type_) | 
		COLOR_PAIR(static_cast<int>(color_)));

	if(color_ != GameObject::Color::White_Green)
	{
		wnoutrefresh(win);
		Curses::napms(50);
		color_ = GameObject::Color::White_Green;
	}
}