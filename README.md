# Barn_Boss_OPP_Project_2025_2026
# 🌾 Barn Boss

> Object-Oriented Programming course project  
> Sofia University "St. Kliment Ohridski", Faculty of Mathematics and Informatics  
> Software Engineering — 2025/2026

---

## 📖 Overview

**Barn Boss** is a console-based farm management simulation game built with object-oriented principles in C++. Multiple users share a common economic environment where they grow crops, raise animals, trade on a marketplace, and complete tasks to climb the leaderboard.

Each player starts with **100 Balance** and **0 Score**, managing their own farm and barn while competing globally.

---

## 🏗️ Class Architecture

```
User  (base class)
├── Player         – manages farm, trades, completes tasks
├── TaskManager    – manages the task board (only 1 per system)
└── MarketManager  – manages the marketplace (only 1 per system)

Farm
├── Cropland       – slots for growing plants
└── Farmland       – slots for raising animals

Barn               – storage for products and quantities
Market             – product catalog with prices and stock
TaskBoard          – list of active tasks with rewards
Scoreboard         – global player rankings
```

**OOP concepts used:** Inheritance, Polymorphism, Encapsulation, File I/O

---

## ✨ Features

### 👤 User Management
- Register with a unique username and role (`Player`, `MarketManager`, `TaskManager`)
- Login / Logout
- Change password
- View profile info

### 🌱 Farm
- Plant seeds (`sowPlant`)
- Add animals (`addAnimal`)
- Harvest produce (`harvest`)
- Expand cropland / farmland slots (`expandCropland`, `expandFarmland`)

### 🏚️ Barn
- Track all products and their quantities
- Automatically updated on purchases, harvests, and task completions

### 🛒 Market
| Action | Who |
|--------|-----|
| Browse catalog | Everyone |
| Buy / Sell products | Player |
| Change prices | MarketManager only |
| Restock products | MarketManager only |

### 📋 TaskBoard
| Action | Who |
|--------|-----|
| View tasks | Everyone |
| Complete tasks | Player |
| Add / Remove tasks | TaskManager only |

### 🏆 Scoreboard
Players are ranked by:
1. Highest **Score**
2. Tie → Higher **Balance**
3. Full tie → Lower **Id** (older account)

> TaskManager and MarketManager are excluded from rankings.

---

## 🌾 Plants & Animals

| Id | Item | Buy Price | Cycles Needed | Produces |
|----|------|-----------|---------------|----------|
| 1 | Wheat Seed | 10 | 3 | 1 × Wheat |
| 2 | Corn Seed | 15 | 4 | 1 × Corn |
| 3 | Chicken | 25 | 3 | 1 × Egg |
| 4 | Cow | 50 | 5 | 1 × Milk |

---

## ⏱️ Game Cycle

Time is measured in **cycles**. Every valid Player command advances that player's cycle count by 1 (cycles are per-player, independent).

**Commands that do NOT advance the cycle:**

`checkBalance` · `checkScore` · `checkBarn` · `checkFarm` · `profileInfo` · `openMarketCatalog` · `showTaskBoard` · `harvest`

> If a command fails due to invalid input or unmet conditions, the cycle does not advance.

---

## 🛒 Starting Market State

| Product | Quantity | Price |
|---------|----------|-------|
| Wheat Seed | 20 | 10 |
| Corn Seed | 20 | 15 |
| Chicken | 10 | 25 |
| Cow | 5 | 50 |
| Wheat | 20 | 15 |
| Corn | 20 | 20 |
| Egg | 15 | 30 |
| Milk | 10 | 60 |

---

## 📋 Starting Tasks

| Id | Requirement | Reward |
|----|-------------|--------|
| 1 | Deliver 5 Wheat | 50 Balance + 10 Score |
| 2 | Deliver 3 Milk | 120 Balance + 20 Score |

---

## 💾 Save & Load

- On `exit` — full game state is saved to a file automatically
- On startup — if a save file exists, it is loaded; otherwise a new world is created

---

## 🖥️ Example Session

```
========================================
            BARN BOSS
========================================
> register Ivan 1234 Player
User registered successfully!

> login Ivan 1234
Welcome, Ivan!

> buyItem 1 2
The purchase was successful!

> sowPlant 1
Plants planted successfully!

> harvest
Harvest completed!

> showScoreboard
=== SCOREBOARD ===
1. Ivan | Score: 0 | Balance: 80

> exit
Game saved successfully.
Goodbye!
```

---

## 📁 Project Structure

```
Barn_Boss/
├── src/
│   ├── User.h / User.cpp
│   ├── Player.h / Player.cpp
│   ├── TaskManager.h / TaskManager.cpp
│   ├── MarketManager.h / MarketManager.cpp
│   ├── Farm.h / Farm.cpp
│   ├── Barn.h / Barn.cpp
│   ├── Market.h / Market.cpp
│   ├── TaskBoard.h / TaskBoard.cpp
│   ├── Scoreboard.h / Scoreboard.cpp
│   └── main.cpp
├── data/
│   └── save.txt
└── README.md
```
