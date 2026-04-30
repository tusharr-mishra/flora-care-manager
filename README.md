<div align="center">

<img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/OOP-Concepts-6DB33F?style=for-the-badge" />
<img src="https://img.shields.io/badge/File_I%2FO-Persistence-8B4513?style=for-the-badge" />
<img src="https://img.shields.io/badge/Dynamic_Memory-Management-2E8B57?style=for-the-badge" />
<img src="https://img.shields.io/badge/Platform-Console-grey?style=for-the-badge&logo=windows-terminal&logoColor=white" />

<br/><br/>

# 🌿 Flora Care Manager

### A smart console application for managing and tracking your plant collection — built in C++ with full OOP architecture.

*Object-Oriented Programming using C++ | Mini Project*

</div>

---

## Overview

**Flora Care Manager** is a console-based plant care tracking system written in C++. It allows users to register different types of plants, log watering schedules, view plant details, and persist all data across sessions using file I/O. 

The project was built to apply core Object-Oriented Programming principles — including **inheritance**, **polymorphism**, **encapsulation**, and **dynamic memory management** — to a real-world inspired problem.

---

## Features

| Feature | Description |
|--------|-------------|
|  **Multi-type Plant Registry** | Add Succulents, Flowers, Cacti, and Water Plants with type-specific attributes |
|  **Watering Schedule Tracker** | Log and update the last watered date for any plant |
|  **View All Plants** | Display full details of every registered plant |
|  **Persistent Storage** | All data is saved to and loaded from `plants.txt` automatically |
|  **Clean Memory Management** | All dynamically allocated objects are freed on exit — zero memory leaks |

---

##  Architecture & OOP Concepts Used

```
plant  (Base Class)
│
├── succulent    → extra: soiltype
├── flower       → extra: color
├── cactus       → extra: spines (bool)
└── waterplant   → extra: humidityreq, leafsize
```

### Key C++ Concepts Demonstrated

- **Inheritance** — All plant types extend a common `plant` base class, reusing shared attributes (`name`, `species`, `sunlightreq`, `waterfreq`, `lastwatdate`) while adding their own.
- **Polymorphism** — Virtual functions (`plantdet()`, `saveToFile()`, `updatewatersched()`) allow each derived class to define its own display and save behavior.
- **Virtual Destructor** — The base class uses a `virtual ~plant()` to ensure proper cleanup through base pointers.
- **Encapsulation** — All plant data is `protected`; accessed through public getter methods.
- **Dynamic Memory Allocation** — Plants are stored as `plant* plants[100]` and allocated with `new`, freed with `delete` on exit.
- **File I/O** — `ofstream` / `ifstream` used for serializing and deserializing plant data across sessions.

---

## Getting Started

### Prerequisites

- A C++ compiler: `g++` (GCC), `clang++`, or MSVC
- Terminal / Command Prompt

### Build & Run

```bash
# Clone the repository
git clone https://github.com/your-username/flora-care-manager.git
cd flora-care-manager

# Compile
g++ -o flora project_code.cpp

# Run
./flora         # Linux / macOS
flora.exe       # Windows
```

---

## Usage

On launch, the program loads existing plant data from `plants.txt` (if available) and presents the main menu:

```
========================================
   FLORA CARE MANAGER - MAIN MENU
========================================
1. Add new plant
2. View all plants
3. Water a plant
4. Exit
========================================
```

**Adding a Plant** — Choose a plant type, then enter details interactively. Type-specific fields (soil type, color, spines, humidity) are prompted accordingly.

**Viewing Plants** — Lists all registered plants with their complete details and type-specific attributes.

**Watering a Plant** — Select a plant by number and log the current watering date.

**Exit** — All data is saved automatically to `plants.txt` before the program closes.

---

## Project Structure

```
flora-care-manager/
│
├── project_code.cpp     # Full source code
├── plants.txt           # Auto-generated data persistence file
└── README.md
```

---

## Plant Types & Their Attributes

| Plant Type | Unique Attribute |
|------------|-----------------|
| `Succulent` | Soil Type (Sandy / Loamy / Clay) |
| `Flower` | Color |
| `Cactus` | Has Spines (Yes / No) |
| `Water Plant` | Humidity Requirement (%), Leaf Size |

---

## Potential Extensions

- [ ] Search / filter plants by type or name
- [ ] Watering due-date alerts (based on `waterfreq` + `lastwatdate`)
- [ ] Sort plants by next watering schedule
- [ ] Export data to CSV
- [ ] GUI frontend (Qt or web-based)

---

## Team

| Name | 
|------|
| Hridyansh Thakran | 
| Kushal Singh |
| Tushar Mishra |

---

## License

This project is open for academic and personal use.

---

<div align="center">
<i>Built with 🌿 and C++ — because even plants deserve good software.</i>
</div>
