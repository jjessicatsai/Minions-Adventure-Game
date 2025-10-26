# Minions-Adventure-Game

## Overview
A text-based roguelike adventure game set in the Minions universe. BRIAN has united with every notorious villain from the Minions franchise to steal Bob's beloved teddy bear, and Gru is counting on YOU to infiltrate the fortress, collect bananas, acquire weapons, and defeat BRIAN in an epic final battle!

## Features

- Grid-based exploration with 9 unique rooms
- Trivia challenges, character interactions, and strategic choices
- Banana currency system to purchase weapons
- Dice-based combat with special abilities
- Boss battle against BRIAN with 5 unique gadget weapons

## How to Play

### Controls
- **[U/D/L/R]**: Navigate up/down/left/right through rooms
- **[I]**: View inventory and banana count

### Room Types

**Trivia Rooms**: Answer 3 questions to earn bananas (0-20 bananas based on performance)

**Interaction Rooms**: Make dialogue choices for bonus bananas (5 bananas for correct choice)

**Shop Room**: Purchase weapons from Dr. Nefario using bananas
- Fart Gun / Lipstick Tazer / Hypno-Hat (10 bananas each)
- Sonic Keytar (15 bananas)
- Freeze Ray (25 bananas)

**Boss Room**: Face BRIAN in turn-based dice combat (requires at least 1 weapon)

### Combat System

Each turn:
1. Select and roll to activate a weapon ability
2. Roll to attack (1-6 damage)
3. Opponent rolls to defend
4. BRIAN uses special abilities and counter-attacks

Win by reducing BRIAN's health from 25 to 0 before yours drops from 20 to 0.

## Strategy Tips

- Complete trivia and interaction rooms before shopping
- Save high-cost weapons like the Freeze Ray for the boss
- You need weapons to fight BRIAN, so don't skip the shop!

## Installation

```bash
g++ -std=c++11 minions_game.cpp -o minions_game
./minions_game
```

Requires C++11 or higher.

## Credits

Inspired by Illumination's Minions franchise

---

*"Bello! Banana!"* 🍌
