#!/usr/bin/env python3
"""
Code similarity checker for two directories
"""
import os
import difflib
from pathlib import Path

def get_c_files(directory):
    """Get all .c files from directory"""
    c_files = {}
    for file in Path(directory).glob('*.c'):
        with open(file, 'r', encoding='utf-8', errors='ignore') as f:
            c_files[file.name] = f.readlines()
    return c_files

def calculate_similarity(dir1, dir2):
    """Calculate similarity between two directories"""
    files1 = get_c_files(dir1)
    files2 = get_c_files(dir2)
    
    # Get total lines
    total_lines1 = sum(len(lines) for lines in files1.values())
    total_lines2 = sum(len(lines) for lines in files2.values())
    
    # Combine all code
    all_code1 = []
    all_code2 = []
    
    for lines in files1.values():
        all_code1.extend(lines)
    for lines in files2.values():
        all_code2.extend(lines)
    
    # Calculate similarity using difflib
    matcher = difflib.SequenceMatcher(None, all_code1, all_code2)
    similarity = matcher.ratio() * 100
    
    print("=" * 60)
    print("CODE SIMILARITY ANALYSIS")
    print("=" * 60)
    print(f"\nDirectory 1: {dir1}")
    print(f"  Files: {len(files1)}")
    print(f"  Total lines: {total_lines1}")
    print(f"  Files: {list(files1.keys())}")
    
    print(f"\nDirectory 2: {dir2}")
    print(f"  Files: {len(files2)}")
    print(f"  Total lines: {total_lines2}")
    print(f"  Files: {list(files2.keys())}")
    
    print("\n" + "=" * 60)
    print(f"SIMILARITY: {similarity:.2f}%")
    print(f"DIFFERENCE: {100 - similarity:.2f}%")
    print("=" * 60)
    
    # Detailed file-by-file comparison
    print("\nDETAILED COMPARISON:")
    print("-" * 60)
    
    # Compare matching files by logic
    comparisons = [
        ('init.c', 'setup_config.c'),
        ('main.c', 'philo_main.c'),
        ('start_simolation.c', 'philo_routine.c'),
        ('tools.c', 'utils_helper.c'),
    ]
    
    for file1, file2 in comparisons:
        if file1 in files1 and file2 in files2:
            m = difflib.SequenceMatcher(None, files1[file1], files2[file2])
            sim = m.ratio() * 100
            print(f"{file1:25} vs {file2:25} = {sim:.1f}% similar")
    
    return similarity

if __name__ == "__main__":
    dir1 = "/workspaces/yaamaich/aefa"
    dir2 = "/workspaces/yaamaich/philosfers"
    
    calculate_similarity(dir1, dir2)
