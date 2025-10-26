#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int MAX_DICE_VALUE = 6;
const int NUM_SHOP_ITEMS = 5;
const int NUM_BOSS_SKILLS = 3;

struct weapon {
    string name;
    string ability;
    int minRoll;
    string combatMessage;
    string type = "";
    int price;
};

struct bossSkills {
    string name;
    int minRoll;
    string messageSuccess;
    string messageFail;
    string type = "";
};

struct player {
    string name = "";
    int bananas;
    vector<weapon> inventory;
    int health = 20;
    
};

struct boss {
    string name;
    int health;
    vector<bossSkills> abilities;
};

struct room {
    string name;
    string intro;

    int row;
    int col;

    string enemy;

    // TRIVIA ROOM SPECIFIC
    vector<string> questions = {};
    vector<string> optionA = {};
    vector<string> optionB = {};
    vector<string> optionC = {};
    vector<char> correctAnswers = {};
    
    // SHOP ROOM SPECIIFC
    vector<weapon> itemsForSale = {};
    vector<weapon> shopItems = {};
    bool itemsGenerated = false;

    // INTERACTION ROOM SPECIFIC
    string question = "";
    char goodAnswerChar = '\0';
    string goodResponse = "";
    char badAnswerChar = '\0';
    string badResponse = "";  

    // COMBAT ROOM SPECIFIC
    string playerDeathMessage = "";
    string bossDeathMessage = "";
    
    string exit = "";
    bool cleared = false;
    string type;

};

vector<boss> makeBosses() {
    return {
        {
            .name = "BRIAN",
            .health = 25,
            .abilities = {
                {
                    "BAD DAD JOKE", 
                    3, 
                    "BRIAN weakens you with a bad dad joke. You are in pain and take 2x damage.", 
                    "BRIAN tries to tell a bad dad joke, but begins to stutter.",
                    "DAMAGE_MULTIPLIER"
                },
                {
                    "SUPER TRICKY CONCEPT", 
                    4, 
                    "BRIAN confuses you with a SUPER advanced topic. You are demoralized and take 2x damage.", 
                    "BRIAN tries to confuse you with a SUPER advanced concept, but you understand it.",
                    "DAMAGE_MULTIPLIER"
                },
                {
                    "FUN FACT", 
                    4, 
                    "BRIAN shares a fun fact. You are charmed and take 2x damage.", 
                    "BRIAN tries to share a fun fact, but you don't think it's very fun.",
                    "DAMAGE_MULTIPLIER"
                }
            }
        }
    };
}

vector<room> makeRooms() {
    return {
        {   
            .name = "ROOM 0",
            .intro = "You are back at the start.",
            .row = 0,
            .col = 0,
            .enemy = "GRU",
            .cleared = false,
            .type = "START"
        },

        {
            .name = "ROOM 1",
            .intro = "SCARLET OVERKILL: Ah, finally, a potential recruit! To steal the queen’s crown, "
                "I need wits, charm, and—most importantly—a little royal expertise. "
                "I'm assembling the perfect team and you might just make the cut-" 
                "if you're smart enough. To get close to the queen and steal her crown, you'll " 
                "need to know some basic information. I'll test you on three facts. Answer at " 
                "them correctly, and you're in. Fail, and you're out faster than you can say "
                "'long live the queen!'",
            .row = 0,
            .col = 1,
            .enemy = "SCARLET OVERKILL",

            .questions = {
                "What is the full name of Queen Elizabeth II?",
                "Which famous diamond is set into the front of the Imperial State Crown?",
                "What is Queen Elizabeth II's favorite breed of dog?"
            },
            .optionA = {
                "Elizabeth Alexandra Mary Windsor",
                "The Koh-i-Noor",
                "Corgi"
            },
            .optionB = {
                "Elizabeth Victoria Alexandra Windsor",
                "The Cullinan II",
                "Golden Retriever"
            },
            .optionC = {
                "Mary Elizabeth Victoria Windsor",
                "The Hope Diamond",
                "Dachshund"
            },
            .correctAnswers = {
                'a',
                'b',
                'a'
            },
            .exit = "Hm... I'm off to interview some more candidates.",
            .cleared = false,
            .type = "TRIVIA"
        
        },

        {
            .name = "ROOM 2",
            .intro = "Hm.. You seem interesting. How would you like to join my.. business...",
            .row = 0,
            .col = 2,
            .enemy = "MR. PERKINS",
            .question = "What is the most important thing in this world? Having [M]oney or [P]ower?",
            .goodAnswerChar = 'm',
            .goodResponse = "I knew you were bright. You can buy anything with money. Including power.",
            .badAnswerChar = 'p',
            .badResponse = "Tsk. You naive soul. Money buys happiness!",
            .exit = "I'm off to oversee my... investments. Go on now.",
            .cleared = false,
            .type = "INTERACTION"
        },

        {
            .name = "ROOM 3",
            .intro = "BALTHAZAR BRATT: Ugh, another wannabe trying to dethrone the king of the 80s! " 
            "You're about to face the raddest music trivia challenge of your pathetic life. Don't "
            "you know? I'm the star of the hottest TV show, “Evil Bratt!” Here's the deal, loser: "
            "I'll play you some lyrics from the best 80s hits, and you'll have to guess the correct "
            "song. Get them right, and maybe, just maybe, I'll consider you a worthy rival. But get "
            "it wrong? I'll moonwalk all over your sorry dreams like the network did to my show! ",
            .row = 1,
            .col = 0,
            .enemy = "BALTHAZAR BRATT",

            .questions = {
                "Which lyric is from the song 'Take On Me' by A-ha?",
                "Which lyric is from the song 'Into the Groove' by Madonna?",
                "Which lyric is from the song 'Bad' by Michael Jackson?"
            },
            .optionA = {
                "\"I’m telling you, take me on, I’ll make it out of here.\"",
                "\"Get into the groove, Boy, you've got to prove, Your love to me, yeah\"",
                "\"You know I’m bad, I’m bad, you know it\""
            },
            .optionB = {
                "\"I’ll be your hero, take on me, and I’ll never look back.\"",
                "\"You got me into the groove, you got me going crazy all night long.\"",
                "\"I’m dangerous, I’m bad, but you know you want me still.\""
            },
            .optionC = {
                "\"Take me on, I'll be gone, in a day or two.\"",
                "\"You can feel the rhythm, dance to the groove, let it show.\"",
                "\"Bad to the bone, I’m the king of the street.\""
            },
            .correctAnswers = {
                'c',
                'a',
                'a'
            },
            .exit = "Man, I got a totally rad idea for a new show. The next time you see me, I'll be on your TV screen!",
            .cleared = false,
            .type = "TRIVIA"
        
        },

        {
            .name = "ROOM 4",
            .intro = "Take a look at the gadgets I've been working on...",
            .row = 1,
            .col = 1,
            .enemy = "DR. NEFARIO",
            .itemsForSale = {
                {
                    "Fart Gun",
                    "Enemy is disgusted and cannot attack during their next move. Must roll 3+ to use.",
                    3,
                    " is overwhelmed by the foul stench! They cannot attack for 1 move.",
                    "STOP_ATTACK",
                    10
                },
                {
                    "Lipstick Tazer",
                    "Enemy is stunned and cannot attack during their next move. Must roll 3+ to use.",
                    3,
                    " is stunned! They cannot attack for 1 move.",
                    "STOP_ATTACK",
                    10
                },
                {
                    "Hypno-Hat",
                    "Enemy is hypnotized and cannot defend your attack. Must roll 3+ to use.",
                    3,
                    " is hypnotized and begins dancing around naked! They cannot defend your attack.",
                    "STOP_DEFENSE",
                    10

                },
                {
                    "Sonic Keytar",
                    "Enemy is deafened and cannot defend your next attack. Must roll 2+ to use.",
                    2,
                    " is deafened by the loud tunes. They cannot defend your attack.",
                    "STOP_DEFENSE",
                    15
                },
                {
                    "Freeze Ray",
                    "Enemy is frozen and cannot defend nor attack for 1 round. Must roll 4+ to use.",
                    4,
                    " is frozen! They cannot defend nor attack for 1 round.",
                    "BOTH_EFFECTS",
                    25
                }
            },
        
            .cleared = false,
            .type = "SHOP"
        
        },

        {
            .name = "ROOM 5",
            .intro = "Alright, listen up, amigo! I'll only accept you as one of my own if you answer me correctly.",
            .row = 1,
            .col = 2,
            .enemy = "EL MACHO",
            .question = "[S]alsa or [G]uacamole?",
            .goodAnswerChar = 's',
            .goodResponse = "I knew you had good taste!",
            .badAnswerChar = 'g',
            .badResponse = "Eugh, I knew you were soft...",
            .cleared = false,
            .type = "INTERACTION"
        
        },

        {
            .name = "ROOM 6",
            .intro = "BELLO!! BANANA???? ",
            .row = 2,
            .col = 0,
            .enemy = "KEVIN",
            .question = "([Y]es or [N]0)",
            .goodAnswerChar = 'y',
            .goodResponse = "WAHOO!",
            .badAnswerChar = 'n',
            .badResponse = "BLEUGH...",
            .exit = "Poopaye!",
            .cleared = false,
            .type = "INTERACTION"
        
        },

        {
            .name = "ROOM 7",
            .intro = "HAHAHAHHAHAA! I've been expecting you, Gru! Oh.. never mind it's one of you losers.",
            .row = 2,
            .col = 1,
            .enemy = "VECTOR",
            .question = "Say, who is the evillest villain you know... [V]ector or [G]ru?",
            .goodAnswerChar = 'v',
            .goodResponse = "Heh, that's right! You're smart for recognizing true evil greatness.",
            .badAnswerChar = 'g',
            .badResponse = "What?! Pathetic.",
            .exit = "Smell you later, loser",
            .cleared = false,
            .type = "INTERACTION"
        
        },

        {
            .name = "ROOM 8",
            .intro = "Hehheheheh.. I've been expecting you. You think you can not show up to lecture without any"
                "consequences? Unfortunately, you're buddy Bob had to pay the price... it'd be a shame if I ripped"
                "the head off of his adorable little teddy bear...",
            .row = 2,
            .col = 2,
            .enemy = "BRIAN",
            .playerDeathMessage = "Heh, better luck next semester...",
            .bossDeathMessage = "I-I'm proud of you.... (dies)",
            .cleared = false,
            .type = "COMBAT"
        
        }
    };
}

void displayWeapons(player &p) {
    cout << "Inventory: " << endl;

    if (p.inventory.empty()) {
        cout << "You have no items in your inventory." << endl;
        cout << "Bananas: " << p.bananas << endl;
    }

    else {
        for (unsigned int i = 0; i < p.inventory.size(); i++) {
            cout << i + 1 << ". " << p.inventory.at(i).name << " - " << p.inventory.at(i).ability << endl;
        }
        cout << "Bananas: " << p.bananas << endl;
    }
}

int rollDice() {
    int diceNum = rand() % MAX_DICE_VALUE + 1;
    return diceNum;
}

void printDirections(int row, int col) {
    cout << "Available directions: ";
    if (row > 0) cout << "[U]p ";
    if (row < 2) cout << "[D]own ";
    if (col > 0) cout << "[L]eft ";
    if (col < 2) cout << "[R]ight ";
    cout << endl;
}

int calculateBananas(int wins) {
    int bananas = 0;
    if (wins == 0) {
        bananas = 0;
    }
    else if (wins == 1) {
        bananas = 5;
    }
    else if (wins == 2) {
        bananas = 10;
    }
    else if (wins == 3) {
        bananas = 20;
    }

    return bananas;
}

int moveToNextRoom(int &row, int &col, player &p) {
    while (true) {
        printDirections(row, col);
        char move;
        cout << "Which direction would you like to move? Or would you like to view your [I]nventory?: ";
        cin >> move;
        cout << endl;
        
        if ((move == 'u' || move == 'U') && row > 0) {
            row--; // Move up
        } 
        else if ((move == 'd' || move == 'D') && row < 2) {
            row++; // Move down
        } 
        else if ((move == 'l' || move == 'L') && col > 0) {
            col--; // Move left
        } 
        else if ((move == 'r' || move == 'R') && col < 2) {
            col++; // Move right
        } 
        else if (move == 'i' || move == 'I') {
            displayWeapons(p);
            cout << endl;
            continue;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        break;
    }
    

    int nextRoomNum = row * 3 + col; 
    return nextRoomNum;  
}

string startGame(player &p) {
    cout << "HELP! BRIAN has united with every notorious villain from the Minions universe \n" 
        << "to snatch Bob's beloved teddy bear! \n"
        << "Gru is counting on you to infiltrate BRIAN'S Shadow Fortress Unit, collecting \n" 
        << "bananas and unlocking weapons along the way to fight the final boss at the end!" << endl;

    string name;
    cout << "Enter your name to begin...";
    cin >> name;

    p.name = name;

    cout << "Gru: " << name << ", all the Minions are counting on you. Don't let us down." << endl;
    return name;
}

int askTriviaQuestions (const room &r) {
    int correct = 0;
    for (unsigned int i = 0; i < r.questions.size(); i++) {
        cout << r.questions.at(i) << endl;
        cout << "a) " << r.optionA.at(i) << endl;
        cout << "b) " << r.optionB.at(i) << endl;
        cout << "c) " << r.optionC.at(i) << endl;

        char userAnswer;
        while (true) {
            cout << "What is the answer? (a/b/c): ";
            cin >> userAnswer;

            if (userAnswer != 'a' && userAnswer != 'A' && userAnswer != 'b' && userAnswer != 'B' && userAnswer != 'c' && userAnswer != 'C') {
                cout << "Not so bright are you... that's not a valid answer!" << endl;
                continue;
            }

            break;
        }

        userAnswer = tolower(userAnswer); //change answer to lowercase
        char correctAnswer = r.correctAnswers.at(i);

        if (userAnswer == correctAnswer) {
            cout << "Correct!" << endl;
            correct++;
        }

        else {
            cout << "Wrong! The correct answer was: " << correctAnswer << endl;
        }

        cout << "You have answered " << correct << " question(s) correctly." << endl;
        cout << endl;

    }
    return correct;
}   

void runTriviaRoom (room &r, player &p) {
    cout << "---" << endl;
    cout << endl;

    if (r.cleared == true) {
        cout << "The room is empty now." << endl;
        return;
    } 

    else {
        cout << r.intro << endl;
        cout << endl;

        while (true) {
            char userReady;
            cout << r.enemy << ": Are you ready to play? [Y]es or [N]o: ";
            cin >> userReady;

            if (userReady == 'y' || userReady == 'Y') {
                cout << r.enemy << ": You're a brave one, let's begin." << endl;
                break;
            }

            else if (userReady == 'N' || userReady == 'n') {
                cout << r.enemy << ": Well, hurry up then!" << endl;
                continue;
            }

            else {
                cout << "That's not a valid answer!" << endl;
                continue;
            }
            break;     
        }
        cout << endl;
        int correctAnswers = askTriviaQuestions(r);

        int bananasWon = calculateBananas(correctAnswers);
        p.bananas += bananasWon;

        if (correctAnswers == 0) {
            cout << r.enemy << ": Oh... you suck... " << bananasWon << " bananas for you..." << endl;
        }

        else if (correctAnswers == 1) {
            cout << r.enemy << ": Not the best performance..." << bananasWon << " bananas for you..." << endl;
        }

        else if (correctAnswers == 2) {
            cout << r.enemy << ": Not too shabby..." << bananasWon << " bananas for you..." << endl;
        }

        else if (correctAnswers == 3) {
            cout << r.enemy << ": WOW! Amazing job!!!" << bananasWon << " bananas for you..." << endl;
        }
        
        cout << "You now have " << p.bananas << " bananas!" << endl;
        cout << r.exit << endl;
        cout << endl;

        r.cleared = true;
    }
    
}

void startingRoom (room &r) {
    cout << r.intro << endl;
}

void runInteractionRoom (room &r, player &p) {
    cout << "---" << endl;
    cout << endl;

    if (r.cleared) {
        cout << "The room is empty..." << endl;

    }
    else {
        cout << r.enemy << ": " << r.intro << endl;
        cout << r.enemy << ": " << r.question << endl;
        
        while (true) {
            char choice;
            cin >> choice;
            choice = tolower(choice);

            if (choice == r.goodAnswerChar) {
                cout << r.enemy << ": " << r.goodResponse << endl;
                cout << "For you, 5 bananas!" << endl;
                p.bananas += 5;
                r.cleared = true;
                cout << "You now have " << p.bananas << " bananas." << endl;
                break;
                
            }

            else if (choice == r.badAnswerChar) {
                cout << r.enemy << ": " << r.badResponse << endl;
                cout << "No bananas for you!" << endl;
                r.cleared = true;
                break;
            }
            else {
                cout << r.enemy << "That's not a valid response!" << endl;
                continue;
            }
        }
    } 
}

void randomizeShopItems(room &r) {
    if (r.itemsGenerated == false) {
        int firstRandItemNum = 0;
        firstRandItemNum = rand() % NUM_SHOP_ITEMS;
        weapon firstItem = r.itemsForSale.at(firstRandItemNum);
        r.shopItems.push_back(firstItem);

        int secondRandItemNum = 0;
        while (true) {
            secondRandItemNum = rand() % NUM_SHOP_ITEMS;
            if (secondRandItemNum == firstRandItemNum) {
                continue;
            }
            break;
        }
        weapon secondItem = r.itemsForSale.at(secondRandItemNum);
        r.shopItems.push_back(secondItem);

        int thirdRandItemNum = 0;
        while (true) {
            thirdRandItemNum = rand() % NUM_SHOP_ITEMS;
            if (thirdRandItemNum == firstRandItemNum || thirdRandItemNum == secondRandItemNum) {
                continue;
            }
            break;
        }
        weapon thirdItem = r.itemsForSale.at(thirdRandItemNum);
        r.shopItems.push_back(thirdItem);

        r.itemsGenerated = true;
    }

    else {
        return;
    }
}

int randBossSkill () {
    int diceNum = rand() % NUM_BOSS_SKILLS;
    return diceNum;
}

void runShopRoom (room &r, player &p) {
    cout << "---" << endl;
    cout << r.enemy << ": " << r.intro << endl;
    cout << "You have " << p.bananas << " bananas." << endl;
    cout << endl;
    randomizeShopItems(r);

    while (true) {    
        if (r.shopItems.empty()) {
            cout << r.enemy << ": Looks like you've bought everything! My shop is empty now. Come back later!" << endl;
            break;
        }
        else {
            cout << "Items available: " << endl;
            for (unsigned int i = 0; i < r.shopItems.size(); i++) {
                cout << i + 1 << ". " << r.shopItems.at(i).name << " (" << r.shopItems.at(i).price << "): " 
                << r.shopItems.at(i).ability << endl;
            }
            cout << endl;
            char buy;
            cout << r.enemy << ": What would you like to purchase? Enter an item number or [E]xit: ";
            cin >> buy;

            if (buy == 'e' || buy == 'E') {
                cout << r.enemy << ": Maybe next time..." << endl;
                break;
            }

            int itemIndex = buy - '1';
            int shopSize = r.shopItems.size();
            if (itemIndex >= 0 && itemIndex < shopSize) {   
                const weapon &selectedItem = r.shopItems.at(itemIndex);

                if (p.bananas >= selectedItem.price) {
                    p.bananas -= selectedItem.price;
                    p.inventory.push_back(selectedItem); // Add to player's inventory
                    cout << endl;
                    cout << "You purchased " << selectedItem.name << "! Remaining bananas: " << p.bananas << endl;
                    cout << endl;
                    r.shopItems.erase((r.shopItems.begin() + itemIndex));

                    if (p.bananas == 0) {
                        cout << r.enemy << ": You're out of bananas! Come back when you get more..." << endl;
                        break;
                    }
                    
                    char buyMore;
                    cout << r.enemy << ": Would you like to buy another item? [Y]es or press any key to exit: ";
                    cin >> buyMore;

                    if (buyMore == 'y' || buyMore == 'Y') {
                        continue;
                    }

                    else {
                        break;
                    }

                } else {
                    cout << endl;
                    cout << r.enemy << ": You don't have enough bananas for the " << selectedItem.name << "." << endl;
                    cout << endl;
                    continue;
                }
                break;
            }

            else {
                cout << endl;
                cout << r.enemy << ": What? That's not an answer! Hurry it up I've got to get back to work." << endl;
                cout << endl;
            }
        }    
    }
}

string findRoomType (room &r) {
    string roomType;
    
    if (r.type == "INTERACTION"){
        roomType = "INTERACTION";
    }
    else if (r.type == "TRIVIA") {
        roomType = "TRIVIA";
    }
    else if (r.type == "SHOP") {
        roomType = "SHOP";
    }
    else if (r.type == "COMBAT") {
        roomType = "COMBAT";
    }
    else { 
        roomType = "START";
    }
    return roomType;
}

void runBossRoom (room &r, player &p, boss &b) {
    cout << "---" << endl;
    cout << endl;
    cout << b.name << ": " << r.intro << endl;
    

    while (p.health > 0 && b.health > 0) {
        bool bossCanAttack = true; 
        bool bossCanDefend = true;
        bool bossDamageMultiplier = false;
        cout << endl;
        displayWeapons(p);
        int chooseWeapon = 0;
        cout << "Select a weapon by number: ";
        cin >> chooseWeapon;
        int inventorySize = p.inventory.size();

        if (chooseWeapon >= 1 && chooseWeapon <= inventorySize) {
            weapon selectedWeapon = p.inventory[chooseWeapon - 1];
            cout << "You have selected: " << selectedWeapon.name << endl;
            cout << "Rolling dice..." << endl;
            int useWeapon = rollDice();
            cout << "You rolled a " << useWeapon << "!" << endl;

            if (useWeapon >= selectedWeapon.minRoll) {
                if (selectedWeapon.type == "STOP_ATTACK") {
                    cout << b.name << selectedWeapon.combatMessage << endl;
                    bossCanAttack = false;
                }

                if (selectedWeapon.type == "STOP_DEFENSE") {
                    cout << b.name << selectedWeapon.combatMessage << endl;
                    bossCanDefend = false;
                }

                if (selectedWeapon.type == "BOTH_EFFECTS") {
                    cout << b.name << selectedWeapon.combatMessage << endl;
                    bossCanDefend = false;
                    bossCanAttack = false;
                }
            }

            else {
                cout << "Uh oh.... you rolled a " << useWeapon << "... epic FAIL. It does nothing." << endl;
            }  
        }

        cout << "You prepare to launch an attack on " << b.name << "!" << endl;
        cout << "Rolling dice..." << endl;
        int numDamage = rollDice(); 
        cout << "You rolled a " << numDamage << "!" << endl;

        int tryDefend = rollDice();

        // BOSS TRY DEFEND

        if (bossCanDefend) {
            cout << b.name << " tries to defend your attack..." << endl;
            cout << "Rolling dice..." << endl;
            cout << b.name << " rolled an " << tryDefend << "!" << endl;
        }

        else {
            cout << "Since you used " << p.inventory[chooseWeapon - 1].name << ", " << b.name << " can't defend the attack!" << endl;
            tryDefend = 0;
        }
        
        if (numDamage > tryDefend) {
            cout << "You sucessfully land your attack!" << endl;
            cout << b.name << " takes " << numDamage << " damage!" << endl; 
        }

        else if (numDamage == tryDefend) {
            cout << b.name << " manages to redirect your attack!" << endl;
            numDamage /= 2;
            cout << b.name << " takes " << numDamage << " damage!" << endl; 
        }

        else {
            cout << "You miss your attack!" << endl;
            numDamage = 0;
        }
        b.health -= numDamage;
        cout << b.name << " now has " << b.health << "HP." << endl;
        

        if (b.health <= 0) {
            cout << b.name << ": " << r.bossDeathMessage << endl;
            cout << "VICTORY!" << endl;
            break;
        }

        cout << endl;

        if (bossCanAttack) {
            cout << b.name << ": It's my turn now...." << endl;
            int bossSkillIndex = randBossSkill();
            bossSkills selectedSkill = b.abilities.at(bossSkillIndex);

            cout << b.name << " tries to use " << selectedSkill.name << endl;

            int trySkill = rollDice();

            if (trySkill >= selectedSkill.minRoll) {
                if (selectedSkill.type == "DAMAGE_MULTIPLIER") {
                    cout << selectedSkill.messageSuccess << endl;
                    bossDamageMultiplier = true;
                }           
            }

            else {
                cout << selectedSkill.messageFail << endl;
            }  

            cout << b.name << ": Now for my attack!!!"  << endl;
            cout << "Rolling dice..." << endl;
            numDamage = rollDice(); 
            cout << b.name << " rolled a " << numDamage << "!" << endl;
            cout << "You try to defend " << b.name << "\'s attack." << endl;

            tryDefend = rollDice();
            cout << "You roll a " << tryDefend << "!" << endl;
            
            if (numDamage > tryDefend) {
                cout << b.name << " successfully lands his attack!" << endl;
                if (bossDamageMultiplier) {
                    cout << "Since " << b.name << " succesfully used " << selectedSkill.name << ", you take an extra 1 damage!" << endl;
                    numDamage += 1;
                }
                cout << "You take " << numDamage << " damage!" << endl; 
            }

            else if (numDamage == tryDefend) {
                cout << "You manage to redirect " << b.name << "\'S your attack!" << endl;
                numDamage /= 2;
                if (bossDamageMultiplier) {
                    cout << "Since " << b.name << " succesfully used " << selectedSkill.name << ", you take an extra 1 damage!" << endl;
                    numDamage += 1;
                }
                cout << "You take " << numDamage << " damage!" << endl; 
            }

            else {
                cout << b.name << " misses his attack!" << endl;
                numDamage = 0;
            }

            p.health -= numDamage;
            cout << "You now have " << p.health << "HP." << endl;
            
        }

        else {
            cout << "Since you successfully used " << p.inventory[chooseWeapon - 1].name << ", " << b.name << " cannot attack!" << endl;
            cout << b.name << ": GRRRR.... Just you wait!" << endl;
        }
        if (p.health <= 0) {
                cout << b.name << ": " << r.playerDeathMessage << endl;
                cout << "YOU LOSE." << endl;
                break;
        }
    } 
}

int main () {
    srand(time(nullptr));
    player player;
    string name = startGame(player);
    vector<room> rooms = makeRooms(); 
    vector<boss> bosses = makeBosses();
    boss finalBoss = bosses.at(0);

    int row = 0;
    int col = 0;

    while(true) {

        int previousRow = row;
        int previousCol = col;

        int nextRoom = moveToNextRoom(row, col, player); 
        room &currentRoom  = rooms.at(nextRoom);
        string roomType = findRoomType(currentRoom);
        if (roomType == "TRIVIA") {
            runTriviaRoom(currentRoom, player);
        }

        else if (roomType == "INTERACTION") {
            runInteractionRoom(currentRoom,  player);
        }   

        else if (roomType == "COMBAT") {
            char enter;
            cout << "You sense an ominous presence coming from this door. Do you wish to proceed? Enter [Y]es to enter or any key to exit: ";
            cin >> enter;

            if (enter == 'y' || enter == 'Y') {
                if (player.inventory.size() < 1) {
                    cout << "You must have at least one item in your inventory." << endl;
                    row = previousRow;
                    col = previousCol;
                    continue;
                }
                else {
                    runBossRoom(currentRoom, player, finalBoss);
                }
            } 
            else {
                cout << "You decide maybe it is best to turn back..." << endl;
                row = previousRow;
                col = previousCol;
                continue;  
            } 
        }

        else if (roomType == "SHOP") {
            runShopRoom(currentRoom, player);
        }

        else {
            startingRoom(currentRoom);
        }
    }
    
}

