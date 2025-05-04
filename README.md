# FdF

## 🌄 Overview

**FdF** (Fil de Fer) is a graphical 3D wireframe renderer written in C using the **MiniLibX** graphics library. The program reads a 2D map of elevation values and projects it in isometric 3D view, allowing users to visualize terrain-like models with simple graphics.

This project is a great introduction to computer graphics, coordinate transformation, and efficient rendering algorithms.

## 🔧 Features

- Parse a `.fdf` file representing a 3D map
- Draw a 3D wireframe using isometric projection
- Basic zoom, translation, and rotation controls (optional)
- Support for elevation-based color gradients (bonus)
- Simple and efficient line drawing using **Bresenham’s algorithm**
- Real-time display using MiniLibX

## 📁 Map File Format

A `.fdf` file is a text file containing rows of space-separated integers, each representing a point's Z (altitude) value.

Example:

0 0 0 0
0 1 2 0
0 0 0 0

Run :

bash
Copy
Edit
./fdf maps/42.fdf
