#!/bin/bash

# Script to compile and run a C++ program with g++
echo "Compiling C++ program with g++"

# Source file name (change this to your C++ source file)
source_file="./main.cpp"

# Output binary name (change this to your desired output name)
output_binary="main"

# Output folder (change this to your desired output folder)
output_folder="./output/"

# Create the output folder if it doesn't exist
if [ ! -d "$output_folder" ]; then
  echo "Creating output folder $output_folder..."
  mkdir "$output_folder"
fi

# Compile the C++ program
g++ -std=c++11 -Wall -Werror "$source_file" -o "$output_folder$output_binary"

# Check if compilation was successful
if [ $? -eq 0 ]; then
  # Run the compiled binary
  echo "Compilation successful. Running $output_folder$output_binary ..."
  "$output_folder$output_binary"
else
  echo "Compilation failed."
fi

# Pause to keep the terminal open (optional)
read -p "Press Enter to exit..."
