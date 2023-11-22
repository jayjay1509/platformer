#include "game.h"

#include "View.h"

sf::View newView;
int life = 3;
int index_coin;
int index_frame_coin;


std::vector<sf::Sprite> sprites;
std::vector<sf::Sprite> sprites2;

void Game::init()
{

	// Create the window
	window_.create(sf::VideoMode(800, 600), "Platformer");
	View view(800, 600);
	window_.setVerticalSyncEnabled(false);
	window_.setFramerateLimit(100);

	// Create tile shape
	tile_shape_ = sf::RectangleShape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	tile_shape_.setFillColor(sf::Color(209, 147, 67));

	if(tile_texture.loadFromFile("data/sprites/tile_0042.png"))
	{
		tile_sprite.setTexture(tile_texture);
		tile_sprite.setScale(TILE_SIZE_PX / (float)tile_texture.getSize().x, TILE_SIZE_PX / (float)tile_texture.getSize().y);
	}else
	{
		__debugbreak();
	}

	if (tile_texture2.loadFromFile("data/sprites/tile_0041.png"))
	{
		tile_sprite2.setTexture(tile_texture2);
		tile_sprite.setScale(TILE_SIZE_PX / (float)tile_texture2.getSize().x, TILE_SIZE_PX / (float)tile_texture2.getSize().y);
	}
	else
	{
		__debugbreak();
	}

	if (tile_texture3.loadFromFile("data/sprites/tile_0043.png"))
	{
		tile_sprite3.setTexture(tile_texture3);
		tile_sprite.setScale(TILE_SIZE_PX / (float)tile_texture3.getSize().x, TILE_SIZE_PX / (float)tile_texture3.getSize().y);
	}
	else
	{
		__debugbreak();
	}

	if (ground_t.loadFromFile("data/sprites/tile_0122.png"))
	{
		ground_s.setTexture(ground_t);
		ground_s.setScale(TILE_SIZE_PX / (float)ground_t.getSize().x, TILE_SIZE_PX / (float)ground_t.getSize().y);
	}
	else
	{
		__debugbreak();
	}

	if (spike_t.loadFromFile("data/sprites/tile_0068.png"))
	{
		spike_s.setTexture(spike_t);
		spike_s.setScale(TILE_SIZE_PX / (float)spike_t.getSize().x, TILE_SIZE_PX / (float)spike_t.getSize().y);
	}
	else
	{
		__debugbreak();
	}

	if (playerTexture.loadFromFile("data/sprites/tile_0000.png")) 
	{
		player_origin_shape_.setTexture(playerTexture);
	}
	else 
	{
		__debugbreak();
	}

	if (backgroundTexture.loadFromFile("data/sprites/origbig.png")) 
	{
		background.setTexture(backgroundTexture);
		background0.setTexture(backgroundTexture);
		background2.setTexture(backgroundTexture);
		background3.setTexture(backgroundTexture);
		background4.setTexture(backgroundTexture);
		background2.setPosition(2304, 0);
		background0.setPosition(-2304, 0);
		background3.setPosition(4608, 0);
		background4.setPosition(6912, 0);
		
	}
	else 
	{
		__debugbreak();
	}

	if (drapeux_t.loadFromFile("data/sprites/tile_0131.png"))
	{
		drapeux_s.setTexture(drapeux_t);
		drapeux_s.setOrigin(0,18);
		drapeux_s.setPosition(3450, 700);
		drapeux_s.setScale(1.5, 1.5);

	}
	else
	{
		__debugbreak();
	}

	if (drapeux_true_t.loadFromFile("data/sprites/drapeux.png"))
	{
		drapeux_true_s.setTexture(drapeux_true_t);
		drapeux_true_s.setOrigin(0, 18);
		drapeux_true_s.setPosition(3450, 700);
		drapeux_true_s.setScale(2, 2);

	}
	else
	{
		__debugbreak();
	}

	if (drapeux_arrive_t.loadFromFile("data/sprites/1212.png"))
	{
		drapeux_arrive_s.setTexture(drapeux_arrive_t);
		drapeux_arrive_s.setScale(20, 20);
		drapeux_arrive_s.setOrigin(0, 11);
		drapeux_arrive_s.setPosition(7500, 949);

	}
	else
	{
		__debugbreak();
	}

	if (you_win_t.loadFromFile("data/sprites/you_win3.png"))
	{
		you_win_s.setTexture(you_win_t);
		you_win_s.setOrigin(400, 310);
		you_win_s.setScale(1.2, 1.2);
	}
	else
	{
		__debugbreak();
	}

	if (you_lose_t.loadFromFile("data/sprites/you_lose2.png"))
	{
		you_lose_s.setTexture(you_lose_t);
		you_lose_s.setOrigin(960, 540);
		you_lose_s.setScale(0.6, 0.6);
	}
	else
	{
		__debugbreak();
	}

	if (heart_full_t.loadFromFile("data/sprites/tile_0044.png"))
	{
		heart_full_s.setTexture(heart_full_t);
		heart_full_s.setOrigin(9, 9);
		heart_full_s.setScale(3, 3);
	 
	}
	else
	{
		__debugbreak();
	}

	if (heart_empty_t.loadFromFile("data/sprites/tile_0046.png"))
	{
		heart_empty_s.setTexture(heart_empty_t);
		heart_empty_s.setOrigin(9, 9);
		heart_empty_s.setScale(2, 2);

	}
	else
	{
		__debugbreak();
	}




	if (coin_t.loadFromFile("data/sprites/coin.png")) 
		{
	    // Largeur d'un sprite individuel
	    const int spriteWidth = 20;

		for (int i = 0; i < coin_t.getSize().x / spriteWidth; i++) {
	        sf::Sprite sprite;
	        sprite.setTexture(coin_t);
	        sprite.setTextureRect(sf::IntRect(i * spriteWidth, 0, spriteWidth, coin_t.getSize().y));
	        sprite.setPosition(6450, 1000);
			sprite.setScale(2.5, 2.5);
			

	        sprites.push_back(sprite);
	    }
		}
	else
	{
	    // En cas d'�chec du chargement de la texture, vous pouvez d�clencher un point d'arr�t pour le d�bogage
	    __debugbreak();
	}

	if (sound_jump_b.loadFromFile("data/song/Jump 1.wav"))
	{
		sound_jump_s.setBuffer(sound_jump_b);
		sound_jump_s.setVolume(30);
	}
	else
	{
		__debugbreak();
	}

	if (sound_coin_b.loadFromFile("data/song/Success 1.wav"))
	{
		sound_coin_s.setBuffer(sound_coin_b);
		sound_coin_s.setVolume(100);
	}
	else
	{
		__debugbreak();
	}

	if (sound_cheakpoint_b.loadFromFile("data/song/chekpoint.wav"))
	{
		sound_cheakpoint_s.setBuffer(sound_cheakpoint_b);
		sound_cheakpoint_s.setVolume(100);
	}
	else
	{
		__debugbreak();
	}

	if (sound_dead_b.loadFromFile("data/song/Game Over 1.wav"))
	{
		sound_dead_s.setBuffer(sound_dead_b);
		sound_dead_s.setVolume(100);
	}
	else
	{
		__debugbreak();
	}

	if (sound_you_lose_b.loadFromFile("data/song/Mario death.wav"))
	{
		sound_you_lose_s.setBuffer(sound_you_lose_b);
		sound_you_lose_s.setVolume(100);
	}
	else
	{
		__debugbreak();
	}

	if (sound_you_lose_b.loadFromFile("data/song/Mario death.wav"))
	{
		sound_you_lose_s.setBuffer(sound_you_lose_b);
		sound_you_lose_s.setVolume(100);
	}
	else
	{
		__debugbreak();
	}

	if (sound_you_win_b.loadFromFile("data/song/Undertale.wav"))
	{
		sound_you_win_s.setBuffer(sound_you_win_b);
		sound_you_win_s.setVolume(100);
	}
	else
	{
		__debugbreak();
	}

	if (sound_main_b.loadFromFile("data/song/main.wav"))
	{
		sound_main_s.setBuffer(sound_main_b);
		sound_main_s.setVolume(30);
	}
	else
	{
		__debugbreak();
	}

	

	

	//tile_shape_.setOutlineColor(sf::Color(245, 213, 127));
	//tile_shape_.setOutlineThickness(-2);

	// Create cursor shape
	cursor_shape_ = sf::RectangleShape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	cursor_shape_.setFillColor(sf::Color(209, 147, 67, 0));
	cursor_shape_.setOutlineColor(sf::Color(250, 250, 250));
	cursor_shape_.setOutlineThickness(-3);

	// Create debug limit shapes
	debug_limit_shape_vertical_ = sf::RectangleShape(sf::Vector2f(2, 10000));
	debug_limit_shape_vertical_.setOrigin(1, 0);
	debug_limit_shape_vertical_.setFillColor(sf::Color(255, 0, 255));
	debug_limit_shape_horizontal_ = sf::RectangleShape(sf::Vector2f(10000, 2));
	debug_limit_shape_horizontal_.setOrigin(0, 1);
	debug_limit_shape_horizontal_.setFillColor(sf::Color(255, 0, 255));

	// Create player shape
	player_origin_shape_.setOrigin(12, 24);

	// Create background shape
	background.setOrigin(0, 0);


	hud_.StartChrono();
	sound_main_s.play();
}



void Game::update()
{
	

	float limit_x_low = -400.f;
	float limit_x_high = 1000000000.f;
	float limit_y_low = 300.f;
	float limit_y_high = 1000000000.f;

	// Performed. Now perform GPU stuff...
	deltaTime_ = (float)std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart).count();
	frameStart = std::chrono::high_resolution_clock::now();



	newView = window_.getView();

	if (!windowResized)
	{
		if (player_pos_.y >= 950)
		{
			newView.setCenter(player_pos_.x, 950);
			if (player_pos_.x <= 1000)
			{
				newView.setCenter(1000, 950);
			}

			else if (player_pos_.x >= 7500)
			{
				newView.setCenter(7500, player_pos_.y);
			}
		}
		else if (player_pos_.y <= 600)
		{
			newView.setCenter(player_pos_.x, 600);
			if (player_pos_.x <= 1000)
			{
				newView.setCenter(1000, 600);
			}

			else if (player_pos_.x >= 7500)
			{
				newView.setCenter(7500, player_pos_.y);
			}


		}

		else if (player_pos_.x <= 1000)
		{
			newView.setCenter(1000, player_pos_.y);
		}

		else if (player_pos_.x >= 7500)
		{
			newView.setCenter(7500, player_pos_.y);
		}

		else
		{
			newView.setCenter(player_pos_);
		}
	}
	else
	{
		if (player_pos_.y >= 950)
		{
			newView.setCenter(player_pos_.x, 950);
			if (player_pos_.x <= 1000)
			{
				newView.setCenter(1000, 950);
			}

			else if (player_pos_.x >= 7000)
			{
				newView.setCenter(7000, player_pos_.y);
			}
		}
		else if (player_pos_.y <= 600)
		{
			newView.setCenter(player_pos_.x, 600);
			if (player_pos_.x <= 1000)
			{
				newView.setCenter(1000, 600);
			}

			else if (player_pos_.x >= 7000)
			{
				newView.setCenter(7000, player_pos_.y);
			}


		}

		else if (player_pos_.x <= 1000)
		{
			newView.setCenter(1000, player_pos_.y);
		}

		else if (player_pos_.x >= 7000)
		{
			newView.setCenter(7000, player_pos_.y);
		}

		else
		{
			newView.setCenter(player_pos_);
		}
	}

	window_.setView(newView);

	const sf::View& currentView = window_.getView();
	hud_.Init(window_);

	hud_.Update(window_.getView());

	
	

	

	if(player_pos_.y >= 1199)
	{
		if(checkpoint)
		{
			player_pos_ = sf::Vector2f(3450, 699);
		}
		else
		{
			player_pos_ = sf::Vector2f(1000, 949);
		}
		--life;
		if (life >= 1)
		{
			sound_dead_s.play();
		}
		
	}

	if (player_pos_.x > 6450&&player_pos_.x<6500&&player_pos_.y>1000&&player_pos_.y<1050 )
	{
		coin = true;
		if (coin_musik == 0)
		{
				sound_coin_s.play();
				coin_musik = 1;
		}
		
	}

	

	if (life <= 0)
	{
		you_lose = true;
		if (you_dead_musik == 0)
		{
			sound_main_s.stop();
			sound_you_lose_s.play();
			you_dead_musik = 1;
		}
	}

	


	if (player_pos_.x >= 3450)
	{
		checkpoint = true;
		if (cheakpoint_musik == 0)
		{
			sound_cheakpoint_s.play();
			cheakpoint_musik = 1;
		}
	}

	

	if (player_pos_.x >= 7500&& coin)
	{
		player_pos_ = sf::Vector2f(2500, 700);
		you_win = true;
		
	}

	if (cheat_code1 && cheat_code2 && cheat_code3 && cheat_code4)
	{
		you_win = true;
	}

	const sf::Vector2i player_coords = tilemap_.PosToCoords(player_pos_);
	constexpr int margin = 1;
	if (tilemap_.TileAt(player_coords + sf::Vector2i(1, 0))) {
		limit_x_high = (player_coords.x + 1) * TILE_SIZE_PX - margin;
	}
	if (tilemap_.TileAt(player_coords + sf::Vector2i(-1, 0))) {
		limit_x_low = (player_coords.x) * TILE_SIZE_PX + margin;
	}
	if (tilemap_.TileAt(player_coords + sf::Vector2i(0, 1))) {
		limit_y_high = (player_coords.y + 1) * TILE_SIZE_PX - margin;
	}
	if (tilemap_.TileAt(player_coords + sf::Vector2i(0, -1))) {
		limit_y_low = (player_coords.y) * TILE_SIZE_PX + margin;
	}

	// moving the player!
	sf::Vector2f delta(0, 0);
	const float kPlayerSpeed = 3;
	const float kJumpSpeed = -8;
	constexpr float kFallLimit = 3;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		delta += sf::Vector2f(-kPlayerSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		delta += sf::Vector2f(kPlayerSpeed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
	
		levelediting = !levelediting;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) 
	{
		cheat_code1 = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		if (cheat_code1)
		{
			cheat_code2 = true;
		}
		else
		{
			cheat_code1 = false;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		if (cheat_code1)
		{
			cheat_code3 = true;
		}
		else
		{
			cheat_code1 = false;
			cheat_code2 = false;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		if (cheat_code1)
		{
			cheat_code4 = true;
		}
		else
		{
			cheat_code1 = false;
			cheat_code2 = false;
			cheat_code3 = false;
		}
	}


	

	// Cancel vertical velocity if grounded
	if (grounded) {
		player_vel_.y = 0;
	}

	// jumping
	bool jump_key_is_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	if (jump_key_is_down && grounded) 
	{
		player_vel_.y = kJumpSpeed;
		sound_jump_s.play();
	}
	

	// Falling speed limit
	if (player_vel_.y > kFallLimit) {
		player_vel_.y = kFallLimit;
	}

	constexpr float kMinFallForce = 0.15f;
	constexpr float kMaxFallForce = 0.6f;
	// Gravity
	player_vel_.y += jump_key_is_down ? kMinFallForce : kMaxFallForce; // accel
	if (!you_win && !you_lose)
	{
		delta += sf::Vector2f(0, player_vel_.y);

		player_pos_ += delta;
	}


	if (player_pos_.x >= limit_x_high - (player_size.x / 2)) {
		player_pos_.x = limit_x_high - (player_size.x / 2);
	}
	if (player_pos_.x <= limit_x_low + (player_size.x / 2)) {
		player_pos_.x = limit_x_low + (player_size.x / 2);
	}

	grounded = false;
	if (player_pos_.y >= limit_y_high) {
		player_pos_.y = limit_y_high;
		grounded = true;
	}

	if (player_pos_.y <= limit_y_low + player_size.y) 
	{
		player_pos_.y = limit_y_low + player_size.y;
		player_vel_.y = 0;
	}
	
	

	 
	// Determine tile coordinates that the mouse is hovering
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
	sf::Vector2i mouseCoord_TilesRelative = sf::Vector2i(
		window_.mapPixelToCoords(mouse_pos, window_.getView()).x / TILE_SIZE_PX,
		window_.mapPixelToCoords(mouse_pos, window_.getView()).y / TILE_SIZE_PX
		);


	// Editor interaction
	
	if (levelediting)
	{

		bool mouse_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		bool mouse_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);
		bool shift_down = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

		if (mouse_left || mouse_right) {
			// Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
			if (tilemap_.InBounds(mouseCoord_TilesRelative))
			{
				if (mouse_left)
				{
					if (shift_down)
						// Set the hovered tile to true or false depending on the pressed mouse button.
						tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::kRed;
					else
						// Set the hovered tile to true or false depending on the pressed mouse button.
						tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::kYellow;

				}
				else
				{
					tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::kNoTile;
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::kRed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::Kright;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::Kspike;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::Kground;
		}
	}
	if (windowResized)
	{
		you_lose_s.setScale(window_.getSize().x / 1000, window_.getSize().y / 800);
		you_win_s.setScale(2.5,2.5); // impossible to set scale with the get.size for this asset so I hope you have the same screen
	}
	else
	{
		you_lose_s.setScale(0.6, 0.6);
		you_win_s.setScale(1.2, 1.2);
	}
	
	// clear the window with black color
	window_.clear(sf::Color::Black);
	
	//Draw the background

	
	window_.draw(background);
	window_.draw(background2);
	window_.draw(background0);
	window_.draw(background3);
	window_.draw(background4);

	


	// draw the tilemap
	for (int y = 0; y < TILEMAP_HEIGHT; y++) {
		for (int x = 0; x < TILEMAP_WIDTH; x++) {

			tile_shape_.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
			tile_sprite.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);

			Tilemap::TileType tileType = (Tilemap::TileType)tilemap_.cells[x + y * TILEMAP_WIDTH];


			switch (tileType)
			{

			case Tilemap::TileType::kYellow:
				//window_.draw(tile_shape_);
				tile_sprite.setTexture(tile_texture);
				window_.draw(tile_sprite);
				break;

			case Tilemap::TileType::kRed:
				tile_sprite.setTexture(tile_texture2);
				window_.draw(tile_sprite);
				break;

			case Tilemap::TileType::Kright:
				tile_sprite.setTexture(tile_texture3);
				window_.draw(tile_sprite);
				break;
			case Tilemap::TileType::Kground:
				tile_sprite.setTexture(ground_t);
				window_.draw(tile_sprite);
				break;
			case Tilemap::TileType::Kspike:
				tile_sprite.setTexture(spike_t);
				window_.draw(tile_sprite);
				break;

			case Tilemap::TileType::kNoTile:
			default:
				break;
			}

			//if ( ) {
			//    // draw tile shape at correct position
			//    tile_shape_.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
			//    window_.draw(tile_shape_);
			//} else {
			//    // draw nothing                    
			//}
		}
	}



	
	// Draw the HUD above everything else
	window_.draw(hud_);

	window_.draw(drapeux_arrive_s);

	if (checkpoint)
	{
		window_.draw(drapeux_true_s);
	}
	else
	{
		window_.draw(drapeux_s);
	}



	// Visualize limits
	if (levelediting)
	{


		debug_limit_shape_vertical_.setPosition(limit_x_high, 0);
		window_.draw(debug_limit_shape_vertical_);
		debug_limit_shape_vertical_.setPosition(limit_x_low, 0);
		window_.draw(debug_limit_shape_vertical_);
		debug_limit_shape_horizontal_.setPosition(0, limit_y_high);
		window_.draw(debug_limit_shape_horizontal_);
		debug_limit_shape_horizontal_.setPosition(0, limit_y_low);
		window_.draw(debug_limit_shape_horizontal_);

		// draw selection cursor
		cursor_shape_.setPosition(TILE_SIZE_PX * mouseCoord_TilesRelative.x, TILE_SIZE_PX * mouseCoord_TilesRelative.y);
		window_.draw(cursor_shape_);
	}

	if (!coin)
	{
		window_.draw(sprites[index_coin]);
	}
	else
	{
		sprites[index_coin].setScale(1, 1);
		sprites[index_coin].setPosition(newView.getCenter().x - 10, newView.getCenter().y - window_.getSize().y / 2 + 20);
		window_.draw(sprites[index_coin]);
	}
	
	

	index_frame_coin++;

	if (index_frame_coin == 6)
	{
		index_frame_coin = 0;
		index_coin++;
	}

	if (index_coin == 9)
	{
		index_coin = 0;
	}

	// draw player
	player_box_shape_.setPosition(player_pos_.x, player_pos_.y);
	window_.draw(player_box_shape_);
	player_origin_shape_.setPosition(player_pos_.x, player_pos_.y);
	window_.draw(player_origin_shape_);

	switch (life)
	{
		case 3:
			heart_full_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 25, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_full_s);
			heart_full_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 75, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_full_s);
			heart_full_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 125, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_full_s);
			break;
		case 2:
			heart_full_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 25, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_full_s);
			heart_full_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 75, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_full_s);
			heart_empty_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 125, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_empty_s);
			break;

		case 1:
			heart_full_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 25, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_full_s);
			heart_empty_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 75, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_empty_s);
			heart_empty_s.setPosition(newView.getCenter().x + window_.getSize().x / 2 - 125, newView.getCenter().y - window_.getSize().y / 2 + 50);
			window_.draw(heart_empty_s);
			break;
	}




	hud_.FrameTime(deltaTime_);

	if (you_win)
	{
		you_win_s.setPosition(player_pos_);
		window_.draw(you_win_s);
		if (you_win_musik == 0)
		{
			sound_main_s.stop();
			sound_you_win_s.play();
			you_win_musik = 1;
		}
	}

	if (you_lose)
	{
		you_lose_s.setPosition(player_pos_);
		window_.draw(you_lose_s);
	}

	// end the current frame
	window_.display();

	// window.draw, etc.
	frameEnd = std::chrono::high_resolution_clock::now();

}

