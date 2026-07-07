# 🎮 Minesweeper Game (C++)

A console-based implementation of the classic **Minesweeper** game developed in **C++** using the Standard Template Library (STL). The game supports multiple difficulty levels, safe first-click gameplay, recursive cell expansion using Depth First Search (DFS), and a colored terminal interface for an improved user experience.

---

## 📌 Features

- 🎯 Three difficulty levels:
  - Easy (9 × 9, 10 mines)
  - Medium (16 × 16, 40 mines)
  - Hard (16 × 30, 99 mines)
- 💣 Random mine placement using modern C++ `mt19937`
- ✅ Safe first reveal (the first revealed cell never contains a mine)
- 🔄 Automatic expansion of empty cells using **Recursive DFS (Flood Fill)**
- 🚩 Flag and unflag cells
- 🎨 Colored console output for better gameplay
- ✔️ Input validation and invalid move handling
- 🏆 Automatic win and game-over detection

---

## 🛠️ Technologies Used

- C++
- Standard Template Library (STL)
- VS Code
- Git & GitHub

---

## 🧠 Algorithms Used

### 1. Recursive Depth First Search (DFS)
Used to reveal all connected empty cells when the player opens a cell with no adjacent mines.

### 2. Random Mine Generation
Implemented using the C++ `<random>` library with the `mt19937` random number generator for better randomness.

### 3. Matrix Traversal
Used to calculate the number of neighbouring mines for every non-mine cell.

---

## 📂 Data Structures Used

- `vector<vector<char>>` – Stores the actual game board.
- `vector<vector<char>>` – Stores the board displayed to the player.
- `vector<vector<bool>>` – Tracks visited cells during DFS.
- Direction arrays (`dr[]` and `dc[]`) – Used for efficient traversal of all eight neighbouring cells.

---

## ▶️ How to Run

### Compile

```bash
g++ ss.cpp -o Minesweeper
```

### Run

#### Windows

```bash
Minesweeper.exe
```

#### Linux / macOS

```bash
./Minesweeper
```

---

## 📸 Gameplay

Choose a difficulty level:

```
1. Easy
2. Medium
3. Hard
```

Enter moves in the format:

```
row column command
```

Example:

```
3 4 R
```

- `R` → Reveal a cell
- `F` → Flag or unflag a cell

---

## 📈 Time Complexity

| Operation | Complexity |
|----------|------------|
| Mine Placement | O(R × C) |
| Reveal (Worst Case) | O(R × C) |
| Print Board | O(R × C) |
| Win Check | O(1) |

where **R** is the number of rows and **C** is the number of columns.

---

## 🚀 Future Enhancements

- ⏱️ Timer
- 🏆 High-score tracking
- 🎮 Custom board size
- 💾 Save and load game
- 🖥️ Graphical User Interface (GUI)

---

## 👩‍💻 Author

**Sai Shanmukhi Angara**

GitHub: https://github.com/saishanmukhiangara