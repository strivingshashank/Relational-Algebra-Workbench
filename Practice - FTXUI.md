# FTXUI Practice To-Do List

## 1. Setup & Basics
**Objective:** Understand how to render text and use basic elements.

- [ ] Install FTXUI and set up a minimal `ScreenInteractive + Renderer` program.
- [ ] Display a simple text: `"Hello, FTXUI!"`.
- [ ] Experiment with `bold`, `underline`, and colors.

**Practice Exercises:**
- [ ] Display your name in **bold green text**.
- [ ] Display three strings stacked vertically.
- [ ] Wrap a text in a **window** with a border.

---

## 2. Layouts
**Objective:** Learn to arrange elements with `vbox` and `hbox`.

- [ ] Create a vertical stack of 3 colored texts using `vbox`.
- [ ] Create a horizontal row of 3 texts using `hbox`.
- [ ] Combine `vbox` inside `hbox` (nested layouts).

**Practice Exercises:**
- [ ] Create a 2x2 grid of strings using nested `hbox` + `vbox`.
- [ ] Add `separator()` between elements.
- [ ] Create a header + content layout in a window.

---

## 3. Renderer
**Objective:** Understand the `Renderer` component and draw function.

- [ ] Write a `drawFunction()` returning a single `Element`.
- [ ] Wrap it with `Renderer(drawFunction)`.
- [ ] Loop it with `ScreenInteractive::Loop()`.

**Practice Exercises:**
- [ ] Display multiple `Elements` from a vector.
- [ ] Toggle color of text based on a boolean variable.
- [ ] Try a `Renderer` function with `bool focused` parameter.

---

## 4. Dynamic Content
**Objective:** Practice updating content on each frame.

- [ ] Use vectors or arrays to generate multiple rows.
- [ ] Change the vector data **outside** the draw function.
- [ ] Observe changes automatically reflected in the next frame.

**Practice Exercises:**
- [ ] Create a counter that increases every frame.
- [ ] Add a “process list” that grows dynamically.
- [ ] Change color of elements based on conditions.

---

## 5. Interactive Components
**Objective:** Learn buttons, input fields, and focus handling.

- [ ] Add a button component and capture clicks.
- [ ] Add an input field for text entry.
- [ ] Experiment with focus (use arrow keys to switch).

**Practice Exercises:**
- [ ] Create two buttons side by side; switch focus using left/right arrows.
- [ ] Input text and display it live above the field.
- [ ] Make a simple menu with 3 selectable options.

---

## 6. Windows, Borders, and Styling
**Objective:** Make UI visually structured and appealing.

- [ ] Wrap content in `window(title, content)`.
- [ ] Apply borders and colors to the window.
- [ ] Add separators and spacing between elements.

**Practice Exercises:**
- [ ] Create a dashboard with 3 windows (header, body, footer).
- [ ] Color-code rows based on status.
- [ ] Combine multiple windows horizontally using `hbox`.

---

## 7. Mini Projects / Challenges
**Objective:** Apply all concepts learned so far.

**Practice Ideas:**
- [ ] **Dynamic Table** – Display a 3-column table with headers, rows, and colored statuses.
- [ ] **Counter Dashboard** – Show multiple counters updating in real-time.
- [ ] **Mini To-Do App** – Add items using input and display them in a list with checkboxes.
- [ ] **Process Simulator** – Display a process list with PID, Name, and Status (static data first, then dynamic updates).
