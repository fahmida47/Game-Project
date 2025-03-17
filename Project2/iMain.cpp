#include "iGraphics.h"
#include<Windows.h>

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
void drawhomepage();
void drawstartpage();
void startbuttonhandler();
void drawhelppage();
void drawaboutus();
void drawlevelpage();
void drawlevel2page();
void drawlevel3page();
void helpbuttonhandler();
void aboutusbuttonhandler();
void backbuttonhandler();
void level1buttonhandler();
void level2buttonhandler();
void level3buttonhandler();


int homepage = 1;
int startbuttonclick = 0;
int helpbuttonclick = 0;
int startpage = 0;
int helppage = 0;
int aboutus = 0;
int levelpage = 0;
int level2page = 0;
int level3page = 0;

boolean musicon = true;
int lastMeowTime = 0;  // Store the time when the last meow sound was played

int jumpHeight = 78;  // Height to jump
bool isJumping = false;  // Flag for jump
int jumpStartTime = 0;  // Time when jump starts
int jumpDuration = 1200;  // Duration of the jump in milliseconds

int wallHeight = 200;   // Wall height where the cat stands
double jumpStartY = wallHeight; // Start jump from the top of the wall





int catx = 100; int caty = 100;
int catRunFrame = 0;  // To keep track of the current running frame
int runAnimationSpeed = 100;  // Time (in ms) between frames to control the speed of animation
int lastAnimationTime = 0;  // To store the time of the last animation frame update

bool isSliding = false;  // Flag for sliding
int slideFrame = 0;  // To keep track of the current sliding frame
int slideSpeed = 200;  // Speed of sliding animation (in ms)
int lastSlideTime = 0;  // To store the time of the last sliding frame update
int slideAnimationSpeed = 150;

int liftY = 105;           // Initial vertical position of the lift
int liftDirection = 1;     // 1 for moving up, -1 for moving down
int liftSpeed = 2;         // Speed of the lift's movement
bool isCatOnLift = false;



int ob1x = 200, ob1y = 0;    // Position of the first obstacle 
int ob3x = 720, ob3y = 100;  // Position of the second obstacle 
int ob2x = 420, ob2y = 0;   // Position of the third obstacle 

int stairX = 640;       // X-position of the stairs
int stairY = 100;       // Y-position of the base of the stairs
int stairWidth = 40;    // Width of the stairs
int stairHeight = 212;  // Height of the stairs

bool isLevelFinished = false;
bool gameOver = false;
bool winMusicPlayed = false;  // Flag to track if win music has been played

int level1TimeLimit = 50;  // 50-second time limit for Level 1
int level1StartTime = 0;   // Time when Level 1 starts
bool isTimerRunning = false;

int level2TimeLimit = 30;  // 40-second time limit for Level 2
int level2StartTime = 0;   // Time when Level 2 starts
bool isLevel2TimerRunning = false;
int level2StartDelay = 3000;
bool level2Started = false;

bool gameOver2 = false;
bool isLevel2Finished = false;
//levvel 3
int level3TimeLimit = 35;  // 20-second time limit for Level 3
int level3StartTime = 0;   // Time when Level 3 starts
bool isLevel3TimerRunning = false;
bool gameOver3 = false;
bool isLevel3Finished = false;




int score = 0;

int fishPositions[7][2] = {
	{ 239, 390 },  // Red fish
	{ 580, 180 },  // Yellow fish
	{ 335, 243 },  // Yellow fish
	{ 403, 212 },  // Yellow fish
	{ 676, 330 },  // Yellow fish
	{ 703, 110 },  // Yellow fish
	{ 176, 225 }   // Yellow fish
};

// Track whether each fish has been collected
bool fishCollected[7] = { false, false, false, false, false, false, false };

// Total fish collected
int totalFishCollected = 0;


// Array to store the running images (only 4 images)
char* catRunImages[8] = {
	"image\\cat_run_1.bmp",
	"image\\cat_run_2.bmp",
	"image\\cat_run_3.bmp",
	"image\\cat_run_4.bmp",
	"image\\cat_run_5.bmp",
	"image\\cat_run_6.bmp",
	"image\\cat_run_7.bmp",
	"image\\cat_run_8.bmp"
};
char* catSlideImages[4] = {
	"image\\cat_slide_1.bmp",
	"image\\cat_slide_2.bmp",
	"image\\cat_slide_3.bmp",
	"image\\cat_slide_4.bmp"
};

int firePositions[4][2] = {
	{ 780, 0 },  // Fire 1
	{ 480, 100 },  // Fire 2
	{ 600, 0 },  // Fire 3
	//{ 750, 100 },  
	{ 500, 150 }   // Fire 5
};

bool fireActive[4] = { true, true, true, true };  // Track active fires

int fishPositionsLevel2[5][2] = {
	{ 22, 100 },  // Fish 1 (Red fish, +3 points)
	{ 350, 0 },  // Fish 2 (Yellow fish, +1 point)
	{ 603, 100 },  // Fish 3 (Yellow fish, +1 point)
	{ 752, 0 },  // Fish 4 (Yellow fish, +1 point)
	{ 950, 100 }   // Fish 5 (Yellow fish, +1 point)
};
bool fishCollectedLevel2[5] = { false, false, false, false, false };

int totalFishCollectedLevel2 = 0;
int scoreLevel2 = 0;  // Score for Level 2
//level3
int backgroundOffset = 0;
int boxX = 400;
int boxY = 40;
int gateX = 150;  // X position of the gate
int gateY = 180;  // Y position of the gate
int targetBoxX = 600;  // Target X position for the box
int targetBoxY = 50;   // Target Y position for the box
bool gateVisible = true;

int stairXLevel3 = 80;       // X-position of the stairs in Level 3
int stairYLevel3 = 50;       // Y-position of the base of the stairs in Level 3
int stairWidthLevel3 = 40;   // Width of the stairs in Level 3
int stairHeightLevel3 = 130; // Height of the stairs in Level 3

int currentPlatformY = 50;




int fishPositionsLevel3[5][2] = {
	{ 330, 290 },  // Red fish (position x, y)
	{ 43, 203 },  // Yellow fish
	{ 500, 200 },  // Yellow fish
	{ 170, 80 },  // Yellow fish
	{ 700, 300 }   // Yellow fish
};

bool fishCollectedLevel3[5] = { false };  // Track which fish have been collected
int totalFishCollectedLevel3 = 0;         // Total fish collected in Level 3
int scoreLevel3 = 0;                      // Score for Level 3

//level 3 fire
int firePositionsLevel3[3][2] = {
	{ 250, 0 },  // Fire 1
	{ 250, 100 },  // Fire 2
	{ 250, 150 }   // Fire 3
};
int fireSpeedLevel3 = 6;
bool fireActiveLevel3[3] = { true, true, true };

int jumpStartPlatformY = 0;//level3
void iDraw()
{
	iClear();
	if (homepage == 1)
	{
		drawhomepage();

	}
	else if (startpage == 1)
	{
		drawstartpage();
	}
	else if (helppage == 1)
	{
		drawhelppage();
	}
	else if (aboutus == 1)
	{
		drawaboutus();
	}

	else if (levelpage == 1)
	{
		drawlevelpage();

		if (isTimerRunning) {
			int currentTime = timeGetTime() / 1000;
			int elapsedTime = currentTime - level1StartTime;  // Elapsed time in seconds
			int remainingTime = level1TimeLimit - elapsedTime;  // Remaining time in seconds

			// Construct the timer text manually
			char timerText[20] = "Time: ";  // Initialize with "Time: "
			int timeValue = remainingTime;

			// Convert the remaining time to a string
			if (timeValue >= 10) {
				timerText[6] = '0' + (timeValue / 10);  // Tens place
				timerText[7] = '0' + (timeValue % 10);  // Ones place
				timerText[8] = '\0';  // Null-terminate the string
			}
			else {
				timerText[6] = '0' + timeValue;
				timerText[7] = '\0';
			}

			// Display the timer text
			iSetColor(255, 255, 255);
			iText(700, 400, timerText, GLUT_BITMAP_TIMES_ROMAN_24);

			// Check if time has run out
			if (remainingTime <= 0) {
				isTimerRunning = false;
				if (!isLevelFinished) {
					gameOver = true;
				}
			}
		}


		if (!isSliding && !isJumping && (catx > 0 && catx < 800)) {
			iShowBMP2(catx, caty, catRunImages[catRunFrame], 0);
		}


		if (!isLevelFinished && !gameOver)
		{
			int currentTime = timeGetTime();
			if (currentTime - lastMeowTime >= 5000)  // 5000 ms = 5 seconds
			{
				PlaySound("meow.wav", NULL, SND_ASYNC);  // Play the meow sound
				lastMeowTime = currentTime;  // Update the last meow time
			}
		}

		if (isJumping)
		{
			int currentTime = timeGetTime();

			// The cat starts from the bottom (ground position)
			int groundY = 100; // Set this to where the bottom of the wall is
			int peakHeight = groundY - jumpHeight; // The highest point of the jump

			// Rising phase (first half of the jump duration)
			if (currentTime - jumpStartTime < jumpDuration / 2)
			{
				caty = groundY + (int)(jumpHeight * ((float)(currentTime - jumpStartTime) / (jumpDuration / 2)));  // Move upwards
			}
			// Falling phase (second half of the jump duration)
			else if (currentTime - jumpStartTime < jumpDuration)
			{
				caty = peakHeight + (int)(jumpHeight * ((float)(currentTime - jumpStartTime - jumpDuration / 2) / (jumpDuration / 2)));  // Move downwards
			}
			// Jump has ended
			else
			{
				caty = groundY;  // The cat lands back on the ground
				isJumping = false;  // Stop jumping
			}
		}
	}


	if (level2page == 1) {
		drawlevel2page();
	}
	if (level3page == 1) {
		drawlevel3page();  // Draw Level 3

		if (catx + 40 >= 760 && caty + 40 >= 300) {
			isLevel3Finished = true;
			isLevel3TimerRunning = false;
		}

		if (isLevel3TimerRunning) {
			int currentTime = timeGetTime() / 1000;
			int elapsedTime = currentTime - level3StartTime;  // Elapsed time in seconds
			int remainingTime = level3TimeLimit - elapsedTime;  // Remaining time in seconds

			// Construct the timer text
			char timerText[20] = "Time: ";  // Initialize with "Time: "
			int timeValue = remainingTime;

			// Convert the remaining time to a string
			if (timeValue >= 10) {
				timerText[6] = '0' + (timeValue / 10);  // Tens place
				timerText[7] = '0' + (timeValue % 10);  // Ones place
				timerText[8] = '\0';  // Null-terminate the string
			}
			else {
				timerText[6] = '0' + timeValue;
				timerText[7] = '\0';
			}
			iSetColor(255, 255, 255);
			iText(700, 400, timerText, GLUT_BITMAP_TIMES_ROMAN_24);

			// Check if time has run out
			if (remainingTime <= 0) {
				isLevel3TimerRunning = false;
				gameOver3 = true;
			}
		}

		if (gameOver3) {
			iShowBMP2(250, 100, "im\\gameover.bmp", 0);
			iSetColor(255, 255, 255);
			iText(340, 180, "Press R to Restart", GLUT_BITMAP_TIMES_ROMAN_24);
			PlaySound("gameovermusic.wav", NULL, SND_ASYNC);
		}

		if (isJumping) {
			int currentTime = timeGetTime();

			// Rising phase (first half of the jump duration)
			if (currentTime - jumpStartTime < jumpDuration / 2) {
				caty = jumpStartY + (int)(jumpHeight * ((float)(currentTime - jumpStartTime) / (jumpDuration / 2)));  // Move upwards
			}
			// Falling phase (second half of the jump duration)
			else if (currentTime - jumpStartTime < jumpDuration) {
				caty = jumpStartY + jumpHeight - (int)(jumpHeight * ((float)(currentTime - jumpStartTime - jumpDuration / 2) / (jumpDuration / 2)));  // Move downwards
			}
			// Jump has ended
			else {
				caty = jumpStartPlatformY;;  // Land on the current platform
				isJumping = false;  // Stop jumping
			}
		}

		// Constrain the cat to the current platform
		if (caty < currentPlatformY) {
			caty = currentPlatformY;
		}
	}
}











bool isCatNearStairs(int catx, int caty) {
	if (catx >= stairX - 50 && catx <= stairX + stairWidth + 50) {
		// Check if the cat is within the vertical range of the stairs
		if (caty >= stairY && caty <= stairY + stairHeight) {
			return true;
		}
	}
	return false;
}
bool isCatNearStairsLevel3(int catx, int caty) {



	if (catx >= stairXLevel3 - 50 && catx <= stairXLevel3 + stairWidthLevel3 + 50) {
		if (caty >= stairYLevel3 && caty <= stairYLevel3 + stairHeightLevel3) {
			return true;  // Cat is near the stairs
		}
	}
	return false;  // Cat is not near the stairs
}


bool isCatCollidingWithBox(int catx, int caty, int boxX, int boxY) {
	return (catx + 50 > boxX && catx < boxX + 50 && caty + 50 > boxY && caty < boxY + 50);
}














/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d y=%d", mx, my);
		PlaySound("clicksound.wav", NULL, SND_SYNC);
		if (homepage == 1 && (mx >= 591 && mx <= 764) && (my >= 304 && my <= 373))
		{
			startbuttonhandler();

		}
		else if (homepage == 1 && (mx >= 594 && mx <= 763) && (my >= 198 && my <= 273))
		{
			helpbuttonhandler();
		}
		else if (homepage == 1 && (mx >= 597 && mx <= 762) && (my >= 92 && my <= 173))
		{
			aboutusbuttonhandler();
		}
		else if (startpage == 1 | helppage == 1 | aboutus == 1 && (mx >= 21 && mx <= 70) && (my >= 377 && my <= 431) )
		{
			backbuttonhandler();
		}
		else if (startpage == 1 && (mx >= 591 && mx <= 761) && (my >= 36 && my <= 101))
		{
			level1buttonhandler();
		}
		else if (isLevelFinished && (mx >= 350 && mx <= 450) && (my >= 150 && my <= 160))
		{
			level2buttonhandler();  // Call level 2
		}


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == ' ')
	{
		if (!isJumping){
			isJumping = true;
			jumpStartTime = timeGetTime();
			jumpStartY = caty;
			jumpStartPlatformY = currentPlatformY;
		}
	}
	if (isLevel3Finished && key == '\r') {  // '\r' is the Enter key
		level1buttonhandler();  // Restart Level 1
	}
	if (gameOver && (key == 'r' || key == 'R')) {
		level1buttonhandler();

		isTimerRunning = true;
		level1StartTime = timeGetTime() / 1000;  // Reset the start time
	}
	if (gameOver2 && (key == 'r' || key == 'R')) {
		level2buttonhandler();


		level2StartTime = timeGetTime() / 1000;  // Reset the start time
	}



	if ((key == 'r' || key == 'R') && gameOver3) {
		level3buttonhandler();  // Call the Level 3 restart handler

	}
	if ((key == 'n' || key == 'N') && isLevelFinished && level2page == 1) {
		level3buttonhandler();  // Level 3
		isLevelFinished = false;  // Reset the level completion flag
	}


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT

*/
int gateUpperX = 150;  // Gate's X position in the upper tileset
int gateUpperY = 180;  // Gate's Y position in the upper tileset
int upperTilesetY = 140;
void iSpecialKeyboard(unsigned char key)
{
	if (gameOver || isLevelFinished || gameOver2 || isLevel3Finished) return;  // Ignore input if the game is over
	int currentTime = timeGetTime();


	// Handle RIGHT arrow key movement (Cat moves to the right)
	if (key == GLUT_KEY_RIGHT)
	{
		if (level3page == 1 && gateVisible&& caty >= upperTilesetY)// && catx + 65 >= gateX)  // 65 is the width of the cat
		{
			if (catx + 65 >= gateUpperX){
				// Prevent the cat from moving further to the right
				catx = gateX - 65;
			}
			else
			{
				catx += 10;  // Move the cat to the right
			}

		}


		else
		{
			if (!isSliding){



				if (catx + 65 < 800)  // Keep the cat within the window
				{
					catx += 10;  // Speed of movement

				}
				if (isCatCollidingWithBox(catx, caty, boxX, boxY)) {
					boxX += 10;  // Move the box to the right
				}


				if (currentTime - lastAnimationTime >= runAnimationSpeed)
				{
					catRunFrame = (catRunFrame + 1) % 8;  // Cycle through 8 frames
					lastAnimationTime = currentTime;
				}


			}
		}
		// Handle movement while jumping (RIGHT)
		if (isJumping)
		{
			if (catx + 65 < 800)  // Keep the cat within the window
			{
				catx += 80;  // Small movement while jumping forward
			}
		}
	}


	// Handle LEFT arrow key movement (Cat moves to the left)
	if (key == GLUT_KEY_LEFT)
	{
		if (catx > 0)
		{
			catx -= 10;  // Speed of movement
		}




		if (currentTime - lastAnimationTime >= runAnimationSpeed)
		{
			catRunFrame = (catRunFrame + 1) % 8;  // Cycle through 8 frames
			lastAnimationTime = currentTime;

		}


		// Handle movement while jumping (LEFT)
		if (isJumping)
		{
			if (catx > 0)  // Keep the cat within the window
			{
				catx -= 40;  // Small movement while jumping backward
			}
		}
	}


	if (key == GLUT_KEY_UP)   // When the UP arrow key is pressed, start moving up
	{
		if (isCatNearStairs(catx, caty)) {  // Check if the cat is near the stairs
			if (caty < stairY + stairHeight) {  // Limit climbing height
				caty += 10;  // Move the cat upwards

			}
		}
		else if (level3page == 1) {  // Level 3
			if (isCatNearStairsLevel3(catx, caty)) {  // Check if the cat is near the stairs in Level 3
				if (caty < stairYLevel3 + stairHeightLevel3) {  // Limit climbing height
					caty += 10;  // Move the cat upwards
					currentPlatformY = caty;
					//currentPlatformY = 185;
				}
			}
		}
	}

	// Handle DOWN arrow key for sliding (Only if not jumping)
	if (key == GLUT_KEY_DOWN && !isJumping)
	{
		if (levelpage == 1) {
			if (!isSliding)  // Start sliding if it's not already sliding
			{
				isSliding = true;  // Start sliding
				slideFrame = 0;  // Reset the sliding animation frame
				lastSlideTime = currentTime;
			}

			// Move the cat to the right while sliding
			if (catx + 65 < 800)  // Keep the cat within the window
			{
				catx += 10;  // Move forward while sliding
			}


			// Update the sliding animation frame
			if (currentTime - lastSlideTime >= slideAnimationSpeed)
			{
				slideFrame = (slideFrame + 1) % 4;  // Cycle through sliding frames
				lastSlideTime = currentTime;
			}

			// Show the sliding animation while moving
			iShowBMP2(catx, caty, catSlideImages[slideFrame], 0);  // Show sliding frame
		}
		else if (level3page == 1) {  // Level 3: Handle descending stairs
			if (isCatNearStairsLevel3(catx, caty)) {  // Check if the cat is near the stairs in Level 3
				if (caty > stairYLevel3) {  // Limit descending to the base of the stairs
					caty -= 10;  // Move the cat downwards
					currentPlatformY = 50;  // Reset platform Y position if needed
				}
				else {
					// Cat is at the base of the stairs, stop descending
					caty = stairYLevel3;
				}
			}
		}
	}

	// Handle the sliding movement while moving right
	if (isSliding && key == GLUT_KEY_RIGHT)
	{
		if (catx + 65 < 800)
		{
			catx += 10;  // Move forward while sliding
		}

		// Update the sliding animation frame
		if (currentTime - lastSlideTime >= slideAnimationSpeed)
		{
			slideFrame = (slideFrame + 1) % 4;
			lastSlideTime = currentTime;
		}

		// Show the sliding animation while moving
		iShowBMP2(catx, caty, catSlideImages[slideFrame], 0);
	}



	// Stop sliding when DOWN key is released or another key is pressed
	if (key != GLUT_KEY_DOWN && isSliding)
	{
		isSliding = false;
		iShowBMP2(catx, caty, "image\\cat_stand.bmp", 0);
	}



	if (key == GLUT_KEY_HOME)
	{

	}
	if (key == GLUT_KEY_F1)
	{
		if (musicon)
		{
			musicon = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicon = true;
			PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

}


void checkFishCollection() {
	for (int i = 0; i < 7; i++) {
		if (!fishCollected[i]) {
			// Check if the cat is near the fish
			if (catx + 65 > fishPositions[i][0] && catx < fishPositions[i][0] + 50 &&
				caty + 50 > fishPositions[i][1] && caty < fishPositions[i][1] + 50) {
				fishCollected[i] = true;
				totalFishCollected++;
				if (i == 0) {
					score += 5;  // Red fish is worth 5 points
				}
				else {
					score += 2;  // Yellow fish is worth 2 points
				}

				PlaySound("collectfish.wav", NULL, SND_ASYNC);
			}
		}
	}
}
void checkWinCondition() {
	if (totalFishCollected == 7) {
		isLevelFinished = true;  // Set the level as finished
		if (!winMusicPlayed) {
			PlaySound("winmusic.wav", NULL, SND_ASYNC);  // Play the win music
			winMusicPlayed = true;  // Set the flag to true so the music doesn't play again
		}
	}
}



void drawhomepage()
{
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, 800, 500);
	iShowBMP2(0, 0, "image\\hioi.bmp", 0);
	iShowBMP2(590, 300, "image\\button1.bmp", 0);
	iShowBMP2(590, 200, "image\\button2.bmp", 0);
	iShowBMP2(590, 100, "image\\button3.bmp", 0);
	iSetColor(255, 255, 255);
	iText(650, 330, "Start", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(650, 230, "Help", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(650, 130, "About Us", GLUT_BITMAP_TIMES_ROMAN_24);


}
void drawstartpage()
{
	iFilledRectangle(0, 0, 800, 450);
	iShowBMP2(0, 0, "image\\startpage22.bmp", 0);
	iShowBMP2(590, 30, "image\\button1.bmp", 0);
	iText(650, 62, "Level 1", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(20, 380, "image\\arrow2.bmp", 0);

}
void drawhelppage()
{
	iFilledRectangle(0, 0, 800, 450);
	iShowBMP2(0, 0, "image\\helppage.bmp", 0);
	iShowBMP2(20, 380, "image\\arrow2.bmp", 0);
}

void drawaboutus(){
	iFilledRectangle(0, 0, 800, 450);
	iShowBMP2(0, 0, "image\\About Us.bmp", 0);
	iShowBMP2(20, 380, "image\\arrow2.bmp", 0);
}
void drawlevelpage()
{

	iFilledRectangle(0, 0, 800, 450);
	iShowBMP2(0, 0, "image\\level.bmp", 0);
	iSetColor(255, 0, 0);  // Set the color to red
	iLine(0, 100, 200, 100);  // Draw the first line
	iLine(0, 300, 130, 320);  // Draw the first line

	// Draw the second red line starting from (160, 100) with length 150
	iLine(330, 100, 450, 100);  // Draw the second line

	// Draw the third red line starting from (340, 100) and extending till the end at 800
	iLine(550, 100, 800, 100);  // Draw the third line

	iShowBMP2(0, 2.2, "image\\tileset.bmp", 0);
	iShowBMP2(330, 2.2, "image\\tileset2.bmp", 0);
	iShowBMP2(550, 2.2, "image\\tileset.bmp", 0);
	iShowBMP2(750, 2.2, "image\\tileset.bmp", 0);
	iShowBMP2(0, 300, "image\\tileset3.bmp", 0);
	iShowBMP2(656, 260, "image\\t11.bmp", 0);
	iShowBMP2(635, 260, "image\\t1.bmp", 0);

	iShowBMP2(720, 280, "im\\grass.bmp", 0);
	iShowBMP2(690, 280, "im\\grass.bmp", 0);

	iShowBMP2(stairX, stairY, "image\\stair.bmp", 0);  // Base of the stairs
	iShowBMP2(stairX, stairY + 103, "image\\stair.bmp", 0);  // Middle of the stairs
	//iShowBMP2(640, 104, "image\\stair.bmp", 0);
	//iShowBMP2(640, 203, "image\\stair.bmp", 0);

	iShowBMP2(ob1x, ob1y, "image\\ob1.bmp", 0);
	iShowBMP2(ob2x, ob2y, "image\\ob1.bmp", 0);
	iShowBMP2(ob3x, ob3y, "image\\ob1.bmp", 0);

	iShowBMP2(737, 310, "im\\flag.bmp", 0);
	iShowBMP2(350, 0, "im\\danger.bmp", 0);

	for (int i = 0; i < 7; i++) {
		if (!fishCollected[i]) {  // Only draw fish that haven't been collected
			if (i == 0) {  // Red fish
				iShowBMP2(fishPositions[i][0], fishPositions[i][1], "im\\redfish.bmp", 0);
			}
			else {  // Yellow fish
				iShowBMP2(fishPositions[i][0], fishPositions[i][1], "im\\fish.bmp", 0);
			}
		}
	}

	// Display the number of fish collected
	iSetColor(255, 255, 255);  // White color

	// Display "Fish Collected: "
	iText(10, 400, "Fish Collected: ", GLUT_BITMAP_TIMES_ROMAN_24);

	// Display the number of fish collected
	char fishCountText[3];  // Maximum 2 digits for fish count (e.g., "7")
	if (totalFishCollected < 10) {
		fishCountText[0] = '0' + totalFishCollected;  // Convert single-digit number to char
		fishCountText[1] = '\0';  // Null-terminate the string
	}
	else {
		fishCountText[0] = '0' + (totalFishCollected / 10);  // First digit
		fishCountText[1] = '0' + (totalFishCollected % 10);  // Second digit
		fishCountText[2] = '\0';  // Null-terminate the string
	}

	// Display the fish count
	iText(159, 400, fishCountText, GLUT_BITMAP_TIMES_ROMAN_24);

	// Display "/7"
	iText(170, 400, "/7", GLUT_BITMAP_TIMES_ROMAN_24);



	// Check for collisions and win condition
	checkFishCollection();
	checkWinCondition();

	if (catx + 100 > ob1x && catx < ob1x + 130 && caty + 78 > ob1y && caty < ob1y + 95) {
		gameOver = true;
	}

	// Check for collision with ob2
	if (caty == ob2y){
		gameOver = true;
	}

	if (catx + 60> ob3x && caty == ob3y) {
		gameOver = true;
	}
	// Display "Game Over"  if the game is over
	if (gameOver) {

		iShowBMP2(250, 100, "im\\gameover.bmp", 0);  // 
		iSetColor(0, 0, 0);  // Set text color to white

		iText(340, 180, "Press R to Restart", GLUT_BITMAP_TIMES_ROMAN_24);
		PlaySound(0, 0, 0);
		PlaySound("gameovermusic.wav", NULL, SND_ASYNC);
		Sleep(3000);  // 3 seconds delay
	}
	if (!gameOver && !isLevelFinished)
	{
		liftY += liftDirection * liftSpeed;
		if (liftY >= 331)  // When the lift reaches its upper limit
		{
			liftDirection = -1;  // Start moving down
		}
		else if (liftY <= 80)  // When the lift reaches its lower limit
		{
			liftDirection = 1;   // Start moving up
		}
	}
	iShowBMP2(180, liftY, "image\\lift2.bmp", 0);
	bool isCatOnLift = false;

	if (catx + 38 > 180 && catx < 180 + 120) {  // If cat is in the horizontal range of the lift
		// Adjust the cat's vertical position to stand on the lift
		caty = liftY + 50;
		isCatOnLift = true;
	}

	if (catx >= 737 - 50 && catx <= 737 + 50 && caty >= 310 - 50 && caty <= 310 + 50) {
		isLevelFinished = true;
		isTimerRunning = false;

	}

	// Display "Level Complete" 
	if (isLevelFinished) {
		iShowBMP2(250, 100, "im\\levelcomplete.bmp", 0);
		iSetColor(255, 255, 255);
		iText(355, 140, "Next Level", GLUT_BITMAP_TIMES_ROMAN_24);


		char scoreText[10];
		if (score < 10) {
			scoreText[0] = '0' + score;
			scoreText[1] = '\0';
		}
		else {
			scoreText[0] = '0' + (score / 10);
			scoreText[1] = '0' + (score % 10);
			scoreText[2] = '\0';
		}
		iText(470, 190, scoreText, GLUT_BITMAP_TIMES_ROMAN_24);
		if (!winMusicPlayed)
		{
			PlaySound("winmusic.wav", NULL, SND_ASYNC);
			winMusicPlayed = true;  // Set the flag to true so the music doesn't play again
		}

		else if (level2page == 1) {
			// Draw Level 2 
			drawlevel2page();
		}
	}



	if (!isCatOnLift &&!isJumping&& !isCatNearStairs(catx, caty))
	{


		if ((catx >= 0 && catx + 65 <= 216))  // On the first red line
		{
			caty = 100;
		}
		else if ((catx >= 300 && catx + 65 <= 485))  // On the second red line
		{
			caty = 100;
		}
		else if ((catx >= 500 && catx + 65 <= 800))  // On the third red line
		{
			caty = 100;
		}
		else  // If the cat is not on any red line, it falls to the ground
		{
			caty = 0;
		}
	}


	if (isSliding)
	{
		int currentTime = timeGetTime();
		// Update the sliding animation frame based on the time
		if (currentTime - lastSlideTime >= slideSpeed)
		{
			slideFrame = (slideFrame + 1) % 4;  // Cycle through 4 sliding frames
			lastSlideTime = currentTime;
		}

		// Display the current slide frame
		iShowBMP2(catx, caty, catSlideImages[slideFrame], 0);

		// Stop sliding after the last frame of the slide
		if (slideFrame == 3 && currentTime - lastSlideTime >= slideSpeed)
		{
			isSliding = false;  // Stop sliding after the last frame of the slide
		}
	}
	else  // If not sliding, show the running or standing animation
	{
		if (catx > 0 && catx < 800)  // Cat is moving normally (not sliding)
		{
			iShowBMP2(catx, caty, catRunImages[catRunFrame], 0);
		}
		else  // Cat is standing still
		{
			iShowBMP2(catx, caty, "image\\cat_stand.bmp", 0);  // Display the standing image
		}
	}

	// Handle the jump logic

	if (isJumping)
	{
		int currentTime = timeGetTime();

		// Rising phase (first half of the jump duration)
		if (currentTime - jumpStartTime < jumpDuration / 2)
		{
			// The cat starts from the red line (y = 100) and goes upwards
			caty = (int)(jumpHeight * ((float)(currentTime - jumpStartTime) / (jumpDuration / 2)));  // Move upwards

			// Ensure caty doesn't fall below 100 (the red line)
			if (caty < 100) {
				caty = 100;
			}
		}
		// Falling phase (second half of the jump duration)
		else if (currentTime - jumpStartTime < jumpDuration)
		{
			// The cat moves downward after reaching the peak of the jump
			caty = jumpHeight - (int)(jumpHeight * ((float)(currentTime - jumpStartTime - jumpDuration / 2) / (jumpDuration / 2)));  // Move downwards

			// Ensure the cat lands on the red line and doesn't fall below it
			if (caty < 100) {
				caty = 100;
				isJumping = false;  // Stop the jump when it lands
			}
		}
		// End of the jump
		else
		{
			caty = 100;  // The cat lands back on the red line (y = 100)
			isJumping = false;  // Stop jumping
		}
	}
}
void drawlevel2page() {
	iShowBMP2(0, 0, "im\\level22.bmp", 0);  // Background remains fixed


	// Update fire and fish positions to create the moving effect
	if (!isLevel2Finished) {
		for (int i = 0; i < 4; i++)
		{
			// Move fire from right to left
			firePositions[i][0] -= 2;  // Adjust speed as needed (e.g., 5 pixels per frame)
			if (firePositions[i][0] < -50)  // Reset fire position when it goes off-screen
			{
				firePositions[i][0] = 800;  // Move fire back to the right side
			}

			// Draw fire
			if (fireActive[i])
			{
				iShowBMP2(firePositions[i][0], firePositions[i][1], "im\\fire.bmp", 0);
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		fishPositionsLevel2[i][0] -= 1;  // Adjust speed as needed (e.g., 5 pixels per frame)
		if (fishPositionsLevel2[i][0] < -50)  // Reset fish position when it goes off-screen
		{
			fishPositionsLevel2[i][0] = 800;  // Move fish back to the right side
		}
	}

	for (int i = 0; i < 5; i++) {
		if (!fishCollectedLevel2[i])
		{
			if (i == 0)  // Red fish
			{
				iShowBMP2(fishPositionsLevel2[i][0], fishPositionsLevel2[i][1], "im\\redfish.bmp", 0);
			}
			else  // Yellow fish
			{
				iShowBMP2(fishPositionsLevel2[i][0], fishPositionsLevel2[i][1], "im\\fish.bmp", 0);
			}
		}
	}


	// Display the number of fish collected in Level 2
	iSetColor(255, 255, 255);  // White color for text
	iText(10, 400, "Fish Collected: ", GLUT_BITMAP_TIMES_ROMAN_24);  // Label

	// Display the number of fish collected
	char fishCountText[3];  // Maximum 2 digits for fish count (e.g., "5")
	if (totalFishCollectedLevel2 < 10) {
		fishCountText[0] = '0' + totalFishCollectedLevel2;  // Convert single-digit number to char
		fishCountText[1] = '\0';  // Null-terminate the string
	}
	else {
		fishCountText[0] = '0' + (totalFishCollectedLevel2 / 10);  // First digit
		fishCountText[1] = '0' + (totalFishCollectedLevel2 % 10);  // Second digit
		fishCountText[2] = '\0';  // Null-terminate the string
	}

	// Display the fish count
	iText(159, 400, fishCountText, GLUT_BITMAP_TIMES_ROMAN_24);

	// Display "/5" (total fish in Level 2)
	iText(170, 400, "/5", GLUT_BITMAP_TIMES_ROMAN_24);

	if (isLevel2TimerRunning && !gameOver2) {
		int currentTime = timeGetTime() / 1000;
		int elapsedTime = currentTime - level2StartTime;  // Elapsed time in seconds
		int remainingTime = level2TimeLimit - elapsedTime;  // Remaining time in seconds

		// Construct the timer text manually
		char timerText[20] = "Time: ";  // Initialize with "Time: "
		int timeValue = remainingTime;

		// Convert the remaining time to a string
		if (timeValue >= 10) {
			timerText[6] = '0' + (timeValue / 10);  // Tens place
			timerText[7] = '0' + (timeValue % 10);  // Ones place
			timerText[8] = '\0';  // Null-terminate the string
		}
		else {
			timerText[6] = '0' + timeValue;
			timerText[7] = '\0';
		}

		// Display the timer text
		iSetColor(255, 255, 255);
		iText(700, 400, timerText, GLUT_BITMAP_TIMES_ROMAN_24);

		// Check if time has run out
		if (remainingTime <= 0) {
			isLevel2TimerRunning = false;
			isLevelFinished = true;  // Level 2 is finished
			isLevel2Finished = true;

		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (fireActive[i])
		{
			int fireX = firePositions[i][0];
			int fireY = firePositions[i][1];

			if (catx == fireX && catx == fireX &&
				caty == fireY && caty == fireY)
			{
				gameOver2 = true;  // Cat hits a fire
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (!fishCollectedLevel2[i])
		{
			int fishX = fishPositionsLevel2[i][0];
			int fishY = fishPositionsLevel2[i][1];

			if (catx + 50 > fishX && catx < fishX + 50 &&
				caty + 50 > fishY && caty < fishY + 50)
			{
				fishCollectedLevel2[i] = true;
				totalFishCollectedLevel2++;

				// Update score
				if (i == 0)  // Red fish (+3 points)
				{
					scoreLevel2 += 3;
				}
				else  // Yellow fish (+2 points)
				{
					scoreLevel2 += 2;
				}

				PlaySound("collectfish.wav", NULL, SND_ASYNC);
			}
		}
	}
	if (gameOver2)
	{
		iShowBMP2(250, 100, "im\\gameover.bmp", 0);
		iSetColor(255, 255, 255);
		iText(340, 180, "Press R to Restart", GLUT_BITMAP_TIMES_ROMAN_24);
		PlaySound(0, 0, 0);
		PlaySound("gameovermusic.wav", NULL, SND_ASYNC);
		Sleep(3000);
	}
	if (isLevelFinished)
	{
		iShowBMP2(250, 100, "im\\levelcomplete.bmp", 0);
		iSetColor(255, 255, 255);
		iSetColor(255, 255, 255);  // White color for text
		iText(329, 140, "Press N for Final level", GLUT_BITMAP_TIMES_ROMAN_24);
		char scoreText[10];
		if (scoreLevel2 < 10) {
			scoreText[0] = '0' + scoreLevel2;
			scoreText[1] = '\0';
		}
		else {
			scoreText[0] = '0' + (scoreLevel2 / 10);
			scoreText[1] = '0' + (scoreLevel2 % 10);
			scoreText[2] = '\0';
		}
		iText(470, 190, scoreText, GLUT_BITMAP_TIMES_ROMAN_24);


	}
	if (isJumping)
	{


		int currentTime = timeGetTime();

		// Rising phase (first half of the jump duration)
		if (currentTime - jumpStartTime < jumpDuration / 2)
		{
			caty = jumpStartY + (int)(jumpHeight * ((float)(currentTime - jumpStartTime) / (jumpDuration / 2)));  // Move upwards
		}
		// Falling phase (second half of the jump duration)
		else if (currentTime - jumpStartTime < jumpDuration)
		{
			caty = jumpStartY + jumpHeight - (int)(jumpHeight * ((float)(currentTime - jumpStartTime - jumpDuration / 2) / (jumpDuration / 2)));  // Move downwards
		}
		// Jump has ended
		else
		{
			caty = jumpStartY;  // The cat lands back on the ground
			isJumping = false;  // Stop jumping
		}

		// Use the standing or running image for the jump
		iShowBMP2(catx, caty, "image\\cat_stand.bmp", 0);  // Replace with "cat_run_1.bmp" if needed
	}
	else
	{
		iShowBMP2(catx, caty, "image\\cat_stand.bmp", 0);  // Use a standing image
	}

	if (!level2Started && !gameOver2) {
		int currentTime = timeGetTime();
		if (currentTime - level2StartTime >= level2StartDelay) {
			level2Started = true;  // Start Level 2 after the delay
			isLevel2TimerRunning = true;  // Start the timer
			level2StartTime = timeGetTime() / 1000;  // Reset the start time for the timer
		}
		else {
			// Display "Get Ready!" message during the 3-second delay
			iSetColor(255, 255, 255);
			iText(350, 350, "Get Ready!", GLUT_BITMAP_TIMES_ROMAN_24);
			return;  // Don't update game logic during the delay
		}
	}






}
void checkFishCollectionLevel3() {
	for (int i = 0; i < 5; i++) {
		if (!fishCollectedLevel3[i]) {
			// Check if the cat is near the fish
			if (catx + 50 > fishPositionsLevel3[i][0] && catx < fishPositionsLevel3[i][0] + 50 &&
				caty + 50 > fishPositionsLevel3[i][1] && caty < fishPositionsLevel3[i][1] + 50) {
				fishCollectedLevel3[i] = true;  // Mark the fish as collected
				totalFishCollectedLevel3++;     // Increment the total fish collected
				if (i == 0) {  // Red fish
					scoreLevel3 += 5;
				}
				else {  // Yellow fish
					scoreLevel3 += 3;
				}

				// Play the collect sound
				PlaySound("collectfish.wav", NULL, SND_ASYNC);
			}
		}
	}
}

bool isBoxAtTargetPosition(int boxX, int boxY) {
	return (boxX >= targetBoxX - 10 && boxX <= targetBoxX + 10 && boxY >= targetBoxY - 10 && boxY <= targetBoxY + 10);
}
bool gateSoundPlayed = false;

void drawlevel3page() {
	iShowBMP2(0, 0, "im\\level33.bmp", 0);
	iShowBMP2(0, 0, "im\\level3tilset.bmp", 0);
	iShowBMP2(65, 0, "im\\level3tilset.bmp", 0);
	iShowBMP2(300, 0, "im\\level3tilset.bmp", 0);
	iShowBMP2(450, 0, "im\\level3tilset.bmp", 0);
	iShowBMP2(600, 0, "im\\level3tilset.bmp", 0);
	iShowBMP2(750, 0, "im\\level3tilset.bmp", 0);

	iShowBMP2(190, 20, "im\\d.bmp", 0);//hole for fire out
	if (gateVisible) {
		iShowBMP2(gateX, gateY, "im\\gate.bmp", 0);
	}
	iShowBMP2(740, 185, "im\\flower.bmp", 0);
	//uper tilset

	iShowBMP2(0, 140, "im\\level3tilset.bmp", 0);
	iShowBMP2(150, 140, "im\\level3tilset.bmp", 0);
	iShowBMP2(300, 140, "im\\level3tilset.bmp", 0);
	iShowBMP2(450, 140, "im\\level3tilset.bmp", 0);
	iShowBMP2(600, 140, "im\\level3tilset.bmp", 0);
	iShowBMP2(750, 140, "im\\level3tilset.bmp", 0);

	//ob
	iShowBMP2(550, 120, "im\\danger.bmp", 0);
	iShowBMP2(680, 30, "image\\ob1.bmp", 0);
	iShowBMP2(450, 280, "image\\ob1.bmp", 0);
	if (catx + 50 > 680 && catx < 680 + 50 &&  // Check X-axis overlap
		caty + 50 > 30 && caty < 30 + 50) {    // Check Y-axis overlap
		gameOver3 = true;  // Set game over if collision occurs
	}

	iSetColor(255, 0, 0);
	iFilledRectangle(600, 50, 38, 16);//emergency button
	iSetColor(255, 255, 255);  // White color for the text
	iText(585, 65, "Put the box here", GLUT_BITMAP_HELVETICA_10);
	//last tilset
	iShowBMP2(150, 255, "im\\level3tilset.bmp", 0);
	//iShowBMP2(300, 255, "im\\level3tilset.bmp", 0);
	iShowBMP2(450, 255, "im\\level3tilset.bmp", 0);
	iShowBMP2(700, 262, "im\\level3tilset.bmp", 0);//end
	iShowBMP2(740, 313, "im\\flag.bmp", 0);

	//stair
	//iShowBMP2(313, 192, "image\\stair.bmp", 0);
	iShowBMP2(680, 192, "image\\stair.bmp", 0);
	iShowBMP2(80, 50, "image\\stair.bmp", 0);
	iShowBMP2(80, 95, "image\\stair.bmp", 0);


	if (!isJumping) {
		// Show the running animation
		iShowBMP2(catx, caty, catRunImages[catRunFrame], 0);
	}
	else {
		// Show the jumping animation
		iShowBMP2(catx, caty, "image\\cat_stand.bmp", 0);
	}
	iShowBMP2(boxX, boxY, "im\\boxx.bmp", 0);


	// Update fire positions
	if (!isLevel3Finished) {
		for (int i = 0; i < 3; i++) {
			if (fireActiveLevel3[i]) {
				firePositionsLevel3[i][1] += fireSpeedLevel3;  // Move the fire upwards

				// Reset the fire if it goes off the screen
				if (firePositionsLevel3[i][1] > 450) {  // Assuming the screen height is 450
					firePositionsLevel3[i][1] = 0;  // Reset to the bottom
				}
			}
		}
	}

	// Draw the fires
	for (int i = 0; i < 3; i++) {
		if (fireActiveLevel3[i]) {
			iShowBMP2(firePositionsLevel3[i][0], firePositionsLevel3[i][1], "im\\fire.bmp", 0);
		}
	}

	checkFishCollectionLevel3();


	for (int i = 0; i < 5; i++) {
		if (!fishCollectedLevel3[i]) {
			if (i == 0) {  // Red fish
				iShowBMP2(fishPositionsLevel3[i][0], fishPositionsLevel3[i][1], "im\\redfish.bmp", 0);
			}
			else {  // Yellow fish
				iShowBMP2(fishPositionsLevel3[i][0], fishPositionsLevel3[i][1], "im\\fish.bmp", 0);
			}
		}
	}
	// Display the score
	iSetColor(255, 255, 255);  // White color
	char scoreText[20] = "Score: ";  // Initialize with "Score: "
	int scoreValue = scoreLevel3;    // The integer score

	// Convert the score to a string
	if (scoreValue >= 10) {
		scoreText[7] = '0' + (scoreValue / 10);  // Tens place
		scoreText[8] = '0' + (scoreValue % 10);  // Ones place
		scoreText[9] = '\0';  // Null-terminate the string
	}
	else {
		scoreText[7] = '0' + scoreValue;  // Single-digit score
		scoreText[8] = '\0';  // Null-terminate the string
	}
	iText(10, 400, scoreText, GLUT_BITMAP_TIMES_ROMAN_24);

	// Display the number of fish collected
	char fishText[20] = "Fish: ";  // Initialize with "Fish: "
	int fishValue = totalFishCollectedLevel3;  // The integer fish count

	// Convert the fish count to a string
	if (fishValue >= 10) {
		fishText[6] = '0' + (fishValue / 10);  // Tens place
		fishText[7] = '0' + (fishValue % 10);  // Ones place
		fishText[8] = '/';  // Add the slash
		fishText[9] = '5';  // Add the total fish count
		fishText[10] = '\0';  // Null-terminate the string
	}
	else {
		fishText[6] = '0' + fishValue;  // Single-digit fish count
		fishText[7] = '/';  // Add the slash
		fishText[8] = '5';  // Add the total fish count
		fishText[9] = '\0';  // Null-terminate the string
	}
	iText(10, 370, fishText, GLUT_BITMAP_TIMES_ROMAN_24);
	//fire collision 
	for (int i = 0; i < 3; i++) {
		if (fireActiveLevel3[i]) {
			if (catx + 50 > firePositionsLevel3[i][0] && catx < firePositionsLevel3[i][0] + 50 &&
				caty + 50 > firePositionsLevel3[i][1] && caty < firePositionsLevel3[i][1] + 50) {
				gameOver3 = true;
				//PlaySound("gameovermusic.wav", NULL, SND_ASYNC); 
			}
		}
	}
	if (isLevel3Finished) {
		// Display the "Level Complete" screen
		iShowBMP2(250, 100, "im\\levelcomplete.bmp", 0);
		char scoreText[10];
		if (scoreLevel2 < 10) {
			scoreText[0] = '0' + scoreLevel2;
			scoreText[1] = '\0';
		}
		else {
			scoreText[0] = '0' + (scoreLevel2 / 10);
			scoreText[1] = '0' + (scoreLevel2 % 10);
			scoreText[2] = '\0';
		}
		iText(470, 190, scoreText, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 100, "Press Enter to Play Again", GLUT_BITMAP_TIMES_ROMAN_24);

		if (!winMusicPlayed) {
			PlaySound("winmusic.wav", NULL, SND_ASYNC);
			winMusicPlayed = true;
		}
		return;  // Stop further rendering
	}



	if (gameOver3) {
		iShowBMP2(250, 100, "im\\gameover.bmp", 0);
		iSetColor(255, 255, 255);
		iText(340, 180, "Press R to Restart", GLUT_BITMAP_TIMES_ROMAN_24);
		PlaySound("gameovermusic.wav", NULL, SND_ASYNC);
		Sleep(3000);

	}
	//gate hide
	if (isBoxAtTargetPosition(boxX, boxY)) {
		gateVisible = false;  // Hide the gate
		if (!gateSoundPlayed) {
			PlaySound("gateopen.wav", NULL, SND_SYNC);  // Play the sound effect
			gateSoundPlayed = true;  // Set the flag to true
		}

	}

}






void startbuttonhandler()
{
	if (musicon)
	{
		musicon = false;
		PlaySound(0, 0, 0);  // Stop any playing sound
	}
	homepage = 0;
	startpage = 1;
}
void helpbuttonhandler()
{
	homepage = 0;
	startpage = 0;
	helppage = 1;
}
void aboutusbuttonhandler(){
	homepage = 0;
	startpage = 0;
	helppage = 0;
	aboutus = 1;
}
void backbuttonhandler()
{
	if (musicon == false)
	{
		musicon = true;
		PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	homepage = 1;
	startpage = 0;
	helppage = 0;

}
void level1buttonhandler()
{
	homepage = 0;
	startpage = 0;
	helppage = 0;
	aboutus=0;
	levelpage = 1;
	level2page = 0;
	level3page = 0;

	catx = 0;
	caty = 100;
	isLevelFinished = false;
	gameOver = false;
	winMusicPlayed = false;

	for (int i = 0; i < 7; i++) {
		fishCollected[i] = false;
	}
	totalFishCollected = 0;  // Reset the fish count to 0
	score = 0;
	level1StartTime = timeGetTime() / 1000;
	isTimerRunning = true;

	isLevel3Finished = false;


	PlaySound(0, 0, 0);
	PlaySound("meow.wav", NULL, SND_ASYNC);
	lastMeowTime = timeGetTime();  // Set the initial time for the first "meow" sound
}
void level2buttonhandler() {
	// Transition to Level 2
	levelpage = 0;  // Disable Level 1
	level2page = 1;  // Enable Level 2

	catx = 0;
	caty = 0;

	//backgroundOffset = 0;
	isLevelFinished = false;
	isLevelFinished = false;
	gameOver2 = false;
	totalFishCollectedLevel2 = 0;
	scoreLevel2 = 0;

	// Reset fires and fish
	for (int i = 0; i < 4; i++)  // Reset 4 fires
	{


		fireActive[i] = true;
	}
	for (int i = 0; i < 5; i++)  // Reset 5 fish
	{
		fishCollectedLevel2[i] = false;
	}



	// Start the timer
	level2StartTime = timeGetTime() / 1000;
	//isLevel2TimerRunning = true;
	level2Started = false;
	isLevel2TimerRunning = true;

	winMusicPlayed = false;
	PlaySound(0, 0, 0);
	PlaySound("meow.wav", NULL, SND_ASYNC);
	lastMeowTime = timeGetTime();  // Set the initial time for the first "meow" sound

}
void level3buttonhandler() {
	levelpage = 0;
	level2page = 0;
	level3page = 1;
	catx = 0;  // Start at the left edge of the screen
	caty = 50; // Stand on the first wall (height = 50)
	isJumping = false;  // Reset jump state

	boxX = 400;  //  X position of the box
	boxY = 40;   // Y position of the box


	gateVisible = true;  // Gate is visible again
	gateSoundPlayed = false;

	// Reset fish data
	for (int i = 0; i < 5; i++) {
		fishCollectedLevel3[i] = false;
	}
	totalFishCollectedLevel3 = 0;
	scoreLevel3 = 0;
	// Reset fires
	for (int i = 0; i < 3; i++) {
		firePositionsLevel3[i][1] = 0;  // Reset Y position to the bottom
		fireActiveLevel3[i] = true;     // Reactivate fires
	}
	gameOver3 = false;
	isLevel3Finished = false;
	// Start the timer
	level3StartTime = timeGetTime() / 1000;  // Record the start time in seconds
	isLevel3TimerRunning = true;


	winMusicPlayed = false;
	// Play meow sound
	PlaySound(0, 0, 0);
	PlaySound("meow.wav", NULL, SND_ASYNC);
	lastMeowTime = timeGetTime();
}





int main()
{
	if (musicon)
	{
		PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	///srand((unsigned)time(NULL));
	iInitialize(800, 450, "The Meow Escape");

	///updated see the documentations
	iStart();
	return 0;
}