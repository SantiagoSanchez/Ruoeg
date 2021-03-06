#include "Human.h"

Human::Human(Dungeon &dungeon) : Player(Player::Race::Human, dungeon)
{
	max_health_points_ = 50;
	health_points_ = max_health_points_;
	attack_points_ = 5;
	armor_points_ = 5;
	color_ = GameObject::Color::White_Black;
}

Human::~Human()
{
}

void Human::levelUp()
{
	max_health_points_ += 15;
	health_points_ = max_health_points_;
	attack_points_ += 3;
	armor_points_ += 3;
	experience_points_ = 0;
	max_experience_points_ = static_cast<int>(max_experience_points_ * 1.50);
	level_ += 1;
}

void Human::draw(WINDOW *win)
{
	doFOV();

	Curses::mvwaddch(win, location_.y, location_.x, 
		static_cast<char>(type_) | 
		COLOR_PAIR(static_cast<int>(color_)));

	if(color_ != GameObject::Color::White_Black)
	{
		wnoutrefresh(win);
		Curses::napms(time_to_flash_);
		color_ = GameObject::Color::White_Black;
	}
}