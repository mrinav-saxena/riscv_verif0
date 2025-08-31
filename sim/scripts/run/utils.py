#!/usr/bin/env python3
import subprocess
import shutil
import stat
import sys
import os
from pathlib import Path

def run(cmd, cwd=None, env=None):
    """Run a subprocess command with error handling"""
    try:
        subprocess.check_call(cmd, cwd=cwd, env=env)
    except subprocess.CalledProcessError as e:
        print(f"Command failed ({e.returncode}): {' '.join(map(str, cmd))}", file=sys.stderr)
        sys.exit(e.returncode)
    except FileNotFoundError:
        print(f"Tool not found: {cmd[0]} (is it in PATH?)", file=sys.stderr)
        sys.exit(127)

def add_permissions_recursive(path):
    """Recursively add read/write permissions to a path"""
    try:
        # Add read/write permissions for current user
        current_perms = os.stat(path).st_mode
        os.chmod(path, current_perms | stat.S_IRUSR | stat.S_IWUSR)
        
        # If it's a directory, recursively add permissions to contents
        if os.path.isdir(path):
            for item in os.listdir(path):
                item_path = os.path.join(path, item)
                add_permissions_recursive(item_path)
    except Exception as e:
        print(f"Warning: Could not set permissions on {path}: {e}")

def safe_remove_directory(path):
    """Safely remove a directory with permission handling and fallbacks"""
    if not path.exists():
        return
    
    print(f"Cleaning {path}...")
    
    # Add permissions before removing
    add_permissions_recursive(path)
    
    # Try Python removal first
    try:
        shutil.rmtree(path)
        return
    except PermissionError as e:
        print(f"Permission error removing {path}: {e}")
        print("Attempting to force remove with system commands...")
    
    # Fallback to system commands
    if os.name == 'nt':  # Windows
        if os.system(f'rmdir /s /q "{path}"') != 0:
            print(f"Failed to remove {path}. Please remove manually and try again.")
            sys.exit(1)
    else:  # Unix-like
        if os.system(f'rm -rf "{path}"') != 0:
            print(f"Failed to remove {path}. Please remove manually and try again.")
            sys.exit(1)

def run_with_logging(cmd, log_path, description="Command", cwd=None, env=None):
    """Run a command and log its output to a file
    
    Args:
        cmd: Command to run (list of strings or string)
        log_path: Path to log file
        description: Description of what the command does (for console output)
        cwd: Working directory for command execution
        env: Environment variables for command execution
    
    Returns:
        subprocess.CompletedProcess result object
    """
    # Convert string command to list if needed
    if isinstance(cmd, str):
        cmd = cmd.split()
    
    print(f"{description} output will be logged to {log_path}")
    
    with open(log_path, 'w') as log_file:
        result = subprocess.run(cmd, capture_output=True, text=True, cwd=cwd, env=env)
        log_file.write("=== STDOUT ===\n")
        log_file.write(result.stdout)
        log_file.write("\n=== STDERR ===\n")
        log_file.write(result.stderr)
        log_file.write(f"\n=== RETURN CODE: {result.returncode} ===\n")
    
    if result.returncode != 0:
        print(f"{description} failed! Check log file: {log_path}", file=sys.stderr)
        print("STDOUT:", result.stdout)
        print("STDERR:", result.stderr)
        sys.exit(1)
    
    return result
