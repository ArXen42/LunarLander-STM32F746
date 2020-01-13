# LunarLander style game on STM32F746 Discovery

## Firmware Structure

Threads:

 - Logic thread: 60Hz (or maybe other tickrate) game state updates
 - Rendering thread: redraws frame based on current game state
 - UI rendering thread: draws text UI separately, possibly in separate image buffers using DMA2D
