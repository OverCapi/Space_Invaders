#define FALSE 0
#define TRUE 1

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define GAME_TITLE "Space Invaders"

#define FPS 60
#define FRAME_TARGET_TIME (1000/FPS)

// GAME SETINGS
#define BORDER_MODE FALSE

/*
            PLAYER
*/

#define PLAYER_TEXTURE_FILE "assets/pixel_ship_yellow.png"
#define PLAYER_STARTPOS_X 450
#define PLAYER_STARTPOS_Y 850
#define PLAYER_WIDTH (50 * 2)
#define PLAYER_HEIGHT (45 * 2)
#define PLAYER_SPEED 400    // pixel per second
#define PLAYER_BORDER_RIGHT (SCREEN_WIDTH - PLAYER_WIDTH)
#define PLAYER_BORDER_BOTTOM (SCREEN_HEIGHT - PLAYER_HEIGHT)
#define PLAYER_COOLDOWN_SHOOT 250   // ms

/*
            PROJECTILE
*/

#define PROJECTILE_TECTURE_FILE "assets/pixel_laser_yellow.png"
#define PROJECTILE_WIDTH 50
#define PROJECTILE_HEIGHT 45
#define PROJECTILE_SPEED 200
#define PROJECTILE_MAX_COUNT 20