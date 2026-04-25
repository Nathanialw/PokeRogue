from transparent_background.Remover import Remover, console
# transparent_background/__init__.py

# Optional GUI import (don’t hard-fail if flet API differs)
try:
    from transparent_background.gui import gui
except Exception:
    gui = None