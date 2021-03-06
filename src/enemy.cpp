#include "enemy.hpp"

int Enemy::width = 1200;
int Enemy::height = 800;

Enemy::Enemy(std::vector<sf::RectangleShape>* enemies)
:	enemies(enemies)
{}

Enemy::~Enemy(){

	enemies = NULL;
}


void Enemy::createRecEnemy(){

	recEnemy.setSize(sf::Vector2f(32.f, 32.f));
	recEnemy.setPosition(static_cast<float>((rand() % static_cast<int>(1168))), 0.f);		// rand() only takes int, then converting into float

	recEnemy.setFillColor(sf::Color::Cyan);
	recEnemy.setOutlineColor(sf::Color::Cyan);
	recEnemy.setOutlineThickness(1.f);

	enemies->push_back(this->recEnemy);
}

void Enemy::spawnEnemy(){
	
	// Updating timer for enemy spawns
	if (enemies->size() < maxEnemies){
		if (enemySpawnTimer >= enemySpawnTimerMax){
			// Spawn enemy and reset timer
			createRecEnemy();
			enemySpawnTimer = 0.f;
		}
		else{
			enemySpawnTimer += 1.f;
		}
	}
}

void Enemy::moveEnemy(){
	// Move enemies
	for (int i = 0; i < enemies->size(); ++i){
		(*enemies)[i].move(0.f, 3.f);
	}
}

void Enemy::updateEnemy(){
	spawnEnemy();
	moveEnemy();
}