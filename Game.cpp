#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<iomanip>

using namespace std;

string monster_names[] = { "Goblin" ,"Ghoul" ,"Abyssal" ,"Witch" ,"Shadow" ,"Nightcrawler" }; //Monsters.

string item_names[] = { "Healing Potion", "Chest", "Mysterious Potion", "Level 2 Sword", " Level 3 Sword", "Level 2 Armour", "Level 3 Armour", "Level 2 Shield", "Level 3 Shield" };

string npcs[] = { "Peasent", "Pub Owner", "Guard", "Blacksmith", "Shopkeeper" };

string inventory[10];

int player_health = 60;
int player_level = 1;
int total_health = 0, max_health = 0, next_level = 40, heal = 0, xp = 0, level = 0;
int damage_multiplier = 10;

int monster_level;
int monster_hp = 0;
int monster_xp = 0;
int boss_health = 400;
int boss_damage;

string player_name;

void monster_maker() {

	srand(time(0));

	monster_hp = 20; //Base health.

	monster_level = rand() % 3 + 1;  //As player's level keeps getting increased, the monster's will get tougher and tougher.

	monster_hp += rand() % 20 * monster_level; //Monster's health will also be randomized according to its level.

	monster_xp = monster_hp;

}

void generateGoblinPicture() {
	cout << R"(
               
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \
        )" << endl;
}

void generateGhoul() {
	cout << R"(
     .-.
    (o o) boo!
    | O \
     \   \
      `~~~'
    )" << endl;

}

void generateAbyssal() {
	cout << R"(

		  .-----.
         /  _    \
        /  / \    \
       |  |   \    |
       \ \ \ /    /
        \ ----- /
        /      \
       /        \
      /   O   O  \
      |    (_)    |
      \    / \    /
       \--------/
        \      /
         \    /
          \  /
           \/                                                                
    )" << endl;

}

void generateWitch() {
	cout << R"(

					      X
                        xXXx                               
					    xxxXxx                        
                        xxXXxx                        
                        xxXXxxx          
                        xxxXxxx                          
                        xxxXXxxx                        
	                     xxxxXXxx                       
                        xxxxXXxx                   
                        %%xxxxx%%                 
                        %%%%%%%%%
                       %%%%%%%%%%%
                       %%%%%%%%%%%			
			           %%%%%%%%%%%
                     xxxxxxxx%%%%%
                   xxXXXXXXXxxx%%%               
                 xxXx/////xxXxxx%%          
         xxxxxxxxxXxx////(/xxXxxx%          
           XXXXXXXxx//(/(((/xxxXxx          
 		       xxxx////(/(/(/)\\xXxx
               ///////(/(/(/\)\\xxxx
               /((/(//(/(/((\/\)xXxxx
               //(/(/(//(/  \ \)\xxxxx
               //((//(/( /    \ \\\xxxx         
			   (((///(\   \ /  )\)\xXxx
               /(//((/(\  @ /@  )\\)\xxx
              //(/(///(\::/ \:::)\\))\xxx
             /(/(/(///(\:(   ):/)\\)\)\xXx
            /((/(/(/(/(\  \ /  /)\\)\\)\xxxx
              //(/(/(/(\\ \__/ /)\\\)\)\\ xx
		   /////(/(/(/(\\\    //)))\)\\)                   
              /((/(/(/(/(\\\_///)))\)\\\\)       
                    
)" << endl;

}

void generateShadow() {
	cout << R"(
       .-"""-.
      /        \
     /  o   o   \
     |    ∆     | 
     \    ~    /
      '-...--'
    )" << endl;
}

void generateNightcrawler() {

	cout << R"(
       )  (
       _ _ _ _ _ _ _ _ _ _ _(.--.)
     {{ { { { { { { { { { { ( '_' )
      >>>>>>>>>>>>>>>>>>>>>>>`--'>
)" << endl;

}

void Hud() {


	system("cls");

	cout << "Name: " << player_name << endl;

	cout << "Health:  " << player_health << endl; //gonna include health variable here.

	cout << "Level: " << player_level << endl;//gonna include a level variable here.

	cout << "Next levl at: " << next_level << ". Current xp points: " << xp << endl;

}

void combatHud() {

	Sleep(1000);
	system("cls");

	if (player_level == 5) {
		cout << "Name: " << player_name << setw(5) << "|" << "\nHealth: " << player_health << "\t" << "Boss's Health: " << boss_health << "\nLevel: " << player_level << endl;
	}
	else {
		cout << "Name: " << player_name << setw(5) << "|" << "\nHealth: " << player_health << "\t" << "Monster's Health: " << monster_hp << "\nLevel: " << player_level << "\t" << "Monster's Level: " << monster_level << endl;
	}

}

void Level_update() {

	xp += monster_xp; //After killing each monster, xp points will be stored in our xp variable.

	if (xp >= next_level) { //When the xp variable is greater than our next_level variable, our level will get updated.
		xp = 0; //This will reset our xp points.
		system("color 2");

		player_level++;
		player_health += 20; //And so our hitpoints will also increase with each level

		max_health = player_health;

		next_level += 20; //With each level up, the next level will require more xp points than the previous one.
		system("cls");

		cout << "Level Upgraded. You are now level: " << player_level << endl;
		Sleep(3000);

		cout << "Your HP is now: " << max_health << endl;

		cout << "Your attack damage has also been increased." << endl;
		damage_multiplier += 10;

		Sleep(3000);
		Hud();

	}

}

void Adding_to_inventory(const string& item) {  //We are gonna take the value from the choices and pass them here.The const data type is used so that the item dosen't get modified.

	for (int i = 0; i < 10; i++) { //The loop will iterate for each value of the array.

		if (inventory[i].empty()) { //Empty is a string function that will check if any index in the array is empty. If it is, the empty function will return true.

			inventory[i] = item; //If it is, the item will be stored in that position.

			cout << "Added " << item << " to your inventory." << endl;

			Sleep(1000);

			break; //and the loop will break.
		}
	}

}

void Showing_inventory() {

	cout << "Inventory: " << endl;
	for (int i = 0; i < 10; i++) {
		if (!inventory[i].empty()) {
			cout << inventory[i] << ",";
		}
	}
}

void Using_item() {

	cout << "Enter the number of item you want to use. Press 0 to exit the inventory." << endl;
	char item_choice;
	cin >> item_choice;

	if (item_choice >= '1' && item_choice <= '10' && !inventory[item_choice - '1'].empty()) { //It will check if the given input is within the range and that the item at that point is not empty.
		string itemName = inventory[item_choice - '1']; //making this variable so that I can use the item_choice variable as a string, and this string will be used in conditionals for the logic I use in the items.

		cout << "You used a " << inventory[item_choice - '1'] << endl;

		if (itemName == "Healing Potion") {
			cout << "Your health was increased." << endl;
			Sleep(2000);
			player_health += 20;
		}


		if (itemName == "Mysterious Potion") {  //For mysterious potion, I wanted to add an element of randomness, as it can both damage and benefit the player.
			int x = rand() % 100 + 1;
			if (x >= 0 && x <= 50) {
				cout << "You were posioned." << endl;
				Sleep(2000);
				player_health -= 20;
			}

			else if (x > 50 && x <= 85) {      //A 35 percent chance that the player will gain health.
				cout << "You were healed." << endl;
				Sleep(2000);
				player_health += 20;
			}

			else {
				cout << "Your attack damage has been increased." << endl;
				Sleep(2000);
				damage_multiplier += 10; //A 15 percent chance that the damage done will be increased.
			}
		}

		if (itemName == "Level 2 Sword") {
			cout << "Your attack power was increased." << endl;
			Sleep(2000);
			damage_multiplier += 10;
		}

		if (itemName == "Level 3 Sword") {
			cout << "Your attack power was increased." << endl;
			Sleep(2000);
			damage_multiplier += 20;
		}

		if (itemName == "Level 2 Armour") {
			cout << "Your health was increased." << endl;
			Sleep(2000);
			player_health += 25;
		}

		if (itemName == "Level 3 Armour") {
			cout << "Your health was increased." << endl;
			Sleep(2000);
			player_health += 40;
		}

		if (itemName == "Chest") { //Writing this whole logic for our chest item.
			int a = rand() % 100 + 1;	//a will be randomized from 1 to 100.
			if (a > 0 && a <= 40) {
				cout << "You have found a helmet. Your health was increased." << endl;
				Sleep(2000);
				player_health += 20;
			}

			else if (a > 40 && a <= 60) {
				cout << "The chest had a hidden trap inside. You were damaged and your health was decreased." << endl;
				Sleep(2000);
				player_health -= 10;
			}

			else if (a > 60 && a <= 80) {
				cout << "The chest was empty and had nothing inside." << endl;
				Sleep(2000);
			}

			else if (a > 80 && a <= 100) {
				cout << "You have found a rare golden sword. Your attack was increased." << endl;
				Sleep(2000);
				damage_multiplier += 50;
			}
		}

		if (itemName == "Level 2 Shield") {
			cout << "Your health was increased." << endl;
			player_health += 10;
			Sleep(2000);
		}

		if (itemName == "Level 3 Sheild") {
			cout << "Your health was increased." << endl;
			player_health += 20;
			Sleep(2000);
		}

		if (itemName == " ") {
			cout << "There is no item here." << endl;
			Sleep(1000);
		}

		inventory[item_choice - '1'] = " "; //This will replace the used item with an empty string.

	}

	else if (item_choice == '0') { //If the user enters 0, we return to the Hud.
		combatHud();
	}

	else if (item_choice != '0') {
		cout << "Wrong input.Please try again." << endl; //This code is for error handling if the user dosent enter 0.
		Using_item();
	}

	else  {
		cout << "Wrong input.Please try again." << endl; //This code is for error handling if the user dosent enter 0.
		Using_item();
	}

}

void combat() {

	srand(time(0));

	Sleep(1000);

	combatHud();

	char player_attack;
	int player_damage;
	int monster_attack =1 ;
	int monster_attack_randomier;

	while (player_health >= 1 && monster_hp >= 1) { // If the player and monster's health is above zero, only then will the attack option work.

		cout << "1 Attack" << endl;
		cout << "2 Block" << endl;
		cout << "3 Inventory" << endl;
		cin >> player_attack;

		if (player_attack == '1') {

			player_attack = '\0';
			int RNG = rand() % 9 + 1; //damage dealt will scale from 1 to 9.
			player_damage = RNG + damage_multiplier;
			cout << "You dealt " << player_damage << " damage." << endl;

			monster_hp -= player_damage;

			Sleep(1000);
			combatHud();

			if (monster_hp > 0) {
				cout << "Monster's turn " << endl;

				monster_attack_randomier = rand() % 9 + 1;
				if (monster_level == 1) {
					monster_attack = monster_attack_randomier * 2;
				}

				else if (monster_level == 2) {
					monster_attack = monster_attack_randomier * 5;
				}

				else if (monster_level == 3) {
					monster_attack = monster_attack_randomier * 7;
				}

				cout << "Monster dealt " << monster_attack << " damage" << endl;

				player_health -= monster_attack;
				Sleep(1000);

				combatHud();

				if (player_health <= 0) {

					player_health = 0;

					cout << "You died. Game Over.";
					Sleep(2000);
					exit(0);

				}
			}
			else if (monster_hp <= 0) {
				system("color 2");
				monster_hp = 0; // If the monster's hp goes below zero, we are gonna make it zero.

				cout << "You killed the monster. You gained " << monster_xp << " xp points." << endl;
				Sleep(3000);

				Hud();
				Level_update();

			}
		}

		if (player_attack == '2') {
			player_attack = '\0';
			int randomizer = rand() % 100 + 1; //adding a randomizer because there will be a chance as to if the player's block actually works

			if (randomizer >= 0 && randomizer <= 40) {
				cout << "The block was successful." << endl;
				Sleep(1000);

				player_health += rand() % 10 + 1; //There will be a chance that the health will be restored from 1 to 10
				cout << "You gained some health." << endl;

				combatHud();

				combat();

			}
			else {
				cout << "The block failed. You suffered some damage." << endl;
				Sleep(1000);
				player_health = player_health - (rand()%20 +5 * 2); //multiplying with two, beacause I want to punish the player, incase his block dosen't work.
				combatHud();
				if (player_health <= 0) {
					cout << "You died!" << endl; //Added this condition because if the player's health was low and the block failed the game was not being over.
					Sleep(1000);
					exit(0);
				}

				Sleep(1000);
				combat();
			}

		}

		else if (player_attack == '3') {

			Showing_inventory();
			Sleep(1000);
			Using_item();
			Sleep(1000);

		}

		else if (player_attack == 'A' || player_attack == 'z') {
			cout << "Wrong input. Try again." << endl;
			Sleep(1000);
			combat();
		}
	}

}

void boss_fight() {

	srand(time(0));

	Sleep(1000);

	system("cls");

	combatHud();


	char player_attack;
	int player_damage;

	while (player_health >= 1 && boss_health >= 1) { // If the player and monster's health is above zero, only then will the attack option work.

		cout << "1 Attack" << endl;
		cout << "2 Block" << endl;
		cout << "3 Inventory" << endl;
		cin >> player_attack;

		if (player_attack == '1') {

			player_attack = '\0';
			int RNG = rand() % 9 + 1; //damage dealt will scale from 1 to 9.
			player_damage = RNG + damage_multiplier;
			cout << "You dealt " << player_damage << " damage." << endl;

			boss_health -= player_damage;

			Sleep(1000);
			combatHud();

			if (boss_health > 0) {
				cout << "Boss's turn " << endl;
				boss_damage = rand() % 150 + 1; //Initializing the value of boss damage here so that it keeps on getting randomized.
				cout << "Boss dealt " << boss_damage << " damage" << endl;

				player_health -= boss_damage;
				Sleep(1000);

				combatHud();

				if (player_health <= 0) {
					cout << "You died. Game Over.";
					Sleep(2000);
					exit(0);

				}
			}
			else if (boss_health <= 0) {
				system("color 2");
				boss_health = 0; // If the monster's hp goes below zero, we are gonna make it zero.

				cout << "You killed the boss. You have won the game." << endl;
				Sleep(3000);
				exit(0);
			}
		}

		if (player_attack == '2') {
			player_attack = '\0';
			int randomizer = rand() % 100 + 1; //adding a randomizer because there will be a chance as to if the player's block actually works

			if (randomizer >= 0 && randomizer <= 40) {
				cout << "The block was successful." << endl;
				Sleep(1000);

				player_health += rand() % 10 + 1; //There will be a chance that the health will be restored from 1 to 10
				cout << "You gained some health." << endl;

				combatHud();
				Sleep(1000);
				boss_fight();


			}
			else {
				cout << "The block failed. You suffered some damage." << endl;
				Sleep(1000);
				player_health = player_health - boss_damage * 2; //multiplying with two, beacause I want to punish the player, incase his block dosen't work.
				combatHud();
				if (player_health <= 0) {
					cout << "You died!" << endl; //Added this condition because if the player's health was low and the block failed the game was not being over.
					Sleep(1000);
					exit(0);
				}

				Sleep(1000);
				boss_fight();
			}

		}

		else if (player_attack == '3') {

			Showing_inventory();
			Sleep(1000);
			Using_item();
			Sleep(1000);

		}

		else if (player_attack == 'A' || player_attack == 'z') {
			cout << "Wrong input. Try again." << endl;
			Sleep(1000);
			boss_fight();
		}
	}


}

void movement() {
	srand(time(0));

	Hud(); //Putting hud in movement as we will need to display it every time.

	if (player_level == 5) { //If player reaches a specific level, we will call the boss fight function.

		system("cls");

		cout << setw(20) << "Okay Player. The time has come for you to fight the King of monsters....." << endl;
		Sleep(3000);

		boss_fight();
	}

	string choice;

	cout << "Move Forward:  1\n";
	cout << "Move Left: 2\n";
	cout << "Move Right:3\n";
	cout << "Move Backward: 4\n";

	cin >> choice;

	if (choice == "1") {

		choice = '\0 ';
		int temp = rand() % 100 + 1;
		cout << "You begin to move forward.\n";

		if (temp > 0 && temp <= 50) { // A 50% chance that a monster will appear.

			system("color 4");

			monster_maker();

			string name = monster_names[rand() % 6]; //aik vairable bnae ge name ka jis me monsters k names store hoge. or vo ese kh hum monster ki global array ka index randomize kr de ge.

			cout << "You have encounterd a " << name << endl;


			if (name == "Goblin") {
				generateGoblinPicture();
				Sleep(3000);
				system("cls");
			}

			else if (name == "Ghoul") {
				generateGhoul();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Abyssal") {
				generateAbyssal();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Witch") {
				generateWitch();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Shadow") {
				generateShadow();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Nightcrawler") {
				generateNightcrawler();
				Sleep(3000);
				system("cls");
			}

			cout << "Prepare to fight !";
			Sleep(2000);
			combat();

		}

		else if (temp > 50 && temp <= 75) {  // There will be a 25% chance that the player finds an item.

			system("color 2");
			string item = item_names[rand() % 9]; //Isi trah hum item ka vairble bnae ge jis k andr apne item ka name store krvae ge by randomizing the index of our global items array.


			string item_choice;
			cout << "You found a " << item << endl;



			if (item == "Healing Potion") {

				cout << "Do you want to take it ?.... Y/N" << endl;   //Creating this choices if the player gets something from the items_names global variable.
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Healing Potion");
					movement();
				}

				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}

			}

			else if (item == "Chest") {
				cout << "Do you want to open it? Y/N " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Chest");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Mysterious Potion") {
				cout << "Do you want to take it? " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Mysterious Potion");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == " Level 3 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 3 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Shield") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Shield");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}
		}

		else if (temp > 75 && temp <= 80) {
			system("color 2");
			cout << "You found nothing of interest.";
			Sleep(2000);
			movement();
		}

		else if (temp > 80 && temp <= 100) {

			string npc_name = npcs[rand() % 5];
			cout << "You have met a " << npc_name << ".";
			Sleep(2000);

			system("cls");

			if (npc_name == "Peasent") {

				cout << "Hello traveller! How are you doing?" << endl;
				Sleep(3000);
				cout << "You should be careful.It's a strange world out there." << endl;
				Sleep(3000);
				cout << "Monsters creeping up everywhere.I just hope everything returns to normal." << endl;
				Sleep(3000);
				movement();
			}

			else if (npc_name == "Pub Owner") {
				cout << "Oi matey!" << endl;
				Sleep(3000);
				cout << "You look like somone who can use a drink.We have got the finest ale in the town." << endl;
				Sleep(3000);
				cout << "Whadaya say ? care for a drink ? " << endl;
				Sleep(3000);

				while (true) {

					char drink_choice;
					cout << "Y for Yes and N for No" << endl;

					cin >> drink_choice;

					if (drink_choice == 'Y' || drink_choice == 'y') {
						char d_choice;

						cout << "What do you want to have?" << endl;
						cout << "Press 1 for Scotch" << endl;
						cout << "Press 2 for Moonshine" << endl;
						cout << "Press 3 for Ale" << endl;
						cout << "Press 4 for Whiskey" << endl;


						cin >> d_choice;
						if (d_choice == '1') {
							cout << "You drank some Scotch and feel sleepy" << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '2') {
							cout << "You have indulged yourself in Moonshine. This is quite strong." << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '3') {
							cout << "You drank the town's most famous ale. You are now feeling that you might throw up." << endl;
							Sleep(5000);
							player_health -= 10;
							movement();
						}

						else if (d_choice == '4') {
							cout << "You drank some whiskey. This reminds you of home. Right now there is no time to think of home." << endl;
							Sleep(5000);
							player_health += 10;
							movement();
						}

						else if (d_choice == 'A' || d_choice == 'z') {
							cout << "Wrong Input, Try again.";
							break;
						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");


					}
					else if (drink_choice == 'N' || drink_choice == 'n') {
						cout << "Your loss mate." << endl;
						Sleep(4000);
						movement();
						break;

				    }
			

			    }

			}

			else if (npc_name == "Guard") {
				cout << "Hold Off You Filthy insect!" << endl;
				Sleep(3000);
				cout << "Don't you dare come near me!" << endl;
				Sleep(3000);
				cout << "You better get lost before I do something you might regert for the rest of your life" << endl;
				Sleep(3000);
				movement();
			}

			else if (npc_name == "Blacksmith") {
				cout << "Oi sonny boy!" << endl;
				Sleep(3000);
				cout << "Your sword looks like it needs some work." << endl;
				Sleep(3000);
				cout << "Mind if I have a look? ." << endl;
				Sleep(3000);
				cout << "Do you want to repair your sword?" << endl;
				char repair;
				cout << "Press Y for Yes or N for No." << endl;

				while (player_health > 1) {


					cin >> repair;

					if (repair == 'Y' || repair == 'y') {
						cout << "Your sword was repaired" << endl;
						damage_multiplier += 5;
						Sleep(4000);
						movement();

					}

					else if (repair == 'N' || repair == 'n') {
						cout << "Okay son, your choice. Do remember it is a scary world out there." << endl;
						Sleep(4000);
						movement();
					}

					else if (repair == 'A' || repair == 'z') {
						cout << "Wrong input! Try again." << endl;
						Sleep(1000);

					}

					cout << "Wrong Input. Try again." << endl;
					Sleep(1000);
					system("cls");

				}

			}

			else if (npc_name == "Shopkeeper") {
				cout << "Hello son. My God! You look like you haven't had a meal for deacades." << endl;
				Sleep(3000);
				cout << "Come here have a seat. What do you wanna have? " << endl;
				Sleep(3000);

				char shop_choice;
				cout << "Press Y to accept or N to refuse." << endl;
				while (true) {
					cin >> shop_choice;

					if (shop_choice == 'Y' || shop_choice == 'y') {
						cout << "Sit here son, tell me what do you wanna have." << endl;
						char food_choice;
						cout << "1 for Beef Jerky." << endl;
						cout << "2 for cup of water." << endl;
						cout << "3 for Chicken soup." << endl;
						cout << "4 for an apple." << endl;

						cin >> food_choice;

						if (food_choice == '1') {
							cout << "You ate some beef jerky. It tasted really amazing." << endl;
							Sleep(3000);
							cout << "You feel stronger and have gained some health." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}


						else if (food_choice == '2') {
							cout << "Your thorat feels parched. You asked the shopkeeper for some water." << endl;
							Sleep(3000);
							cout << "You drank some water and now feel refresehd." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '3') {
							cout << "Your stomach is growling. You can really use a good meal right now. You asked the shopkeeper for some chicken soup" << endl;
							Sleep(3000);
							cout << "You ate the soup and now feel satisfied. Your health has increased" << endl;
							player_health += 10;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '4') {
							cout << "Ahhh an apple. Smart choice." << endl;
							Sleep(3000);
							cout << "You know what they say, an apple a day keeps the monsters away." << endl;
							Sleep(3000);
							cout << "You don't care and start eating your apple. It was very healthy." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == 'A' || food_choice == 'z') {
							cout << "Wrong Input. Try again." << endl;
							break;

						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");

					}

					else if (shop_choice == 'N' || shop_choice == 'n') {
						cout << "Your choice son. I was just being kind." << endl;
						Sleep(3000);
						movement();
					}

				}
			}

			//This whole portion is for NPCS
		}

	}

	if (choice == "2") {
		choice = '\0 ';
		int temp = rand() % 100 + 1;
		cout << "You begin to move left.\n";

		if (temp >= 0 && temp <= 50) { // A 50% chance that a monster will appear.

			system("color 4");

			monster_maker();

			string name = monster_names[rand() % 6]; //aik vairable bnae ge name ka jis me monsters k names store hoge. or vo ese kh hum monster ki global array ka index randomize kr de ge.

			cout << "You have encounterd a " << name << endl;
			if (name == "Goblin") {
				generateGoblinPicture();
				Sleep(3000);
				system("cls");
			}

			else if (name == "Ghoul") {
				generateGhoul();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Abyssal") {
				generateAbyssal();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Witch") {
				generateWitch();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Shadow") {
				generateShadow();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Nightcrawler") {
				generateNightcrawler();
				Sleep(3000);
				system("cls");
			}



			cout << "Prepare to fight !";

			Sleep(2000);
			combat();

		}

		else if (temp > 50 && temp <= 75) {  // There will be a 25% chance that the player finds an item.


			string item = item_names[rand() % 9]; //Isi trah hum item ka vairble bnae ge jis k andr apne item ka name store krvae ge by randomizing the index of our global items array.


			string item_choice;
			cout << "You found a " << item << endl;



			if (item == "Healing Potion") {

				cout << "Do you want to take it ?.... Y/N" << endl;   //Creating this choices if the player gets something from the items_names global variable.
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Healing Potion");
					movement();
				}

				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}

			}

			else if (item == "Chest") {
				cout << "Do you want to open it? Y/N " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Chest");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Mysterious Potion") {
				cout << "Do you want to take it? " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Mysterious Potion");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == " Level 3 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 3 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Shield") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Shield");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}
		}

		else if (temp > 75 && temp <= 80) {
			cout << "You found nothing of interest.";
			Sleep(1000);
			movement();
		}

		else if (temp > 80 && temp <= 100) {
			string npc_name = npcs[rand() % 5];
			cout << "You have met a " << npc_name << ".";
			Sleep(2000);

			system("cls");

			if (npc_name == "Peasent") {

				cout << "Hello traveller! How are you doing?" << endl;
				Sleep(3000);
				cout << "You should be careful.It's a strange world out there." << endl;
				Sleep(3000);
				cout << "Monsters creeping up everywhere.I just hope everything returns to normal." << endl;
				Sleep(3000);
				movement();
			}

			else if (npc_name == "Pub Owner") {
				cout << "Oi matey!" << endl;
				Sleep(3000);
				cout << "You look like somone who can use a drink.We have got the finest ale in the town." << endl;
				Sleep(3000);
				cout << "Whadaya say ? care for a drink ? " << endl;
				Sleep(3000);

				while (true) {

					char drink_choice;
					cout << "Y for Yes and N for No" << endl;

					cin >> drink_choice;

					if (drink_choice == 'Y' || drink_choice == 'y') {
						char d_choice;

						cout << "What do you want to have?" << endl;
						cout << "Press 1 for Scotch" << endl;
						cout << "Press 2 for Moonshine" << endl;
						cout << "Press 3 for Ale" << endl;
						cout << "Press 4 for Whiskey" << endl;


						cin >> d_choice;
						if (d_choice == '1') {
							cout << "You drank some Scotch and feel sleepy" << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '2') {
							cout << "You have indulged yourself in Moonshine. This is quite strong." << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '3') {
							cout << "You drank the town's most famous ale. You are now feeling that you might throw up." << endl;
							Sleep(5000);
							player_health -= 10;
							movement();
						}

						else if (d_choice == '4') {
							cout << "You drank some whiskey. This reminds you of home. Right now there is no time to think of home." << endl;
							Sleep(5000);
							player_health += 10;
							movement();
						}

						else if (d_choice == 'A' || d_choice == 'z') {
							cout << "Wrong Input, Try again.";
							break;
						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");


					}
					else if (drink_choice == 'N' || drink_choice == 'n') {
						cout << "Your loss mate." << endl;
						Sleep(4000);
						movement();
						break;

					}


				}

			}

			else if (npc_name == "Guard") {
				cout << "Hold Off You Filthy insect!" << endl;
				Sleep(3000);
				cout << "Don't you dare come near me!" << endl;
				Sleep(3000);
				cout << "You better get lost before I do something you might regert for the rest of your life" << endl;
				Sleep(3000);
				movement();
			}

			else if (npc_name == "Blacksmith") {
				cout << "Oi sonny boy!" << endl;
				Sleep(3000);
				cout << "Your sword looks like it needs some work." << endl;
				Sleep(3000);
				cout << "Mind if I have a look? ." << endl;
				Sleep(3000);
				cout << "Do you want to repair your sword?" << endl;
				char repair;
				cout << "Press Y for Yes or N for No." << endl;

				while (player_health > 1) {


					cin >> repair;

					if (repair == 'Y' || repair == 'y') {
						cout << "Your sword was repaired" << endl;
						damage_multiplier += 5;
						Sleep(4000);
						movement();

					}

					else if (repair == 'N' || repair == 'n') {
						cout << "Okay son, your choice. Do remember it is a scary world out there." << endl;
						Sleep(4000);
						movement();
					}

					else if (repair == 'A' || repair == 'z') {
						cout << "Wrong input! Try again." << endl;
						Sleep(1000);

					}

					cout << "Wrong Input. Try again." << endl;
					Sleep(1000);
					system("cls");

				}

			}

			else if (npc_name == "Shopkeeper") {
				cout << "Hello son. My God! You look like you haven't had a meal for deacades." << endl;
				Sleep(3000);
				cout << "Come here have a seat. What do you wanna have? " << endl;
				Sleep(3000);

				char shop_choice;
				cout << "Press Y to accept or N to refuse." << endl;
				while (true) {
					cin >> shop_choice;

					if (shop_choice == 'Y' || shop_choice == 'y') {
						cout << "Sit here son, tell me what do you wanna have." << endl;
						char food_choice;
						cout << "1 for Beef Jerky." << endl;
						cout << "2 for cup of water." << endl;
						cout << "3 for Chicken soup." << endl;
						cout << "4 for an apple." << endl;

						cin >> food_choice;


						if (food_choice == '1') {
							cout << "You ate some beef jerky. It tasted really amazing." << endl;
							Sleep(3000);
							cout << "You feel stronger and have gained some health." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}


						else if (food_choice == '2') {
							cout << "Your thorat feels parched. You asked the shopkeeper for some water." << endl;
							Sleep(3000);
							cout << "You drank some water and now feel refresehd." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '3') {
							cout << "Your stomach is growling. You can really use a good meal right now. You asked the shopkeeper for some chicken soup" << endl;
							Sleep(3000);
							cout << "You ate the soup and now feel satisfied. Your health has increased" << endl;
							player_health += 10;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '4') {
							cout << "Ahhh an apple. Smart choice." << endl;
							Sleep(3000);
							cout << "You know what they say, an apple a day keeps the monsters away." << endl;
							Sleep(3000);
							cout << "You don't care and start eating your apple. It was very healthy." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == 'A' || food_choice == 'z') {
							cout << "Wrong Input. Try again." << endl;
							break;

						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");

					}

					else if (shop_choice == 'N' || shop_choice == 'n') {
						cout << "Your choice son. I was just being kind." << endl;
						Sleep(3000);
						movement();
					}

				}
				}

		} //This whole portion is for NPCS
	}

	if (choice == "3") {
		choice = '\0';
		int temp = rand() % 100 + 1;
		cout << "You begin to move right.\n";

		if (temp >= 0 && temp <= 50) { // A 50% chance that a monster will appear.

			system("color 4");

			monster_maker();

			string name = monster_names[rand() % 6]; //aik vairable bnae ge name ka jis me monsters k names store hoge. or vo ese kh hum monster ki global array ka index randomize kr de ge.

			cout << "You have encounterd a " << name << endl;



			if (name == "Goblin") {
				generateGoblinPicture();
				Sleep(3000);
				system("cls");
			}

			else if (name == "Ghoul") {
				generateGhoul();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Abyssal") {
				generateAbyssal();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Witch") {
				generateWitch();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Shadow") {
				generateShadow();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Nightcrawler") {
				generateNightcrawler();
				Sleep(3000);
				system("cls");
			}

			cout << "Prepare to fight !";

			Sleep(2000);
			combat();

		}

		else if (temp > 50 && temp <= 75) {  // There will be a 25% chance that the player finds an item.


			string item = item_names[rand() % 9]; //Isi trah hum item ka vairble bnae ge jis k andr apne item ka name store krvae ge by randomizing the index of our global items array.


			string item_choice;
			cout << "You found a " << item << endl;



			if (item == "Healing Potion") {

				cout << "Do you want to take it ?.... Y/N" << endl;   //Creating this choices if the player gets something from the items_names global variable.
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Healing Potion");
					movement();
				}

				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}

			}

			else if (item == "Chest") {
				cout << "Do you want to open it? Y/N " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Chest");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Mysterious Potion") {
				cout << "Do you want to take it? " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Mysterious Potion");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == " Level 3 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 3 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Shield") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Shield");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}
		}

		else if (temp > 75 && temp <= 80) {  //The remaining 15% will be for nothing found.
			cout << "You found nothing of interest.";
			Sleep(1000);
			movement();
		}

		else if (temp > 80 && temp <= 100) {
			string npc_name = npcs[rand() % 5];
			cout << "You have met a " << npc_name << ".";
			Sleep(2000);

			system("cls");

			if (npc_name == "Peasent") {

				cout << "Hello traveller! How are you doing?" << endl;
				Sleep(3000);
				cout << "You should be careful.It's a strange world out there." << endl;
				Sleep(3000);
				cout << "Monsters creeping up everywhere.I just hope everything returns to normal." << endl;
				Sleep(3000);
				movement();
			}

			else if (npc_name == "Pub Owner") {
				cout << "Oi matey!" << endl;
				Sleep(3000);
				cout << "You look like somone who can use a drink.We have got the finest ale in the town." << endl;
				Sleep(3000);
				cout << "Whadaya say ? care for a drink ? " << endl;
				Sleep(3000);

				while (true) {

					char drink_choice;
					cout << "Y for Yes and N for No" << endl;

					cin >> drink_choice;

					if (drink_choice == 'Y' || drink_choice == 'y') {
						char d_choice;

						cout << "What do you want to have?" << endl;
						cout << "Press 1 for Scotch" << endl;
						cout << "Press 2 for Moonshine" << endl;
						cout << "Press 3 for Ale" << endl;
						cout << "Press 4 for Whiskey" << endl;


						cin >> d_choice;
						if (d_choice == '1') {
							cout << "You drank some Scotch and feel sleepy" << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '2') {
							cout << "You have indulged yourself in Moonshine. This is quite strong." << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '3') {
							cout << "You drank the town's most famous ale. You are now feeling that you might throw up." << endl;
							Sleep(5000);
							player_health -= 10;
							movement();
						}

						else if (d_choice == '4') {
							cout << "You drank some whiskey. This reminds you of home. Right now there is no time to think of home." << endl;
							Sleep(5000);
							player_health += 10;
							movement();
						}

						else if (d_choice == 'A' || d_choice == 'z') {
							cout << "Wrong Input, Try again.";
							break;
						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");


					}
					else if (drink_choice == 'N' || drink_choice == 'n') {
						cout << "Your loss mate." << endl;
						Sleep(4000);
						movement();
						break;

					}


				}

			}

			else if (npc_name == "Guard") {
				cout << "Hold Off You Filthy insect!" << endl;
				Sleep(3000);
				cout << "Don't you dare come near me!" << endl;
				Sleep(3000);
				cout << "You better get lost before I do something you might regert for the rest of your life" << endl;
				Sleep(3000);
				movement();
			}

			else if (npc_name == "Blacksmith") {
				cout << "Oi sonny boy!" << endl;
				Sleep(3000);
				cout << "Your sword looks like it needs some work." << endl;
				Sleep(3000);
				cout << "Mind if I have a look? ." << endl;
				Sleep(3000);
				cout << "Do you want to repair your sword?" << endl;
				char repair;
				cout << "Press Y for Yes or N for No." << endl;

				while (player_health > 1) {


					cin >> repair;

					if (repair == 'Y' || repair == 'y') {
						cout << "Your sword was repaired" << endl;
						damage_multiplier += 5;
						Sleep(4000);
						movement();

					}

					else if (repair == 'N' || repair == 'n') {
						cout << "Okay son, your choice. Do remember it is a scary world out there." << endl;
						Sleep(4000);
						movement();
					}

					else if (repair == 'A' || repair == 'z') {
						cout << "Wrong input! Try again." << endl;
						Sleep(1000);

					}

					cout << "Wrong Input. Try again." << endl;
					Sleep(1000);
					system("cls");

				}

			}

			else if (npc_name == "Shopkeeper") {
				cout << "Hello son. My God! You look like you haven't had a meal for deacades." << endl;
				Sleep(3000);
				cout << "Come here have a seat. What do you wanna have? " << endl;
				Sleep(3000);

				char shop_choice;
				cout << "Press Y to accept or N to refuse." << endl;
				while (true) {
					cin >> shop_choice;

					if (shop_choice == 'Y' || shop_choice == 'y') {
						cout << "Sit here son, tell me what do you wanna have." << endl;
						char food_choice;
						cout << "1 for Beef Jerky." << endl;
						cout << "2 for cup of water." << endl;
						cout << "3 for Chicken soup." << endl;
						cout << "4 for an apple." << endl;

						cin >> food_choice;


						if (food_choice == '1') {
							cout << "You ate some beef jerky. It tasted really amazing." << endl;
							Sleep(3000);
							cout << "You feel stronger and have gained some health." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}


						else if (food_choice == '2') {
							cout << "Your thorat feels parched. You asked the shopkeeper for some water." << endl;
							Sleep(3000);
							cout << "You drank some water and now feel refresehd." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '3') {
							cout << "Your stomach is growling. You can really use a good meal right now. You asked the shopkeeper for some chicken soup" << endl;
							Sleep(3000);
							cout << "You ate the soup and now feel satisfied. Your health has increased" << endl;
							player_health += 10;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '4') {
							cout << "Ahhh an apple. Smart choice." << endl;
							Sleep(3000);
							cout << "You know what they say, an apple a day keeps the monsters away." << endl;
							Sleep(3000);
							cout << "You don't care and start eating your apple. It was very healthy." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == 'A' || food_choice == 'z') {
							cout << "Wrong Input. Try again." << endl;
							break;

						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");

					}

					else if (shop_choice == 'N' || shop_choice == 'n') {
						cout << "Your choice son. I was just being kind." << endl;
						Sleep(3000);
						movement();
					}

				}
				}


		} //This whole portion is for NPCS
	}

	if (choice == "4") {
		choice = '\0';
		int temp = rand() % 100 + 1;
		cout << "You begin to move backward.\n";

		if (temp >= 0 && temp <= 50) { // A 50% chance that a monster will appear.

			system("color 4");

			monster_maker();

			string name = monster_names[rand() % 6]; //aik vairable bnae ge name ka jis me monsters k names store hoge. or vo ese kh hum monster ki global array ka index randomize kr de ge.

			cout << "You have encounterd a " << name << endl;

			if (name == "Goblin") {
				generateGoblinPicture();
				Sleep(3000);
				system("cls");
			}

			else if (name == "Ghoul") {
				generateGhoul();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Abyssal") {
				generateAbyssal();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Witch") {
				generateWitch();
				Sleep(3000);
				system("cls");

			}
			else if (name == "Shadow") {
				generateShadow();
				Sleep(3000);
				system("cls");
			}
			else if (name == "Nightcrawler") {
				generateNightcrawler();
				Sleep(3000);
				system("cls");
			}

			cout << "Prepare to fight !";

			Sleep(2000);
			combat();

		}

		else if (temp > 50 && temp <= 75) {  // There will be a 25% chance that the player finds an item.


			string item = item_names[rand() % 9]; //Isi trah hum item ka vairble bnae ge jis k andr apne item ka name store krvae ge by randomizing the index of our global items array.


			string item_choice;
			cout << "You found a " << item << endl;



			if (item == "Healing Potion") {

				cout << "Do you want to take it ?.... Y/N" << endl;   //Creating this choices if the player gets something from the items_names global variable.
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Healing Potion");
					movement();
				}

				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}

			}

			else if (item == "Chest") {
				cout << "Do you want to open it? Y/N " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Chest");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Mysterious Potion") {
				cout << "Do you want to take it? " << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Mysterious Potion");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == " Level 3 Sword") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Sword");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 3 Armour") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 3 Armour");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}

			else if (item == "Level 2 Shield") {
				cout << "Do you want to take it ?.... Y/N" << endl;
				cin >> item_choice;
				if (item_choice == "y" || item_choice == "Y") {
					Adding_to_inventory("Level 2 Shield");
					movement();
				}
				else if (item_choice == "n" || item_choice == "N") {
					cout << "The item was not added to your inventory." << endl;
					Sleep(1000);
					movement();
				}
			}
		}

		else if (temp > 75 && temp <= 80) {  //The remaining 15% will be for nothing found.
			cout << "You found nothing of interest.";
			Sleep(1000);
			movement();
		}

		else if (temp > 80 && temp <= 100) {
			string npc_name = npcs[rand() % 5];
			cout << "You have met a " << npc_name << ".";
			Sleep(2000);

			system("cls");

			if (npc_name == "Peasent") {

				cout << "Hello traveller! How are you doing?" << endl;
				Sleep(3000);
				cout << "You should be careful.It's a strange world out there." << endl;
				Sleep(3000);
				cout << "Monsters creeping up everywhere.I just hope everything returns to normal." << endl;
				Sleep(3000);
				movement();
			}

			else if (npc_name == "Pub Owner") {
				cout << "Oi matey!" << endl;
				Sleep(4000);
				cout << "You look like somone who can use a drink.We have got the finest ale in the town." << endl;
				Sleep(4000);
				cout << "Whadaya say ? care for a drink ? " << endl;
				Sleep(4000);

				while (true) {

					char drink_choice;
					cout << "Y for Yes and N for No" << endl;

					cin >> drink_choice;

					if (drink_choice == 'Y' || drink_choice == 'y') {
						char d_choice;

						cout << "What do you want to have?" << endl;
						cout << "Press 1 for Scotch" << endl;
						cout << "Press 2 for Moonshine" << endl;
						cout << "Press 3 for Ale" << endl;
						cout << "Press 4 for Whiskey" << endl;


						cin >> d_choice;
						if (d_choice == '1') {
							cout << "You drank some Scotch and feel sleepy" << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '2') {
							cout << "You have indulged yourself in Moonshine. This is quite strong." << endl;
							Sleep(5000);
							player_health -= 5;
							movement();
						}

						else if (d_choice == '3') {
							cout << "You drank the town's most famous ale. You are now feeling that you might throw up." << endl;
							Sleep(5000);
							player_health -= 10;
							movement();
						}

						else if (d_choice == '4') {
							cout << "You drank some whiskey. This reminds you of home. Right now there is no time to think of home." << endl;
							Sleep(5000);
							player_health += 10;
							movement();
						}

						else if (d_choice == 'A' || d_choice == 'z') {
							cout << "Wrong Input, Try again.";
							break;
						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");


					}
					else if (drink_choice == 'N' || drink_choice == 'n') {
						cout << "Your loss mate." << endl;
						Sleep(4000);
						movement();
						break;

					}


				}

			}

			else if (npc_name == "Guard") {
				cout << "Hold Off You Filthy insect!" << endl;
				Sleep(3000);
				cout << "Don't you dare come near me!" << endl;
				Sleep(3000);
				cout << "You better get lost before I do something you might regert for the rest of your life" << endl;
				Sleep(4000);
				movement();
			}

			else if (npc_name == "Blacksmith") {
				cout << "Oi sonny boy!" << endl;
				Sleep(3000);
				cout << "Your sword looks like it needs some work." << endl;
				Sleep(3000);
				cout << "Mind if I have a look? ." << endl;
				Sleep(3000);
				cout << "Do you want to repair your sword?" << endl;
				char repair;
				cout << "Press Y for Yes or N for No." << endl;

				while (player_health > 1) {


					cin >> repair;

					if (repair == 'Y' || repair == 'y') {
						cout << "Your sword was repaired" << endl;
						damage_multiplier += 5;
						Sleep(4000);
						movement();

					}

					else if (repair == 'N' || repair == 'n') {
						cout << "Okay son, your choice. Do remember it is a scary world out there." << endl;
						Sleep(4000);
						movement();
					}

					else if (repair == 'A' || repair == 'z') {
						cout << "Wrong input! Try again." << endl;
						Sleep(1000);

					}

					cout << "Wrong Input. Try again." << endl;
					Sleep(1000);
					system("cls");

				}

			}

			else if (npc_name == "Shopkeeper") {
				cout << "Hello son. My God! You look like you haven't had a meal for deacades." << endl;
				Sleep(4000);
				cout << "Come here have a seat. What do you wanna have? " << endl;
				Sleep(4000);

				char shop_choice;
				cout << "Press Y to accept or N to refuse." << endl;
				while (true) {
					cin >> shop_choice;

					if (shop_choice == 'Y' || shop_choice == 'y') {
						cout << "Sit here son, tell me what do you wanna have." << endl;
						char food_choice;
						cout << "1 for Beef Jerky." << endl;
						cout << "2 for cup of water." << endl;
						cout << "3 for Chicken soup." << endl;
						cout << "4 for an apple." << endl;

						cin >> food_choice;


						if (food_choice == '1') {
							cout << "You ate some beef jerky. It tasted really amazing." << endl;
							Sleep(3000);
							cout << "You feel stronger and have gained some health." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}


						else if (food_choice == '2') {
							cout << "Your thorat feels parched. You asked the shopkeeper for some water." << endl;
							Sleep(3000);
							cout << "You drank some water and now feel refresehd." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '3') {
							cout << "Your stomach is growling. You can really use a good meal right now. You asked the shopkeeper for some chicken soup" << endl;
							Sleep(3000);
							cout << "You ate the soup and now feel satisfied. Your health has increased" << endl;
							player_health += 10;
							Sleep(3000);
							movement();
						}

						else if (food_choice == '4') {
							cout << "Ahhh an apple. Smart choice." << endl;
							Sleep(3000);
							cout << "You know what they say, an apple a day keeps the monsters away." << endl;
							Sleep(3000);
							cout << "You don't care and start eating your apple. It was very healthy." << endl;
							player_health += 5;
							Sleep(3000);
							movement();
						}

						else if (food_choice == 'A' || food_choice == 'z') {
							cout << "Wrong Input. Try again." << endl;
							break;

						}

						cout << "Wrong Input. Try again." << endl;
						Sleep(1000);
						system("cls");

					}

					else if (shop_choice == 'N' || shop_choice == 'n') {
						cout << "Your choice son. I was just being kind." << endl;
						Sleep(3000);
						movement();
					}

				}
				}

		} //This whole portion is for NPCS
	}

	else {
		movement(); //For error handling, we will call the function again.
	}

}

int main() {

	total_health = player_health;
	max_health = total_health;

	string greetings = "Greetings Player! ";

	for (int i = 0; i <= greetings.length(); i++) {
		cout << greetings[i];
		Sleep(50);
	}
	system("cls");

	string play_game = "Do you want to play the game ?\nPress Y for Yes and N for No. ";
	string start;

	for (int i = 0; i <= play_game.length(); i++) {
		cout << play_game[i];
		Sleep(50);
	}

start:

	cin >> start;

	if (start == "Y" || start == "y") {
		system("color 2");
		cout << "Great";


			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\tLOADING WORLD.";
			char x = 219;
			for (int i = 0; i < 40; i++) {
				Sleep(100);
				cout << x;
			}
			
		Sleep(1000);
		system("cls");

		cout << "Enter your character's name: ";

		cin >> player_name;

			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\tCREATING PLAYER.";
			char y = 219;
			for (int i = 0; i < 30; i++) {
				Sleep(100);
				cout << y;
			}

		system("cls");
		Sleep(1000);

		string opening_scene1 = "In the heart of the Shattered Plains, where the remnants of a once-majestic kingdom lie scattered, you find yourself standing alone.";

		for (int i = 0; i <opening_scene1.length(); i++) {
			cout << opening_scene1[i];
			Sleep(50);
		}
		Sleep(2000);
		system("cls");
		string opening_scene2 = "The air is thick with an ominous stillness, and the horizon is painted in hues of twilight.";
		for (int i = 0; i < opening_scene2.length(); i++) {
			cout << opening_scene2[i];
			Sleep(50);
		}
		Sleep(2000);
		system("cls");
		string opening_scene3 = " A gentle breeze carries the whispers of ancient spirits, and the ground beneath your feet resonates with the echoes of a forgotten era.";
		for (int i = 0; i < opening_scene3.length(); i++) {
			cout << opening_scene3[i];
			Sleep(50);
		}
		Sleep(2000);
		system("cls");
		string opening_scene4 = " As you begin to move, the landscape shifts around you, revealing a world teeming with untold mysteries and hidden dangers.";
		for (int i = 0; i < opening_scene4.length(); i++) {
			cout << opening_scene4[i] ;
			Sleep(50);

		}
		Sleep(2000);
		system("cls");
		string opening_scene5 = "Strange creatures, born from the fragments of the shattered realm, prowl the desolate plains. ";
		for (int i = 0; i < opening_scene5.length(); i++) {
			cout << opening_scene5[i];
			Sleep(50);
		}
		Sleep(2000);
		system("cls");
		string opening_scene6 = "Armed with nothing but your instincts, you set forth on a journey into the unknown.";
		for (int i = 0; i < opening_scene6.length(); i++) {
			cout << opening_scene6[i];
			Sleep(50);
		}
		
		Sleep(2000);
		system("cls");
		movement();
	}

	else if (start == "N" || start == "n") {
		cout << "Exiting......";
		Sleep(3000);
	}

	else {
		system("color 4");
		cout << "Wrong Input. Try again after 5 seconds." << endl;
		Sleep(5000);
		goto start;

	}

	return 0;
}