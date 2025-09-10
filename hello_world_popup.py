#!/usr/bin/env python3
"""
Simple application that shows a pop-up window with "hello world" message.
This version works across different platforms and environments.
"""

import sys
import webbrowser
import tempfile
import os

def show_hello_world_popup():
    """Display a pop-up window with 'hello world' message."""
    try:
        # Try tkinter first (if available)
        import tkinter as tk
        from tkinter import messagebox
        
        root = tk.Tk()
        root.withdraw()  # Hide the root window
        messagebox.showinfo("Hello World", "hello world")
        root.destroy()
        print("Pop-up displayed using tkinter")
        
    except ImportError:
        # Fallback: Create a temporary HTML file and open it in browser
        html_content = """
        <!DOCTYPE html>
        <html>
        <head><title>Hello World</title></head>
        <body>
            <script>
                alert("hello world");
                window.close();
            </script>
            <h1>Hello World</h1>
            <p>A pop-up should have appeared with "hello world"</p>
        </body>
        </html>
        """
        
        with tempfile.NamedTemporaryFile(mode='w', suffix='.html', delete=False) as f:
            f.write(html_content)
            temp_file = f.name
        
        try:
            webbrowser.open('file://' + temp_file)
            print(f"Pop-up displayed using web browser: file://{temp_file}")
        finally:
            # Clean up the temporary file after a short delay
            import time
            time.sleep(2)
            try:
                os.unlink(temp_file)
            except:
                pass

if __name__ == "__main__":
    show_hello_world_popup()