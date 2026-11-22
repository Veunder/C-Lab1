//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <random>
//
//
//int main() {
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    int minRange = 0;
//    int maxRange = 5;
//    std::uniform_int_distribution<int> distribution(minRange, maxRange);
//    sf::Texture atlas;
//    if (!atlas.loadFromFile(R"(C:\Users\misha\CLionProjects\SFML\no_background.png)")) {
//        std::cout << "Не удалось открыть файл!\n";
//        exit(0);
//    }
//
//    auto window = sf::RenderWindow{{600u, 600u}, "CMake SFML Project"};
//    window.setFramerateLimit(60);
//
//    sf::IntRect dino_frames[2] = {sf::IntRect(938, 4, 40, 43), sf::IntRect(982, 4, 40, 43)};
//    sf::IntRect obstacleRects[] = {
//            sf::IntRect(229, 3, 15, 33),
//            sf::IntRect(263, 3, 15, 33),
//            sf::IntRect(297, 3, 15, 33),
//            sf::IntRect(333, 3, 23, 48),
//            sf::IntRect(383, 3, 23, 48),
//            sf::IntRect(432, 3, 49, 48)
//    };
//
//
//    bool is_active = false;
//    int current_frame = 0;
//
//    sf::Sprite dino;
//    dino.setTexture(atlas);
//    dino.setTextureRect(dino_frames[current_frame]);
//
//    sf::Sprite ground1;
//    ground1.setTexture(atlas);
//    ground1.setTextureRect(sf::IntRect(1, 53, 1200, 15));
//    ground1.setPosition(0, 290);
//
//    sf::Sprite ground2;
//    ground2.setTexture(atlas);
//    ground2.setTextureRect(sf::IntRect(1, 53, 1200, 15));
//    ground2.setPosition(ground1.getGlobalBounds().width, 290);
//
//    sf::Sprite obstacle;
//    obstacle.setTexture(atlas);
//    obstacle.setTextureRect(obstacleRects[distribution(gen)]);
//    obstacle.setPosition(window.getSize().x, 303 - obstacle.getGlobalBounds().height);
//
//    sf::Sprite startButton;
//    startButton.setTexture(atlas);
//    startButton.setTextureRect(sf::IntRect(255, 69, 34, 30));
//    startButton.setPosition(window.getSize().x / 2 - startButton.getGlobalBounds().width / 2,
//                            window.getSize().y / 2 - startButton.getGlobalBounds().height / 2);
//
//    float ground_speed = -5;
//    float ground_acceleration = -0.0001;
//    float player_gravity = 0;
//
//    dino.setPosition(10, 260);
//
//    sf::Clock time;
//
//    while (window.isOpen()) {
//        for (auto event = sf::Event{}; window.pollEvent(event);) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//            if (is_active) {
//                if (event.type == sf::Event::KeyPressed) {
//                    if (event.key.code == sf::Keyboard::Space) {
//                        if (dino.getGlobalBounds().top >= 260) {
//                            player_gravity = -15;
//                        }
//                    }
//                }
//            }
//            if (!is_active) {
//                if (event.type == sf::Event::MouseButtonPressed) {
//                    if (event.mouseButton.button == sf::Mouse::Left) {
//                        if (startButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
//                            is_active = true;
//                            ground_speed = -5;
//                            dino.setPosition(10, 260);
//                            obstacle.setPosition(window.getSize().x, 303 - obstacle.getGlobalBounds().height);
//                        }
//                    }
//                }
//            }
//        }
//
//        if (!is_active) {
//            window.clear(sf::Color::White);
//            window.draw(startButton);
//            window.display();
//        } else {
//            ground1.move(ground_speed, 0);
//            ground2.move(ground_speed, 0);
//            obstacle.move(ground_speed, 0);
//            if (ground1.getPosition().x + ground1.getGlobalBounds().width < 0) {
//                ground1.setPosition(ground2.getPosition().x + ground2.getGlobalBounds().width, ground1.getPosition().y);
//            }
//            if (ground2.getPosition().x + ground2.getGlobalBounds().width < 0) {
//                ground2.setPosition(ground1.getPosition().x + ground1.getGlobalBounds().width, ground1.getPosition().y);
//            }
//            ground_speed += ground_acceleration;
//
//            window.clear(sf::Color::White);
//
//            player_gravity++;
//            if (time.getElapsedTime().asSeconds() >= 0.1) {
//                current_frame++;
//                current_frame %= 2;
//                dino.setTextureRect(dino_frames[current_frame]);
//                time.restart();
//            }
//
//            if (dino.getGlobalBounds().intersects(obstacle.getGlobalBounds())) {
//                is_active = false;
//            }
//            dino.move(0, player_gravity);
//            if (dino.getGlobalBounds().top >= 260) {
//                dino.setPosition(10, 260);
//            }
//
//            window.draw(ground1);
//            window.draw(ground2);
//            if (obstacle.getGlobalBounds().left + obstacle.getGlobalBounds().width <= 0) {
//                int rnd_number = distribution(gen);
//                obstacle.setTextureRect(obstacleRects[rnd_number]);
//                obstacle.setPosition(window.getSize().x, 303 - obstacle.getGlobalBounds().height);
//            }
//            window.draw(obstacle);
//            window.draw(dino);
//
//            window.display();
//        }
//    }
//}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <SFML/Audio.hpp>

using namespace std;

class Obstacle {
public:
    Obstacle(sf::Vector2f position, sf::Texture &texture, sf::IntRect &TextureRect) {
        sprite.setTexture(texture);
        sprite.setTextureRect(TextureRect);
        sprite.setPosition(position);
    }

    bool isOutsideWindow() {
        return sprite.getPosition().x + sprite.getGlobalBounds().width < 0;
    }

    sf::Sprite sprite;
};

void game_init() {

}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    int minRange = 0;
    int maxRange = 6;
    std::uniform_int_distribution<int> distribution(minRange, maxRange);

    sf::Texture atlas;
    if (!atlas.loadFromFile(R"(C:\Users\misha\CLionProjects\SFML\no_background.png)")) {
        cout << "Не удалось открыть файл\n";
        exit(0);
    }

    sf::Text scoreText;
    sf::Font font;
    if (!font.loadFromFile(R"(C:\Users\misha\CLionProjects\SFML\Pentapixel.ttf)")) {
        cout << "Не удалось открыть файл\n";
        exit(0);
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);
    int score = 0;

    sf::SoundBuffer jumpBuffer;
    if (!jumpBuffer.loadFromFile(R"(C:\Users\misha\CLionProjects\SFML\jump.wav)")) {
        cout << "Не удалось загрузить звук прыжка" << endl;
        exit(0);
    }

    sf::Sound jumpSound;
    jumpSound.setBuffer(jumpBuffer);

    sf::SoundBuffer dieBuffer;
    if (!dieBuffer.loadFromFile(R"(C:\Users\misha\CLionProjects\SFML\die.wav)")) {
        cout << "Не удалось загрузить звук прыжка" << endl;
        exit(0);
    }

    sf::Sound dieSound;
    dieSound.setBuffer(dieBuffer);

    sf::SoundBuffer pointBuffer;
    if (!pointBuffer.loadFromFile(R"(C:\Users\misha\CLionProjects\SFML\point.wav)")) {
        cout << "Не удалось загрузить звук прыжка" << endl;
        exit(0);
    }

    sf::Sound pointSound;
    pointSound.setBuffer(pointBuffer);

    auto window = sf::RenderWindow{{800u, 600u}, "CMake SFML Project"};

    sf::Sprite startButton;
    startButton.setTexture(atlas);
    startButton.setTextureRect(sf::IntRect(255, 69, 34, 30));
    startButton.setPosition(window.getSize().x / 2 - startButton.getGlobalBounds().width / 2,
                            window.getSize().y / 2 - startButton.getGlobalBounds().height / 2);

    sf::IntRect dinoRunFrames[2] = {
            sf::IntRect(938, 4, 40, 43),
            sf::IntRect(982, 4, 40, 43)
    };
    int currentDinoFrame = 0;
    int currentBirdFrame = 6;

    sf::Sprite dino;
    dino.setTexture(atlas);
    dino.setTextureRect(dinoRunFrames[currentDinoFrame]);

    float player_gravity = 0;

    sf::Sprite ground1, ground2;
    ground1.setTexture(atlas);
    ground2.setTexture(atlas);

    sf::IntRect groundRect(1, 53, 1200, 15);

    ground1.setTextureRect(groundRect);
    ground2.setTextureRect(groundRect);

    ground1.setPosition(0, 290);
    ground2.setPosition(ground1.getGlobalBounds().width, 290);

    dino.setPosition(10, 260);

    sf::IntRect obstacleRects[] = {
            sf::IntRect(229, 3, 15, 33),
            sf::IntRect(263, 3, 15, 33),
            sf::IntRect(297, 3, 15, 33),
            sf::IntRect(333, 3, 23, 48),
            sf::IntRect(383, 3, 23, 48),
            sf::IntRect(432, 3, 49, 48),
            sf::IntRect(136, 4, 42, 36),
            sf::IntRect(182, 4, 42, 36)
    };

    sf::IntRect cloudRect(488, 4, 121, 42);
    sf::Sprite cloud;
    cloud.setTexture(atlas);
    cloud.setTextureRect(cloudRect);
    cloud.setPosition(window.getSize().x, 100);

    int rnd_index = distribution(gen);
    Obstacle obstacle(sf::Vector2f(800.0, 303 - obstacleRects[rnd_index].height), atlas,
                      obstacleRects[rnd_index]);

    float ground_speed = -1;
    float ground_acceleration = -0.0001;

    sf::Clock animationClock, moveClock, gravityClock, scoreClock;

    bool is_active = false;

    while (window.isOpen()) {

        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (!is_active && event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                if (startButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    is_active = true;
                    rnd_index = distribution(gen);
                    if (rnd_index == 6 && distribution(gen) % 2) {
                        obstacle = Obstacle(sf::Vector2f(800.0, 260 - obstacleRects[rnd_index].height), atlas,
                                            obstacleRects[rnd_index]);
                    } else {
                        obstacle = Obstacle(sf::Vector2f(800.0, 303 - obstacleRects[rnd_index].height), atlas,
                                            obstacleRects[rnd_index]);
                    }
                    dino.setPosition(10, 260);
                    player_gravity = 0;
                    ground_speed = -1;
                    ground_acceleration = -0.0001;
                    cloud.setPosition(window.getSize().x, 100);
                }
            }
            if (!is_active && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                is_active = true;
                rnd_index = distribution(gen);
                if (rnd_index == 6 && distribution(gen) % 2) {
                    obstacle = Obstacle(sf::Vector2f(800.0, 260 - obstacleRects[rnd_index].height), atlas,
                                        obstacleRects[rnd_index]);
                } else {
                    obstacle = Obstacle(sf::Vector2f(800.0, 303 - obstacleRects[rnd_index].height), atlas,
                                        obstacleRects[rnd_index]);
                }
                dino.setPosition(10, 260);
                player_gravity = 0;
                ground_speed = -1;
                ground_acceleration = -0.0001;
                score = 0;
                cloud.setPosition(window.getSize().x, 100);
            }

            if (is_active) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space) {
                        if (dino.getGlobalBounds().top >= 260) {
                            player_gravity = -17;
                            jumpSound.play();
                        }
                    }
                }
            }
        }

        if (!is_active) {
            window.clear(sf::Color::White);
            window.draw(startButton);
            window.display();
        } else {
            if (moveClock.getElapsedTime().asSeconds() > 0.0025f) {
                ground_speed += ground_acceleration;
                ground_speed = max(ground_speed, -4.0f);
                obstacle.sprite.move(ground_speed, 0);

                if (obstacle.isOutsideWindow()) {
                    rnd_index = distribution(gen);
                    if (rnd_index == 6 && distribution(gen) % 2) {
                        obstacle = Obstacle(sf::Vector2f(800.0, 260 - obstacleRects[rnd_index].height), atlas,
                                            obstacleRects[rnd_index]);
                    } else {
                        obstacle = Obstacle(sf::Vector2f(800.0, 303 - obstacleRects[rnd_index].height), atlas,
                                            obstacleRects[rnd_index]);
                    }
                }
                if (obstacle.sprite.getGlobalBounds().intersects(dino.getGlobalBounds())) {
                    is_active = false;
                    dieSound.play();
                }

                ground1.move(ground_speed, 0);
                ground2.move(ground_speed, 0);
                cloud.move(ground_speed / 2, 0);

                if (ground1.getPosition().x + ground1.getGlobalBounds().width < 0) {
                    ground1.setPosition(ground2.getPosition().x + ground2.getGlobalBounds().width,
                                        ground1.getPosition().y);
                }
                if (ground2.getPosition().x + ground2.getGlobalBounds().width < 0) {
                    ground2.setPosition(ground1.getPosition().x + ground1.getGlobalBounds().width,
                                        ground1.getPosition().y);
                }
                if (cloud.getPosition().x + cloud.getGlobalBounds().width < 0) {
                    cloud.setPosition(window.getSize().x, 100);
                }
                moveClock.restart();
            }

            if (animationClock.getElapsedTime().asSeconds() > 0.1f) {
                currentDinoFrame = (currentDinoFrame + 1) % 2;
                dino.setTextureRect(dinoRunFrames[currentDinoFrame]);
                if (rnd_index == 6) {
                    currentBirdFrame = 6 + (currentBirdFrame + 1) % 2;
                    obstacle.sprite.setTextureRect(obstacleRects[currentBirdFrame]);
                }
                animationClock.restart();
            }

            if (scoreClock.getElapsedTime().asSeconds() > 0.5f) {
                score++;
                scoreClock.restart();
            }

            if (gravityClock.getElapsedTime().asSeconds() > 0.015f) {
                player_gravity++;
                dino.move(0, player_gravity);
                gravityClock.restart();
            }

            window.clear(sf::Color::White);

            if (dino.getGlobalBounds().top >= 260) {
                dino.setPosition(10, 260);
            }

            scoreText.setString("Score: " + to_string(score));
            window.draw(scoreText);

            window.draw(obstacle.sprite);

            window.draw(cloud);
            window.draw(ground1);
            window.draw(ground2);
            window.draw(dino);
            window.display();
        }
    }
}